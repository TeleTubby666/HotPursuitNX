#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_5b9600(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005b9600  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005b9601  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 005b9606  b802000600             -mov eax, 0x60002
    cpu.eax = 393218 /*0x60002*/;
    // 005b960b  891560c85b00           -mov dword ptr [0x5bc860], edx
    app->getMemory<x86::reg32>(x86::reg32(6015072) /* 0x5bc860 */) = cpu.edx;
    // 005b9611  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9612  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5b9614(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005b9614  a368c85b00             -mov dword ptr [0x5bc868], eax
    app->getMemory<x86::reg32>(x86::reg32(6015080) /* 0x5bc868 */) = cpu.eax;
    // 005b9619  89156cc85b00           -mov dword ptr [0x5bc86c], edx
    app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */) = cpu.edx;
    // 005b961f  891d70c85b00           -mov dword ptr [0x5bc870], ebx
    app->getMemory<x86::reg32>(x86::reg32(6015088) /* 0x5bc870 */) = cpu.ebx;
    // 005b9625  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005b9629  890d74c85b00           -mov dword ptr [0x5bc874], ecx
    app->getMemory<x86::reg32>(x86::reg32(6015092) /* 0x5bc874 */) = cpu.ecx;
    // 005b962f  a378c85b00             -mov dword ptr [0x5bc878], eax
    app->getMemory<x86::reg32>(x86::reg32(6015096) /* 0x5bc878 */) = cpu.eax;
    // 005b9634  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005b9636  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_5b963c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005b963c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005b963d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005b963e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005b963f  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005b9645  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005b9647  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b9649  89942488000000         -mov dword ptr [esp + 0x88], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 005b9650  833d60c85b0000         +cmp dword ptr [0x5bc860], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015072) /* 0x5bc860 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9657  7c0f                   -jl 0x5b9668
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005b9668;
    }
    // 005b9659  a160c85b00             -mov eax, dword ptr [0x5bc860]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015072) /* 0x5bc860 */);
    // 005b965e  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005b9664  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9665  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9666  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9667  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005b9668:
    // 005b9668  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005b9669  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005b966a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005b966b  803d10c85b0000         +cmp byte ptr [0x5bc810], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005b9672  7475                   -je 0x5b96e9
    if (cpu.flags.zf)
    {
        goto L_0x005b96e9;
    }
L_0x005b9674:
    // 005b9674  c744240c60000000       -mov dword ptr [esp + 0xc], 0x60
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 96 /*0x60*/;
    // 005b967c  a100c85b00             -mov eax, dword ptr [0x5bc800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b9681  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9683  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005b9687  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b9688  8b3d00c85b00           -mov edi, dword ptr [0x5bc800]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b968e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005b968f  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9692  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9694  0f848b000000           -je 0x5b9725
    if (cpu.flags.zf)
    {
        goto L_0x005b9725;
    }
L_0x005b969a:
    // 005b969a  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x005b96a5:
    // 005b96a5  803d10c85b0000         +cmp byte ptr [0x5bc810], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005b96ac  7522                   -jne 0x5b96d0
    if (!cpu.flags.zf)
    {
        goto L_0x005b96d0;
    }
    // 005b96ae  833d00c85b0000         +cmp dword ptr [0x5bc800], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b96b5  7411                   -je 0x5b96c8
    if (cpu.flags.zf)
    {
        goto L_0x005b96c8;
    }
    // 005b96b7  a100c85b00             -mov eax, dword ptr [0x5bc800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b96bc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005b96be  8b1500c85b00           -mov edx, dword ptr [0x5bc800]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b96c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005b96c5  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005b96c8:
    // 005b96c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005b96ca  890d00c85b00           -mov dword ptr [0x5bc800], ecx
    app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */) = cpu.ecx;
L_0x005b96d0:
    // 005b96d0  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 005b96d7  a360c85b00             -mov dword ptr [0x5bc860], eax
    app->getMemory<x86::reg32>(x86::reg32(6015072) /* 0x5bc860 */) = cpu.eax;
    // 005b96dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b96dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b96de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b96df  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005b96e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b96e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b96e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b96e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005b96e9:
    // 005b96e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005b96ea  6800c85b00             -push 0x5bc800
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014976 /*0x5bc800*/;
    cpu.esp -= 4;
    // 005b96ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005b96f0  e83f110000             -call 0x5ba834
    cpu.esp -= 4;
    sub_5ba834(app, cpu);
    if (cpu.terminate) return;
    // 005b96f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b96f7  0f8477ffffff           -je 0x5b9674
    if (cpu.flags.zf)
    {
        goto L_0x005b9674;
    }
    // 005b96fd  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9702  7414                   -je 0x5b9718
    if (cpu.flags.zf)
    {
        goto L_0x005b9718;
    }
    // 005b9704  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9709  758f                   -jne 0x5b969a
    if (!cpu.flags.zf)
    {
        goto L_0x005b969a;
    }
    // 005b970b  c7842494000000f6ffffff -mov dword ptr [esp + 0x94], 0xfffffff6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967286 /*0xfffffff6*/;
    // 005b9716  eb8d                   -jmp 0x5b96a5
    goto L_0x005b96a5;
L_0x005b9718:
    // 005b9718  c7842494000000eeffffff -mov dword ptr [esp + 0x94], 0xffffffee
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967278 /*0xffffffee*/;
    // 005b9723  eb80                   -jmp 0x5b96a5
    goto L_0x005b96a5;
L_0x005b9725:
    // 005b9725  f644241020             +test byte ptr [esp + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 005b972a  0f84c2000000           -je 0x5b97f2
    if (cpu.flags.zf)
    {
        goto L_0x005b97f2;
    }
    // 005b9730  c60515c85b0001         -mov byte ptr [0x5bc815], 1
    app->getMemory<x86::reg8>(x86::reg32(6014997) /* 0x5bc815 */) = 1 /*0x1*/;
L_0x005b9737:
    // 005b9737  8aac2496000000         -mov ch, byte ptr [esp + 0x96]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */);
    // 005b973e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005b9743  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005b9747  80cd02                 -or ch, 2
    cpu.ch |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 005b974a  6689942482000000       -mov word ptr [esp + 0x82], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.dx;
    // 005b9752  88ac2496000000         -mov byte ptr [esp + 0x96], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */) = cpu.ch;
    // 005b9759  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 005b975e  83e005                 -and eax, 5
    cpu.eax &= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 005b9761  66898c248e000000       -mov word ptr [esp + 0x8e], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.cx;
    // 005b9769  83f805                 +cmp eax, 5
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
    // 005b976c  7508                   -jne 0x5b9776
    if (!cpu.flags.zf)
    {
        goto L_0x005b9776;
    }
    // 005b976e  808c249400000001       -or byte ptr [esp + 0x94], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x005b9776:
    // 005b9776  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005b977a  83e006                 -and eax, 6
    cpu.eax &= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 005b977d  83f806                 +cmp eax, 6
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
    // 005b9780  7508                   -jne 0x5b978a
    if (!cpu.flags.zf)
    {
        goto L_0x005b978a;
    }
    // 005b9782  808c249400000002       -or byte ptr [esp + 0x94], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x005b978a:
    // 005b978a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005b978e  83e009                 -and eax, 9
    cpu.eax &= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 005b9791  83f809                 +cmp eax, 9
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
    // 005b9794  7508                   -jne 0x5b979e
    if (!cpu.flags.zf)
    {
        goto L_0x005b979e;
    }
    // 005b9796  808c249400000004       -or byte ptr [esp + 0x94], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x005b979e:
    // 005b979e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005b97a2  83e00a                 -and eax, 0xa
    cpu.eax &= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 005b97a5  83f80a                 +cmp eax, 0xa
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
    // 005b97a8  752b                   -jne 0x5b97d5
    if (!cpu.flags.zf)
    {
        goto L_0x005b97d5;
    }
    // 005b97aa  8ab42494000000         -mov dh, byte ptr [esp + 0x94]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 005b97b1  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 005b97b6  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 005b97bb  80ce08                 -or dh, 8
    cpu.dh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 005b97be  6689b42482000000       -mov word ptr [esp + 0x82], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.si;
    // 005b97c6  6689bc248e000000       -mov word ptr [esp + 0x8e], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.di;
    // 005b97ce  88b42494000000         -mov byte ptr [esp + 0x94], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.dh;
L_0x005b97d5:
    // 005b97d5  a100c85b00             -mov eax, dword ptr [0x5bc800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b97da  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 005b97dc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005b97de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005b97df  8b2d00c85b00           -mov ebp, dword ptr [0x5bc800]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b97e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005b97e6  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b97e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b97eb  7412                   -je 0x5b97ff
    if (cpu.flags.zf)
    {
        goto L_0x005b97ff;
    }
    // 005b97ed  e9a8feffff             -jmp 0x5b969a
    goto L_0x005b969a;
L_0x005b97f2:
    // 005b97f2  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 005b97f4  883515c85b00           -mov byte ptr [0x5bc815], dh
    app->getMemory<x86::reg8>(x86::reg32(6014997) /* 0x5bc815 */) = cpu.dh;
    // 005b97fa  e938ffffff             -jmp 0x5b9737
    goto L_0x005b9737;
