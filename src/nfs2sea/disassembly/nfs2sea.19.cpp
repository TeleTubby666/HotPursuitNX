#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_487914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487914  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487915  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487916  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487917  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487918  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048791b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048791d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048791f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00487922  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00487925  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00487927  8a99251f5600           -mov bl, byte ptr [ecx + 0x561f25]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5644069) /* 0x561f25 */);
    // 0048792d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00487930  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00487932  7549                   -jne 0x48797d
    if (!cpu.flags.zf)
    {
        goto L_0x0048797d;
    }
    // 00487934  80b9261f560000         +cmp byte ptr [ecx + 0x561f26], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5644070) /* 0x561f26 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048793b  742a                   -je 0x487967
    if (cpu.flags.zf)
    {
        goto L_0x00487967;
    }
    // 0048793d  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487941  8b80fc9b5900           -mov eax, dword ptr [eax + 0x599bfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872636) /* 0x599bfc */);
    // 00487947  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00487949  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0048794c  e8cfc00100             -call 0x4a3a20
    cpu.esp -= 4;
    sub_4a3a20(app, cpu);
    if (cpu.terminate) return;
L_0x00487951:
    // 00487951  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487955  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487958  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048795a  e8b1ba0100             -call 0x4a3410
    cpu.esp -= 4;
    sub_4a3410(app, cpu);
    if (cpu.terminate) return;
    // 0048795f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00487962  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487963  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487964  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487965  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487966  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487967:
    // 00487967  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487969  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048796b  668b812a1f5600         -mov ax, word ptr [ecx + 0x561f2a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5644074) /* 0x561f2a */);
    // 00487972  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487976  e875cc0100             -call 0x4a45f0
    cpu.esp -= 4;
    sub_4a45f0(app, cpu);
    if (cpu.terminate) return;
    // 0048797b  ebd4                   -jmp 0x487951
    goto L_0x00487951;
L_0x0048797d:
    // 0048797d  80fb01                 +cmp bl, 1
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
    // 00487980  755b                   -jne 0x4879dd
    if (!cpu.flags.zf)
    {
        goto L_0x004879dd;
    }
    // 00487982  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487983  80b9261f560000         +cmp byte ptr [ecx + 0x561f26], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5644070) /* 0x561f26 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048798a  740f                   -je 0x48799b
    if (cpu.flags.zf)
    {
        goto L_0x0048799b;
    }
    // 0048798c  8bb8fc9b5900           -mov edi, dword ptr [eax + 0x599bfc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872636) /* 0x599bfc */);
    // 00487992  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 00487995  83ef40                 -sub edi, 0x40
    (cpu.edi) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00487998  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
L_0x0048799b:
    // 0048799b  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0048799d  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 004879a0  8b85261f5600           -mov eax, dword ptr [ebp + 0x561f26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5644070) /* 0x561f26 */);
    // 004879a6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004879a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004879aa  8b85251f5600           -mov eax, dword ptr [ebp + 0x561f25]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5644069) /* 0x561f25 */);
    // 004879b0  c1f818                 +sar eax, 0x18
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
    // 004879b3  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004879b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004879b8  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004879bc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004879be  e85dcc0100             -call 0x4a4620
    cpu.esp -= 4;
    sub_4a4620(app, cpu);
    if (cpu.terminate) return;
    // 004879c3  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004879c7  8885281f5600           -mov byte ptr [ebp + 0x561f28], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5644072) /* 0x561f28 */) = cpu.al;
    // 004879cd  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004879d1  8885291f5600           -mov byte ptr [ebp + 0x561f29], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5644073) /* 0x561f29 */) = cpu.al;
    // 004879d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879d8  e974ffffff             -jmp 0x487951
    goto L_0x00487951;
L_0x004879dd:
    // 004879dd  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004879e2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004879e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4879ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004879ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004879ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004879ee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004879f0  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004879f3  8a9a251f5600           -mov bl, byte ptr [edx + 0x561f25]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5644069) /* 0x561f25 */);
    // 004879f9  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004879fb  740d                   -je 0x487a0a
    if (cpu.flags.zf)
    {
        goto L_0x00487a0a;
    }
    // 004879fd  80fb01                 +cmp bl, 1
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
    // 00487a00  7408                   -je 0x487a0a
    if (cpu.flags.zf)
    {
        goto L_0x00487a0a;
    }
    // 00487a02  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00487a07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487a0a:
    // 00487a0a  e809b90100             -call 0x4a3318
    cpu.esp -= 4;
    sub_4a3318(app, cpu);
    if (cpu.terminate) return;
    // 00487a0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487a14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487a14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487a15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487a16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487a17  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487a19  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00487a1c  8a90251f5600           -mov dl, byte ptr [eax + 0x561f25]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5644069) /* 0x561f25 */);
    // 00487a22  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00487a24  740e                   -je 0x487a34
    if (cpu.flags.zf)
    {
        goto L_0x00487a34;
    }
    // 00487a26  80fa01                 +cmp dl, 1
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
    // 00487a29  7409                   -je 0x487a34
    if (cpu.flags.zf)
    {
        goto L_0x00487a34;
    }
    // 00487a2b  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x00487a30:
    // 00487a30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487a34:
    // 00487a34  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487a36  e861ba0100             -call 0x4a349c
    cpu.esp -= 4;
    sub_4a349c(app, cpu);
    if (cpu.terminate) return;
    // 00487a3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487a3d  7cf1                   -jl 0x487a30
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487a30;
    }
    // 00487a3f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487a41  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00487a44  8b9a2c1f5600           -mov ebx, dword ptr [edx + 0x561f2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5644076) /* 0x561f2c */);
    // 00487a4a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00487a4c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487a4e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487a50  7cde                   -jl 0x487a30
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487a30;
    }
    // 00487a52  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487a54  668b9a201f5600         -mov bx, word ptr [edx + 0x561f20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5644064) /* 0x561f20 */);
    // 00487a5b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487a5d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00487a60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487a62  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00487a65  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487a67  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00487a6a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487a6c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487a6f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487a71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487a73  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00487a7a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487a7c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00487a7f  6683b8029c590000       +cmp word ptr [eax + 0x599c02], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5872642) /* 0x599c02 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00487a87  7c2b                   -jl 0x487ab4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ab4;
    }
    // 00487a89  8b88009c5900           -mov ecx, dword ptr [eax + 0x599c00]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872640) /* 0x599c00 */);
    // 00487a8f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487a91  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00487a94  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00487a96  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00487a99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487a9b  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00487a9e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487aa0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00487aa3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487aa5  81c1b0040000           -add ecx, 0x4b0
    (cpu.ecx) += x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 00487aab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487aae  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487ab0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ab1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ab2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ab3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487ab4:
    // 00487ab4  8b80009c5900           -mov eax, dword ptr [eax + 0x599c00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5872640) /* 0x599c00 */);
    // 00487aba  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00487abd  2db0040000             -sub eax, 0x4b0
    (cpu.eax) -= x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 00487ac2  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00487ac5  b950fbffff             -mov ecx, 0xfffffb50
    cpu.ecx = 4294966096 /*0xfffffb50*/;
    // 00487aca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487acc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487acf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487ad1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ad2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ad3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ad4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487ad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487ad8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487ad9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487ada  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487adc  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00487adf  8a9a251f5600           -mov bl, byte ptr [edx + 0x561f25]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5644069) /* 0x561f25 */);
    // 00487ae5  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00487ae7  740d                   -je 0x487af6
    if (cpu.flags.zf)
    {
        goto L_0x00487af6;
    }
    // 00487ae9  80fb01                 +cmp bl, 1
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
    // 00487aec  7408                   -je 0x487af6
    if (cpu.flags.zf)
    {
        goto L_0x00487af6;
    }
    // 00487aee  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00487af3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487af4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487af5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487af6:
    // 00487af6  e8a1b90100             -call 0x4a349c
    cpu.esp -= 4;
    sub_4a349c(app, cpu);
    if (cpu.terminate) return;
    // 00487afb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487afc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487afd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487b00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487b01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487b02  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487b04  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00487b07  8a98251f5600           -mov bl, byte ptr [eax + 0x561f25]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5644069) /* 0x561f25 */);
    // 00487b0d  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00487b0f  740d                   -je 0x487b1e
    if (cpu.flags.zf)
    {
        goto L_0x00487b1e;
    }
    // 00487b11  80fb01                 +cmp bl, 1
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
    // 00487b14  7408                   -je 0x487b1e
    if (cpu.flags.zf)
    {
        goto L_0x00487b1e;
    }
    // 00487b16  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00487b1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487b1e:
    // 00487b1e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487b1f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00487b21  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00487b24  a190944d00             -mov eax, dword ptr [0x4d9490]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */);
    // 00487b29  668bb6201f5600         -mov si, word ptr [esi + 0x561f20]
    cpu.si = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5644064) /* 0x561f20 */);
    // 00487b30  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00487b36  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00487b38  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487b3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487b3c  e89fbe0100             -call 0x4a39e0
    cpu.esp -= 4;
    sub_4a39e0(app, cpu);
    if (cpu.terminate) return;
    // 00487b41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487b43  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487b45  e82eb80100             -call 0x4a3378
    cpu.esp -= 4;
    sub_4a3378(app, cpu);
    if (cpu.terminate) return;
    // 00487b4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487b50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487b51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487b52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487b53  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00487b55  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00487b58  81c3201f5600           -add ebx, 0x561f20
    (cpu.ebx) += x86::reg32(x86::sreg32(5644064 /*0x561f20*/));
    // 00487b5e  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00487b61  807b0407               +cmp byte ptr [ebx + 4], 7
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
    // 00487b65  7461                   -je 0x487bc8
    if (cpu.flags.zf)
    {
        goto L_0x00487bc8;
    }
    // 00487b67  807b0409               +cmp byte ptr [ebx + 4], 9
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
    // 00487b6b  7457                   -je 0x487bc4
    if (cpu.flags.zf)
    {
        goto L_0x00487bc4;
    }
    // 00487b6d  807b0408               +cmp byte ptr [ebx + 4], 8
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
    // 00487b71  7451                   -je 0x487bc4
    if (cpu.flags.zf)
    {
        goto L_0x00487bc4;
    }
    // 00487b73  807b0402               +cmp byte ptr [ebx + 4], 2
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
    // 00487b77  0f85a2000000           -jne 0x487c1f
    if (!cpu.flags.zf)
    {
        goto L_0x00487c1f;
    }
    // 00487b7d  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 00487b82  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 00487b88  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00487b8e  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00487b94  8a4303                 -mov al, byte ptr [ebx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00487b97  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00487b99  3c01                   +cmp al, 1
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
    // 00487b9b  7515                   -jne 0x487bb2
    if (!cpu.flags.zf)
    {
        goto L_0x00487bb2;
    }
    // 00487b9d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00487ba2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487ba4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487ba6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487ba9  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487bab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487bad  7401                   -je 0x487bb0
    if (cpu.flags.zf)
    {
        goto L_0x00487bb0;
    }
    // 00487baf  41                     -inc ecx
    (cpu.ecx)++;
L_0x00487bb0:
    // 00487bb0  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
L_0x00487bb2:
    // 00487bb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487bb4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487bb6  7e0c                   -jle 0x487bc4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487bc4;
    }
    // 00487bb8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00487bba:
    // 00487bba  40                     -inc eax
    (cpu.eax)++;
    // 00487bbb  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00487bbe  42                     -inc edx
    (cpu.edx)++;
    // 00487bbf  39c8                   +cmp eax, ecx
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
    // 00487bc1  7cf7                   -jl 0x487bba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487bba;
    }
    // 00487bc3  90                     -nop 
    ;
L_0x00487bc4:
    // 00487bc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487bc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487bc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487bc7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487bc8:
    // 00487bc8  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 00487bcd  be1c000000             -mov esi, 0x1c
    cpu.esi = 28 /*0x1c*/;
    // 00487bd2  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 00487bd8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00487bda  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00487be0  83c11b                 -add ecx, 0x1b
    (cpu.ecx) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00487be3  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00487be9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487beb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487bed  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487bf0  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487bf2  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00487bf9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487bfb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487bfd  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00487c00  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00487c02  807b0302               +cmp byte ptr [ebx + 3], 2
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
    // 00487c06  7502                   -jne 0x487c0a
    if (!cpu.flags.zf)
    {
        goto L_0x00487c0a;
    }
    // 00487c08  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00487c0a:
    // 00487c0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487c0c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487c0e  7eb4                   -jle 0x487bc4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487bc4;
    }
    // 00487c10  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x00487c12:
    // 00487c12  40                     -inc eax
    (cpu.eax)++;
    // 00487c13  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00487c16  42                     -inc edx
    (cpu.edx)++;
    // 00487c17  39c8                   +cmp eax, ecx
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
    // 00487c19  7cf7                   -jl 0x487c12
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487c12;
    }
    // 00487c1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487c1f:
    // 00487c1f  807b0400               +cmp byte ptr [ebx + 4], 0
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
    // 00487c23  759f                   -jne 0x487bc4
    if (!cpu.flags.zf)
    {
        goto L_0x00487bc4;
    }
    // 00487c25  807b0302               +cmp byte ptr [ebx + 3], 2
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
    // 00487c29  7502                   -jne 0x487c2d
    if (!cpu.flags.zf)
    {
        goto L_0x00487c2d;
    }
    // 00487c2b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00487c2d:
    // 00487c2d  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00487c30  80fa10                 +cmp dl, 0x10
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
    // 00487c33  7517                   -jne 0x487c4c
    if (!cpu.flags.zf)
    {
        goto L_0x00487c4c;
    }
    // 00487c35  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487c37  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487c39  7e89                   -jle 0x487bc4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487bc4;
    }
L_0x00487c3b:
    // 00487c3b  42                     -inc edx
    (cpu.edx)++;
    // 00487c3c  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 00487c41  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00487c44  39ca                   +cmp edx, ecx
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
    // 00487c46  7cf3                   -jl 0x487c3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487c3b;
    }
    // 00487c48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487c4c:
    // 00487c4c  80fa08                 +cmp dl, 8
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
    // 00487c4f  0f856fffffff           -jne 0x487bc4
    if (!cpu.flags.zf)
    {
        goto L_0x00487bc4;
    }
    // 00487c55  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487c57  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487c59  0f8e65ffffff           -jle 0x487bc4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487bc4;
    }
L_0x00487c5f:
    // 00487c5f  42                     -inc edx
    (cpu.edx)++;
    // 00487c60  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00487c63  40                     -inc eax
    (cpu.eax)++;
    // 00487c64  39ca                   +cmp edx, ecx
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
    // 00487c66  7cf7                   -jl 0x487c5f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487c5f;
    }
    // 00487c68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_487c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487c70  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487c77  740f                   -je 0x487c88
    if (cpu.flags.zf)
    {
        goto L_0x00487c88;
    }
    // 00487c79  83f87f                 +cmp eax, 0x7f
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
    // 00487c7c  7f04                   -jg 0x487c82
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487c82;
    }
    // 00487c7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487c80  7d0c                   -jge 0x487c8e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487c8e;
    }
L_0x00487c82:
    // 00487c82  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00487c87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487c88:
    // 00487c88  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00487c8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487c8e:
    // 00487c8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487c8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487c90  a22aac4d00             -mov byte ptr [0x4dac2a], al
    app->getMemory<x86::reg8>(x86::reg32(5090346) /* 0x4dac2a */) = cpu.al;
    // 00487c95  8b0db8ab4d00           -mov ecx, dword ptr [0x4dabb8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 00487c9b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487c9d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487c9f  e868010000             -call 0x487e0c
    cpu.esp -= 4;
    sub_487e0c(app, cpu);
    if (cpu.terminate) return;
    // 00487ca4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487ca6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ca7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ca8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487cb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487cb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487cb4  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 00487cba  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00487cbc  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00487cbe  750a                   -jne 0x487cca
    if (!cpu.flags.zf)
    {
        goto L_0x00487cca;
    }
    // 00487cc0  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 00487cc5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487cc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487cc8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487cc9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487cca:
    // 00487cca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487ccb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487ccc  e8ff910100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00487cd1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487cd3  e804960100             -call 0x4a12dc
    cpu.esp -= 4;
    sub_4a12dc(app, cpu);
    if (cpu.terminate) return;
    // 00487cd8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487cda  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487cdc  7c56                   -jl 0x487d34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487d34;
    }
    // 00487cde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00487ce1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487ce3  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00487ce6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487ce8  8a982b9c5900           -mov bl, byte ptr [eax + 0x599c2b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872683) /* 0x599c2b */);
    // 00487cee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487cf0  7439                   -je 0x487d2b
    if (cpu.flags.zf)
    {
        goto L_0x00487d2b;
    }
    // 00487cf2  b9f09b5900             -mov ecx, 0x599bf0
    cpu.ecx = 5872624 /*0x599bf0*/;
    // 00487cf7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00487cf9:
    // 00487cf9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487cfb  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 00487cfe  39d8                   +cmp eax, ebx
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
    // 00487d00  7512                   -jne 0x487d14
    if (!cpu.flags.zf)
    {
        goto L_0x00487d14;
    }
    // 00487d02  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 00487d06  750c                   -jne 0x487d14
    if (!cpu.flags.zf)
    {
        goto L_0x00487d14;
    }
    // 00487d08  833900                 +cmp dword ptr [ecx], 0
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
    // 00487d0b  7c07                   -jl 0x487d14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487d14;
    }
    // 00487d0d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487d0f  e8d8fcffff             -call 0x4879ec
    cpu.esp -= 4;
    sub_4879ec(app, cpu);
    if (cpu.terminate) return;
L_0x00487d14:
    // 00487d14  42                     -inc edx
    (cpu.edx)++;
    // 00487d15  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00487d18  83fa10                 +cmp edx, 0x10
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
    // 00487d1b  7cdc                   -jl 0x487cf9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487cf9;
    }
L_0x00487d1d:
    // 00487d1d  e8c2910100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00487d22  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00487d24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d26  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487d28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487d2b:
    // 00487d2b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487d2d  e8bafcffff             -call 0x4879ec
    cpu.esp -= 4;
    sub_4879ec(app, cpu);
    if (cpu.terminate) return;
    // 00487d32  ebe9                   -jmp 0x487d1d
    goto L_0x00487d1d;
L_0x00487d34:
    // 00487d34  bef8ffffff             -mov esi, 0xfffffff8
    cpu.esi = 4294967288 /*0xfffffff8*/;
    // 00487d39  e8a6910100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00487d3e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00487d40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487d44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487d50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487d51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487d52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487d53  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00487d55  e882950100             -call 0x4a12dc
    cpu.esp -= 4;
    sub_4a12dc(app, cpu);
    if (cpu.terminate) return;
    // 00487d5a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487d5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487d5e  0f8c75000000           -jl 0x487dd9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487dd9;
    }
    // 00487d64  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00487d6b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00487d6d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00487d70  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487d72  81c2f09b5900           -add edx, 0x599bf0
    (cpu.edx) += x86::reg32(x86::sreg32(5872624 /*0x599bf0*/));
    // 00487d78  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00487d7b  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00487d7e  39d8                   +cmp eax, ebx
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
    // 00487d80  7460                   -je 0x487de2
    if (cpu.flags.zf)
    {
        goto L_0x00487de2;
    }
    // 00487d82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487d83  0fb67a3b               -movzx edi, byte ptr [edx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 00487d87  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487d89  745d                   -je 0x487de8
    if (cpu.flags.zf)
    {
        goto L_0x00487de8;
    }
    // 00487d8b  b9f09b5900             -mov ecx, 0x599bf0
    cpu.ecx = 5872624 /*0x599bf0*/;
    // 00487d90  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00487d92:
    // 00487d92  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487d94  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 00487d97  39fa                   +cmp edx, edi
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
    // 00487d99  752e                   -jne 0x487dc9
    if (!cpu.flags.zf)
    {
        goto L_0x00487dc9;
    }
    // 00487d9b  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 00487d9f  7528                   -jne 0x487dc9
    if (!cpu.flags.zf)
    {
        goto L_0x00487dc9;
    }
    // 00487da1  833900                 +cmp dword ptr [ecx], 0
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
    // 00487da4  7c23                   -jl 0x487dc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487dc9;
    }
    // 00487da6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487da8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00487dab  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00487dae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487db0  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00487db7  e8f4c90100             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 00487dbc  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 00487dbf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487dc1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00487dc4  e84bfbffff             -call 0x487914
    cpu.esp -= 4;
    sub_487914(app, cpu);
    if (cpu.terminate) return;
