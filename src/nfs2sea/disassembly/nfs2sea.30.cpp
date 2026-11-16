#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4b0330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0332  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0333  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0334  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b0335  be06124e00             -mov esi, 0x4e1206
    cpu.esi = 5116422 /*0x4e1206*/;
    // 004b033a  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x004b033c:
    // 004b033c  b8ca114e00             -mov eax, 0x4e11ca
    cpu.eax = 5116362 /*0x4e11ca*/;
    // 004b0341  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b0343  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
L_0x004b0345:
    // 004b0345  3d06124e00             +cmp eax, 0x4e1206
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5116422 /*0x4e1206*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b034a  7315                   -jae 0x4b0361
    if (!cpu.flags.cf)
    {
        goto L_0x004b0361;
    }
    // 004b034c  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b034f  740b                   -je 0x4b035c
    if (cpu.flags.zf)
    {
        goto L_0x004b035c;
    }
    // 004b0351  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0354  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b0356  7204                   -jb 0x4b035c
    if (cpu.flags.cf)
    {
        goto L_0x004b035c;
    }
    // 004b0358  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b035a  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x004b035c:
    // 004b035c  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b035f  ebe4                   -jmp 0x4b0345
    goto L_0x004b0345;
L_0x004b0361:
    // 004b0361  81fb06124e00           +cmp ebx, 0x4e1206
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5116422 /*0x4e1206*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0367  740d                   -je 0x4b0376
    if (cpu.flags.zf)
    {
        goto L_0x004b0376;
    }
    // 004b0369  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b036c  e8b3ffffff             -call 0x4b0324
    cpu.esp -= 4;
    sub_4b0324(app, cpu);
    if (cpu.terminate) return;
    // 004b0371  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 004b0374  ebc6                   -jmp 0x4b033c
    goto L_0x004b033c;
L_0x004b0376:
    // 004b0376  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b0377  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0378  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0379  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b037a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b037b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b037c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b037c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b037d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b037e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b037f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b0380  be1e124e00             -mov esi, 0x4e121e
    cpu.esi = 5116446 /*0x4e121e*/;
    // 004b0385  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0387  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x004b0389:
    // 004b0389  b806124e00             -mov eax, 0x4e1206
    cpu.eax = 5116422 /*0x4e1206*/;
    // 004b038e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b0390  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
L_0x004b0392:
    // 004b0392  3d1e124e00             +cmp eax, 0x4e121e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5116446 /*0x4e121e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0397  7315                   -jae 0x4b03ae
    if (!cpu.flags.cf)
    {
        goto L_0x004b03ae;
    }
    // 004b0399  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b039c  740b                   -je 0x4b03a9
    if (cpu.flags.zf)
    {
        goto L_0x004b03a9;
    }
    // 004b039e  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b03a1  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b03a3  7704                   -ja 0x4b03a9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b03a9;
    }
    // 004b03a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b03a7  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x004b03a9:
    // 004b03a9  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b03ac  ebe4                   -jmp 0x4b0392
    goto L_0x004b0392;
L_0x004b03ae:
    // 004b03ae  81fb1e124e00           +cmp ebx, 0x4e121e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5116446 /*0x4e121e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b03b4  7412                   -je 0x4b03c8
    if (cpu.flags.zf)
    {
        goto L_0x004b03c8;
    }
    // 004b03b6  3a7301                 +cmp dh, byte ptr [ebx + 1]
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b03b9  7208                   -jb 0x4b03c3
    if (cpu.flags.cf)
    {
        goto L_0x004b03c3;
    }
    // 004b03bb  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b03be  e861ffffff             -call 0x4b0324
    cpu.esp -= 4;
    sub_4b0324(app, cpu);
    if (cpu.terminate) return;
L_0x004b03c3:
    // 004b03c3  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 004b03c6  ebc1                   -jmp 0x4b0389
    goto L_0x004b0389;
L_0x004b03c8:
    // 004b03c8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b03c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b03cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b03cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b03ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b03cf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b03d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b03d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b03d3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b03d5  8b3534945b00           -mov esi, dword ptr [0x5b9434]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004b03db  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b03dd  743f                   -je 0x4b041e
    if (cpu.flags.zf)
    {
        goto L_0x004b041e;
    }
    // 004b03df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b03e1  743b                   -je 0x4b041e
    if (cpu.flags.zf)
    {
        goto L_0x004b041e;
    }
    // 004b03e3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b03e5  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b03e6  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b03e8  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b03ea  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b03ec  49                     -dec ecx
    (cpu.ecx)--;
    // 004b03ed  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b03ef  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004b03f1  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b03f3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b03f4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b03f5  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b03f7  eb1f                   -jmp 0x4b0418
    goto L_0x004b0418;
L_0x004b03f9:
    // 004b03f9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b03fb  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b03fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b03ff  e891a80000             -call 0x4bac95
    cpu.esp -= 4;
    sub_4bac95(app, cpu);
    if (cpu.terminate) return;
    // 004b0404  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0406  750d                   -jne 0x4b0415
    if (!cpu.flags.zf)
    {
        goto L_0x004b0415;
    }
    // 004b0408  803c393d               +cmp byte ptr [ecx + edi], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b040c  7507                   -jne 0x4b0415
    if (!cpu.flags.zf)
    {
        goto L_0x004b0415;
    }
    // 004b040e  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b0411  01c8                   +add eax, ecx
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
    // 004b0413  eb0b                   -jmp 0x4b0420
    goto L_0x004b0420;
L_0x004b0415:
    // 004b0415  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b0418:
    // 004b0418  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b041a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b041c  75db                   -jne 0x4b03f9
    if (!cpu.flags.zf)
    {
        goto L_0x004b03f9;
    }
L_0x004b041e:
    // 004b041e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b0420:
    // 004b0420  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0423  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0424  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0425  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0426  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0427(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0427  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0428  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0429  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b042b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b042d:
    // 004b042d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b042f  e895a90000             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004b0434  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0436  750c                   -jne 0x4b0444
    if (!cpu.flags.zf)
    {
        goto L_0x004b0444;
    }
    // 004b0438  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b043a  e8c6a90000             -call 0x4bae05
    cpu.esp -= 4;
    sub_4bae05(app, cpu);
    if (cpu.terminate) return;
    // 004b043f  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0440  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0442  ebe9                   -jmp 0x4b042d
    goto L_0x004b042d;
L_0x004b0444:
    // 004b0444  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0446  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0447  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0448  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0449(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0449  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b044a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b044b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b044c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b044d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b044f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b0451  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b0453  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b0455  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0457  7438                   -je 0x4b0491
    if (cpu.flags.zf)
    {
        goto L_0x004b0491;
    }
L_0x004b0459:
    // 004b0459  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b045b  7658                   -jbe 0x4b04b5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b04b5;
    }
    // 004b045d  803900                 +cmp byte ptr [ecx], 0
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
    // 004b0460  7418                   -je 0x4b047a
    if (cpu.flags.zf)
    {
        goto L_0x004b047a;
    }
    // 004b0462  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004b0467  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0469  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b046b  e85a890000             -call 0x4b8dca
    cpu.esp -= 4;
    sub_4b8dca(app, cpu);
    if (cpu.terminate) return;
    // 004b0470  83f8ff                 +cmp eax, -1
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
    // 004b0473  750c                   -jne 0x4b0481
    if (!cpu.flags.zf)
    {
        goto L_0x004b0481;
    }
    // 004b0475  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0476  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0477  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0478  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0479  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b047a:
    // 004b047a  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 004b047f  eb34                   -jmp 0x4b04b5
    goto L_0x004b04b5;
L_0x004b0481:
    // 004b0481  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0483  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b0484  e87ca90000             -call 0x4bae05
    cpu.esp -= 4;
    sub_4bae05(app, cpu);
    if (cpu.terminate) return;
    // 004b0489  83c602                 +add esi, 2
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
    // 004b048c  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b048d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b048f  ebc8                   -jmp 0x4b0459
    goto L_0x004b0459;
L_0x004b0491:
    // 004b0491  803900                 +cmp byte ptr [ecx], 0
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
    // 004b0494  741f                   -je 0x4b04b5
    if (cpu.flags.zf)
    {
        goto L_0x004b04b5;
    }
    // 004b0496  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004b049b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b049d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b049f  e826890000             -call 0x4b8dca
    cpu.esp -= 4;
    sub_4b8dca(app, cpu);
    if (cpu.terminate) return;
    // 004b04a4  83f8ff                 +cmp eax, -1
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
    // 004b04a7  740e                   -je 0x4b04b7
    if (cpu.flags.zf)
    {
        goto L_0x004b04b7;
    }
    // 004b04a9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b04ab  e855a90000             -call 0x4bae05
    cpu.esp -= 4;
    sub_4bae05(app, cpu);
    if (cpu.terminate) return;
    // 004b04b0  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b04b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b04b3  ebdc                   -jmp 0x4b0491
    goto L_0x004b0491;
L_0x004b04b5:
    // 004b04b5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004b04b7:
    // 004b04b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b04bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b04bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b04bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b04be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b04bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b04c0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b04c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b04c5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b04c7  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b04cb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b04d0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b04d4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b04d7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b04d9  7415                   -je 0x4b04f0
    if (cpu.flags.zf)
    {
        goto L_0x004b04f0;
    }
    // 004b04db  66833900               +cmp word ptr [ecx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b04df  750f                   -jne 0x4b04f0
    if (!cpu.flags.zf)
    {
        goto L_0x004b04f0;
    }
    // 004b04e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b04e3  7509                   -jne 0x4b04ee
    if (!cpu.flags.zf)
    {
        goto L_0x004b04ee;
    }
    // 004b04e5  e848a90000             -call 0x4bae32
    cpu.esp -= 4;
    sub_4bae32(app, cpu);
    if (cpu.terminate) return;
    // 004b04ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b04ec  7502                   -jne 0x4b04f0
    if (!cpu.flags.zf)
    {
        goto L_0x004b04f0;
    }
L_0x004b04ee:
    // 004b04ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b04f0:
    // 004b04f0  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b04f5  750b                   -jne 0x4b0502
    if (!cpu.flags.zf)
    {
        goto L_0x004b0502;
    }
    // 004b04f7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b04f9  e834a90000             -call 0x4bae32
    cpu.esp -= 4;
    sub_4bae32(app, cpu);
    if (cpu.terminate) return;
    // 004b04fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0500  7511                   -jne 0x4b0513
    if (!cpu.flags.zf)
    {
        goto L_0x004b0513;
    }
L_0x004b0502:
    // 004b0502  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0504  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0506  e893a90000             -call 0x4bae9e
    cpu.esp -= 4;
    sub_4bae9e(app, cpu);
    if (cpu.terminate) return;
    // 004b050b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b050d  0f849a000000           -je 0x4b05ad
    if (cpu.flags.zf)
    {
        goto L_0x004b05ad;
    }
L_0x004b0513:
    // 004b0513  833d38945b0000         +cmp dword ptr [0x5b9438], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b051a  7505                   -jne 0x4b0521
    if (!cpu.flags.zf)
    {
        goto L_0x004b0521;
    }
    // 004b051c  e843aa0000             -call 0x4baf64
    cpu.esp -= 4;
    sub_4baf64(app, cpu);
    if (cpu.terminate) return;
L_0x004b0521:
    // 004b0521  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b0525  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0527  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0529  e8cb000000             -call 0x4b05f9
    cpu.esp -= 4;
    sub_4b05f9(app, cpu);
    if (cpu.terminate) return;
    // 004b052e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0530  0f8577000000           -jne 0x4b05ad
    if (!cpu.flags.zf)
    {
        goto L_0x004b05ad;
    }
    // 004b0536  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0538  e877aa0000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004b053d  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b0540  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0544  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b0547  e87760ffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b054c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b054e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b0550  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0552  750c                   -jne 0x4b0560
    if (!cpu.flags.zf)
    {
        goto L_0x004b0560;
    }
L_0x004b0554:
    // 004b0554  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b0559  e80360ffff             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 004b055e  eb4d                   -jmp 0x4b05ad
    goto L_0x004b05ad;
L_0x004b0560:
    // 004b0560  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0562  7427                   -je 0x4b058b
    if (cpu.flags.zf)
    {
        goto L_0x004b058b;
    }
    // 004b0564  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0566  e849aa0000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004b056b  40                     -inc eax
    (cpu.eax)++;
    // 004b056c  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0570  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b0574  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b0577  e84760ffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b057c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b057e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0580  750b                   -jne 0x4b058d
    if (!cpu.flags.zf)
    {
        goto L_0x004b058d;
    }
    // 004b0582  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0584  e86fafffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b0589  ebc9                   -jmp 0x4b0554
    goto L_0x004b0554;
L_0x004b058b:
    // 004b058b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004b058d:
    // 004b058d  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b0591  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b0593  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0595  e82daa0000             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004b059a  83f8ff                 +cmp eax, -1
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
    // 004b059d  7515                   -jne 0x4b05b4
    if (!cpu.flags.zf)
    {
        goto L_0x004b05b4;
    }
L_0x004b059f:
    // 004b059f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b05a1  e852afffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b05a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b05a8  e84bafffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004b05ad:
    // 004b05ad  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b05b2  eb3d                   -jmp 0x4b05f1
    goto L_0x004b05f1;
L_0x004b05b4:
    // 004b05b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b05b6  7416                   -je 0x4b05ce
    if (cpu.flags.zf)
    {
        goto L_0x004b05ce;
    }
    // 004b05b8  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b05bc  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b05c0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b05c2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b05c4  e8fea90000             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004b05c9  83f8ff                 +cmp eax, -1
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
    // 004b05cc  74d1                   -je 0x4b059f
    if (cpu.flags.zf)
    {
        goto L_0x004b059f;
    }
L_0x004b05ce:
    // 004b05ce  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b05d2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b05d4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b05d6  e8b6c6feff             -call 0x49cc91
    cpu.esp -= 4;
    sub_49cc91(app, cpu);
    if (cpu.terminate) return;
    // 004b05db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b05dd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b05df  e814afffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b05e4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b05e6  7407                   -je 0x4b05ef
    if (cpu.flags.zf)
    {
        goto L_0x004b05ef;
    }
    // 004b05e8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b05ea  e809afffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004b05ef:
    // 004b05ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b05f1:
    // 004b05f1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b05f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b05f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b05f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b05f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b05f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b05f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b05f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b05fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b05fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b05fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b05fd  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b0600  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0602  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b0604  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0606  750a                   -jne 0x4b0612
    if (!cpu.flags.zf)
    {
        goto L_0x004b0612;
    }
L_0x004b0608:
    // 004b0608  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b060d  e9b2010000             -jmp 0x4b07c4
    goto L_0x004b07c4;
L_0x004b0612:
    // 004b0612  66833800               +cmp word ptr [eax], 0
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
    // 004b0616  74f0                   -je 0x4b0608
    if (cpu.flags.zf)
    {
        goto L_0x004b0608;
    }
    // 004b0618  833d38945b0000         +cmp dword ptr [0x5b9438], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b061f  7505                   -jne 0x4b0626
    if (!cpu.flags.zf)
    {
        goto L_0x004b0626;
    }
    // 004b0621  e83ea90000             -call 0x4baf64
    cpu.esp -= 4;
    sub_4baf64(app, cpu);
    if (cpu.terminate) return;
L_0x004b0626:
    // 004b0626  8b3538945b00           -mov esi, dword ptr [0x5b9438]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004b062c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b062e  7539                   -jne 0x4b0669
    if (!cpu.flags.zf)
    {
        goto L_0x004b0669;
    }
    // 004b0630  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b0632  0f848a010000           -je 0x4b07c2
    if (cpu.flags.zf)
    {
        goto L_0x004b07c2;
    }
    // 004b0638  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004b063d  e8815fffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b0642  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0644  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0646  74c0                   -je 0x4b0608
    if (cpu.flags.zf)
    {
        goto L_0x004b0608;
    }
    // 004b0648  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b064e  a338945b00             -mov dword ptr [0x5b9438], eax
    app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */) = cpu.eax;
    // 004b0653  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b065a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b065d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b065f  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
    // 004b0664  e9cb000000             -jmp 0x4b0734
    goto L_0x004b0734;
L_0x004b0669:
    // 004b0669  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b066b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b066d  e85a010000             -call 0x4b07cc
    cpu.esp -= 4;
    sub_4b07cc(app, cpu);
    if (cpu.terminate) return;
    // 004b0672  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b0674  0f8448010000           -je 0x4b07c2
    if (cpu.flags.zf)
    {
        goto L_0x004b07c2;
    }
    // 004b067a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b067c  0f8fa7000000           -jg 0x4b0729
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b0729;
    }
    // 004b0682  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b0684  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0686  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b0688  40                     -inc eax
    (cpu.eax)++;
    // 004b0689  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004b068c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b0690  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b0693  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0697  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b069b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b069d  833d30945b0000         +cmp dword ptr [0x5b9430], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b06a4  7534                   -jne 0x4b06da
    if (!cpu.flags.zf)
    {
        goto L_0x004b06da;
    }
    // 004b06a6  e8185fffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b06ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b06ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b06af  0f8453ffffff           -je 0x4b0608
    if (cpu.flags.zf)
    {
        goto L_0x004b0608;
    }
    // 004b06b5  8b1538945b00           -mov edx, dword ptr [0x5b9438]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004b06bb  e8bda90000             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
    // 004b06c0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b06c4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b06c6  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b06ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b06cc  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b06ce  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
    // 004b06d3  e8571ffeff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004b06d8  eb34                   -jmp 0x4b070e
    goto L_0x004b070e;
L_0x004b06da:
    // 004b06da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b06dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b06de  e808020000             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 004b06e3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b06e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b06e7  0f841bffffff           -je 0x4b0608
    if (cpu.flags.zf)
    {
        goto L_0x004b0608;
    }
    // 004b06ed  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b06f1  01c3                   +add ebx, eax
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
    // 004b06f3  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b06f6  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004b06fc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b06ff  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b0701  e85f020000             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 004b0706  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b0709  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
L_0x004b070e:
    // 004b070e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0710  c744860400000000       -mov dword ptr [esi + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004b0718  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004b071d  893538945b00           -mov dword ptr [0x5b9438], esi
    app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */) = cpu.esi;
    // 004b0723  c6040100               -mov byte ptr [ecx + eax], 0
    app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 004b0727  eb0b                   -jmp 0x4b0734
    goto L_0x004b0734;
L_0x004b0729:
    // 004b0729  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b072b  0f8491000000           -je 0x4b07c2
    if (cpu.flags.zf)
    {
        goto L_0x004b07c2;
    }
    // 004b0731  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004b0734:
    // 004b0734  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b0736  e879a80000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004b073b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b073f  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004b0744  803c0100               +cmp byte ptr [ecx + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b0748  7407                   -je 0x4b0751
    if (cpu.flags.zf)
    {
        goto L_0x004b0751;
    }
    // 004b074a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b074c  8b1c9e                 -mov ebx, dword ptr [esi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004b074f  eb02                   -jmp 0x4b0753
    goto L_0x004b0753;
L_0x004b0751:
    // 004b0751  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b0753:
    // 004b0753  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0755  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0759  e856a80000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004b075e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b0760  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b0762  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0764  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0767  e87f010000             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 004b076c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b0770  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0772  0f8490feffff           -je 0x4b0608
    if (cpu.flags.zf)
    {
        goto L_0x004b0608;
    }
    // 004b0778  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b077c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b077e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b0780  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b0783  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0785  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b0789  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b078c  e8eca80000             -call 0x4bb07d
    cpu.esp -= 4;
    sub_4bb07d(app, cpu);
    if (cpu.terminate) return;
    // 004b0791  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b0795  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b0797  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b079b  66c7003d00             -mov word ptr [eax], 0x3d
    app->getMemory<x86::reg16>(cpu.eax) = 61 /*0x3d*/;
    // 004b07a0  8d4702                 -lea eax, [edi + 2]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b07a3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b07a5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b07a7  e8f6a80000             -call 0x4bb0a2
    cpu.esp -= 4;
    sub_4bb0a2(app, cpu);
    if (cpu.terminate) return;
    // 004b07ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b07ae  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b07b1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b07b3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b07b7  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b07b9  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004b07be  c6040101               -mov byte ptr [ecx + eax], 1
    app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1) = 1 /*0x1*/;
L_0x004b07c2:
    // 004b07c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b07c4:
    // 004b07c4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b07c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b07cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b07cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b07cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b07ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b07cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b07d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b07d1  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b07d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b07d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b07d6  a138945b00             -mov eax, dword ptr [0x5b9438]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004b07db  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b07df  e9de000000             -jmp 0x4b08c2
    goto L_0x004b08c2;
L_0x004b07e4:
    // 004b07e4  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004b07e8:
    // 004b07e8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b07ec  6683383d               +cmp word ptr [eax], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b07f0  0f858d000000           -jne 0x4b0883
    if (!cpu.flags.zf)
    {
        goto L_0x004b0883;
    }
    // 004b07f6  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b07fb  0f8582000000           -jne 0x4b0883
    if (!cpu.flags.zf)
    {
        goto L_0x004b0883;
    }
    // 004b0801  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0805  2b3538945b00           -sub esi, dword ptr [0x5b9438]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */)));
    // 004b080b  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b080e  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 004b0811  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0813  0f8565000000           -jne 0x4b087e
    if (!cpu.flags.zf)
    {
        goto L_0x004b087e;
    }
    // 004b0819  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b081d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0821  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004b0823  eb08                   -jmp 0x4b082d
    goto L_0x004b082d;
L_0x004b0825:
    // 004b0825  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004b0828  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b082a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b082d:
    // 004b082d  833900                 +cmp dword ptr [ecx], 0
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
    // 004b0830  75f3                   -jne 0x4b0825
    if (!cpu.flags.zf)
    {
        goto L_0x004b0825;
    }
    // 004b0832  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004b0838  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b083a  7447                   -je 0x4b0883
    if (cpu.flags.zf)
    {
        goto L_0x004b0883;
    }
    // 004b083c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b083e  803c0600               +cmp byte ptr [esi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b0842  7407                   -je 0x4b084b
    if (cpu.flags.zf)
    {
        goto L_0x004b084b;
    }
    // 004b0844  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b0846  e8adacffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004b084b:
    // 004b084b  8b1d38945b00           -mov ebx, dword ptr [0x5b9438]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004b0851  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b0853  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0855  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004b085b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004b085e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0860  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b0862  e8fe000000             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 004b0867  890d30945b00           -mov dword ptr [0x5b9430], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.ecx;
    // 004b086d  01f1                   +add ecx, esi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b086f  eb07                   -jmp 0x4b0878
    goto L_0x004b0878;
L_0x004b0871:
    // 004b0871  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b0874  46                     -inc esi
    (cpu.esi)++;
    // 004b0875  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004b0877  41                     -inc ecx
    (cpu.ecx)++;
L_0x004b0878:
    // 004b0878  39fe                   +cmp esi, edi
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
    // 004b087a  7d07                   -jge 0x4b0883
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0883;
    }
    // 004b087c  ebf3                   -jmp 0x4b0871
    goto L_0x004b0871;
L_0x004b087e:
    // 004b087e  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b0881  eb5f                   -jmp 0x4b08e2
    goto L_0x004b08e2;
L_0x004b0883:
    // 004b0883  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b0887  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0889  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004b088c  e829a80000             -call 0x4bb0ba
    cpu.esp -= 4;
    sub_4bb0ba(app, cpu);
    if (cpu.terminate) return;
    // 004b0891  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0893  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0895  668b4500               -mov ax, word ptr [ebp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp);
    // 004b0899  e81ca80000             -call 0x4bb0ba
    cpu.esp -= 4;
    sub_4bb0ba(app, cpu);
    if (cpu.terminate) return;
    // 004b089e  6639c2                 +cmp dx, ax
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b08a1  751a                   -jne 0x4b08bd
    if (!cpu.flags.zf)
    {
        goto L_0x004b08bd;
    }
    // 004b08a3  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b08a8  7413                   -je 0x4b08bd
    if (cpu.flags.zf)
    {
        goto L_0x004b08bd;
    }
    // 004b08aa  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b08ae  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b08b1  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b08b4  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b08b8  e92bffffff             -jmp 0x4b07e8
    goto L_0x004b07e8;
L_0x004b08bd:
    // 004b08bd  8344240804             -add dword ptr [esp + 8], 4
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b08c2:
    // 004b08c2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b08c6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b08c8  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b08cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b08ce  0f8510ffffff           -jne 0x4b07e4
    if (!cpu.flags.zf)
    {
        goto L_0x004b07e4;
    }
    // 004b08d4  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b08d8  a138945b00             -mov eax, dword ptr [0x5b9438]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004b08dd  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b08df  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004b08e2:
    // 004b08e2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b08e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b08eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b08eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b08ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b08ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b08ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b08ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b08f0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b08f2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b08f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b08f6  7509                   -jne 0x4b0901
    if (!cpu.flags.zf)
    {
        goto L_0x004b0901;
    }
    // 004b08f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b08fa  e8c45cffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b08ff  eb5e                   -jmp 0x4b095f
    goto L_0x004b095f;
L_0x004b0901:
    // 004b0901  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0903  7509                   -jne 0x4b090e
    if (!cpu.flags.zf)
    {
        goto L_0x004b090e;
    }
    // 004b0905  e8eeabffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b090a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b090c  eb51                   -jmp 0x4b095f
    goto L_0x004b095f;
L_0x004b090e:
    // 004b090e  e8b7a70000             -call 0x4bb0ca
    cpu.esp -= 4;
    sub_4bb0ca(app, cpu);
    if (cpu.terminate) return;
    // 004b0913  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0915  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0917  e8b9a70000             -call 0x4bb0d5
    cpu.esp -= 4;
    sub_4bb0d5(app, cpu);
    if (cpu.terminate) return;
    // 004b091c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b091e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0920  753b                   -jne 0x4b095d
    if (!cpu.flags.zf)
    {
        goto L_0x004b095d;
    }
    // 004b0922  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0924  e89a5cffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b0929  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b092b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b092d  7425                   -je 0x4b0954
    if (cpu.flags.zf)
    {
        goto L_0x004b0954;
    }
    // 004b092f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b0931  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0933  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b0935  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b0936  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b0938  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b093a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b093b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b093d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b0940  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0942  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b0944  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b0947  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b0949  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b094a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b094b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b094d  e8a6abffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b0952  eb09                   -jmp 0x4b095d
    goto L_0x004b095d;
L_0x004b0954:
    // 004b0954  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b0956  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0958  e878a70000             -call 0x4bb0d5
    cpu.esp -= 4;
    sub_4bb0d5(app, cpu);
    if (cpu.terminate) return;
L_0x004b095d:
    // 004b095d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004b095f:
    // 004b095f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0960  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0961  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0962  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0963  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0964  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0965(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0965  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0966  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0967  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0968  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b096a  39c2                   +cmp edx, eax
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
    // 004b096c  7440                   -je 0x4b09ae
    if (cpu.flags.zf)
    {
        goto L_0x004b09ae;
    }
    // 004b096e  7328                   -jae 0x4b0998
    if (!cpu.flags.cf)
    {
        goto L_0x004b0998;
    }
    // 004b0970  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004b0973  39c7                   +cmp edi, eax
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
    // 004b0975  7621                   -jbe 0x4b0998
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b0998;
    }
    // 004b0977  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004b097a  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004b097d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b097f  4f                     -dec edi
    (cpu.edi)--;
    // 004b0980  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b0981  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b0983  fd                     -std 
    cpu.flags.df = 1;
    // 004b0984  4e                     -dec esi
    (cpu.esi)--;
    // 004b0985  4f                     -dec edi
    (cpu.edi)--;
    // 004b0986  d1e9                   +shr ecx, 1
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
    // 004b0988  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
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
    // 004b098b  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004b098d  46                     -inc esi
    (cpu.esi)++;
    // 004b098e  47                     -inc edi
    (cpu.edi)++;
    // 004b098f  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b0992  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b0993  fc                     -cld 
    cpu.flags.df = 0;
    // 004b0994  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0995  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0996  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0997  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0998:
    // 004b0998  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b099a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b099c  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b099e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b099f  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b09a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b09a2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b09a5  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b09a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09a8  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b09ab  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b09ad  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004b09ae:
    // 004b09ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b09c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b09c0  833d7cf34d0000         +cmp dword ptr [0x4df37c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b09c7  7401                   -je 0x4b09ca
    if (cpu.flags.zf)
    {
        goto L_0x004b09ca;
    }
    // 004b09c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b09ca:
    // 004b09ca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b09cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b09cc  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 004b09d1  b8e8d64d00             -mov eax, 0x4dd6e8
    cpu.eax = 5101288 /*0x4dd6e8*/;
    // 004b09d6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b09db  e83c96fdff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 004b09e0  b8f4094b00             -mov eax, 0x4b09f4
    cpu.eax = 4917748 /*0x4b09f4*/;
    // 004b09e5  890d7cf34d00           -mov dword ptr [0x4df37c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */) = cpu.ecx;
    // 004b09eb  e8b0a3feff             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 004b09f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b09f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b09f4  833d7cf34d0000         +cmp dword ptr [0x4df37c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b09fb  7501                   -jne 0x4b09fe
    if (!cpu.flags.zf)
    {
        goto L_0x004b09fe;
    }
    // 004b09fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b09fe:
    // 004b09fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b09ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0a00  e8ab59ffff             -call 0x4a63b0
    cpu.esp -= 4;
    sub_4a63b0(app, cpu);
    if (cpu.terminate) return;
    // 004b0a05  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 004b0a0a  b8e8d64d00             -mov eax, 0x4dd6e8
    cpu.eax = 5101288 /*0x4dd6e8*/;
    // 004b0a0f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0a11  e80696fdff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 004b0a16  890d7cf34d00           -mov dword ptr [0x4df37c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */) = cpu.ecx;
    // 004b0a1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b0a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0a20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0a21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0a22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0a23  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b0a25  2eff15f0634c00         -call dword ptr cs:[0x4c63f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006320) /* 0x4c63f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0a2c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b0a2e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0a30  2eff15f0634c00         -call dword ptr cs:[0x4c63f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006320) /* 0x4c63f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0a37  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0a3a  750e                   -jne 0x4b0a4a
    if (!cpu.flags.zf)
    {
        goto L_0x004b0a4a;
    }
    // 004b0a3c  3d010d0000             +cmp eax, 0xd01
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3329 /*0xd01*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0a41  7c07                   -jl 0x4b0a4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0a4a;
    }
    // 004b0a43  3d040d0000             +cmp eax, 0xd04
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3332 /*0xd04*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0a48  7e06                   -jle 0x4b0a50
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0a50;
    }
L_0x004b0a4a:
    // 004b0a4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0a4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0a50:
    // 004b0a50  baf0fb4d00             -mov edx, 0x4dfbf0
    cpu.edx = 5110768 /*0x4dfbf0*/;
    // 004b0a55  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0a5a  891540ab4d00           -mov dword ptr [0x4dab40], edx
    app->getMemory<x86::reg32>(x86::reg32(5090112) /* 0x4dab40 */) = cpu.edx;
    // 004b0a60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0a70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0a71  baf4b64b00             -mov edx, 0x4bb6f4
    cpu.edx = 4962036 /*0x4bb6f4*/;
    // 004b0a76  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004b0a7b  e8785dffff             -call 0x4a67f8
    cpu.esp -= 4;
    sub_4a67f8(app, cpu);
    if (cpu.terminate) return;
    // 004b0a80  ba28b54b00             -mov edx, 0x4bb528
    cpu.edx = 4961576 /*0x4bb528*/;
    // 004b0a85  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 004b0a8a  e8695dffff             -call 0x4a67f8
    cpu.esp -= 4;
    sub_4a67f8(app, cpu);
    if (cpu.terminate) return;
    // 004b0a8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0aa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0aa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0aa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0aa3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0aa5  e8263afdff             -call 0x4844d0
    cpu.esp -= 4;
    sub_4844d0(app, cpu);
    if (cpu.terminate) return;
    // 004b0aaa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0aac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0aae  e8f142fdff             -call 0x484da4
    cpu.esp -= 4;
    sub_484da4(app, cpu);
    if (cpu.terminate) return;
    // 004b0ab3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0ab5  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0ab8  7d06                   -jge 0x4b0ac0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0ac0;
    }
L_0x004b0aba:
    // 004b0aba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0abc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0abd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0abe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0abf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0ac0:
    // 004b0ac0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0ac2  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004b0ac7  83e80c                 -sub eax, 0xc
    (cpu.eax) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0aca  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b0acc  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004b0ace  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0ad0  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004b0ad7  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b0ad9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004b0ade  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0ae0  b8b4174d00             -mov eax, 0x4d17b4
    cpu.eax = 5052340 /*0x4d17b4*/;
    // 004b0ae5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b0ae7  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004b0ae9  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0aeb  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004b0af2  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b0af4  39c3                   +cmp ebx, eax
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
    // 004b0af6  75c2                   -jne 0x4b0aba
    if (!cpu.flags.zf)
    {
        goto L_0x004b0aba;
    }
    // 004b0af8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b0afd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0aff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0b04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0b04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0b05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0b06  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0b07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0b08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0b09  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0b0b  e8c039fdff             -call 0x4844d0
    cpu.esp -= 4;
    sub_4844d0(app, cpu);
    if (cpu.terminate) return;
    // 004b0b10  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0b12  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0b14  e88b42fdff             -call 0x484da4
    cpu.esp -= 4;
    sub_484da4(app, cpu);
    if (cpu.terminate) return;
    // 004b0b19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0b1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0b1d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004b0b22  e879ffffff             -call 0x4b0aa0
    cpu.esp -= 4;
    sub_4b0aa0(app, cpu);
    if (cpu.terminate) return;
    // 004b0b27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0b29  7508                   -jne 0x4b0b33
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b33;
    }