L_0x005b97ff:
    // 005b97ff  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005b9804  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 005b9808  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b980a  e8680f0000             -call 0x5ba777
    cpu.esp -= 4;
    sub_5ba777(app, cpu);
    if (cpu.terminate) return;
    // 005b980f  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 005b9814  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005b9819  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 005b981d  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 005b9821  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9823  8b1500c85b00           -mov edx, dword ptr [0x5bc800]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b9829  6804c85b00             -push 0x5bc804
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014980 /*0x5bc804*/;
    cpu.esp -= 4;
    // 005b982e  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 005b9832  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005b9834  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b9835  8b0d00c85b00           -mov ecx, dword ptr [0x5bc800]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b983b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005b983c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b983f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9841  0f8553feffff           -jne 0x5b969a
    if (!cpu.flags.zf)
    {
        goto L_0x005b969a;
    }
    // 005b9847  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005b984c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b984e  6689842480000000       -mov word ptr [esp + 0x80], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.ax;
    // 005b9856  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005b9858  668b942482000000       -mov dx, word ptr [esp + 0x82]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
    // 005b9860  668b84248e000000       -mov ax, word ptr [esp + 0x8e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
    // 005b9868  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005b986b  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 005b986e  668984248c000000       -mov word ptr [esp + 0x8c], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.ax;
    // 005b9876  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005b9878  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005b9880  69c0112b0000           -imul eax, eax, 0x2b11
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(11025 /*0x2b11*/)));
    // 005b9886  bb112b0000             -mov ebx, 0x2b11
    cpu.ebx = 11025 /*0x2b11*/;
    // 005b988b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b988d  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 005b9894  6689942490000000       -mov word ptr [esp + 0x90], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.dx;
    // 005b989c  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005b98a3  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b98a8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005b98aa  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005b98b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b98b2  8b3504c85b00           -mov esi, dword ptr [0x5bc804]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b98b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005b98b9  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b98bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b98be  7508                   -jne 0x5b98c8
    if (!cpu.flags.zf)
    {
        goto L_0x005b98c8;
    }
    // 005b98c0  808c249500000002       -or byte ptr [esp + 0x95], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x005b98c8:
    // 005b98c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b98ca  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005b98d2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005b98d9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005b98db  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005b98de  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005b98e0  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 005b98e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005b98e5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005b98e8  bf803e0000             -mov edi, 0x3e80
    cpu.edi = 16000 /*0x3e80*/;
    // 005b98ed  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005b98ef  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 005b98f6  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005b98fd  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9902  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9904  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005b990b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b990c  8b2d04c85b00           -mov ebp, dword ptr [0x5bc804]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9912  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005b9913  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9916  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9918  7508                   -jne 0x5b9922
    if (!cpu.flags.zf)
    {
        goto L_0x005b9922;
    }
    // 005b991a  808c249500000004       -or byte ptr [esp + 0x95], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x005b9922:
    // 005b9922  c784248400000022560000 -mov dword ptr [esp + 0x84], 0x5622
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 22050 /*0x5622*/;
    // 005b992d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005b992f  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005b9937  69c022560000           -imul eax, eax, 0x5622
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(22050 /*0x5622*/)));
    // 005b993d  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005b9944  8b1504c85b00           -mov edx, dword ptr [0x5bc804]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b994a  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005b9951  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005b9953  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b9954  8b0d04c85b00           -mov ecx, dword ptr [0x5bc804]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b995a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005b995b  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b995e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9960  7508                   -jne 0x5b996a
    if (!cpu.flags.zf)
    {
        goto L_0x005b996a;
    }
    // 005b9962  808c249500000008       -or byte ptr [esp + 0x95], 8
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x005b996a:
    // 005b996a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b996c  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005b9974  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005b997b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005b997d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005b9980  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005b9982  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005b9985  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005b9987  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005b998a  bb007d0000             -mov ebx, 0x7d00
    cpu.ebx = 32000 /*0x7d00*/;
    // 005b998f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005b9991  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 005b9998  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005b999f  8b1504c85b00           -mov edx, dword ptr [0x5bc804]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b99a5  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005b99ac  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005b99ae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b99af  8b3504c85b00           -mov esi, dword ptr [0x5bc804]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b99b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005b99b6  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b99b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b99bb  7508                   -jne 0x5b99c5
    if (!cpu.flags.zf)
    {
        goto L_0x005b99c5;
    }
    // 005b99bd  808c249500000010       -or byte ptr [esp + 0x95], 0x10
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x005b99c5:
    // 005b99c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005b99c7  bf44ac0000             -mov edi, 0xac44
    cpu.edi = 44100 /*0xac44*/;
    // 005b99cc  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005b99d4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 005b99d7  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 005b99de  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005b99e5  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b99ea  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005b99ec  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005b99f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b99f4  8b2d04c85b00           -mov ebp, dword ptr [0x5bc804]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b99fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005b99fb  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b99fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9a00  7508                   -jne 0x5b9a0a
    if (!cpu.flags.zf)
    {
        goto L_0x005b9a0a;
    }
    // 005b9a02  808c249500000020       -or byte ptr [esp + 0x95], 0x20
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x005b9a0a:
    // 005b9a0a  f68424940000000f       +test byte ptr [esp + 0x94], 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) & 15 /*0xf*/));
    // 005b9a12  7571                   -jne 0x5b9a85
    if (!cpu.flags.zf)
    {
        goto L_0x005b9a85;
    }
L_0x005b9a14:
    // 005b9a14  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x005b9a1f:
    // 005b9a1f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9a21  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9a26  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 005b9a28  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 005b9a2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9a31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005b9a32  8b1d04c85b00           -mov ebx, dword ptr [0x5bc804]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9a38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005b9a39  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9a3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9a3e  0f8561fcffff           -jne 0x5b96a5
    if (!cpu.flags.zf)
    {
        goto L_0x005b96a5;
    }
    // 005b9a44  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9a4d  754f                   -jne 0x5b9a9e
    if (!cpu.flags.zf)
    {
        goto L_0x005b9a9e;
    }
    // 005b9a4f  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9a58  7544                   -jne 0x5b9a9e
    if (!cpu.flags.zf)
    {
        goto L_0x005b9a9e;
    }
    // 005b9a5a  c784249400000001000000 -mov dword ptr [esp + 0x94], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
L_0x005b9a65:
    // 005b9a65  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 005b9a6c  81f9112b0000           +cmp ecx, 0x2b11
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11025 /*0x2b11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9a72  0f859a000000           -jne 0x5b9b12
    if (!cpu.flags.zf)
    {
        goto L_0x005b9b12;
    }
    // 005b9a78  808c249500000002       +or byte ptr [esp + 0x95], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 005b9a80  e920fcffff             -jmp 0x5b96a5
    goto L_0x005b96a5;
L_0x005b9a85:
    // 005b9a85  f68424950000003e       +test byte ptr [esp + 0x95], 0x3e
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) & 62 /*0x3e*/));
    // 005b9a8d  7485                   -je 0x5b9a14
    if (cpu.flags.zf)
    {
        goto L_0x005b9a14;
    }
    // 005b9a8f  83bc249400000000       +cmp dword ptr [esp + 0x94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9a97  7e86                   -jle 0x5b9a1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005b9a1f;
    }
    // 005b9a99  e907fcffff             -jmp 0x5b96a5
    goto L_0x005b96a5;
L_0x005b9a9e:
    // 005b9a9e  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9aa7  7518                   -jne 0x5b9ac1
    if (!cpu.flags.zf)
    {
        goto L_0x005b9ac1;
    }
    // 005b9aa9  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9ab2  750d                   -jne 0x5b9ac1
    if (!cpu.flags.zf)
    {
        goto L_0x005b9ac1;
    }
    // 005b9ab4  c784249400000002000000 -mov dword ptr [esp + 0x94], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 2 /*0x2*/;
    // 005b9abf  eba4                   -jmp 0x5b9a65
    goto L_0x005b9a65;
L_0x005b9ac1:
    // 005b9ac1  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9aca  7518                   -jne 0x5b9ae4
    if (!cpu.flags.zf)
    {
        goto L_0x005b9ae4;
    }
    // 005b9acc  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9ad5  750d                   -jne 0x5b9ae4
    if (!cpu.flags.zf)
    {
        goto L_0x005b9ae4;
    }
    // 005b9ad7  c784249400000004000000 -mov dword ptr [esp + 0x94], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4 /*0x4*/;
    // 005b9ae2  eb81                   -jmp 0x5b9a65
    goto L_0x005b9a65;
L_0x005b9ae4:
    // 005b9ae4  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9aed  0f85a7fbffff           -jne 0x5b969a
    if (!cpu.flags.zf)
    {
        goto L_0x005b969a;
    }
    // 005b9af3  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005b9afc  0f8598fbffff           -jne 0x5b969a
    if (!cpu.flags.zf)
    {
        goto L_0x005b969a;
    }
    // 005b9b02  c784249400000008000000 -mov dword ptr [esp + 0x94], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 8 /*0x8*/;
    // 005b9b0d  e953ffffff             -jmp 0x5b9a65
    goto L_0x005b9a65;
L_0x005b9b12:
    // 005b9b12  81f9803e0000           +cmp ecx, 0x3e80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16000 /*0x3e80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9b18  750d                   -jne 0x5b9b27
    if (!cpu.flags.zf)
    {
        goto L_0x005b9b27;
    }
    // 005b9b1a  808c249500000004       +or byte ptr [esp + 0x95], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 005b9b22  e97efbffff             -jmp 0x5b96a5
    goto L_0x005b96a5;
L_0x005b9b27:
    // 005b9b27  81f922560000           +cmp ecx, 0x5622
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9b2d  750d                   -jne 0x5b9b3c
    if (!cpu.flags.zf)
    {
        goto L_0x005b9b3c;
    }
    // 005b9b2f  808c249500000008       +or byte ptr [esp + 0x95], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 005b9b37  e969fbffff             -jmp 0x5b96a5
    goto L_0x005b96a5;
L_0x005b9b3c:
    // 005b9b3c  81f9007d0000           +cmp ecx, 0x7d00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32000 /*0x7d00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9b42  750d                   -jne 0x5b9b51
    if (!cpu.flags.zf)
    {
        goto L_0x005b9b51;
    }
    // 005b9b44  808c249500000010       +or byte ptr [esp + 0x95], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 005b9b4c  e954fbffff             -jmp 0x5b96a5
    goto L_0x005b96a5;
L_0x005b9b51:
    // 005b9b51  81f944ac0000           +cmp ecx, 0xac44
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44100 /*0xac44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9b57  0f853dfbffff           -jne 0x5b969a
    if (!cpu.flags.zf)
    {
        goto L_0x005b969a;
    }
    // 005b9b5d  808c249500000020       +or byte ptr [esp + 0x95], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 005b9b65  e93bfbffff             -jmp 0x5b96a5
    goto L_0x005b96a5;
}

/* align: skip 0x8b 0xc0 */
void sub_5b9b6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005b9b6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005b9b6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005b9b6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005b9b6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005b9b70  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005b9b73  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 005b9b77  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 005b9b7b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 005b9b80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9b82  0f8499010000           -je 0x5b9d21
    if (cpu.flags.zf)
    {
        goto L_0x005b9d21;
    }
    // 005b9b88  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x005b9b8d:
    // 005b9b8d  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 005b9b90  0f8495010000           -je 0x5b9d2b
    if (cpu.flags.zf)
    {
        goto L_0x005b9d2b;
    }
    // 005b9b96  c70564c85b0022560000   -mov dword ptr [0x5bc864], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */) = 22050 /*0x5622*/;
L_0x005b9ba0:
    // 005b9ba0  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 005b9ba3  0f84e9010000           -je 0x5b9d92
    if (cpu.flags.zf)
    {
        goto L_0x005b9d92;
    }
    // 005b9ba9  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x005b9bae:
    // 005b9bae  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