L_0x00487dc9:
    // 00487dc9  43                     -inc ebx
    (cpu.ebx)++;
    // 00487dca  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00487dcd  83fb10                 +cmp ebx, 0x10
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
    // 00487dd0  7cc0                   -jl 0x487d92
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487d92;
    }
    // 00487dd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487dd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487dd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487dd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487dd7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487dd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487dd9:
    // 00487dd9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00487dde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ddf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487de0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487de1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487de2:
    // 00487de2  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487de4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487de5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487de6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487de7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487de8:
    // 00487de8  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00487deb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487ded  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00487df0  e8bbc90100             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 00487df5  8b522e                 -mov edx, dword ptr [edx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 00487df8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487dfa  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00487dfd  e812fbffff             -call 0x487914
    cpu.esp -= 4;
    sub_487914(app, cpu);
    if (cpu.terminate) return;
    // 00487e02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487e04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487e0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487e0c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487e0d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487e0f  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487e16  7410                   -je 0x487e28
    if (cpu.flags.zf)
    {
        goto L_0x00487e28;
    }
    // 00487e18  83fa7f                 +cmp edx, 0x7f
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
    // 00487e1b  7f04                   -jg 0x487e21
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487e21;
    }
    // 00487e1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487e1f  7d0e                   -jge 0x487e2f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487e2f;
    }
L_0x00487e21:
    // 00487e21  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00487e26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487e28:
    // 00487e28  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00487e2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487e2f:
    // 00487e2f  e89c900100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00487e34  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487e36  e815ffffff             -call 0x487d50
    cpu.esp -= 4;
    sub_487d50(app, cpu);
    if (cpu.terminate) return;
    // 00487e3b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487e3d  e8a2900100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00487e42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487e50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487e51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487e52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487e53  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00487e56  8b1dc4944d00           -mov ebx, dword ptr [0x4d94c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */);
    // 00487e5c  8b35c0944d00           -mov esi, dword ptr [0x4d94c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084352) /* 0x4d94c0 */);
    // 00487e62  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00487e69  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00487e6b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00487e6e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00487e71  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487e73  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00487e75  e8cafb0000             -call 0x497a44
    cpu.esp -= 4;
    sub_497a44(app, cpu);
    if (cpu.terminate) return;
    // 00487e7a  8b35c0944d00           -mov esi, dword ptr [0x4d94c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084352) /* 0x4d94c0 */);
    // 00487e80  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487e82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487e84  741d                   -je 0x487ea3
    if (cpu.flags.zf)
    {
        goto L_0x00487ea3;
    }
    // 00487e86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487e87  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487e89  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487e8b  7e13                   -jle 0x487ea0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487ea0;
    }
L_0x00487e8d:
    // 00487e8d  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 00487e94  42                     -inc edx
    (cpu.edx)++;
    // 00487e95  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00487e97  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00487e99  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00487e9c  39f2                   +cmp edx, esi
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
    // 00487e9e  7ced                   -jl 0x487e8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487e8d;
    }
L_0x00487ea0:
    // 00487ea0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00487ea2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00487ea3:
    // 00487ea3  8935c0944d00           -mov dword ptr [0x4d94c0], esi
    app->getMemory<x86::reg32>(x86::reg32(5084352) /* 0x4d94c0 */) = cpu.esi;
    // 00487ea9  891dc4944d00           -mov dword ptr [0x4d94c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */) = cpu.ebx;
    // 00487eaf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00487eb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487eb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487eb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487eb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487eb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487eb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487eba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487ebb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487ebd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00487ebf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487ec1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487ec2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487ec4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487ec5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487ec6  2eff15a8454c00         -call dword ptr cs:[0x4c45a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998568) /* 0x4c45a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487ecd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487ecf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487ed1  7c04                   -jl 0x487ed7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ed7;
    }
    // 00487ed3  39f8                   +cmp eax, edi
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
    // 00487ed5  7c0c                   -jl 0x487ee3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ee3;
    }
L_0x00487ed7:
    // 00487ed7  81fb02010000           -cmp ebx, 0x102
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
    // 00487edd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487edf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ee0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ee1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ee2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487ee3:
    // 00487ee3  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00487ee6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ee7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ee8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ee9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487eec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487eec  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487ef0  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487ef2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487ef4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_487ef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487ef8  833d3820560000         +cmp dword ptr [0x562038], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5644344) /* 0x562038 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487eff  7401                   -je 0x487f02
    if (cpu.flags.zf)
    {
        goto L_0x00487f02;
    }
    // 00487f01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487f02:
    // 00487f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487f03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487f04  2eff15a0444c00         -call dword ptr cs:[0x4c44a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998304) /* 0x4c44a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f0b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00487f0d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487f0f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487f11  6830205600             -push 0x562030
    app->getMemory<x86::reg32>(cpu.esp-4) = 5644336 /*0x562030*/;
    cpu.esp -= 4;
    // 00487f16  a334205600             -mov dword ptr [0x562034], eax
    app->getMemory<x86::reg32>(x86::reg32(5644340) /* 0x562034 */) = cpu.eax;
    // 00487f1b  2eff1598444c00         -call dword ptr cs:[0x4c4498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998296) /* 0x4c4498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487f23  2eff15a4444c00         -call dword ptr cs:[0x4c44a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998308) /* 0x4c44a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487f2b  2eff1598444c00         -call dword ptr cs:[0x4c4498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998296) /* 0x4c4498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487f33  2eff154c444c00         -call dword ptr cs:[0x4c444c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998220) /* 0x4c444c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f3a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00487f3f  e80cffffff             -call 0x487e50
    cpu.esp -= 4;
    sub_487e50(app, cpu);
    if (cpu.terminate) return;
    // 00487f44  890d38205600           -mov dword ptr [0x562038], ecx
    app->getMemory<x86::reg32>(x86::reg32(5644344) /* 0x562038 */) = cpu.ecx;
    // 00487f4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487f50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487f51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487f53  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00487f56  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00487f58  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00487f5a  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487f5e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00487f60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f61  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00487f63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487f64  68ec7e4800             -push 0x487eec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4751084 /*0x487eec*/;
    cpu.esp -= 4;
    // 00487f69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487f6a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487f6c  2eff153c444c00         -call dword ptr cs:[0x4c443c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998204) /* 0x4c443c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f73  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487f75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487f77  7441                   -je 0x487fba
    if (cpu.flags.zf)
    {
        goto L_0x00487fba;
    }
    // 00487f79  833d3820560000         +cmp dword ptr [0x562038], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5644344) /* 0x562038 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487f80  7507                   -jne 0x487f89
    if (!cpu.flags.zf)
    {
        goto L_0x00487f89;
    }
    // 00487f82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487f84  e86fffffff             -call 0x487ef8
    cpu.esp -= 4;
    sub_487ef8(app, cpu);
    if (cpu.terminate) return;
L_0x00487f89:
    // 00487f89  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00487f90  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00487f92  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00487f95  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00487f98  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487f9b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00487f9d  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00487fa0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487fa2  e8a9010000             -call 0x488150
    cpu.esp -= 4;
    sub_488150(app, cpu);
    if (cpu.terminate) return;
    // 00487fa7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487fa8  2eff1538454c00         -call dword ptr cs:[0x4c4538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998456) /* 0x4c4538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487faf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00487fb1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487fb3  2eff1578454c00         -call dword ptr cs:[0x4c4578]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998520) /* 0x4c4578 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00487fba:
    // 00487fba  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487fbc  740e                   -je 0x487fcc
    if (cpu.flags.zf)
    {
        goto L_0x00487fcc;
    }
    // 00487fbe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487fc3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00487fc6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fc9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00487fcc:
    // 00487fcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487fce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00487fd1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fd2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fd4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_487fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487fd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487fda  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487fe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487fe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487fe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487fe3  83f8ff                 +cmp eax, -1
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
    // 00487fe6  7418                   -je 0x488000
    if (cpu.flags.zf)
    {
        goto L_0x00488000;
    }
    // 00487fe8  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
L_0x00487fea:
    // 00487fea  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487fec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487fed  2eff157c454c00         -call dword ptr cs:[0x4c457c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998524) /* 0x4c457c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487ff4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487ff5  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487ffc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ffd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ffe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488000:
    // 00488000  2eff15a4444c00         -call dword ptr cs:[0x4c44a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998308) /* 0x4c44a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488007  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488009  ebdf                   -jmp 0x487fea
    goto L_0x00487fea;
}

/* align: skip 0x90 */
void Application::sub_48800c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048800c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048800d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048800e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00488010  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488011  2eff1578454c00         -call dword ptr cs:[0x4c4578]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998520) /* 0x4c4578 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488018  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488019  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048801a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48801c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048801c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048801d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048801e  8b0de8894d00           -mov ecx, dword ptr [0x4d89e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 00488024  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488026  7505                   -jne 0x48802d
    if (!cpu.flags.zf)
    {
        goto L_0x0048802d;
    }
    // 00488028  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x0048802d:
    // 0048802d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048802f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00488032  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00488034  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00488037  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488039  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048803c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048803e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00488041  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488043  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488045  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00488048  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048804a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048804c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048804d  2eff1578454c00         -call dword ptr cs:[0x4c4578]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998520) /* 0x4c4578 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488054  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488055  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488056  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488058(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488058  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488059  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048805a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048805b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048805d  2eff15a0444c00         -call dword ptr cs:[0x4c44a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998304) /* 0x4c44a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488064  8b0d38205600           -mov ecx, dword ptr [0x562038]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5644344) /* 0x562038 */);
    // 0048806a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048806c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048806e  7415                   -je 0x488085
    if (cpu.flags.zf)
    {
        goto L_0x00488085;
    }
L_0x00488070:
    // 00488070  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488072  7520                   -jne 0x488094
    if (!cpu.flags.zf)
    {
        goto L_0x00488094;
    }
    // 00488074  3b1534205600           +cmp edx, dword ptr [0x562034]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5644340) /* 0x562034 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048807a  7512                   -jne 0x48808e
    if (!cpu.flags.zf)
    {
        goto L_0x0048808e;
    }
L_0x0048807c:
    // 0048807c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00488081  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488082  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488083  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488084  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488085:
    // 00488085  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488087  e86cfeffff             -call 0x487ef8
    cpu.esp -= 4;
    sub_487ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048808c  ebe2                   -jmp 0x488070
    goto L_0x00488070;
L_0x0048808e:
    // 0048808e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488090  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488091  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488092  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488093  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488094:
    // 00488094  83fbff                 +cmp ebx, -1
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
    // 00488097  74e3                   -je 0x48807c
    if (cpu.flags.zf)
    {
        goto L_0x0048807c;
    }
    // 00488099  3b5310                 +cmp edx, dword ptr [ebx + 0x10]
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
    // 0048809c  74de                   -je 0x48807c
    if (cpu.flags.zf)
    {
        goto L_0x0048807c;
    }
    // 0048809e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004880a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4880a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004880a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004880a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004880a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004880a8  833d3820560000         +cmp dword ptr [0x562038], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5644344) /* 0x562038 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004880af  742f                   -je 0x4880e0
    if (cpu.flags.zf)
    {
        goto L_0x004880e0;
    }
L_0x004880b1:
    // 004880b1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004880b3  7534                   -jne 0x4880e9
    if (!cpu.flags.zf)
    {
        goto L_0x004880e9;
    }
    // 004880b5  a130205600             -mov eax, dword ptr [0x562030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644336) /* 0x562030 */);
L_0x004880ba:
    // 004880ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004880bb  2eff15f4444c00         -call dword ptr cs:[0x4c44f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998388) /* 0x4c44f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004880c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004880c4  7c35                   -jl 0x4880fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004880fb;
    }
    // 004880c6  0f8e5b000000           -jle 0x488127
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488127;
    }
    // 004880cc  83f802                 +cmp eax, 2
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
    // 004880cf  7c4e                   -jl 0x48811f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048811f;
    }
    // 004880d1  7e44                   -jle 0x488117
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488117;
    }
    // 004880d3  83f80f                 +cmp eax, 0xf
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
    // 004880d6  754f                   -jne 0x488127
    if (!cpu.flags.zf)
    {
        goto L_0x00488127;
    }
    // 004880d8  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004880dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004880df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004880e0:
    // 004880e0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004880e2  e811feffff             -call 0x487ef8
    cpu.esp -= 4;
    sub_487ef8(app, cpu);
    if (cpu.terminate) return;
    // 004880e7  ebc8                   -jmp 0x4880b1
    goto L_0x004880b1;
L_0x004880e9:
    // 004880e9  83faff                 +cmp edx, -1
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
    // 004880ec  7404                   -je 0x4880f2
    if (cpu.flags.zf)
    {
        goto L_0x004880f2;
    }
    // 004880ee  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004880f0  ebc8                   -jmp 0x4880ba
    goto L_0x004880ba;
L_0x004880f2:
    // 004880f2  2eff15a4444c00         -call dword ptr cs:[0x4c44a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998308) /* 0x4c44a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004880f9  ebbf                   -jmp 0x4880ba
    goto L_0x004880ba;
L_0x004880fb:
    // 004880fb  83f8fe                 +cmp eax, -2
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
    // 004880fe  7d0d                   -jge 0x48810d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048810d;
    }
    // 00488100  83f8f1                 +cmp eax, -0xf
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
    // 00488103  7522                   -jne 0x488127
    if (!cpu.flags.zf)
    {
        goto L_0x00488127;
    }
    // 00488105  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0048810a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048810b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048810c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048810d:
    // 0048810d  7f1d                   -jg 0x48812c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048812c;
    }
    // 0048810f  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00488114  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488117:
    // 00488117  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048811c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048811d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048811e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048811f:
    // 0048811f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00488124  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488125  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488126  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488127:
    // 00488127  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488129  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048812a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048812b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048812c:
    // 0048812c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488131  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488132  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488133  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00488150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488151  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488152  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488154  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00488156  833d3820560000         +cmp dword ptr [0x562038], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5644344) /* 0x562038 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048815d  742a                   -je 0x488189
    if (cpu.flags.zf)
    {
        goto L_0x00488189;
    }
L_0x0048815f:
    // 0048815f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488161  752f                   -jne 0x488192
    if (!cpu.flags.zf)
    {
        goto L_0x00488192;
    }
    // 00488163  8b0d30205600           -mov ecx, dword ptr [0x562030]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5644336) /* 0x562030 */);
    // 00488169  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0048816c  83f806                 +cmp eax, 6
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
    // 0048816f  7764                   -ja 0x4881d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004881d5;
    }
    // 00488171  ff248534814800         -jmp dword ptr [eax*4 + 0x488134]
    cpu.ip = app->getMemory<x86::reg32>(4751668 + cpu.eax * 4); goto dynamic_jump;
  case 0x00488178:
    // 00488178  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
L_0x0048817d:
    // 0048817d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048817e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048817f  2eff1570454c00         -call dword ptr cs:[0x4c4570]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998512) /* 0x4c4570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488186  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488187  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488188  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488189:
    // 00488189  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048818b  e868fdffff             -call 0x487ef8
    cpu.esp -= 4;
    sub_487ef8(app, cpu);
    if (cpu.terminate) return;
    // 00488190  ebcd                   -jmp 0x48815f
    goto L_0x0048815f;
L_0x00488192:
    // 00488192  83f9ff                 +cmp ecx, -1
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
    // 00488195  7411                   -je 0x4881a8
    if (cpu.flags.zf)
    {
        goto L_0x004881a8;
    }
    // 00488197  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488199  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0048819c  83f806                 +cmp eax, 6
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
    // 0048819f  7734                   -ja 0x4881d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004881d5;
    }
    // 004881a1  ff248534814800         -jmp dword ptr [eax*4 + 0x488134]
    cpu.ip = app->getMemory<x86::reg32>(4751668 + cpu.eax * 4); goto dynamic_jump;
L_0x004881a8:
    // 004881a8  2eff15a4444c00         -call dword ptr cs:[0x4c44a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998308) /* 0x4c44a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004881af  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004881b1  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004881b4  83f806                 +cmp eax, 6
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
    // 004881b7  771c                   -ja 0x4881d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004881d5;
    }
    // 004881b9  ff248534814800         -jmp dword ptr [eax*4 + 0x488134]
    cpu.ip = app->getMemory<x86::reg32>(4751668 + cpu.eax * 4); goto dynamic_jump;
  case 0x004881c0:
    // 004881c0  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004881c5  ebb6                   -jmp 0x48817d
    goto L_0x0048817d;
  case 0x004881c7:
    // 004881c7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004881cc  ebaf                   -jmp 0x48817d
    goto L_0x0048817d;
  case 0x004881ce:
    // 004881ce  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004881d3  eba8                   -jmp 0x48817d
    goto L_0x0048817d;
  case 0x004881d5:
L_0x004881d5:
    // 004881d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004881d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004881d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004881d9  2eff1570454c00         -call dword ptr cs:[0x4c4570]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998512) /* 0x4c4570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004881e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881e2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004881e3:
    // 004881e3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004881e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004881e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004881ea  2eff1570454c00         -call dword ptr cs:[0x4c4570]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998512) /* 0x4c4570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004881f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881f3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004881f4:
    // 004881f4  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004881f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004881fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004881fb  2eff1570454c00         -call dword ptr cs:[0x4c4570]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998512) /* 0x4c4570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488202  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488203  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488204  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488208(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488208  833dc8944d0000         +cmp dword ptr [0x4d94c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084360) /* 0x4d94c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048820f  750a                   -jne 0x48821b
    if (!cpu.flags.zf)
    {
        goto L_0x0048821b;
    }
    // 00488211  e852010000             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 00488216  a3c8944d00             -mov dword ptr [0x4d94c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5084360) /* 0x4d94c8 */) = cpu.eax;