L_0x004b0b2b:
    // 004b0b2b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0b2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0b33:
    // 004b0b33  8d043b                 -lea eax, [ebx + edi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 004b0b36  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004b0b3b  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0b3e  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004b0b42  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0b44  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004b0b4b  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b0b4d  8d57f4                 -lea edx, [edi - 0xc]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-12) /* -0xc */);
    // 004b0b50  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0b52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0b54  e887e0fdff             -call 0x48ebe0
    cpu.esp -= 4;
    sub_48ebe0(app, cpu);
    if (cpu.terminate) return;
    // 004b0b59  39c1                   +cmp ecx, eax
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
    // 004b0b5b  74ce                   -je 0x4b0b2b
    if (cpu.flags.zf)
    {
        goto L_0x004b0b2b;
    }
    // 004b0b5d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0b5f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0b61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0b68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0b68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0b69  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0b6a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0b6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0b6e  7505                   -jne 0x4b0b75
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b75;
    }
L_0x004b0b70:
    // 004b0b70  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0b72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0b75:
    // 004b0b75  e826ffffff             -call 0x4b0aa0
    cpu.esp -= 4;
    sub_4b0aa0(app, cpu);
    if (cpu.terminate) return;
    // 004b0b7a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0b7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0b7e  7522                   -jne 0x4b0ba2
    if (!cpu.flags.zf)
    {
        goto L_0x004b0ba2;
    }
    // 004b0b80  833d74fc4d0000         +cmp dword ptr [0x4dfc74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5110900) /* 0x4dfc74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0b87  74e7                   -je 0x4b0b70
    if (cpu.flags.zf)
    {
        goto L_0x004b0b70;
    }
    // 004b0b89  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0b8b  e81442fdff             -call 0x484da4
    cpu.esp -= 4;
    sub_484da4(app, cpu);
    if (cpu.terminate) return;
L_0x004b0b90:
    // 004b0b90  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0b92  75dc                   -jne 0x4b0b70
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b70;
    }
    // 004b0b94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0b96  e88d3dfdff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
    // 004b0b9b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0b9d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0b9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ba0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ba1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0ba2:
    // 004b0ba2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0ba4  e85bffffff             -call 0x4b0b04
    cpu.esp -= 4;
    sub_4b0b04(app, cpu);
    if (cpu.terminate) return;
    // 004b0ba9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0bab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0bad  74e1                   -je 0x4b0b90
    if (cpu.flags.zf)
    {
        goto L_0x004b0b90;
    }
    // 004b0baf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0bb1  e8ee41fdff             -call 0x484da4
    cpu.esp -= 4;
    sub_484da4(app, cpu);
    if (cpu.terminate) return;
    // 004b0bb6  2b0570fc4d00           +sub eax, dword ptr [0x4dfc70]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5110896) /* 0x4dfc70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0bbc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b0bbe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0bc0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0bc2  e86175fdff             -call 0x488128
    cpu.esp -= 4;
    sub_488128(app, cpu);
    if (cpu.terminate) return;
    // 004b0bc7  ebc7                   -jmp 0x4b0b90
    goto L_0x004b0b90;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b0bcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0bcc  c70550dd4d00680b4b00   -mov dword ptr [0x4ddd50], 0x4b0b68
    app->getMemory<x86::reg32>(x86::reg32(5102928) /* 0x4ddd50 */) = 4918120 /*0x4b0b68*/;
    // 004b0bd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0be0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0be1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0be2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0be3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0be6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0be8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b0bea  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b0bec  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 004b0bf2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0bf4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004b0bf6  7415                   -je 0x4b0c0d
    if (cpu.flags.zf)
    {
        goto L_0x004b0c0d;
    }
    // 004b0bf8  83fd01                 +cmp ebp, 1
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
    // 004b0bfb  7d04                   -jge 0x4b0c01
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0c01;
    }
    // 004b0bfd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b0bff  7d13                   -jge 0x4b0c14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0c14;
    }
L_0x004b0c01:
    // 004b0c01  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004b0c06:
    // 004b0c06  83c408                 +add esp, 8
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
    // 004b0c09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0c0d:
    // 004b0c0d  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004b0c12  ebf2                   -jmp 0x4b0c06
    goto L_0x004b0c06;
L_0x004b0c14:
    // 004b0c14  e84747ffff             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 004b0c19  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0c1b  e84c4bffff             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 004b0c20  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0c22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0c24  0f8ca9000000           -jl 0x4b0cd3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0cd3;
    }
    // 004b0c2a  83fb7f                 +cmp ebx, 0x7f
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
    // 004b0c2d  0f8fa0000000           -jg 0x4b0cd3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b0cd3;
    }
    // 004b0c33  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0c35  0f8c98000000           -jl 0x4b0cd3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0cd3;
    }
    // 004b0c3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0c3c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b0c3f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0c41  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004b0c44  05b0bf5900             -add eax, 0x59bfb0
    (cpu.eax) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 004b0c49  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0c4b  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004b0c4e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b0c52  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b0c54  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0c58  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004b0c5b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0c5d  0f8481000000           -je 0x4b0ce4
    if (cpu.flags.zf)
    {
        goto L_0x004b0ce4;
    }
    // 004b0c63  beb0bf5900             -mov esi, 0x59bfb0
    cpu.esi = 5881776 /*0x59bfb0*/;
    // 004b0c68  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b0c6c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004b0c6e:
    // 004b0c6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0c70  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0c74  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 004b0c77  39d8                   +cmp eax, ebx
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
    // 004b0c79  7540                   -jne 0x4b0cbb
    if (!cpu.flags.zf)
    {
        goto L_0x004b0cbb;
    }
    // 004b0c7b  807e0c01               +cmp byte ptr [esi + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b0c7f  753a                   -jne 0x4b0cbb
    if (!cpu.flags.zf)
    {
        goto L_0x004b0cbb;
    }
    // 004b0c81  833e00                 +cmp dword ptr [esi], 0
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
    // 004b0c84  7c35                   -jl 0x4b0cbb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0cbb;
    }
    // 004b0c86  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 004b0c89  8b5035                 -mov edx, dword ptr [eax + 0x35]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(53) /* 0x35 */);
    // 004b0c8c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b0c8f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b0c92  884839                 -mov byte ptr [eax + 0x39], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(57) /* 0x39 */) = cpu.cl;
    // 004b0c95  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0c99  0faf90a4bf5900         -imul edx, dword ptr [eax + 0x59bfa4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881764) /* 0x59bfa4 */))));
    // 004b0ca0  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 004b0ca5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0ca7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0caa  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0cac  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0cae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0cb0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b0cb2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b0cb4  e89386fdff             -call 0x48934c
    cpu.esp -= 4;
    sub_48934c(app, cpu);
    if (cpu.terminate) return;
    // 004b0cb9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b0cbb:
    // 004b0cbb  47                     -inc edi
    (cpu.edi)++;
    // 004b0cbc  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004b0cbf  83ff10                 +cmp edi, 0x10
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0cc2  7caa                   -jl 0x4b0c6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0c6e;
    }
    // 004b0cc4  e8ab46ffff             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004b0cc9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0ccb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ccc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0ccf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0cd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0cd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0cd2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0cd3:
    // 004b0cd3  e89c46ffff             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004b0cd8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004b0cdd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0ce0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ce1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ce2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ce3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0ce4:
    // 004b0ce4  884c2839               -mov byte ptr [eax + ebp + 0x39], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(57) /* 0x39 */ + cpu.ebp * 1) = cpu.cl;
    // 004b0ce8  8b442835               -mov eax, dword ptr [eax + ebp + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(53) /* 0x35 */ + cpu.ebp * 1);
    // 004b0cec  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b0cef  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b0cf2  8b93a4bf5900           -mov edx, dword ptr [ebx + 0x59bfa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5881764) /* 0x59bfa4 */);
    // 004b0cf8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004b0cfb  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 004b0d00  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0d02  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0d05  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0d07  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0d09  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b0d0b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0d0d  e83a86fdff             -call 0x48934c
    cpu.esp -= 4;
    sub_48934c(app, cpu);
    if (cpu.terminate) return;
    // 004b0d12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0d14  e85b46ffff             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004b0d19  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0d1b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d1c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0d1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0d31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0d32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0d33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0d35  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b0d38  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0d3a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004b0d3d  05b0bf5900             -add eax, 0x59bfb0
    (cpu.eax) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 004b0d42  8b500e                 -mov edx, dword ptr [eax + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b0d45  668b5842               -mov bx, word ptr [eax + 0x42]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 004b0d49  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b0d4c  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 004b0d4f  7424                   -je 0x4b0d75
    if (cpu.flags.zf)
    {
        goto L_0x004b0d75;
    }
    // 004b0d51  8b4854                 -mov ecx, dword ptr [eax + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b0d54  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0d56  7446                   -je 0x4b0d9e
    if (cpu.flags.zf)
    {
        goto L_0x004b0d9e;
    }
    // 004b0d58  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0d5a  8b5854                 -mov ebx, dword ptr [eax + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b0d5d  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 004b0d60  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
L_0x004b0d64:
    // 004b0d64  8b5840                 -mov ebx, dword ptr [eax + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004b0d67  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b0d6a  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004b0d6d  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b0d70  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 004b0d73  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b0d75:
    // 004b0d75  8b585c                 -mov ebx, dword ptr [eax + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004b0d78  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0d7a  741a                   -je 0x4b0d96
    if (cpu.flags.zf)
    {
        goto L_0x004b0d96;
    }
    // 004b0d7c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0d7e  8a483f                 -mov cl, byte ptr [eax + 0x3f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */);
    // 004b0d81  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
    // 004b0d85  8b583e                 -mov ebx, dword ptr [eax + 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 004b0d88  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b0d8b  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004b0d8e  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b0d91  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 004b0d94  01ca                   +add edx, ecx
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
L_0x004b0d96:
    // 004b0d96  66895012               -mov word ptr [eax + 0x12], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */) = cpu.dx;
    // 004b0d9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0d9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0d9e:
    // 004b0d9e  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 004b0da1  ebc1                   -jmp 0x4b0d64
    goto L_0x004b0d64;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b0db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0db0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0db1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0db2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0db3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0db4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0db7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b0db9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0dbb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b0dbd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0dbf  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b0dc4  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b0dca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b0dcc  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004b0dcf  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b0dd1  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b0dd4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b0dd8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0dda  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b0ddd  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 004b0de0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0de4  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004b0de7  0fafef                 -imul ebp, edi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b0dea  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b0dec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0dee  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004b0df1  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b0df7  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b0df9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b0dfb  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b0e01  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b0e03  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0e05  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004b0e08  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004b0e0b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b0e0d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b0e0f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b0e12  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004b0e15  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b0e18  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b0e1a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b0e1c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b0e1f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b0e21  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b0e23  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b0e25  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b0e27  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b0e2b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b0e2c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b0e2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0e2f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0e32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0e38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0e38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0e39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0e3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0e3b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0e3e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b0e40  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0e42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0e44  7c23                   -jl 0x4b0e69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0e69;
    }
L_0x004b0e46:
    // 004b0e46  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0e48  7d05                   -jge 0x4b0e4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0e4f;
    }
    // 004b0e4a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b0e4c  80f301                 -xor bl, 1
    cpu.bl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004b0e4f:
    // 004b0e4f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b0e51  e85affffff             -call 0x4b0db0
    cpu.esp -= 4;
    sub_4b0db0(app, cpu);
    if (cpu.terminate) return;
    // 004b0e56  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0e58  7518                   -jne 0x4b0e72
    if (!cpu.flags.zf)
    {
        goto L_0x004b0e72;
    }
    // 004b0e5a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b0e5c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b0e5e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b0e5f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b0e60  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0e62  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0e65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0e69:
    // 004b0e69  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b0e6e  f7d8                   +neg eax
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
    // 004b0e70  ebd4                   -jmp 0x4b0e46
    goto L_0x004b0e46;
L_0x004b0e72:
    // 004b0e72  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0e76  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0e77  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0e7b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0e7c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0e80  e833030000             -call 0x4b11b8
    cpu.esp -= 4;
    sub_4b11b8(app, cpu);
    if (cpu.terminate) return;
    // 004b0e85  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b0e87  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b0e89  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b0e8a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b0e8b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0e8d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0e90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0e94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0e94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0e95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0e96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0e97  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0e98  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0e99  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b0e9d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0ea1  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0ea5  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004b0eaa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b0eac:
    // 004b0eac  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b0eae  4b                     -dec ebx
    (cpu.ebx)--;
    // 004b0eaf  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b0eb1  c1ee1f                 -shr esi, 0x1f
    cpu.esi >>= 31 /*0x1f*/ % 32;
    // 004b0eb4  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b0eb6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b0eb8  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0eba  39f8                   +cmp eax, edi
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
    // 004b0ebc  7203                   -jb 0x4b0ec1
    if (cpu.flags.cf)
    {
        goto L_0x004b0ec1;
    }
    // 004b0ebe  42                     -inc edx
    (cpu.edx)++;
    // 004b0ebf  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x004b0ec1:
    // 004b0ec1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0ec3  75e7                   -jne 0x4b0eac
    if (!cpu.flags.zf)
    {
        goto L_0x004b0eac;
    }
    // 004b0ec5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0ec7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ec8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ec9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0eca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ecb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ecc  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0ed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0ed2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0ed3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0ed4  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0ed8  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0edc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0ede  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0ee0  7c28                   -jl 0x4b0f0a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b0f0a;
    }
L_0x004b0ee2:
    // 004b0ee2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0ee4  7d05                   -jge 0x4b0eeb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0eeb;
    }
    // 004b0ee6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b0ee8  80f201                 -xor dl, 1
    cpu.dl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004b0eeb:
    // 004b0eeb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0eec  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0ef0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0ef1  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0ef5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0ef6  e899ffffff             -call 0x4b0e94
    cpu.esp -= 4;
    sub_4b0e94(app, cpu);
    if (cpu.terminate) return;
    // 004b0efb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0efd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0eff  7402                   -je 0x4b0f03
    if (cpu.flags.zf)
    {
        goto L_0x004b0f03;
    }
    // 004b0f01  f7d8                   +neg eax
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
L_0x004b0f03:
    // 004b0f03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f07  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004b0f0a:
    // 004b0f0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0f0b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0f0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f0d  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b0f11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0f12  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b0f16  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b0f1b  e898020000             -call 0x4b11b8
    cpu.esp -= 4;
    sub_4b11b8(app, cpu);
    if (cpu.terminate) return;
    // 004b0f20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f22  ebbe                   -jmp 0x4b0ee2
    goto L_0x004b0ee2;
}

/* align: skip  */
void Application::sub_4b0f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0f24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0f27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0f28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0f29  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0f2a  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b0f2d  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004b0f31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0f32  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004b0f36  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f37  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004b0f3b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f3c  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0f40  e84fffffff             -call 0x4b0e94
    cpu.esp -= 4;
    sub_4b0e94(app, cpu);
    if (cpu.terminate) return;
    // 004b0f45  e866feffff             -call 0x4b0db0
    cpu.esp -= 4;
    sub_4b0db0(app, cpu);
    if (cpu.terminate) return;
    // 004b0f4a  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b0f4e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0f4f  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b0f53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0f54  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0f58  e85b020000             -call 0x4b11b8
    cpu.esp -= 4;
    sub_4b11b8(app, cpu);
    if (cpu.terminate) return;
    // 004b0f5d  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0f61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0f62  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0f66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0f67  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f69  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0f6d  e872000000             -call 0x4b0fe4
    cpu.esp -= 4;
    sub_4b0fe4(app, cpu);
    if (cpu.terminate) return;
    // 004b0f72  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0f76  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b0f79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f7c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f7f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b0f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0f84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0f87  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0f88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0f89  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0f8a  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b0f8d  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004b0f91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0f92  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004b0f96  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f97  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004b0f9b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f9c  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0fa0  e82bffffff             -call 0x4b0ed0
    cpu.esp -= 4;
    sub_4b0ed0(app, cpu);
    if (cpu.terminate) return;
    // 004b0fa5  e88efeffff             -call 0x4b0e38
    cpu.esp -= 4;
    sub_4b0e38(app, cpu);
    if (cpu.terminate) return;
    // 004b0faa  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b0fae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0faf  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b0fb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0fb4  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0fb8  e8fb010000             -call 0x4b11b8
    cpu.esp -= 4;
    sub_4b11b8(app, cpu);
    if (cpu.terminate) return;
    // 004b0fbd  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0fc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0fc2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0fc6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0fc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0fc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0fc9  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0fcd  e812000000             -call 0x4b0fe4
    cpu.esp -= 4;
    sub_4b0fe4(app, cpu);
    if (cpu.terminate) return;
    // 004b0fd2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0fd6  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b0fd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fdf  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b0fe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0fe4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0fe5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0fe6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0fe7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0fea  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b0fec  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0ff0  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004b0ff4  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b0ff8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b0ffb  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b0fff  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1001  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b1005  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b1009  3b3424                 +cmp esi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b100c  7711                   -ja 0x4b101f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b101f;
    }
    // 004b100e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b1010  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1012  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1013  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1014  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b1016  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b1019  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b101a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b101b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b101c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004b101f:
    // 004b101f  ff442404               -inc dword ptr [esp + 4]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))++;
    // 004b1023  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b1025  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1027  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1028  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1029  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b102b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b102e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b102f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1030  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1031  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4b1034(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1034  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1035  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1036  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1037  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b103a  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b103e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1040  83f820                 +cmp eax, 0x20
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
    // 004b1043  7d46                   -jge 0x4b108b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b108b;
    }
    // 004b1045  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1047  7458                   -je 0x4b10a1
    if (cpu.flags.zf)
    {
        goto L_0x004b10a1;
    }
    // 004b1049  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b104a  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b104e  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1050  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b1052  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b1056  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b105a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b105c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b1061  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1063  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b1067  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b1069  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b106b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b106f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b1070:
    // 004b1070  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b1074  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x004b1076:
    // 004b1076  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1077  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1078  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b107c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b107e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b107f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1080  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b1082  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1085  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1086  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1087  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1088  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004b108b:
    // 004b108b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b108d  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b1090  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b1093  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1095  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b1099  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b109b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b109f  ebcf                   -jmp 0x4b1070
    goto L_0x004b1070;
L_0x004b10a1:
    // 004b10a1  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b10a5  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b10a9  ebcb                   -jmp 0x4b1076
    goto L_0x004b1076;
}

/* align: skip 0x90 */
void Application::sub_4b10ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b10ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b10ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b10ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b10af  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b10b2  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b10b6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b10b8  83f820                 +cmp eax, 0x20
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
    // 004b10bb  7d4a                   -jge 0x4b1107
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1107;
    }
    // 004b10bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b10bf  745c                   -je 0x4b111d
    if (cpu.flags.zf)
    {
        goto L_0x004b111d;
    }
    // 004b10c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b10c2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b10c7  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b10cb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b10cd  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b10d1  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b10d3  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b10d5  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 004b10d7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b10d9  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b10db  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b10df  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b10e1  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b10e5  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b10e7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b10eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b10ec:
    // 004b10ec  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b10f0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x004b10f2:
    // 004b10f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b10f3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b10f4  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b10f8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b10fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b10fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b10fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b10fe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1102  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1103  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1104  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004b1107:
    // 004b1107  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b110a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b110c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b1110  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004b1112  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b1114  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b1117  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b111b  ebcf                   -jmp 0x4b10ec
    goto L_0x004b10ec;
L_0x004b111d:
    // 004b111d  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b1121  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b1125  ebcb                   -jmp 0x4b10f2
    goto L_0x004b10f2;
}

/* align: skip 0x90 */
void Application::sub_4b1128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1128  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1129  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b112a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b112b  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b112e  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b1132  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1134  83f820                 +cmp eax, 0x20
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
    // 004b1137  7d48                   -jge 0x4b1181
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1181;
    }
    // 004b1139  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b113b  7460                   -je 0x4b119d
    if (cpu.flags.zf)
    {
        goto L_0x004b119d;
    }
    // 004b113d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b113e  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b1143  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b1147  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1149  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b114d  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004b114f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1151  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 004b1153  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b1155  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1157  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b115b  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b115d  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b1161  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004b1163  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b1167  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b1168:
    // 004b1168  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b116a  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b116e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b116f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1170  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b1172  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1174  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1175  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1176  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b1178  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b117b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b117c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b117d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b117e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004b1181:
    // 004b1181  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b1184  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1186  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b118a  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004b118c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b1190  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b1194  c1f81f                 +sar eax, 0x1f
    {
        x86::reg8 tmp = 31 /*0x1f*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004b1197  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b119b  ebcb                   -jmp 0x4b1168
    goto L_0x004b1168;
L_0x004b119d:
    // 004b119d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b119f  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b11a3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b11a4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b11a5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b11a7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b11a9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b11aa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b11ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b11ad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b11b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11b3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b11b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b11b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b11b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b11ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b11bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b11bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b11bd  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b11c0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b11c2  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b11c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b11c8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b11cb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b11cd  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b11d1  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b11d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b11d6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b11da  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004b11dc  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b11df  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b11e3  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004b11e6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b11e8  7413                   -je 0x4b11fd
    if (cpu.flags.zf)
    {
        goto L_0x004b11fd;
    }
    // 004b11ea  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b11ec  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b11ee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b11ef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b11f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b11f2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b11f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11fa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004b11fd:
    // 004b11fd  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b1200  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b1204  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b1206  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1208  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1209  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b120a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b120c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b120f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1210  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1211  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1212  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1213  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1214  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b1218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1218  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b1219  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b121a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b121b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b121e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b1220  83fa20                 +cmp edx, 0x20
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
    // 004b1223  7d29                   -jge 0x4b124e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b124e;
    }
    // 004b1225  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1227  7433                   -je 0x4b125c
    if (cpu.flags.zf)
    {
        goto L_0x004b125c;
    }
    // 004b1229  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004b122b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b122d  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b122f  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b1234  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1236  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004b1238  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x004b123b:
    // 004b123b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b123f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b1241  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b1243  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1244  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b1245  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b1247  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b124a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b124b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b124c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b124d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b124e:
    // 004b124e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1250  83ea20                 -sub edx, 0x20
    (cpu.edx) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b1253  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b1256  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004b1258  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b125a  ebdf                   -jmp 0x4b123b
    goto L_0x004b123b;
L_0x004b125c:
    // 004b125c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b125f  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004b1262  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b1266  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004b1268  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b126a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b126b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b126c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b126e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b1271  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1272  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1273  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1274  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b1278(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b1278  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1279  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b127a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b127b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b127c  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b127f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b1281  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1283  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1284  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b1288  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004b128d  e886ffffff             -call 0x4b1218
    cpu.esp -= 4;
    sub_4b1218(app, cpu);
    if (cpu.terminate) return;
    // 004b1292  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b1296  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1297  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b129b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b129c  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004b12a1  e8defcffff             -call 0x4b0f84
    cpu.esp -= 4;
    sub_4b0f84(app, cpu);
    if (cpu.terminate) return;
    // 004b12a6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b12aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b12ab  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b12ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b12af  e864ffffff             -call 0x4b1218
    cpu.esp -= 4;
    sub_4b1218(app, cpu);
    if (cpu.terminate) return;
    // 004b12b4  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b12b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b12b9  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b12bd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b12be  e80dfcffff             -call 0x4b0ed0
    cpu.esp -= 4;
    sub_4b0ed0(app, cpu);
    if (cpu.terminate) return;
    // 004b12c3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b12c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b12ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b12d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b12d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b12d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b12d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b12d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b12d4  81ec44050000           -sub esp, 0x544
    (cpu.esp) -= x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 004b12da  899424c4040000         -mov dword ptr [esp + 0x4c4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */) = cpu.edx;
    // 004b12e1  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 004b12e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b12ea  899424cc040000         -mov dword ptr [esp + 0x4cc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.edx;
    // 004b12f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b12f3  0f8437120000           -je 0x4b2530
    if (cpu.flags.zf)
    {
        goto L_0x004b2530;
    }
    // 004b12f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b12fb  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b12fd  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1300  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1303  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1305  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1308  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b130f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b1311  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1313  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004b131a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b131c  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1323  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b1325  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1328  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b132f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1331  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004b1334  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b133b  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1342  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1344  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1347  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b134a  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1351  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004b1354  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1357  89b424c8040000         -mov dword ptr [esp + 0x4c8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */) = cpu.esi;
    // 004b135e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1360  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b1367  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004b136e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1370  8aa424c9040000         -mov ah, byte ptr [esp + 0x4c9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 004b1377  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004b137a  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004b137d  0f85e8010000           -jne 0x4b156b
    if (!cpu.flags.zf)
    {
        goto L_0x004b156b;
    }
L_0x004b1383:
    // 004b1383  8a9424c9040000         -mov dl, byte ptr [esp + 0x4c9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 004b138a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b138c  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b138f  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004b1392  c1ed18                 -shr ebp, 0x18
    cpu.ebp >>= 24 /*0x18*/ % 32;
    // 004b1395  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b1398  889424c9040000         -mov byte ptr [esp + 0x4c9], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */) = cpu.dl;
    // 004b139f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b13a1  0f8c39020000           -jl 0x4b15e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b15e0;
    }
L_0x004b13a7:
    // 004b13a7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b13a9  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b13ac  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b13af  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004b13b2  898424cc040000         -mov dword ptr [esp + 0x4cc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.eax;
    // 004b13b9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b13bb  0f8c7d020000           -jl 0x4b163e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b163e;
    }
L_0x004b13c1:
    // 004b13c1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b13c3  8b8c24cc040000         -mov ecx, dword ptr [esp + 0x4cc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004b13ca  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b13cd  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b13cf  898c24cc040000         -mov dword ptr [esp + 0x4cc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.ecx;
    // 004b13d6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b13d8  0f85be020000           -jne 0x4b169c
    if (!cpu.flags.zf)
    {
        goto L_0x004b169c;
    }
L_0x004b13de:
    // 004b13de  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b13e5  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004b13ec  89842400050000         -mov dword ptr [esp + 0x500], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */) = cpu.eax;
L_0x004b13f3:
    // 004b13f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b13f5  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004b13f8  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 004b13fb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1400  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1402  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1404  0f8cce000000           -jl 0x4b14d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b14d8;
    }
L_0x004b140a:
    // 004b140a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b140c  8b8c2400050000         -mov ecx, dword ptr [esp + 0x500]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 004b1413  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004b1416  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1418  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004b141a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b141c  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b1423  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1425  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 004b1427  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1429  8bac24d4040000         -mov ebp, dword ptr [esp + 0x4d4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b1430  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004b1433  45                     -inc ebp
    (cpu.ebp)++;
    // 004b1434  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004b1437  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004b143e  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004b1440  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1445  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1447  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1449  0f8c89000000           -jl 0x4b14d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b14d8;
    }
    // 004b144f  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 004b1456  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1458  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b145a  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b145c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b145e  45                     -inc ebp
    (cpu.ebp)++;
    // 004b145f  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004b1462  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 004b1465  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004b1468  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004b146f  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004b1471  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1476  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1478  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b147a  7c5c                   -jl 0x4b14d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b14d8;
    }
    // 004b147c  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 004b1483  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1485  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1487  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1489  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b148b  45                     -inc ebp
    (cpu.ebp)++;
    // 004b148c  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004b148f  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 004b1492  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004b1495  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004b149c  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004b149e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b14a3  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b14a5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b14a7  7c2f                   -jl 0x4b14d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b14d8;
    }
    // 004b14a9  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 004b14b0  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004b14b2  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b14b4  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b14b6  886500                 -mov byte ptr [ebp], ah
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.ah;
    // 004b14b9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b14bb  45                     -inc ebp
    (cpu.ebp)++;
    // 004b14bc  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004b14bf  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004b14c6  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 004b14c9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b14ce  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b14d0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b14d2  0f8d32ffffff           -jge 0x4b140a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b140a;
    }
L_0x004b14d8:
    // 004b14d8  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b14db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b14dd  0f8c420b0000           -jl 0x4b2025
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2025;
    }
    // 004b14e3  8b842400050000         -mov eax, dword ptr [esp + 0x500]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 004b14ea  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 004b14ed  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b14f4  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004b14f7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004b14f9  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1500  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1502  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1504  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b150b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b150e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1510  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004b1517  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b151e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1520  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1523  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b152a  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004b152f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1532  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b1534  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1536  8b8424d4040000         -mov eax, dword ptr [esp + 0x4d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b153d  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b1544  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b154b  40                     -inc eax
    (cpu.eax)++;
    // 004b154c  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1553  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 004b155a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b155d  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b155f  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 004b1566  e988feffff             -jmp 0x4b13f3
    goto L_0x004b13f3;
L_0x004b156b:
    // 004b156b  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1572  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1574  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1577  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b1579  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b157b  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b1582  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1584  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1587  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b158a  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b158c  8d7102                 -lea esi, [ecx + 2]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004b158f  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004b1596  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1598  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b159b  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b159d  89b42430050000         -mov dword ptr [esp + 0x530], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.esi;
    // 004b15a4  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b15a6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b15a8  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b15af  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b15b2  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b15b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b15bb  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b15be  8a5601                 -mov dl, byte ptr [esi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b15c1  89bc2430050000         -mov dword ptr [esp + 0x530], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edi;
    // 004b15c8  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b15ca  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 004b15cf  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b15d1  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b15d8  c1e608                 +shl esi, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b15db  e9a3fdffff             -jmp 0x4b1383
    goto L_0x004b1383;
L_0x004b15e0:
    // 004b15e0  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b15e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b15e9  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b15eb  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b15f2  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b15f5  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b15f7  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b15fe  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b1605  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1607  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1609  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b160c  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1613  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1615  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1618  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b161b  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b161d  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1624  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b162b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b162d  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1630  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1632  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004b1639  e969fdffff             -jmp 0x4b13a7
    goto L_0x004b13a7;
L_0x004b163e:
    // 004b163e  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1645  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1647  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b1649  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1650  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1653  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1655  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b165c  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1663  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1665  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1667  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b166a  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1671  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1673  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1676  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1679  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b167b  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1682  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004b1689  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b168b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b168e  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1690  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 004b1697  e925fdffff             -jmp 0x4b13c1
    goto L_0x004b13c1;
L_0x004b169c:
    // 004b169c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b169e  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b16a1  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004b16a4  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b16a7  88842440050000         -mov byte ptr [esp + 0x540], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */) = cpu.al;
    // 004b16ae  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b16b0  0f8ce4030000           -jl 0x4b1a9a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1a9a;
    }
L_0x004b16b6:
    // 004b16b6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b16bb  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004b16c0  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b16c2  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004b16c7  89ac24e4040000         -mov dword ptr [esp + 0x4e4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebp;
    // 004b16ce  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 004b16d5  89942418050000         -mov dword ptr [esp + 0x518], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.edx;
    // 004b16dc  898c241c050000         -mov dword ptr [esp + 0x51c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ecx;
L_0x004b16e3:
    // 004b16e3  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b16e5  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004b16ec  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b16ee  8b94241c050000         -mov edx, dword ptr [esp + 0x51c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004b16f5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b16f7  89841480040000         -mov dword ptr [esp + edx + 0x480], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.edx * 1) = cpu.eax;
    // 004b16fe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b1700  0f8cf2030000           -jl 0x4b1af8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1af8;
    }
    // 004b1706  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1708  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b170b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b170d  0f84be040000           -je 0x4b1bd1
    if (cpu.flags.zf)
    {
        goto L_0x004b1bd1;
    }
    // 004b1713  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004b1718:
    // 004b1718  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b171a  40                     -inc eax
    (cpu.eax)++;
    // 004b171b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b171d  7df9                   -jge 0x4b1718
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1718;
    }
    // 004b171f  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004b1722  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1724  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1726  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1728  0f8c40040000           -jl 0x4b1b6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1b6e;
    }
L_0x004b172e:
    // 004b172e  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1735  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1738  89942410050000         -mov dword ptr [esp + 0x510], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */) = cpu.edx;
    // 004b173f  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1746  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1749  89942428050000         -mov dword ptr [esp + 0x528], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */) = cpu.edx;
    // 004b1750  83f810                 +cmp eax, 0x10
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
    // 004b1753  0f8ec5050000           -jle 0x4b1d1e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1d1e;
    }
    // 004b1759  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b175e  8d58f0                 -lea ebx, [eax - 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 004b1761  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1763  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1765  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004b1767  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004b1769  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b176b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b176d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b176f  0f8cd9040000           -jl 0x4b1c4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1c4e;
    }
L_0x004b1775:
    // 004b1775  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b1777  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b177a  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004b177d  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004b1780  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1782  0f8c1e050000           -jl 0x4b1ca6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1ca6;
    }