L_0x005b9bb3:
    // 005b9bb3  803d15c85b0000         +cmp byte ptr [0x5bc815], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014997) /* 0x5bc815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005b9bba  0f8420020000           -je 0x5b9de0
    if (cpu.flags.zf)
    {
        goto L_0x005b9de0;
    }
    // 005b9bc0  c70530c85b0000200000   -mov dword ptr [0x5bc830], 0x2000
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = 8192 /*0x2000*/;
    // 005b9bca  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9bcd  750c                   -jne 0x5b9bdb
    if (!cpu.flags.zf)
    {
        goto L_0x005b9bdb;
    }
    // 005b9bcf  a130c85b00             -mov eax, dword ptr [0x5bc830]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */);
    // 005b9bd4  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005b9bd6  a330c85b00             -mov dword ptr [0x5bc830], eax
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.eax;
L_0x005b9bdb:
    // 005b9bdb  83fe01                 +cmp esi, 1
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
    // 005b9bde  750e                   -jne 0x5b9bee
    if (!cpu.flags.zf)
    {
        goto L_0x005b9bee;
    }
    // 005b9be0  8b1530c85b00           -mov edx, dword ptr [0x5bc830]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */);
    // 005b9be6  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005b9be8  891530c85b00           -mov dword ptr [0x5bc830], edx
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.edx;
L_0x005b9bee:
    // 005b9bee  812530c85b00f0ff0f00   -and dword ptr [0x5bc830], 0xffff0
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005b9bf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005b9bfa  a338c85b00             -mov dword ptr [0x5bc838], eax
    app->getMemory<x86::reg32>(x86::reg32(6015032) /* 0x5bc838 */) = cpu.eax;
    // 005b9bff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b9c01  a32cc85b00             -mov dword ptr [0x5bc82c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015020) /* 0x5bc82c */) = cpu.eax;
    // 005b9c06  a324c85b00             -mov dword ptr [0x5bc824], eax
    app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */) = cpu.eax;
    // 005b9c0b  a328c85b00             -mov dword ptr [0x5bc828], eax
    app->getMemory<x86::reg32>(x86::reg32(6015016) /* 0x5bc828 */) = cpu.eax;
    // 005b9c10  a338c85b00             -mov dword ptr [0x5bc838], eax
    app->getMemory<x86::reg32>(x86::reg32(6015032) /* 0x5bc838 */) = cpu.eax;
    // 005b9c15  a318c85b00             -mov dword ptr [0x5bc818], eax
    app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */) = cpu.eax;
    // 005b9c1a  a344c85b00             -mov dword ptr [0x5bc844], eax
    app->getMemory<x86::reg32>(x86::reg32(6015044) /* 0x5bc844 */) = cpu.eax;
    // 005b9c1f  b932000000             -mov ecx, 0x32
    cpu.ecx = 50 /*0x32*/;
    // 005b9c24  a164c85b00             -mov eax, dword ptr [0x5bc864]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */);
    // 005b9c29  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005b9c2b  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005b9c30  a31cc85b00             -mov dword ptr [0x5bc81c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015004) /* 0x5bc81c */) = cpu.eax;
    // 005b9c35  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005b9c37  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 005b9c3a  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 005b9c3d  a213c85b00             -mov byte ptr [0x5bc813], al
    app->getMemory<x86::reg8>(x86::reg32(6014995) /* 0x5bc813 */) = cpu.al;
    // 005b9c42  0fbe0513c85b00         -movsx eax, byte ptr [0x5bc813]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014995) /* 0x5bc813 */)));
    // 005b9c49  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 005b9c4b  a214c85b00             -mov byte ptr [0x5bc814], al
    app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */) = cpu.al;
    // 005b9c50  803d10c85b0000         +cmp byte ptr [0x5bc810], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005b9c57  751d                   -jne 0x5b9c76
    if (!cpu.flags.zf)
    {
        goto L_0x005b9c76;
    }
    // 005b9c59  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9c5b  6800c85b00             -push 0x5bc800
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014976 /*0x5bc800*/;
    cpu.esp -= 4;
    // 005b9c60  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9c62  e8cd0b0000             -call 0x5ba834
    cpu.esp -= 4;
    sub_5ba834(app, cpu);
    if (cpu.terminate) return;
    // 005b9c67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9c69  0f859a010000           -jne 0x5b9e09
    if (!cpu.flags.zf)
    {
        goto L_0x005b9e09;
    }
    // 005b9c6f  c60510c85b0001         -mov byte ptr [0x5bc810], 1
    app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */) = 1 /*0x1*/;
L_0x005b9c76:
    // 005b9c76  a100c85b00             -mov eax, dword ptr [0x5bc800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b9c7b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005b9c7c  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005b9c80  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9c82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005b9c83  8b0d00c85b00           -mov ecx, dword ptr [0x5bc800]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b9c89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005b9c8a  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9c8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9c8f  0f84a0010000           -je 0x5b9e35
    if (cpu.flags.zf)
    {
        goto L_0x005b9e35;
    }
    // 005b9c95  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9c9c  740e                   -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005b9c9e  685cc65b00             -push 0x5bc65c
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014556 /*0x5bc65c*/;
    cpu.esp -= 4;
L_0x005b9ca3:
    // 005b9ca3  ff156cc85b00           -call dword ptr [0x5bc86c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9ca9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005b9cac:
    // 005b9cac  803d12c85b0000         +cmp byte ptr [0x5bc812], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014994) /* 0x5bc812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005b9cb3  7434                   -je 0x5b9ce9
    if (cpu.flags.zf)
    {
        goto L_0x005b9ce9;
    }
    // 005b9cb5  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 005b9cb7  881512c85b00           -mov byte ptr [0x5bc812], dl
    app->getMemory<x86::reg8>(x86::reg32(6014994) /* 0x5bc812 */) = cpu.dl;
    // 005b9cbd  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9cc2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9cc4  8b3504c85b00           -mov esi, dword ptr [0x5bc804]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9cca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005b9ccb  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9cce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9cd0  7417                   -je 0x5b9ce9
    if (cpu.flags.zf)
    {
        goto L_0x005b9ce9;
    }
    // 005b9cd2  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9cd9  740e                   -je 0x5b9ce9
    if (cpu.flags.zf)
    {
        goto L_0x005b9ce9;
    }
    // 005b9cdb  68a0c75b00             -push 0x5bc7a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014880 /*0x5bc7a0*/;
    cpu.esp -= 4;
    // 005b9ce0  ff156cc85b00           -call dword ptr [0x5bc86c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9ce6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005b9ce9:
    // 005b9ce9  803d10c85b0000         +cmp byte ptr [0x5bc810], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005b9cf0  7425                   -je 0x5b9d17
    if (cpu.flags.zf)
    {
        goto L_0x005b9d17;
    }
    // 005b9cf2  833d00c85b0000         +cmp dword ptr [0x5bc800], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9cf9  0f859e040000           -jne 0x5ba19d
    if (!cpu.flags.zf)
    {
        goto L_0x005ba19d;
    }
L_0x005b9cff:
    // 005b9cff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005b9d01  890d00c85b00           -mov dword ptr [0x5bc800], ecx
    app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */) = cpu.ecx;
    // 005b9d07  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 005b9d09  881d11c85b00           -mov byte ptr [0x5bc811], bl
    app->getMemory<x86::reg8>(x86::reg32(6014993) /* 0x5bc811 */) = cpu.bl;
    // 005b9d0f  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 005b9d11  883d10c85b00           -mov byte ptr [0x5bc810], bh
    app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */) = cpu.bh;
L_0x005b9d17:
    // 005b9d17  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005b9d19  83c444                 +add esp, 0x44
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005b9d1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9d1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9d1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9d1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005b9d20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005b9d21:
    // 005b9d21  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 005b9d26  e962feffff             -jmp 0x5b9b8d
    goto L_0x005b9b8d;
L_0x005b9d2b:
    // 005b9d2b  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 005b9d2e  740f                   -je 0x5b9d3f
    if (cpu.flags.zf)
    {
        goto L_0x005b9d3f;
    }
    // 005b9d30  c70564c85b00803e0000   -mov dword ptr [0x5bc864], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */) = 16000 /*0x3e80*/;
    // 005b9d3a  e961feffff             -jmp 0x5b9ba0
    goto L_0x005b9ba0;
L_0x005b9d3f:
    // 005b9d3f  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 005b9d42  740f                   -je 0x5b9d53
    if (cpu.flags.zf)
    {
        goto L_0x005b9d53;
    }
    // 005b9d44  c70564c85b00007d0000   -mov dword ptr [0x5bc864], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */) = 32000 /*0x7d00*/;
    // 005b9d4e  e94dfeffff             -jmp 0x5b9ba0
    goto L_0x005b9ba0;
L_0x005b9d53:
    // 005b9d53  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 005b9d56  740f                   -je 0x5b9d67
    if (cpu.flags.zf)
    {
        goto L_0x005b9d67;
    }
    // 005b9d58  c70564c85b0044ac0000   -mov dword ptr [0x5bc864], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */) = 44100 /*0xac44*/;
    // 005b9d62  e939feffff             -jmp 0x5b9ba0
    goto L_0x005b9ba0;
L_0x005b9d67:
    // 005b9d67  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 005b9d6a  740f                   -je 0x5b9d7b
    if (cpu.flags.zf)
    {
        goto L_0x005b9d7b;
    }
    // 005b9d6c  c70564c85b00112b0000   -mov dword ptr [0x5bc864], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */) = 11025 /*0x2b11*/;
    // 005b9d76  e925feffff             -jmp 0x5b9ba0
    goto L_0x005b9ba0;
L_0x005b9d7b:
    // 005b9d7b  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9d82  0f8424ffffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005b9d88  6800c65b00             -push 0x5bc600
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014464 /*0x5bc600*/;
    cpu.esp -= 4;
    // 005b9d8d  e911ffffff             -jmp 0x5b9ca3
    goto L_0x005b9ca3;
L_0x005b9d92:
    // 005b9d92  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 005b9d95  740f                   -je 0x5b9da6
    if (cpu.flags.zf)
    {
        goto L_0x005b9da6;
    }
    // 005b9d97  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 005b9d9c  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 005b9da1  e90dfeffff             -jmp 0x5b9bb3
    goto L_0x005b9bb3;
L_0x005b9da6:
    // 005b9da6  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 005b9da9  740a                   -je 0x5b9db5
    if (cpu.flags.zf)
    {
        goto L_0x005b9db5;
    }
    // 005b9dab  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 005b9db0  e9f9fdffff             -jmp 0x5b9bae
    goto L_0x005b9bae;
L_0x005b9db5:
    // 005b9db5  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 005b9db8  740f                   -je 0x5b9dc9
    if (cpu.flags.zf)
    {
        goto L_0x005b9dc9;
    }
    // 005b9dba  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 005b9dbf  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 005b9dc4  e9eafdffff             -jmp 0x5b9bb3
    goto L_0x005b9bb3;