L_0x0048821b:
    // 0048821b  a1c8944d00             -mov eax, dword ptr [0x4d94c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084360) /* 0x4d94c8 */);
    // 00488220  e893010000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00488225  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048822a  e875feffff             -call 0x4880a4
    cpu.esp -= 4;
    sub_4880a4(app, cpu);
    if (cpu.terminate) return;
    // 0048822f  83f803                 +cmp eax, 3
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
    // 00488232  7501                   -jne 0x488235
    if (!cpu.flags.zf)
    {
        goto L_0x00488235;
    }
    // 00488234  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488235:
    // 00488235  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488236  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048823b  a3cc944d00             -mov dword ptr [0x4d94cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5084364) /* 0x4d94cc */) = cpu.eax;
    // 00488240  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488245  e806ffffff             -call 0x488150
    cpu.esp -= 4;
    sub_488150(app, cpu);
    if (cpu.terminate) return;
    // 0048824a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048824b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48824c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048824c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048824d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488252  8b15cc944d00           -mov edx, dword ptr [0x4d94cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084364) /* 0x4d94cc */);
    // 00488258  e8f3feffff             -call 0x488150
    cpu.esp -= 4;
    sub_488150(app, cpu);
    if (cpu.terminate) return;
    // 0048825d  a1c8944d00             -mov eax, dword ptr [0x4d94c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084360) /* 0x4d94c8 */);
    // 00488262  e869010000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00488267  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488268  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48826c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048826c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048826d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048826e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488270  2eff155c444c00         -call dword ptr cs:[0x4c445c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998236) /* 0x4c445c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488277  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488278  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488279  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48827c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048827c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048827d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048827e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488280  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488282  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488284  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488286  2eff152c444c00         -call dword ptr cs:[0x4c442c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998188) /* 0x4c442c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048828d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048828e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048828f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488290  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488291  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488292  2eff155c454c00         -call dword ptr cs:[0x4c455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998492) /* 0x4c455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488299  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048829a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48829c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048829c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048829d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048829e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004882a1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004882a4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004882a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004882ab  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004882ad  e806fcffff             -call 0x487eb8
    cpu.esp -= 4;
    sub_487eb8(app, cpu);
    if (cpu.terminate) return;
    // 004882b2  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004882b5  750b                   -jne 0x4882c2
    if (!cpu.flags.zf)
    {
        goto L_0x004882c2;
    }
    // 004882b7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004882bc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004882bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004882c2:
    // 004882c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004882c4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004882c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4882cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004882cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004882cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004882ce  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004882d1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004882d4  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004882d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004882db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004882e0  e8d3fbffff             -call 0x487eb8
    cpu.esp -= 4;
    sub_487eb8(app, cpu);
    if (cpu.terminate) return;
    // 004882e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004882e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4882ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004882ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004882ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004882ee  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004882f1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004882f4  8b0de8894d00           -mov ecx, dword ptr [0x4d89e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004882fa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004882fc  7505                   -jne 0x488303
    if (!cpu.flags.zf)
    {
        goto L_0x00488303;
    }
    // 004882fe  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x00488303:
    // 00488303  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048830a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048830c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048830f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488311  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00488314  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488316  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00488319  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048831b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048831d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00488320  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00488322  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488324  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488326  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048832b  e888fbffff             -call 0x487eb8
    cpu.esp -= 4;
    sub_487eb8(app, cpu);
    if (cpu.terminate) return;
    // 00488330  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00488333  750b                   -jne 0x488340
    if (!cpu.flags.zf)
    {
        goto L_0x00488340;
    }
    // 00488335  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048833a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048833d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048833e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048833f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488340:
    // 00488340  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488342  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488345  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488346  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488347  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488348(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488348  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488349  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0048834e  e865fbffff             -call 0x487eb8
    cpu.esp -= 4;
    sub_487eb8(app, cpu);
    if (cpu.terminate) return;
    // 00488353  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488354  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488358(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488358  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488359  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048835a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048835b  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488362  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488363  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488364  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488368(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488368  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488369  833dc4944d0000         +cmp dword ptr [0x4d94c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488370  740e                   -je 0x488380
    if (cpu.flags.zf)
    {
        goto L_0x00488380;
    }
    // 00488372  8b0dc4944d00           -mov ecx, dword ptr [0x4d94c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */);
    // 00488378  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048837a  7517                   -jne 0x488393
    if (!cpu.flags.zf)
    {
        goto L_0x00488393;
    }
    // 0048837c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048837e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048837f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488380:
    // 00488380  e8cbfaffff             -call 0x487e50
    cpu.esp -= 4;
    sub_487e50(app, cpu);
    if (cpu.terminate) return;
    // 00488385  8b0dc4944d00           -mov ecx, dword ptr [0x4d94c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */);
    // 0048838b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048838d  7504                   -jne 0x488393
    if (!cpu.flags.zf)
    {
        goto L_0x00488393;
    }
    // 0048838f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488391  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488392  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488393:
    // 00488393  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488394  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488395  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488397  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 0048839c  a3c4944d00             -mov dword ptr [0x4d94c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */) = cpu.eax;
    // 004883a1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004883a3  e8e4000000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 004883a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004883a9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004883ab  2eff1510454c00         -call dword ptr cs:[0x4c4510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998416) /* 0x4c4510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004883b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004883b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4883b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004883b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004883ba  7501                   -jne 0x4883bd
    if (!cpu.flags.zf)
    {
        goto L_0x004883bd;
    }
    // 004883bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004883bd:
    // 004883bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004883be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004883bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004883c0  2eff1550444c00         -call dword ptr cs:[0x4c4450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998224) /* 0x4c4450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004883c7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004883cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4883d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004883d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004883d2  7501                   -jne 0x4883d5
    if (!cpu.flags.zf)
    {
        goto L_0x004883d5;
    }
    // 004883d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004883d5:
    // 004883d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004883d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004883d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004883d8  2eff1514454c00         -call dword ptr cs:[0x4c4514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998420) /* 0x4c4514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004883df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4883e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004883e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004883e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004883e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004883e9  7502                   -jne 0x4883ed
    if (!cpu.flags.zf)
    {
        goto L_0x004883ed;
    }
    // 004883eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004883ed:
    // 004883ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004883ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004883ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004883f0  2eff1544444c00         -call dword ptr cs:[0x4c4444]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998212) /* 0x4c4444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004883f7  a1c4944d00             -mov eax, dword ptr [0x4d94c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */);
    // 004883fc  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 00488403  891dc4944d00           -mov dword ptr [0x4d94c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084356) /* 0x4d94c4 */) = cpu.ebx;
    // 00488409  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048840b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048840c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048840d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048840e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488410  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488412  750b                   -jne 0x48841f
    if (!cpu.flags.zf)
    {
        goto L_0x0048841f;
    }
    // 00488414  a13c205600             -mov eax, dword ptr [0x56203c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644348) /* 0x56203c */);
    // 00488419  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048841e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048841f:
    // 0048841f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488420  8b153c205600           -mov edx, dword ptr [0x56203c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644348) /* 0x56203c */);
    // 00488426  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048842c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048842d  6818dd4c00             -push 0x4cdd18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037336 /*0x4cdd18*/;
    cpu.esp -= 4;
    // 00488432  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488433  e839c5ffff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00488438  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048843b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048843c  a13c205600             -mov eax, dword ptr [0x56203c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644348) /* 0x56203c */);
    // 00488441  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00488446  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488448  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488449  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048844a  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488451  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488453  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488455  7503                   -jne 0x48845a
    if (!cpu.flags.zf)
    {
        goto L_0x0048845a;
    }
L_0x00488457:
    // 00488457  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488458  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488459  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048845a:
    // 0048845a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048845c  e8f7fbffff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 00488461  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488463  74f2                   -je 0x488457
    if (cpu.flags.zf)
    {
        goto L_0x00488457;
    }
    // 00488465  89153c205600           -mov dword ptr [0x56203c], edx
    app->getMemory<x86::reg32>(x86::reg32(5644348) /* 0x56203c */) = cpu.edx;
    // 0048846b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048846c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048846d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488470  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488471  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488473  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488475  7502                   -jne 0x488479
    if (!cpu.flags.zf)
    {
        goto L_0x00488479;
    }
L_0x00488477:
    // 00488477  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488478  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488479:
    // 00488479  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048847b  e8d8fbffff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 00488480  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488482  74f3                   -je 0x488477
    if (cpu.flags.zf)
    {
        goto L_0x00488477;
    }
    // 00488484  89153c205600           -mov dword ptr [0x56203c], edx
    app->getMemory<x86::reg32>(x86::reg32(5644348) /* 0x56203c */) = cpu.edx;
    // 0048848a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048848b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48848c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048848c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048848d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048848f  e80d000000             -call 0x4884a1
    cpu.esp -= 4;
    sub_4884a1(app, cpu);
    if (cpu.terminate) return;
    // 00488494  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488495  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488496(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488496  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00488498  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488499  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048849b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048849e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004884a0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004884a1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004884a6  0f85a7000000           -jne 0x488553
    if (!cpu.flags.zf)
    {
        goto L_0x00488553;
    }
L_0x004884ac:
    // 004884ac  83fa00                 +cmp edx, 0
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
    // 004884af  7c3f                   -jl 0x4884f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004884f0;
    }
    // 004884b1  80fbff                 +cmp bl, 0xff
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
    // 004884b4  743b                   -je 0x4884f1
    if (cpu.flags.zf)
    {
        goto L_0x004884f1;
    }
    // 004884b6  38fb                   +cmp bl, bh
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
    // 004884b8  7537                   -jne 0x4884f1
    if (!cpu.flags.zf)
    {
        goto L_0x004884f1;
    }
    // 004884ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004884bb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004884bc  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004884bf  83ea20                 +sub edx, 0x20
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
    // 004884c2  7813                   -js 0x4884d7
    if (cpu.flags.sf)
    {
        goto L_0x004884d7;
    }
L_0x004884c4:
    // 004884c4  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004884c6  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004884c9  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004884cc  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004884cf  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004884d2  83ea20                 +sub edx, 0x20
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
    // 004884d5  79ed                   -jns 0x4884c4
    if (!cpu.flags.sf)
    {
        goto L_0x004884c4;
    }
L_0x004884d7:
    // 004884d7  83c218                 +add edx, 0x18
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
    // 004884da  780a                   -js 0x4884e6
    if (cpu.flags.sf)
    {
        goto L_0x004884e6;
    }
L_0x004884dc:
    // 004884dc  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004884de  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004884e1  83ea08                 +sub edx, 8
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
    // 004884e4  79f6                   -jns 0x4884dc
    if (!cpu.flags.sf)
    {
        goto L_0x004884dc;
    }
L_0x004884e6:
    // 004884e6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004884e8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004884eb  83c208                 +add edx, 8
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
    // 004884ee  753d                   -jne 0x48852d
    if (!cpu.flags.zf)
    {
        goto L_0x0048852d;
    }
L_0x004884f0:
    // 004884f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004884f1:
    // 004884f1  83ea20                 +sub edx, 0x20
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
    // 004884f4  781f                   -js 0x488515
    if (cpu.flags.sf)
    {
        goto L_0x00488515;
    }
L_0x004884f6:
    // 004884f6  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004884f8  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004884fb  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004884fe  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00488501  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00488504  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00488507  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048850a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048850d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00488510  83ea20                 +sub edx, 0x20
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
    // 00488513  79e1                   -jns 0x4884f6
    if (!cpu.flags.sf)
    {
        goto L_0x004884f6;
    }
L_0x00488515:
    // 00488515  83c218                 +add edx, 0x18
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
    // 00488518  780d                   -js 0x488527
    if (cpu.flags.sf)
    {
        goto L_0x00488527;
    }
L_0x0048851a:
    // 0048851a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048851c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048851f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00488522  83ea08                 +sub edx, 8
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
    // 00488525  79f3                   -jns 0x48851a
    if (!cpu.flags.sf)
    {
        goto L_0x0048851a;
    }
L_0x00488527:
    // 00488527  83c208                 +add edx, 8
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
    // 0048852a  7501                   -jne 0x48852d
    if (!cpu.flags.zf)
    {
        goto L_0x0048852d;
    }
    // 0048852c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048852d:
    // 0048852d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 00488533  7405                   -je 0x48853a
    if (cpu.flags.zf)
    {
        goto L_0x0048853a;
    }
    // 00488535  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00488537  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0048853a:
    // 0048853a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00488540  7406                   -je 0x488548
    if (cpu.flags.zf)
    {
        goto L_0x00488548;
    }
    // 00488542  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00488545  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x00488548:
    // 00488548  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0048854e  7402                   -je 0x488552
    if (cpu.flags.zf)
    {
        goto L_0x00488552;
    }
    // 00488550  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x00488552:
    // 00488552  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488553:
    // 00488553  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00488558  740d                   -je 0x488567
    if (cpu.flags.zf)
    {
        goto L_0x00488567;
    }
    // 0048855a  83fa01                 +cmp edx, 1
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
    // 0048855d  7c08                   -jl 0x488567
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488567;
    }
    // 0048855f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00488561  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00488564  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00488567:
    // 00488567  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0048856c  740e                   -je 0x48857c
    if (cpu.flags.zf)
    {
        goto L_0x0048857c;
    }
    // 0048856e  83fa02                 +cmp edx, 2
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
    // 00488571  7c09                   -jl 0x48857c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048857c;
    }
    // 00488573  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00488576  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00488579  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0048857c:
    // 0048857c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00488581  740d                   -je 0x488590
    if (cpu.flags.zf)
    {
        goto L_0x00488590;
    }
    // 00488583  83fa04                 +cmp edx, 4
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
    // 00488586  7c08                   -jl 0x488590
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488590;
    }
    // 00488588  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048858a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048858d  83ea04                 +sub edx, 4
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
L_0x00488590:
    // 00488590  e917ffffff             -jmp 0x4884ac
    goto L_0x004884ac;
}

/* align: skip  */
void Application::sub_4884a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004884a1;
    // 00488496  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00488498  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488499  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048849b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048849e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004884a0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004884a1:
    // 004884a1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004884a6  0f85a7000000           -jne 0x488553
    if (!cpu.flags.zf)
    {
        goto L_0x00488553;
    }
L_0x004884ac:
    // 004884ac  83fa00                 +cmp edx, 0
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
    // 004884af  7c3f                   -jl 0x4884f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004884f0;
    }
    // 004884b1  80fbff                 +cmp bl, 0xff
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
    // 004884b4  743b                   -je 0x4884f1
    if (cpu.flags.zf)
    {
        goto L_0x004884f1;
    }
    // 004884b6  38fb                   +cmp bl, bh
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
    // 004884b8  7537                   -jne 0x4884f1
    if (!cpu.flags.zf)
    {
        goto L_0x004884f1;
    }
    // 004884ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004884bb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004884bc  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004884bf  83ea20                 +sub edx, 0x20
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
    // 004884c2  7813                   -js 0x4884d7
    if (cpu.flags.sf)
    {
        goto L_0x004884d7;
    }
L_0x004884c4:
    // 004884c4  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004884c6  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004884c9  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004884cc  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004884cf  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004884d2  83ea20                 +sub edx, 0x20
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
    // 004884d5  79ed                   -jns 0x4884c4
    if (!cpu.flags.sf)
    {
        goto L_0x004884c4;
    }
L_0x004884d7:
    // 004884d7  83c218                 +add edx, 0x18
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
    // 004884da  780a                   -js 0x4884e6
    if (cpu.flags.sf)
    {
        goto L_0x004884e6;
    }
L_0x004884dc:
    // 004884dc  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004884de  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004884e1  83ea08                 +sub edx, 8
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
    // 004884e4  79f6                   -jns 0x4884dc
    if (!cpu.flags.sf)
    {
        goto L_0x004884dc;
    }
L_0x004884e6:
    // 004884e6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004884e8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004884eb  83c208                 +add edx, 8
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
    // 004884ee  753d                   -jne 0x48852d
    if (!cpu.flags.zf)
    {
        goto L_0x0048852d;
    }
L_0x004884f0:
    // 004884f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004884f1:
    // 004884f1  83ea20                 +sub edx, 0x20
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
    // 004884f4  781f                   -js 0x488515
    if (cpu.flags.sf)
    {
        goto L_0x00488515;
    }
L_0x004884f6:
    // 004884f6  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004884f8  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004884fb  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004884fe  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00488501  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00488504  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00488507  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048850a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048850d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00488510  83ea20                 +sub edx, 0x20
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
    // 00488513  79e1                   -jns 0x4884f6
    if (!cpu.flags.sf)
    {
        goto L_0x004884f6;
    }
L_0x00488515:
    // 00488515  83c218                 +add edx, 0x18
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
    // 00488518  780d                   -js 0x488527
    if (cpu.flags.sf)
    {
        goto L_0x00488527;
    }
L_0x0048851a:
    // 0048851a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048851c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048851f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00488522  83ea08                 +sub edx, 8
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
    // 00488525  79f3                   -jns 0x48851a
    if (!cpu.flags.sf)
    {
        goto L_0x0048851a;
    }
L_0x00488527:
    // 00488527  83c208                 +add edx, 8
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
    // 0048852a  7501                   -jne 0x48852d
    if (!cpu.flags.zf)
    {
        goto L_0x0048852d;
    }
    // 0048852c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048852d:
    // 0048852d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 00488533  7405                   -je 0x48853a
    if (cpu.flags.zf)
    {
        goto L_0x0048853a;
    }
    // 00488535  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00488537  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0048853a:
    // 0048853a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00488540  7406                   -je 0x488548
    if (cpu.flags.zf)
    {
        goto L_0x00488548;
    }
    // 00488542  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00488545  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x00488548:
    // 00488548  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0048854e  7402                   -je 0x488552
    if (cpu.flags.zf)
    {
        goto L_0x00488552;
    }
    // 00488550  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x00488552:
    // 00488552  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488553:
    // 00488553  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00488558  740d                   -je 0x488567
    if (cpu.flags.zf)
    {
        goto L_0x00488567;
    }
    // 0048855a  83fa01                 +cmp edx, 1
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
    // 0048855d  7c08                   -jl 0x488567
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488567;
    }
    // 0048855f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00488561  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00488564  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00488567:
    // 00488567  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0048856c  740e                   -je 0x48857c
    if (cpu.flags.zf)
    {
        goto L_0x0048857c;
    }
    // 0048856e  83fa02                 +cmp edx, 2
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
    // 00488571  7c09                   -jl 0x48857c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048857c;
    }
    // 00488573  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00488576  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00488579  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0048857c:
    // 0048857c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00488581  740d                   -je 0x488590
    if (cpu.flags.zf)
    {
        goto L_0x00488590;
    }
    // 00488583  83fa04                 +cmp edx, 4
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
    // 00488586  7c08                   -jl 0x488590
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488590;
    }
    // 00488588  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048858a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048858d  83ea04                 +sub edx, 4
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
L_0x00488590:
    // 00488590  e917ffffff             -jmp 0x4884ac
    goto L_0x004884ac;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4885a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004885a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004885a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4885a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004885a4  833ddc984d0000         +cmp dword ptr [0x4d98dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085404) /* 0x4d98dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004885ab  7501                   -jne 0x4885ae
    if (!cpu.flags.zf)
    {
        goto L_0x004885ae;
    }
    // 004885ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004885ae:
    // 004885ae  e871010000             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
    // 004885b3  b85c205600             -mov eax, 0x56205c
    cpu.eax = 5644380 /*0x56205c*/;
    // 004885b8  e86f090000             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 004885bd  b840205600             -mov eax, 0x562040
    cpu.eax = 5644352 /*0x562040*/;
    // 004885c2  e965090000             -jmp 0x488f2c
    return sub_488f2c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4885c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004885c8  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004885cb  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 004885cf  7506                   -jne 0x4885d7
    if (!cpu.flags.zf)
    {
        goto L_0x004885d7;
    }
    // 004885d1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004885d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004885d7:
    // 004885d7  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004885da  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004885df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4885e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004885e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004885e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004885e2  bac8854800             -mov edx, 0x4885c8
    cpu.edx = 4752840 /*0x4885c8*/;
    // 004885e7  b85c205600             -mov eax, 0x56205c
    cpu.eax = 5644380 /*0x56205c*/;
    // 004885ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004885ee  e8410e0000             -call 0x489434
    cpu.esp -= 4;
    sub_489434(app, cpu);
    if (cpu.terminate) return;
    // 004885f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4885f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004885f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004885f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004885fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004885fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004885fe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00488600  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00488602  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00488606  833ddc984d0000         +cmp dword ptr [0x4d98dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085404) /* 0x4d98dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048860d  0f84b0000000           -je 0x4886c3
    if (cpu.flags.zf)
    {
        goto L_0x004886c3;
    }