L_0x004b1788:
    // 004b1788  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b178b  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b178d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b1792  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b1794:
    // 004b1794  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b1796  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b1798:
    // 004b1798  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b179b  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004b17a2  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004b17a9  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b17ab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b17ad  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b17af  89940400040000         -mov dword ptr [esp + eax + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1) = cpu.edx;
    // 004b17b6  899c24e4040000         -mov dword ptr [esp + 0x4e4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebx;
    // 004b17bd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b17bf  7413                   -je 0x4b17d4
    if (cpu.flags.zf)
    {
        goto L_0x004b17d4;
    }
    // 004b17c1  8a8c2418050000         -mov cl, byte ptr [esp + 0x518]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 004b17c8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b17ca  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b17cc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b17ce  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x004b17d4:
    // 004b17d4  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004b17db  898c0440040000         -mov dword ptr [esp + eax + 0x440], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 1) = cpu.ecx;
    // 004b17e2  8b842418050000         -mov eax, dword ptr [esp + 0x518]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 004b17e9  48                     -dec eax
    (cpu.eax)--;
    // 004b17ea  8b9c241c050000         -mov ebx, dword ptr [esp + 0x51c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004b17f1  89842418050000         -mov dword ptr [esp + 0x518], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.eax;
    // 004b17f8  8b8424d8040000         -mov eax, dword ptr [esp + 0x4d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */);
    // 004b17ff  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1802  40                     -inc eax
    (cpu.eax)++;
    // 004b1803  899c241c050000         -mov dword ptr [esp + 0x51c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ebx;
    // 004b180a  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 004b1811  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1813  0f84cafeffff           -je 0x4b16e3
    if (cpu.flags.zf)
    {
        goto L_0x004b16e3;
    }
    // 004b1819  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b181b  0f85c2feffff           -jne 0x4b16e3
    if (!cpu.flags.zf)
    {
        goto L_0x004b16e3;
    }
    // 004b1821  48                     -dec eax
    (cpu.eax)--;
    // 004b1822  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004b1827  898424dc040000         -mov dword ptr [esp + 0x4dc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */) = cpu.eax;
    // 004b182e  89948440040000         -mov dword ptr [esp + eax*4 + 0x440], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 4) = cpu.edx;
    // 004b1835  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004b183a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004b183c:
    // 004b183c  83c010                 +add eax, 0x10
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
    // 004b183f  8948f0                 -mov dword ptr [eax - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 004b1842  8948f4                 -mov dword ptr [eax - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004b1845  8948f8                 -mov dword ptr [eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 004b1848  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004b184b  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b184c  75ee                   -jne 0x4b183c
    if (!cpu.flags.zf)
    {
        goto L_0x004b183c;
    }
    // 004b184e  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 004b1850  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004b1857  899424e0040000         -mov dword ptr [esp + 0x4e0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.edx;
    // 004b185e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b1860  0f8efc000000           -jle 0x4b1962
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1962;
    }
L_0x004b1866:
    // 004b1866  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b1868  0f8c30050000           -jl 0x4b1d9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1d9e;
    }
    // 004b186e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1870  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b1873  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1875  0f84f7050000           -je 0x4b1e72
    if (cpu.flags.zf)
    {
        goto L_0x004b1e72;
    }
    // 004b187b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x004b1880:
    // 004b1880  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1882  42                     -inc edx
    (cpu.edx)++;
    // 004b1883  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b1885  7df9                   -jge 0x4b1880
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1880;
    }
    // 004b1887  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b188a  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b188c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b188e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1890  0f8c7e050000           -jl 0x4b1e14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1e14;
    }
L_0x004b1896:
    // 004b1896  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b189d  8bac2434050000         -mov ebp, dword ptr [esp + 0x534]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b18a4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b18a7  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 004b18aa  898c242c050000         -mov dword ptr [esp + 0x52c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */) = cpu.ecx;
    // 004b18b1  83fa10                 +cmp edx, 0x10
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
    // 004b18b4  0f8ecf060000           -jle 0x4b1f89
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1f89;
    }
    // 004b18ba  8d4af0                 -lea ecx, [edx - 0x10]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-16) /* -0x10 */);
    // 004b18bd  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004b18c4  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b18c9  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004b18d0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b18d2  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 004b18d4  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004b18db  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b18dd  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004b18e4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b18e6  0f8c03060000           -jl 0x4b1eef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1eef;
    }
L_0x004b18ec:
    // 004b18ec  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b18ee  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b18f1  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b18f4  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004b18f7  898c24e8040000         -mov dword ptr [esp + 0x4e8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */) = cpu.ecx;
    // 004b18fe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1900  0f8c29060000           -jl 0x4b1f2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1f2f;
    }
L_0x004b1906:
    // 004b1906  8b8c24e8040000         -mov ecx, dword ptr [esp + 0x4e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */);
    // 004b190d  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004b1910  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b1912:
    // 004b1912  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004b1914  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b1919  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b191b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004b191d:
    // 004b191d  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1920  43                     -inc ebx
    (cpu.ebx)++;
    // 004b1921  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b1923:
    // 004b1923  fec0                   -inc al
    (cpu.al)++;
    // 004b1925  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1927  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b1929  3a0c14                 +cmp cl, byte ptr [esp + edx]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b192c  7501                   -jne 0x4b192f
    if (!cpu.flags.zf)
    {
        goto L_0x004b192f;
    }
    // 004b192e  4b                     -dec ebx
    (cpu.ebx)--;
L_0x004b192f:
    // 004b192f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b1931  75f0                   -jne 0x4b1923
    if (!cpu.flags.zf)
    {
        goto L_0x004b1923;
    }
    // 004b1933  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1935  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b1937  c6041401               -mov byte ptr [esp + edx], 1
    app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1) = 1 /*0x1*/;
    // 004b193b  8b9424e0040000         -mov edx, dword ptr [esp + 0x4e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */);
    // 004b1942  8b8c24e4040000         -mov ecx, dword ptr [esp + 0x4e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004b1949  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b194c  88841400030000         -mov byte ptr [esp + edx + 0x300], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.edx * 1) = cpu.al;
    // 004b1953  89ac24e0040000         -mov dword ptr [esp + 0x4e0], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.ebp;
    // 004b195a  39cd                   +cmp ebp, ecx
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
    // 004b195c  0f8c04ffffff           -jl 0x4b1866
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1866;
    }
L_0x004b1962:
    // 004b1962  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004b1967  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004b196e  bb40404040             -mov ebx, 0x40404040
    cpu.ebx = 1077952576 /*0x40404040*/;
L_0x004b1973:
    // 004b1973  83c210                 +add edx, 0x10
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
    // 004b1976  895af0                 -mov dword ptr [edx - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004b1979  895af4                 -mov dword ptr [edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004b197c  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004b197f  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004b1982  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1983  75ee                   -jne 0x4b1973
    if (!cpu.flags.zf)
    {
        goto L_0x004b1973;
    }
    // 004b1985  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004b198c  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b1993  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004b199a  898424fc040000         -mov dword ptr [esp + 0x4fc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.eax;
    // 004b19a1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b19a6  8b8c24dc040000         -mov ecx, dword ptr [esp + 0x4dc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 004b19ad  898424ec040000         -mov dword ptr [esp + 0x4ec], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.eax;
    // 004b19b4  39c1                   +cmp ecx, eax
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
    // 004b19b6  0f8c22faffff           -jl 0x4b13de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b13de;
    }
    // 004b19bc  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b19c1  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004b19c6  89842420050000         -mov dword ptr [esp + 0x520], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.eax;
    // 004b19cd  898c2424050000         -mov dword ptr [esp + 0x524], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.ecx;
L_0x004b19d4:
    // 004b19d4  8b842420050000         -mov eax, dword ptr [esp + 0x520]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 004b19db  8b840400040000         -mov eax, dword ptr [esp + eax + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1);
    // 004b19e2  8bac24ec040000         -mov ebp, dword ptr [esp + 0x4ec]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004b19e9  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 004b19f0  83fd09                 +cmp ebp, 9
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
    // 004b19f3  0f8de5f9ffff           -jge 0x4b13de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b13de;
    }
    // 004b19f9  8a8c2424050000         -mov cl, byte ptr [esp + 0x524]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 004b1a00  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004b1a05  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
L_0x004b1a07:
    // 004b1a07  8b8424f0040000         -mov eax, dword ptr [esp + 0x4f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */);
    // 004b1a0e  48                     -dec eax
    (cpu.eax)--;
    // 004b1a0f  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 004b1a16  83f8ff                 +cmp eax, -1
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
    // 004b1a19  0f84c3050000           -je 0x4b1fe2
    if (cpu.flags.zf)
    {
        goto L_0x004b1fe2;
    }
    // 004b1a1f  8b8c24fc040000         -mov ecx, dword ptr [esp + 0x4fc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */);
    // 004b1a26  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1a28  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b1a2a  41                     -inc ecx
    (cpu.ecx)++;
    // 004b1a2b  898424f4040000         -mov dword ptr [esp + 0x4f4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */) = cpu.eax;
    // 004b1a32  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004b1a39  898c24fc040000         -mov dword ptr [esp + 0x4fc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.ecx;
    // 004b1a40  898424f8040000         -mov dword ptr [esp + 0x4f8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = cpu.eax;
    // 004b1a47  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1a49  8b8c24f4040000         -mov ecx, dword ptr [esp + 0x4f4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 004b1a50  8a842440050000         -mov al, byte ptr [esp + 0x540]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 004b1a57  39c8                   +cmp eax, ecx
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
    // 004b1a59  7519                   -jne 0x4b1a74
    if (!cpu.flags.zf)
    {
        goto L_0x004b1a74;
    }
    // 004b1a5b  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004b1a62  898424d0040000         -mov dword ptr [esp + 0x4d0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */) = cpu.eax;
    // 004b1a69  c78424f804000060000000 -mov dword ptr [esp + 0x4f8], 0x60
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = 96 /*0x60*/;
L_0x004b1a74:
    // 004b1a74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1a76  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b1a78  7e8d                   -jle 0x4b1a07
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1a07;
    }
L_0x004b1a7a:
    // 004b1a7a  43                     -inc ebx
    (cpu.ebx)++;
    // 004b1a7b  8a8c24f4040000         -mov cl, byte ptr [esp + 0x4f4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 004b1a82  42                     -inc edx
    (cpu.edx)++;
    // 004b1a83  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004b1a86  8a8c24f8040000         -mov cl, byte ptr [esp + 0x4f8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1272) /* 0x4f8 */);
    // 004b1a8d  40                     -inc eax
    (cpu.eax)++;
    // 004b1a8e  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004b1a91  39e8                   +cmp eax, ebp
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
    // 004b1a93  7ce5                   -jl 0x4b1a7a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1a7a;
    }
    // 004b1a95  e96dffffff             -jmp 0x4b1a07
    goto L_0x004b1a07;
L_0x004b1a9a:
    // 004b1a9a  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1aa1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1aa3  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b1aa5  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1aac  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1ab3  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1ab6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1ab8  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1aba  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1ac1  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b1ac8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1aca  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1acc  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1acf  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1ad6  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1ad9  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1adc  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1adf  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1ae1  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 004b1ae8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b1aea  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b1af1  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1af3  e9befbffff             -jmp 0x4b16b6
    goto L_0x004b16b6;
L_0x004b1af8:
    // 004b1af8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1afa  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b1afd  c1ea1d                 -shr edx, 0x1d
    cpu.edx >>= 29 /*0x1d*/ % 32;
    // 004b1b00  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004b1b03  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1b05  0f8d8dfcffff           -jge 0x4b1798
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1798;
    }
    // 004b1b0b  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1b12  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1b14  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b1b16  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1b1d  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1b20  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1b22  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1b29  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1b30  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1b32  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1b35  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1b3c  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b1b3f  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1b41  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1b48  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1b4f  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1b56  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1b58  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1b5b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1b5d  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004b1b64  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1b67  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1b69  e92afcffff             -jmp 0x4b1798
    goto L_0x004b1798;
L_0x004b1b6e:
    // 004b1b6e  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1b75  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1b77  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1b79  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1b80  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1b83  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1b85  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1b8c  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1b93  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1b95  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b1b98  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1b9f  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1ba6  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1ba9  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1bac  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1bae  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 004b1bb5  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1bbc  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1bbe  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1bc5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1bc7  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1bca  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1bcc  e95dfbffff             -jmp 0x4b172e
    goto L_0x004b172e;
L_0x004b1bd1:
    // 004b1bd1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004b1bd6:
    // 004b1bd6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1bd8  40                     -inc eax
    (cpu.eax)++;
    // 004b1bd9  4f                     -dec edi
    (cpu.edi)--;
    // 004b1bda  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 004b1bdd  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1bdf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1be1  7c09                   -jl 0x4b1bec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1bec;
    }
    // 004b1be3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1be5  74ef                   -je 0x4b1bd6
    if (cpu.flags.zf)
    {
        goto L_0x004b1bd6;
    }
    // 004b1be7  e942fbffff             -jmp 0x4b172e
    goto L_0x004b172e;
L_0x004b1bec:
    // 004b1bec  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1bf3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1bf5  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b1bf7  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1bfe  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004b1c01  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1c03  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1c0a  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1c11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1c13  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b1c16  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1c1d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1c20  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1c22  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1c24  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b1c26  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1c28  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1c2a  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1c31  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1c38  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1c3b  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1c3e  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b1c45  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1c47  748d                   -je 0x4b1bd6
    if (cpu.flags.zf)
    {
        goto L_0x004b1bd6;
    }
    // 004b1c49  e9e0faffff             -jmp 0x4b172e
    goto L_0x004b172e;
L_0x004b1c4e:
    // 004b1c4e  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1c55  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1c57  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b1c59  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 004b1c60  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1c62  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1c69  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1c70  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1c72  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b1c75  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1c7c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1c7f  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1c81  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1c83  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b1c85  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1c87  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1c8e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1c90  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 004b1c97  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1c9a  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b1ca1  e9cffaffff             -jmp 0x4b1775
    goto L_0x004b1775;
L_0x004b1ca6:
    // 004b1ca6  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1cad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1caf  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b1cb1  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004b1cb8  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1cbf  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004b1cc6  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1cc9  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1ccb  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b1cd2  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1cd9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1cdb  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b1cde  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004b1ce5  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1cec  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004b1cf3  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1cf6  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1cf8  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1cfa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1cfc  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b1d03  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1d05  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1d0c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1d0f  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1d12  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b1d19  e96afaffff             -jmp 0x4b1788
    goto L_0x004b1788;
L_0x004b1d1e:
    // 004b1d1e  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b1d23  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1d25  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1d27  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004b1d29  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1d2b  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1d2d  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1d2f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1d31  7c0c                   -jl 0x4b1d3f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1d3f;
    }
    // 004b1d33  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1d35  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b1d3a  e955faffff             -jmp 0x4b1794
    goto L_0x004b1794;
L_0x004b1d3f:
    // 004b1d3f  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1d46  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1d48  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b1d4a  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 004b1d51  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1d53  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1d5a  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1d61  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1d63  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b1d66  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1d6d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1d70  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1d72  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1d74  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b1d76  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1d78  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1d7f  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1d81  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 004b1d88  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1d8b  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b1d92  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b1d94  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b1d99  e9f6f9ffff             -jmp 0x4b1794
    goto L_0x004b1794;
L_0x004b1d9e:
    // 004b1d9e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b1da0  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b1da3  c1eb1d                 -shr ebx, 0x1d
    cpu.ebx >>= 29 /*0x1d*/ % 32;
    // 004b1da6  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004b1da9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1dab  0f8d6cfbffff           -jge 0x4b191d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b191d;
    }
    // 004b1db1  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1db8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1dba  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1dbc  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1dc3  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1dc6  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1dc8  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1dcf  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1dd6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1dd8  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b1ddb  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1de2  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1de9  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1dec  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1def  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1df1  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004b1df8  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1dff  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1e01  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1e08  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1e0a  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1e0d  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1e0f  e909fbffff             -jmp 0x4b191d
    goto L_0x004b191d;
L_0x004b1e14:
    // 004b1e14  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1e1b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1e1d  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b1e1f  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1e26  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004b1e29  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1e2b  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1e32  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1e39  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1e3b  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b1e3e  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1e45  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1e4c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1e4f  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1e52  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1e54  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004b1e5b  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1e62  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1e64  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b1e66  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1e68  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1e6b  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1e6d  e924faffff             -jmp 0x4b1896
    goto L_0x004b1896;
L_0x004b1e72:
    // 004b1e72  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x004b1e77:
    // 004b1e77  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b1e79  42                     -inc edx
    (cpu.edx)++;
    // 004b1e7a  4f                     -dec edi
    (cpu.edi)--;
    // 004b1e7b  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 004b1e7e  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1e80  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1e82  7c09                   -jl 0x4b1e8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1e8d;
    }
    // 004b1e84  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b1e86  74ef                   -je 0x4b1e77
    if (cpu.flags.zf)
    {
        goto L_0x004b1e77;
    }
    // 004b1e88  e909faffff             -jmp 0x4b1896
    goto L_0x004b1896;
L_0x004b1e8d:
    // 004b1e8d  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1e94  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1e96  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b1e98  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1e9f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1ea2  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1ea4  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1eab  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1eb2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b1eb4  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b1eb7  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1ebe  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1ec1  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1ec3  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004b1eca  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1ecc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b1ece  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1ed5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1ed7  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1eda  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1edd  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1edf  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 004b1ee6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b1ee8  748d                   -je 0x4b1e77
    if (cpu.flags.zf)
    {
        goto L_0x004b1e77;
    }
    // 004b1eea  e9a7f9ffff             -jmp 0x4b1896
    goto L_0x004b1896;
L_0x004b1eef:
    // 004b1eef  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1ef6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1ef8  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b1efa  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b1efc  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004b1f00  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1f07  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1f0a  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1f0c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1f0e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1f10  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b1f17  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1f19  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 004b1f20  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1f23  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b1f2a  e9bdf9ffff             -jmp 0x4b18ec
    goto L_0x004b18ec;
L_0x004b1f2f:
    // 004b1f2f  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1f36  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1f3d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1f40  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004b1f43  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1f45  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1f4c  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b1f53  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1f56  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b1f5d  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1f64  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1f67  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004b1f6b  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004b1f72  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1f74  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1f76  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b1f7d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1f7f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1f82  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b1f84  e97df9ffff             -jmp 0x4b1906
    goto L_0x004b1906;
L_0x004b1f89:
    // 004b1f89  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b1f8e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b1f90  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1f92  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 004b1f94  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004b1f96  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1f98  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1f9a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b1f9c  0f8d70f9ffff           -jge 0x4b1912
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1912;
    }
    // 004b1fa2  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b1fa9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1fab  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b1fad  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b1faf  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004b1fb3  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b1fba  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b1fbd  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1fbf  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b1fc1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b1fc3  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b1fca  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b1fcc  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 004b1fd3  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1fd6  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b1fdd  e930f9ffff             -jmp 0x4b1912
    goto L_0x004b1912;
L_0x004b1fe2:
    // 004b1fe2  8bac2420050000         -mov ebp, dword ptr [esp + 0x520]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 004b1fe9  8b842424050000         -mov eax, dword ptr [esp + 0x524]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 004b1ff0  8b8c24ec040000         -mov ecx, dword ptr [esp + 0x4ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004b1ff7  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1ffa  48                     -dec eax
    (cpu.eax)--;
    // 004b1ffb  41                     -inc ecx
    (cpu.ecx)++;
    // 004b1ffc  89ac2420050000         -mov dword ptr [esp + 0x520], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.ebp;
    // 004b2003  89842424050000         -mov dword ptr [esp + 0x524], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.eax;
    // 004b200a  8bac24dc040000         -mov ebp, dword ptr [esp + 0x4dc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 004b2011  898c24ec040000         -mov dword ptr [esp + 0x4ec], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.ecx;
    // 004b2018  39e9                   +cmp ecx, ebp
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
    // 004b201a  0f8eb4f9ffff           -jle 0x4b19d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b19d4;
    }
    // 004b2020  e9b9f3ffff             -jmp 0x4b13de
    goto L_0x004b13de;
L_0x004b2025:
    // 004b2025  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2028  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b202a  83f860                 +cmp eax, 0x60
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b202d  7468                   -je 0x4b2097
    if (cpu.flags.zf)
    {
        goto L_0x004b2097;
    }
    // 004b202f  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004b2034  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2036  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b203b  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
L_0x004b203e:
    // 004b203e  8bac0c44040000         -mov ebp, dword ptr [esp + ecx + 0x444]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1092) /* 0x444 */ + cpu.ecx * 1);
    // 004b2045  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2048  40                     -inc eax
    (cpu.eax)++;
    // 004b2049  39ea                   +cmp edx, ebp
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
    // 004b204b  73f1                   -jae 0x4b203e
    if (!cpu.flags.cf)
    {
        goto L_0x004b203e;
    }
L_0x004b204d:
    // 004b204d  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b2052  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2054  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2056  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004b2058  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b205a  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b205c  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b205e  8b8c8480040000         -mov ecx, dword ptr [esp + eax*4 + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.eax * 4);
    // 004b2065  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2067  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2069  8a942440050000         -mov dl, byte ptr [esp + 0x540]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 004b2070  8a840400030000         -mov al, byte ptr [esp + eax + 0x300]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.eax * 1);
    // 004b2077  38d0                   +cmp al, dl
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
    // 004b2079  7425                   -je 0x4b20a0
    if (cpu.flags.zf)
    {
        goto L_0x004b20a0;
    }
    // 004b207b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b207d  7c21                   -jl 0x4b20a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b20a0;
    }
    // 004b207f  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b2086  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004b2088  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b208b  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 004b2092  e95cf3ffff             -jmp 0x4b13f3
    goto L_0x004b13f3;
L_0x004b2097:
    // 004b2097  8b8424d0040000         -mov eax, dword ptr [esp + 0x4d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */);
    // 004b209e  ebad                   -jmp 0x4b204d
    goto L_0x004b204d;
L_0x004b20a0:
    // 004b20a0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b20a2  7c21                   -jl 0x4b20c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b20c5;
    }
L_0x004b20a4:
    // 004b20a4  3a842440050000         +cmp al, byte ptr [esp + 0x540]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b20ab  747b                   -je 0x4b2128
    if (cpu.flags.zf)
    {
        goto L_0x004b2128;
    }
    // 004b20ad  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b20b4  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b20b7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004b20b9  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004b20c0  e92ef3ffff             -jmp 0x4b13f3
    goto L_0x004b13f3;
L_0x004b20c5:
    // 004b20c5  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b20cc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b20ce  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b20d0  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b20d7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b20da  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b20dc  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b20e3  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b20ea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b20ec  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b20ef  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b20f6  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b20fd  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b2100  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b2103  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2105  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004b210c  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b2113  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b2115  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b211c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b211e  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2121  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b2123  e97cffffff             -jmp 0x4b20a4
    goto L_0x004b20a4;
L_0x004b2128:
    // 004b2128  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b212f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b2131  0f8cf7000000           -jl 0x4b222e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b222e;
    }
    // 004b2137  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2139  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b213c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b213e  0f84c9010000           -je 0x4b230d
    if (cpu.flags.zf)
    {
        goto L_0x004b230d;
    }
    // 004b2144  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004b2149:
    // 004b2149  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b214b  40                     -inc eax
    (cpu.eax)++;
    // 004b214c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b214e  7df9                   -jge 0x4b2149
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b2149;
    }
    // 004b2150  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004b2153  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2155  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b2157  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b2159  0f8c5a010000           -jl 0x4b22b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b22b9;
    }
L_0x004b215f:
    // 004b215f  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b2166  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b2169  898c2414050000         -mov dword ptr [esp + 0x514], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */) = cpu.ecx;
    // 004b2170  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2177  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b217a  898c24c0040000         -mov dword ptr [esp + 0x4c0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */) = cpu.ecx;
    // 004b2181  83f810                 +cmp eax, 0x10
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
    // 004b2184  0f8ec6020000           -jle 0x4b2450
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2450;
    }
    // 004b218a  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 004b218d  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004b2194  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b2199  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004b21a0  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b21a2  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 004b21a4  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004b21ab  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b21ad  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004b21b4  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 004b21bb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b21bd  0f8cd6010000           -jl 0x4b2399
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2399;
    }
L_0x004b21c3:
    // 004b21c3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b21c5  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b21c8  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b21cb  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004b21ce  898c2408050000         -mov dword ptr [esp + 0x508], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */) = cpu.ecx;
    // 004b21d5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b21d7  0f8c11020000           -jl 0x4b23ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b23ee;
    }
L_0x004b21dd:
    // 004b21dd  8b8c2404050000         -mov ecx, dword ptr [esp + 0x504]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 004b21e4  8bac2408050000         -mov ebp, dword ptr [esp + 0x508]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */);
    // 004b21eb  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004b21ee  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b21f0  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b21f2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b21f7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b21f9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b21fb:
    // 004b21fb  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b21fe  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
L_0x004b2205:
    // 004b2205  8bac2404050000         -mov ebp, dword ptr [esp + 0x504]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 004b220c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b220e  0f84c7020000           -je 0x4b24db
    if (cpu.flags.zf)
    {
        goto L_0x004b24db;
    }
    // 004b2214  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b2217  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x004b221a:
    // 004b221a  42                     -inc edx
    (cpu.edx)++;
    // 004b221b  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004b221e  39c2                   +cmp edx, eax
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
    // 004b2220  72f8                   -jb 0x4b221a
    if (cpu.flags.cf)
    {
        goto L_0x004b221a;
    }
    // 004b2222  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 004b2229  e9c5f1ffff             -jmp 0x4b13f3
    goto L_0x004b13f3;
L_0x004b222e:
    // 004b222e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2230  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2233  c1e81d                 -shr eax, 0x1d
    cpu.eax >>= 29 /*0x1d*/ % 32;
    // 004b2236  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004b2239  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
    // 004b2240  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b2242  7c0a                   -jl 0x4b224e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b224e;
    }
    // 004b2244  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b224c  ebb7                   -jmp 0x4b2205
    goto L_0x004b2205;
L_0x004b224e:
    // 004b224e  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2255  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2257  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b2259  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b2260  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b2263  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2265  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004b226c  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2273  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2275  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b2278  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b227f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b2282  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2284  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b228b  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2292  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b2299  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b229b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b229e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b22a0  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004b22a7  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b22aa  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b22ac  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b22b4  e94cffffff             -jmp 0x4b2205
    goto L_0x004b2205;
L_0x004b22b9:
    // 004b22b9  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b22c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b22c2  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b22c4  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b22cb  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b22d2  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b22d5  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b22d8  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004b22da  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b22e1  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b22e8  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b22eb  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004b22ef  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004b22f6  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b22f8  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b22fa  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b2301  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2303  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2306  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b2308  e952feffff             -jmp 0x4b215f
    goto L_0x004b215f;
L_0x004b230d:
    // 004b230d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004b2312  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b2314:
    // 004b2314  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b2316  40                     -inc eax
    (cpu.eax)++;
    // 004b2317  4f                     -dec edi
    (cpu.edi)--;
    // 004b2318  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 004b231b  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b231d  898c2438050000         -mov dword ptr [esp + 0x538], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */) = cpu.ecx;
    // 004b2324  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b2326  7c0e                   -jl 0x4b2336
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2336;
    }
    // 004b2328  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b232f  74e3                   -je 0x4b2314
    if (cpu.flags.zf)
    {
        goto L_0x004b2314;
    }
    // 004b2331  e929feffff             -jmp 0x4b215f
    goto L_0x004b215f;
L_0x004b2336:
    // 004b2336  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b233d  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2344  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b2347  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004b234a  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b234c  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b2353  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b235a  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2361  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b2364  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004b2368  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b236a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b236c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b236e  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b2375  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b2377  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b237e  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b2381  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2384  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b238b  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2392  7480                   -je 0x4b2314
    if (cpu.flags.zf)
    {
        goto L_0x004b2314;
    }
    // 004b2394  e9c6fdffff             -jmp 0x4b215f
    goto L_0x004b215f;
L_0x004b2399:
    // 004b2399  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b23a0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b23a2  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b23a4  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 004b23ab  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b23ad  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b23b4  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b23bb  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b23c2  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b23c5  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004b23c9  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b23cb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b23cd  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b23cf  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b23d6  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b23d8  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 004b23df  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b23e2  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b23e9  e9d5fdffff             -jmp 0x4b21c3
    goto L_0x004b21c3;
L_0x004b23ee:
    // 004b23ee  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b23f5  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b23fc  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b23ff  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004b2402  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2404  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b240b  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2412  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2414  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b2417  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b241e  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2425  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b2428  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b242b  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004b242d  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004b2434  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b243b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b243d  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b2444  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2446  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2449  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b244b  e98dfdffff             -jmp 0x4b21dd
    goto L_0x004b21dd;
L_0x004b2450:
    // 004b2450  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004b2455  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b2457  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2459  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b245b  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 004b245d  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b245f  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 004b2466  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b2468  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b246a  7c15                   -jl 0x4b2481
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2481;
    }
L_0x004b246c:
    // 004b246c  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b246e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b2473  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b2475  03842404050000         +add eax, dword ptr [esp + 0x504]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b247c  e97afdffff             -jmp 0x4b21fb
    goto L_0x004b21fb;
L_0x004b2481:
    // 004b2481  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2488  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b248a  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b248c  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 004b2493  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2495  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004b249c  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b24a3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b24a5  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b24a8  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b24af  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b24b2  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004b24b4  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004b24bb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b24bd  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b24c4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b24c6  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004b24c8  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 004b24cf  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b24d2  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004b24d9  eb91                   -jmp 0x4b246c
    goto L_0x004b246c;
L_0x004b24db:
    // 004b24db  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b24dd  4f                     -dec edi
    (cpu.edi)--;
    // 004b24de  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 004b24e1  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b24e3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b24e5  7c5b                   -jl 0x4b2542
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2542;
    }
L_0x004b24e7:
    // 004b24e7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b24e9  0f84b1000000           -je 0x4b25a0
    if (cpu.flags.zf)
    {
        goto L_0x004b25a0;
    }
    // 004b24ef  8bbc24c4040000         -mov edi, dword ptr [esp + 0x4c4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 004b24f6  8b9c24cc040000         -mov ebx, dword ptr [esp + 0x4cc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004b24fd  8bb424c8040000         -mov esi, dword ptr [esp + 0x4c8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */);
    // 004b2504  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2506  81fefb320000           +cmp esi, 0x32fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13051 /*0x32fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b250c  0f851e010000           -jne 0x4b2630
    if (!cpu.flags.zf)
    {
        goto L_0x004b2630;
    }
    // 004b2512  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 004b2519  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b251b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b251d  39c7                   +cmp edi, eax
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
    // 004b251f  760f                   -jbe 0x4b2530
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2530;
    }
L_0x004b2521:
    // 004b2521  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2523  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2525  40                     -inc eax
    (cpu.eax)++;
    // 004b2526  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2528  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004b252b  39d8                   +cmp eax, ebx
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
    // 004b252d  72f2                   -jb 0x4b2521
    if (cpu.flags.cf)
    {
        goto L_0x004b2521;
    }
    // 004b252f  90                     -nop 
    ;
L_0x004b2530:
    // 004b2530  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004b2537  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 004b253d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b253e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b253f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2540  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2541  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2542:
    // 004b2542  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2549  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b254b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b254d  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b2554  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b2557  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2559  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2560  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b2567  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2569  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b256b  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b256e  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b2575  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2577  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b257a  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b257d  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b257f  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b2586  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b258d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b258f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b2592  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b2594  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004b259b  e947ffffff             -jmp 0x4b24e7
    goto L_0x004b24e7;
L_0x004b25a0:
    // 004b25a0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b25a2  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b25a5  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004b25a8  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b25ab  8884243c050000         -mov byte ptr [esp + 0x53c], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */) = cpu.al;
    // 004b25b2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b25b4  7c1f                   -jl 0x4b25d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b25d5;
    }
L_0x004b25b6:
    // 004b25b6  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004b25bd  8a84243c050000         -mov al, byte ptr [esp + 0x53c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */);
    // 004b25c4  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b25c7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004b25c9  898c24d4040000         -mov dword ptr [esp + 0x4d4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ecx;
    // 004b25d0  e91eeeffff             -jmp 0x4b13f3
    goto L_0x004b13f3;
L_0x004b25d5:
    // 004b25d5  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b25dc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b25de  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b25e0  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b25e7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b25ea  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b25ec  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b25f3  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b25fa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b25fc  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b25ff  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004b2606  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b2609  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b260b  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b260d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b260f  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004b2616  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b2618  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004b261f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2622  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b2625  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b2627  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 004b262e  eb86                   -jmp 0x4b25b6
    goto L_0x004b25b6;
L_0x004b2630:
    // 004b2630  81fefb340000           +cmp esi, 0x34fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13563 /*0x34fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2636  0f85f4feffff           -jne 0x4b2530
    if (!cpu.flags.zf)
    {
        goto L_0x004b2530;
    }
    // 004b263c  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 004b2643  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004b2645  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2647  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2649  39c7                   +cmp edi, eax
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
    // 004b264b  0f86dffeffff           -jbe 0x4b2530
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2530;
    }