L_0x005b9dc9:
    // 005b9dc9  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9dd0  0f84d6feffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005b9dd6  682cc65b00             -push 0x5bc62c
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014508 /*0x5bc62c*/;
    cpu.esp -= 4;
    // 005b9ddb  e9c3feffff             -jmp 0x5b9ca3
    goto L_0x005b9ca3;
L_0x005b9de0:
    // 005b9de0  c70530c85b0014000000   -mov dword ptr [0x5bc830], 0x14
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = 20 /*0x14*/;
    // 005b9dea  a164c85b00             -mov eax, dword ptr [0x5bc864]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */);
    // 005b9def  0faf0530c85b00         -imul eax, dword ptr [0x5bc830]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */))));
    // 005b9df6  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 005b9dfb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b9dfd  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005b9dff  a330c85b00             -mov dword ptr [0x5bc830], eax
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.eax;
    // 005b9e04  e9e5fdffff             -jmp 0x5b9bee
    goto L_0x005b9bee;
L_0x005b9e09:
    // 005b9e09  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9e0e  750a                   -jne 0x5b9e1a
    if (!cpu.flags.zf)
    {
        goto L_0x005b9e1a;
    }
    // 005b9e10  bdeeffffff             -mov ebp, 0xffffffee
    cpu.ebp = 4294967278 /*0xffffffee*/;
    // 005b9e15  e992feffff             -jmp 0x5b9cac
    goto L_0x005b9cac;
L_0x005b9e1a:
    // 005b9e1a  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9e1f  750a                   -jne 0x5b9e2b
    if (!cpu.flags.zf)
    {
        goto L_0x005b9e2b;
    }
    // 005b9e21  bdf6ffffff             -mov ebp, 0xfffffff6
    cpu.ebp = 4294967286 /*0xfffffff6*/;
    // 005b9e26  e981feffff             -jmp 0x5b9cac
    goto L_0x005b9cac;
L_0x005b9e2b:
    // 005b9e2b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 005b9e30  e977feffff             -jmp 0x5b9cac
    goto L_0x005b9cac;
L_0x005b9e35:
    // 005b9e35  803d11c85b0000         +cmp byte ptr [0x5bc811], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014993) /* 0x5bc811 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005b9e3c  755f                   -jne 0x5b9e9d
    if (!cpu.flags.zf)
    {
        goto L_0x005b9e9d;
    }
    // 005b9e3e  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005b9e43  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005b9e45  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005b9e47  e82b090000             -call 0x5ba777
    cpu.esp -= 4;
    sub_5ba777(app, cpu);
    if (cpu.terminate) return;
    // 005b9e4c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005b9e51  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005b9e56  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 005b9e59  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005b9e5d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9e5f  8b1500c85b00           -mov edx, dword ptr [0x5bc800]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b9e65  6804c85b00             -push 0x5bc804
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014980 /*0x5bc804*/;
    cpu.esp -= 4;
    // 005b9e6a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005b9e6e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005b9e70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b9e71  8b0d00c85b00           -mov ecx, dword ptr [0x5bc800]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005b9e77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005b9e78  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9e7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9e7d  7417                   -je 0x5b9e96
    if (cpu.flags.zf)
    {
        goto L_0x005b9e96;
    }
    // 005b9e7f  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9e86  0f8420feffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005b9e8c  6890c65b00             -push 0x5bc690
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014608 /*0x5bc690*/;
    cpu.esp -= 4;
    // 005b9e91  e90dfeffff             -jmp 0x5b9ca3
    goto L_0x005b9ca3;
L_0x005b9e96:
    // 005b9e96  c60511c85b0001         -mov byte ptr [0x5bc811], 1
    app->getMemory<x86::reg8>(x86::reg32(6014993) /* 0x5bc811 */) = 1 /*0x1*/;
L_0x005b9e9d:
    // 005b9e9d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005b9ea2  668974242a             -mov word ptr [esp + 0x2a], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 005b9ea7  6689542428             -mov word ptr [esp + 0x28], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 005b9eac  a164c85b00             -mov eax, dword ptr [0x5bc864]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */);
    // 005b9eb1  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 005b9eb5  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005b9ebc  a164c85b00             -mov eax, dword ptr [0x5bc864]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */);
    // 005b9ec1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005b9ec3  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 005b9ec7  660fbe0513c85b00       -movsx ax, byte ptr [0x5bc813]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014995) /* 0x5bc813 */)));
    // 005b9ecf  6689442434             -mov word ptr [esp + 0x34], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 005b9ed4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005b9ed6  66897c2436             -mov word ptr [esp + 0x36], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 005b9edb  66895c2438             -mov word ptr [esp + 0x38], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.bx;
    // 005b9ee0  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9ee5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9ee7  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005b9eeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b9eec  8b1d04c85b00           -mov ebx, dword ptr [0x5bc804]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9ef2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005b9ef3  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9ef6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9ef8  7417                   -je 0x5b9f11
    if (cpu.flags.zf)
    {
        goto L_0x005b9f11;
    }
    // 005b9efa  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9f01  0f84a5fdffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005b9f07  68c4c65b00             -push 0x5bc6c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014660 /*0x5bc6c4*/;
    cpu.esp -= 4;
    // 005b9f0c  e992fdffff             -jmp 0x5b9ca3
    goto L_0x005b9ca3;
L_0x005b9f11:
    // 005b9f11  c744241414000000       -mov dword ptr [esp + 0x14], 0x14
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 20 /*0x14*/;
    // 005b9f19  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9f1e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9f20  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005b9f24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005b9f25  8b0d04c85b00           -mov ecx, dword ptr [0x5bc804]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005b9f2b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005b9f2c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005b9f2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005b9f31  7417                   -je 0x5b9f4a
    if (cpu.flags.zf)
    {
        goto L_0x005b9f4a;
    }
    // 005b9f33  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9f3a  0f846cfdffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005b9f40  68fcc65b00             -push 0x5bc6fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014716 /*0x5bc6fc*/;
    cpu.esp -= 4;
    // 005b9f45  e959fdffff             -jmp 0x5b9ca3
    goto L_0x005b9ca3;