L_0x00488613:
    // 00488613  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488615  745e                   -je 0x488675
    if (cpu.flags.zf)
    {
        goto L_0x00488675;
    }
    // 00488617  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 0048861b  7507                   -jne 0x488624
    if (!cpu.flags.zf)
    {
        goto L_0x00488624;
    }
    // 0048861d  c7462402000000         -mov dword ptr [esi + 0x24], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 2 /*0x2*/;
L_0x00488624:
    // 00488624  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 00488628  7507                   -jne 0x488631
    if (!cpu.flags.zf)
    {
        goto L_0x00488631;
    }
    // 0048862a  c7462804000000         -mov dword ptr [esi + 0x28], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 4 /*0x4*/;
L_0x00488631:
    // 00488631  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 00488635  7507                   -jne 0x48863e
    if (!cpu.flags.zf)
    {
        goto L_0x0048863e;
    }
    // 00488637  c7462c06000000         -mov dword ptr [esi + 0x2c], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 6 /*0x6*/;
L_0x0048863e:
    // 0048863e  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 00488642  7507                   -jne 0x48864b
    if (!cpu.flags.zf)
    {
        goto L_0x0048864b;
    }
    // 00488644  c74614a0854800         -mov dword ptr [esi + 0x14], 0x4885a0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 4752800 /*0x4885a0*/;
L_0x0048864b:
    // 0048864b  837e1c00               +cmp dword ptr [esi + 0x1c], 0
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
    // 0048864f  7507                   -jne 0x488658
    if (!cpu.flags.zf)
    {
        goto L_0x00488658;
    }
    // 00488651  c7461ca0854800         -mov dword ptr [esi + 0x1c], 0x4885a0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 4752800 /*0x4885a0*/;
L_0x00488658:
    // 00488658  837e1800               +cmp dword ptr [esi + 0x18], 0
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
    // 0048865c  7507                   -jne 0x488665
    if (!cpu.flags.zf)
    {
        goto L_0x00488665;
    }
    // 0048865e  c74618a0854800         -mov dword ptr [esi + 0x18], 0x4885a0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4752800 /*0x4885a0*/;
L_0x00488665:
    // 00488665  837e2000               +cmp dword ptr [esi + 0x20], 0
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
    // 00488669  7507                   -jne 0x488672
    if (!cpu.flags.zf)
    {
        goto L_0x00488672;
    }
    // 0048866b  c74620a0854800         -mov dword ptr [esi + 0x20], 0x4885a0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 4752800 /*0x4885a0*/;
L_0x00488672:
    // 00488672  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00488675:
    // 00488675  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488677  741f                   -je 0x488698
    if (cpu.flags.zf)
    {
        goto L_0x00488698;
    }
    // 00488679  837f0c00               +cmp dword ptr [edi + 0xc], 0
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
    // 0048867d  7419                   -je 0x488698
    if (cpu.flags.zf)
    {
        goto L_0x00488698;
    }
    // 0048867f  833de0984d0000         +cmp dword ptr [0x4d98e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085408) /* 0x4d98e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488686  750a                   -jne 0x488692
    if (!cpu.flags.zf)
    {
        goto L_0x00488692;
    }
    // 00488688  b8e0854800             -mov eax, 0x4885e0
    cpu.eax = 4752864 /*0x4885e0*/;
    // 0048868d  e8e2730100             -call 0x49fa74
    cpu.esp -= 4;
    sub_49fa74(app, cpu);
    if (cpu.terminate) return;
L_0x00488692:
    // 00488692  ff05e0984d00           -inc dword ptr [0x4d98e0]
    (app->getMemory<x86::reg32>(x86::reg32(5085408) /* 0x4d98e0 */))++;
L_0x00488698:
    // 00488698  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048869a  ff5704                 -call dword ptr [edi + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048869d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048869f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004886a1  7419                   -je 0x4886bc
    if (cpu.flags.zf)
    {
        goto L_0x004886bc;
    }
    // 004886a3  837f0c00               +cmp dword ptr [edi + 0xc], 0
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
    // 004886a7  7413                   -je 0x4886bc
    if (cpu.flags.zf)
    {
        goto L_0x004886bc;
    }
    // 004886a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004886ab  750f                   -jne 0x4886bc
    if (!cpu.flags.zf)
    {
        goto L_0x004886bc;
    }
    // 004886ad  8b1de0984d00           -mov ebx, dword ptr [0x4d98e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085408) /* 0x4d98e0 */);
    // 004886b3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004886b4  891de0984d00           -mov dword ptr [0x4d98e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5085408) /* 0x4d98e0 */) = cpu.ebx;
    // 004886ba  7411                   -je 0x4886cd
    if (cpu.flags.zf)
    {
        goto L_0x004886cd;
    }
L_0x004886bc:
    // 004886bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004886be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886c0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004886c3:
    // 004886c3  e818000000             -call 0x4886e0
    cpu.esp -= 4;
    sub_4886e0(app, cpu);
    if (cpu.terminate) return;
    // 004886c8  e946ffffff             -jmp 0x488613
    goto L_0x00488613;
L_0x004886cd:
    // 004886cd  b8e0854800             -mov eax, 0x4885e0
    cpu.eax = 4752864 /*0x4885e0*/;
    // 004886d2  e805740100             -call 0x49fadc
    cpu.esp -= 4;
    sub_49fadc(app, cpu);
    if (cpu.terminate) return;
    // 004886d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004886d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886db  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4886e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004886e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004886e1  8b15dc984d00           -mov edx, dword ptr [0x4d98dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085404) /* 0x4d98dc */);
    // 004886e7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004886e9  7402                   -je 0x4886ed
    if (cpu.flags.zf)
    {
        goto L_0x004886ed;
    }
    // 004886eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004886ed:
    // 004886ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004886ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004886ef  b85c205600             -mov eax, 0x56205c
    cpu.eax = 5644380 /*0x56205c*/;
    // 004886f4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004886f6  e8f1070000             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 004886fb  b840205600             -mov eax, 0x562040
    cpu.eax = 5644352 /*0x562040*/;
    // 00488700  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488702  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488704  e8e3070000             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 00488709  b8a4854800             -mov eax, 0x4885a4
    cpu.eax = 4752804 /*0x4885a4*/;
    // 0048870e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00488713  e8c8d50000             -call 0x495ce0
    cpu.esp -= 4;
    sub_495ce0(app, cpu);
    if (cpu.terminate) return;
    // 00488718  890ddc984d00           -mov dword ptr [0x4d98dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085404) /* 0x4d98dc */) = cpu.ecx;
    // 0048871e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048871f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488720  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488721  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488724(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488724  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488725  833ddc984d0000         +cmp dword ptr [0x4d98dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085404) /* 0x4d98dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048872c  7420                   -je 0x48874e
    if (cpu.flags.zf)
    {
        goto L_0x0048874e;
    }
L_0x0048872e:
    // 0048872e  b85c205600             -mov eax, 0x56205c
    cpu.eax = 5644380 /*0x56205c*/;
    // 00488733  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488735  e8fa0a0000             -call 0x489234
    cpu.esp -= 4;
    sub_489234(app, cpu);
    if (cpu.terminate) return;
    // 0048873a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048873c  7512                   -jne 0x488750
    if (!cpu.flags.zf)
    {
        goto L_0x00488750;
    }
L_0x0048873e:
    // 0048873e  b840205600             -mov eax, 0x562040
    cpu.eax = 5644352 /*0x562040*/;
    // 00488743  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488745  e8ea0a0000             -call 0x489234
    cpu.esp -= 4;
    sub_489234(app, cpu);
    if (cpu.terminate) return;
    // 0048874a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048874c  7509                   -jne 0x488757
    if (!cpu.flags.zf)
    {
        goto L_0x00488757;
    }
L_0x0048874e:
    // 0048874e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048874f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488750:
    // 00488750  e823000000             -call 0x488778
    cpu.esp -= 4;
    sub_488778(app, cpu);
    if (cpu.terminate) return;
    // 00488755  ebd7                   -jmp 0x48872e
    goto L_0x0048872e;
L_0x00488757:
    // 00488757  e81c000000             -call 0x488778
    cpu.esp -= 4;
    sub_488778(app, cpu);
    if (cpu.terminate) return;
    // 0048875c  ebe0                   -jmp 0x48873e
    goto L_0x0048873e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488760  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488762  7406                   -je 0x48876a
    if (cpu.flags.zf)
    {
        goto L_0x0048876a;
    }
    // 00488764  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00488768  7503                   -jne 0x48876d
    if (!cpu.flags.zf)
    {
        goto L_0x0048876d;
    }
L_0x0048876a:
    // 0048876a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048876c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048876d:
    // 0048876d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048876e  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00488771  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488775  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488778  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488779  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048877b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048877d  7406                   -je 0x488785
    if (cpu.flags.zf)
    {
        goto L_0x00488785;
    }
    // 0048877f  83781000               +cmp dword ptr [eax + 0x10], 0
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
    // 00488783  7504                   -jne 0x488789
    if (!cpu.flags.zf)
    {
        goto L_0x00488789;
    }
L_0x00488785:
    // 00488785  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488787  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488788  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488789:
    // 00488789  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048878a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048878b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048878c  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048878f  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488792  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488794  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488796  742a                   -je 0x4887c2
    if (cpu.flags.zf)
    {
        goto L_0x004887c2;
    }
    // 00488798  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048879b  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 0048879f  7421                   -je 0x4887c2
    if (cpu.flags.zf)
    {
        goto L_0x004887c2;
    }
    // 004887a1  8b35e0984d00           -mov esi, dword ptr [0x4d98e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5085408) /* 0x4d98e0 */);
    // 004887a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004887a9  7417                   -je 0x4887c2
    if (cpu.flags.zf)
    {
        goto L_0x004887c2;
    }
    // 004887ab  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004887ae  893de0984d00           -mov dword ptr [0x4d98e0], edi
    app->getMemory<x86::reg32>(x86::reg32(5085408) /* 0x4d98e0 */) = cpu.edi;
    // 004887b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004887b6  750a                   -jne 0x4887c2
    if (!cpu.flags.zf)
    {
        goto L_0x004887c2;
    }
    // 004887b8  b8e0854800             -mov eax, 0x4885e0
    cpu.eax = 4752864 /*0x4885e0*/;
    // 004887bd  e81a730100             -call 0x49fadc
    cpu.esp -= 4;
    sub_49fadc(app, cpu);
    if (cpu.terminate) return;
L_0x004887c2:
    // 004887c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004887c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4887c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004887c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004887ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004887cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004887cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004887cd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004887ce  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004887d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004887d3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004887d8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004887da  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004887dc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004887de  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004887e1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004887e3  740e                   -je 0x4887f3
    if (cpu.flags.zf)
    {
        goto L_0x004887f3;
    }
    // 004887e5  3b0d04c94d00           +cmp ecx, dword ptr [0x4dc904]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5097732) /* 0x4dc904 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004887eb  7504                   -jne 0x4887f1
    if (!cpu.flags.zf)
    {
        goto L_0x004887f1;
    }
    // 004887ed  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004887ef  eb02                   -jmp 0x4887f3
    goto L_0x004887f3;
L_0x004887f1:
    // 004887f1  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
L_0x004887f3:
    // 004887f3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004887f5  3c72                   +cmp al, 0x72
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
    // 004887f7  7208                   -jb 0x488801
    if (cpu.flags.cf)
    {
        goto L_0x00488801;
    }
    // 004887f9  760c                   -jbe 0x488807
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488807;
    }
    // 004887fb  3c77                   +cmp al, 0x77
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
    // 004887fd  740e                   -je 0x48880d
    if (cpu.flags.zf)
    {
        goto L_0x0048880d;
    }
    // 004887ff  eb18                   -jmp 0x488819
    goto L_0x00488819;
L_0x00488801:
    // 00488801  3c61                   +cmp al, 0x61
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
    // 00488803  740e                   -je 0x488813
    if (cpu.flags.zf)
    {
        goto L_0x00488813;
    }
    // 00488805  eb12                   -jmp 0x488819
    goto L_0x00488819;
L_0x00488807:
    // 00488807  800c2401               +or byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0048880b  eb1d                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x0048880d:
    // 0048880d  800c2402               +or byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00488811  eb17                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x00488813:
    // 00488813  800c2482               +or byte ptr [esp], 0x82
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(130 /*0x82*/))));
    // 00488817  eb11                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x00488819:
    // 00488819  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0048881e  e8fd990100             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 00488823  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00488825  e9af000000             -jmp 0x4888d9
    goto L_0x004888d9;
L_0x0048882a:
    // 0048882a  43                     -inc ebx
    (cpu.ebx)++;
    // 0048882b  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0048882d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048882f  0f848d000000           -je 0x4888c2
    if (cpu.flags.zf)
    {
        goto L_0x004888c2;
    }
    // 00488835  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488837  0f8485000000           -je 0x4888c2
    if (cpu.flags.zf)
    {
        goto L_0x004888c2;
    }
    // 0048883d  3c63                   +cmp al, 0x63
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
    // 0048883f  7216                   -jb 0x488857
    if (cpu.flags.cf)
    {
        goto L_0x00488857;
    }
    // 00488841  0f8652000000           -jbe 0x488899
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488899;
    }
    // 00488847  3c6e                   +cmp al, 0x6e
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
    // 00488849  72df                   -jb 0x48882a
    if (cpu.flags.cf)
    {
        goto L_0x0048882a;
    }
    // 0048884b  0f865d000000           -jbe 0x4888ae
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004888ae;
    }
    // 00488851  3c74                   +cmp al, 0x74
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
    // 00488853  7426                   -je 0x48887b
    if (cpu.flags.zf)
    {
        goto L_0x0048887b;
    }
    // 00488855  ebd3                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x00488857:
    // 00488857  3c2b                   +cmp al, 0x2b
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
    // 00488859  72cf                   -jb 0x48882a
    if (cpu.flags.cf)
    {
        goto L_0x0048882a;
    }
    // 0048885b  7606                   -jbe 0x488863
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488863;
    }
    // 0048885d  3c62                   +cmp al, 0x62
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
    // 0048885f  7425                   -je 0x488886
    if (cpu.flags.zf)
    {
        goto L_0x00488886;
    }
    // 00488861  ebc7                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x00488863:
    // 00488863  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488865  7404                   -je 0x48886b
    if (cpu.flags.zf)
    {
        goto L_0x0048886b;
    }
L_0x00488867:
    // 00488867  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00488869  ebbf                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x0048886b:
    // 0048886b  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 0048886e  80cc03                 +or ah, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00488871  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00488876  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00488879  ebaf                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x0048887b:
    // 0048887b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048887d  75e8                   -jne 0x488867
    if (!cpu.flags.zf)
    {
        goto L_0x00488867;
    }
    // 0048887f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00488884  eba4                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x00488886:
    // 00488886  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488888  75dd                   -jne 0x488867
    if (!cpu.flags.zf)
    {
        goto L_0x00488867;
    }
    // 0048888a  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048888d  0c40                   +or al, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0048888f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00488894  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00488897  eb91                   -jmp 0x48882a
    goto L_0x0048882a;
L_0x00488899:
    // 00488899  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048889b  75ca                   -jne 0x488867
    if (!cpu.flags.zf)
    {
        goto L_0x00488867;
    }
    // 0048889d  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0048889f  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004888a2  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004888a7  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 004888a9  e97cffffff             -jmp 0x48882a
    goto L_0x0048882a;
L_0x004888ae:
    // 004888ae  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004888b0  75b5                   -jne 0x488867
    if (!cpu.flags.zf)
    {
        goto L_0x00488867;
    }
    // 004888b2  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004888b4  24fe                   +and al, 0xfe
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 004888b6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004888bb  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004888bd  e968ffffff             -jmp 0x48882a
    goto L_0x0048882a;
L_0x004888c2:
    // 004888c2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004888c4  7510                   -jne 0x4888d6
    if (!cpu.flags.zf)
    {
        goto L_0x004888d6;
    }
    // 004888c6  813d11cb4d0000020000   +cmp dword ptr [0x4dcb11], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098257) /* 0x4dcb11 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004888d0  7504                   -jne 0x4888d6
    if (!cpu.flags.zf)
    {
        goto L_0x004888d6;
    }
    // 004888d2  800c2440               -or byte ptr [esp], 0x40
    app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004888d6:
    // 004888d6  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004888d9:
    // 004888d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004888db  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004888de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4888e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004888e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004888e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004888e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004888e7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004888e9  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004888eb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004888ed  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004888f1  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004888f5  09590c                 -or dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004888f8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004888fd  e898ca0100             -call 0x4a539a
    cpu.esp -= 4;
    sub_4a539a(app, cpu);
    if (cpu.terminate) return;
    // 00488902  3c72                   +cmp al, 0x72
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
    // 00488904  7522                   -jne 0x488928
    if (!cpu.flags.zf)
    {
        goto L_0x00488928;
    }
    // 00488906  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488908  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0048890b  7405                   -je 0x488912
    if (cpu.flags.zf)
    {
        goto L_0x00488912;
    }
    // 0048890d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00488912:
    // 00488912  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00488915  7405                   -je 0x48891c
    if (cpu.flags.zf)
    {
        goto L_0x0048891c;
    }
    // 00488917  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048891a  eb03                   -jmp 0x48891f
    goto L_0x0048891f;
L_0x0048891c:
    // 0048891c  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x0048891f:
    // 0048891f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488921  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00488925  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488926  eb30                   -jmp 0x488958
    goto L_0x00488958;
L_0x00488928:
    // 00488928  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0048892b  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0048892e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00488933  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 00488936  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00488939  7404                   -je 0x48893f
    if (cpu.flags.zf)
    {
        goto L_0x0048893f;
    }
    // 0048893b  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048893d  eb02                   -jmp 0x488941
    goto L_0x00488941;
L_0x0048893f:
    // 0048893f  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00488941:
    // 00488941  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00488944  7405                   -je 0x48894b
    if (cpu.flags.zf)
    {
        goto L_0x0048894b;
    }
    // 00488946  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00488949  eb03                   -jmp 0x48894e
    goto L_0x0048894e;
L_0x0048894b:
    // 0048894b  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048894e:
    // 0048894e  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 00488953  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00488957  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00488958:
    // 00488958  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488959  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048895a  e86dca0100             -call 0x4a53cc
    cpu.esp -= 4;
    sub_4a53cc(app, cpu);
    if (cpu.terminate) return;
    // 0048895f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00488962  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00488965  837910ff               +cmp dword ptr [ecx + 0x10], -1
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
    // 00488969  750b                   -jne 0x488976
    if (!cpu.flags.zf)
    {
        goto L_0x00488976;
    }
    // 0048896b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048896d  e845cd0100             -call 0x4a56b7
    cpu.esp -= 4;
    sub_4a56b7(app, cpu);
    if (cpu.terminate) return;
    // 00488972  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488974  eb4e                   -jmp 0x4889c4
    goto L_0x004889c4;