L_0x004b2651:
    // 004b2651  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2653  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2655  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2657  40                     -inc eax
    (cpu.eax)++;
    // 004b2658  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b265a  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004b265d  39f0                   +cmp eax, esi
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
    // 004b265f  72f0                   -jb 0x4b2651
    if (cpu.flags.cf)
    {
        goto L_0x004b2651;
    }
    // 004b2661  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004b2668  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 004b266e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b266f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2670  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2671  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2672  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b2690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004b2690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2691  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2692  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2693  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2694  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2695  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b2698  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b269a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004b269c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004b26a1  88642410               -mov byte ptr [esp + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 004b26a5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b26a7  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b26ab  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b26ad  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004b26af  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b26b1  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004b26b8  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b26ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b26bc  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004b26bf  81fa314b0000           +cmp edx, 0x4b31
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19249 /*0x4b31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b26c5  0f8498000000           -je 0x4b2763
    if (cpu.flags.zf)
    {
        goto L_0x004b2763;
    }
    // 004b26cb  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004b26d0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b26d2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004b26d4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b26d6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004b26dd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b26df  83c505                 -add ebp, 5
    (cpu.ebp) += x86::reg32(x86::sreg32(5 /*0x5*/));
L_0x004b26e2:
    // 004b26e2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b26e6  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004b26e9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b26ed  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b26f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b26f3  7e61                   -jle 0x4b2756
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2756;
    }
L_0x004b26f5:
    // 004b26f5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b26f8  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004b26fa  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004b26fc  80e43f                 -and ah, 0x3f
    cpu.ah &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004b26ff  0fb6ec                 -movzx ebp, ah
    cpu.ebp = x86::reg32(cpu.ah);
    // 004b2702  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2705  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b270a  43                     -inc ebx
    (cpu.ebx)++;
    // 004b270b  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004b270e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b2711  83f803                 +cmp eax, 3
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
    // 004b2714  7739                   -ja 0x4b274f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b274f;
    }
    // 004b2716  ff248580264b00         -jmp dword ptr [eax*4 + 0x4b2680]
    cpu.ip = app->getMemory<x86::reg32>(4925056 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b271d:
    // 004b271d  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2721  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b2723  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b2725  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2729  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b272a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b272c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b272f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2731  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b2733  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b2736  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2738  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2739  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b273d  8d3c2b                 -lea edi, [ebx + ebp]
    cpu.edi = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 004b2740  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b2742  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004b2745  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b2747  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b274b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004b274f:
    // 004b274f  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b2754  7f9f                   -jg 0x4b26f5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b26f5;
    }
L_0x004b2756:
    // 004b2756  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b275a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b275d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b275e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b275f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2760  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2761  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2762  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2763:
    // 004b2763  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004b2768  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b276a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004b276c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b276e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004b2775  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004b2777  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b277a  e963ffffff             -jmp 0x4b26e2
    goto L_0x004b26e2;
  case 0x004b277f:
    // 004b277f  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b2781  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2784  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 004b2788  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
  [[fallthrough]];
  case 0x004b278b:
    // 004b278b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b278f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2791  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b2793  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b2797  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b279b  e88ffefdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004b27a0  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b27a4  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b27a6  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b27a8  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004b27ac  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b27b0  eb9d                   -jmp 0x4b274f
    goto L_0x004b274f;
  case 0x004b27b2:
    // 004b27b2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b27b6  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b27b9  8a23                   -mov ah, byte ptr [ebx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b27bb  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004b27be  8d7a01                 -lea edi, [edx + 1]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b27c1  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 004b27c3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b27c7  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004b27ca  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004b27ce  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b27d0  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b27d1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b27d5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b27d7  0f8e72ffffff           -jle 0x4b274f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b274f;
    }
L_0x004b27dd:
    // 004b27dd  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b27e0  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b27e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b27e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b27e6  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b27e8  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004b27ea  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004b27ed  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b27ef  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b27f3  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b27f7  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b27f8  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004b27fa  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b27fd  43                     -inc ebx
    (cpu.ebx)++;
    // 004b27fe  41                     -inc ecx
    (cpu.ecx)++;
    // 004b27ff  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b2803  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b2806  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b2808  7e0e                   -jle 0x4b2818
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2818;
    }
    // 004b280a  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b280c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b280f  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b2810  08e0                   -or al, ah
    cpu.al |= x86::reg8(x86::sreg8(cpu.ah));
    // 004b2812  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004b2816  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
L_0x004b2818:
    // 004b2818  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b281a  7fc1                   -jg 0x4b27dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b27dd;
    }
    // 004b281c  e92effffff             -jmp 0x4b274f
    goto L_0x004b274f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b2824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2824  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2825  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b2827  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b282a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b282b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b282c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b282d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b282f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2831  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b2833  c745fc00000000         -mov dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 0 /*0x0*/;
    // 004b283a  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b283c  0f84d8000000           -je 0x4b291a
    if (cpu.flags.zf)
    {
        return sub_4b291a(app, cpu);
    }
    // 004b2842  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004b2845  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b2848  2401                   +and al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004b284a  7403                   -je 0x4b284f
    if (cpu.flags.zf)
    {
        goto L_0x004b284f;
    }
    // 004b284c  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
L_0x004b284f:
    // 004b284f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2851  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b2853  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b2856  8a6301                 -mov ah, byte ptr [ebx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2859  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b285c  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004b285f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b2862  83f900                 +cmp ecx, 0
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
    // 004b2865  0f84af000000           -je 0x4b291a
    if (cpu.flags.zf)
    {
        return sub_4b291a(app, cpu);
    }
    // 004b286b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b286d  eb46                   -jmp 0x4b28b5
    return sub_4b28b5(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4b2870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004b2870:
    // 004b2870  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b2873  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2875  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2877  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b2879  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b287b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b287e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b2881  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b2884  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2886  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b288a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b288d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b288f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b2891  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2893  7826                   -js 0x4b28bb
    if (cpu.flags.sf)
    {
        goto L_0x004b28bb;
    }
L_0x004b2895:
    // 004b2895  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004b2898  75d6                   -jne 0x4b2870
    if (!cpu.flags.zf)
    {
        goto L_0x004b2870;
    }
    // 004b289a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b289d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b289f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28a1  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b28a4  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b28a7  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b28aa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28ac  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28b0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b28b3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28b5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28b7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28b9  79da                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
L_0x004b28bb:
    // 004b28bb  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28bd  7831                   -js 0x4b28f0
    if (cpu.flags.sf)
    {
        goto L_0x004b28f0;
    }
    // 004b28bf  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28c1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004b28c4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004b28c7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b28ca  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28cc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b28ce  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b28d0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b28d3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004b28d5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004b28d8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28da  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28de  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004b28e1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b28e4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28e6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28e8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28ea  79a9                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b28ec  ebcd                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b28ee  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b28f0:
    // 004b28f0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28f2  7930                   -jns 0x4b2924
    if (!cpu.flags.sf)
    {
        goto L_0x004b2924;
    }
    // 004b28f4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b28f7  7317                   -jae 0x4b2910
    if (!cpu.flags.cf)
    {
        goto L_0x004b2910;
    }
    // 004b28f9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004b28fc  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b28ff  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2902  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2904  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2906  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004b2908  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b290a  7989                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b290c  ebad                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b290e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b2910:
    // 004b2910  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2912  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2915  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2918  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b291a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b291d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2920  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b2922  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2923  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2924:
    // 004b2924  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2926  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2929  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b292c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b292e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2930  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2932  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2934  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2937  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004b293a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004b293d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004b293f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004b2941  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2943  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b2947  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004b294a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004b294d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004b2953  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2956  7d24                   -jge 0x4b297c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4b297c(app, cpu);
    }
    // 004b2958  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b2961  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2964  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2966  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2968  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b296a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b296c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b296e  0f8921ffffff           -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b2974  e942ffffff             -jmp 0x4b28bb
    goto L_0x004b28bb;
}

/* align: skip  */
void Application::sub_4b291a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b291a;
L_0x004b2870:
    // 004b2870  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b2873  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2875  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2877  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b2879  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b287b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b287e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b2881  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b2884  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2886  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b288a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b288d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b288f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b2891  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2893  7826                   -js 0x4b28bb
    if (cpu.flags.sf)
    {
        goto L_0x004b28bb;
    }
L_0x004b2895:
    // 004b2895  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004b2898  75d6                   -jne 0x4b2870
    if (!cpu.flags.zf)
    {
        goto L_0x004b2870;
    }
    // 004b289a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b289d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b289f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28a1  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b28a4  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b28a7  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b28aa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28ac  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28b0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b28b3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28b5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28b7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28b9  79da                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
L_0x004b28bb:
    // 004b28bb  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28bd  7831                   -js 0x4b28f0
    if (cpu.flags.sf)
    {
        goto L_0x004b28f0;
    }
    // 004b28bf  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28c1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004b28c4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004b28c7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b28ca  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28cc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b28ce  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b28d0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b28d3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004b28d5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004b28d8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28da  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28de  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004b28e1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b28e4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28e6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28e8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28ea  79a9                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b28ec  ebcd                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b28ee  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b28f0:
    // 004b28f0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28f2  7930                   -jns 0x4b2924
    if (!cpu.flags.sf)
    {
        goto L_0x004b2924;
    }
    // 004b28f4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b28f7  7317                   -jae 0x4b2910
    if (!cpu.flags.cf)
    {
        goto L_0x004b2910;
    }
    // 004b28f9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004b28fc  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b28ff  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2902  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2904  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2906  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004b2908  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b290a  7989                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b290c  ebad                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b290e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b2910:
    // 004b2910  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2912  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2915  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2918  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
L_entry_0x004b291a:
    // 004b291a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b291d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2920  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b2922  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2923  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2924:
    // 004b2924  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2926  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2929  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b292c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b292e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2930  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2932  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2934  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2937  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004b293a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004b293d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004b293f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004b2941  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2943  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b2947  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004b294a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004b294d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004b2953  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2956  7d24                   -jge 0x4b297c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4b297c(app, cpu);
    }
    // 004b2958  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b2961  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2964  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2966  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2968  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b296a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b296c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b296e  0f8921ffffff           -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b2974  e942ffffff             -jmp 0x4b28bb
    goto L_0x004b28bb;
}

/* align: skip  */
void Application::sub_4b28bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b28bb;
L_0x004b2870:
    // 004b2870  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b2873  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2875  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2877  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b2879  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b287b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b287e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b2881  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b2884  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2886  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b288a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b288d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b288f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b2891  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2893  7826                   -js 0x4b28bb
    if (cpu.flags.sf)
    {
        goto L_0x004b28bb;
    }
L_0x004b2895:
    // 004b2895  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004b2898  75d6                   -jne 0x4b2870
    if (!cpu.flags.zf)
    {
        goto L_0x004b2870;
    }
    // 004b289a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b289d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b289f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28a1  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b28a4  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b28a7  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b28aa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28ac  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28b0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b28b3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28b5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28b7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28b9  79da                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
L_0x004b28bb:
L_entry_0x004b28bb:
    // 004b28bb  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28bd  7831                   -js 0x4b28f0
    if (cpu.flags.sf)
    {
        goto L_0x004b28f0;
    }
    // 004b28bf  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28c1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004b28c4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004b28c7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b28ca  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28cc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b28ce  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b28d0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b28d3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004b28d5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004b28d8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28da  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28de  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004b28e1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b28e4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28e6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28e8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28ea  79a9                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b28ec  ebcd                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b28ee  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b28f0:
    // 004b28f0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28f2  7930                   -jns 0x4b2924
    if (!cpu.flags.sf)
    {
        goto L_0x004b2924;
    }
    // 004b28f4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b28f7  7317                   -jae 0x4b2910
    if (!cpu.flags.cf)
    {
        goto L_0x004b2910;
    }
    // 004b28f9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004b28fc  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b28ff  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2902  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2904  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2906  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004b2908  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b290a  7989                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b290c  ebad                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b290e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b2910:
    // 004b2910  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2912  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2915  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2918  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b291a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b291d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2920  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b2922  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2923  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2924:
    // 004b2924  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2926  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2929  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b292c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b292e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2930  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2932  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2934  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2937  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004b293a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004b293d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004b293f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004b2941  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2943  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b2947  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004b294a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004b294d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004b2953  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2956  7d24                   -jge 0x4b297c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4b297c(app, cpu);
    }
    // 004b2958  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b2961  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2964  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2966  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2968  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b296a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b296c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b296e  0f8921ffffff           -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b2974  e942ffffff             -jmp 0x4b28bb
    goto L_0x004b28bb;
}

/* align: skip  */
void Application::sub_4b28b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b28b5;
L_0x004b2870:
    // 004b2870  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b2873  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2875  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2877  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b2879  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b287b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b287e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b2881  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b2884  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2886  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b288a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b288d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b288f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b2891  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2893  7826                   -js 0x4b28bb
    if (cpu.flags.sf)
    {
        goto L_0x004b28bb;
    }
L_0x004b2895:
    // 004b2895  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004b2898  75d6                   -jne 0x4b2870
    if (!cpu.flags.zf)
    {
        goto L_0x004b2870;
    }
    // 004b289a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b289d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b289f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28a1  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b28a4  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b28a7  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b28aa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28ac  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28b0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b28b3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
L_entry_0x004b28b5:
    // 004b28b5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28b7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28b9  79da                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
L_0x004b28bb:
    // 004b28bb  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28bd  7831                   -js 0x4b28f0
    if (cpu.flags.sf)
    {
        goto L_0x004b28f0;
    }
    // 004b28bf  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28c1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004b28c4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004b28c7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b28ca  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28cc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b28ce  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b28d0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b28d3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004b28d5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004b28d8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28da  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28de  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004b28e1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b28e4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28e6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28e8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28ea  79a9                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b28ec  ebcd                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b28ee  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b28f0:
    // 004b28f0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28f2  7930                   -jns 0x4b2924
    if (!cpu.flags.sf)
    {
        goto L_0x004b2924;
    }
    // 004b28f4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b28f7  7317                   -jae 0x4b2910
    if (!cpu.flags.cf)
    {
        goto L_0x004b2910;
    }
    // 004b28f9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004b28fc  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b28ff  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2902  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2904  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2906  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004b2908  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b290a  7989                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b290c  ebad                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b290e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b2910:
    // 004b2910  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2912  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2915  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2918  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b291a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b291d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2920  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b2922  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2923  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2924:
    // 004b2924  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2926  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2929  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b292c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b292e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2930  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2932  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2934  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2937  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004b293a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004b293d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004b293f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004b2941  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2943  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b2947  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004b294a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004b294d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004b2953  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2956  7d24                   -jge 0x4b297c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4b297c(app, cpu);
    }
    // 004b2958  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b2961  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2964  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2966  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2968  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b296a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b296c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b296e  0f8921ffffff           -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b2974  e942ffffff             -jmp 0x4b28bb
    goto L_0x004b28bb;
}

/* align: skip  */
void Application::sub_4b2895(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b2895;
L_0x004b2870:
    // 004b2870  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b2873  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2875  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2877  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b2879  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b287b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b287e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b2881  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b2884  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2886  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b288a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b288d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b288f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b2891  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2893  7826                   -js 0x4b28bb
    if (cpu.flags.sf)
    {
        goto L_0x004b28bb;
    }
L_0x004b2895:
L_entry_0x004b2895:
    // 004b2895  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004b2898  75d6                   -jne 0x4b2870
    if (!cpu.flags.zf)
    {
        goto L_0x004b2870;
    }
    // 004b289a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004b289d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004b289f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28a1  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b28a4  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004b28a7  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b28aa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28ac  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28b0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004b28b3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28b5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28b7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28b9  79da                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
L_0x004b28bb:
    // 004b28bb  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28bd  7831                   -js 0x4b28f0
    if (cpu.flags.sf)
    {
        goto L_0x004b28f0;
    }
    // 004b28bf  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004b28c1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004b28c4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004b28c7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b28ca  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28cc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b28ce  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b28d0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b28d3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004b28d5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004b28d8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b28da  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b28de  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004b28e1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b28e4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b28e6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b28e8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b28ea  79a9                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b28ec  ebcd                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b28ee  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b28f0:
    // 004b28f0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b28f2  7930                   -jns 0x4b2924
    if (!cpu.flags.sf)
    {
        goto L_0x004b2924;
    }
    // 004b28f4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b28f7  7317                   -jae 0x4b2910
    if (!cpu.flags.cf)
    {
        goto L_0x004b2910;
    }
    // 004b28f9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004b28fc  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b28ff  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2902  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2904  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2906  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004b2908  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b290a  7989                   -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b290c  ebad                   -jmp 0x4b28bb
    goto L_0x004b28bb;
    // 004b290e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004b2910:
    // 004b2910  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2912  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2915  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2918  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b291a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b291d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b291f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2920  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b2922  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2923  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2924:
    // 004b2924  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2926  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2929  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b292c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b292e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b2930  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2932  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2934  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2937  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004b293a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004b293d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004b293f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004b2941  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b2943  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004b2947  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004b294a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004b294d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004b2953  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2956  7d24                   -jge 0x4b297c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4b297c(app, cpu);
    }
    // 004b2958  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b295e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b2961  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2964  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2966  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2968  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b296a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b296c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b296e  0f8921ffffff           -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        goto L_0x004b2895;
    }
    // 004b2974  e942ffffff             -jmp 0x4b28bb
    goto L_0x004b28bb;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b297c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b297c  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004b297f  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2981  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004b2983  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2985  0f890affffff           -jns 0x4b2895
    if (!cpu.flags.sf)
    {
        return sub_4b2895(app, cpu);
    }
    // 004b298b  e92bffffff             -jmp 0x4b28bb
    return sub_4b28bb(app, cpu);
}

/* align: skip  */
void Application::sub_4b2990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2991  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004b2992:
    // 004b2992  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2994  8b0d50945b00           -mov ecx, dword ptr [0x5b9450]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6001744) /* 0x5b9450 */);
    // 004b299a  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b299c  803c1100               +cmp byte ptr [ecx + edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b29a0  7513                   -jne 0x4b29b5
    if (!cpu.flags.zf)
    {
        goto L_0x004b29b5;
    }
    // 004b29a2  8b1540945b00           -mov edx, dword ptr [0x5b9440]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001728) /* 0x5b9440 */);
    // 004b29a8  42                     -inc edx
    (cpu.edx)++;
    // 004b29a9  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004b29ac  891540945b00           -mov dword ptr [0x5b9440], edx
    app->getMemory<x86::reg32>(x86::reg32(6001728) /* 0x5b9440 */) = cpu.edx;
    // 004b29b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b29b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b29b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b29b5:
    // 004b29b5  a144945b00             -mov eax, dword ptr [0x5b9444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001732) /* 0x5b9444 */);
    // 004b29ba  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004b29bd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b29c2  e8c9ffffff             -call 0x4b2990
    cpu.esp -= 4;
    sub_4b2990(app, cpu);
    if (cpu.terminate) return;
    // 004b29c7  a14c945b00             -mov eax, dword ptr [0x5b944c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001740) /* 0x5b944c */);
    // 004b29cc  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004b29cf  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b29d4  ebbc                   -jmp 0x4b2992
    goto L_0x004b2992;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b29d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b29d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b29d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b29da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b29db  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004b29e1  891540945b00           -mov dword ptr [0x5b9440], edx
    app->getMemory<x86::reg32>(x86::reg32(6001728) /* 0x5b9440 */) = cpu.edx;
    // 004b29e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b29e9  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 004b29f0  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004b29f7  891550945b00           -mov dword ptr [0x5b9450], edx
    app->getMemory<x86::reg32>(x86::reg32(6001744) /* 0x5b9450 */) = cpu.edx;
    // 004b29fd  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b29ff  891544945b00           -mov dword ptr [0x5b9444], edx
    app->getMemory<x86::reg32>(x86::reg32(6001732) /* 0x5b9444 */) = cpu.edx;
    // 004b2a05  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b2a0c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2a0e  89154c945b00           -mov dword ptr [0x5b944c], edx
    app->getMemory<x86::reg32>(x86::reg32(6001740) /* 0x5b944c */) = cpu.edx;
    // 004b2a14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2a16  0f8445010000           -je 0x4b2b61
    if (cpu.flags.zf)
    {
        goto L_0x004b2b61;
    }
    // 004b2a1c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a1e  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b2a21  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2a23  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a25  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b2a28  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b2a2a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a2c  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2a2d  81fafb470000           +cmp edx, 0x47fb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18427 /*0x47fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2a33  0f84d0000000           -je 0x4b2b09
    if (cpu.flags.zf)
    {
        goto L_0x004b2b09;
    }
L_0x004b2a39:
    // 004b2a39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a3d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b2a3f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b2a42  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004b2a49  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b2a4c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a4e  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004b2a55  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2a56  8b942400030000         -mov edx, dword ptr [esp + 0x300]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004b2a5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a5f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b2a62  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b2a65  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2a66  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a68  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2a69  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 004b2a70  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b2a72:
    // 004b2a72  a150945b00             -mov eax, dword ptr [0x5b9450]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001744) /* 0x5b9450 */);
    // 004b2a77  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004b2a7a  42                     -inc edx
    (cpu.edx)++;
    // 004b2a7b  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004b2a7e  81fa00010000           +cmp edx, 0x100
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
    // 004b2a84  7cec                   -jl 0x4b2a72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2a72;
    }
    // 004b2a86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2a87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2a88  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2a89  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a8b  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004b2a8e  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2a8f  c6040201               -mov byte ptr [edx + eax], 1
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 1 /*0x1*/;
    // 004b2a93  0fb669ff               -movzx ebp, byte ptr [ecx - 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */));
    // 004b2a97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a99  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b2a9b  7e37                   -jle 0x4b2ad4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2ad4;
    }
L_0x004b2a9d:
    // 004b2a9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a9f  8b1d44945b00           -mov ebx, dword ptr [0x5b9444]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6001732) /* 0x5b9444 */);
    // 004b2aa5  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b2aa7  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b2aaa  8d3c13                 -lea edi, [ebx + edx]
    cpu.edi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004b2aad  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b2ab0  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2ab2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b2ab4  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004b2ab6  8b3d4c945b00           -mov edi, dword ptr [0x5b944c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6001740) /* 0x5b944c */);
    // 004b2abc  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2abe  881c3a                 -mov byte ptr [edx + edi], bl
    app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1) = cpu.bl;
    // 004b2ac1  8b1d50945b00           -mov ebx, dword ptr [0x5b9450]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6001744) /* 0x5b9450 */);
    // 004b2ac7  40                     -inc eax
    (cpu.eax)++;
    // 004b2ac8  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2ac9  c6041aff               -mov byte ptr [edx + ebx], 0xff
    app->getMemory<x86::reg8>(cpu.edx + cpu.ebx * 1) = 255 /*0xff*/;
    // 004b2acd  39e8                   +cmp eax, ebp
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
    // 004b2acf  7ccc                   -jl 0x4b2a9d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2a9d;
    }
    // 004b2ad1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004b2ad4:
    // 004b2ad4  890d48945b00           -mov dword ptr [0x5b9448], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001736) /* 0x5b9448 */) = cpu.ecx;
    // 004b2ada  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2adb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b2adc:
    // 004b2adc  8b0d48945b00           -mov ecx, dword ptr [0x5b9448]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6001736) /* 0x5b9448 */);
    // 004b2ae2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ae4  a150945b00             -mov eax, dword ptr [0x5b9450]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001744) /* 0x5b9450 */);
    // 004b2ae9  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b2aeb  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004b2aee  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2aef  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004b2af1  751e                   -jne 0x4b2b11
    if (!cpu.flags.zf)
    {
        goto L_0x004b2b11;
    }
    // 004b2af3  a140945b00             -mov eax, dword ptr [0x5b9440]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001728) /* 0x5b9440 */);
    // 004b2af8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2af9  890d48945b00           -mov dword ptr [0x5b9448], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001736) /* 0x5b9448 */) = cpu.ecx;
    // 004b2aff  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004b2b02  a340945b00             -mov dword ptr [0x5b9440], eax
    app->getMemory<x86::reg32>(x86::reg32(6001728) /* 0x5b9440 */) = cpu.eax;
    // 004b2b07  ebd3                   -jmp 0x4b2adc
    goto L_0x004b2adc;
L_0x004b2b09:
    // 004b2b09  83c103                 +add ecx, 3
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
    // 004b2b0c  e928ffffff             -jmp 0x4b2a39
    goto L_0x004b2a39;
L_0x004b2b11:
    // 004b2b11  890d48945b00           -mov dword ptr [0x5b9448], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001736) /* 0x5b9448 */) = cpu.ecx;
    // 004b2b17  7c1f                   -jl 0x4b2b38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2b38;
    }
    // 004b2b19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2b1b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b2b1d  41                     -inc ecx
    (cpu.ecx)++;
    // 004b2b1e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2b20  743f                   -je 0x4b2b61
    if (cpu.flags.zf)
    {
        goto L_0x004b2b61;
    }
    // 004b2b22  a140945b00             -mov eax, dword ptr [0x5b9440]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001728) /* 0x5b9440 */);
    // 004b2b27  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2b28  890d48945b00           -mov dword ptr [0x5b9448], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001736) /* 0x5b9448 */) = cpu.ecx;
    // 004b2b2e  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004b2b31  a340945b00             -mov dword ptr [0x5b9440], eax
    app->getMemory<x86::reg32>(x86::reg32(6001728) /* 0x5b9440 */) = cpu.eax;
    // 004b2b36  eba4                   -jmp 0x4b2adc
    goto L_0x004b2adc;
L_0x004b2b38:
    // 004b2b38  a144945b00             -mov eax, dword ptr [0x5b9444]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001732) /* 0x5b9444 */);
    // 004b2b3d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004b2b40  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b2b45  e846feffff             -call 0x4b2990
    cpu.esp -= 4;
    sub_4b2990(app, cpu);
    if (cpu.terminate) return;
    // 004b2b4a  a14c945b00             -mov eax, dword ptr [0x5b944c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001740) /* 0x5b944c */);
    // 004b2b4f  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004b2b52  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b2b57  e834feffff             -call 0x4b2990
    cpu.esp -= 4;
    sub_4b2990(app, cpu);
    if (cpu.terminate) return;
    // 004b2b5c  e97bffffff             -jmp 0x4b2adc
    goto L_0x004b2adc;
L_0x004b2b61:
    // 004b2b61  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004b2b68  890d48945b00           -mov dword ptr [0x5b9448], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001736) /* 0x5b9448 */) = cpu.ecx;
    // 004b2b6e  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004b2b74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b2b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2b81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2b82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2b83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2b84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2b85  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2b88  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b2b8a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b2b8c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2b8e  0f8ee6000000           -jle 0x4b2c7a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c7a;
    }
L_0x004b2b94:
    // 004b2b94  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2b97  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b2b99  0f8ee2000000           -jle 0x4b2c81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c81;
    }
L_0x004b2b9f:
    // 004b2b9f  39d1                   +cmp ecx, edx
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
    // 004b2ba1  7e0d                   -jle 0x4b2bb0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2bb0;
    }
    // 004b2ba3  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2ba6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b2ba8  0f8eda000000           -jle 0x4b2c88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c88;
    }
    // 004b2bae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004b2bb0:
    // 004b2bb0  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2bb3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b2bb5  0f8ed6000000           -jle 0x4b2c91
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c91;
    }
    // 004b2bbb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x004b2bbd:
    // 004b2bbd  39d1                   +cmp ecx, edx
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
    // 004b2bbf  7e0d                   -jle 0x4b2bce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2bce;
    }
    // 004b2bc1  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2bc4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b2bc6  0f8ece000000           -jle 0x4b2c9a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c9a;
    }
    // 004b2bcc  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
L_0x004b2bce:
    // 004b2bce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2bd0  0f84cd000000           -je 0x4b2ca3
    if (cpu.flags.zf)
    {
        goto L_0x004b2ca3;
    }
    // 004b2bd6  81fa00008000           +cmp edx, 0x800000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388608 /*0x800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2bdc  0f8ed6000000           -jle 0x4b2cb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2cb8;
    }
    // 004b2be2  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004b2be7  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004b2bea  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x004b2bed:
    // 004b2bed  81fa00002000           +cmp edx, 0x200000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2097152 /*0x200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2bf3  7e0c                   -jle 0x4b2c01
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c01;
    }
    // 004b2bf5  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2bf8  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2bfb  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004b2bfe  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
L_0x004b2c01:
    // 004b2c01  81fa00001000           +cmp edx, 0x100000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048576 /*0x100000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2c07  7e0c                   -jle 0x4b2c15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c15;
    }
    // 004b2c09  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2c0c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b2c0f  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 004b2c12  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
L_0x004b2c15:
    // 004b2c15  81fa00800000           +cmp edx, 0x8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2c1b  7e04                   -jle 0x4b2c21
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2c21;
    }
    // 004b2c1d  83042402               -add dword ptr [esp], 2
    (app->getMemory<x86::reg32>(cpu.esp)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b2c21:
    // 004b2c21  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004b2c24  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b2c26  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004b2c28  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b2c2a  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2c2d  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004b2c2f  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b2c32  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2c35  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004b2c37  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2c3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2c3c  e8ff8a0000             -call 0x4bb740
    cpu.esp -= 4;
    sub_4bb740(app, cpu);
    if (cpu.terminate) return;
    // 004b2c41  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2c43  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b2c46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2c48  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2c4a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2c4d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2c4f  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b2c52  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b2c55  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b2c57  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2c59  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2c5c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2c5e  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b2c61  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b2c64  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b2c67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2c69  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2c6c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2c6e  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2c71  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2c74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2c75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2c76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2c77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2c78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2c79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2c7a:
    // 004b2c7a  f7da                   +neg edx
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
    // 004b2c7c  e913ffffff             -jmp 0x4b2b94
    goto L_0x004b2b94;
L_0x004b2c81:
    // 004b2c81  f7d9                   +neg ecx
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
    // 004b2c83  e917ffffff             -jmp 0x4b2b9f
    goto L_0x004b2b9f;
L_0x004b2c88:
    // 004b2c88  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2c8a  f7da                   +neg edx
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
    // 004b2c8c  e91fffffff             -jmp 0x4b2bb0
    goto L_0x004b2bb0;
L_0x004b2c91:
    // 004b2c91  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004b2c93  f7d9                   +neg ecx
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
    // 004b2c95  e923ffffff             -jmp 0x4b2bbd
    goto L_0x004b2bbd;
L_0x004b2c9a:
    // 004b2c9a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b2c9c  f7da                   +neg edx
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
    // 004b2c9e  e92bffffff             -jmp 0x4b2bce
    goto L_0x004b2bce;
L_0x004b2ca3:
    // 004b2ca3  c70300000100           -mov dword ptr [ebx], 0x10000
    app->getMemory<x86::reg32>(cpu.ebx) = 65536 /*0x10000*/;
    // 004b2ca9  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b2cac  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b2caf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2cb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2cb8:
    // 004b2cb8  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b2cba  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b2cbd  e92bffffff             -jmp 0x4b2bed
    goto L_0x004b2bed;
}

/* align: skip  */
void Application::sub_4b2cc2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2cc2  e9da8a0000             -jmp 0x4bb7a1
    return sub_4bb7a1(app, cpu);
}