L_0x005b9f4a:
    // 005b9f4a  837c244000             +cmp dword ptr [esp + 0x40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9f4f  0f8429010000           -je 0x5ba07e
    if (cpu.flags.zf)
    {
        goto L_0x005ba07e;
    }
    // 005b9f55  f644241804             +test byte ptr [esp + 0x18], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) & 4 /*0x4*/));
    // 005b9f5a  0f844cfdffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005b9f60  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005b9f64  a33cc85b00             -mov dword ptr [0x5bc83c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */) = cpu.eax;
    // 005b9f69  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005b9f70  a13cc85b00             -mov eax, dword ptr [0x5bc83c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */);
    // 005b9f75  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 005b9f77  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 005b9f79  0f852dfdffff           -jne 0x5b9cac
    if (!cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
L_0x005b9f7f:
    // 005b9f7f  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005b9f86  a13cc85b00             -mov eax, dword ptr [0x5bc83c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */);
    // 005b9f8b  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 005b9f8d  a35cc85b00             -mov dword ptr [0x5bc85c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */) = cpu.eax;
    // 005b9f92  8b155cc85b00           -mov edx, dword ptr [0x5bc85c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */);
    // 005b9f98  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 005b9f9b  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 005b9fa0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005b9fa2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005b9fa5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005b9fa7  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005b9fac  a334c85b00             -mov dword ptr [0x5bc834], eax
    app->getMemory<x86::reg32>(x86::reg32(6015028) /* 0x5bc834 */) = cpu.eax;
    // 005b9fb1  a15cc85b00             -mov eax, dword ptr [0x5bc85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */);
    // 005b9fb6  a340c85b00             -mov dword ptr [0x5bc840], eax
    app->getMemory<x86::reg32>(x86::reg32(6015040) /* 0x5bc840 */) = cpu.eax;
    // 005b9fbb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005b9fbd  a34cc85b00             -mov dword ptr [0x5bc84c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015052) /* 0x5bc84c */) = cpu.eax;
    // 005b9fc2  a350c85b00             -mov dword ptr [0x5bc850], eax
    app->getMemory<x86::reg32>(x86::reg32(6015056) /* 0x5bc850 */) = cpu.eax;
    // 005b9fc7  a348c85b00             -mov dword ptr [0x5bc848], eax
    app->getMemory<x86::reg32>(x86::reg32(6015048) /* 0x5bc848 */) = cpu.eax;
    // 005b9fcc  837c244000             +cmp dword ptr [esp + 0x40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005b9fd1  0f8400010000           -je 0x5ba0d7
    if (cpu.flags.zf)
    {
        goto L_0x005ba0d7;
    }
    // 005b9fd7  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
L_0x005b9fdc:
    // 005b9fdc  a30cc85b00             -mov dword ptr [0x5bc80c], eax
    app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */) = cpu.eax;
    // 005b9fe1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9fe3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9fe5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005b9fe7  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005b9fec  6858c85b00             -push 0x5bc858
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015064 /*0x5bc858*/;
    cpu.esp -= 4;
    // 005b9ff1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005b9ff3  6854c85b00             -push 0x5bc854
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015060 /*0x5bc854*/;
    cpu.esp -= 4;
    // 005b9ff8  8b1d3cc85b00           -mov ebx, dword ptr [0x5bc83c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */);
    // 005b9ffe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005b9fff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba001  8b350cc85b00           -mov esi, dword ptr [0x5bc80c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba007  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba008  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba00b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba00d  0f8599fcffff           -jne 0x5b9cac
    if (!cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005ba013  8b1d3cc85b00           -mov ebx, dword ptr [0x5bc83c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */);
    // 005ba019  a154c85b00             -mov eax, dword ptr [0x5bc854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015060) /* 0x5bc854 */);
    // 005ba01e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005ba020  e852070000             -call 0x5ba777
    cpu.esp -= 4;
    sub_5ba777(app, cpu);
    if (cpu.terminate) return;
    // 005ba025  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba02a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba02c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba02e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba030  8b3d3cc85b00           -mov edi, dword ptr [0x5bc83c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */);
    // 005ba036  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005ba037  8b1554c85b00           -mov edx, dword ptr [0x5bc854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015060) /* 0x5bc854 */);
    // 005ba03d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba03e  8b0d0cc85b00           -mov ecx, dword ptr [0x5bc80c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba044  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba045  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba048  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005ba04a  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba04f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba051  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba053  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba055  8b1d0cc85b00           -mov ebx, dword ptr [0x5bc80c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba05b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba05c  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba05f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba061  0f8425010000           -je 0x5ba18c
    if (cpu.flags.zf)
    {
        goto L_0x005ba18c;
    }
    // 005ba067  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba06e  0f8438fcffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005ba074  686cc75b00             -push 0x5bc76c
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014828 /*0x5bc76c*/;
    cpu.esp -= 4;
    // 005ba079  e925fcffff             -jmp 0x5b9ca3
    goto L_0x005b9ca3;
L_0x005ba07e:
    // 005ba07e  803d15c85b0000         +cmp byte ptr [0x5bc815], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014997) /* 0x5bc815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba085  7418                   -je 0x5ba09f
    if (cpu.flags.zf)
    {
        goto L_0x005ba09f;
    }
    // 005ba087  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba08e  b800a00000             -mov eax, 0xa000
    cpu.eax = 40960 /*0xa000*/;
    // 005ba093  d3e0                   +shl eax, cl
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
    // 005ba095  a33cc85b00             -mov dword ptr [0x5bc83c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */) = cpu.eax;
    // 005ba09a  e9e0feffff             -jmp 0x5b9f7f
    goto L_0x005b9f7f;
L_0x005ba09f:
    // 005ba09f  8b1564c85b00           -mov edx, dword ptr [0x5bc864]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */);
    // 005ba0a5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005ba0ac  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005ba0ae  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005ba0b1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005ba0b3  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 005ba0b8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005ba0bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005ba0bd  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005ba0bf  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005ba0c4  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba0cb  d3e0                   +shl eax, cl
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
    // 005ba0cd  a33cc85b00             -mov dword ptr [0x5bc83c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */) = cpu.eax;
    // 005ba0d2  e9a8feffff             -jmp 0x5b9f7f
    goto L_0x005b9f7f;
L_0x005ba0d7:
    // 005ba0d7  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005ba0dc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005ba0de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005ba0e0  e892060000             -call 0x5ba777
    cpu.esp -= 4;
    sub_5ba777(app, cpu);
    if (cpu.terminate) return;
    // 005ba0e5  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 005ba0ea  ba08000100             -mov edx, 0x10008
    cpu.edx = 65544 /*0x10008*/;
    // 005ba0ef  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005ba0f2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005ba0f6  a13cc85b00             -mov eax, dword ptr [0x5bc83c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015036) /* 0x5bc83c */);
    // 005ba0fb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 005ba100  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005ba104  668974242a             -mov word ptr [esp + 0x2a], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 005ba109  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005ba10d  66894c2428             -mov word ptr [esp + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 005ba112  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005ba116  a164c85b00             -mov eax, dword ptr [0x5bc864]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */);
    // 005ba11b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 005ba11f  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba126  a164c85b00             -mov eax, dword ptr [0x5bc864]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */);
    // 005ba12b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005ba12d  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 005ba131  660fbe0513c85b00       -movsx ax, byte ptr [0x5bc813]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014995) /* 0x5bc813 */)));
    // 005ba139  6689442434             -mov word ptr [esp + 0x34], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 005ba13e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005ba140  66897c2436             -mov word ptr [esp + 0x36], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 005ba145  6689742438             -mov word ptr [esp + 0x38], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.si;
    // 005ba14a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba14c  a100c85b00             -mov eax, dword ptr [0x5bc800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005ba151  6808c85b00             -push 0x5bc808
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014984 /*0x5bc808*/;
    cpu.esp -= 4;
    // 005ba156  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba158  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005ba15c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005ba15d  8b0d00c85b00           -mov ecx, dword ptr [0x5bc800]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005ba163  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba164  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba167  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba169  7417                   -je 0x5ba182
    if (cpu.flags.zf)
    {
        goto L_0x005ba182;
    }
    // 005ba16b  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba172  0f8434fbffff           -je 0x5b9cac
    if (cpu.flags.zf)
    {
        goto L_0x005b9cac;
    }
    // 005ba178  6834c75b00             -push 0x5bc734
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014772 /*0x5bc734*/;
    cpu.esp -= 4;
    // 005ba17d  e921fbffff             -jmp 0x5b9ca3
    goto L_0x005b9ca3;
L_0x005ba182:
    // 005ba182  a108c85b00             -mov eax, dword ptr [0x5bc808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014984) /* 0x5bc808 */);
    // 005ba187  e950feffff             -jmp 0x5b9fdc
    goto L_0x005b9fdc;
L_0x005ba18c:
    // 005ba18c  c60512c85b0001         -mov byte ptr [0x5bc812], 1
    app->getMemory<x86::reg8>(x86::reg32(6014994) /* 0x5bc812 */) = 1 /*0x1*/;
    // 005ba193  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005ba195  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005ba198  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba199  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba19a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba19b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba19c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba19d:
    // 005ba19d  a100c85b00             -mov eax, dword ptr [0x5bc800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005ba1a2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba1a4  8b1500c85b00           -mov edx, dword ptr [0x5bc800]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005ba1aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba1ab  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba1ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba1b0  0f8449fbffff           -je 0x5b9cff
    if (cpu.flags.zf)
    {
        goto L_0x005b9cff;
    }
    // 005ba1b6  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba1bd  740e                   -je 0x5ba1cd
    if (cpu.flags.zf)
    {
        goto L_0x005ba1cd;
    }
    // 005ba1bf  68d0c75b00             -push 0x5bc7d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014928 /*0x5bc7d0*/;
    cpu.esp -= 4;
    // 005ba1c4  ff156cc85b00           -call dword ptr [0x5bc86c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba1ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005ba1cd:
    // 005ba1cd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005ba1d2  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005ba1d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba1d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba1d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba1d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba1d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_5ba1dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba1dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba1dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba1de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba1df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005ba1e1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005ba1e3  803d12c85b0000         +cmp byte ptr [0x5bc812], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014994) /* 0x5bc812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba1ea  751f                   -jne 0x5ba20b
    if (!cpu.flags.zf)
    {
        goto L_0x005ba20b;
    }
L_0x005ba1ec:
    // 005ba1ec  803d15c85b0000         +cmp byte ptr [0x5bc815], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014997) /* 0x5bc815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba1f3  751d                   -jne 0x5ba212
    if (!cpu.flags.zf)
    {
        goto L_0x005ba212;
    }
    // 005ba1f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005ba1fa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005ba1fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005ba1fe  e869f9ffff             -call 0x5b9b6c
    cpu.esp -= 4;
    sub_5b9b6c(app, cpu);
    if (cpu.terminate) return;
    // 005ba203  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba205  750b                   -jne 0x5ba212
    if (!cpu.flags.zf)
    {
        goto L_0x005ba212;
    }
    // 005ba207  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba208  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba209  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba20a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba20b:
    // 005ba20b  e814000000             -call 0x5ba224
    cpu.esp -= 4;
    sub_5ba224(app, cpu);
    if (cpu.terminate) return;
    // 005ba210  ebda                   -jmp 0x5ba1ec
    goto L_0x005ba1ec;
L_0x005ba212:
    // 005ba212  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005ba214  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005ba216  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005ba218  e84ff9ffff             -call 0x5b9b6c
    cpu.esp -= 4;
    sub_5b9b6c(app, cpu);
    if (cpu.terminate) return;
    // 005ba21d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba21e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba21f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba220  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_5ba224(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba224  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba225  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba226  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba227  803d12c85b0000         +cmp byte ptr [0x5bc812], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014994) /* 0x5bc812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba22e  7534                   -jne 0x5ba264
    if (!cpu.flags.zf)
    {
        goto L_0x005ba264;
    }
L_0x005ba230:
    // 005ba230  803d10c85b0000         +cmp byte ptr [0x5bc810], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba237  7425                   -je 0x5ba25e
    if (cpu.flags.zf)
    {
        goto L_0x005ba25e;
    }
    // 005ba239  833d00c85b0000         +cmp dword ptr [0x5bc800], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba240  7558                   -jne 0x5ba29a
    if (!cpu.flags.zf)
    {
        goto L_0x005ba29a;
    }
L_0x005ba242:
    // 005ba242  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005ba243  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba244  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005ba246  893d00c85b00           -mov dword ptr [0x5bc800], edi
    app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */) = cpu.edi;
    // 005ba24c  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 005ba24e  881d11c85b00           -mov byte ptr [0x5bc811], bl
    app->getMemory<x86::reg8>(x86::reg32(6014993) /* 0x5bc811 */) = cpu.bl;
    // 005ba254  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 005ba256  883d10c85b00           -mov byte ptr [0x5bc810], bh
    app->getMemory<x86::reg8>(x86::reg32(6014992) /* 0x5bc810 */) = cpu.bh;
    // 005ba25c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba25d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x005ba25e:
    // 005ba25e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005ba260  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba261  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba262  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba263  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba264:
    // 005ba264  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 005ba266  881512c85b00           -mov byte ptr [0x5bc812], dl
    app->getMemory<x86::reg8>(x86::reg32(6014994) /* 0x5bc812 */) = cpu.dl;
    // 005ba26c  a104c85b00             -mov eax, dword ptr [0x5bc804]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005ba271  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba273  8b1504c85b00           -mov edx, dword ptr [0x5bc804]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014980) /* 0x5bc804 */);
    // 005ba279  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba27a  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba27d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba27f  74af                   -je 0x5ba230
    if (cpu.flags.zf)
    {
        goto L_0x005ba230;
    }
    // 005ba281  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba288  74a6                   -je 0x5ba230
    if (cpu.flags.zf)
    {
        goto L_0x005ba230;
    }
    // 005ba28a  68a0c75b00             -push 0x5bc7a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014880 /*0x5bc7a0*/;
    cpu.esp -= 4;
    // 005ba28f  ff156cc85b00           -call dword ptr [0x5bc86c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba295  83c404                 +add esp, 4
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
    // 005ba298  eb96                   -jmp 0x5ba230
    goto L_0x005ba230;
L_0x005ba29a:
    // 005ba29a  a100c85b00             -mov eax, dword ptr [0x5bc800]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005ba29f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba2a1  8b3500c85b00           -mov esi, dword ptr [0x5bc800]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6014976) /* 0x5bc800 */);
    // 005ba2a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba2a8  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba2ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba2ad  7493                   -je 0x5ba242
    if (cpu.flags.zf)
    {
        goto L_0x005ba242;
    }
    // 005ba2af  833d6cc85b0000         +cmp dword ptr [0x5bc86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba2b6  740e                   -je 0x5ba2c6
    if (cpu.flags.zf)
    {
        goto L_0x005ba2c6;
    }
    // 005ba2b8  68d0c75b00             -push 0x5bc7d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6014928 /*0x5bc7d0*/;
    cpu.esp -= 4;
    // 005ba2bd  ff156cc85b00           -call dword ptr [0x5bc86c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6015084) /* 0x5bc86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba2c3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005ba2c6:
    // 005ba2c6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005ba2cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba2cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba2cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba2ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5ba2d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba2d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba2d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba2d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba2d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005ba2d4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005ba2d6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005ba2d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005ba2da  7e43                   -jle 0x5ba31f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005ba31f;
    }