L_0x00488976:
    // 00488976  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048897d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488980  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00488987  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048898e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488991  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00488994  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488997  c7401500000000         -mov dword ptr [eax + 0x15], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 0048899e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004889a1  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004889a8  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004889ab  740e                   -je 0x4889bb
    if (cpu.flags.zf)
    {
        goto L_0x004889bb;
    }
    // 004889ad  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004889b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004889b4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004889b6  e8a8cd0100             -call 0x4a5763
    cpu.esp -= 4;
    sub_4a5763(app, cpu);
    if (cpu.terminate) return;
L_0x004889bb:
    // 004889bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004889bd  e8b1ce0100             -call 0x4a5873
    cpu.esp -= 4;
    sub_4a5873(app, cpu);
    if (cpu.terminate) return;
    // 004889c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004889c4:
    // 004889c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889c7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4889ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004889ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004889cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004889cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004889cd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004889d0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004889d2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004889d4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004889d6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004889d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004889da  e8eafdffff             -call 0x4887c9
    cpu.esp -= 4;
    sub_4887c9(app, cpu);
    if (cpu.terminate) return;
    // 004889df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004889e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004889e3  7422                   -je 0x488a07
    if (cpu.flags.zf)
    {
        goto L_0x00488a07;
    }
    // 004889e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004889e7  e810cc0100             -call 0x4a55fc
    cpu.esp -= 4;
    sub_4a55fc(app, cpu);
    if (cpu.terminate) return;
    // 004889ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004889ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004889f0  7413                   -je 0x488a05
    if (cpu.flags.zf)
    {
        goto L_0x00488a05;
    }
    // 004889f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004889f3  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004889f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004889f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004889f8  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004889fa  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004889fe  e8e1feffff             -call 0x4888e4
    cpu.esp -= 4;
    sub_4888e4(app, cpu);
    if (cpu.terminate) return;
    // 00488a03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00488a05:
    // 00488a05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00488a07:
    // 00488a07  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488a0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488a0e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488a0e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488a0f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488a11  e8b4ffffff             -call 0x4889ca
    cpu.esp -= 4;
    sub_4889ca(app, cpu);
    if (cpu.terminate) return;
    // 00488a16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488a18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488a19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488a1a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488a1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488a1d  ff1530cb4d00           -call dword ptr [0x4dcb30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098288) /* 0x4dcb30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488a23  a1e4435b00             -mov eax, dword ptr [0x5b43e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
L_0x00488a28:
    // 00488a28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488a2a  7429                   -je 0x488a55
    if (cpu.flags.zf)
    {
        goto L_0x00488a55;
    }
    // 00488a2c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00488a2f  39d3                   +cmp ebx, edx
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
    // 00488a31  751e                   -jne 0x488a51
    if (!cpu.flags.zf)
    {
        goto L_0x00488a51;
    }
    // 00488a33  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00488a37  740c                   -je 0x488a45
    if (cpu.flags.zf)
    {
        goto L_0x00488a45;
    }
    // 00488a39  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00488a3e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488a40  e8ec020000             -call 0x488d31
    cpu.esp -= 4;
    sub_488d31(app, cpu);
    if (cpu.terminate) return;
L_0x00488a45:
    // 00488a45  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488a4b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488a4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488a51:
    // 00488a51  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488a53  ebd3                   -jmp 0x488a28
    goto L_0x00488a28;
L_0x00488a55:
    // 00488a55  bae8435b00             -mov edx, 0x5b43e8
    cpu.edx = 5981160 /*0x5b43e8*/;
L_0x00488a5a:
    // 00488a5a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00488a5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488a5e  741c                   -je 0x488a7c
    if (cpu.flags.zf)
    {
        goto L_0x00488a7c;
    }
    // 00488a60  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00488a63  7513                   -jne 0x488a78
    if (!cpu.flags.zf)
    {
        goto L_0x00488a78;
    }
    // 00488a65  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488a67  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00488a69  8b15e4435b00           -mov edx, dword ptr [0x5b43e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
    // 00488a6f  a3e4435b00             -mov dword ptr [0x5b43e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */) = cpu.eax;
    // 00488a74  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00488a76  ebcd                   -jmp 0x488a45
    goto L_0x00488a45;
L_0x00488a78:
    // 00488a78  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488a7a  ebde                   -jmp 0x488a5a
    goto L_0x00488a5a;
L_0x00488a7c:
    // 00488a7c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00488a81  e89a970100             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 00488a86  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488a8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488a8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488a92(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488a92  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488a93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488a94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488a95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488a96  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488a99  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00488a9b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00488a9d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488a9f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488aa1  e823fdffff             -call 0x4887c9
    cpu.esp -= 4;
    sub_4887c9(app, cpu);
    if (cpu.terminate) return;
    // 00488aa6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00488aa8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488aaa  7455                   -je 0x488b01
    if (cpu.flags.zf)
    {
        goto L_0x00488b01;
    }
    // 00488aac  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00488aaf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488ab1  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488ab7  833d6ccb4d0000         +cmp dword ptr [0x4dcb6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098348) /* 0x4dcb6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488abe  7408                   -je 0x488ac8
    if (cpu.flags.zf)
    {
        goto L_0x00488ac8;
    }
    // 00488ac0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488ac2  ff156ccb4d00           -call dword ptr [0x4dcb6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098348) /* 0x4dcb6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00488ac8:
    // 00488ac8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488aca  e849ffffff             -call 0x488a18
    cpu.esp -= 4;
    sub_488a18(app, cpu);
    if (cpu.terminate) return;
    // 00488acf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488ad1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488ad3  7422                   -je 0x488af7
    if (cpu.flags.zf)
    {
        goto L_0x00488af7;
    }
    // 00488ad5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488ad6  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00488ad9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488adb  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 00488ae1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488ae3  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00488ae6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00488ae8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488aea  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00488aec  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488af0  e8effdffff             -call 0x4888e4
    cpu.esp -= 4;
    sub_4888e4(app, cpu);
    if (cpu.terminate) return;
    // 00488af5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00488af7:
    // 00488af7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488af9  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488aff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00488b01:
    // 00488b01  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488b04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488b09(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488b09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488b0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488b0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488b0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488b0d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488b10  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488b12  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00488b14  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00488b17  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00488b19  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488b1f  8a630c                 -mov ah, byte ptr [ebx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00488b22  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00488b25  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 00488b28  83e730                 -and edi, 0x30
    cpu.edi &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00488b2b  88630c                 -mov byte ptr [ebx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x00488b2e:
    // 00488b2e  49                     -dec ecx
    (cpu.ecx)--;
    // 00488b2f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488b31  7e19                   -jle 0x488b4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488b4c;
    }
    // 00488b33  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488b35  e845d00100             -call 0x4a5b7f
    cpu.esp -= 4;
    sub_4a5b7f(app, cpu);
    if (cpu.terminate) return;
    // 00488b3a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00488b3d  83f8ff                 +cmp eax, -1
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
    // 00488b40  740a                   -je 0x488b4c
    if (cpu.flags.zf)
    {
        goto L_0x00488b4c;
    }
    // 00488b42  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00488b45  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00488b47  42                     -inc edx
    (cpu.edx)++;
    // 00488b48  3c0a                   +cmp al, 0xa
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
    // 00488b4a  75e2                   -jne 0x488b2e
    if (!cpu.flags.zf)
    {
        goto L_0x00488b2e;
    }
L_0x00488b4c:
    // 00488b4c  833c24ff               +cmp dword ptr [esp], -1
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
    // 00488b50  750e                   -jne 0x488b60
    if (!cpu.flags.zf)
    {
        goto L_0x00488b60;
    }
    // 00488b52  39f2                   +cmp edx, esi
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
    // 00488b54  7406                   -je 0x488b5c
    if (cpu.flags.zf)
    {
        goto L_0x00488b5c;
    }
    // 00488b56  f6430c20               +test byte ptr [ebx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 00488b5a  7404                   -je 0x488b60
    if (cpu.flags.zf)
    {
        goto L_0x00488b60;
    }
L_0x00488b5c:
    // 00488b5c  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00488b5e  eb03                   -jmp 0x488b63
    goto L_0x00488b63;
L_0x00488b60:
    // 00488b60  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x00488b63:
    // 00488b63  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00488b66  09fd                   -or ebp, edi
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edi));
    // 00488b68  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00488b6b  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00488b6e  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488b74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488b76  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488b79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488b7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488b7e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488b7f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488b80  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488b82  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00488b85  e8f5cf0100             -call 0x4a5b7f
    cpu.esp -= 4;
    sub_4a5b7f(app, cpu);
    if (cpu.terminate) return;
    // 00488b8a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488b8c  83f8ff                 +cmp eax, -1
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
    // 00488b8f  7504                   -jne 0x488b95
    if (!cpu.flags.zf)
    {
        goto L_0x00488b95;
    }
    // 00488b91  804a1002               -or byte ptr [edx + 0x10], 2
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00488b95:
    // 00488b95  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488b97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488b9a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488b9a  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00488b9d  e985d10100             -jmp 0x4a5d27
    return sub_4a5d27(app, cpu);
}

/* align: skip  */
void Application::sub_488ba2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488ba2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488ba3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488ba4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488ba5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00488ba8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488baa  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00488bad  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488bb3  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488bb6  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00488bb9  83fe01                 +cmp esi, 1
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
    // 00488bbc  7418                   -je 0x488bd6
    if (cpu.flags.zf)
    {
        goto L_0x00488bd6;
    }
    // 00488bbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488bc0  740d                   -je 0x488bcf
    if (cpu.flags.zf)
    {
        goto L_0x00488bcf;
    }
    // 00488bc2  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00488bc5  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488bcb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488bcd  eb30                   -jmp 0x488bff
    goto L_0x00488bff;
L_0x00488bcf:
    // 00488bcf  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00488bd6:
    // 00488bd6  bd7e8b4800             -mov ebp, 0x488b7e
    cpu.ebp = 4754302 /*0x488b7e*/;
    // 00488bdb  b89a8b4800             -mov eax, 0x488b9a
    cpu.eax = 4754330 /*0x488b9a*/;
    // 00488be0  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00488be4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00488be8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488bea  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00488bed  e8fed10100             -call 0x4a5df0
    cpu.esp -= 4;
    sub_4a5df0(app, cpu);
    if (cpu.terminate) return;
    // 00488bf2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488bf4  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00488bf7  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488bfd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00488bff:
    // 00488bff  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00488c02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488c06(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488c06  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488c07  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488c08  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488c0b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00488c0f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00488c11  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00488c15  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00488c18  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00488c1c  e881ffffff             -call 0x488ba2
    cpu.esp -= 4;
    sub_488ba2(app, cpu);
    if (cpu.terminate) return;
    // 00488c21  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488c24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488c27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488c27  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488c28  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488c29  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488c2b  ff1530cb4d00           -call dword ptr [0x4dcb30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098288) /* 0x4dcb30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488c31  a1e4435b00             -mov eax, dword ptr [0x5b43e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
L_0x00488c36:
    // 00488c36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488c38  750e                   -jne 0x488c48
    if (!cpu.flags.zf)
    {
        goto L_0x00488c48;
    }
    // 00488c3a  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488c40  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488c45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488c48:
    // 00488c48  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00488c4b  7404                   -je 0x488c51
    if (cpu.flags.zf)
    {
        goto L_0x00488c51;
    }
    // 00488c4d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488c4f  ebe5                   -jmp 0x488c36
    goto L_0x00488c36;
L_0x00488c51:
    // 00488c51  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488c57  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00488c5c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488c5e  e803000000             -call 0x488c66
    cpu.esp -= 4;
    sub_488c66(app, cpu);
    if (cpu.terminate) return;
    // 00488c63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488c66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488c66  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488c67  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488c69  e8c3000000             -call 0x488d31
    cpu.esp -= 4;
    sub_488d31(app, cpu);
    if (cpu.terminate) return;
    // 00488c6e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488c70  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488c72  e840ca0100             -call 0x4a56b7
    cpu.esp -= 4;
    sub_4a56b7(app, cpu);
    if (cpu.terminate) return;
    // 00488c77  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488c79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488c7b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488c7b  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00488c7e  83f839                 +cmp eax, 0x39
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488c81  7e03                   -jle 0x488c86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488c86;
    }
    // 00488c83  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x00488c86:
    // 00488c86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488c87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488c87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488c88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488c89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488c8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488c8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488c8c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488c8f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00488c91  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00488c94  e8eddf0100             -call 0x4a6c86
    cpu.esp -= 4;
    sub_4a6c86(app, cpu);
    if (cpu.terminate) return;
    // 00488c99  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488c9b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00488c9e  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00488ca0  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00488ca2  e8e0e00100             -call 0x4a6d87
    cpu.esp -= 4;
    sub_4a6d87(app, cpu);
    if (cpu.terminate) return;
    // 00488ca7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488ca9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00488caa:
    // 00488caa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00488cac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00488cae  3c00                   +cmp al, 0
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
    // 00488cb0  7410                   -je 0x488cc2
    if (cpu.flags.zf)
    {
        goto L_0x00488cc2;
    }
    // 00488cb2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00488cb5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488cb8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00488cbb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488cbe  3c00                   +cmp al, 0
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
    // 00488cc0  75e8                   -jne 0x488caa
    if (!cpu.flags.zf)
    {
        goto L_0x00488caa;
    }
L_0x00488cc2:
    // 00488cc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488cc3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00488cc4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00488cc6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00488cc8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488cca  49                     -dec ecx
    (cpu.ecx)--;
    // 00488ccb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488ccd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00488ccf  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00488cd1  49                     -dec ecx
    (cpu.ecx)--;
    // 00488cd2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00488cd3  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00488cd5  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00488cd8  c60174                 -mov byte ptr [ecx], 0x74
    app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 00488cdb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00488cdd:
    // 00488cdd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488cdf  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00488ce2  e894ffffff             -call 0x488c7b
    cpu.esp -= 4;
    sub_488c7b(app, cpu);
    if (cpu.terminate) return;
    // 00488ce7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00488ce9  4a                     -dec edx
    (cpu.edx)--;
    // 00488cea  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 00488ced  39f2                   +cmp edx, esi
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
    // 00488cef  75ec                   -jne 0x488cdd
    if (!cpu.flags.zf)
    {
        goto L_0x00488cdd;
    }
    // 00488cf1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488cf4  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00488cf7  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00488cfa  c641055f               -mov byte ptr [ecx + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 00488cfe  e878ffffff             -call 0x488c7b
    cpu.esp -= 4;
    sub_488c7b(app, cpu);
    if (cpu.terminate) return;
    // 00488d03  884106                 -mov byte ptr [ecx + 6], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00488d06  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488d09  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00488d0c  e86affffff             -call 0x488c7b
    cpu.esp -= 4;
    sub_488c7b(app, cpu);
    if (cpu.terminate) return;
    // 00488d11  c641082e               -mov byte ptr [ecx + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00488d15  c6410974               -mov byte ptr [ecx + 9], 0x74
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00488d19  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 00488d1d  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00488d21  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00488d25  884107                 -mov byte ptr [ecx + 7], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00488d28  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488d2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488d2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00488d2b;
    // 00488c87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488c88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488c89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488c8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488c8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488c8c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488c8f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00488c91  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00488c94  e8eddf0100             -call 0x4a6c86
    cpu.esp -= 4;
    sub_4a6c86(app, cpu);
    if (cpu.terminate) return;
    // 00488c99  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488c9b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00488c9e  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00488ca0  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00488ca2  e8e0e00100             -call 0x4a6d87
    cpu.esp -= 4;
    sub_4a6d87(app, cpu);
    if (cpu.terminate) return;
    // 00488ca7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488ca9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00488caa:
    // 00488caa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00488cac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00488cae  3c00                   +cmp al, 0
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
    // 00488cb0  7410                   -je 0x488cc2
    if (cpu.flags.zf)
    {
        goto L_0x00488cc2;
    }
    // 00488cb2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00488cb5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488cb8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00488cbb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488cbe  3c00                   +cmp al, 0
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
    // 00488cc0  75e8                   -jne 0x488caa
    if (!cpu.flags.zf)
    {
        goto L_0x00488caa;
    }
L_0x00488cc2:
    // 00488cc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488cc3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00488cc4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00488cc6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00488cc8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488cca  49                     -dec ecx
    (cpu.ecx)--;
    // 00488ccb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488ccd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00488ccf  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00488cd1  49                     -dec ecx
    (cpu.ecx)--;
    // 00488cd2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00488cd3  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00488cd5  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00488cd8  c60174                 -mov byte ptr [ecx], 0x74
    app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 00488cdb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00488cdd:
    // 00488cdd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488cdf  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00488ce2  e894ffffff             -call 0x488c7b
    cpu.esp -= 4;
    sub_488c7b(app, cpu);
    if (cpu.terminate) return;
    // 00488ce7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00488ce9  4a                     -dec edx
    (cpu.edx)--;
    // 00488cea  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 00488ced  39f2                   +cmp edx, esi
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
    // 00488cef  75ec                   -jne 0x488cdd
    if (!cpu.flags.zf)
    {
        goto L_0x00488cdd;
    }
    // 00488cf1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488cf4  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00488cf7  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00488cfa  c641055f               -mov byte ptr [ecx + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 00488cfe  e878ffffff             -call 0x488c7b
    cpu.esp -= 4;
    sub_488c7b(app, cpu);
    if (cpu.terminate) return;
    // 00488d03  884106                 -mov byte ptr [ecx + 6], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00488d06  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488d09  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00488d0c  e86affffff             -call 0x488c7b
    cpu.esp -= 4;
    sub_488c7b(app, cpu);
    if (cpu.terminate) return;
    // 00488d11  c641082e               -mov byte ptr [ecx + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00488d15  c6410974               -mov byte ptr [ecx + 9], 0x74
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00488d19  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 00488d1d  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00488d21  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00488d25  884107                 -mov byte ptr [ecx + 7], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00488d28  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_entry_0x00488d2b:
    // 00488d2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488d31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488d31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488d32  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488d33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488d34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488d35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488d36  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00488d3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488d3e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00488d40  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00488d44  750a                   -jne 0x488d50
    if (!cpu.flags.zf)
    {
        goto L_0x00488d50;
    }
    // 00488d46  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488d4b  e993000000             -jmp 0x488de3
    goto L_0x00488de3;
L_0x00488d50:
    // 00488d50  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00488d53  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00488d55  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00488d58  7409                   -je 0x488d63
    if (cpu.flags.zf)
    {
        goto L_0x00488d63;
    }
    // 00488d5a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488d5c  e8eee00100             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
    // 00488d61  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00488d63:
    // 00488d63  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00488d66  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488d6c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488d6e  e8ebe10100             -call 0x4a6f5e
    cpu.esp -= 4;
    sub_4a6f5e(app, cpu);
    if (cpu.terminate) return;
    // 00488d73  83f8ff                 +cmp eax, -1
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
    // 00488d76  740e                   -je 0x488d86
    if (cpu.flags.zf)
    {
        goto L_0x00488d86;
    }
    // 00488d78  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488d7a  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00488d7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488d7f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00488d81  e831e20100             -call 0x4a6fb7
    cpu.esp -= 4;
    sub_4a6fb7(app, cpu);
    if (cpu.terminate) return;