/* align: skip  */
void Application::sub_4b2cc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2cc7  803d84014e0000         +cmp byte ptr [0x4e0184], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112196) /* 0x4e0184 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2cce  741a                   -je 0x4b2cea
    if (cpu.flags.zf)
    {
        goto L_0x004b2cea;
    }
    // 004b2cd0  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004b2cd6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2cd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2cd8  cc                     -int3 
    NFS2_ASSERT(false);
    // 004b2cd9  eb06                   -jmp 0x4b2ce1
    goto L_0x004b2ce1;
    // 004b2cdb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2cdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2cdd  49                     -dec ecx
    (cpu.ecx)--;
    // 004b2cde  44                     -inc esp
    (cpu.esp)++;
    // 004b2cdf  45                     -inc ebp
    (cpu.ebp)++;
    // 004b2ce0  4f                     -dec edi
    (cpu.edi)--;
L_0x004b2ce1:
    // 004b2ce1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b2ce6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b2ce9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2cea:
    // 004b2cea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2cec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2ced(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2ced  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2cee  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2cf4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2cf6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2cf8  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004b2cfa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2cfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2cfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2cfd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2cfd  87442404               -xchg dword ptr [esp + 4], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b2d01  e807000000             -call 0x4b2d0d
    cpu.esp -= 4;
    sub_4b2d0d(app, cpu);
    if (cpu.terminate) return;
    // 004b2d06  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2d0a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b2d0d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2d0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d0e  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2d10  731a                   -jae 0x4b2d2c
    if (!cpu.flags.cf)
    {
        goto L_0x004b2d2c;
    }
    // 004b2d12  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004b2d14  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b2d16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2d17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d18  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2d1e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b2d20  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d21  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2d23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d24  7606                   -jbe 0x4b2d2c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2d2c;
    }
    // 004b2d26  e811000000             -call 0x4b2d3c
    cpu.esp -= 4;
    sub_4b2d3c(app, cpu);
    if (cpu.terminate) return;
    // 004b2d2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2d2c:
    // 004b2d2c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d2d  b888014e00             -mov eax, 0x4e0188
    cpu.eax = 5112200 /*0x4e0188*/;
    // 004b2d32  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b2d37  e8c58a0000             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
    // 004b2d3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d3d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2d3e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2d42  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004b2d47:
    // 004b2d47  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004b2d4a  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004b2d50  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b2d55  7ff0                   -jg 0x4b2d47
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2d47;
    }
    // 004b2d57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d58  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d59  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b2d3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b2d3c;
    // 004b2d0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d0e  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2d10  731a                   -jae 0x4b2d2c
    if (!cpu.flags.cf)
    {
        goto L_0x004b2d2c;
    }
    // 004b2d12  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004b2d14  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b2d16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2d17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d18  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2d1e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b2d20  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d21  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2d23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d24  7606                   -jbe 0x4b2d2c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2d2c;
    }
    // 004b2d26  e811000000             -call 0x4b2d3c
    cpu.esp -= 4;
    sub_4b2d3c(app, cpu);
    if (cpu.terminate) return;
    // 004b2d2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2d2c:
    // 004b2d2c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d2d  b888014e00             -mov eax, 0x4e0188
    cpu.eax = 5112200 /*0x4e0188*/;
    // 004b2d32  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b2d37  e8c58a0000             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004b2d3c:
    // 004b2d3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d3d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2d3e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2d42  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004b2d47:
    // 004b2d47  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004b2d4a  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004b2d50  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b2d55  7ff0                   -jg 0x4b2d47
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2d47;
    }
    // 004b2d57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d58  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d59  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b2d5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2d5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d5d  e8daffffff             -call 0x4b2d3c
    cpu.esp -= 4;
    sub_4b2d3c(app, cpu);
    if (cpu.terminate) return;
    // 004b2d62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2d63  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2d67  2b0424                 +sub eax, dword ptr [esp]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b2d6a  94                     -xchg esp, eax
    {
        x86::reg32 tmp = cpu.esp;
        cpu.esp = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b2d6b  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2d6e  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip  */
void Application::sub_4b2d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2d70  ff159c014e00           -call dword ptr [0x4e019c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5112220) /* 0x4e019c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2d76  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2d77  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004b2d7c  b8fc174d00             -mov eax, 0x4d17fc
    cpu.eax = 5052412 /*0x4d17fc*/;
    // 004b2d81  e87b8a0000             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
    // 004b2d86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2d76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b2d76;
    // 004b2d70  ff159c014e00           -call dword ptr [0x4e019c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5112220) /* 0x4e019c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004b2d76:
    // 004b2d76  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2d77  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004b2d7c  b8fc174d00             -mov eax, 0x4d17fc
    cpu.eax = 5052412 /*0x4d17fc*/;
    // 004b2d81  e87b8a0000             -call 0x4bb801
    cpu.esp -= 4;
    sub_4bb801(app, cpu);
    if (cpu.terminate) return;
    // 004b2d86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2d88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2d8a  0f85ff84ffff           -jne 0x4ab28f
    if (!cpu.flags.zf)
    {
        return sub_4ab28f(app, cpu);
    }
    // 004b2d90  e8be5f0000             -call 0x4b8d53
    cpu.esp -= 4;
    sub_4b8d53(app, cpu);
    if (cpu.terminate) return;
    // 004b2d95  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2d97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2d98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2d99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2d9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2d9b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2d9c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b2d9e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b2da1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b2da6  e885d5ffff             -call 0x4b0330
    cpu.esp -= 4;
    sub_4b0330(app, cpu);
    if (cpu.terminate) return;
    // 004b2dab  a150094e00             -mov eax, dword ptr [0x4e0950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004b2db0  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2db3  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b2db5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2db7  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2db9  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004b2dbb  8b1d50094e00           -mov ebx, dword ptr [0x4e0950]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004b2dc1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2dc3  e867f8fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004b2dc8  a150094e00             -mov eax, dword ptr [0x4e0950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004b2dcd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b2dcf  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004b2dd5  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004b2dd8  e84e71ffff             -call 0x4a9f2b
    cpu.esp -= 4;
    sub_4a9f2b(app, cpu);
    if (cpu.terminate) return;
    // 004b2ddd  e83c8a0000             -call 0x4bb81e
    cpu.esp -= 4;
    sub_4bb81e(app, cpu);
    if (cpu.terminate) return;
    // 004b2de2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b2de4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2de5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2de6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2de7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2de8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2de9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2de9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2dea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2deb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2dec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2ded  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2dee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2def  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b2df2  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b2df4  a1c8da4d00             -mov eax, dword ptr [0x4ddac8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102280) /* 0x4ddac8 */);
    // 004b2df9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2dfb  e8cb000000             -call 0x4b2ecb
    cpu.esp -= 4;
    sub_4b2ecb(app, cpu);
    if (cpu.terminate) return;
    // 004b2e00  40                     -inc eax
    (cpu.eax)++;
    // 004b2e01  8b15c8da4d00           -mov edx, dword ptr [0x4ddac8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102280) /* 0x4ddac8 */);
    // 004b2e07  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b2e0b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2e0e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2e10  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b2e13  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2e16  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b2e18  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2e1a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2e1e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b2e21  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2e25  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2e28  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2e2a  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b2e2d  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b2e2f  e88f37ffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b2e34  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b2e36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2e38  7455                   -je 0x4b2e8f
    if (cpu.flags.zf)
    {
        goto L_0x004b2e8f;
    }
    // 004b2e3a  8b35c8da4d00           -mov esi, dword ptr [0x4ddac8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102280) /* 0x4ddac8 */);
    // 004b2e40  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2e42  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b2e44  a32c0e5700             -mov dword ptr [0x570e2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5705260) /* 0x570e2c */) = cpu.eax;
    // 004b2e49  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b2e4a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b2e4c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b2e4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2e4f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2e51  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b2e54  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2e56  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b2e58  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b2e5b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2e5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2e5e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b2e5f  a12c0e5700             -mov eax, dword ptr [0x570e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705260) /* 0x570e2c */);
    // 004b2e64  8b15ccda4d00           -mov edx, dword ptr [0x4ddacc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102284) /* 0x4ddacc */);
    // 004b2e6a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b2e6c  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2e6f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b2e71  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b2e73  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2e77  e84f000000             -call 0x4b2ecb
    cpu.esp -= 4;
    sub_4b2ecb(app, cpu);
    if (cpu.terminate) return;
    // 004b2e7c  a12c0e5700             -mov eax, dword ptr [0x570e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705260) /* 0x570e2c */);
    // 004b2e81  01f0                   +add eax, esi
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
    // 004b2e83  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b2e89  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2e8d  eb05                   -jmp 0x4b2e94
    goto L_0x004b2e94;
L_0x004b2e8f:
    // 004b2e8f  a32c0e5700             -mov dword ptr [0x570e2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5705260) /* 0x570e2c */) = cpu.eax;
L_0x004b2e94:
    // 004b2e94  a3280e5700             -mov dword ptr [0x570e28], eax
    app->getMemory<x86::reg32>(x86::reg32(5705256) /* 0x570e28 */) = cpu.eax;
    // 004b2e99  a1280e5700             -mov eax, dword ptr [0x570e28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705256) /* 0x570e28 */);
    // 004b2e9e  a3d8a45b00             -mov dword ptr [0x5ba4d8], eax
    app->getMemory<x86::reg32>(x86::reg32(6005976) /* 0x5ba4d8 */) = cpu.eax;
    // 004b2ea3  a12c0e5700             -mov eax, dword ptr [0x570e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705260) /* 0x570e2c */);
    // 004b2ea8  a3dca45b00             -mov dword ptr [0x5ba4dc], eax
    app->getMemory<x86::reg32>(x86::reg32(6005980) /* 0x5ba4dc */) = cpu.eax;
    // 004b2ead  a1d8a45b00             -mov eax, dword ptr [0x5ba4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6005976) /* 0x5ba4d8 */);
    // 004b2eb2  a3300e5700             -mov dword ptr [0x570e30], eax
    app->getMemory<x86::reg32>(x86::reg32(5705264) /* 0x570e30 */) = cpu.eax;
    // 004b2eb7  a1dca45b00             -mov eax, dword ptr [0x5ba4dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6005980) /* 0x5ba4dc */);
    // 004b2ebc  a3340e5700             -mov dword ptr [0x570e34], eax
    app->getMemory<x86::reg32>(x86::reg32(5705268) /* 0x570e34 */) = cpu.eax;
    // 004b2ec1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b2ec4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ec5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ec6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ec7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ec8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ec9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2eca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2ecb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2ecb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2ecc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2ecd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2ece  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2ecf  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b2ed2  8b0de0a45b00           -mov ecx, dword ptr [0x5ba4e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6005984) /* 0x5ba4e0 */);
    // 004b2ed8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b2eda  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b2edd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004b2edf:
    // 004b2edf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2ee1  80fa20                 +cmp dl, 0x20
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
    // 004b2ee4  7405                   -je 0x4b2eeb
    if (cpu.flags.zf)
    {
        goto L_0x004b2eeb;
    }
    // 004b2ee6  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2ee9  7503                   -jne 0x4b2eee
    if (!cpu.flags.zf)
    {
        goto L_0x004b2eee;
    }
L_0x004b2eeb:
    // 004b2eeb  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2eec  ebf1                   -jmp 0x4b2edf
    goto L_0x004b2edf;
L_0x004b2eee:
    // 004b2eee  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b2ef0  0f84bd000000           -je 0x4b2fb3
    if (cpu.flags.zf)
    {
        goto L_0x004b2fb3;
    }
    // 004b2ef6  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2ef8  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b2efa  80ff22                 +cmp bh, 0x22
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2efd  7503                   -jne 0x4b2f02
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f02;
    }
    // 004b2eff  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004b2f01  40                     -inc eax
    (cpu.eax)++;
L_0x004b2f02:
    // 004b2f02  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b2f06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004b2f08:
    // 004b2f08  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f0b  751c                   -jne 0x4b2f29
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f29;
    }
    // 004b2f0d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b2f0f  750f                   -jne 0x4b2f20
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f20;
    }
    // 004b2f11  40                     -inc eax
    (cpu.eax)++;
    // 004b2f12  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b2f14  7504                   -jne 0x4b2f1a
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f1a;
    }
    // 004b2f16  b202                   -mov dl, 2
    cpu.dl = 2 /*0x2*/;
    // 004b2f18  ebee                   -jmp 0x4b2f08
    goto L_0x004b2f08;
L_0x004b2f1a:
    // 004b2f1a  740d                   -je 0x4b2f29
    if (cpu.flags.zf)
    {
        goto L_0x004b2f29;
    }
    // 004b2f1c  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004b2f1e  ebe8                   -jmp 0x4b2f08
    goto L_0x004b2f08;
L_0x004b2f20:
    // 004b2f20  80fa01                 +cmp dl, 1
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
    // 004b2f23  0f845e000000           -je 0x4b2f87
    if (cpu.flags.zf)
    {
        goto L_0x004b2f87;
    }
L_0x004b2f29:
    // 004b2f29  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f2b  80fe20                 +cmp dh, 0x20
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f2e  7405                   -je 0x4b2f35
    if (cpu.flags.zf)
    {
        goto L_0x004b2f35;
    }
    // 004b2f30  80fe09                 +cmp dh, 9
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f33  7508                   -jne 0x4b2f3d
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f3d;
    }
L_0x004b2f35:
    // 004b2f35  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b2f37  0f844a000000           -je 0x4b2f87
    if (cpu.flags.zf)
    {
        goto L_0x004b2f87;
    }
L_0x004b2f3d:
    // 004b2f3d  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f3f  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 004b2f41  7444                   -je 0x4b2f87
    if (cpu.flags.zf)
    {
        goto L_0x004b2f87;
    }
    // 004b2f43  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f46  7530                   -jne 0x4b2f78
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f78;
    }
    // 004b2f48  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b2f4a  7511                   -jne 0x4b2f5d
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f5d;
    }
    // 004b2f4c  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f50  7526                   -jne 0x4b2f78
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f78;
    }
    // 004b2f52  8a70ff                 -mov dh, byte ptr [eax - 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004b2f55  40                     -inc eax
    (cpu.eax)++;
    // 004b2f56  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f59  74ad                   -je 0x4b2f08
    if (cpu.flags.zf)
    {
        goto L_0x004b2f08;
    }
    // 004b2f5b  eb1b                   -jmp 0x4b2f78
    goto L_0x004b2f78;
L_0x004b2f5d:
    // 004b2f5d  80fa01                 +cmp dl, 1
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
    // 004b2f60  750f                   -jne 0x4b2f71
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f71;
    }
    // 004b2f62  8a7001                 -mov dh, byte ptr [eax + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b2f65  80fe22                 +cmp dh, 0x22
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f68  740d                   -je 0x4b2f77
    if (cpu.flags.zf)
    {
        goto L_0x004b2f77;
    }
    // 004b2f6a  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f6d  7509                   -jne 0x4b2f78
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f78;
    }
    // 004b2f6f  eb06                   -jmp 0x4b2f77
    goto L_0x004b2f77;
L_0x004b2f71:
    // 004b2f71  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f75  7501                   -jne 0x4b2f78
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f78;
    }
L_0x004b2f77:
    // 004b2f77  40                     -inc eax
    (cpu.eax)++;
L_0x004b2f78:
    // 004b2f78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b2f7a  7408                   -je 0x4b2f84
    if (cpu.flags.zf)
    {
        goto L_0x004b2f84;
    }
    // 004b2f7c  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f7e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2f7f  8833                   -mov byte ptr [ebx], dh
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dh;
    // 004b2f81  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2f82  eb84                   -jmp 0x4b2f08
    goto L_0x004b2f08;
L_0x004b2f84:
    // 004b2f84  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2f85  eb81                   -jmp 0x4b2f08
    goto L_0x004b2f08;
L_0x004b2f87:
    // 004b2f87  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b2f89  741d                   -je 0x4b2fa8
    if (cpu.flags.zf)
    {
        goto L_0x004b2fa8;
    }
    // 004b2f8b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b2f8d  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2f91  892c96                 -mov dword ptr [esi + edx*4], ebp
    app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4) = cpu.ebp;
    // 004b2f94  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f96  47                     -inc edi
    (cpu.edi)++;
    // 004b2f97  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b2f99  7504                   -jne 0x4b2f9f
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f9f;
    }
    // 004b2f9b  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004b2f9d  eb14                   -jmp 0x4b2fb3
    goto L_0x004b2fb3;
L_0x004b2f9f:
    // 004b2f9f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2fa0  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004b2fa3  e937ffffff             -jmp 0x4b2edf
    goto L_0x004b2edf;
L_0x004b2fa8:
    // 004b2fa8  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2faa  47                     -inc edi
    (cpu.edi)++;
    // 004b2fab  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b2fad  0f8538ffffff           -jne 0x4b2eeb
    if (!cpu.flags.zf)
    {
        goto L_0x004b2eeb;
    }
L_0x004b2fb3:
    // 004b2fb3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2fb6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b2fb8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b2fba  890de0a45b00           -mov dword ptr [0x5ba4e0], ecx
    app->getMemory<x86::reg32>(x86::reg32(6005984) /* 0x5ba4e0 */) = cpu.ecx;
    // 004b2fc0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b2fc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b2fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b2fd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2fd1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fd3  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2fda  7507                   -jne 0x4b2fe3
    if (!cpu.flags.zf)
    {
        goto L_0x004b2fe3;
    }
    // 004b2fdc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004b2fe1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2fe2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2fe3:
    // 004b2fe3  e87823ffff             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 004b2fe8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2fea  e87d27ffff             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 004b2fef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2ff1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2ff3  7c1a                   -jl 0x4b300f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b300f;
    }
    // 004b2ff5  e87a23ffff             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004b2ffa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2ffc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b2fff  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3001  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004b3004  8b80debf5900           -mov eax, dword ptr [eax + 0x59bfde]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881822) /* 0x59bfde */);
    // 004b300a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b300d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b300e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b300f:
    // 004b300f  e86023ffff             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004b3014  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004b3019  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b301a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b301b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b301b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b301c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b301d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b301e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b301f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3022  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3024  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b3026  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3028  7c08                   -jl 0x4b3032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3032;
    }
    // 004b302a  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113532) /* 0x4e06bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3030  7614                   -jbe 0x4b3046
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3046;
    }
L_0x004b3032:
    // 004b3032  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b3037  e87436ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004b303c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3041  e997000000             -jmp 0x4b30dd
    goto L_0x004b30dd;
L_0x004b3046:
    // 004b3046  8b2dac064e00           -mov ebp, dword ptr [0x4e06ac]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b304c  8b6c8500               -mov ebp, dword ptr [ebp + eax*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004b3050  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3056  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3058  e81b510000             -call 0x4b8178
    cpu.esp -= 4;
    sub_4b8178(app, cpu);
    if (cpu.terminate) return;
    // 004b305d  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004b305f  7422                   -je 0x4b3083
    if (cpu.flags.zf)
    {
        goto L_0x004b3083;
    }
    // 004b3061  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004b3063  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b3065  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b3067  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3068  2eff1590654c00         -call dword ptr cs:[0x4c6590]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006736) /* 0x4c6590 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b306f  83f8ff                 +cmp eax, -1
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
    // 004b3072  750f                   -jne 0x4b3083
    if (!cpu.flags.zf)
    {
        goto L_0x004b3083;
    }
L_0x004b3074:
    // 004b3074  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3076  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b307c  e83135ffff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004b3081  eb5a                   -jmp 0x4b30dd
    goto L_0x004b30dd;
L_0x004b3083:
    // 004b3083  833dd0ed4d0000         +cmp dword ptr [0x4dedd0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107152) /* 0x4dedd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b308a  7422                   -je 0x4b30ae
    if (cpu.flags.zf)
    {
        goto L_0x004b30ae;
    }
    // 004b308c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b308e  ff15a4ed4d00           -call dword ptr [0x4deda4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107108) /* 0x4deda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3094  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3096  7416                   -je 0x4b30ae
    if (cpu.flags.zf)
    {
        goto L_0x004b30ae;
    }
    // 004b3098  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b309a  ff15d0ed4d00           -call dword ptr [0x4dedd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107152) /* 0x4dedd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b30a0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b30a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b30a4  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b30aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b30ac  eb2f                   -jmp 0x4b30dd
    goto L_0x004b30dd;
L_0x004b30ae:
    // 004b30ae  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b30b0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b30b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b30b5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b30b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b30b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b30b8  2eff15e4654c00         -call dword ptr cs:[0x4c65e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006820) /* 0x4c65e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b30bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b30c1  74b1                   -je 0x4b3074
    if (cpu.flags.zf)
    {
        goto L_0x004b3074;
    }
    // 004b30c3  3b1c24                 +cmp ebx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b30c6  740a                   -je 0x4b30d2
    if (cpu.flags.zf)
    {
        goto L_0x004b30d2;
    }
    // 004b30c8  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 004b30cd  e8de35ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
L_0x004b30d2:
    // 004b30d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b30d4  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b30da  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x004b30dd:
    // 004b30dd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b30e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b30e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b30e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b30e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b30e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b30e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b30e9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b30ea  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b30ec  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004b30ef  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b30f5  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b30f8  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b30fb  83f901                 +cmp ecx, 1
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
    // 004b30fe  741e                   -je 0x4b311e
    if (cpu.flags.zf)
    {
        goto L_0x004b311e;
    }
    // 004b3100  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b3102  7413                   -je 0x4b3117
    if (cpu.flags.zf)
    {
        goto L_0x004b3117;
    }
L_0x004b3104:
    // 004b3104  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004b3107  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b310d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b3112  e9a6000000             -jmp 0x4b31bd
    goto L_0x004b31bd;
L_0x004b3117:
    // 004b3117  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004b311e:
    // 004b311e  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 004b3122  7510                   -jne 0x4b3134
    if (!cpu.flags.zf)
    {
        goto L_0x004b3134;
    }
    // 004b3124  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b3129  e88235ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004b312e  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004b3132  ebd0                   -jmp 0x4b3104
    goto L_0x004b3104;
L_0x004b3134:
    // 004b3134  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b3137  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004b313b  7507                   -jne 0x4b3144
    if (!cpu.flags.zf)
    {
        goto L_0x004b3144;
    }
    // 004b313d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b313f  e8c7d0ffff             -call 0x4b020b
    cpu.esp -= 4;
    sub_4b020b(app, cpu);
    if (cpu.terminate) return;
L_0x004b3144:
    // 004b3144  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 004b3149  83fb0a                 +cmp ebx, 0xa
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
    // 004b314c  7533                   -jne 0x4b3181
    if (!cpu.flags.zf)
    {
        goto L_0x004b3181;
    }
    // 004b314e  8a420c                 -mov al, byte ptr [edx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004b3151  b900060000             -mov ecx, 0x600
    cpu.ecx = 1536 /*0x600*/;
    // 004b3156  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004b3158  7527                   -jne 0x4b3181
    if (!cpu.flags.zf)
    {
        goto L_0x004b3181;
    }
    // 004b315a  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004b315e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3160  c6000d                 -mov byte ptr [eax], 0xd
    app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 004b3163  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3165  45                     -inc ebp
    (cpu.ebp)++;
    // 004b3166  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b3169  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b316b  40                     -inc eax
    (cpu.eax)++;
    // 004b316c  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004b316f  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b3172  39f0                   +cmp eax, esi
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
    // 004b3174  750b                   -jne 0x4b3181
    if (!cpu.flags.zf)
    {
        goto L_0x004b3181;
    }
    // 004b3176  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3178  e81281ffff             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
    // 004b317d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b317f  7583                   -jne 0x4b3104
    if (!cpu.flags.zf)
    {
        goto L_0x004b3104;
    }
L_0x004b3181:
    // 004b3181  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004b3185  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3187  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004b3189  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b318b  47                     -inc edi
    (cpu.edi)++;
    // 004b318c  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b318f  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004b3191  45                     -inc ebp
    (cpu.ebp)++;
    // 004b3192  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004b3195  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b3198  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 004b319a  7505                   -jne 0x4b31a1
    if (!cpu.flags.zf)
    {
        goto L_0x004b31a1;
    }
    // 004b319c  3b6a14                 +cmp ebp, dword ptr [edx + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b319f  750f                   -jne 0x4b31b0
    if (!cpu.flags.zf)
    {
        goto L_0x004b31b0;
    }
L_0x004b31a1:
    // 004b31a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b31a3  e8e780ffff             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
    // 004b31a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b31aa  0f8554ffffff           -jne 0x4b3104
    if (!cpu.flags.zf)
    {
        goto L_0x004b3104;
    }
L_0x004b31b0:
    // 004b31b0  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004b31b3  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b31b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b31bb  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x004b31bd:
    // 004b31bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b31c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b31c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b31c5  83ec76                 -sub esp, 0x76
    (cpu.esp) -= x86::reg32(x86::sreg32(118 /*0x76*/));
    // 004b31c8  db7c246c               -fstp xword ptr [esp + 0x6c]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(108) /* 0x6c */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31cc  dd3424                 -fnsave dword ptr [esp]
    NFS2_ASSERT(false);
    // 004b31cf  db6c241c               -fld xword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004b31d3  db6c246c               -fld xword ptr [esp + 0x6c]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(108) /* 0x6c */)));
    // 004b31d7  e824870000             -call 0x4bb900
    cpu.esp -= 4;
    sub_4bb900(app, cpu);
    if (cpu.terminate) return;
    // 004b31dc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004b31de  db7c241c               -fstp xword ptr [esp + 0x1c]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(28) /* 0x1c */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31e2  6625ff00               -and ax, 0xff
    cpu.ax &= x86::reg16(x86::sreg16(255 /*0xff*/));
    // 004b31e6  660b442404             -or ax, word ptr [esp + 4]
    cpu.ax |= x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b31eb  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004b31f0  dd2424                 -frstor dword ptr [esp]
    NFS2_ASSERT(false);
    // 004b31f3  83c476                 -add esp, 0x76
    (cpu.esp) += x86::reg32(x86::sreg32(118 /*0x76*/));
    // 004b31f6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b31f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b31f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b31f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b31fa  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b31fb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b31fc  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b31ff  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b3201  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004b3203  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b3208  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b320a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b320d  885c246c               -mov byte ptr [esp + 0x6c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 004b3211  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004b3213  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 004b3217  66895c241e             -mov word ptr [esp + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 004b321c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b321e  66894c241c             -mov word ptr [esp + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004b3223  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004b3227  e978000000             -jmp 0x4b32a4
    goto L_0x004b32a4;
L_0x004b322c:
    // 004b322c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b322e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3230  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004b3234  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004b3238  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b323a  e87a020000             -call 0x4b34b9
    cpu.esp -= 4;
    sub_4b34b9(app, cpu);
    if (cpu.terminate) return;
    // 004b323f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3241  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004b3245  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b3247  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b3249  47                     -inc edi
    (cpu.edi)++;
    // 004b324a  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 004b324e  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004b3252  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004b3254  0f8453020000           -je 0x4b34ad
    if (cpu.flags.zf)
    {
        goto L_0x004b34ad;
    }
    // 004b325a  3c6e                   +cmp al, 0x6e
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
    // 004b325c  0f85d8000000           -jne 0x4b333a
    if (!cpu.flags.zf)
    {
        goto L_0x004b333a;
    }
    // 004b3262  8a74241e               -mov dh, byte ptr [esp + 0x1e]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004b3266  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004b3269  7461                   -je 0x4b32cc
    if (cpu.flags.zf)
    {
        goto L_0x004b32cc;
    }
    // 004b326b  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004b326e  7413                   -je 0x4b3283
    if (cpu.flags.zf)
    {
        goto L_0x004b3283;
    }
    // 004b3270  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3272  83c208                 +add edx, 8
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
    // 004b3275  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3277  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
L_0x004b327a:
    // 004b327a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b327e  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 004b3281  eb21                   -jmp 0x4b32a4
    goto L_0x004b32a4;
L_0x004b3283:
    // 004b3283  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004b3286  740c                   -je 0x4b3294
    if (cpu.flags.zf)
    {
        goto L_0x004b3294;
    }
    // 004b3288  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b328a  83c004                 +add eax, 4
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
    // 004b328d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b328f  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b3292  eb0a                   -jmp 0x4b329e
    goto L_0x004b329e;
L_0x004b3294:
    // 004b3294  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3296  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3299  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004b329b  8b57fc                 -mov edx, dword ptr [edi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
L_0x004b329e:
    // 004b329e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b32a2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004b32a4:
    // 004b32a4  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004b32a8  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b32aa  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004b32ac  0f84fb010000           -je 0x4b34ad
    if (cpu.flags.zf)
    {
        goto L_0x004b34ad;
    }
    // 004b32b2  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b32b5  80ff25                 +cmp bh, 0x25
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b32b8  0f846effffff           -je 0x4b322c
    if (cpu.flags.zf)
    {
        goto L_0x004b322c;
    }
    // 004b32be  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b32c0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b32c2  88fa                   -mov dl, bh
    cpu.dl = cpu.bh;
    // 004b32c4  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004b32c8  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b32ca  ebd8                   -jmp 0x4b32a4
    goto L_0x004b32a4;
L_0x004b32cc:
    // 004b32cc  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004b32cf  743d                   -je 0x4b330e
    if (cpu.flags.zf)
    {
        goto L_0x004b330e;
    }
    // 004b32d1  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004b32d4  7414                   -je 0x4b32ea
    if (cpu.flags.zf)
    {
        goto L_0x004b32ea;
    }
    // 004b32d6  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b32d8  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b32db  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004b32dd  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 004b32e0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b32e4  66268902               -mov word ptr es:[edx], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 004b32e8  ebba                   -jmp 0x4b32a4
    goto L_0x004b32a4;
L_0x004b32ea:
    // 004b32ea  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004b32ed  7413                   -je 0x4b3302
    if (cpu.flags.zf)
    {
        goto L_0x004b3302;
    }
    // 004b32ef  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b32f1  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b32f4  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004b32f6  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004b32f9:
    // 004b32f9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b32fd  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 004b3300  eba2                   -jmp 0x4b32a4
    goto L_0x004b32a4;
L_0x004b3302:
    // 004b3302  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3304  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3307  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3309  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b330c  ebeb                   -jmp 0x4b32f9
    goto L_0x004b32f9;
L_0x004b330e:
    // 004b330e  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004b3311  740f                   -je 0x4b3322
    if (cpu.flags.zf)
    {
        goto L_0x004b3322;
    }
    // 004b3313  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3315  83c008                 +add eax, 8
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
    // 004b3318  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b331a  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 004b331d  e958ffffff             -jmp 0x4b327a
    goto L_0x004b327a;
L_0x004b3322:
    // 004b3322  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004b3325  0f8569ffffff           -jne 0x4b3294
    if (!cpu.flags.zf)
    {
        goto L_0x004b3294;
    }
    // 004b332b  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b332d  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3330  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004b3332  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004b3335  e964ffffff             -jmp 0x4b329e
    goto L_0x004b329e;
L_0x004b333a:
    // 004b333a  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004b333e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b3340  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3342  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b3346  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004b334a  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004b334e  e878050000             -call 0x4b38cb
    cpu.esp -= 4;
    sub_4b38cb(app, cpu);
    if (cpu.terminate) return;
    // 004b3353  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3355  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b3359  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b335b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b335d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b3361  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b3365  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3369  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b336b  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b336f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3371  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b3375  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b3377  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b337b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b337d  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3381  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3383  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3385  8a64241e               -mov ah, byte ptr [esp + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004b3389  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b338d  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004b3390  751d                   -jne 0x4b33af
    if (!cpu.flags.zf)
    {
        goto L_0x004b33af;
    }
    // 004b3392  807c241620             +cmp byte ptr [esp + 0x16], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3397  7516                   -jne 0x4b33af
    if (!cpu.flags.zf)
    {
        goto L_0x004b33af;
    }
L_0x004b3399:
    // 004b3399  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004b339e  7e0f                   -jle 0x4b33af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b33af;
    }
    // 004b33a0  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004b33a5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b33a7  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b33a9  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b33ad  ebea                   -jmp 0x4b3399
    goto L_0x004b3399;
L_0x004b33af:
    // 004b33af  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
L_0x004b33b3:
    // 004b33b3  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b33b8  7e14                   -jle 0x4b33ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b33ce;
    }
    // 004b33ba  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b33bc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b33be  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b33c0  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b33c2  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b33c6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b33c7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b33c8  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b33cc  ebe5                   -jmp 0x4b33b3
    goto L_0x004b33b3;
L_0x004b33ce:
    // 004b33ce  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b33d3  7e0f                   -jle 0x4b33e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b33e4;
    }
    // 004b33d5  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b33da  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b33dc  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b33de  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b33e2  ebea                   -jmp 0x4b33ce
    goto L_0x004b33ce;
L_0x004b33e4:
    // 004b33e4  8a742415               -mov dh, byte ptr [esp + 0x15]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 004b33e8  80fe73                 +cmp dh, 0x73
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b33eb  7532                   -jne 0x4b341f
    if (!cpu.flags.zf)
    {
        goto L_0x004b341f;
    }
    // 004b33ed  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b33f2  740f                   -je 0x4b3403
    if (cpu.flags.zf)
    {
        goto L_0x004b3403;
    }
L_0x004b33f4:
    // 004b33f4  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b33f6  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b33f8  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b33fa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b33fc  e872040000             -call 0x4b3873
    cpu.esp -= 4;
    sub_4b3873(app, cpu);
    if (cpu.terminate) return;
    // 004b3401  eb3d                   -jmp 0x4b3440
    goto L_0x004b3440;
L_0x004b3403:
    // 004b3403  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3408  7e36                   -jle 0x4b3440
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3440;
    }
    // 004b340a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b340c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b340e  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004b3411  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3413  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3417  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b3418  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3419  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004b341d  ebe4                   -jmp 0x4b3403
    goto L_0x004b3403;
L_0x004b341f:
    // 004b341f  80fe53                 +cmp dh, 0x53
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3422  74d0                   -je 0x4b33f4
    if (cpu.flags.zf)
    {
        goto L_0x004b33f4;
    }
L_0x004b3424:
    // 004b3424  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3429  7e15                   -jle 0x4b3440
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3440;
    }
    // 004b342b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b342d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b342f  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004b3432  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3434  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3438  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b3439  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b343a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b343e  ebe4                   -jmp 0x4b3424
    goto L_0x004b3424;
L_0x004b3440:
    // 004b3440  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3445  7e0f                   -jle 0x4b3456
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3456;
    }
    // 004b3447  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b344c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b344e  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3450  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b3454  ebea                   -jmp 0x4b3440
    goto L_0x004b3440;
L_0x004b3456:
    // 004b3456  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b345b  7e15                   -jle 0x4b3472
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3472;
    }
    // 004b345d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b345f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3461  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004b3464  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3466  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b346a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b346b  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b346c  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004b3470  ebe4                   -jmp 0x4b3456
    goto L_0x004b3456;
L_0x004b3472:
    // 004b3472  837c243400             +cmp dword ptr [esp + 0x34], 0
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
    // 004b3477  7e0f                   -jle 0x4b3488
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3488;
    }
    // 004b3479  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b347e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3480  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b3482  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b3486  ebea                   -jmp 0x4b3472
    goto L_0x004b3472;
L_0x004b3488:
    // 004b3488  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004b348d  0f8411feffff           -je 0x4b32a4
    if (cpu.flags.zf)
    {
        goto L_0x004b32a4;
    }
L_0x004b3493:
    // 004b3493  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004b3498  0f8e06feffff           -jle 0x4b32a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b32a4;
    }
    // 004b349e  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004b34a3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b34a5  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b34a7  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b34ab  ebe6                   -jmp 0x4b3493
    goto L_0x004b3493;