L_0x005ba2dc:
    // 005ba2dc  833d48c85b0000         +cmp dword ptr [0x5bc848], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015048) /* 0x5bc848 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba2e3  7e3f                   -jle 0x5ba324
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005ba324;
    }
L_0x005ba2e5:
    // 005ba2e5  a148c85b00             -mov eax, dword ptr [0x5bc848]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015048) /* 0x5bc848 */);
    // 005ba2ea  39c6                   +cmp esi, eax
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
    // 005ba2ec  0f8e98000000           -jle 0x5ba38a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005ba38a;
    }
    // 005ba2f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005ba2f4:
    // 005ba2f4  8b1548c85b00           -mov edx, dword ptr [0x5bc848]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015048) /* 0x5bc848 */);
    // 005ba2fa  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005ba2fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005ba2fe  891548c85b00           -mov dword ptr [0x5bc848], edx
    app->getMemory<x86::reg32>(x86::reg32(6015048) /* 0x5bc848 */) = cpu.edx;
    // 005ba304  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005ba306  ff1568c85b00           -call dword ptr [0x5bc868]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6015080) /* 0x5bc868 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba30c  8b0d11c85b00           -mov ecx, dword ptr [0x5bc811]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014993) /* 0x5bc811 */);
    // 005ba312  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 005ba315  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005ba317  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 005ba319  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005ba31b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005ba31d  7fbd                   -jg 0x5ba2dc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005ba2dc;
    }
L_0x005ba31f:
    // 005ba31f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba320  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba321  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba322  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba323  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba324:
    // 005ba324  ff054cc85b00           -inc dword ptr [0x5bc84c]
    (app->getMemory<x86::reg32>(x86::reg32(6015052) /* 0x5bc84c */))++;
    // 005ba32a  ff1574c85b00           -call dword ptr [0x5bc874]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6015092) /* 0x5bc874 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba330  a14cc85b00             -mov eax, dword ptr [0x5bc84c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015052) /* 0x5bc84c */);
    // 005ba335  0faf0564c85b00         -imul eax, dword ptr [0x5bc864]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015076) /* 0x5bc864 */))));
    // 005ba33c  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 005ba341  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005ba343  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005ba345  8b0d50c85b00           -mov ecx, dword ptr [0x5bc850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6015056) /* 0x5bc850 */);
    // 005ba34b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005ba34d  a348c85b00             -mov dword ptr [0x5bc848], eax
    app->getMemory<x86::reg32>(x86::reg32(6015048) /* 0x5bc848 */) = cpu.eax;
    // 005ba352  25f0ffff0f             -and eax, 0xffffff0
    cpu.eax &= x86::reg32(x86::sreg32(268435440 /*0xffffff0*/));
    // 005ba357  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 005ba35a  a348c85b00             -mov dword ptr [0x5bc848], eax
    app->getMemory<x86::reg32>(x86::reg32(6015048) /* 0x5bc848 */) = cpu.eax;
    // 005ba35f  8b0d4cc85b00           -mov ecx, dword ptr [0x5bc84c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6015052) /* 0x5bc84c */);
    // 005ba365  891550c85b00           -mov dword ptr [0x5bc850], edx
    app->getMemory<x86::reg32>(x86::reg32(6015056) /* 0x5bc850 */) = cpu.edx;
    // 005ba36b  81f930750000           +cmp ecx, 0x7530
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30000 /*0x7530*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba371  0f8e6effffff           -jle 0x5ba2e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005ba2e5;
    }
    // 005ba377  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 005ba379  891d4cc85b00           -mov dword ptr [0x5bc84c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6015052) /* 0x5bc84c */) = cpu.ebx;
    // 005ba37f  891d50c85b00           -mov dword ptr [0x5bc850], ebx
    app->getMemory<x86::reg32>(x86::reg32(6015056) /* 0x5bc850 */) = cpu.ebx;
    // 005ba385  e95bffffff             -jmp 0x5ba2e5
    goto L_0x005ba2e5;
L_0x005ba38a:
    // 005ba38a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005ba38c  e963ffffff             -jmp 0x5ba2f4
    goto L_0x005ba2f4;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_5ba394(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba394  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba395  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba396  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba397  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba398  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005ba399  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005ba39a  8b1518c85b00           -mov edx, dword ptr [0x5bc818]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */);
    // 005ba3a0  81fa00000011           +cmp edx, 0x11000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(285212672 /*0x11000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba3a6  0f879f000000           -ja 0x5ba44b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005ba44b;
    }
L_0x005ba3ac:
    // 005ba3ac  a118c85b00             -mov eax, dword ptr [0x5bc818]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */);
    // 005ba3b1  8b351cc85b00           -mov esi, dword ptr [0x5bc81c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6015004) /* 0x5bc81c */);
    // 005ba3b7  8b3d5cc85b00           -mov edi, dword ptr [0x5bc85c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */);
    // 005ba3bd  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 005ba3bf  39f8                   +cmp eax, edi
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
    // 005ba3c1  7c10                   -jl 0x5ba3d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005ba3d3;
    }
    // 005ba3c3  8b2d18c85b00           -mov ebp, dword ptr [0x5bc818]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */);
    // 005ba3c9  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005ba3cb  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005ba3cd  892d18c85b00           -mov dword ptr [0x5bc818], ebp
    app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */) = cpu.ebp;
L_0x005ba3d3:
    // 005ba3d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba3d5  0f8cab000000           -jl 0x5ba486
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005ba486;
    }
    // 005ba3db  8b1544c85b00           -mov edx, dword ptr [0x5bc844]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015044) /* 0x5bc844 */);
    // 005ba3e1  42                     -inc edx
    (cpu.edx)++;
    // 005ba3e2  8b0d40c85b00           -mov ecx, dword ptr [0x5bc840]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6015040) /* 0x5bc840 */);
    // 005ba3e8  891544c85b00           -mov dword ptr [0x5bc844], edx
    app->getMemory<x86::reg32>(x86::reg32(6015044) /* 0x5bc844 */) = cpu.edx;
    // 005ba3ee  39c8                   +cmp eax, ecx
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
    // 005ba3f0  0f8c78000000           -jl 0x5ba46e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005ba46e;
    }
L_0x005ba3f6:
    // 005ba3f6  8b1d44c85b00           -mov ebx, dword ptr [0x5bc844]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6015044) /* 0x5bc844 */);
    // 005ba3fc  81fbb80b0000           +cmp ebx, 0xbb8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3000 /*0xbb8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba402  7c40                   -jl 0x5ba444
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005ba444;
    }
    // 005ba404  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 005ba409  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005ba40b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005ba40d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005ba410  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005ba412  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005ba414  752e                   -jne 0x5ba444
    if (!cpu.flags.zf)
    {
        goto L_0x005ba444;
    }
    // 005ba416  833d40c85b0010         +cmp dword ptr [0x5bc840], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015040) /* 0x5bc840 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba41d  7e56                   -jle 0x5ba475
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005ba475;
    }
    // 005ba41f  8b3d30c85b00           -mov edi, dword ptr [0x5bc830]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */);
    // 005ba425  4f                     -dec edi
    (cpu.edi)--;
    // 005ba426  a15cc85b00             -mov eax, dword ptr [0x5bc85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */);
    // 005ba42b  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 005ba42d  893d30c85b00           -mov dword ptr [0x5bc830], edi
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.edi;
    // 005ba433  81e5f0ff0f00           -and ebp, 0xffff0
    cpu.ebp &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005ba439  a340c85b00             -mov dword ptr [0x5bc840], eax
    app->getMemory<x86::reg32>(x86::reg32(6015040) /* 0x5bc840 */) = cpu.eax;
    // 005ba43e  892d30c85b00           -mov dword ptr [0x5bc830], ebp
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.ebp;
L_0x005ba444:
    // 005ba444  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba445  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba446  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba447  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba448  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba449  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba44a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba44b:
    // 005ba44b  8b1d1cc85b00           -mov ebx, dword ptr [0x5bc81c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6015004) /* 0x5bc81c */);
    // 005ba451  8d8a000000f0           -lea ecx, [edx - 0x10000000]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-268435456) /* -0x10000000 */);
    // 005ba457  81eb00000010           +sub ebx, 0x10000000
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005ba45d  890d18c85b00           -mov dword ptr [0x5bc818], ecx
    app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */) = cpu.ecx;
    // 005ba463  891d1cc85b00           -mov dword ptr [0x5bc81c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6015004) /* 0x5bc81c */) = cpu.ebx;
    // 005ba469  e93effffff             -jmp 0x5ba3ac
    goto L_0x005ba3ac;
L_0x005ba46e:
    // 005ba46e  a340c85b00             -mov dword ptr [0x5bc840], eax
    app->getMemory<x86::reg32>(x86::reg32(6015040) /* 0x5bc840 */) = cpu.eax;
    // 005ba473  eb81                   -jmp 0x5ba3f6
    goto L_0x005ba3f6;
L_0x005ba475:
    // 005ba475  a15cc85b00             -mov eax, dword ptr [0x5bc85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */);
    // 005ba47a  a340c85b00             -mov dword ptr [0x5bc840], eax
    app->getMemory<x86::reg32>(x86::reg32(6015040) /* 0x5bc840 */) = cpu.eax;
    // 005ba47f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba480  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba481  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba482  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba483  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba484  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba485  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba486:
    // 005ba486  833d18c85b0000         +cmp dword ptr [0x5bc818], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba48d  74b5                   -je 0x5ba444
    if (cpu.flags.zf)
    {
        goto L_0x005ba444;
    }
    // 005ba48f  8b1d30c85b00           -mov ebx, dword ptr [0x5bc830]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */);
    // 005ba495  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005ba497  891d30c85b00           -mov dword ptr [0x5bc830], ebx
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.ebx;
    // 005ba49d  8d730f                 -lea esi, [ebx + 0xf]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 005ba4a0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 005ba4a2  893530c85b00           -mov dword ptr [0x5bc830], esi
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.esi;
    // 005ba4a8  81e7f0ff0f00           -and edi, 0xffff0
    cpu.edi &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005ba4ae  8b2d34c85b00           -mov ebp, dword ptr [0x5bc834]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6015028) /* 0x5bc834 */);
    // 005ba4b4  893d30c85b00           -mov dword ptr [0x5bc830], edi
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.edi;
    // 005ba4ba  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba4bc  7e06                   -jle 0x5ba4c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005ba4c4;
    }
    // 005ba4be  892d30c85b00           -mov dword ptr [0x5bc830], ebp
    app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */) = cpu.ebp;