L_0x00488d86:
    // 00488d86  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00488d88  740a                   -je 0x488d94
    if (cpu.flags.zf)
    {
        goto L_0x00488d94;
    }
    // 00488d8a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00488d8d  e899e20100             -call 0x4a702b
    cpu.esp -= 4;
    sub_4a702b(app, cpu);
    if (cpu.terminate) return;
    // 00488d92  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00488d94:
    // 00488d94  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 00488d98  7415                   -je 0x488daf
    if (cpu.flags.zf)
    {
        goto L_0x00488daf;
    }
    // 00488d9a  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488d9d  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00488da0  e813e30100             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 00488da5  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488da8  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00488daf:
    // 00488daf  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00488db3  7416                   -je 0x488dcb
    if (cpu.flags.zf)
    {
        goto L_0x00488dcb;
    }
    // 00488db5  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488db8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488dba  8a5014                 -mov dl, byte ptr [eax + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00488dbd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488dbf  e8c3feffff             -call 0x488c87
    cpu.esp -= 4;
    sub_488c87(app, cpu);
    if (cpu.terminate) return;
    // 00488dc4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488dc6  e8f1e30100             -call 0x4a71bc
    cpu.esp -= 4;
    sub_4a71bc(app, cpu);
    if (cpu.terminate) return;
L_0x00488dcb:
    // 00488dcb  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00488dce  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488dd4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00488dd6  7409                   -je 0x488de1
    if (cpu.flags.zf)
    {
        goto L_0x00488de1;
    }
    // 00488dd8  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00488ddb  ff152ccb4d00           -call dword ptr [0x4dcb2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098284) /* 0x4dcb2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00488de1:
    // 00488de1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00488de3:
    // 00488de3  81c414010000           +add esp, 0x114
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(276 /*0x114*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00488de9  e93dffffff             -jmp 0x488d2b
    return sub_488d2b(app, cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_488df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488df3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488df5  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00488df8  baeafb0000             -mov edx, 0xfbea
    cpu.edx = 64490 /*0xfbea*/;
    // 00488dfd  39f0                   +cmp eax, esi
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
    // 00488dff  7323                   -jae 0x488e24
    if (!cpu.flags.cf)
    {
        goto L_0x00488e24;
    }
L_0x00488e01:
    // 00488e01  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488e03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e05  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00488e07  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00488e09  31d9                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e0b  668b0c4de8984d00       -mov cx, word ptr [ecx*2 + 0x4d98e8]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5085416) /* 0x4d98e8 */ + cpu.ecx * 2);
    // 00488e13  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00488e19  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00488e1c  40                     -inc eax
    (cpu.eax)++;
    // 00488e1d  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488e1f  39f0                   +cmp eax, esi
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
    // 00488e21  72de                   -jb 0x488e01
    if (cpu.flags.cf)
    {
        goto L_0x00488e01;
    }
    // 00488e23  90                     -nop 
    ;
L_0x00488e24:
    // 00488e24  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488e26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_488e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488e34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e34  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488e36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488e38  740c                   -je 0x488e46
    if (cpu.flags.zf)
    {
        goto L_0x00488e46;
    }
L_0x00488e3a:
    // 00488e3a  4a                     -dec edx
    (cpu.edx)--;
    // 00488e3b  83faff                 +cmp edx, -1
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
    // 00488e3e  7406                   -je 0x488e46
    if (cpu.flags.zf)
    {
        goto L_0x00488e46;
    }
    // 00488e40  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488e42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488e44  75f4                   -jne 0x488e3a
    if (!cpu.flags.zf)
    {
        goto L_0x00488e3a;
    }
L_0x00488e46:
    // 00488e46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488e48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488e4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488e4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488e4c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488e4d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488e4f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e51  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488e53  7441                   -je 0x488e96
    if (cpu.flags.zf)
    {
        goto L_0x00488e96;
    }
    // 00488e55  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00488e57  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488e59  763b                   -jbe 0x488e96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488e96;
    }
    // 00488e5b  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00488e5e  39fa                   +cmp edx, edi
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
    // 00488e60  743c                   -je 0x488e9e
    if (cpu.flags.zf)
    {
        goto L_0x00488e9e;
    }
    // 00488e62  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 00488e64  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488e66  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488e68  740b                   -je 0x488e75
    if (cpu.flags.zf)
    {
        goto L_0x00488e75;
    }
L_0x00488e6a:
    // 00488e6a  3b10                   +cmp edx, dword ptr [eax]
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
    // 00488e6c  7407                   -je 0x488e75
    if (cpu.flags.zf)
    {
        goto L_0x00488e75;
    }
    // 00488e6e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488e70  833800                 +cmp dword ptr [eax], 0
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
    // 00488e73  75f5                   -jne 0x488e6a
    if (!cpu.flags.zf)
    {
        goto L_0x00488e6a;
    }
L_0x00488e75:
    // 00488e75  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00488e77  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488e79  7417                   -je 0x488e92
    if (cpu.flags.zf)
    {
        goto L_0x00488e92;
    }
    // 00488e7b  39f2                   +cmp edx, esi
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
    // 00488e7d  7513                   -jne 0x488e92
    if (!cpu.flags.zf)
    {
        goto L_0x00488e92;
    }
    // 00488e7f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00488e84  2919                   -sub dword ptr [ecx], ebx
    (app->getMemory<x86::reg32>(cpu.ecx)) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e86  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00488e88  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00488e8a  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
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
    // 00488e8d  7503                   -jne 0x488e92
    if (!cpu.flags.zf)
    {
        goto L_0x00488e92;
    }
    // 00488e8f  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00488e92:
    // 00488e92  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488e94  7544                   -jne 0x488eda
    if (!cpu.flags.zf)
    {
        goto L_0x00488eda;
    }
L_0x00488e96:
    // 00488e96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488e98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488e9e:
    // 00488e9e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00488ea3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488ea5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488ea7  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00488eaa  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00488eac  39f7                   +cmp edi, esi
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
    // 00488eae  7519                   -jne 0x488ec9
    if (!cpu.flags.zf)
    {
        goto L_0x00488ec9;
    }
    // 00488eb0  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00488eb7  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488eba  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00488ebd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488ebf  7519                   -jne 0x488eda
    if (!cpu.flags.zf)
    {
        goto L_0x00488eda;
    }
    // 00488ec1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488ec3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488ec9:
    // 00488ec9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00488ecb  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00488ece  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488ed0  7508                   -jne 0x488eda
    if (!cpu.flags.zf)
    {
        goto L_0x00488eda;
    }
    // 00488ed2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488ed4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ed5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ed6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ed7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ed8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ed9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488eda:
    // 00488eda  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00488ee0  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00488ee4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488ee6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ee7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ee8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488eea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488eeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488eec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488eec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488eed  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488eef  e874f4ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 00488ef4  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00488efa  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00488f01  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00488f08  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00488f0f  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00488f12  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488f14  7408                   -je 0x488f1e
    if (cpu.flags.zf)
    {
        goto L_0x00488f1e;
    }
    // 00488f16  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00488f19  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00488f1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488f1e:
    // 00488f1e  ba308e4800             -mov edx, 0x488e30
    cpu.edx = 4754992 /*0x488e30*/;
    // 00488f23  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00488f26  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00488f29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488f2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f2c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f2d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488f2f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00488f32  e8adf4ffff             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 00488f37  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00488f3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488f41  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488f43  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00488f46  e86df4ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00488f4b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488f4d  741b                   -je 0x488f6a
    if (cpu.flags.zf)
    {
        goto L_0x00488f6a;
    }
    // 00488f4f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488f50  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00488f53  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00488f55  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488f57  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00488f5a  43                     -inc ebx
    (cpu.ebx)++;
    // 00488f5b  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00488f5d  833a00                 +cmp dword ptr [edx], 0
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
    // 00488f60  7503                   -jne 0x488f65
    if (!cpu.flags.zf)
    {
        goto L_0x00488f65;
    }
    // 00488f62  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00488f65:
    // 00488f65  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00488f69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00488f6a:
    // 00488f6a  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00488f6d  e85ef4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00488f72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488f75  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488f77  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00488f7a  e839f4ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00488f7f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488f81  741e                   -je 0x488fa1
    if (cpu.flags.zf)
    {
        goto L_0x00488fa1;
    }
    // 00488f83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488f84  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00488f87  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00488f8d  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488f8f  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00488f92  43                     -inc ebx
    (cpu.ebx)++;
    // 00488f93  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00488f95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488f97  7512                   -jne 0x488fab
    if (!cpu.flags.zf)
    {
        goto L_0x00488fab;
    }
    // 00488f99  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00488f9c  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00488fa0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00488fa1:
    // 00488fa1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00488fa4  e827f4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00488fa9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488faa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488fab:
    // 00488fab  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00488fad  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00488fb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fb2  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00488fb5  e816f4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00488fba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488fbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488fbc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488fbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488fbe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488fc0  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00488fc3  e8f0f3ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00488fc8  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00488fcb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488fcd  741a                   -je 0x488fe9
    if (cpu.flags.zf)
    {
        goto L_0x00488fe9;
    }
    // 00488fcf  3b4a0c                 +cmp ecx, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488fd2  7526                   -jne 0x488ffa
    if (!cpu.flags.zf)
    {
        goto L_0x00488ffa;
    }
    // 00488fd4  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00488fdb  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
L_0x00488fde:
    // 00488fde  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00488fe1  ff0a                   -dec dword ptr [edx]
    (app->getMemory<x86::reg32>(cpu.edx))--;
    // 00488fe3  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x00488fe9:
    // 00488fe9  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00488fed  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00488ff0  e8dbf3ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00488ff5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488ff7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ff8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ff9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488ffa:
    // 00488ffa  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488ffc  ebe0                   -jmp 0x488fde
    goto L_0x00488fde;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489002  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489004  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00489007  e8acf3ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048900c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048900f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489011  742f                   -je 0x489042
    if (cpu.flags.zf)
    {
        goto L_0x00489042;
    }
    // 00489013  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489014  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489015  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00489017  4b                     -dec ebx
    (cpu.ebx)--;
    // 00489018  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048901b  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0048901d  39f1                   +cmp ecx, esi
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
    // 0048901f  7432                   -je 0x489053
    if (cpu.flags.zf)
    {
        goto L_0x00489053;
    }
    // 00489021  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489022  89720c                 -mov dword ptr [edx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x00489025:
    // 00489025  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00489028  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048902a  39f9                   +cmp ecx, edi
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
    // 0048902c  7405                   -je 0x489033
    if (cpu.flags.zf)
    {
        goto L_0x00489033;
    }
    // 0048902e  897a0c                 -mov dword ptr [edx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00489031  ebf2                   -jmp 0x489025
    goto L_0x00489025;
L_0x00489033:
    // 00489033  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00489039  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048903a:
    // 0048903a  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00489040  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00489042:
    // 00489042  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00489046  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00489049  e882f3ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048904e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489050  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489051  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489052  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489053:
    // 00489053  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048905a  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048905d  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00489060  ebd8                   -jmp 0x48903a
    goto L_0x0048903a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489064  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489065  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489066  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489068  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048906a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048906d  e846f3ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489072  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489074  750b                   -jne 0x489081
    if (!cpu.flags.zf)
    {
        goto L_0x00489081;
    }
    // 00489076  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00489079  e852f3ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048907e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048907f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489080  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489081:
    // 00489081  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489082  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489083  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489084  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489086  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00489089  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048908b  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048908e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00489090  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489092  42                     -inc edx
    (cpu.edx)++;
    // 00489093  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00489096  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00489098  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048909a  7414                   -je 0x4890b0
    if (cpu.flags.zf)
    {
        goto L_0x004890b0;
    }
L_0x0048909c:
    // 0048909c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048909e  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004890a1  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004890a4  39f8                   +cmp eax, edi
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
    // 004890a6  7308                   -jae 0x4890b0
    if (!cpu.flags.cf)
    {
        goto L_0x004890b0;
    }
    // 004890a8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004890aa  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004890ac  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004890ae  75ec                   -jne 0x48909c
    if (!cpu.flags.zf)
    {
        goto L_0x0048909c;
    }
L_0x004890b0:
    // 004890b0  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004890b3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004890b5  751c                   -jne 0x4890d3
    if (!cpu.flags.zf)
    {
        goto L_0x004890d3;
    }
    // 004890b7  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x004890ba:
    // 004890ba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004890bc  7503                   -jne 0x4890c1
    if (!cpu.flags.zf)
    {
        goto L_0x004890c1;
    }
    // 004890be  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x004890c1:
    // 004890c1  804b0401               +or byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004890c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890c8  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004890cb  e800f3ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004890d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004890d3:
    // 004890d3  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 004890d5  ebe3                   -jmp 0x4890ba
    goto L_0x004890ba;
}

/* align: skip 0x90 */
void Application::sub_4890d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004890d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004890d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004890da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004890dc  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004890df  e8d4f2ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004890e4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004890e6  750d                   -jne 0x4890f5
    if (!cpu.flags.zf)
    {
        goto L_0x004890f5;
    }
    // 004890e8  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004890eb  e8e0f2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004890f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004890f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004890f5:
    // 004890f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004890f7  e84cfdffff             -call 0x488e48
    cpu.esp -= 4;
    sub_488e48(app, cpu);
    if (cpu.terminate) return;
    // 004890fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004890fe  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00489101  e8caf2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489106  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489108  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489109  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048910a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48910c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048910c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048910e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489112  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489113  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489114  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489115  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489118  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048911a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048911c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048911f  e894f2ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489124  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489126  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489128  742b                   -je 0x489155
    if (cpu.flags.zf)
    {
        goto L_0x00489155;
    }
    // 0048912a  8b7710                 -mov esi, dword ptr [edi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0048912d  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00489130  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00489132  7539                   -jne 0x48916d
    if (!cpu.flags.zf)
    {
        goto L_0x0048916d;
    }
    // 00489134  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00489136:
    // 00489136  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00489139  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048913b  7414                   -je 0x489151
    if (cpu.flags.zf)
    {
        goto L_0x00489151;
    }
L_0x0048913d:
    // 0048913d  39e9                   +cmp ecx, ebp
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
    // 0048913f  7410                   -je 0x489151
    if (cpu.flags.zf)
    {
        goto L_0x00489151;
    }
    // 00489141  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00489143  7431                   -je 0x489176
    if (cpu.flags.zf)
    {
        goto L_0x00489176;
    }
    // 00489145  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489147  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0048914a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048914c  3b0424                 +cmp eax, dword ptr [esp]
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
    // 0048914f  7625                   -jbe 0x489176
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00489176;
    }
L_0x00489151:
    // 00489151  39e9                   +cmp ecx, ebp
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
    // 00489153  7405                   -je 0x48915a
    if (cpu.flags.zf)
    {
        goto L_0x0048915a;
    }
L_0x00489155:
    // 00489155  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0048915a:
    // 0048915a  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048915d  e86ef2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489162  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489164  83c404                 +add esp, 4
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
    // 00489167  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489168  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489169  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048916a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048916b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048916c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048916d:
    // 0048916d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048916f  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00489172  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489174  ebc0                   -jmp 0x489136
    goto L_0x00489136;
L_0x00489176:
    // 00489176  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00489178  43                     -inc ebx
    (cpu.ebx)++;
    // 00489179  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048917b  75c0                   -jne 0x48913d
    if (!cpu.flags.zf)
    {
        goto L_0x0048913d;
    }
    // 0048917d  ebd2                   -jmp 0x489151
    goto L_0x00489151;
}

/* align: skip 0x90 */
void Application::sub_489180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489181  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489182  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489183  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489185  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00489188  e82bf2ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048918d  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00489190  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00489195  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489197  750e                   -jne 0x4891a7
    if (!cpu.flags.zf)
    {
        goto L_0x004891a7;
    }
    // 00489199  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048919c  e82ff2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004891a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004891a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004891a7:
    // 004891a7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004891a9  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004891ac  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004891af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004891b1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004891b4  e817f2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004891b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004891bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4891c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004891c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004891c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004891c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004891c3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004891c5  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004891c8  e8ebf1ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004891cd  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004891d0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004891d2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004891d4  750e                   -jne 0x4891e4
    if (!cpu.flags.zf)
    {
        goto L_0x004891e4;
    }
    // 004891d6  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004891d9  e8f2f1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004891de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004891e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004891e4:
    // 004891e4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004891e6  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004891e9  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004891ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004891ee  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004891f1  e8daf1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004891f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004891f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4891fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004891fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004891fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004891fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004891ff  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489201  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00489203  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00489206  e8adf1ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048920b  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048920e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489210  7414                   -je 0x489226
    if (cpu.flags.zf)
    {
        goto L_0x00489226;
    }
L_0x00489212:
    // 00489212  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00489214  7410                   -je 0x489226
    if (cpu.flags.zf)
    {
        goto L_0x00489226;
    }
    // 00489216  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00489218  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048921a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048921c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048921e  7506                   -jne 0x489226
    if (!cpu.flags.zf)
    {
        goto L_0x00489226;
    }
    // 00489220  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00489222  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489224  75ec                   -jne 0x489212
    if (!cpu.flags.zf)
    {
        goto L_0x00489212;
    }
L_0x00489226:
    // 00489226  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00489229  e8a2f1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048922e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489230  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489231  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489232  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489234  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489235  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489236  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489238  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048923b  e878f1ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489240  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00489243  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489245  741f                   -je 0x489266
    if (cpu.flags.zf)
    {
        goto L_0x00489266;
    }
    // 00489247  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489249  770f                   -ja 0x48925a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048925a;
    }
    // 0048924b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0048924d:
    // 0048924d  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00489250  e87bf1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489255  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489257  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489258  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489259  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048925a:
    // 0048925a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048925b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048925d  e8d2fbffff             -call 0x488e34
    cpu.esp -= 4;
    sub_488e34(app, cpu);
    if (cpu.terminate) return;
    // 00489262  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489264  ebe7                   -jmp 0x48924d
    goto L_0x0048924d;
L_0x00489266:
    // 00489266  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489268  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048926b  e860f1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489270  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489272  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489273  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489274  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489278(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489278  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489279  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048927a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048927b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048927d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048927f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00489282  e831f1ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489287  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048928a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048928c  7412                   -je 0x4892a0
    if (cpu.flags.zf)
    {
        goto L_0x004892a0;
    }
L_0x0048928e:
    // 0048928e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489290  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00489293  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489296  39f0                   +cmp eax, esi
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
    // 00489298  7306                   -jae 0x4892a0
    if (!cpu.flags.cf)
    {
        goto L_0x004892a0;
    }
    // 0048929a  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048929c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048929e  75ee                   -jne 0x48928e
    if (!cpu.flags.zf)
    {
        goto L_0x0048928e;
    }
L_0x004892a0:
    // 004892a0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004892a2  750e                   -jne 0x4892b2
    if (!cpu.flags.zf)
    {
        goto L_0x004892b2;
    }
L_0x004892a4:
    // 004892a4  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004892a7  e824f1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004892ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004892ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004892b2:
    // 004892b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004892b4  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004892b7  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004892ba  39f0                   +cmp eax, esi
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
    // 004892bc  74e6                   -je 0x4892a4
    if (cpu.flags.zf)
    {
        goto L_0x004892a4;
    }
    // 004892be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004892c0  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004892c3  e808f1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004892c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004892ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4892d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004892d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004892d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004892d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004892d3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004892d5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004892d7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004892da  e8d9f0ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004892df  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004892e2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004892e4  7414                   -je 0x4892fa
    if (cpu.flags.zf)
    {
        goto L_0x004892fa;
    }