L_0x004b34ad:
    // 004b34ad  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b34b1  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b34b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b34b5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b34b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b34b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b34b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b34b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b34b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b34ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b34bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b34bc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b34be  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b34c0  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 004b34c4  e83d010000             -call 0x4b3606
    cpu.esp -= 4;
    sub_4b3606(app, cpu);
    if (cpu.terminate) return;
    // 004b34c9  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b34d0  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b34d3  7524                   -jne 0x4b34f9
    if (!cpu.flags.zf)
    {
        goto L_0x004b34f9;
    }
    // 004b34d5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b34d7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b34da  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b34dc  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b34df  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b34e2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b34e4  7d10                   -jge 0x4b34f6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b34f6;
    }
    // 004b34e6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b34e8  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004b34eb  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004b34ed  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004b34f0  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004b34f3  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x004b34f6:
    // 004b34f6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b34f7  eb1f                   -jmp 0x4b3518
    goto L_0x004b3518;
L_0x004b34f9:
    // 004b34f9  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b34fb  80fa30                 +cmp dl, 0x30
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
    // 004b34fe  7218                   -jb 0x4b3518
    if (cpu.flags.cf)
    {
        goto L_0x004b3518;
    }
    // 004b3500  80fa39                 +cmp dl, 0x39
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
    // 004b3503  7713                   -ja 0x4b3518
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b3518;
    }
    // 004b3505  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b3509  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b350b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b350d  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b3510  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3512  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3513  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b3516  ebe1                   -jmp 0x4b34f9
    goto L_0x004b34f9;
L_0x004b3518:
    // 004b3518  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004b351f  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3522  7551                   -jne 0x4b3575
    if (!cpu.flags.zf)
    {
        goto L_0x004b3575;
    }
    // 004b3524  40                     -inc eax
    (cpu.eax)++;
    // 004b3525  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b352c  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b352f  751b                   -jne 0x4b354c
    if (!cpu.flags.zf)
    {
        goto L_0x004b354c;
    }
    // 004b3531  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3533  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3536  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3538  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b353b  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b353e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3540  7d07                   -jge 0x4b3549
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b3549;
    }
    // 004b3542  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x004b3549:
    // 004b3549  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b354a  eb1f                   -jmp 0x4b356b
    goto L_0x004b356b;
L_0x004b354c:
    // 004b354c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b354e  80fa30                 +cmp dl, 0x30
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
    // 004b3551  7218                   -jb 0x4b356b
    if (cpu.flags.cf)
    {
        goto L_0x004b356b;
    }
    // 004b3553  80fa39                 +cmp dl, 0x39
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
    // 004b3556  7713                   -ja 0x4b356b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b356b;
    }
    // 004b3558  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b355c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b355e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3560  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b3563  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3565  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3566  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004b3569  ebe1                   -jmp 0x4b354c
    goto L_0x004b354c;
L_0x004b356b:
    // 004b356b  837b08ff               +cmp dword ptr [ebx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b356f  7404                   -je 0x4b3575
    if (cpu.flags.zf)
    {
        goto L_0x004b3575;
    }
    // 004b3571  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x004b3575:
    // 004b3575  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3577  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b357a  80fa4e                 +cmp dl, 0x4e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b357d  721f                   -jb 0x4b359e
    if (cpu.flags.cf)
    {
        goto L_0x004b359e;
    }
    // 004b357f  0f8677000000           -jbe 0x4b35fc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b35fc;
    }
    // 004b3585  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3588  720b                   -jb 0x4b3595
    if (cpu.flags.cf)
    {
        goto L_0x004b3595;
    }
    // 004b358a  762b                   -jbe 0x4b35b7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b35b7;
    }
    // 004b358c  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b358f  7426                   -je 0x4b35b7
    if (cpu.flags.zf)
    {
        goto L_0x004b35b7;
    }
    // 004b3591  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3592  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3593  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3594  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3595:
    // 004b3595  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3598  742b                   -je 0x4b35c5
    if (cpu.flags.zf)
    {
        goto L_0x004b35c5;
    }
    // 004b359a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b359b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b359c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b359d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b359e:
    // 004b359e  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b35a1  720b                   -jb 0x4b35ae
    if (cpu.flags.cf)
    {
        goto L_0x004b35ae;
    }
    // 004b35a3  7626                   -jbe 0x4b35cb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b35cb;
    }
    // 004b35a5  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b35a8  743d                   -je 0x4b35e7
    if (cpu.flags.zf)
    {
        goto L_0x004b35e7;
    }
    // 004b35aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b35ae:
    // 004b35ae  80fa46                 +cmp dl, 0x46
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b35b1  7443                   -je 0x4b35f6
    if (cpu.flags.zf)
    {
        goto L_0x004b35f6;
    }
    // 004b35b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b35b7:
    // 004b35b7  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004b35ba  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004b35bd  40                     -inc eax
    (cpu.eax)++;
    // 004b35be  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004b35c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b35c5:
    // 004b35c5  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004b35c9  eb35                   -jmp 0x4b3600
    goto L_0x004b3600;
L_0x004b35cb:
    // 004b35cb  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b35cf  7531                   -jne 0x4b3602
    if (!cpu.flags.zf)
    {
        goto L_0x004b3602;
    }
    // 004b35d1  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b35d5  752b                   -jne 0x4b3602
    if (!cpu.flags.zf)
    {
        goto L_0x004b3602;
    }
    // 004b35d7  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004b35da  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b35dd  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b35e0  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 004b35e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b35e7:
    // 004b35e7  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004b35ea  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b35ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b35ef  88531f                 -mov byte ptr [ebx + 0x1f], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 004b35f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b35f6:
    // 004b35f6  804b1e80               +or byte ptr [ebx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 004b35fa  eb04                   -jmp 0x4b3600
    goto L_0x004b3600;
L_0x004b35fc:
    // 004b35fc  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004b3600:
    // 004b3600  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004b3602:
    // 004b3602  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3603  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3604  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3605  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3606(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3606  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3607  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3608  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
L_0x004b360e:
    // 004b360e  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b3610  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3613  7506                   -jne 0x4b361b
    if (!cpu.flags.zf)
    {
        goto L_0x004b361b;
    }
    // 004b3615  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004b3619  eb42                   -jmp 0x4b365d
    goto L_0x004b365d;
L_0x004b361b:
    // 004b361b  80fb23                 +cmp bl, 0x23
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b361e  7506                   -jne 0x4b3626
    if (!cpu.flags.zf)
    {
        goto L_0x004b3626;
    }
    // 004b3620  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004b3624  eb37                   -jmp 0x4b365d
    goto L_0x004b365d;
L_0x004b3626:
    // 004b3626  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3629  7513                   -jne 0x4b363e
    if (!cpu.flags.zf)
    {
        goto L_0x004b363e;
    }
    // 004b362b  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004b362e  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004b3631  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 004b3633  886a1e                 -mov byte ptr [edx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 004b3636  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 004b3639  885a1e                 -mov byte ptr [edx + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 004b363c  eb1f                   -jmp 0x4b365d
    goto L_0x004b365d;
L_0x004b363e:
    // 004b363e  80fb20                 +cmp bl, 0x20
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
    // 004b3641  7512                   -jne 0x4b3655
    if (!cpu.flags.zf)
    {
        goto L_0x004b3655;
    }
    // 004b3643  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004b3646  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004b3649  7512                   -jne 0x4b365d
    if (!cpu.flags.zf)
    {
        goto L_0x004b365d;
    }
    // 004b364b  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 004b364d  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004b3650  884a1e                 -mov byte ptr [edx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004b3653  eb08                   -jmp 0x4b365d
    goto L_0x004b365d;
L_0x004b3655:
    // 004b3655  80fb30                 +cmp bl, 0x30
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
    // 004b3658  7506                   -jne 0x4b3660
    if (!cpu.flags.zf)
    {
        goto L_0x004b3660;
    }
    // 004b365a  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x004b365d:
    // 004b365d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b365e  ebae                   -jmp 0x4b360e
    goto L_0x004b360e;
L_0x004b3660:
    // 004b3660  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3661  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3662  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3663(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3663  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3664  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3665  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3666  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3667  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3669  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b366b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b366d  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004b366f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b3671:
    // 004b3671  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b3673  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 004b3676  42                     -inc edx
    (cpu.edx)++;
    // 004b3677  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b3679  7407                   -je 0x4b3682
    if (cpu.flags.zf)
    {
        goto L_0x004b3682;
    }
    // 004b367b  39f8                   +cmp eax, edi
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
    // 004b367d  7403                   -je 0x4b3682
    if (cpu.flags.zf)
    {
        goto L_0x004b3682;
    }
    // 004b367f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3680  ebef                   -jmp 0x4b3671
    goto L_0x004b3671;
L_0x004b3682:
    // 004b3682  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b3683  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3684  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3685  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3686  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3687(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3687  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3688  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3689  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b368a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b368d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b368f  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b3691  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3693  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b3695  83feff                 +cmp esi, -1
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
    // 004b3698  7525                   -jne 0x4b36bf
    if (!cpu.flags.zf)
    {
        goto L_0x004b36bf;
    }
L_0x004b369a:
    // 004b369a  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004b369e  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 004b36a1  7418                   -je 0x4b36bb
    if (cpu.flags.zf)
    {
        goto L_0x004b36bb;
    }
    // 004b36a3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b36a5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b36a7  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 004b36aa  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b36ad  e84e840000             -call 0x4bbb00
    cpu.esp -= 4;
    sub_4bbb00(app, cpu);
    if (cpu.terminate) return;
    // 004b36b2  83f8ff                 +cmp eax, -1
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
    // 004b36b5  74e3                   -je 0x4b369a
    if (cpu.flags.zf)
    {
        goto L_0x004b369a;
    }
    // 004b36b7  01c1                   +add ecx, eax
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
    // 004b36b9  ebdf                   -jmp 0x4b369a
    goto L_0x004b369a;
L_0x004b36bb:
    // 004b36bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b36bd  eb2a                   -jmp 0x4b36e9
    goto L_0x004b36e9;
L_0x004b36bf:
    // 004b36bf  6626833b00             +cmp word ptr es:[ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b36c4  741d                   -je 0x4b36e3
    if (cpu.flags.zf)
    {
        goto L_0x004b36e3;
    }
    // 004b36c6  39f1                   +cmp ecx, esi
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
    // 004b36c8  7f19                   -jg 0x4b36e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b36e3;
    }
    // 004b36ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b36cc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b36ce  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004b36d2  e829840000             -call 0x4bbb00
    cpu.esp -= 4;
    sub_4bbb00(app, cpu);
    if (cpu.terminate) return;
    // 004b36d7  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b36da  83f8ff                 +cmp eax, -1
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
    // 004b36dd  74e0                   -je 0x4b36bf
    if (cpu.flags.zf)
    {
        goto L_0x004b36bf;
    }
    // 004b36df  01c1                   +add ecx, eax
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
    // 004b36e1  ebdc                   -jmp 0x4b36bf
    goto L_0x004b36bf;
L_0x004b36e3:
    // 004b36e3  39f1                   +cmp ecx, esi
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
    // 004b36e5  7ed4                   -jle 0x4b36bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b36bb;
    }
    // 004b36e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004b36e9:
    // 004b36e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b36ec  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b36ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b36ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b36f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b36f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b36f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b36f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b36f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b36f4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b36f7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b36f9  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b36fc  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b3701  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b3703  e876840000             -call 0x4bbb7e
    cpu.esp -= 4;
    sub_4bbb7e(app, cpu);
    if (cpu.terminate) return;
    // 004b3708  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3709  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b370b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b370d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b370f  49                     -dec ecx
    (cpu.ecx)--;
    // 004b3710  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b3712  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004b3714  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b3716  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b3717  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b3718  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b371b  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004b371d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b371e  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004b3721  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004b3724  eb07                   -jmp 0x4b372d
    goto L_0x004b372d;
L_0x004b3726:
    // 004b3726  4a                     -dec edx
    (cpu.edx)--;
    // 004b3727  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b3729  48                     -dec eax
    (cpu.eax)--;
    // 004b372a  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004b372c  4b                     -dec ebx
    (cpu.ebx)--;
L_0x004b372d:
    // 004b372d  39f2                   +cmp edx, esi
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
    // 004b372f  75f5                   -jne 0x4b3726
    if (!cpu.flags.zf)
    {
        goto L_0x004b3726;
    }
    // 004b3731  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x004b3734:
    // 004b3734  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3736  7c07                   -jl 0x4b373f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b373f;
    }
    // 004b3738  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b3739  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 004b373c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b373d  ebf5                   -jmp 0x4b3734
    goto L_0x004b3734;
L_0x004b373f:
    // 004b373f  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004b3742  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 004b3746  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3749  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b374a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b374b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b374c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b374d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b374e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b374e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b374f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3750  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3751  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3754  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3756  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b3758  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b375b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b375d  7d0b                   -jge 0x4b376a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b376a;
    }
    // 004b375f  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b3761  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3764  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 004b3767  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x004b376a:
    // 004b376a  837e08ff               +cmp dword ptr [esi + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b376e  7507                   -jne 0x4b3777
    if (!cpu.flags.zf)
    {
        goto L_0x004b3777;
    }
    // 004b3770  c7460804000000         -mov dword ptr [esi + 8], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x004b3777:
    // 004b3777  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004b377c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b377e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b3780  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004b3785  e8f4830000             -call 0x4bbb7e
    cpu.esp -= 4;
    sub_4bbb7e(app, cpu);
    if (cpu.terminate) return;
    // 004b378a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004b378c:
    // 004b378c  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b378e  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b3791  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004b3793  7404                   -je 0x4b3799
    if (cpu.flags.zf)
    {
        goto L_0x004b3799;
    }
    // 004b3795  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3797  ebf3                   -jmp 0x4b378c
    goto L_0x004b378c;
L_0x004b3799:
    // 004b3799  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004b379d  742c                   -je 0x4b37cb
    if (cpu.flags.zf)
    {
        goto L_0x004b37cb;
    }
    // 004b379f  c6012e                 -mov byte ptr [ecx], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 004b37a2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b37a4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b37a6  eb1b                   -jmp 0x4b37c3
    goto L_0x004b37c3;
L_0x004b37a8:
    // 004b37a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b37aa  6689542402             -mov word ptr [esp + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004b37af  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b37b2  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b37b5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b37b8  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004b37bc  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b37bf  40                     -inc eax
    (cpu.eax)++;
    // 004b37c0  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004b37c2  41                     -inc ecx
    (cpu.ecx)++;
L_0x004b37c3:
    // 004b37c3  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b37c6  7ce0                   -jl 0x4b37a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b37a8;
    }
    // 004b37c8  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x004b37cb:
    // 004b37cb  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 004b37d0  7450                   -je 0x4b3822
    if (cpu.flags.zf)
    {
        goto L_0x004b3822;
    }
L_0x004b37d2:
    // 004b37d2  39d9                   +cmp ecx, ebx
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
    // 004b37d4  7532                   -jne 0x4b3808
    if (!cpu.flags.zf)
    {
        goto L_0x004b3808;
    }
    // 004b37d6  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b37d9  c60331                 -mov byte ptr [ebx], 0x31
    app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
L_0x004b37dc:
    // 004b37dc  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b37de  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b37e1  80fa30                 +cmp dl, 0x30
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
    // 004b37e4  7504                   -jne 0x4b37ea
    if (!cpu.flags.zf)
    {
        goto L_0x004b37ea;
    }
    // 004b37e6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b37e8  ebf2                   -jmp 0x4b37dc
    goto L_0x004b37dc;
L_0x004b37ea:
    // 004b37ea  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b37ed  7510                   -jne 0x4b37ff
    if (!cpu.flags.zf)
    {
        goto L_0x004b37ff;
    }
    // 004b37ef  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004b37f2  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b37f5  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b37f7:
    // 004b37f7  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b37fa  7503                   -jne 0x4b37ff
    if (!cpu.flags.zf)
    {
        goto L_0x004b37ff;
    }
    // 004b37fc  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b37fd  ebf8                   -jmp 0x4b37f7
    goto L_0x004b37f7;
L_0x004b37ff:
    // 004b37ff  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004b3802  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3803  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 004b3806  eb1a                   -jmp 0x4b3822
    goto L_0x004b3822;
L_0x004b3808:
    // 004b3808  49                     -dec ecx
    (cpu.ecx)--;
    // 004b3809  80392e                 +cmp byte ptr [ecx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b380c  7501                   -jne 0x4b380f
    if (!cpu.flags.zf)
    {
        goto L_0x004b380f;
    }
    // 004b380e  49                     -dec ecx
    (cpu.ecx)--;
L_0x004b380f:
    // 004b380f  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b3811  3c39                   +cmp al, 0x39
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
    // 004b3813  7408                   -je 0x4b381d
    if (cpu.flags.zf)
    {
        goto L_0x004b381d;
    }
    // 004b3815  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004b3817  fec4                   +inc ah
    {
        x86::reg8& tmp = cpu.ah;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004b3819  8821                   -mov byte ptr [ecx], ah
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 004b381b  eb05                   -jmp 0x4b3822
    goto L_0x004b3822;
L_0x004b381d:
    // 004b381d  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004b3820  ebb0                   -jmp 0x4b37d2
    goto L_0x004b37d2;
L_0x004b3822:
    // 004b3822  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3825  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3826  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3827  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3828  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3829(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3829  ff153c074e00           -call dword ptr [0x4e073c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113660) /* 0x4e073c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b382f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3833  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3834  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3835  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3836  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004b383a  7530                   -jne 0x4b386c
    if (!cpu.flags.zf)
    {
        goto L_0x004b386c;
    }
    // 004b383c  80781630               +cmp byte ptr [eax + 0x16], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3840  752a                   -jne 0x4b386c
    if (!cpu.flags.zf)
    {
        goto L_0x004b386c;
    }
    // 004b3842  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b3845  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b3848  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b384b  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b384d  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b3850  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b3852  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004b3855  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b3857  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004b385a  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b385c  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004b385f  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b3861  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b3863  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3865  7e05                   -jle 0x4b386c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b386c;
    }
    // 004b3867  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3869  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x004b386c:
    // 004b386c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b386d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b386e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b386f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3870  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3871  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3872  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3873(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3873  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3874  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3875  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b3876  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3877  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b387a  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b387c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b387e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x004b3880:
    // 004b3880  837b2800               +cmp dword ptr [ebx + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3884  7e3d                   -jle 0x4b38c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b38c3;
    }
    // 004b3886  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3888  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b388a  66268b16               -mov dx, word ptr es:[esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.esi);
    // 004b388e  e86d820000             -call 0x4bbb00
    cpu.esp -= 4;
    sub_4bbb00(app, cpu);
    if (cpu.terminate) return;
    // 004b3893  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b3896  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3898  83f8ff                 +cmp eax, -1
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
    // 004b389b  74e3                   -je 0x4b3880
    if (cpu.flags.zf)
    {
        goto L_0x004b3880;
    }
    // 004b389d  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b38a0  7f1a                   -jg 0x4b38bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b38bc;
    }
    // 004b38a2  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
L_0x004b38a4:
    // 004b38a4  4f                     -dec edi
    (cpu.edi)--;
    // 004b38a5  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b38a8  74d6                   -je 0x4b3880
    if (cpu.flags.zf)
    {
        goto L_0x004b3880;
    }
    // 004b38aa  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b38ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b38ae  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b38b0  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b38b2  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004b38b5  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b38b6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b38b7  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b38ba  ebe8                   -jmp 0x4b38a4
    goto L_0x004b38a4;
L_0x004b38bc:
    // 004b38bc  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x004b38c3:
    // 004b38c3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b38c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38c7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b38c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b38cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b38cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b38cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b38cd  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b38ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b38cf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b38d2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b38d4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b38d6  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b38d8  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b38da  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b38e1  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004b38e8  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004b38ef  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004b38f6  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004b38fd  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b38ff  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004b3902  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004b3909  3c69                   +cmp al, 0x69
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
    // 004b390b  7219                   -jb 0x4b3926
    if (cpu.flags.cf)
    {
        goto L_0x004b3926;
    }
    // 004b390d  0f8686000000           -jbe 0x4b3999
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3999;
    }
    // 004b3913  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3915  720b                   -jb 0x4b3922
    if (cpu.flags.cf)
    {
        goto L_0x004b3922;
    }
    // 004b3917  7620                   -jbe 0x4b3939
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3939;
    }
    // 004b3919  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x004b391b:
    // 004b391b  741c                   -je 0x4b3939
    if (cpu.flags.zf)
    {
        goto L_0x004b3939;
    }
    // 004b391d  e956010000             -jmp 0x4b3a78
    goto L_0x004b3a78;
L_0x004b3922:
    // 004b3922  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3924  ebf5                   -jmp 0x4b391b
    goto L_0x004b391b;
L_0x004b3926:
    // 004b3926  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3928  0f824a010000           -jb 0x4b3a78
    if (cpu.flags.cf)
    {
        goto L_0x004b3a78;
    }
    // 004b392e  7609                   -jbe 0x4b3939
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3939;
    }
    // 004b3930  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3932  7465                   -je 0x4b3999
    if (cpu.flags.zf)
    {
        goto L_0x004b3999;
    }
    // 004b3934  e93f010000             -jmp 0x4b3a78
    goto L_0x004b3a78;
L_0x004b3939:
    // 004b3939  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b393d  7420                   -je 0x4b395f
    if (cpu.flags.zf)
    {
        goto L_0x004b395f;
    }
    // 004b393f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3941  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3944  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b3946  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b3949  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b394c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b394e  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3951  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b3953  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004b3956:
    // 004b3956  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b395a  e919010000             -jmp 0x4b3a78
    goto L_0x004b3a78;
L_0x004b395f:
    // 004b395f  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b3963  7413                   -je 0x4b3978
    if (cpu.flags.zf)
    {
        goto L_0x004b3978;
    }
    // 004b3965  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3967  83c004                 +add eax, 4
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
    // 004b396a  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b396c  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
L_0x004b396f:
    // 004b396f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3973  e900010000             -jmp 0x4b3a78
    goto L_0x004b3a78;
L_0x004b3978:
    // 004b3978  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b397a  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b397d  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b397f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b3982  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3986  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004b398a  0f84e8000000           -je 0x4b3a78
    if (cpu.flags.zf)
    {
        goto L_0x004b3a78;
    }
    // 004b3990  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b3992  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3997  ebd6                   -jmp 0x4b396f
    goto L_0x004b396f;
L_0x004b3999:
    // 004b3999  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b399d  741d                   -je 0x4b39bc
    if (cpu.flags.zf)
    {
        goto L_0x004b39bc;
    }
    // 004b399f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b39a1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b39a4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b39a6  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b39a9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b39ac  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b39ae  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b39b1  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b39b3  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b39b6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b39ba  eb33                   -jmp 0x4b39ef
    goto L_0x004b39ef;
L_0x004b39bc:
    // 004b39bc  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b39c0  740c                   -je 0x4b39ce
    if (cpu.flags.zf)
    {
        goto L_0x004b39ce;
    }
    // 004b39c2  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b39c4  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b39c7  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b39c9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b39cc  eb1d                   -jmp 0x4b39eb
    goto L_0x004b39eb;
L_0x004b39ce:
    // 004b39ce  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b39d0  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b39d3  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b39d5  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b39d8  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b39db  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b39df  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 004b39e2  740b                   -je 0x4b39ef
    if (cpu.flags.zf)
    {
        goto L_0x004b39ef;
    }
    // 004b39e4  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004b39e8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x004b39eb:
    // 004b39eb  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004b39ef:
    // 004b39ef  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004b39f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b39f4  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004b39f7  7409                   -je 0x4b3a02
    if (cpu.flags.zf)
    {
        goto L_0x004b3a02;
    }
    // 004b39f9  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 004b39fe  7409                   -je 0x4b3a09
    if (cpu.flags.zf)
    {
        goto L_0x004b3a09;
    }
    // 004b3a00  eb0b                   -jmp 0x4b3a0d
    goto L_0x004b3a0d;
L_0x004b3a02:
    // 004b3a02  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b3a07  7c04                   -jl 0x4b3a0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3a0d;
    }
L_0x004b3a09:
    // 004b3a09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3a0b  7444                   -je 0x4b3a51
    if (cpu.flags.zf)
    {
        goto L_0x004b3a51;
    }
L_0x004b3a0d:
    // 004b3a0d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3a10  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3a13  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004b3a16  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004b3a1a  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b3a1e  742b                   -je 0x4b3a4b
    if (cpu.flags.zf)
    {
        goto L_0x004b3a4b;
    }
    // 004b3a20  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b3a23  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3a27  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004b3a29  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 004b3a2b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b3a2e  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b3a31  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b3a35  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b3a38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3a3a  7508                   -jne 0x4b3a44
    if (!cpu.flags.zf)
    {
        goto L_0x004b3a44;
    }
    // 004b3a3c  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b3a3f  e912ffffff             -jmp 0x4b3956
    goto L_0x004b3956;
L_0x004b3a44:
    // 004b3a44  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3a46  e90bffffff             -jmp 0x4b3956
    goto L_0x004b3956;
L_0x004b3a4b:
    // 004b3a4b  f75c2408               +neg dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004b3a4f  eb27                   -jmp 0x4b3a78
    goto L_0x004b3a78;
L_0x004b3a51:
    // 004b3a51  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b3a54  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004b3a56  740f                   -je 0x4b3a67
    if (cpu.flags.zf)
    {
        goto L_0x004b3a67;
    }
    // 004b3a58  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3a5b  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3a5e  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004b3a61  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004b3a65  eb11                   -jmp 0x4b3a78
    goto L_0x004b3a78;
L_0x004b3a67:
    // 004b3a67  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004b3a69  740d                   -je 0x4b3a78
    if (cpu.flags.zf)
    {
        goto L_0x004b3a78;
    }
    // 004b3a6b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3a6e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3a71  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004b3a74  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004b3a78:
    // 004b3a78  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b3a7b  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004b3a80  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3a82  7261                   -jb 0x4b3ae5
    if (cpu.flags.cf)
    {
        goto L_0x004b3ae5;
    }
    // 004b3a84  0f86f0010000           -jbe 0x4b3c7a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3c7a;
    }
    // 004b3a8a  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3a8c  7238                   -jb 0x4b3ac6
    if (cpu.flags.cf)
    {
        goto L_0x004b3ac6;
    }
    // 004b3a8e  0f86c6010000           -jbe 0x4b3c5a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3c5a;
    }
    // 004b3a94  3c73                   +cmp al, 0x73
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
    // 004b3a96  7221                   -jb 0x4b3ab9
    if (cpu.flags.cf)
    {
        goto L_0x004b3ab9;
    }
    // 004b3a98  0f86e0000000           -jbe 0x4b3b7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3b7e;
    }
    // 004b3a9e  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3aa0  0f82a2030000           -jb 0x4b3e48
    if (cpu.flags.cf)
    {
        goto L_0x004b3e48;
    }
    // 004b3aa6  0f86ce010000           -jbe 0x4b3c7a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3c7a;
    }
    // 004b3aac  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3aae  0f8463010000           -je 0x4b3c17
    if (cpu.flags.zf)
    {
        goto L_0x004b3c17;
    }
    // 004b3ab4  e98f030000             -jmp 0x4b3e48
    goto L_0x004b3e48;