L_0x005ba4c4:
    // 005ba4c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005ba4c6  a344c85b00             -mov dword ptr [0x5bc844], eax
    app->getMemory<x86::reg32>(x86::reg32(6015044) /* 0x5bc844 */) = cpu.eax;
    // 005ba4cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_5ba4d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba4d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba4d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba4d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba4d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba4d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005ba4d9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005ba4dc  803d12c85b0000         +cmp byte ptr [0x5bc812], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014994) /* 0x5bc812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba4e3  7509                   -jne 0x5ba4ee
    if (!cpu.flags.zf)
    {
        goto L_0x005ba4ee;
    }
L_0x005ba4e5:
    // 005ba4e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005ba4e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba4ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba4ee:
    // 005ba4ee  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba4f3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba4f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005ba4f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005ba4f8  8b0d0cc85b00           -mov ecx, dword ptr [0x5bc80c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba4fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba4ff  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba502  f6042402               +test byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 2 /*0x2*/));
    // 005ba506  0f85e4000000           -jne 0x5ba5f0
    if (!cpu.flags.zf)
    {
        goto L_0x005ba5f0;
    }
    // 005ba50c  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba511  6820c85b00             -push 0x5bc820
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015008 /*0x5bc820*/;
    cpu.esp -= 4;
    // 005ba516  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba518  6824c85b00             -push 0x5bc824
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015012 /*0x5bc824*/;
    cpu.esp -= 4;
    // 005ba51d  8b1d0cc85b00           -mov ebx, dword ptr [0x5bc80c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba523  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba524  ff5010                 -call dword ptr [eax + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba527  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba529  75ba                   -jne 0x5ba4e5
    if (!cpu.flags.zf)
    {
        goto L_0x005ba4e5;
    }
    // 005ba52b  803d15c85b0000         +cmp byte ptr [0x5bc815], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014997) /* 0x5bc815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba532  740a                   -je 0x5ba53e
    if (cpu.flags.zf)
    {
        goto L_0x005ba53e;
    }
    // 005ba534  a120c85b00             -mov eax, dword ptr [0x5bc820]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015008) /* 0x5bc820 */);
    // 005ba539  a324c85b00             -mov dword ptr [0x5bc824], eax
    app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */) = cpu.eax;
L_0x005ba53e:
    // 005ba53e  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba545  d32d24c85b00           -shr dword ptr [0x5bc824], cl
    app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */) >>= cpu.cl % 32;
    // 005ba54b  812524c85b00f0ff0f00   -and dword ptr [0x5bc824], 0xffff0
    app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005ba555  a124c85b00             -mov eax, dword ptr [0x5bc824]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */);
    // 005ba55a  3b0528c85b00           +cmp eax, dword ptr [0x5bc828]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015016) /* 0x5bc828 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba560  0f82a4000000           -jb 0x5ba60a
    if (cpu.flags.cf)
    {
        goto L_0x005ba60a;
    }
    // 005ba566  a124c85b00             -mov eax, dword ptr [0x5bc824]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */);
L_0x005ba56b:
    // 005ba56b  2b0528c85b00           -sub eax, dword ptr [0x5bc828]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015016) /* 0x5bc828 */)));
    // 005ba571  01051cc85b00           -add dword ptr [0x5bc81c], eax
    (app->getMemory<x86::reg32>(x86::reg32(6015004) /* 0x5bc81c */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 005ba577  a124c85b00             -mov eax, dword ptr [0x5bc824]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */);
    // 005ba57c  3b0528c85b00           +cmp eax, dword ptr [0x5bc828]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015016) /* 0x5bc828 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba582  0f8592000000           -jne 0x5ba61a
    if (!cpu.flags.zf)
    {
        goto L_0x005ba61a;
    }
    // 005ba588  8b157cc85b00           -mov edx, dword ptr [0x5bc87c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015100) /* 0x5bc87c */);
    // 005ba58e  42                     -inc edx
    (cpu.edx)++;
    // 005ba58f  89157cc85b00           -mov dword ptr [0x5bc87c], edx
    app->getMemory<x86::reg32>(x86::reg32(6015100) /* 0x5bc87c */) = cpu.edx;
    // 005ba595  81faf4010000           +cmp edx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba59b  0f8f85000000           -jg 0x5ba626
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005ba626;
    }
L_0x005ba5a1:
    // 005ba5a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x005ba5a2:
    // 005ba5a2  8b1d24c85b00           -mov ebx, dword ptr [0x5bc824]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */);
    // 005ba5a8  031d30c85b00           -add ebx, dword ptr [0x5bc830]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */)));
    // 005ba5ae  81e3f0ff0f00           -and ebx, 0xffff0
    cpu.ebx &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005ba5b4  3b1d5cc85b00           +cmp ebx, dword ptr [0x5bc85c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba5ba  7c06                   -jl 0x5ba5c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005ba5c2;
    }
    // 005ba5bc  2b1d5cc85b00           -sub ebx, dword ptr [0x5bc85c]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */)));
L_0x005ba5c2:
    // 005ba5c2  3b1d2cc85b00           +cmp ebx, dword ptr [0x5bc82c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015020) /* 0x5bc82c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005ba5c8  0f8c78000000           -jl 0x5ba646
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005ba646;
    }
    // 005ba5ce  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 005ba5d0  2b352cc85b00           -sub esi, dword ptr [0x5bc82c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015020) /* 0x5bc82c */)));
    // 005ba5d6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x005ba5d8:
    // 005ba5d8  a15cc85b00             -mov eax, dword ptr [0x5bc85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */);
    // 005ba5dd  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005ba5e0  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 005ba5e3  39c2                   +cmp edx, eax
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
    // 005ba5e5  7c71                   -jl 0x5ba658
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005ba658;
    }
    // 005ba5e7  830530c85b0010         +add dword ptr [0x5bc830], 0x10
    {
        auto tmp1 = app->getMemory<x86::reg32>(x86::reg32(6015024) /* 0x5bc830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005ba5ee  ebb2                   -jmp 0x5ba5a2
    goto L_0x005ba5a2;
L_0x005ba5f0:
    // 005ba5f0  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba5f5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba5f7  8b350cc85b00           -mov esi, dword ptr [0x5bc80c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba5fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba5fe  ff5050                 -call dword ptr [eax + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba601  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005ba604  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba605  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba606  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba607  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba608  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba609  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba60a:
    // 005ba60a  a124c85b00             -mov eax, dword ptr [0x5bc824]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */);
    // 005ba60f  03055cc85b00           +add eax, dword ptr [0x5bc85c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005ba615  e951ffffff             -jmp 0x5ba56b
    goto L_0x005ba56b;
L_0x005ba61a:
    // 005ba61a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005ba61c  a37cc85b00             -mov dword ptr [0x5bc87c], eax
    app->getMemory<x86::reg32>(x86::reg32(6015100) /* 0x5bc87c */) = cpu.eax;
    // 005ba621  e97bffffff             -jmp 0x5ba5a1
    goto L_0x005ba5a1;
L_0x005ba626:
    // 005ba626  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005ba628  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba62d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba62f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba631  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba633  8b1d0cc85b00           -mov ebx, dword ptr [0x5bc80c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba639  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005ba63a  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba63d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005ba640  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba641  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba642  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba643  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba644  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba645  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005ba646:
    // 005ba646  8b355cc85b00           -mov esi, dword ptr [0x5bc85c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6015068) /* 0x5bc85c */);
    // 005ba64c  8b0d2cc85b00           -mov ecx, dword ptr [0x5bc82c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6015020) /* 0x5bc82c */);
    // 005ba652  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 005ba654  29ce                   +sub esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005ba656  eb80                   -jmp 0x5ba5d8
    goto L_0x005ba5d8;
L_0x005ba658:
    // 005ba658  803d15c85b0000         +cmp byte ptr [0x5bc815], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6014997) /* 0x5bc815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005ba65f  7505                   -jne 0x5ba666
    if (!cpu.flags.zf)
    {
        goto L_0x005ba666;
    }
    // 005ba661  e82efdffff             -call 0x5ba394
    cpu.esp -= 4;
    sub_5ba394(app, cpu);
    if (cpu.terminate) return;
L_0x005ba666:
    // 005ba666  a124c85b00             -mov eax, dword ptr [0x5bc824]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015012) /* 0x5bc824 */);
    // 005ba66b  a328c85b00             -mov dword ptr [0x5bc828], eax
    app->getMemory<x86::reg32>(x86::reg32(6015016) /* 0x5bc828 */) = cpu.eax;
    // 005ba670  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005ba672  0f84ef000000           -je 0x5ba767
    if (cpu.flags.zf)
    {
        goto L_0x005ba767;
    }
    // 005ba678  013518c85b00           -add dword ptr [0x5bc818], esi
    (app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */)) += x86::reg32(x86::sreg32(cpu.esi));
    // 005ba67e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba680  8b150cc85b00           -mov edx, dword ptr [0x5bc80c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba686  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba688  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005ba68a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba68c  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba693  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005ba695  6858c85b00             -push 0x5bc858
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015064 /*0x5bc858*/;
    cpu.esp -= 4;
    // 005ba69a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005ba69c  6854c85b00             -push 0x5bc854
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015060 /*0x5bc854*/;
    cpu.esp -= 4;
    // 005ba6a1  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba6a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005ba6a9  a12cc85b00             -mov eax, dword ptr [0x5bc82c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015020) /* 0x5bc82c */);
    // 005ba6ae  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005ba6b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005ba6b1  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba6b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005ba6b7  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba6ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba6bc  7532                   -jne 0x5ba6f0
    if (!cpu.flags.zf)
    {
        goto L_0x005ba6f0;
    }
    // 005ba6be  a154c85b00             -mov eax, dword ptr [0x5bc854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015060) /* 0x5bc854 */);
    // 005ba6c3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005ba6c5  e806fcffff             -call 0x5ba2d0
    cpu.esp -= 4;
    sub_5ba2d0(app, cpu);
    if (cpu.terminate) return;
    // 005ba6ca  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba6cf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba6d1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba6d3  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba6da  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba6dc  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 005ba6de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005ba6df  8b1554c85b00           -mov edx, dword ptr [0x5bc854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015060) /* 0x5bc854 */);
    // 005ba6e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba6e6  8b0d0cc85b00           -mov ecx, dword ptr [0x5bc80c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba6ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba6ed  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005ba6f0:
    // 005ba6f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005ba6f2  7473                   -je 0x5ba767
    if (cpu.flags.zf)
    {
        goto L_0x005ba767;
    }
    // 005ba6f4  8b3518c85b00           -mov esi, dword ptr [0x5bc818]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */);
    // 005ba6fa  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 005ba6fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba6fe  893518c85b00           -mov dword ptr [0x5bc818], esi
    app->getMemory<x86::reg32>(x86::reg32(6015000) /* 0x5bc818 */) = cpu.esi;
    // 005ba704  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba706  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba70b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba70d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba70f  6858c85b00             -push 0x5bc858
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015064 /*0x5bc858*/;
    cpu.esp -= 4;
    // 005ba714  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba71b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005ba71d  6854c85b00             -push 0x5bc854
    app->getMemory<x86::reg32>(cpu.esp-4) = 6015060 /*0x5bc854*/;
    cpu.esp -= 4;
    // 005ba722  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 005ba724  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba725  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba727  8b2d0cc85b00           -mov ebp, dword ptr [0x5bc80c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba72d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005ba72e  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005ba731  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005ba733  750c                   -jne 0x5ba741
    if (!cpu.flags.zf)
    {
        goto L_0x005ba741;
    }
    // 005ba735  a154c85b00             -mov eax, dword ptr [0x5bc854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6015060) /* 0x5bc854 */);
    // 005ba73a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005ba73c  e88ffbffff             -call 0x5ba2d0
    cpu.esp -= 4;
    sub_5ba2d0(app, cpu);
    if (cpu.terminate) return;