L_0x004892e6:
    // 004892e6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004892e8  7410                   -je 0x4892fa
    if (cpu.flags.zf)
    {
        goto L_0x004892fa;
    }
    // 004892ea  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004892ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004892ee  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004892f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004892f2  7506                   -jne 0x4892fa
    if (!cpu.flags.zf)
    {
        goto L_0x004892fa;
    }
    // 004892f4  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004892f6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004892f8  75ec                   -jne 0x4892e6
    if (!cpu.flags.zf)
    {
        goto L_0x004892e6;
    }
L_0x004892fa:
    // 004892fa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004892fc  750e                   -jne 0x48930c
    if (!cpu.flags.zf)
    {
        goto L_0x0048930c;
    }
L_0x004892fe:
    // 004892fe  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00489301  e8caf0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489306  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489308  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489309  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048930a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048930b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048930c:
    // 0048930c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048930e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00489310  e833fbffff             -call 0x488e48
    cpu.esp -= 4;
    sub_488e48(app, cpu);
    if (cpu.terminate) return;
    // 00489315  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489317  75e5                   -jne 0x4892fe
    if (!cpu.flags.zf)
    {
        goto L_0x004892fe;
    }
    // 00489319  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048931b  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048931e  e8adf0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489323  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489325  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489326  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489327  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489328  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48932c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048932c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048932d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048932e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489330  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00489332  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00489335  e87ef0ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048933a  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048933d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048933f  7433                   -je 0x489374
    if (cpu.flags.zf)
    {
        goto L_0x00489374;
    }
    // 00489341  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489343  7713                   -ja 0x489358
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489358;
    }
    // 00489345  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00489347:
    // 00489347  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489349  751c                   -jne 0x489367
    if (!cpu.flags.zf)
    {
        goto L_0x00489367;
    }
L_0x0048934b:
    // 0048934b  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048934e  e87df0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489353  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489355  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489356  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489357  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489358:
    // 00489358  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0048935b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048935e  e8d1faffff             -call 0x488e34
    cpu.esp -= 4;
    sub_488e34(app, cpu);
    if (cpu.terminate) return;
    // 00489363  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489365  ebe0                   -jmp 0x489347
    goto L_0x00489347;
L_0x00489367:
    // 00489367  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00489369  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048936b  e8d8faffff             -call 0x488e48
    cpu.esp -= 4;
    sub_488e48(app, cpu);
    if (cpu.terminate) return;
    // 00489370  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489372  75d7                   -jne 0x48934b
    if (!cpu.flags.zf)
    {
        goto L_0x0048934b;
    }
L_0x00489374:
    // 00489374  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489376  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00489379  e852f0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048937e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489380  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489381  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489382  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489384(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489384  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489385  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489386  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489388  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048938a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048938d  e826f0ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489392  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00489394  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489396  e899faffff             -call 0x488e34
    cpu.esp -= 4;
    sub_488e34(app, cpu);
    if (cpu.terminate) return;
    // 0048939b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048939d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048939f  750d                   -jne 0x4893ae
    if (!cpu.flags.zf)
    {
        goto L_0x004893ae;
    }
L_0x004893a1:
    // 004893a1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004893a4  e827f0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004893a9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004893ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004893ae:
    // 004893ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004893b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004893b2  e891faffff             -call 0x488e48
    cpu.esp -= 4;
    sub_488e48(app, cpu);
    if (cpu.terminate) return;
    // 004893b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004893b9  75e6                   -jne 0x4893a1
    if (!cpu.flags.zf)
    {
        goto L_0x004893a1;
    }
    // 004893bb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004893bd  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004893c0  e80bf0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004893c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004893c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4893cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004893cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004893cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004893ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004893cf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004893d1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004893d3  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004893d6  e8ddefffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004893db  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004893de  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004893e0  7412                   -je 0x4893f4
    if (cpu.flags.zf)
    {
        goto L_0x004893f4;
    }
L_0x004893e2:
    // 004893e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004893e4  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004893e7  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004893ea  39f0                   +cmp eax, esi
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
    // 004893ec  7306                   -jae 0x4893f4
    if (!cpu.flags.cf)
    {
        goto L_0x004893f4;
    }
    // 004893ee  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004893f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004893f2  75ee                   -jne 0x4893e2
    if (!cpu.flags.zf)
    {
        goto L_0x004893e2;
    }
L_0x004893f4:
    // 004893f4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004893f6  7510                   -jne 0x489408
    if (!cpu.flags.zf)
    {
        goto L_0x00489408;
    }
L_0x004893f8:
    // 004893f8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004893fa:
    // 004893fa  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004893fd  e8ceefffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489402  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489404  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489405  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489406  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489407  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489408:
    // 00489408  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048940a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048940d  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489410  39f0                   +cmp eax, esi
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
    // 00489412  75e4                   -jne 0x4893f8
    if (!cpu.flags.zf)
    {
        goto L_0x004893f8;
    }
    // 00489414  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489416  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489418  e82bfaffff             -call 0x488e48
    cpu.esp -= 4;
    sub_488e48(app, cpu);
    if (cpu.terminate) return;
    // 0048941d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048941f  75d9                   -jne 0x4893fa
    if (!cpu.flags.zf)
    {
        goto L_0x004893fa;
    }
    // 00489421  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489423  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00489426  e8a5efffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048942b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048942d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048942e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048942f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489430  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489434(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489434  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489435  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489436  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489437  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489438  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048943b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048943d  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048943f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00489441  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00489444  e86fefffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489449  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048944c  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0048944f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00489452  806604fe               -and byte ptr [esi + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00489456  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00489459  e872efffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048945e  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00489461  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489463  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489465  7422                   -je 0x489489
    if (cpu.flags.zf)
    {
        goto L_0x00489489;
    }
L_0x00489467:
    // 00489467  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048946a  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0048946d  751a                   -jne 0x489489
    if (!cpu.flags.zf)
    {
        goto L_0x00489489;
    }
    // 0048946f  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00489472  750f                   -jne 0x489483
    if (!cpu.flags.zf)
    {
        goto L_0x00489483;
    }
    // 00489474  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00489476  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489478  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048947a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048947c  7504                   -jne 0x489482
    if (!cpu.flags.zf)
    {
        goto L_0x00489482;
    }
    // 0048947e  804e0401               -or byte ptr [esi + 4], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00489482:
    // 00489482  43                     -inc ebx
    (cpu.ebx)++;
L_0x00489483:
    // 00489483  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00489485  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489487  75de                   -jne 0x489467
    if (!cpu.flags.zf)
    {
        goto L_0x00489467;
    }
L_0x00489489:
    // 00489489  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048948c  e827efffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489491  f6460401               +test byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 00489495  741d                   -je 0x4894b4
    if (cpu.flags.zf)
    {
        goto L_0x004894b4;
    }
L_0x00489497:
    // 00489497  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048949a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048949d  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048949f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004894a2  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004894a5  e826efffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004894aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004894ac  83c404                 +add esp, 4
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
    // 004894af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004894b4:
    // 004894b4  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004894b9  ebdc                   -jmp 0x489497
    goto L_0x00489497;
}

/* align: skip 0x90 */
void Application::sub_4894bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004894bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004894bd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004894bf  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004894c2  e8f1eeffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004894c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004894c9  e866ffffff             -call 0x489434
    cpu.esp -= 4;
    sub_489434(app, cpu);
    if (cpu.terminate) return;
    // 004894ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004894d0  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004894d3  e8f8eeffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004894d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004894da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4894dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004894dc  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004894df  e9d4eeffff             -jmp 0x4883b8
    return sub_4883b8(app, cpu);
}

/* align: skip  */
void Application::sub_4894e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004894e4  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004894e7  e9e4eeffff             -jmp 0x4883d0
    return sub_4883d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4894f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004894f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004894f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004894f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004894f4  833dec9a4d0000         +cmp dword ptr [0x4d9aec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004894fb  7424                   -je 0x489521
    if (cpu.flags.zf)
    {
        goto L_0x00489521;
    }
L_0x004894fd:
    // 004894fd  833de89a4d0000         +cmp dword ptr [0x4d9ae8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085928) /* 0x4d9ae8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489504  750a                   -jne 0x489510
    if (!cpu.flags.zf)
    {
        goto L_0x00489510;
    }
    // 00489506  e85deeffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048950b  a3e89a4d00             -mov dword ptr [0x4d9ae8], eax
    app->getMemory<x86::reg32>(x86::reg32(5085928) /* 0x4d9ae8 */) = cpu.eax;
L_0x00489510:
    // 00489510  833dec9a4d0000         +cmp dword ptr [0x4d9aec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489517  7453                   -je 0x48956c
    if (cpu.flags.zf)
    {
        goto L_0x0048956c;
    }
    // 00489519  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048951e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048951f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489520  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489521:
    // 00489521  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489522  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489523  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489524  be38dd4c00             -mov esi, 0x4cdd38
    cpu.esi = 5037368 /*0x4cdd38*/;
    // 00489529  bf62000000             -mov edi, 0x62
    cpu.edi = 98 /*0x62*/;
    // 0048952e  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00489531  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00489533  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00489535  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00489538  8935f48f4d00           -mov dword ptr [0x4d8ff4], esi
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.esi;
    // 0048953e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489540  b848dd4c00             -mov eax, 0x4cdd48
    cpu.eax = 5037384 /*0x4cdd48*/;
    // 00489545  893df88f4d00           -mov dword ptr [0x4d8ff8], edi
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.edi;
    // 0048954b  e8b893ffff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00489550  a3ec9a4d00             -mov dword ptr [0x4d9aec], eax
    app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */) = cpu.eax;
    // 00489555  890d78205600           -mov dword ptr [0x562078], ecx
    app->getMemory<x86::reg32>(x86::reg32(5644408) /* 0x562078 */) = cpu.ecx;
    // 0048955b  892d80205600           -mov dword ptr [0x562080], ebp
    app->getMemory<x86::reg32>(x86::reg32(5644416) /* 0x562080 */) = cpu.ebp;
    // 00489561  892d7c205600           -mov dword ptr [0x56207c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5644412) /* 0x56207c */) = cpu.ebp;
    // 00489567  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489568  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489569  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048956a  eb91                   -jmp 0x4894fd
    goto L_0x004894fd;
L_0x0048956c:
    // 0048956c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048956e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048956f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489570  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489574(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489574  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489575  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489576  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489577  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489578  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489579  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048957a  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048957c  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 00489582  833dec9a4d0000         +cmp dword ptr [0x4d9aec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489589  0f8460020000           -je 0x4897ef
    if (cpu.flags.zf)
    {
        goto L_0x004897ef;
    }
    // 0048958f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489591  0f8458020000           -je 0x4897ef
    if (cpu.flags.zf)
    {
        goto L_0x004897ef;
    }
    // 00489597  e8ccdc0100             -call 0x4a7268
    cpu.esp -= 4;
    sub_4a7268(app, cpu);
    if (cpu.terminate) return;
L_0x0048959c:
    // 0048959c  8b15ec9a4d00           -mov edx, dword ptr [0x4d9aec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */);
    // 004895a2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004895a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004895a7  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004895aa  890dec9a4d00           -mov dword ptr [0x4d9aec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */) = cpu.ecx;
    // 004895b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004895b2  0f84ff020000           -je 0x4898b7
    if (cpu.flags.zf)
    {
        goto L_0x004898b7;
    }
    // 004895b8  a180205600             -mov eax, dword ptr [0x562080]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644416) /* 0x562080 */);
    // 004895bd  8b1d78205600           -mov ebx, dword ptr [0x562078]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5644408) /* 0x562078 */);
    // 004895c3  39d8                   +cmp eax, ebx
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
    // 004895c5  0f8d2b020000           -jge 0x4897f6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004897f6;
    }
L_0x004895cb:
    // 004895cb  a380205600             -mov dword ptr [0x562080], eax
    app->getMemory<x86::reg32>(x86::reg32(5644416) /* 0x562080 */) = cpu.eax;
L_0x004895d0:
    // 004895d0  8b3580205600           -mov esi, dword ptr [0x562080]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5644416) /* 0x562080 */);
    // 004895d6  4e                     -dec esi
    (cpu.esi)--;
    // 004895d7  893580205600           -mov dword ptr [0x562080], esi
    app->getMemory<x86::reg32>(x86::reg32(5644416) /* 0x562080 */) = cpu.esi;
    // 004895dd  83feff                 +cmp esi, -1
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
    // 004895e0  0f84c9020000           -je 0x4898af
    if (cpu.flags.zf)
    {
        goto L_0x004898af;
    }
    // 004895e6  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004895e9  8b357c205600           -mov esi, dword ptr [0x56207c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5644412) /* 0x56207c */);
    // 004895ef  8b157c205600           -mov edx, dword ptr [0x56207c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644412) /* 0x56207c */);
    // 004895f5  8b0d78205600           -mov ecx, dword ptr [0x562078]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5644408) /* 0x562078 */);
    // 004895fb  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 004895fe  42                     -inc edx
    (cpu.edx)++;
    // 004895ff  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489601  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489603  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489606  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489608  8a6609                 -mov ah, byte ptr [esi + 9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0048960b  89157c205600           -mov dword ptr [0x56207c], edx
    app->getMemory<x86::reg32>(x86::reg32(5644412) /* 0x56207c */) = cpu.edx;
    // 00489611  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00489613  0f84ee010000           -je 0x489807
    if (cpu.flags.zf)
    {
        goto L_0x00489807;
    }
    // 00489619  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048961b  8a4609                 -mov al, byte ptr [esi + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0048961e  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00489621  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489622  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00489625  0f84d2010000           -je 0x4897fd
    if (cpu.flags.zf)
    {
        goto L_0x004897fd;
    }
    // 0048962b  b854dd4c00             -mov eax, 0x4cdd54
    cpu.eax = 5037396 /*0x4cdd54*/;
L_0x00489630:
    // 00489630  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489631  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00489633  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489634  6864dd4c00             -push 0x4cdd64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037412 /*0x4cdd64*/;
    cpu.esp -= 4;
    // 00489639  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048963f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489640  e82cb3ffff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00489645  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00489648:
    // 00489648  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048964e  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00489654  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489656  49                     -dec ecx
    (cpu.ecx)--;
    // 00489657  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489659  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048965b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048965d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048965e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00489661  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489663  e864dd0100             -call 0x4a73cc
    cpu.esp -= 4;
    sub_4a73cc(app, cpu);
    if (cpu.terminate) return;
    // 00489668  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048966d  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00489670  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00489673  e8a88e0100             -call 0x4a2520
    cpu.esp -= 4;
    sub_4a2520(app, cpu);
    if (cpu.terminate) return;
    // 00489678  8a5df8                 -mov bl, byte ptr [ebp - 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048967b  80fb20                 +cmp bl, 0x20
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
    // 0048967e  0f83b2010000           -jae 0x489836
    if (!cpu.flags.cf)
    {
        goto L_0x00489836;
    }
L_0x00489684:
    // 00489684  c645f85f               -mov byte ptr [ebp - 8], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 95 /*0x5f*/;
L_0x00489688:
    // 00489688  8a6df9                 -mov ch, byte ptr [ebp - 7]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 0048968b  80fd20                 +cmp ch, 0x20
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048968e  0f83b0010000           -jae 0x489844
    if (!cpu.flags.cf)
    {
        goto L_0x00489844;
    }
L_0x00489694:
    // 00489694  c645f95f               -mov byte ptr [ebp - 7], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) = 95 /*0x5f*/;
L_0x00489698:
    // 00489698  8a55fa                 -mov dl, byte ptr [ebp - 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0048969b  80fa20                 +cmp dl, 0x20
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
    // 0048969e  0f83ae010000           -jae 0x489852
    if (!cpu.flags.cf)
    {
        goto L_0x00489852;
    }
L_0x004896a4:
    // 004896a4  c645fa5f               -mov byte ptr [ebp - 6], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = 95 /*0x5f*/;
L_0x004896a8:
    // 004896a8  8a7dfb                 -mov bh, byte ptr [ebp - 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 004896ab  80ff20                 +cmp bh, 0x20
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
    // 004896ae  0f83ac010000           -jae 0x489860
    if (!cpu.flags.cf)
    {
        goto L_0x00489860;
    }
L_0x004896b4:
    // 004896b4  c645fb5f               -mov byte ptr [ebp - 5], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = 95 /*0x5f*/;
L_0x004896b8:
    // 004896b8  f6460a02               +test byte ptr [esi + 0xa], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 2 /*0x2*/));
    // 004896bc  0f84ac010000           -je 0x48986e
    if (cpu.flags.zf)
    {
        goto L_0x0048986e;
    }
    // 004896c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004896c4  8a45fb                 -mov al, byte ptr [ebp - 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 004896c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004896c8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004896ca  8a45fa                 -mov al, byte ptr [ebp - 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 004896cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004896ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004896d0  8a45f9                 -mov al, byte ptr [ebp - 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 004896d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004896d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004896d6  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004896d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004896da  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004896dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004896de  6884dd4c00             -push 0x4cdd84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037444 /*0x4cdd84*/;
    cpu.esp -= 4;
    // 004896e3  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004896e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004896ea  e882b2ffff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 004896ef  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x004896f2:
    // 004896f2  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004896f8  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004896fe  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489700  49                     -dec ecx
    (cpu.ecx)--;
    // 00489701  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489703  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00489705  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00489707  49                     -dec ecx
    (cpu.ecx)--;
    // 00489708  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048970b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048970d  e8badc0100             -call 0x4a73cc
    cpu.esp -= 4;
    sub_4a73cc(app, cpu);
    if (cpu.terminate) return;
    // 00489712  f6460a01               +test byte ptr [esi + 0xa], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 1 /*0x1*/));
    // 00489716  7473                   -je 0x48978b
    if (cpu.flags.zf)
    {
        goto L_0x0048978b;
    }
    // 00489718  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048971a  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048971f  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00489722  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00489724  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489726  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489728  7e09                   -jle 0x489733
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489733;
    }
    // 0048972a  83fa35                 +cmp edx, 0x35
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048972d  0f8d5b010000           -jge 0x48988e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048988e;
    }
L_0x00489733:
    // 00489733  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489735  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048973a  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048973d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048973f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489741  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489743  0f8e3e010000           -jle 0x489887
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489887;
    }
L_0x00489749:
    // 00489749  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048974b:
    // 0048974b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048974d  8d560b                 -lea edx, [esi + 0xb]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 00489750  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00489753  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489755  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489757  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048975d  e8eab1ffff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 00489762  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00489764  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048976a  889429f4feffff         -mov byte ptr [ecx + ebp - 0x10c], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-268) /* -0x10c */ + cpu.ebp * 1) = cpu.dl;
    // 00489771  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489773  49                     -dec ecx
    (cpu.ecx)--;
    // 00489774  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489776  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00489778  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048977a  49                     -dec ecx
    (cpu.ecx)--;
    // 0048977b  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00489781  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00489784  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489786  e841dc0100             -call 0x4a73cc
    cpu.esp -= 4;
    sub_4a73cc(app, cpu);
    if (cpu.terminate) return;