L_0x004b3ab9:
    // 004b3ab9  3c70                   +cmp al, 0x70
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(112 /*0x70*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x004b3abb:
    // 004b3abb  0f845f020000           -je 0x4b3d20
    if (cpu.flags.zf)
    {
        goto L_0x004b3d20;
    }
    // 004b3ac1  e982030000             -jmp 0x4b3e48
    goto L_0x004b3e48;
L_0x004b3ac6:
    // 004b3ac6  3c66                   +cmp al, 0x66
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(102 /*0x66*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3ac8  0f8294000000           -jb 0x4b3b62
    if (cpu.flags.cf)
    {
        goto L_0x004b3b62;
    }
    // 004b3ace  765d                   -jbe 0x4b3b2d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3b2d;
    }
    // 004b3ad0  3c67                   +cmp al, 0x67
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3ad2  0f868a000000           -jbe 0x4b3b62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3b62;
    }
    // 004b3ad8  3c69                   +cmp al, 0x69
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
    // 004b3ada  0f849a010000           -je 0x4b3c7a
    if (cpu.flags.zf)
    {
        goto L_0x004b3c7a;
    }
    // 004b3ae0  e963030000             -jmp 0x4b3e48
    goto L_0x004b3e48;
L_0x004b3ae5:
    // 004b3ae5  3c47                   +cmp al, 0x47
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(71 /*0x47*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3ae7  722f                   -jb 0x4b3b18
    if (cpu.flags.cf)
    {
        goto L_0x004b3b18;
    }
    // 004b3ae9  0f8673000000           -jbe 0x4b3b62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3b62;
    }
    // 004b3aef  3c53                   +cmp al, 0x53
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3af1  7221                   -jb 0x4b3b14
    if (cpu.flags.cf)
    {
        goto L_0x004b3b14;
    }
    // 004b3af3  0f8685000000           -jbe 0x4b3b7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3b7e;
    }
    // 004b3af9  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3afb  0f8247030000           -jb 0x4b3e48
    if (cpu.flags.cf)
    {
        goto L_0x004b3e48;
    }
    // 004b3b01  0f8610010000           -jbe 0x4b3c17
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3c17;
    }
    // 004b3b07  3c63                   +cmp al, 0x63
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
    // 004b3b09  0f849d020000           -je 0x4b3dac
    if (cpu.flags.zf)
    {
        goto L_0x004b3dac;
    }
    // 004b3b0f  e934030000             -jmp 0x4b3e48
    goto L_0x004b3e48;
L_0x004b3b14:
    // 004b3b14  3c50                   +cmp al, 0x50
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3b16  eba3                   -jmp 0x4b3abb
    goto L_0x004b3abb;
L_0x004b3b18:
    // 004b3b18  3c45                   +cmp al, 0x45
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3b1a  7204                   -jb 0x4b3b20
    if (cpu.flags.cf)
    {
        goto L_0x004b3b20;
    }
    // 004b3b1c  7644                   -jbe 0x4b3b62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3b62;
    }
    // 004b3b1e  eb0d                   -jmp 0x4b3b2d
    goto L_0x004b3b2d;
L_0x004b3b20:
    // 004b3b20  3c43                   +cmp al, 0x43
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3b22  0f84f4020000           -je 0x4b3e1c
    if (cpu.flags.zf)
    {
        goto L_0x004b3e1c;
    }
    // 004b3b28  e91b030000             -jmp 0x4b3e48
    goto L_0x004b3e48;
L_0x004b3b2d:
    // 004b3b2d  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004b3b31  742f                   -je 0x4b3b62
    if (cpu.flags.zf)
    {
        goto L_0x004b3b62;
    }
    // 004b3b33  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3b35  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3b38  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b3b3a  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b3b3d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3b41  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b3b43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3b45  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3b47  e802fcffff             -call 0x4b374e
    cpu.esp -= 4;
    sub_4b374e(app, cpu);
    if (cpu.terminate) return;
    // 004b3b4c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004b3b51  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b3b53  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3b55  e809fbffff             -call 0x4b3663
    cpu.esp -= 4;
    sub_4b3663(app, cpu);
    if (cpu.terminate) return;
    // 004b3b5a  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b3b5d  e9f9020000             -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3b62:
    // 004b3b62  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b3b64  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3b66  e8befcffff             -call 0x4b3829
    cpu.esp -= 4;
    sub_4b3829(app, cpu);
    if (cpu.terminate) return;
    // 004b3b6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3b6d  e8befcffff             -call 0x4b3830
    cpu.esp -= 4;
    sub_4b3830(app, cpu);
    if (cpu.terminate) return;
    // 004b3b72  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b3b74  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b3b77  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b3b79  e9dd020000             -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3b7e:
    // 004b3b7e  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004b3b81  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b3b84  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004b3b86  741d                   -je 0x4b3ba5
    if (cpu.flags.zf)
    {
        goto L_0x004b3ba5;
    }
    // 004b3b88  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3b8a  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3b8d  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b3b8f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004b3b92  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b3b96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3b98  7505                   -jne 0x4b3b9f
    if (!cpu.flags.zf)
    {
        goto L_0x004b3b9f;
    }
    // 004b3b9a  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004b3b9d  742e                   -je 0x4b3bcd
    if (cpu.flags.zf)
    {
        goto L_0x004b3bcd;
    }
L_0x004b3b9f:
    // 004b3b9f  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b3ba1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3ba3  eb28                   -jmp 0x4b3bcd
    goto L_0x004b3bcd;
L_0x004b3ba5:
    // 004b3ba5  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004b3ba7  7410                   -je 0x4b3bb9
    if (cpu.flags.zf)
    {
        goto L_0x004b3bb9;
    }
    // 004b3ba9  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3bab  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3bae  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004b3bb0  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004b3bb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3bb5  7416                   -je 0x4b3bcd
    if (cpu.flags.zf)
    {
        goto L_0x004b3bcd;
    }
    // 004b3bb7  eb0e                   -jmp 0x4b3bc7
    goto L_0x004b3bc7;
L_0x004b3bb9:
    // 004b3bb9  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3bbb  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3bbe  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b3bc0  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b3bc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3bc5  7406                   -je 0x4b3bcd
    if (cpu.flags.zf)
    {
        goto L_0x004b3bcd;
    }
L_0x004b3bc7:
    // 004b3bc7  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b3bc9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3bcb  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x004b3bcd:
    // 004b3bcd  80791553               +cmp byte ptr [ecx + 0x15], 0x53
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3bd1  7514                   -jne 0x4b3be7
    if (!cpu.flags.zf)
    {
        goto L_0x004b3be7;
    }
    // 004b3bd3  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004b3bd7  7514                   -jne 0x4b3bed
    if (!cpu.flags.zf)
    {
        goto L_0x004b3bed;
    }
L_0x004b3bd9:
    // 004b3bd9  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b3bdb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3bdd  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3be0  e8a2faffff             -call 0x4b3687
    cpu.esp -= 4;
    sub_4b3687(app, cpu);
    if (cpu.terminate) return;
    // 004b3be5  eb12                   -jmp 0x4b3bf9
    goto L_0x004b3bf9;
L_0x004b3be7:
    // 004b3be7  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b3beb  75ec                   -jne 0x4b3bd9
    if (!cpu.flags.zf)
    {
        goto L_0x004b3bd9;
    }
L_0x004b3bed:
    // 004b3bed  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b3bef  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3bf1  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3bf4  e86afaffff             -call 0x4b3663
    cpu.esp -= 4;
    sub_4b3663(app, cpu);
    if (cpu.terminate) return;
L_0x004b3bf9:
    // 004b3bf9  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3bfc  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b3bff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b3c01  0f8c54020000           -jl 0x4b3e5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3e5b;
    }
    // 004b3c07  39d0                   +cmp eax, edx
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
    // 004b3c09  0f8e4c020000           -jle 0x4b3e5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3e5b;
    }
    // 004b3c0f  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b3c12  e944020000             -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3c17:
    // 004b3c17  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004b3c1b  7438                   -je 0x4b3c55
    if (cpu.flags.zf)
    {
        goto L_0x004b3c55;
    }
    // 004b3c1d  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b3c21  740f                   -je 0x4b3c32
    if (cpu.flags.zf)
    {
        goto L_0x004b3c32;
    }
    // 004b3c23  833c2400               +cmp dword ptr [esp], 0
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
    // 004b3c27  7510                   -jne 0x4b3c39
    if (!cpu.flags.zf)
    {
        goto L_0x004b3c39;
    }
    // 004b3c29  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004b3c2e  7425                   -je 0x4b3c55
    if (cpu.flags.zf)
    {
        goto L_0x004b3c55;
    }
    // 004b3c30  eb07                   -jmp 0x4b3c39
    goto L_0x004b3c39;
L_0x004b3c32:
    // 004b3c32  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b3c37  741c                   -je 0x4b3c55
    if (cpu.flags.zf)
    {
        goto L_0x004b3c55;
    }
L_0x004b3c39:
    // 004b3c39  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3c3c  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3c3f  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b3c42  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 004b3c46  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3c49  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3c4c  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b3c4f  8a5115                 -mov dl, byte ptr [ecx + 0x15]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b3c52  881406                 -mov byte ptr [esi + eax], dl
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dl;
L_0x004b3c55:
    // 004b3c55  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004b3c5a:
    // 004b3c5a  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3c5e  751a                   -jne 0x4b3c7a
    if (!cpu.flags.zf)
    {
        goto L_0x004b3c7a;
    }
    // 004b3c60  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b3c63  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004b3c68  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004b3c6b  740d                   -je 0x4b3c7a
    if (cpu.flags.zf)
    {
        goto L_0x004b3c7a;
    }
    // 004b3c6d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3c70  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b3c73  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b3c76  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x004b3c7a:
    // 004b3c7a  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b3c7c  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3c7f  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b3c81  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b3c83  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004b3c86  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3c88  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004b3c8b  7436                   -je 0x4b3cc3
    if (cpu.flags.zf)
    {
        goto L_0x004b3cc3;
    }
    // 004b3c8d  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3c91  7515                   -jne 0x4b3ca8
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ca8;
    }
    // 004b3c93  833c2400               +cmp dword ptr [esp], 0
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
    // 004b3c97  750f                   -jne 0x4b3ca8
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ca8;
    }
    // 004b3c99  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004b3c9e  7508                   -jne 0x4b3ca8
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ca8;
    }
L_0x004b3ca0:
    // 004b3ca0  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 004b3ca4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b3ca6  eb51                   -jmp 0x4b3cf9
    goto L_0x004b3cf9;
L_0x004b3ca8:
    // 004b3ca8  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3cab  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b3cad  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b3caf  e8e57e0000             -call 0x4bbb99
    cpu.esp -= 4;
    sub_4bbb99(app, cpu);
    if (cpu.terminate) return;
    // 004b3cb4  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3cb8  7531                   -jne 0x4b3ceb
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ceb;
    }
    // 004b3cba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3cbc  e8a6010000             -call 0x4b3e67
    cpu.esp -= 4;
    sub_4b3e67(app, cpu);
    if (cpu.terminate) return;
    // 004b3cc1  eb28                   -jmp 0x4b3ceb
    goto L_0x004b3ceb;
L_0x004b3cc3:
    // 004b3cc3  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3cc7  7507                   -jne 0x4b3cd0
    if (!cpu.flags.zf)
    {
        goto L_0x004b3cd0;
    }
    // 004b3cc9  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b3cce  74d0                   -je 0x4b3ca0
    if (cpu.flags.zf)
    {
        goto L_0x004b3ca0;
    }
L_0x004b3cd0:
    // 004b3cd0  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b3cd3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3cd7  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b3cd9  e8a87f0000             -call 0x4bbc86
    cpu.esp -= 4;
    sub_4bbc86(app, cpu);
    if (cpu.terminate) return;
    // 004b3cde  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3ce2  7507                   -jne 0x4b3ceb
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ceb;
    }
    // 004b3ce4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3ce6  e87c010000             -call 0x4b3e67
    cpu.esp -= 4;
    sub_4b3e67(app, cpu);
    if (cpu.terminate) return;
L_0x004b3ceb:
    // 004b3ceb  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004b3cf0  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b3cf2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3cf4  e86af9ffff             -call 0x4b3663
    cpu.esp -= 4;
    sub_4b3663(app, cpu);
    if (cpu.terminate) return;
L_0x004b3cf9:
    // 004b3cf9  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b3cfc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3cfe  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3d01  39c2                   +cmp edx, eax
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
    // 004b3d03  7d05                   -jge 0x4b3d0a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b3d0a;
    }
    // 004b3d05  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3d07  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004b3d0a:
    // 004b3d0a  837908ff               +cmp dword ptr [ecx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3d0e  0f8547010000           -jne 0x4b3e5b
    if (!cpu.flags.zf)
    {
        goto L_0x004b3e5b;
    }
    // 004b3d14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3d16  e815fbffff             -call 0x4b3830
    cpu.esp -= 4;
    sub_4b3830(app, cpu);
    if (cpu.terminate) return;
    // 004b3d1b  e93b010000             -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3d20:
    // 004b3d20  83790400               +cmp dword ptr [ecx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3d24  7516                   -jne 0x4b3d3c
    if (!cpu.flags.zf)
    {
        goto L_0x004b3d3c;
    }
    // 004b3d26  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 004b3d2a  7409                   -je 0x4b3d35
    if (cpu.flags.zf)
    {
        goto L_0x004b3d35;
    }
    // 004b3d2c  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 004b3d33  eb07                   -jmp 0x4b3d3c
    goto L_0x004b3d3c;
L_0x004b3d35:
    // 004b3d35  c7410408000000         -mov dword ptr [ecx + 4], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x004b3d3c:
    // 004b3d3c  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004b3d40  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3d42  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3d45  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b3d47  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b3d4a  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b3d4d  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004b3d50  7429                   -je 0x4b3d7b
    if (cpu.flags.zf)
    {
        goto L_0x004b3d7b;
    }
    // 004b3d52  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3d55  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b3d57  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004b3d5c  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b3d5f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b3d61  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004b3d66  e885f9ffff             -call 0x4b36f0
    cpu.esp -= 4;
    sub_4b36f0(app, cpu);
    if (cpu.terminate) return;
    // 004b3d6b  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004b3d70  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 004b3d73  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b3d75  c646043a               -mov byte ptr [esi + 4], 0x3a
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 004b3d79  eb09                   -jmp 0x4b3d84
    goto L_0x004b3d84;
L_0x004b3d7b:
    // 004b3d7b  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004b3d80  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b3d82  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004b3d84:
    // 004b3d84  e867f9ffff             -call 0x4b36f0
    cpu.esp -= 4;
    sub_4b36f0(app, cpu);
    if (cpu.terminate) return;
    // 004b3d89  80791550               +cmp byte ptr [ecx + 0x15], 0x50
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3d8d  7507                   -jne 0x4b3d96
    if (!cpu.flags.zf)
    {
        goto L_0x004b3d96;
    }
    // 004b3d8f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3d91  e8d1000000             -call 0x4b3e67
    cpu.esp -= 4;
    sub_4b3e67(app, cpu);
    if (cpu.terminate) return;
L_0x004b3d96:
    // 004b3d96  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004b3d9b  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b3d9d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3d9f  e8bff8ffff             -call 0x4b3663
    cpu.esp -= 4;
    sub_4b3663(app, cpu);
    if (cpu.terminate) return;
L_0x004b3da4:
    // 004b3da4  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004b3da7  e9af000000             -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3dac:
    // 004b3dac  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b3daf  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004b3db6  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004b3db9  7453                   -je 0x4b3e0e
    if (cpu.flags.zf)
    {
        goto L_0x004b3e0e;
    }
    // 004b3dbb  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3dbd  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3dc0  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b3dc2  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b3dc6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3dc8  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 004b3dcb  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3dcf  e82c7d0000             -call 0x4bbb00
    cpu.esp -= 4;
    sub_4bbb00(app, cpu);
    if (cpu.terminate) return;
    // 004b3dd4  83f8ff                 +cmp eax, -1
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
    // 004b3dd7  0f847e000000           -je 0x4b3e5b
    if (cpu.flags.zf)
    {
        goto L_0x004b3e5b;
    }
    // 004b3ddd  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3de1  8b2dd0a35b00           -mov ebp, dword ptr [0x5ba3d0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
    // 004b3de7  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b3de9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b3deb  746e                   -je 0x4b3e5b
    if (cpu.flags.zf)
    {
        goto L_0x004b3e5b;
    }
    // 004b3ded  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3def  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3df3  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004b3df9  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b3dfb  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b3e00  7459                   -je 0x4b3e5b
    if (cpu.flags.zf)
    {
        goto L_0x004b3e5b;
    }
    // 004b3e02  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 004b3e06  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004b3e09  ff4120                 +inc dword ptr [ecx + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3e0c  eb4d                   -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3e0e:
    // 004b3e0e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3e10  83c004                 +add eax, 4
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
    // 004b3e13  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b3e15  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b3e18  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b3e1a  eb3f                   -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3e1c:
    // 004b3e1c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b3e1e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3e21  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b3e23  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b3e27  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b3e2d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b3e2f  e8cc7c0000             -call 0x4bbb00
    cpu.esp -= 4;
    sub_4bbb00(app, cpu);
    if (cpu.terminate) return;
    // 004b3e34  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3e36  83f8ff                 +cmp eax, -1
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
    // 004b3e39  0f8565ffffff           -jne 0x4b3da4
    if (!cpu.flags.zf)
    {
        goto L_0x004b3da4;
    }
    // 004b3e3f  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b3e46  eb13                   -jmp 0x4b3e5b
    goto L_0x004b3e5b;
L_0x004b3e48:
    // 004b3e48  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b3e4f  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b3e52  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b3e54  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x004b3e5b:
    // 004b3e5b  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b3e5d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3e5f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3e62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e63  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b3e64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3e67(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3e67  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3e68  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b3e6a:
    // 004b3e6a  803a00                 +cmp byte ptr [edx], 0
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
    // 004b3e6d  740e                   -je 0x4b3e7d
    if (cpu.flags.zf)
    {
        goto L_0x004b3e7d;
    }
    // 004b3e6f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b3e71  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b3e73  e8aa26fdff             -call 0x486522
    cpu.esp -= 4;
    sub_486522(app, cpu);
    if (cpu.terminate) return;
    // 004b3e78  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004b3e7a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b3e7b  ebed                   -jmp 0x4b3e6a
    goto L_0x004b3e6a;
L_0x004b3e7d:
    // 004b3e7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b3e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3e80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3e81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3e83  3d00000100             +cmp eax, 0x10000
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
    // 004b3e88  7f1b                   -jg 0x4b3ea5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3ea5;
    }
    // 004b3e8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b3e8c  7c1e                   -jl 0x4b3eac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3eac;
    }
L_0x004b3e8e:
    // 004b3e8e  e8e141fdff             -call 0x488074
    cpu.esp -= 4;
    sub_488074(app, cpu);
    if (cpu.terminate) return;
    // 004b3e93  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 004b3e98  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004b3e9d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b3ea0  c1f80e                 +sar eax, 0xe
    {
        x86::reg8 tmp = 14 /*0xe*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004b3ea3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ea4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3ea5:
    // 004b3ea5  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 004b3eaa  ebe2                   -jmp 0x4b3e8e
    goto L_0x004b3e8e;
L_0x004b3eac:
    // 004b3eac  31c2                   +xor edx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b3eae  ebde                   -jmp 0x4b3e8e
    goto L_0x004b3e8e;
}

/* align: skip  */
void Application::sub_4b3eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3eb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b3eb2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3eb2  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 004b3eb4  9b                     -wait 
    /*nothing*/;
    // 004b3eb5  dbe3                   +fninit 
    cpu.fpu.init();
    // 004b3eb7  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004b3eb9  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004b3ebb  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3ebd  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b3ebf  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004b3ec1  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004b3ec3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004b3ec5  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 004b3ec7  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004b3ec8  7402                   -je 0x4b3ecc
    if (cpu.flags.zf)
    {
        goto L_0x004b3ecc;
    }
    // 004b3eca  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x004b3ecc:
    // 004b3ecc  9b                     -wait 
    /*nothing*/;
    // 004b3ecd  dbe3                   -fninit 
    cpu.fpu.init();
    // 004b3ecf  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b3ed2  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 004b3ed6  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b3ed8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b3ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b3ee0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3ee1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3ee2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3ee3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3ee4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b3ee7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b3ee9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b3eeb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b3eed  3b054cb24d00           +cmp eax, dword ptr [0x4db24c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3ef3  7c49                   -jl 0x4b3f3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3f3e;
    }
    // 004b3ef5  3b0554b24d00           +cmp eax, dword ptr [0x4db254]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3efb  7d41                   -jge 0x4b3f3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b3f3e;
    }
    // 004b3efd  3b3550b24d00           +cmp esi, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3f03  7c39                   -jl 0x4b3f3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3f3e;
    }
    // 004b3f05  3b3558b24d00           +cmp esi, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3f0b  7d31                   -jge 0x4b3f3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b3f3e;
    }
    // 004b3f0d  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3f14  7509                   -jne 0x4b3f1f
    if (!cpu.flags.zf)
    {
        goto L_0x004b3f1f;
    }
    // 004b3f16  803d5eb24d0000         +cmp byte ptr [0x4db25e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091934) /* 0x4db25e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3f1d  7427                   -je 0x4b3f46
    if (cpu.flags.zf)
    {
        goto L_0x004b3f46;
    }
L_0x004b3f1f:
    // 004b3f1f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b3f21  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 004b3f24  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3f2a  81fbff000000           +cmp ebx, 0xff
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
    // 004b3f30  0f84ae000000           -je 0x4b3fe4
    if (cpu.flags.zf)
    {
        goto L_0x004b3fe4;
    }
    // 004b3f36  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b3f38  0f85c0000000           -jne 0x4b3ffe
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ffe;
    }
L_0x004b3f3e:
    // 004b3f3e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b3f41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3f45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3f46:
    // 004b3f46  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b3f48  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3f4a  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004b3f50  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004b3f53  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004b3f59  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004b3f5c  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004b3f62  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b3f64  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3f66  81fb00000010           +cmp ebx, 0x10000000
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
    // 004b3f6c  726b                   -jb 0x4b3fd9
    if (cpu.flags.cf)
    {
        goto L_0x004b3fd9;
    }
    // 004b3f6e  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004b3f74  7340                   -jae 0x4b3fb6
    if (!cpu.flags.cf)
    {
        goto L_0x004b3fb6;
    }
    // 004b3f76  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004b3f79  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b3f7b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3f7d  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004b3f80  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b3f83  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004b3f85  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004b3f8b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b3f8e  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004b3f93  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004b3f96  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3f98  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004b3f9a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b3f9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b3f9f  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004b3fa2  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3fa4  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004b3fa7  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b3fad  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004b3fb2  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b3fb4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b3fb6:
    // 004b3fb6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b3fb8  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004b3fbe  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004b3fc1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b3fc3  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b3fc6  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004b3fcc  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004b3fcf  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004b3fd2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3fd4  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b3fd6  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004b3fd9:
    // 004b3fd9  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b3fdc  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b3fdf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3fe0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3fe1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3fe2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3fe3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3fe4:
    // 004b3fe4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3fe6  e881e6fcff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004b3feb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b3fed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3fef  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b3ff1  e87a98ffff             -call 0x4ad870
    cpu.esp -= 4;
    sub_4ad870(app, cpu);
    if (cpu.terminate) return;
    // 004b3ff6  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b3ff9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ffa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ffb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ffc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ffd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3ffe:
    // 004b3ffe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4000  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4003  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4008  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b400b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b400d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004b4010  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4016  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b401b  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b401f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4023  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b4025  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 004b402a  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b402d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b402f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b4031  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b4033  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b4035  e89628ffff             -call 0x4a68d0
    cpu.esp -= 4;
    sub_4a68d0(app, cpu);
    if (cpu.terminate) return;
    // 004b403a  e8a172feff             -call 0x49b2e0
    cpu.esp -= 4;
    sub_49b2e0(app, cpu);
    if (cpu.terminate) return;
    // 004b403f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4041  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b4044  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b404a  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b404e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4050  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b4052  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004b4055  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b405a  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4060  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b4064  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b4068  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004b406d  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004b4072  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4074  2b442414               -sub eax, dword ptr [esp + 0x14]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b4078  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004b407b  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004b4080  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4082  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4085  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4087  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b4089  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004b408c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b408e  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4094  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b4098  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b409a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b409c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b409e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b40a1  c1e810                 +shr eax, 0x10
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
    // 004b40a4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b40a6  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004b40a9  39d8                   +cmp eax, ebx
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
    // 004b40ab  0f8e77000000           -jle 0x4b4128
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4128;
    }
    // 004b40b1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004b40b3:
    // 004b40b3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b40b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b40b7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b40bb  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b40bf  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b40c1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b40c4  c1e810                 +shr eax, 0x10
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
    // 004b40c7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b40c9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b40cb  3dff000000             +cmp eax, 0xff
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
    // 004b40d0  7e6e                   -jle 0x4b4140
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4140;
    }
    // 004b40d2  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004b40d7:
    // 004b40d7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b40d9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b40db  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b40df  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b40e1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b40e4  c1e810                 +shr eax, 0x10
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
    // 004b40e7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b40e9  03442404               -add eax, dword ptr [esp + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b40ed  3dff000000             +cmp eax, 0xff
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
    // 004b40f2  7e60                   -jle 0x4b4154
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4154;
    }
    // 004b40f4  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004b40f9:
    // 004b40f9  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b40fd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b40ff  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 004b4102  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004b4105  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4107  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b4109  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b410c  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b410e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4110  e857e5fcff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004b4115  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4117  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b4119  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b411b  e85097ffff             -call 0x4ad870
    cpu.esp -= 4;
    sub_4ad870(app, cpu);
    if (cpu.terminate) return;
    // 004b4120  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b4123  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4124  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4125  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4126  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4127  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4128:
    // 004b4128  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b412a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b412c  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b412f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b4131  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b4134  c1e810                 +shr eax, 0x10
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
    // 004b4137  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b4139  01d8                   +add eax, ebx
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
    // 004b413b  e973ffffff             -jmp 0x4b40b3
    goto L_0x004b40b3;
L_0x004b4140:
    // 004b4140  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4144  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b4146  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b4148  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b414b  c1e810                 +shr eax, 0x10
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
    // 004b414e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b4150  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b4152  eb83                   -jmp 0x4b40d7
    goto L_0x004b40d7;
L_0x004b4154:
    // 004b4154  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4158  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b415a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b415e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b4160  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b4163  c1e810                 +shr eax, 0x10
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
    // 004b4166  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b4168  01c8                   +add eax, ecx
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
    // 004b416a  eb8d                   -jmp 0x4b40f9
    goto L_0x004b40f9;
}

/* align: skip  */
void Application::sub_4b416c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b416c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b416d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b416e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b416f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4170  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4175  0f8efb000000           -jle 0x4b4276
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4276;
    }
    // 004b417b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b417d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b417f  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b4183  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b4187  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b418b  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b418f  83f901                 +cmp ecx, 1
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
    // 004b4192  0f8cde000000           -jl 0x4b4276
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b4276;
    }
    // 004b4198  d1e9                   +shr ecx, 1
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
    // 004b419a  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004b419e  7259                   -jb 0x4b41f9
    if (cpu.flags.cf)
    {
        goto L_0x004b41f9;
    }
L_0x004b41a0:
    // 004b41a0  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x004b41a4:
    // 004b41a4  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b41a7  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b41aa  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b41ad  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004b41b0  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b41b3  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b41b6  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b41ba  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b41be  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b41c1  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b41c3  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b41c5  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b41c7  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b41ca  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b41cd  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b41d0  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b41d4  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b41d8  83e901                 +sub ecx, 1
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
    // 004b41db  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b41dd  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b41e0  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004b41e3  7fbf                   -jg 0x4b41a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b41a4;
    }
    // 004b41e5  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b41e9  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b41ed  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b41f2  75ac                   -jne 0x4b41a0
    if (!cpu.flags.zf)
    {
        goto L_0x004b41a0;
    }
    // 004b41f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b41f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b41f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b41f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b41f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b41f9:
    // 004b41f9  8344242801             -add dword ptr [esp + 0x28], 1
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b41fe  8344242c02             -add dword ptr [esp + 0x2c], 2
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b4203:
    // 004b4203  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b4207  83f900                 +cmp ecx, 0
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
    // 004b420a  7441                   -je 0x4b424d
    if (cpu.flags.zf)
    {
        goto L_0x004b424d;
    }
L_0x004b420c:
    // 004b420c  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b420f  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b4212  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b4215  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004b4218  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b421b  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b421e  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b4222  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b4226  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b4229  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b422b  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b422d  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b422f  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b4232  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b4235  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b4238  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b423c  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b4240  83e901                 +sub ecx, 1
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
    // 004b4243  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b4245  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b4248  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004b424b  7fbf                   -jg 0x4b420c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b420c;
    }
L_0x004b424d:
    // 004b424d  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b424f  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b4251  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b4254  88fe                   -mov dh, bh
    cpu.dh = cpu.bh;
    // 004b4256  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b4259  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b425c  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b4260  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b4264  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004b4267  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b426b  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b426f  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b4274  758d                   -jne 0x4b4203
    if (!cpu.flags.zf)
    {
        goto L_0x004b4203;
    }
L_0x004b4276:
    // 004b4276  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4277  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4278  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4279  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b427a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b4280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4281  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4282  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4283  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4284  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b4286  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4288  0f849a000000           -je 0x4b4328
    if (cpu.flags.zf)
    {
        goto L_0x004b4328;
    }
    // 004b428e  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004b4291  39c1                   +cmp ecx, eax
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
    // 004b4293  0f828f000000           -jb 0x4b4328
    if (cpu.flags.cf)
    {
        goto L_0x004b4328;
    }
    // 004b4299  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b429b  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b429e  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004b42a1  83f910                 +cmp ecx, 0x10
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
    // 004b42a4  7305                   -jae 0x4b42ab
    if (!cpu.flags.cf)
    {
        goto L_0x004b42ab;
    }
    // 004b42a6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x004b42ab:
    // 004b42ab  39c1                   +cmp ecx, eax
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
    // 004b42ad  0f8775000000           -ja 0x4b4328
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b4328;
    }
    // 004b42b3  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004b42b6  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004b42b9  39d9                   +cmp ecx, ebx
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
    // 004b42bb  7705                   -ja 0x4b42c2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b42c2;
    }
    // 004b42bd  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004b42c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b42c2:
    // 004b42c2  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x004b42c5:
    // 004b42c5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b42c7  39d1                   +cmp ecx, edx
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
    // 004b42c9  7612                   -jbe 0x4b42dd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b42dd;
    }
    // 004b42cb  39da                   +cmp edx, ebx
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
    // 004b42cd  7602                   -jbe 0x4b42d1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b42d1;
    }
    // 004b42cf  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004b42d1:
    // 004b42d1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b42d4  39f0                   +cmp eax, esi
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
    // 004b42d6  75ed                   -jne 0x4b42c5
    if (!cpu.flags.zf)
    {
        goto L_0x004b42c5;
    }
    // 004b42d8  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004b42db  eb4b                   -jmp 0x4b4328
    goto L_0x004b4328;
L_0x004b42dd:
    // 004b42dd  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004b42e0  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004b42e3  43                     -inc ebx
    (cpu.ebx)++;
    // 004b42e4  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b42e6  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004b42e9  83fa10                 +cmp edx, 0x10
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
    // 004b42ec  721e                   -jb 0x4b430c
    if (cpu.flags.cf)
    {
        goto L_0x004b430c;
    }
    // 004b42ee  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004b42f1  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b42f4  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b42f6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004b42f8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b42fb  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b42fe  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b4301  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b4304  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b4307  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b430a  eb12                   -jmp 0x4b431e
    goto L_0x004b431e;
L_0x004b430c:
    // 004b430c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 004b430f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b4312  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b4315  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b4318  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b431b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004b431e:
    // 004b431e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4320  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b4323  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b4326  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b4328:
    // 004b4328  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b432a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b432b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b432c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b432d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b432e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b4330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4330  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4331  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4332  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4333  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4334  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b4336  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4338  0f841d010000           -je 0x4b445b
    if (cpu.flags.zf)
    {
        goto L_0x004b445b;
    }
    // 004b433e  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b4341  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 004b4344  0f8411010000           -je 0x4b445b
    if (cpu.flags.zf)
    {
        goto L_0x004b445b;
    }
    // 004b434a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b434c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004b434f  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004b4352  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b4354  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 004b4357  7522                   -jne 0x4b437b
    if (!cpu.flags.zf)
    {
        goto L_0x004b437b;
    }
    // 004b4359  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b435b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b435d  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b435f  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4362  7503                   -jne 0x4b4367
    if (!cpu.flags.zf)
    {
        goto L_0x004b4367;
    }
    // 004b4364  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004b4367:
    // 004b4367  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b436a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b436d  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4370  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b4373  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4376  e994000000             -jmp 0x4b440f
    goto L_0x004b440f;
L_0x004b437b:
    // 004b437b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b437d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b4380  39c3                   +cmp ebx, eax
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
    // 004b4382  7316                   -jae 0x4b439a
    if (!cpu.flags.cf)
    {
        goto L_0x004b439a;
    }
    // 004b4384  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 004b4387  0f8782000000           -ja 0x4b440f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b440f;
    }
    // 004b438d  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004b4390  39c3                   +cmp ebx, eax
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
    // 004b4392  0f8277000000           -jb 0x4b440f
    if (cpu.flags.cf)
    {
        goto L_0x004b440f;
    }
    // 004b4398  eb19                   -jmp 0x4b43b3
    goto L_0x004b43b3;
L_0x004b439a:
    // 004b439a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b439d  39c3                   +cmp ebx, eax
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
    // 004b439f  0f826a000000           -jb 0x4b440f
    if (cpu.flags.cf)
    {
        goto L_0x004b440f;
    }
    // 004b43a5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b43a8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b43ab  39d3                   +cmp ebx, edx
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
    // 004b43ad  0f875c000000           -ja 0x4b440f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b440f;
    }
L_0x004b43b3:
    // 004b43b3  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004b43b6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b43b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b43bb  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b43be  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b43c0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b43c2  39f8                   +cmp eax, edi
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
    // 004b43c4  7328                   -jae 0x4b43ee
    if (!cpu.flags.cf)
    {
        goto L_0x004b43ee;
    }
    // 004b43c6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b43c9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b43cb  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b43cd  39f8                   +cmp eax, edi
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
    // 004b43cf  7705                   -ja 0x4b43d6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b43d6;
    }
    // 004b43d1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x004b43d6:
    // 004b43d6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b43d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b43da:
    // 004b43da  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b43dc  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004b43df  742e                   -je 0x4b440f
    if (cpu.flags.zf)
    {
        goto L_0x004b440f;
    }
    // 004b43e1  83faff                 +cmp edx, -1
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
    // 004b43e4  7408                   -je 0x4b43ee
    if (cpu.flags.zf)
    {
        goto L_0x004b43ee;
    }
    // 004b43e6  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004b43e9  01d0                   +add eax, edx
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
    // 004b43eb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b43ec  75ec                   -jne 0x4b43da
    if (!cpu.flags.zf)
    {
        goto L_0x004b43da;
    }
L_0x004b43ee:
    // 004b43ee  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b43f1  39c3                   +cmp ebx, eax
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
    // 004b43f3  7303                   -jae 0x4b43f8
    if (!cpu.flags.cf)
    {
        goto L_0x004b43f8;
    }
    // 004b43f5  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x004b43f8:
    // 004b43f8  39c3                   +cmp ebx, eax
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
    // 004b43fa  7213                   -jb 0x4b440f
    if (cpu.flags.cf)
    {
        goto L_0x004b440f;
    }
    // 004b43fc  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b43ff  39c3                   +cmp ebx, eax
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
    // 004b4401  720c                   -jb 0x4b440f
    if (cpu.flags.cf)
    {
        goto L_0x004b440f;
    }
    // 004b4403  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b4406  39c3                   +cmp ebx, eax
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
    // 004b4408  7205                   -jb 0x4b440f
    if (cpu.flags.cf)
    {
        goto L_0x004b440f;
    }
    // 004b440a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b440d  ebe9                   -jmp 0x4b43f8
    goto L_0x004b43f8;
L_0x004b440f:
    // 004b440f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b4412  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b4414  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4416  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4418  39df                   +cmp edi, ebx
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
    // 004b441a  7512                   -jne 0x4b442e
    if (!cpu.flags.zf)
    {
        goto L_0x004b442e;
    }
    // 004b441c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b441e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b4420  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004b4422  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4425  7503                   -jne 0x4b442a
    if (!cpu.flags.zf)
    {
        goto L_0x004b442a;
    }
    // 004b4427  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004b442a:
    // 004b442a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b442c  eb0f                   -jmp 0x4b443d
    goto L_0x004b443d;
L_0x004b442e:
    // 004b442e  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 004b4431  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4434  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b4437  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b443a  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004b443d:
    // 004b443d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b4440  4a                     -dec edx
    (cpu.edx)--;
    // 004b4441  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b4444  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b4447  39fb                   +cmp ebx, edi
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
    // 004b4449  7308                   -jae 0x4b4453
    if (!cpu.flags.cf)
    {
        goto L_0x004b4453;
    }
    // 004b444b  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b444e  7603                   -jbe 0x4b4453
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4453;
    }
    // 004b4450  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004b4453:
    // 004b4453  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4456  7603                   -jbe 0x4b445b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b445b;
    }
    // 004b4458  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004b445b:
    // 004b445b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b445c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b445d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b445e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b445f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4460  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4461  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4462  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4464  a138db4d00             -mov eax, dword ptr [0x4ddb38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */);
    // 004b4469  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b446b  eb09                   -jmp 0x4b4476
    goto L_0x004b4476;
L_0x004b446d:
    // 004b446d  39c2                   +cmp edx, eax
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
    // 004b446f  7209                   -jb 0x4b447a
    if (cpu.flags.cf)
    {
        goto L_0x004b447a;
    }
    // 004b4471  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4473  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004b4476:
    // 004b4476  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4478  75f3                   -jne 0x4b446d
    if (!cpu.flags.zf)
    {
        goto L_0x004b446d;
    }
L_0x004b447a:
    // 004b447a  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b447d  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4480  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b4482  7405                   -je 0x4b4489
    if (cpu.flags.zf)
    {
        goto L_0x004b4489;
    }
    // 004b4484  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b4487  eb06                   -jmp 0x4b448f
    goto L_0x004b448f;
L_0x004b4489:
    // 004b4489  891538db4d00           -mov dword ptr [0x4ddb38], edx
    app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */) = cpu.edx;
L_0x004b448f:
    // 004b448f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4491  7403                   -je 0x4b4496
    if (cpu.flags.zf)
    {
        goto L_0x004b4496;
    }
    // 004b4493  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004b4496:
    // 004b4496  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004b4499  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b449b  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b449e  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 004b44a5  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 004b44ac  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 004b44b3  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 004b44ba  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004b44bd  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004b44c0  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b44c3  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004b44c6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b44c8  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 004b44cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b44d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b44d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b44d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b44d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b44d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b44d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b44d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b44d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b44da  833dcc094e0000         +cmp dword ptr [0x4e09cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114316) /* 0x4e09cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b44e1  7507                   -jne 0x4b44ea
    if (!cpu.flags.zf)
    {
        goto L_0x004b44ea;
    }