L_0x005ba741:
    // 005ba741  a10cc85b00             -mov eax, dword ptr [0x5bc80c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba746  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005ba748  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba74a  0fbe0d14c85b00         -movsx ecx, byte ptr [0x5bc814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6014996) /* 0x5bc814 */)));
    // 005ba751  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005ba753  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 005ba755  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005ba756  8b1554c85b00           -mov edx, dword ptr [0x5bc854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6015060) /* 0x5bc854 */);
    // 005ba75c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005ba75d  8b0d0cc85b00           -mov ecx, dword ptr [0x5bc80c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6014988) /* 0x5bc80c */);
    // 005ba763  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba764  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005ba767:
    // 005ba767  891d2cc85b00           -mov dword ptr [0x5bc82c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6015020) /* 0x5bc82c */) = cpu.ebx;
    // 005ba76d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba76e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005ba771  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba772  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba773  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba775  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba776  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_5ba777(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba777  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba778  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005ba77a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005ba77b  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 005ba77d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005ba780  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 005ba782  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005ba785  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 005ba787  e804000000             -call 0x5ba790
    cpu.esp -= 4;
    sub_5ba790(app, cpu);
    if (cpu.terminate) return;
    // 005ba78c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba78d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba78e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_5ba790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba790  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005ba792  742c                   -je 0x5ba7c0
    if (cpu.flags.zf)
    {
        goto L_0x005ba7c0;
    }
    // 005ba794  3810                   -cmp byte ptr [eax], dl
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
L_0x005ba796:
    // 005ba796  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 005ba798  7409                   -je 0x5ba7a3
    if (cpu.flags.zf)
    {
        goto L_0x005ba7a3;
    }
    // 005ba79a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 005ba79c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005ba79d  c1ca08                 +ror edx, 8
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
    // 005ba7a0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7a1  75f3                   -jne 0x5ba796
    if (!cpu.flags.zf)
    {
        goto L_0x005ba796;
    }
L_0x005ba7a3:
    // 005ba7a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba7a4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005ba7a7  e81b000000             -call 0x5ba7c7
    cpu.esp -= 4;
    sub_5ba7c7(app, cpu);
    if (cpu.terminate) return;
    // 005ba7ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba7ad  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 005ba7b0  740e                   -je 0x5ba7c0
    if (cpu.flags.zf)
    {
        goto L_0x005ba7c0;
    }
    // 005ba7b2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 005ba7b4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7b5  7409                   -je 0x5ba7c0
    if (cpu.flags.zf)
    {
        goto L_0x005ba7c0;
    }
    // 005ba7b7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 005ba7ba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7bb  7403                   -je 0x5ba7c0
    if (cpu.flags.zf)
    {
        goto L_0x005ba7c0;
    }
    // 005ba7bd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x005ba7c0:
    // 005ba7c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5ba7c2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba7c2  90                     -nop 
    ;
    // 005ba7c3  90                     -nop 
    ;
    // 005ba7c4  90                     -nop 
    ;
    // 005ba7c5  90                     -nop 
    ;
    // 005ba7c6  90                     -nop 
    ;
    // 005ba7c7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005ba7c9  7467                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
L_0x005ba7cb:
    // 005ba7cb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 005ba7cd  7408                   -je 0x5ba7d7
    if (cpu.flags.zf)
    {
        goto L_0x005ba7d7;
    }
    // 005ba7cf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba7d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005ba7d4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7d5  75f4                   -jne 0x5ba7cb
    if (!cpu.flags.zf)
    {
        goto L_0x005ba7cb;
    }
L_0x005ba7d7:
    // 005ba7d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba7d8  c1e902                 +shr ecx, 2
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
    // 005ba7db  743a                   -je 0x5ba817
    if (cpu.flags.zf)
    {
        goto L_0x005ba817;
    }
    // 005ba7dd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7de  7429                   -je 0x5ba809
    if (cpu.flags.zf)
    {
        goto L_0x005ba809;
    }
L_0x005ba7e0:
    // 005ba7e0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba7e2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005ba7e5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7e6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005ba7e9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005ba7ec  7418                   -je 0x5ba806
    if (cpu.flags.zf)
    {
        goto L_0x005ba806;
    }
    // 005ba7ee  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 005ba7f1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005ba7f4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005ba7f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7f8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005ba7fb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005ba7fe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005ba801  75dd                   -jne 0x5ba7e0
    if (!cpu.flags.zf)
    {
        goto L_0x005ba7e0;
    }
    // 005ba803  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x005ba806:
    // 005ba806  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005ba809:
    // 005ba809  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba80b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005ba80e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005ba811  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005ba814  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005ba817:
    // 005ba817  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba818  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 005ba81b  7415                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
    // 005ba81d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba81f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005ba822  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba823  740d                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
    // 005ba825  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba827  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005ba82a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba82b  7405                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
    // 005ba82d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba82f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x005ba832:
    // 005ba832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_5ba7c7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x005ba7c7;
    // 005ba7c2  90                     -nop 
    ;
    // 005ba7c3  90                     -nop 
    ;
    // 005ba7c4  90                     -nop 
    ;
    // 005ba7c5  90                     -nop 
    ;
    // 005ba7c6  90                     -nop 
    ;
L_entry_0x005ba7c7:
    // 005ba7c7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005ba7c9  7467                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
L_0x005ba7cb:
    // 005ba7cb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 005ba7cd  7408                   -je 0x5ba7d7
    if (cpu.flags.zf)
    {
        goto L_0x005ba7d7;
    }
    // 005ba7cf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba7d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005ba7d4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7d5  75f4                   -jne 0x5ba7cb
    if (!cpu.flags.zf)
    {
        goto L_0x005ba7cb;
    }
L_0x005ba7d7:
    // 005ba7d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005ba7d8  c1e902                 +shr ecx, 2
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
    // 005ba7db  743a                   -je 0x5ba817
    if (cpu.flags.zf)
    {
        goto L_0x005ba817;
    }
    // 005ba7dd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7de  7429                   -je 0x5ba809
    if (cpu.flags.zf)
    {
        goto L_0x005ba809;
    }
L_0x005ba7e0:
    // 005ba7e0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba7e2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005ba7e5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7e6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005ba7e9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005ba7ec  7418                   -je 0x5ba806
    if (cpu.flags.zf)
    {
        goto L_0x005ba806;
    }
    // 005ba7ee  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 005ba7f1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005ba7f4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005ba7f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba7f8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005ba7fb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005ba7fe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005ba801  75dd                   -jne 0x5ba7e0
    if (!cpu.flags.zf)
    {
        goto L_0x005ba7e0;
    }
    // 005ba803  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x005ba806:
    // 005ba806  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005ba809:
    // 005ba809  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba80b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005ba80e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005ba811  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005ba814  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005ba817:
    // 005ba817  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005ba818  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 005ba81b  7415                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
    // 005ba81d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba81f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005ba822  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba823  740d                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
    // 005ba825  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba827  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005ba82a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005ba82b  7405                   -je 0x5ba832
    if (cpu.flags.zf)
    {
        goto L_0x005ba832;
    }
    // 005ba82d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005ba82f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x005ba832:
    // 005ba832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_5ba834(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba834  ff2530b65b00           -jmp dword ptr [0x5bb630]
    return app->dynamic_call(app->getMemory<x86::reg32>(6010416), cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_5ba840(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005ba840  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba842  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba844  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba846  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba848  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba84a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba84c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba84e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba850  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba852  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba854  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba856  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba858  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba85a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba85c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba85e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba860  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba862  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba864  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba866  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba868  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba86a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba86c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba86e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba870  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba872  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba874  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba876  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba878  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba87a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba87c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba87e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba880  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba882  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba884  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba886  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba888  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba88a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba88c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba88e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba890  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba892  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba894  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba896  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba898  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba89a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba89c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba89e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba8fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba900  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba902  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba904  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba906  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba908  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba90a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba90c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba90e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba910  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba912  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba914  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba916  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba918  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba91a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba91c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba91e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba920  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba922  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba924  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba926  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba928  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba92a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba92c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba92e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba930  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba932  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba934  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba936  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba938  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba93a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba93c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba93e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba940  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba942  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba944  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba946  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba948  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba94a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba94c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba94e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba950  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba952  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba954  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba956  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba958  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba95a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba95c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba95e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba960  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba962  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba964  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba966  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba968  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba96a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba96c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba96e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba970  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba972  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba974  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba976  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba978  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba97a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba97c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba97e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba980  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba982  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba984  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba986  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba988  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba98a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba98c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba98e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba990  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba992  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba994  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba996  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba998  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba99a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba99c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba99e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005ba9fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