L_0x0048978b:
    // 0048978b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00489790  baa4dd4c00             -mov edx, 0x4cdda4
    cpu.edx = 5037476 /*0x4cdda4*/;
    // 00489795  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00489798  e82fdc0100             -call 0x4a73cc
    cpu.esp -= 4;
    sub_4a73cc(app, cpu);
    if (cpu.terminate) return;
    // 0048979d  f6460a04               +test byte ptr [esi + 0xa], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 4 /*0x4*/));
    // 004897a1  0f84f1000000           -je 0x489898
    if (cpu.flags.zf)
    {
        goto L_0x00489898;
    }
    // 004897a7  8d4e0b                 -lea ecx, [esi + 0xb]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 004897aa  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
L_0x004897af:
    // 004897af  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004897b2  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004897b4  fecc                   -dec ah
    (cpu.ah)--;
    // 004897b6  886608                 -mov byte ptr [esi + 8], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ah;
    // 004897b9  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004897bb  0f84d7000000           -je 0x489898
    if (cpu.flags.zf)
    {
        goto L_0x00489898;
    }
    // 004897c1  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004897c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004897c5  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004897c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004897c8  68a8dd4c00             -push 0x4cdda8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037480 /*0x4cdda8*/;
    cpu.esp -= 4;
    // 004897cd  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004897d3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004897d4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004897d6  e896b1ffff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 004897db  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004897e1  83c40c                 +add esp, 0xc
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
    // 004897e4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004897e7  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004897e8  e8dfdb0100             -call 0x4a73cc
    cpu.esp -= 4;
    sub_4a73cc(app, cpu);
    if (cpu.terminate) return;
    // 004897ed  ebc0                   -jmp 0x4897af
    goto L_0x004897af;
L_0x004897ef:
    // 004897ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004897f1  e9a6fdffff             -jmp 0x48959c
    goto L_0x0048959c;
L_0x004897f6:
    // 004897f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004897f8  e9cefdffff             -jmp 0x4895cb
    goto L_0x004895cb;
L_0x004897fd:
    // 004897fd  b85cdd4c00             -mov eax, 0x4cdd5c
    cpu.eax = 5037404 /*0x4cdd5c*/;
    // 00489802  e929feffff             -jmp 0x489630
    goto L_0x00489630;
L_0x00489807:
    // 00489807  f6460a08               +test byte ptr [esi + 0xa], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 8 /*0x8*/));
    // 0048980b  7422                   -je 0x48982f
    if (cpu.flags.zf)
    {
        goto L_0x0048982f;
    }
    // 0048980d  b854dd4c00             -mov eax, 0x4cdd54
    cpu.eax = 5037396 /*0x4cdd54*/;
L_0x00489812:
    // 00489812  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489813  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00489815  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489816  6874dd4c00             -push 0x4cdd74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037428 /*0x4cdd74*/;
    cpu.esp -= 4;
    // 0048981b  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00489821  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489822  e84ab1ffff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00489827  83c410                 +add esp, 0x10
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
    // 0048982a  e919feffff             -jmp 0x489648
    goto L_0x00489648;
L_0x0048982f:
    // 0048982f  b85cdd4c00             -mov eax, 0x4cdd5c
    cpu.eax = 5037404 /*0x4cdd5c*/;
    // 00489834  ebdc                   -jmp 0x489812
    goto L_0x00489812;
L_0x00489836:
    // 00489836  80fb7f                 +cmp bl, 0x7f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489839  0f8745feffff           -ja 0x489684
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489684;
    }
    // 0048983f  e944feffff             -jmp 0x489688
    goto L_0x00489688;
L_0x00489844:
    // 00489844  80fd7f                 +cmp ch, 0x7f
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489847  0f8747feffff           -ja 0x489694
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489694;
    }
    // 0048984d  e946feffff             -jmp 0x489698
    goto L_0x00489698;
L_0x00489852:
    // 00489852  80fa7f                 +cmp dl, 0x7f
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489855  0f8749feffff           -ja 0x4896a4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004896a4;
    }
    // 0048985b  e948feffff             -jmp 0x4896a8
    goto L_0x004896a8;
L_0x00489860:
    // 00489860  80ff7f                 +cmp bh, 0x7f
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489863  0f874bfeffff           -ja 0x4896b4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004896b4;
    }
    // 00489869  e94afeffff             -jmp 0x4896b8
    goto L_0x004896b8;
L_0x0048986e:
    // 0048986e  6894dd4c00             -push 0x4cdd94
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037460 /*0x4cdd94*/;
    cpu.esp -= 4;
    // 00489873  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00489879  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048987a  e8f2b0ffff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 0048987f  83c408                 +add esp, 8
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
    // 00489882  e96bfeffff             -jmp 0x4896f2
    goto L_0x004896f2;
L_0x00489887:
    // 00489887  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00489889  e9bbfeffff             -jmp 0x489749
    goto L_0x00489749;
L_0x0048988e:
    // 0048988e  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 00489893  e9b3feffff             -jmp 0x48974b
    goto L_0x0048974b;
L_0x00489898:
    // 00489898  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048989d  bab0dd4c00             -mov edx, 0x4cddb0
    cpu.edx = 5037488 /*0x4cddb0*/;
    // 004898a2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004898a5  e822db0100             -call 0x4a73cc
    cpu.esp -= 4;
    sub_4a73cc(app, cpu);
    if (cpu.terminate) return;
    // 004898aa  e921fdffff             -jmp 0x4895d0
    goto L_0x004895d0;
L_0x004898af:
    // 004898af  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004898b2  e815da0100             -call 0x4a72cc
    cpu.esp -= 4;
    sub_4a72cc(app, cpu);
    if (cpu.terminate) return;
L_0x004898b7:
    // 004898b7  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004898ba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004898bc  7407                   -je 0x4898c5
    if (cpu.flags.zf)
    {
        goto L_0x004898c5;
    }
    // 004898be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004898c0  e8a794ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x004898c5:
    // 004898c5  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004898c9  740e                   -je 0x4898d9
    if (cpu.flags.zf)
    {
        goto L_0x004898d9;
    }
    // 004898cb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004898d0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004898d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004898d9:
    // 004898d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004898db  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004898dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4898e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004898e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004898e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004898e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004898e7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004898e9  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004898ec  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004898ef  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004898f2  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004898f5  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004898f8  a1e89a4d00             -mov eax, dword ptr [0x4d9ae8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085928) /* 0x4d9ae8 */);
    // 004898fd  e8b6eaffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489902  833dec9a4d0000         +cmp dword ptr [0x4d9aec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489909  0f847d010000           -je 0x489a8c
    if (cpu.flags.zf)
    {
        goto L_0x00489a8c;
    }
    // 0048990f  8b157c205600           -mov edx, dword ptr [0x56207c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644412) /* 0x56207c */);
    // 00489915  8b0d80205600           -mov ecx, dword ptr [0x562080]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5644416) /* 0x562080 */);
    // 0048991b  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048991d  8b1d78205600           -mov ebx, dword ptr [0x562078]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5644408) /* 0x562078 */);
    // 00489923  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489925  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489928  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048992a  8b35ec9a4d00           -mov esi, dword ptr [0x4d9aec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */);
    // 00489930  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00489933  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489935  39d9                   +cmp ecx, ebx
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
    // 00489937  0f856f010000           -jne 0x489aac
    if (!cpu.flags.zf)
    {
        goto L_0x00489aac;
    }
    // 0048993d  8b157c205600           -mov edx, dword ptr [0x56207c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644412) /* 0x56207c */);
    // 00489943  42                     -inc edx
    (cpu.edx)++;
    // 00489944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489946  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489949  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048994b  89157c205600           -mov dword ptr [0x56207c], edx
    app->getMemory<x86::reg32>(x86::reg32(5644412) /* 0x56207c */) = cpu.edx;
L_0x00489951:
    // 00489951  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00489954  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489956  0f8467010000           -je 0x489ac3
    if (cpu.flags.zf)
    {
        goto L_0x00489ac3;
    }
    // 0048995c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048995e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489960  49                     -dec ecx
    (cpu.ecx)--;
    // 00489961  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489963  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00489965  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00489967  49                     -dec ecx
    (cpu.ecx)--;
    // 00489968  83f935                 +cmp ecx, 0x35
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048996b  0f8348010000           -jae 0x489ab9
    if (!cpu.flags.cf)
    {
        goto L_0x00489ab9;
    }
    // 00489971  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00489973  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489975  49                     -dec ecx
    (cpu.ecx)--;
    // 00489976  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489978  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048997a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048997c  49                     -dec ecx
    (cpu.ecx)--;
L_0x0048997d:
    // 0048997d  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489981  0f8443010000           -je 0x489aca
    if (cpu.flags.zf)
    {
        goto L_0x00489aca;
    }
    // 00489987  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489989  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048998e  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 00489990  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00489992  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00489995  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489997  39fa                   +cmp edx, edi
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
    // 00489999  7e02                   -jle 0x48999d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048999d;
    }
    // 0048999b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0048999d:
    // 0048999d  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
L_0x004899a0:
    // 004899a0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004899a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004899a5  7405                   -je 0x4899ac
    if (cpu.flags.zf)
    {
        goto L_0x004899ac;
    }
    // 004899a7  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x004899ac:
    // 004899ac  88460a                 -mov byte ptr [esi + 0xa], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.al;
    // 004899af  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 004899b4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004899b6  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004899b9  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004899bc  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 004899bf  8d460b                 -lea eax, [esi + 0xb]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 004899c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004899c4  742a                   -je 0x4899f0
    if (cpu.flags.zf)
    {
        goto L_0x004899f0;
    }
    // 004899c6  807e0800               +cmp byte ptr [esi + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004899ca  7424                   -je 0x4899f0
    if (cpu.flags.zf)
    {
        goto L_0x004899f0;
    }
    // 004899cc  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004899cf  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004899d1  80ce04                 -or dh, 4
    cpu.dh |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004899d4  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004899d7  88760a                 -mov byte ptr [esi + 0xa], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
    // 004899da  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004899dd  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004899df  760f                   -jbe 0x4899f0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004899f0;
    }
L_0x004899e1:
    // 004899e1  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004899e3  42                     -inc edx
    (cpu.edx)++;
    // 004899e4  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 004899e6  fec3                   -inc bl
    (cpu.bl)++;
    // 004899e8  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004899eb  40                     -inc eax
    (cpu.eax)++;
    // 004899ec  38eb                   +cmp bl, ch
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004899ee  72f1                   -jb 0x4899e1
    if (cpu.flags.cf)
    {
        goto L_0x004899e1;
    }
L_0x004899f0:
    // 004899f0  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004899f4  7425                   -je 0x489a1b
    if (cpu.flags.zf)
    {
        goto L_0x00489a1b;
    }
    // 004899f6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004899f8  7421                   -je 0x489a1b
    if (cpu.flags.zf)
    {
        goto L_0x00489a1b;
    }
    // 004899fa  8a560a                 -mov dl, byte ptr [esi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004899fd  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00489a00  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00489a02  88560a                 -mov byte ptr [esi + 0xa], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dl;
    // 00489a05  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00489a08  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00489a0a  760c                   -jbe 0x489a18
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00489a18;
    }
L_0x00489a0c:
    // 00489a0c  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00489a0e  42                     -inc edx
    (cpu.edx)++;
    // 00489a0f  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 00489a11  fec3                   -inc bl
    (cpu.bl)++;
    // 00489a13  40                     -inc eax
    (cpu.eax)++;
    // 00489a14  38cb                   +cmp bl, cl
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
    // 00489a16  72f4                   -jb 0x489a0c
    if (cpu.flags.cf)
    {
        goto L_0x00489a0c;
    }
L_0x00489a18:
    // 00489a18  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00489a1b:
    // 00489a1b  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00489a1e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00489a20  0f84ad000000           -je 0x489ad3
    if (cpu.flags.zf)
    {
        goto L_0x00489ad3;
    }
    // 00489a26  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00489a29  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00489a2b  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00489a2e  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00489a31  88760a                 -mov byte ptr [esi + 0xa], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
L_0x00489a34:
    // 00489a34  833df09a4d0000         +cmp dword ptr [0x4d9af0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085936) /* 0x4d9af0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489a3b  744f                   -je 0x489a8c
    if (cpu.flags.zf)
    {
        goto L_0x00489a8c;
    }
    // 00489a3d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00489a40  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00489a43  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489a44  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489a46  0f848f000000           -je 0x489adb
    if (cpu.flags.zf)
    {
        goto L_0x00489adb;
    }
    // 00489a4c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00489a4e:
    // 00489a4e  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00489a51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a52  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489a54  0f848b000000           -je 0x489ae5
    if (cpu.flags.zf)
    {
        goto L_0x00489ae5;
    }
    // 00489a5a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
L_0x00489a5c:
    // 00489a5c  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00489a5f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a60  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00489a62  0f8484000000           -je 0x489aec
    if (cpu.flags.zf)
    {
        goto L_0x00489aec;
    }
    // 00489a68  b854dd4c00             -mov eax, 0x4cdd54
    cpu.eax = 5037396 /*0x4cdd54*/;
L_0x00489a6d:
    // 00489a6d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489a70  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00489a73  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489a76  a0f49a4d00             -mov al, byte ptr [0x4d9af4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5085940) /* 0x4d9af4 */);
    // 00489a7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a7c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00489a7e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a7f  68b8dd4c00             -push 0x4cddb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037496 /*0x4cddb8*/;
    cpu.esp -= 4;
    // 00489a84  e8d7000000             -call 0x489b60
    cpu.esp -= 4;
    sub_489b60(app, cpu);
    if (cpu.terminate) return;
    // 00489a89  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00489a8c:
    // 00489a8c  a1e89a4d00             -mov eax, dword ptr [0x4d9ae8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085928) /* 0x4d9ae8 */);
    // 00489a91  e83ae9ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489a96  833dec9a4d0000         +cmp dword ptr [0x4d9aec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085932) /* 0x4d9aec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489a9d  7457                   -je 0x489af6
    if (cpu.flags.zf)
    {
        goto L_0x00489af6;
    }
    // 00489a9f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489aa4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00489aa6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489aa7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489aa8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489aa9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00489aac:
    // 00489aac  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00489aaf  a380205600             -mov dword ptr [0x562080], eax
    app->getMemory<x86::reg32>(x86::reg32(5644416) /* 0x562080 */) = cpu.eax;
    // 00489ab4  e998feffff             -jmp 0x489951
    goto L_0x00489951;
L_0x00489ab9:
    // 00489ab9  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 00489abe  e9bafeffff             -jmp 0x48997d
    goto L_0x0048997d;
L_0x00489ac3:
    // 00489ac3  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00489ac5  e9b3feffff             -jmp 0x48997d
    goto L_0x0048997d;
L_0x00489aca:
    // 00489aca  c6460800               -mov byte ptr [esi + 8], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00489ace  e9cdfeffff             -jmp 0x4899a0
    goto L_0x004899a0;
L_0x00489ad3:
    // 00489ad3  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00489ad6  e959ffffff             -jmp 0x489a34
    goto L_0x00489a34;
L_0x00489adb:
    // 00489adb  b8b4dd4c00             -mov eax, 0x4cddb4
    cpu.eax = 5037492 /*0x4cddb4*/;
    // 00489ae0  e969ffffff             -jmp 0x489a4e
    goto L_0x00489a4e;
L_0x00489ae5:
    // 00489ae5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489ae7  e970ffffff             -jmp 0x489a5c
    goto L_0x00489a5c;
L_0x00489aec:
    // 00489aec  b85cdd4c00             -mov eax, 0x4cdd5c
    cpu.eax = 5037404 /*0x4cdd5c*/;
    // 00489af1  e977ffffff             -jmp 0x489a6d
    goto L_0x00489a6d;
L_0x00489af6:
    // 00489af6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489af8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00489afa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489afb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489afc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489afd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_489b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489b00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489b01  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489b03  39c2                   +cmp edx, eax
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
    // 00489b05  771d                   -ja 0x489b24
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489b24;
    }
L_0x00489b07:
    // 00489b07  833dc8894d0000         +cmp dword ptr [0x4d89c8], 0
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
    // 00489b0e  752f                   -jne 0x489b3f
    if (!cpu.flags.zf)
    {
        goto L_0x00489b3f;
    }
    // 00489b10  833dc0894d0000         +cmp dword ptr [0x4d89c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081536) /* 0x4d89c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489b17  7433                   -je 0x489b4c
    if (cpu.flags.zf)
    {
        goto L_0x00489b4c;
    }
    // 00489b19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489b1b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489b1d  e817da0100             -call 0x4a7539
    cpu.esp -= 4;
    sub_4a7539(app, cpu);
    if (cpu.terminate) return;
L_0x00489b22:
    // 00489b22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489b24:
    // 00489b24  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00489b27  39d1                   +cmp ecx, edx
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
    // 00489b29  73dc                   -jae 0x489b07
    if (!cpu.flags.cf)
    {
        goto L_0x00489b07;
    }
    // 00489b2b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489b2d  8d1419                 -lea edx, [ecx + ebx]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebx * 1);
L_0x00489b30:
    // 00489b30  4b                     -dec ebx
    (cpu.ebx)--;
    // 00489b31  83fbff                 +cmp ebx, -1
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
    // 00489b34  74ec                   -je 0x489b22
    if (cpu.flags.zf)
    {
        goto L_0x00489b22;
    }
    // 00489b36  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00489b37  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00489b3a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00489b3b  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00489b3d  ebf1                   -jmp 0x489b30
    goto L_0x00489b30;
L_0x00489b3f:
    // 00489b3f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489b41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489b43  e8cdda0100             -call 0x4a7615
    cpu.esp -= 4;
    sub_4a7615(app, cpu);
    if (cpu.terminate) return;
    // 00489b48  0f77                   -emms 
    cpu.mmx.init();
    // 00489b4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489b4c:
    // 00489b4c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489b4e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489b50  e8f0340100             -call 0x49d045
    cpu.esp -= 4;
    sub_49d045(app, cpu);
    if (cpu.terminate) return;
    // 00489b55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489b60  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00489b66  833dfc9a4d0002         +cmp dword ptr [0x4d9afc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085948) /* 0x4d9afc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489b6d  7c21                   -jl 0x489b90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489b90;
    }
    // 00489b6f  833df89a4d0000         +cmp dword ptr [0x4d9af8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489b76  750a                   -jne 0x489b82
    if (!cpu.flags.zf)
    {
        goto L_0x00489b82;
    }
    // 00489b78  e8ebe7ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 00489b7d  a3f89a4d00             -mov dword ptr [0x4d9af8], eax
    app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */) = cpu.eax;
L_0x00489b82:
    // 00489b82  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489b87  e82ce8ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489b8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489b8e  7507                   -jne 0x489b97
    if (!cpu.flags.zf)
    {
        goto L_0x00489b97;
    }
L_0x00489b90:
    // 00489b90  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00489b96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489b97:
    // 00489b97  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489b98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489b99  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00489ba0  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00489ba7  8b942410010000         -mov edx, dword ptr [esp + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00489bae  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 00489bb5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489bb9  e836600100             -call 0x49fbf4
    cpu.esp -= 4;
    sub_49fbf4(app, cpu);
    if (cpu.terminate) return;
    // 00489bbe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489bc0  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489bc4  899c2408010000         -mov dword ptr [esp + 0x108], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.ebx;
    // 00489bcb  e8e0000000             -call 0x489cb0
    cpu.esp -= 4;
    sub_489cb0(app, cpu);
    if (cpu.terminate) return;
    // 00489bd0  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489bd5  e8f6e7ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489bda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bdb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bdc  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00489be2  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