L_0x004b44e3:
    // 004b44e3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b44e5  e973000000             -jmp 0x4b455d
    goto L_0x004b455d;
L_0x004b44ea:
    // 004b44ea  833dc4da4d00fe         +cmp dword ptr [0x4ddac4], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102276) /* 0x4ddac4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b44f1  74f0                   -je 0x4b44e3
    if (cpu.flags.zf)
    {
        goto L_0x004b44e3;
    }
    // 004b44f3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b44f5  e87d000000             -call 0x4b4577
    cpu.esp -= 4;
    sub_4b4577(app, cpu);
    if (cpu.terminate) return;
    // 004b44fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b44fc  745f                   -je 0x4b455d
    if (cpu.flags.zf)
    {
        goto L_0x004b455d;
    }
    // 004b44fe  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004b4500  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 004b4505  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4509  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b450a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b450c  2eff15c4654c00         -call dword ptr cs:[0x4c65c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006788) /* 0x4c65c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b4513  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4517  7444                   -je 0x4b455d
    if (cpu.flags.zf)
    {
        goto L_0x004b455d;
    }
    // 004b4519  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b451c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b451f  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4522  39f0                   +cmp eax, esi
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
    // 004b4524  77bd                   -ja 0x4b44e3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b44e3;
    }
    // 004b4526  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b4529  83f838                 +cmp eax, 0x38
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b452c  72b5                   -jb 0x4b44e3
    if (cpu.flags.cf)
    {
        goto L_0x004b44e3;
    }
    // 004b452e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b4530  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4532  e829ffffff             -call 0x4b4460
    cpu.esp -= 4;
    sub_4b4460(app, cpu);
    if (cpu.terminate) return;
    // 004b4537  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4539  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b453b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b453e  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b4540  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b4542  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004b4545  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b454c  47                     -inc edi
    (cpu.edi)++;
    // 004b454d  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4550  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004b4553  e8a06fffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004b4558  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b455d:
    // 004b455d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4560  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4561  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4562  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4563  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4564  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4565  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4566(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4566  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4567  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4569  e87c770000             -call 0x4bbcea
    cpu.esp -= 4;
    sub_4bbcea(app, cpu);
    if (cpu.terminate) return;
    // 004b456e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4570  e85fffffff             -call 0x4b44d4
    cpu.esp -= 4;
    sub_4b44d4(app, cpu);
    if (cpu.terminate) return;
    // 004b4575  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4576  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4577(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4577  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4578  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4579  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b457b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b457d  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b4580  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b4582  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4584  7438                   -je 0x4b45be
    if (cpu.flags.zf)
    {
        goto L_0x004b45be;
    }
    // 004b4586  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b4588  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004b458b  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b458d  7305                   -jae 0x4b4594
    if (!cpu.flags.cf)
    {
        goto L_0x004b4594;
    }
L_0x004b458f:
    // 004b458f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4591  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4592  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4593  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4594:
    // 004b4594  8b0dd0094e00           -mov ecx, dword ptr [0x4e09d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114320) /* 0x4e09d0 */);
    // 004b459a  39c8                   +cmp eax, ecx
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
    // 004b459c  7304                   -jae 0x4b45a2
    if (!cpu.flags.cf)
    {
        goto L_0x004b45a2;
    }
    // 004b459e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b45a0  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004b45a2:
    // 004b45a2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b45a4  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004b45a9  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b45ab  72e2                   -jb 0x4b458f
    if (cpu.flags.cf)
    {
        goto L_0x004b458f;
    }
    // 004b45ad  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004b45af  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004b45b2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b45b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b45b6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004b45b9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004b45be:
    // 004b45be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b45c1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b45c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b45c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b45c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b45c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b45c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b45c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b45c7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b45c9  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 004b45cc  7523                   -jne 0x4b45f1
    if (!cpu.flags.zf)
    {
        goto L_0x004b45f1;
    }
    // 004b45ce  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b45d3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b45d5  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b45d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b45d9  7409                   -je 0x4b45e4
    if (cpu.flags.zf)
    {
        goto L_0x004b45e4;
    }
L_0x004b45db:
    // 004b45db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b45e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b45e4:
    // 004b45e4  b990010000             -mov ecx, 0x190
    cpu.ecx = 400 /*0x190*/;
    // 004b45e9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b45eb  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b45ed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b45ef  74ea                   -je 0x4b45db
    if (cpu.flags.zf)
    {
        goto L_0x004b45db;
    }
L_0x004b45f1:
    // 004b45f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b45f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b45f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b45f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b45f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b45f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b45fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b45fb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b45fc  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004b45ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4601  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b4604  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b4606  0f85b8000000           -jne 0x4b46c4
    if (!cpu.flags.zf)
    {
        goto L_0x004b46c4;
    }
    // 004b460c  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004b4612  e8adffffff             -call 0x4b45c4
    cpu.esp -= 4;
    sub_4b45c4(app, cpu);
    if (cpu.terminate) return;
    // 004b4617  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4619  7413                   -je 0x4b462e
    if (cpu.flags.zf)
    {
        goto L_0x004b462e;
    }
    // 004b461b  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b461e  8b3445c61f4d00         -mov esi, dword ptr [eax*2 + 0x4d1fc6]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5054406) /* 0x4d1fc6 */ + cpu.eax * 2);
    // 004b4625  8b0445c41f4d00         -mov eax, dword ptr [eax*2 + 0x4d1fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054404) /* 0x4d1fc4 */ + cpu.eax * 2);
    // 004b462c  eb11                   -jmp 0x4b463f
    goto L_0x004b463f;
L_0x004b462e:
    // 004b462e  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b4631  8b3445ac1f4d00         -mov esi, dword ptr [eax*2 + 0x4d1fac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5054380) /* 0x4d1fac */ + cpu.eax * 2);
    // 004b4638  8b0445aa1f4d00         -mov eax, dword ptr [eax*2 + 0x4d1faa]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054378) /* 0x4d1faa */ + cpu.eax * 2);
L_0x004b463f:
    // 004b463f  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004b4642  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b4645  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4647  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b4649  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b464e  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004b4651  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004b4655  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004b4659  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b465d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b4660  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b4664  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b4668  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b466a  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 004b466e  e8a626ffff             -call 0x4a6d19
    cpu.esp -= 4;
    sub_4a6d19(app, cpu);
    if (cpu.terminate) return;
    // 004b4673  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b4677  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004b467a  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b467c  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b467f  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004b4684  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4686  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4689  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b468b  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b468e  83f805                 +cmp eax, 5
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
    // 004b4691  751f                   -jne 0x4b46b2
    if (!cpu.flags.zf)
    {
        goto L_0x004b46b2;
    }
    // 004b4693  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004b4696  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b4698  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004b469b  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b469e  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b46a0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b46a2  39f0                   +cmp eax, esi
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
    // 004b46a4  7e08                   -jle 0x4b46ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b46ae;
    }
    // 004b46a6  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b46a9  83e802                 +sub eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b46ac  eb05                   -jmp 0x4b46b3
    goto L_0x004b46b3;
L_0x004b46ae:
    // 004b46ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b46b0  eb01                   -jmp 0x4b46b3
    goto L_0x004b46b3;
L_0x004b46b2:
    // 004b46b2  48                     -dec eax
    (cpu.eax)--;
L_0x004b46b3:
    // 004b46b3  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b46b7  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b46b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b46bb  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b46be  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b46c0  01d8                   +add eax, ebx
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
    // 004b46c2  eb0f                   -jmp 0x4b46d3
    goto L_0x004b46d3;
L_0x004b46c4:
    // 004b46c4  83f901                 +cmp ecx, 1
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
    // 004b46c7  7507                   -jne 0x4b46d0
    if (!cpu.flags.zf)
    {
        goto L_0x004b46d0;
    }
    // 004b46c9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b46cc  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b46ce  eb03                   -jmp 0x4b46d3
    goto L_0x004b46d3;
L_0x004b46d0:
    // 004b46d0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x004b46d3:
    // 004b46d3  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004b46d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b46dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b46dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b46dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b46de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b46df  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b46e1  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 004b46e5  751b                   -jne 0x4b4702
    if (!cpu.flags.zf)
    {
        goto L_0x004b4702;
    }
    // 004b46e7  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 004b46eb  7515                   -jne 0x4b4702
    if (!cpu.flags.zf)
    {
        goto L_0x004b4702;
    }
    // 004b46ed  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b46f0  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004b46f3  39fe                   +cmp esi, edi
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
    // 004b46f5  7e09                   -jle 0x4b4700
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4700;
    }
L_0x004b46f7:
    // 004b46f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b46fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4700:
    // 004b4700  7c16                   -jl 0x4b4718
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b4718;
    }
L_0x004b4702:
    // 004b4702  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b4704  e8eefeffff             -call 0x4b45f7
    cpu.esp -= 4;
    sub_4b45f7(app, cpu);
    if (cpu.terminate) return;
    // 004b4709  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b470b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b470d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b470f  e8e3feffff             -call 0x4b45f7
    cpu.esp -= 4;
    sub_4b45f7(app, cpu);
    if (cpu.terminate) return;
    // 004b4714  39c6                   +cmp esi, eax
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
    // 004b4716  7fdf                   -jg 0x4b46f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b46f7;
    }
L_0x004b4718:
    // 004b4718  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b471a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b471b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b471c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b471d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b471e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b471e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b471f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4720  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4721  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4722  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4723  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4724  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b4727  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b4729  a102054e00             -mov eax, dword ptr [0x4e0502]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113090) /* 0x4e0502 */);
    // 004b472e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4730  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b4732  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b4734  0f8484020000           -je 0x4b49be
    if (cpu.flags.zf)
    {
        goto L_0x004b49be;
    }
    // 004b473a  bad8034e00             -mov edx, 0x4e03d8
    cpu.edx = 5112792 /*0x4e03d8*/;
    // 004b473f  b8b4034e00             -mov eax, 0x4e03b4
    cpu.eax = 5112756 /*0x4e03b4*/;
    // 004b4744  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b4747  e890ffffff             -call 0x4b46dc
    cpu.esp -= 4;
    sub_4b46dc(app, cpu);
    if (cpu.terminate) return;
    // 004b474c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b4750  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4752  740c                   -je 0x4b4760
    if (cpu.flags.zf)
    {
        goto L_0x004b4760;
    }
    // 004b4754  bed8034e00             -mov esi, 0x4e03d8
    cpu.esi = 5112792 /*0x4e03d8*/;
    // 004b4759  bbb4034e00             -mov ebx, 0x4e03b4
    cpu.ebx = 5112756 /*0x4e03b4*/;
    // 004b475e  eb0a                   -jmp 0x4b476a
    goto L_0x004b476a;
L_0x004b4760:
    // 004b4760  beb4034e00             -mov esi, 0x4e03b4
    cpu.esi = 5112756 /*0x4e03b4*/;
    // 004b4765  bbd8034e00             -mov ebx, 0x4e03d8
    cpu.ebx = 5112792 /*0x4e03d8*/;
L_0x004b476a:
    // 004b476a  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b476d  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004b4772  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004b4775  e84afeffff             -call 0x4b45c4
    cpu.esp -= 4;
    sub_4b45c4(app, cpu);
    if (cpu.terminate) return;
    // 004b477a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b477c  8d442d00               -lea eax, [ebp + ebp]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 1);
    // 004b4780  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b4782  740e                   -je 0x4b4792
    if (cpu.flags.zf)
    {
        goto L_0x004b4792;
    }
    // 004b4784  8b90c61f4d00           -mov edx, dword ptr [eax + 0x4d1fc6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5054406) /* 0x4d1fc6 */);
    // 004b478a  8b80c41f4d00           -mov eax, dword ptr [eax + 0x4d1fc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5054404) /* 0x4d1fc4 */);
    // 004b4790  eb0c                   -jmp 0x4b479e
    goto L_0x004b479e;
L_0x004b4792:
    // 004b4792  8b90ac1f4d00           -mov edx, dword ptr [eax + 0x4d1fac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5054380) /* 0x4d1fac */);
    // 004b4798  8b80aa1f4d00           -mov eax, dword ptr [eax + 0x4d1faa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5054378) /* 0x4d1faa */);
L_0x004b479e:
    // 004b479e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b47a1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b47a4  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b47a6  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b47aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b47ac  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004b47af  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b47b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b47b5  0f85b9000000           -jne 0x4b4874
    if (!cpu.flags.zf)
    {
        goto L_0x004b4874;
    }
    // 004b47bb  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b47be  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b47c0  7e0a                   -jle 0x4b47cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b47cc;
    }
    // 004b47c2  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b47c7  e9dd000000             -jmp 0x4b48a9
    goto L_0x004b48a9;
L_0x004b47cc:
    // 004b47cc  0f85d7000000           -jne 0x4b48a9
    if (!cpu.flags.zf)
    {
        goto L_0x004b48a9;
    }
    // 004b47d2  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b47d5  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b47d8  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b47db  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b47dd  c744241807000000       -mov dword ptr [esp + 0x18], 7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 7 /*0x7*/;
    // 004b47e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b47e7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b47ea  f77c2418               -idiv dword ptr [esp + 0x18]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b47ee  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b47f1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b47f3  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b47f6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b47fa  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004b47fd  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 004b4800  c744241807000000       -mov dword ptr [esp + 0x18], 7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 7 /*0x7*/;
    // 004b4808  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b480a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b480d  f77c2418               -idiv dword ptr [esp + 0x18]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4811  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b4814  48                     -dec eax
    (cpu.eax)--;
    // 004b4815  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4817  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b481a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b481e  83fa05                 +cmp edx, 5
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
    // 004b4821  7529                   -jne 0x4b484c
    if (!cpu.flags.zf)
    {
        goto L_0x004b484c;
    }
    // 004b4823  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4827  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b482b  83e807                 -sub eax, 7
    (cpu.eax) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b482e  39d0                   +cmp eax, edx
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
    // 004b4830  0f8d73000000           -jge 0x4b48a9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b48a9;
    }
    // 004b4836  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b483a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b483f  39d0                   +cmp eax, edx
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
    // 004b4841  0f8c62000000           -jl 0x4b48a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b48a9;
    }
    // 004b4847  e964000000             -jmp 0x4b48b0
    goto L_0x004b48b0;
L_0x004b484c:
    // 004b484c  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b484f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b4853  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b4857  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b485a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b485c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4860  40                     -inc eax
    (cpu.eax)++;
    // 004b4861  39d0                   +cmp eax, edx
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
    // 004b4863  7f44                   -jg 0x4b48a9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b48a9;
    }
    // 004b4865  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4869  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b486e  39d0                   +cmp eax, edx
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
    // 004b4870  7e37                   -jle 0x4b48a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b48a9;
    }
    // 004b4872  eb3c                   -jmp 0x4b48b0
    goto L_0x004b48b0;
L_0x004b4874:
    // 004b4874  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004b4877  83f801                 +cmp eax, 1
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
    // 004b487a  751f                   -jne 0x4b489b
    if (!cpu.flags.zf)
    {
        goto L_0x004b489b;
    }
    // 004b487c  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b487f  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004b4884  e83bfdffff             -call 0x4b45c4
    cpu.esp -= 4;
    sub_4b45c4(app, cpu);
    if (cpu.terminate) return;
    // 004b4889  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b488b  740d                   -je 0x4b489a
    if (cpu.flags.zf)
    {
        goto L_0x004b489a;
    }
    // 004b488d  a1ae1f4d00             -mov eax, dword ptr [0x4d1fae]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054382) /* 0x4d1fae */);
    // 004b4892  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b4895  39c2                   +cmp edx, eax
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
    // 004b4897  7e01                   -jle 0x4b489a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b489a;
    }
    // 004b4899  42                     -inc edx
    (cpu.edx)++;
L_0x004b489a:
    // 004b489a  4a                     -dec edx
    (cpu.edx)--;
L_0x004b489b:
    // 004b489b  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004b489e  39c2                   +cmp edx, eax
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
    // 004b48a0  7f07                   -jg 0x4b48a9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b48a9;
    }
    // 004b48a2  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b48a7  7407                   -je 0x4b48b0
    if (cpu.flags.zf)
    {
        goto L_0x004b48b0;
    }
L_0x004b48a9:
    // 004b48a9  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004b48ae  7416                   -je 0x4b48c6
    if (cpu.flags.zf)
    {
        goto L_0x004b48c6;
    }
L_0x004b48b0:
    // 004b48b0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b48b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b48b4  e814010000             -call 0x4b49cd
    cpu.esp -= 4;
    sub_4b49cd(app, cpu);
    if (cpu.terminate) return;
    // 004b48b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b48bb  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004b48be  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b48c0  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004b48c6:
    // 004b48c6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b48c8  7513                   -jne 0x4b48dd
    if (!cpu.flags.zf)
    {
        goto L_0x004b48dd;
    }
    // 004b48ca  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b48ce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b48d0  0f84e8000000           -je 0x4b49be
    if (cpu.flags.zf)
    {
        goto L_0x004b49be;
    }
    // 004b48d6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b48d8  e9e1000000             -jmp 0x4b49be
    goto L_0x004b49be;
L_0x004b48dd:
    // 004b48dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b48df  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004b48e2  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b48e5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b48e7  0f857f000000           -jne 0x4b496c
    if (!cpu.flags.zf)
    {
        goto L_0x004b496c;
    }
    // 004b48ed  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b48f0  39c5                   +cmp ebp, eax
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
    // 004b48f2  7e07                   -jle 0x4b48fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b48fb;
    }
    // 004b48f4  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004b48f6  e9a6000000             -jmp 0x4b49a1
    goto L_0x004b49a1;
L_0x004b48fb:
    // 004b48fb  0f85a0000000           -jne 0x4b49a1
    if (!cpu.flags.zf)
    {
        goto L_0x004b49a1;
    }
    // 004b4901  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b4904  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004b4907  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b490a  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b490c  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
    // 004b4911  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4913  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4916  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4918  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b491b  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b491d  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b4920  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004b4923  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004b4926  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4928  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b492a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b492d  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b492f  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b4932  48                     -dec eax
    (cpu.eax)--;
    // 004b4933  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b4935  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4937  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b493a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b493c  83fe05                 +cmp esi, 5
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b493f  7518                   -jne 0x4b4959
    if (!cpu.flags.zf)
    {
        goto L_0x004b4959;
    }
    // 004b4941  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4945  83e807                 -sub eax, 7
    (cpu.eax) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b4948  39c5                   +cmp ebp, eax
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
    // 004b494a  7f07                   -jg 0x4b4953
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b4953;
    }
L_0x004b494c:
    // 004b494c  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b4951  eb4e                   -jmp 0x4b49a1
    goto L_0x004b49a1;
L_0x004b4953:
    // 004b4953  39c2                   +cmp edx, eax
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
    // 004b4955  7f4a                   -jg 0x4b49a1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b49a1;
    }
    // 004b4957  eb4e                   -jmp 0x4b49a7
    goto L_0x004b49a7;
L_0x004b4959:
    // 004b4959  4e                     -dec esi
    (cpu.esi)--;
    // 004b495a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b495c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b495f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b4961  40                     -inc eax
    (cpu.eax)++;
    // 004b4962  39c5                   +cmp ebp, eax
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
    // 004b4964  7ce6                   -jl 0x4b494c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b494c;
    }
    // 004b4966  39c2                   +cmp edx, eax
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
    // 004b4968  7d37                   -jge 0x4b49a1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b49a1;
    }
    // 004b496a  eb3b                   -jmp 0x4b49a7
    goto L_0x004b49a7;
L_0x004b496c:
    // 004b496c  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004b496f  83fe01                 +cmp esi, 1
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
    // 004b4972  7520                   -jne 0x4b4994
    if (!cpu.flags.zf)
    {
        goto L_0x004b4994;
    }
    // 004b4974  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b4977  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004b497c  e843fcffff             -call 0x4b45c4
    cpu.esp -= 4;
    sub_4b45c4(app, cpu);
    if (cpu.terminate) return;
    // 004b4981  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4983  740e                   -je 0x4b4993
    if (cpu.flags.zf)
    {
        goto L_0x004b4993;
    }
    // 004b4985  a1ae1f4d00             -mov eax, dword ptr [0x4d1fae]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054382) /* 0x4d1fae */);
    // 004b498a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b498d  39c2                   +cmp edx, eax
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
    // 004b498f  7e02                   -jle 0x4b4993
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4993;
    }
    // 004b4991  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004b4993:
    // 004b4993  4a                     -dec edx
    (cpu.edx)--;
L_0x004b4994:
    // 004b4994  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004b4997  39c2                   +cmp edx, eax
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
    // 004b4999  7f06                   -jg 0x4b49a1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b49a1;
    }
    // 004b499b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b499d  39c2                   +cmp edx, eax
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
    // 004b499f  7406                   -je 0x4b49a7
    if (cpu.flags.zf)
    {
        goto L_0x004b49a7;
    }
L_0x004b49a1:
    // 004b49a1  833c2400               +cmp dword ptr [esp], 0
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
    // 004b49a5  740b                   -je 0x4b49b2
    if (cpu.flags.zf)
    {
        goto L_0x004b49b2;
    }
L_0x004b49a7:
    // 004b49a7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b49a9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b49ab  e81d000000             -call 0x4b49cd
    cpu.esp -= 4;
    sub_4b49cd(app, cpu);
    if (cpu.terminate) return;
    // 004b49b0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004b49b2:
    // 004b49b2  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b49b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b49b8  7404                   -je 0x4b49be
    if (cpu.flags.zf)
    {
        goto L_0x004b49be;
    }
    // 004b49ba  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b49bc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004b49be:
    // 004b49be  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b49c0  897920                 -mov dword ptr [ecx + 0x20], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 004b49c3  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b49c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b49cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b49ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b49cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b49d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b49d1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b49d4  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b49d7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b49d9  39f1                   +cmp ecx, esi
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
    // 004b49db  7c14                   -jl 0x4b49f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b49f1;
    }
    // 004b49dd  7517                   -jne 0x4b49f6
    if (!cpu.flags.zf)
    {
        goto L_0x004b49f6;
    }
    // 004b49df  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b49e2  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b49e5  39e9                   +cmp ecx, ebp
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
    // 004b49e7  7c08                   -jl 0x4b49f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b49f1;
    }
    // 004b49e9  750b                   -jne 0x4b49f6
    if (!cpu.flags.zf)
    {
        goto L_0x004b49f6;
    }
    // 004b49eb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b49ed  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b49ef  7d05                   -jge 0x4b49f6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b49f6;
    }
L_0x004b49f1:
    // 004b49f1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004b49f6:
    // 004b49f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b49f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b49fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b49fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b49ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4a00  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b4a02  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b4a04  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4a06  81fac0a80000           +cmp edx, 0xa8c0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43200 /*0xa8c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4a0c  731c                   -jae 0x4b4a2a
    if (!cpu.flags.cf)
    {
        goto L_0x004b4a2a;
    }
    // 004b4a0e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b4a10  7e18                   -jle 0x4b4a2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4a2a;
    }
    // 004b4a12  8db280510100           -lea esi, [edx + 0x15180]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(86400) /* 0x15180 */);
    // 004b4a18  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4a1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a1c  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004b4a21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b4a23  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a25  01c7                   +add edi, eax
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
    // 004b4a27  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4a28  eb0f                   -jmp 0x4b4a39
    goto L_0x004b4a39;
L_0x004b4a2a:
    // 004b4a2a  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004b4a2f  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4a31  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b4a35  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a37  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b4a39:
    // 004b4a39  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004b4a3e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b4a40  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a42  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a44  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b4a46  be100e0000             -mov esi, 0xe10
    cpu.esi = 3600 /*0xe10*/;
    // 004b4a4b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4a4d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a4f  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a51  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a53  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4a56  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4a58  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a5a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b4a5c  be3c000000             -mov esi, 0x3c
    cpu.esi = 60 /*0x3c*/;
    // 004b4a61  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4a63  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a65  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a67  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a69  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b4a6c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4a6e  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a70  bb6e010000             -mov ebx, 0x16e
    cpu.ebx = 366 /*0x16e*/;
    // 004b4a75  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b4a77  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004b4a79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a7b  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4a7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4a7f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b4a82  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a84  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b4a87  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a89  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4a8b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b4a8e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4a90  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b4a92  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4a94  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b4a96  7608                   -jbe 0x4b4aa0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4aa0;
    }
    // 004b4a98  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b4a9b  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b4a9e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b4aa0:
    // 004b4aa0  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004b4aa6  e819fbffff             -call 0x4b45c4
    cpu.esp -= 4;
    sub_4b45c4(app, cpu);
    if (cpu.terminate) return;
    // 004b4aab  056d010000             -add eax, 0x16d
    (cpu.eax) += x86::reg32(x86::sreg32(365 /*0x16d*/));
L_0x004b4ab0:
    // 004b4ab0  39c3                   +cmp ebx, eax
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
    // 004b4ab2  7205                   -jb 0x4b4ab9
    if (cpu.flags.cf)
    {
        goto L_0x004b4ab9;
    }
    // 004b4ab4  42                     -inc edx
    (cpu.edx)++;
    // 004b4ab5  29c3                   +sub ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b4ab7  ebf7                   -jmp 0x4b4ab0
    goto L_0x004b4ab0;
L_0x004b4ab9:
    // 004b4ab9  beac1f4d00             -mov esi, 0x4d1fac
    cpu.esi = 5054380 /*0x4d1fac*/;
    // 004b4abe  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b4ac1  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004b4ac7  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004b4aca  e8f5faffff             -call 0x4b45c4
    cpu.esp -= 4;
    sub_4b45c4(app, cpu);
    if (cpu.terminate) return;
    // 004b4acf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4ad1  7405                   -je 0x4b4ad8
    if (cpu.flags.zf)
    {
        goto L_0x004b4ad8;
    }
    // 004b4ad3  bec61f4d00             -mov esi, 0x4d1fc6
    cpu.esi = 5054406 /*0x4d1fc6*/;
L_0x004b4ad8:
    // 004b4ad8  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 004b4add  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4adf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4ae1  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4ae3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4ae5  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 004b4ae8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b4aeb  39d3                   +cmp ebx, edx
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
    // 004b4aed  7201                   -jb 0x4b4af0
    if (cpu.flags.cf)
    {
        goto L_0x004b4af0;
    }
    // 004b4aef  40                     -inc eax
    (cpu.eax)++;
L_0x004b4af0:
    // 004b4af0  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b4af3  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004b4af7  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4af9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4afb  43                     -inc ebx
    (cpu.ebx)++;
    // 004b4afc  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b4aff  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b4b02  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 004b4b07  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b4b09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4b0b  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b4b0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4b12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b12  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4b13  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4b14  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b4b1b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b4b1d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b4b1f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4b21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4b23  b8df630000             -mov eax, 0x63df
    cpu.eax = 25567 /*0x63df*/;
    // 004b4b28  e8d0feffff             -call 0x4b49fd
    cpu.esp -= 4;
    sub_4b49fd(app, cpu);
    if (cpu.terminate) return;
    // 004b4b2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4b31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4b32  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4b34  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b4b3a  8d5014                 -lea edx, [eax + 0x14]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b4b3d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4b3f  e8ceffffff             -call 0x4b4b12
    cpu.esp -= 4;
    sub_4b4b12(app, cpu);
    if (cpu.terminate) return;
    // 004b4b44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4b47(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b47  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4b48  8a1512054e00           -mov dl, byte ptr [0x4e0512]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */);
    // 004b4b4e  a112054e00             -mov eax, dword ptr [0x4e0512]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113106) /* 0x4e0512 */);
    // 004b4b53  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b4b56  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b4b59  881512054e00           -mov byte ptr [0x4e0512], dl
    app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */) = cpu.dl;
    // 004b4b5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4b61(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4b62  8a1512054e00           -mov dl, byte ptr [0x4e0512]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */);
    // 004b4b68  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b4b6b  a112054e00             -mov eax, dword ptr [0x4e0512]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113106) /* 0x4e0512 */);
    // 004b4b70  881512054e00           -mov byte ptr [0x4e0512], dl
    app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */) = cpu.dl;
    // 004b4b76  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004b4b78  80e6fd                 -and dh, 0xfd
    cpu.dh &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004b4b7b  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b4b7e  883512054e00           -mov byte ptr [0x4e0512], dh
    app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */) = cpu.dh;
    // 004b4b84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4b86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b86  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4b87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4b88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4b89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4b8a  81ecac000000           -sub esp, 0xac
    (cpu.esp) -= x86::reg32(x86::sreg32(172 /*0xac*/));
    // 004b4b90  8a2512054e00           -mov ah, byte ptr [0x4e0512]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */);
    // 004b4b96  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004b4b99  7409                   -je 0x4b4ba4
    if (cpu.flags.zf)
    {
        goto L_0x004b4ba4;
    }
    // 004b4b9b  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004b4b9e  0f85cd000000           -jne 0x4b4c71
    if (!cpu.flags.zf)
    {
        goto L_0x004b4c71;
    }
L_0x004b4ba4:
    // 004b4ba4  8a3512054e00           -mov dh, byte ptr [0x4e0512]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */);
    // 004b4baa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4bac  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004b4baf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4bb0  883512054e00           -mov byte ptr [0x4e0512], dh
    app->getMemory<x86::reg8>(x86::reg32(5113106) /* 0x4e0512 */) = cpu.dh;
    // 004b4bb6  2eff1528654c00         -call dword ptr cs:[0x4c6528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006632) /* 0x4c6528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b4bbd  83f801                 +cmp eax, 1
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
    // 004b4bc0  0f82ab000000           -jb 0x4b4c71
    if (cpu.flags.cf)
    {
        goto L_0x004b4c71;
    }
    // 004b4bc6  7635                   -jbe 0x4b4bfd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4bfd;
    }
    // 004b4bc8  83f802                 +cmp eax, 2
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
    // 004b4bcb  0f85a0000000           -jne 0x4b4c71
    if (!cpu.flags.zf)
    {
        goto L_0x004b4c71;
    }
    // 004b4bd1  c7050a054e0001000000   -mov dword ptr [0x4e050a], 1
    app->getMemory<x86::reg32>(x86::reg32(5113098) /* 0x4e050a */) = 1 /*0x1*/;
    // 004b4bdb  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004b4be2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4be4  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b4be7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4be9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b4bec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4bee  a30e054e00             -mov dword ptr [0x4e050e], eax
    app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */) = cpu.eax;
    // 004b4bf3  f7db                   +neg ebx
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
    // 004b4bf5  891d0e054e00           -mov dword ptr [0x4e050e], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */) = cpu.ebx;
    // 004b4bfb  eb08                   -jmp 0x4b4c05
    goto L_0x004b4c05;
L_0x004b4bfd:
    // 004b4bfd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4bff  890d0a054e00           -mov dword ptr [0x4e050a], ecx
    app->getMemory<x86::reg32>(x86::reg32(5113098) /* 0x4e050a */) = cpu.ecx;
L_0x004b4c05:
    // 004b4c05  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004b4c09  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4c0c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b4c0e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4c10  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b4c13  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4c15  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004b4c1a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b4c1d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4c21  a306054e00             -mov dword ptr [0x4e0506], eax
    app->getMemory<x86::reg32>(x86::reg32(5113094) /* 0x4e0506 */) = cpu.eax;
    // 004b4c26  b8fc034e00             -mov eax, 0x4e03fc
    cpu.eax = 5112828 /*0x4e03fc*/;
    // 004b4c2b  e897630000             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004b4c30  83f8ff                 +cmp eax, -1
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
    // 004b4c33  750a                   -jne 0x4b4c3f
    if (!cpu.flags.zf)
    {
        goto L_0x004b4c3f;
    }
    // 004b4c35  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 004b4c37  883dfc034e00           -mov byte ptr [0x4e03fc], bh
    app->getMemory<x86::reg8>(x86::reg32(5112828) /* 0x4e03fc */) = cpu.bh;
    // 004b4c3d  eb08                   -jmp 0x4b4c47
    goto L_0x004b4c47;
L_0x004b4c3f:
    // 004b4c3f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b4c41  881d7c044e00           -mov byte ptr [0x4e047c], bl
    app->getMemory<x86::reg8>(x86::reg32(5112956) /* 0x4e047c */) = cpu.bl;
L_0x004b4c47:
    // 004b4c47  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004b4c4c  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004b4c50  b87d044e00             -mov eax, 0x4e047d
    cpu.eax = 5112957 /*0x4e047d*/;
    // 004b4c55  e86d630000             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004b4c5a  83f8ff                 +cmp eax, -1
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
    // 004b4c5d  750a                   -jne 0x4b4c69
    if (!cpu.flags.zf)
    {
        goto L_0x004b4c69;
    }
    // 004b4c5f  30ed                   +xor ch, ch
    cpu.clear_co();
    cpu.set_szp((cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch))));
    // 004b4c61  882d7d044e00           -mov byte ptr [0x4e047d], ch
    app->getMemory<x86::reg8>(x86::reg32(5112957) /* 0x4e047d */) = cpu.ch;
    // 004b4c67  eb08                   -jmp 0x4b4c71
    goto L_0x004b4c71;
L_0x004b4c69:
    // 004b4c69  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004b4c6b  880dfd044e00           -mov byte ptr [0x4e04fd], cl
    app->getMemory<x86::reg8>(x86::reg32(5113085) /* 0x4e04fd */) = cpu.cl;
L_0x004b4c71:
    // 004b4c71  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 004b4c77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
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

}
