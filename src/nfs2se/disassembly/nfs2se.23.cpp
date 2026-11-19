#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_48c370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c370  a1e8c24c00             -mov eax, dword ptr [0x4cc2e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030632) /* 0x4cc2e8 */);
    // 0048c375  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c378(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c378  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c379  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c37a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c37b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c37c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c37d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048c37f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048c381  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048c383  803d7dc34c0002         +cmp byte ptr [0x4cc37d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c38a  0f850e010000           -jne 0x48c49e
    if (!cpu.flags.zf)
    {
        goto L_0x0048c49e;
    }
L_0x0048c390:
    // 0048c390  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c395  3b05f4c24c00           +cmp eax, dword ptr [0x4cc2f4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c39b  0f8482000000           -je 0x48c423
    if (cpu.flags.zf)
    {
        goto L_0x0048c423;
    }
    // 0048c3a1  8b3df0c24c00           -mov edi, dword ptr [0x4cc2f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c3a7  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c3ac  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c3ae  a3f0c24c00             -mov dword ptr [0x4cc2f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */) = cpu.eax;
    // 0048c3b3  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c3b6  833df8c24c0000         +cmp dword ptr [0x4cc2f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c3bd  7410                   -je 0x48c3cf
    if (cpu.flags.zf)
    {
        goto L_0x0048c3cf;
    }
    // 0048c3bf  8b15f8c24c00           -mov edx, dword ptr [0x4cc2f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */);
    // 0048c3c5  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c3ca  e811f4ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048c3cf:
    // 0048c3cf  893df8c24c00           -mov dword ptr [0x4cc2f8], edi
    app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */) = cpu.edi;
    // 0048c3d5  a108c34c00             -mov eax, dword ptr [0x4cc308]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */);
    // 0048c3da  ff0d08c34c00           -dec dword ptr [0x4cc308]
    (app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */))--;
    // 0048c3e0  292d0cc34c00           -sub dword ptr [0x4cc30c], ebp
    (app->getMemory<x86::reg32>(x86::reg32(5030668) /* 0x4cc30c */)) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048c3e6  a104c34c00             -mov eax, dword ptr [0x4cc304]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030660) /* 0x4cc304 */);
    // 0048c3eb  ff0504c34c00           -inc dword ptr [0x4cc304]
    (app->getMemory<x86::reg32>(x86::reg32(5030660) /* 0x4cc304 */))++;
    // 0048c3f1  0fbe057ec34c00         -movsx eax, byte ptr [0x4cc37e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */)));
    // 0048c3f8  8b14858cc34c00         -mov edx, dword ptr [eax*4 + 0x4cc38c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.eax * 4);
    // 0048c3ff  ff0c858cc34c00         -dec dword ptr [eax*4 + 0x4cc38c]
    (app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.eax * 4))--;
    // 0048c406  0fbe057ec34c00         -movsx eax, byte ptr [0x4cc37e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */)));
    // 0048c40d  833c858cc34c0000       +cmp dword ptr [eax*4 + 0x4cc38c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c415  0f8e95000000           -jle 0x48c4b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c4b0;
    }
L_0x0048c41b:
    // 0048c41b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0048c41d  88257dc34c00           -mov byte ptr [0x4cc37d], ah
    app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */) = cpu.ah;
L_0x0048c423:
    // 0048c423  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c428  3b05f4c24c00           +cmp eax, dword ptr [0x4cc2f4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c42e  0f85e0000000           -jne 0x48c514
    if (!cpu.flags.zf)
    {
        goto L_0x0048c514;
    }
    // 0048c434  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c439  8338ff                 +cmp dword ptr [eax], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c43c  0f84ae000000           -je 0x48c4f0
    if (cpu.flags.zf)
    {
        goto L_0x0048c4f0;
    }
    // 0048c442  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c447  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048c44a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048c44c  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c451  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048c454  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048c456  803d7dc34c0001         +cmp byte ptr [0x4cc37d], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c45d  7519                   -jne 0x48c478
    if (!cpu.flags.zf)
    {
        goto L_0x0048c478;
    }
    // 0048c45f  0fbe3d71c34c00         -movsx edi, byte ptr [0x4cc371]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030769) /* 0x4cc371 */)));
    // 0048c466  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048c468  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048c46a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048c46c  e8ef3effff             -call 0x480360
    cpu.esp -= 4;
    sub_480360(app, cpu);
    if (cpu.terminate) return;
    // 0048c471  c6057dc34c0002         -mov byte ptr [0x4cc37d], 2
    app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */) = 2 /*0x2*/;
L_0x0048c478:
    // 0048c478  803d7dc34c0000         +cmp byte ptr [0x4cc37d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c47f  7507                   -jne 0x48c488
    if (!cpu.flags.zf)
    {
        goto L_0x0048c488;
    }
    // 0048c481  c6057dc34c0001         -mov byte ptr [0x4cc37d], 1
    app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */) = 1 /*0x1*/;
L_0x0048c488:
    // 0048c488  803d7dc34c0002         +cmp byte ptr [0x4cc37d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c48f  7505                   -jne 0x48c496
    if (!cpu.flags.zf)
    {
        goto L_0x0048c496;
    }
    // 0048c491  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0048c496:
    // 0048c496  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c498  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c499  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c49a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c49b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c49c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c49d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c49e:
    // 0048c49e  803d7dc34c0001         +cmp byte ptr [0x4cc37d], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c4a5  0f84e5feffff           -je 0x48c390
    if (cpu.flags.zf)
    {
        goto L_0x0048c390;
    }
    // 0048c4ab  e973ffffff             -jmp 0x48c423
    goto L_0x0048c423;
L_0x0048c4b0:
    // 0048c4b0  a07ac34c00             -mov al, byte ptr [0x4cc37a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */);
    // 0048c4b5  fe0d7ac34c00           -dec byte ptr [0x4cc37a]
    (app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */))--;
    // 0048c4bb  a07ec34c00             -mov al, byte ptr [0x4cc37e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */);
    // 0048c4c0  3a057fc34c00           +cmp al, byte ptr [0x4cc37f]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c4c6  0f844fffffff           -je 0x48c41b
    if (cpu.flags.zf)
    {
        goto L_0x0048c41b;
    }
    // 0048c4cc  a07ec34c00             -mov al, byte ptr [0x4cc37e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */);
    // 0048c4d1  fe057ec34c00           -inc byte ptr [0x4cc37e]
    (app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */))++;
    // 0048c4d7  803d7ec34c0014         +cmp byte ptr [0x4cc37e], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c4de  0f8c37ffffff           -jl 0x48c41b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c41b;
    }
    // 0048c4e4  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0048c4e6  a27ec34c00             -mov byte ptr [0x4cc37e], al
    app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */) = cpu.al;
    // 0048c4eb  e92bffffff             -jmp 0x48c41b
    goto L_0x0048c41b;
L_0x0048c4f0:
    // 0048c4f0  8b15f0c24c00           -mov edx, dword ptr [0x4cc2f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c4f6  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c4fb  e8e0f2ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c500  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0048c506  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0048c50c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c50e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c50f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c511  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c512  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c513  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c514:
    // 0048c514  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c519  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048c51c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048c51e  8b1df0c24c00           -mov ebx, dword ptr [0x4cc2f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c524  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048c527  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c529  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048c52b  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c530  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c532  a3f0c24c00             -mov dword ptr [0x4cc2f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */) = cpu.eax;
    // 0048c537  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048c53a  833df8c24c0000         +cmp dword ptr [0x4cc2f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c541  7410                   -je 0x48c553
    if (cpu.flags.zf)
    {
        goto L_0x0048c553;
    }
    // 0048c543  8b15f8c24c00           -mov edx, dword ptr [0x4cc2f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */);
    // 0048c549  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c54e  e88df2ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048c553:
    // 0048c553  891df8c24c00           -mov dword ptr [0x4cc2f8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */) = cpu.ebx;
    // 0048c559  a108c34c00             -mov eax, dword ptr [0x4cc308]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */);
    // 0048c55e  ff0d08c34c00           -dec dword ptr [0x4cc308]
    (app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */))--;
    // 0048c564  290d0cc34c00           -sub dword ptr [0x4cc30c], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5030668) /* 0x4cc30c */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c56a  a104c34c00             -mov eax, dword ptr [0x4cc304]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030660) /* 0x4cc304 */);
    // 0048c56f  ff0504c34c00           -inc dword ptr [0x4cc304]
    (app->getMemory<x86::reg32>(x86::reg32(5030660) /* 0x4cc304 */))++;
    // 0048c575  0fbe057ec34c00         -movsx eax, byte ptr [0x4cc37e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */)));
    // 0048c57c  8b14858cc34c00         -mov edx, dword ptr [eax*4 + 0x4cc38c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.eax * 4);
    // 0048c583  ff0c858cc34c00         -dec dword ptr [eax*4 + 0x4cc38c]
    (app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.eax * 4))--;
    // 0048c58a  0fbe057ec34c00         -movsx eax, byte ptr [0x4cc37e]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */)));
    // 0048c591  833c858cc34c0000       +cmp dword ptr [eax*4 + 0x4cc38c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c599  0f8ff7feffff           -jg 0x48c496
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c496;
    }
    // 0048c59f  a07ac34c00             -mov al, byte ptr [0x4cc37a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */);
    // 0048c5a4  fe0d7ac34c00           -dec byte ptr [0x4cc37a]
    (app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */))--;
    // 0048c5aa  a07ec34c00             -mov al, byte ptr [0x4cc37e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */);
    // 0048c5af  3a057fc34c00           +cmp al, byte ptr [0x4cc37f]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c5b5  0f84dbfeffff           -je 0x48c496
    if (cpu.flags.zf)
    {
        goto L_0x0048c496;
    }
    // 0048c5bb  a07ec34c00             -mov al, byte ptr [0x4cc37e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */);
    // 0048c5c0  fe057ec34c00           -inc byte ptr [0x4cc37e]
    (app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */))++;
    // 0048c5c6  803d7ec34c0014         +cmp byte ptr [0x4cc37e], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c5cd  0f8cc3feffff           -jl 0x48c496
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c496;
    }
    // 0048c5d3  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0048c5d5  880d7ec34c00           -mov byte ptr [0x4cc37e], cl
    app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */) = cpu.cl;
    // 0048c5db  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c5dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48c5f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048c5f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c5f5  e80ed7feff             -call 0x479d08
    cpu.esp -= 4;
    sub_479d08(app, cpu);
    if (cpu.terminate) return;
    // 0048c5fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c5fc  7404                   -je 0x48c602
    if (cpu.flags.zf)
    {
        goto L_0x0048c602;
    }
    // 0048c5fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c600  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c601  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c602:
    // 0048c602  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c603  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c604  e8a7c70000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048c609  a06dc34c00             -mov al, byte ptr [0x4cc36d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
    // 0048c60e  3c03                   +cmp al, 3
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
    // 0048c610  770c                   -ja 0x48c61e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c612  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0048c617  ff2485e4c54800         -jmp dword ptr [eax*4 + 0x48c5e4]
    cpu.ip = app->getMemory<x86::reg32>(4769252 + cpu.eax * 4); goto dynamic_jump;
  case 0x0048c61e:
L_0x0048c61e:
    // 0048c61e  e8a1c70000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c623  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c625  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c626  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c627  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c628  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048c629:
    // 0048c629  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048c62b:
    // 0048c62b  3a0d70c34c00           +cmp cl, byte ptr [0x4cc370]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5030768) /* 0x4cc370 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c631  750d                   -jne 0x48c640
    if (!cpu.flags.zf)
    {
        goto L_0x0048c640;
    }
    // 0048c633  a180c34c00             -mov eax, dword ptr [0x4cc380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */);
    // 0048c638  3b0584c34c00           +cmp eax, dword ptr [0x4cc384]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030788) /* 0x4cc384 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c63e  7dde                   -jge 0x48c61e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048c61e;
    }
L_0x0048c640:
    // 0048c640  3a0d7bc34c00           +cmp cl, byte ptr [0x4cc37b]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c646  7526                   -jne 0x48c66e
    if (!cpu.flags.zf)
    {
        goto L_0x0048c66e;
    }
    // 0048c648  833d88c34c00ff         +cmp dword ptr [0x4cc388], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030792) /* 0x4cc388 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c64f  74cd                   -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c651  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c656  e899f1ffff             -call 0x48b7f4
    cpu.esp -= 4;
    sub_48b7f4(app, cpu);
    if (cpu.terminate) return;
    // 0048c65b  3b0588c34c00           +cmp eax, dword ptr [0x4cc388]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030792) /* 0x4cc388 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c661  0f8c8f000000           -jl 0x48c6f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c6f6;
    }
L_0x0048c667:
    // 0048c667  c6057bc34c00ff         -mov byte ptr [0x4cc37b], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */) = 255 /*0xff*/;
L_0x0048c66e:
    // 0048c66e  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c673  e844f0ffff             -call 0x48b6bc
    cpu.esp -= 4;
    sub_48b6bc(app, cpu);
    if (cpu.terminate) return;
    // 0048c678  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c67a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c67c  0f8e91000000           -jle 0x48c713
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c713;
    }
L_0x0048c682:
    // 0048c682  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c684  e87bf9ffff             -call 0x48c004
    cpu.esp -= 4;
    sub_48c004(app, cpu);
    if (cpu.terminate) return;
    // 0048c689  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c68b  7c0f                   -jl 0x48c69c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c69c;
    }
    // 0048c68d  83f803                 +cmp eax, 3
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
    // 0048c690  0f85b8000000           -jne 0x48c74e
    if (!cpu.flags.zf)
    {
        goto L_0x0048c74e;
    }
    // 0048c696  ff0580c34c00           -inc dword ptr [0x4cc380]
    (app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */))++;
L_0x0048c69c:
    // 0048c69c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048c69e  7f8b                   -jg 0x48c62b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c62b;
    }
    // 0048c6a0  83faf6                 +cmp edx, -0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c6a3  7e86                   -jle 0x48c62b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c62b;
    }
    // 0048c6a5  803d70c34c0000         +cmp byte ptr [0x4cc370], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030768) /* 0x4cc370 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c6ac  0f846cffffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c6b2  a180c34c00             -mov eax, dword ptr [0x4cc380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */);
    // 0048c6b7  3b0584c34c00           +cmp eax, dword ptr [0x4cc384]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030788) /* 0x4cc384 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c6bd  7d27                   -jge 0x48c6e6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048c6e6;
    }
    // 0048c6bf  833d80c34c0000         +cmp dword ptr [0x4cc380], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c6c6  0f859d000000           -jne 0x48c769
    if (!cpu.flags.zf)
    {
        goto L_0x0048c769;
    }
L_0x0048c6cc:
    // 0048c6cc  833d80c34c0000         +cmp dword ptr [0x4cc380], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c6d3  0f8445ffffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c6d9  e82ef1ffff             -call 0x48b80c
    cpu.esp -= 4;
    sub_48b80c(app, cpu);
    if (cpu.terminate) return;
    // 0048c6de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c6e0  0f8438ffffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
L_0x0048c6e6:
    // 0048c6e6  e8f5020000             -call 0x48c9e0
    cpu.esp -= 4;
    sub_48c9e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c6eb  e8d4c60000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c6f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c6f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c6f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c6f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c6f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c6f6:
    // 0048c6f6  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c6fb  e864f1ffff             -call 0x48b864
    cpu.esp -= 4;
    sub_48b864(app, cpu);
    if (cpu.terminate) return;
    // 0048c700  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c702  0f855fffffff           -jne 0x48c667
    if (!cpu.flags.zf)
    {
        goto L_0x0048c667;
    }
    // 0048c708  e8b7c60000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c70d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c70f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c710  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c711  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c712  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c713:
    // 0048c713  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c716  0f8e66ffffff           -jle 0x48c682
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c682;
    }
    // 0048c71c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c71e  0f8478ffffff           -je 0x48c69c
    if (cpu.flags.zf)
    {
        goto L_0x0048c69c;
    }
    // 0048c724  833d80c34c0000         +cmp dword ptr [0x4cc380], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c72b  0f84edfeffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c731  803d70c34c0000         +cmp byte ptr [0x4cc370], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030768) /* 0x4cc370 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c738  0f84e0feffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c73e  e89d020000             -call 0x48c9e0
    cpu.esp -= 4;
    sub_48c9e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c743  e87cc60000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c748  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c74a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c74b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c74c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c74d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c74e:
    // 0048c74e  83f801                 +cmp eax, 1
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
    // 0048c751  0f8545ffffff           -jne 0x48c69c
    if (!cpu.flags.zf)
    {
        goto L_0x0048c69c;
    }
    // 0048c757  803d6dc34c0001         +cmp byte ptr [0x4cc36d], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c75e  0f85bafeffff           -jne 0x48c61e
    if (!cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c764  e933ffffff             -jmp 0x48c69c
    goto L_0x0048c69c;
L_0x0048c769:
    // 0048c769  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c76e  e8f1f0ffff             -call 0x48b864
    cpu.esp -= 4;
    sub_48b864(app, cpu);
    if (cpu.terminate) return;
    // 0048c773  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c775  0f856bffffff           -jne 0x48c6e6
    if (!cpu.flags.zf)
    {
        goto L_0x0048c6e6;
    }
    // 0048c77b  e94cffffff             -jmp 0x48c6cc
    goto L_0x0048c6cc;
  case 0x0048c780:
    // 0048c780  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048c782:
    // 0048c782  3a0d7bc34c00           +cmp cl, byte ptr [0x4cc37b]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c788  7526                   -jne 0x48c7b0
    if (!cpu.flags.zf)
    {
        goto L_0x0048c7b0;
    }
    // 0048c78a  833d88c34c00ff         +cmp dword ptr [0x4cc388], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030792) /* 0x4cc388 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c791  0f8487feffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c797  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c79c  e853f0ffff             -call 0x48b7f4
    cpu.esp -= 4;
    sub_48b7f4(app, cpu);
    if (cpu.terminate) return;
    // 0048c7a1  3b0588c34c00           +cmp eax, dword ptr [0x4cc388]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030792) /* 0x4cc388 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c7a7  7c6f                   -jl 0x48c818
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c818;
    }
L_0x0048c7a9:
    // 0048c7a9  c6057bc34c00ff         -mov byte ptr [0x4cc37b], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */) = 255 /*0xff*/;
L_0x0048c7b0:
    // 0048c7b0  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c7b5  e802efffff             -call 0x48b6bc
    cpu.esp -= 4;
    sub_48b6bc(app, cpu);
    if (cpu.terminate) return;
    // 0048c7ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c7bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c7be  7e71                   -jle 0x48c831
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c831;
    }
L_0x0048c7c0:
    // 0048c7c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c7c2  e83df8ffff             -call 0x48c004
    cpu.esp -= 4;
    sub_48c004(app, cpu);
    if (cpu.terminate) return;
    // 0048c7c7  83f801                 +cmp eax, 1
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
    // 0048c7ca  756a                   -jne 0x48c836
    if (!cpu.flags.zf)
    {
        goto L_0x0048c836;
    }
L_0x0048c7cc:
    // 0048c7cc  833ddcc34c0000         +cmp dword ptr [0x4cc3dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030876) /* 0x4cc3dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c7d3  0f8445feffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c7d9  e82af7ffff             -call 0x48bf08
    cpu.esp -= 4;
    sub_48bf08(app, cpu);
    if (cpu.terminate) return;
    // 0048c7de  3b05dcc34c00           +cmp eax, dword ptr [0x4cc3dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030876) /* 0x4cc3dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c7e4  7c63                   -jl 0x48c849
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c849;
    }
    // 0048c7e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048c7e8  891ddcc34c00           -mov dword ptr [0x4cc3dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030876) /* 0x4cc3dc */) = cpu.ebx;
    // 0048c7ee  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c7f3  e850c30000             -call 0x498b48
    cpu.esp -= 4;
    sub_498b48(app, cpu);
    if (cpu.terminate) return;
    // 0048c7f8  833d74c44c0000         +cmp dword ptr [0x4cc474], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c7ff  0f8419feffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c805  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c807  ff1574c44c00           -call dword ptr [0x4cc474]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c80d  e8b2c50000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c812  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c814  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c815  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c816  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c817  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c818:
    // 0048c818  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c81d  e842f0ffff             -call 0x48b864
    cpu.esp -= 4;
    sub_48b864(app, cpu);
    if (cpu.terminate) return;
    // 0048c822  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c824  7583                   -jne 0x48c7a9
    if (!cpu.flags.zf)
    {
        goto L_0x0048c7a9;
    }
    // 0048c826  e899c50000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c82b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c82d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c82e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c82f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c830  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c831:
    // 0048c831  83f8f6                 +cmp eax, -0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c834  7e8a                   -jle 0x48c7c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c7c0;
    }
L_0x0048c836:
    // 0048c836  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048c838  0f8f44ffffff           -jg 0x48c782
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c782;
    }
    // 0048c83e  83faf6                 +cmp edx, -0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-10 /*-0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c841  0f8e3bffffff           -jle 0x48c782
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c782;
    }
    // 0048c847  eb83                   -jmp 0x48c7cc
    goto L_0x0048c7cc;
L_0x0048c849:
    // 0048c849  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c84e  e811f0ffff             -call 0x48b864
    cpu.esp -= 4;
    sub_48b864(app, cpu);
    if (cpu.terminate) return;
    // 0048c853  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c855  7444                   -je 0x48c89b
    if (cpu.flags.zf)
    {
        goto L_0x0048c89b;
    }
    // 0048c857  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c859  a06fc34c00             -mov al, byte ptr [0x4cc36f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030767) /* 0x4cc36f */);
    // 0048c85e  e84d2fffff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 0048c863  83f801                 +cmp eax, 1
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
    // 0048c866  0f8fb2fdffff           -jg 0x48c61e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c61e;
    }
    // 0048c86c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c86e  8915dcc34c00           -mov dword ptr [0x4cc3dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5030876) /* 0x4cc3dc */) = cpu.edx;
    // 0048c874  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c876  e8cdc20000             -call 0x498b48
    cpu.esp -= 4;
    sub_498b48(app, cpu);
    if (cpu.terminate) return;
    // 0048c87b  833d74c44c0000         +cmp dword ptr [0x4cc474], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c882  0f8496fdffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c888  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c88a  ff1574c44c00           -call dword ptr [0x4cc474]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c890  e82fc50000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c895  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c897  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c898  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c899  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c89a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c89b:
    // 0048c89b  e86cefffff             -call 0x48b80c
    cpu.esp -= 4;
    sub_48b80c(app, cpu);
    if (cpu.terminate) return;
    // 0048c8a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c8a2  0f8476fdffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c8a8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048c8aa  892ddcc34c00           -mov dword ptr [0x4cc3dc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5030876) /* 0x4cc3dc */) = cpu.ebp;
    // 0048c8b0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c8b5  e88ec20000             -call 0x498b48
    cpu.esp -= 4;
    sub_498b48(app, cpu);
    if (cpu.terminate) return;
    // 0048c8ba  833d74c44c0000         +cmp dword ptr [0x4cc474], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c8c1  0f8457fdffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c8c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c8c9  ff1574c44c00           -call dword ptr [0x4cc474]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c8cf  e8f0c40000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c8d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c8d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c8d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c8d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c8d9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048c8da:
    // 0048c8da  e8d9f5ffff             -call 0x48beb8
    cpu.esp -= 4;
    sub_48beb8(app, cpu);
    if (cpu.terminate) return;
    // 0048c8df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c8e1  0f8f37fdffff           -jg 0x48c61e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c61e;
    }
    // 0048c8e7  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048c8ec  e8cf3bffff             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
    // 0048c8f1  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048c8f6  e825f2feff             -call 0x47bb20
    cpu.esp -= 4;
    sub_47bb20(app, cpu);
    if (cpu.terminate) return;
    // 0048c8fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c8fd  0f841bfdffff           -je 0x48c61e
    if (cpu.flags.zf)
    {
        goto L_0x0048c61e;
    }
    // 0048c903  a07ac34c00             -mov al, byte ptr [0x4cc37a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */);
    // 0048c908  fe0d7ac34c00           -dec byte ptr [0x4cc37a]
    (app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */))--;
    // 0048c90e  e8b9f7ffff             -call 0x48c0cc
    cpu.esp -= 4;
    sub_48c0cc(app, cpu);
    if (cpu.terminate) return;
    // 0048c913  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0048c915  e812000000             -call 0x48c92c
    cpu.esp -= 4;
    sub_48c92c(app, cpu);
    if (cpu.terminate) return;
    // 0048c91a  88156dc34c00           -mov byte ptr [0x4cc36d], dl
    app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */) = cpu.dl;
    // 0048c920  e89fc40000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c925  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c927  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c928  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c929  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c92a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_48c92c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c92c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c92d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c92e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c92f  ba78c34800             -mov edx, 0x48c378
    cpu.edx = 4768632 /*0x48c378*/;
    // 0048c934  b970bc4800             -mov ecx, 0x48bc70
    cpu.ecx = 4766832 /*0x48bc70*/;
    // 0048c939  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048c93b  891570c44c00           -mov dword ptr [0x4cc470], edx
    app->getMemory<x86::reg32>(x86::reg32(5031024) /* 0x4cc470 */) = cpu.edx;
    // 0048c941  890dcccd4c00           -mov dword ptr [0x4ccdcc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033420) /* 0x4ccdcc */) = cpu.ecx;
    // 0048c947  891d80c34c00           -mov dword ptr [0x4cc380], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */) = cpu.ebx;
    // 0048c94d  891d04c34c00           -mov dword ptr [0x4cc304], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030660) /* 0x4cc304 */) = cpu.ebx;
    // 0048c953  891d08c34c00           -mov dword ptr [0x4cc308], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */) = cpu.ebx;
    // 0048c959  891d0cc34c00           -mov dword ptr [0x4cc30c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030668) /* 0x4cc30c */) = cpu.ebx;
    // 0048c95f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c961  891df0c24c00           -mov dword ptr [0x4cc2f0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */) = cpu.ebx;
    // 0048c967  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c969  891df4c24c00           -mov dword ptr [0x4cc2f4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */) = cpu.ebx;
    // 0048c96f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048c974  890d00c34c00           -mov dword ptr [0x4cc300], ecx
    app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */) = cpu.ecx;
    // 0048c97a  30fc                   -xor ah, bh
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0048c97c  88256dc34c00           -mov byte ptr [0x4cc36d], ah
    app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */) = cpu.ah;
    // 0048c982  30da                   -xor dl, bl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0048c984  88157ec34c00           -mov byte ptr [0x4cc37e], dl
    app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */) = cpu.dl;
    // 0048c98a  30fe                   -xor dh, bh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0048c98c  88357fc34c00           -mov byte ptr [0x4cc37f], dh
    app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */) = cpu.dh;
    // 0048c992  0fbe057fc34c00         -movsx eax, byte ptr [0x4cc37f]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */)));
    // 0048c999  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048c99b  890c858cc34c00         -mov dword ptr [eax*4 + 0x4cc38c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.eax * 4) = cpu.ecx;
    // 0048c9a2  c6056ec34c0001         -mov byte ptr [0x4cc36e], 1
    app->getMemory<x86::reg8>(x86::reg32(5030766) /* 0x4cc36e */) = 1 /*0x1*/;
    // 0048c9a9  30ef                   -xor bh, ch
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0048c9ab  883d7dc34c00           -mov byte ptr [0x4cc37d], bh
    app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */) = cpu.bh;
    // 0048c9b1  803d78c34c0000         +cmp byte ptr [0x4cc378], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030776) /* 0x4cc378 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c9b8  7406                   -je 0x48c9c0
    if (cpu.flags.zf)
    {
        goto L_0x0048c9c0;
    }
    // 0048c9ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c9bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c9c0:
    // 0048c9c0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048c9c5  b8f4c54800             -mov eax, 0x48c5f4
    cpu.eax = 4769268 /*0x48c5f4*/;
    // 0048c9ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c9cc  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 0048c9ce  e88dd1feff             -call 0x479b60
    cpu.esp -= 4;
    sub_479b60(app, cpu);
    if (cpu.terminate) return;
    // 0048c9d3  882d78c34c00           -mov byte ptr [0x4cc378], ch
    app->getMemory<x86::reg8>(x86::reg32(5030776) /* 0x4cc378 */) = cpu.ch;
    // 0048c9d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c9db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48c9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c9e0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048c9e3  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048c9e8  e833f1feff             -call 0x47bb20
    cpu.esp -= 4;
    sub_47bb20(app, cpu);
    if (cpu.terminate) return;
    // 0048c9ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c9ef  7509                   -jne 0x48c9fa
    if (!cpu.flags.zf)
    {
        goto L_0x0048c9fa;
    }
    // 0048c9f1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048c9f6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048c9f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c9fa:
    // 0048c9fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c9fb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048c9ff  e85ce4feff             -call 0x47ae60
    cpu.esp -= 4;
    sub_47ae60(app, cpu);
    if (cpu.terminate) return;
    // 0048ca04  a072c34c00             -mov al, byte ptr [0x4cc372]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030770) /* 0x4cc372 */);
    // 0048ca09  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0048ca0d  a073c34c00             -mov al, byte ptr [0x4cc373]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030771) /* 0x4cc373 */);
    // 0048ca12  8844240b               -mov byte ptr [esp + 0xb], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) = cpu.al;
    // 0048ca16  a074c34c00             -mov al, byte ptr [0x4cc374]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030772) /* 0x4cc374 */);
    // 0048ca1b  8844240d               -mov byte ptr [esp + 0xd], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0048ca1f  a075c34c00             -mov al, byte ptr [0x4cc375]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030773) /* 0x4cc375 */);
    // 0048ca24  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ca28  8844240e               -mov byte ptr [esp + 0xe], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */) = cpu.al;
    // 0048ca2c  b810c34c00             -mov eax, 0x4cc310
    cpu.eax = 5030672 /*0x4cc310*/;
    // 0048ca31  e81ac00000             -call 0x498a50
    cpu.esp -= 4;
    sub_498a50(app, cpu);
    if (cpu.terminate) return;
    // 0048ca36  a300c34c00             -mov dword ptr [0x4cc300], eax
    app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */) = cpu.eax;
    // 0048ca3b  833d00c34c0000         +cmp dword ptr [0x4cc300], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ca42  7c5b                   -jl 0x48ca9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ca9f;
    }
    // 0048ca44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ca45  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048ca4a  e86dc70000             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0048ca4f  a271c34c00             -mov byte ptr [0x4cc371], al
    app->getMemory<x86::reg8>(x86::reg32(5030769) /* 0x4cc371 */) = cpu.al;
    // 0048ca54  0fbe1571c34c00         -movsx edx, byte ptr [0x4cc371]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030769) /* 0x4cc371 */)));
    // 0048ca5b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048ca62  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ca64  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048ca67  8a80dba75200           -mov al, byte ptr [eax + 0x52a7db]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416923) /* 0x52a7db */);
    // 0048ca6d  a26fc34c00             -mov byte ptr [0x4cc36f], al
    app->getMemory<x86::reg8>(x86::reg32(5030767) /* 0x4cc36f */) = cpu.al;
    // 0048ca72  c6056dc34c0002         -mov byte ptr [0x4cc36d], 2
    app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */) = 2 /*0x2*/;
    // 0048ca79  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0048ca7b  88156cc34c00           -mov byte ptr [0x4cc36c], dl
    app->getMemory<x86::reg8>(x86::reg32(5030764) /* 0x4cc36c */) = cpu.dl;
    // 0048ca81  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ca83  66891d76c34c00         -mov word ptr [0x4cc376], bx
    app->getMemory<x86::reg16>(x86::reg32(5030774) /* 0x4cc376 */) = cpu.bx;
    // 0048ca8a  b88cbf4800             -mov eax, 0x48bf8c
    cpu.eax = 4767628 /*0x48bf8c*/;
    // 0048ca8f  e81cc00000             -call 0x498ab0
    cpu.esp -= 4;
    sub_498ab0(app, cpu);
    if (cpu.terminate) return;
    // 0048ca94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ca95  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048ca9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ca9b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048ca9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ca9f:
    // 0048ca9f  66a176c34c00           -mov ax, word ptr [0x4cc376]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5030774) /* 0x4cc376 */);
    // 0048caa5  66ff0576c34c00         -inc word ptr [0x4cc376]
    (app->getMemory<x86::reg16>(x86::reg32(5030774) /* 0x4cc376 */))++;
    // 0048caac  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048cab1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cab2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048cab5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48cac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cac0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cac1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cac2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cac3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0048cac6  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048caca  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048cacd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048cad1  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0048cad5  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048cad9  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048cadd  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cae1  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cae5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048cae7  bdd0070000             -mov ebp, 0x7d0
    cpu.ebp = 2000 /*0x7d0*/;
    // 0048caec  e8ff390100             -call 0x4a04f0
    cpu.esp -= 4;
    sub_4a04f0(app, cpu);
    if (cpu.terminate) return;
    // 0048caf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048caf3  0f8494000000           -je 0x48cb8d
    if (cpu.flags.zf)
    {
        goto L_0x0048cb8d;
    }
    // 0048caf9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cafd  2b1424                 -sub edx, dword ptr [esp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0048cb00  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cb02  0f8c8e000000           -jl 0x48cb96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cb96;
    }
    // 0048cb08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0048cb0a:
    // 0048cb0a  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cb0e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048cb10  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048cb14  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048cb16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cb18  0f8c81000000           -jl 0x48cb9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cb9f;
    }
    // 0048cb1e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048cb20:
    // 0048cb20  39cb                   +cmp ebx, ecx
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
    // 0048cb22  0f8e9c010000           -jle 0x48ccc4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ccc4;
    }
    // 0048cb28  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cb2a  0f8c78000000           -jl 0x48cba8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cba8;
    }
L_0x0048cb30:
    // 0048cb30  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cb34  2b0424                 -sub eax, dword ptr [esp]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0048cb37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cb39  0f8c8c000000           -jl 0x48cbcb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cbcb;
    }
L_0x0048cb3f:
    // 0048cb3f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048cb43  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048cb47  2b4c2404               -sub ecx, dword ptr [esp + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0048cb4b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cb4d  0f8c7f000000           -jl 0x48cbd2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cbd2;
    }
    // 0048cb53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048cb55:
    // 0048cb55  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048cb59  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cb5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048cb5f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048cb62  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cb64  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048cb66  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cb68  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cb6a  7c6f                   -jl 0x48cbdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cbdb;
    }
    // 0048cb6c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048cb71:
    // 0048cb71  8a1dd8a64c00           -mov bl, byte ptr [0x4ca6d8]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0048cb77  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048cb7b  80fb08                 +cmp bl, 8
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cb7e  0f85a3000000           -jne 0x48cc27
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc27;
    }
L_0x0048cb84:
    // 0048cb84  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cb87  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cb8b  7e55                   -jle 0x48cbe2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048cbe2;
    }
L_0x0048cb8d:
    // 0048cb8d  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0048cb90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb93  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048cb96:
    // 0048cb96  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048cb98  f7d8                   +neg eax
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
    // 0048cb9a  e96bffffff             -jmp 0x48cb0a
    goto L_0x0048cb0a;
L_0x0048cb9f:
    // 0048cb9f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048cba1  f7d9                   +neg ecx
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
    // 0048cba3  e978ffffff             -jmp 0x48cb20
    goto L_0x0048cb20;
L_0x0048cba8:
    // 0048cba8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cbac  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cbaf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048cbb2  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048cbb6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048cbba  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cbbe  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048cbc2  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048cbc6  e965ffffff             -jmp 0x48cb30
    goto L_0x0048cb30;
L_0x0048cbcb:
    // 0048cbcb  f7d8                   +neg eax
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
    // 0048cbcd  e96dffffff             -jmp 0x48cb3f
    goto L_0x0048cb3f;
L_0x0048cbd2:
    // 0048cbd2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048cbd4  f7d8                   +neg eax
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
    // 0048cbd6  e97affffff             -jmp 0x48cb55
    goto L_0x0048cb55;
L_0x0048cbdb:
    // 0048cbdb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048cbe0  eb8f                   -jmp 0x48cb71
    goto L_0x0048cb71;
L_0x0048cbe2:
    // 0048cbe2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cbe6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048cbe8  8b0de8a64c00           -mov ecx, dword ptr [0x4ca6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048cbee  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 0048cbf1  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048cbf7  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0048cbf9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cbfc  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048cc00  40                     -inc eax
    (cpu.eax)++;
    // 0048cc01  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cc03  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048cc06  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048cc08  0f8d76ffffff           -jge 0x48cb84
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048cb84;
    }
    // 0048cc0e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048cc12  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cc16  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cc1a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048cc1c  01ce                   +add esi, ecx
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
    // 0048cc1e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048cc22  e95dffffff             -jmp 0x48cb84
    goto L_0x0048cb84;
L_0x0048cc27:
    // 0048cc27  80fb0f                 +cmp bl, 0xf
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cc2a  754d                   -jne 0x48cc79
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc79;
    }
L_0x0048cc2c:
    // 0048cc2c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cc2f  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cc33  0f8f54ffffff           -jg 0x48cb8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048cb8d;
    }
    // 0048cc39  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cc3d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048cc3f  8b0de8a64c00           -mov ecx, dword ptr [0x4ca6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048cc45  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0048cc48  0315dca64c00           -add edx, dword ptr [0x4ca6dc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048cc4e  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 0048cc52  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cc55  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048cc59  40                     -inc eax
    (cpu.eax)++;
    // 0048cc5a  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cc5c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048cc5f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048cc61  7dc9                   -jge 0x48cc2c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048cc2c;
    }
    // 0048cc63  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048cc67  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cc6b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cc6f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048cc71  01ce                   +add esi, ecx
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
    // 0048cc73  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048cc77  ebb3                   -jmp 0x48cc2c
    goto L_0x0048cc2c;
L_0x0048cc79:
    // 0048cc79  80fb10                 +cmp bl, 0x10
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cc7c  74ae                   -je 0x48cc2c
    if (cpu.flags.zf)
    {
        goto L_0x0048cc2c;
    }
L_0x0048cc7e:
    // 0048cc7e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cc81  3b442408               +cmp eax, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cc85  0f8f02ffffff           -jg 0x48cb8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048cb8d;
    }
    // 0048cc8b  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048cc8c  0f84fbfeffff           -je 0x48cb8d
    if (cpu.flags.zf)
    {
        goto L_0x0048cb8d;
    }
    // 0048cc92  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cc96  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048cc98  e8333a0100             -call 0x4a06d0
    cpu.esp -= 4;
    sub_4a06d0(app, cpu);
    if (cpu.terminate) return;
    // 0048cc9d  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cca0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048cca4  43                     -inc ebx
    (cpu.ebx)++;
    // 0048cca5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048cca7  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048ccaa  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048ccac  7dd0                   -jge 0x48cc7e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048cc7e;
    }
    // 0048ccae  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048ccb2  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ccb6  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048ccba  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ccbc  01d6                   +add esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ccbe  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048ccc2  ebba                   -jmp 0x48cc7e
    goto L_0x0048cc7e;
L_0x0048ccc4:
    // 0048ccc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ccc6  0f8ca1000000           -jl 0x48cd6d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cd6d;
    }
L_0x0048cccc:
    // 0048cccc  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ccd0  2b0c24                 -sub ecx, dword ptr [esp]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0048ccd3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ccd5  0f8cb5000000           -jl 0x48cd90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cd90;
    }
    // 0048ccdb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048ccdd:
    // 0048ccdd  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048cce1  2b542404               -sub edx, dword ptr [esp + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0048cce5  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048cce9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cceb  0f8ca8000000           -jl 0x48cd99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cd99;
    }
L_0x0048ccf1:
    // 0048ccf1  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0048ccf5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ccf7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ccfa  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ccfc  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048ccfe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cd00  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cd02  0f8c98000000           -jl 0x48cda0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cda0;
    }
    // 0048cd08  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048cd0d:
    // 0048cd0d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048cd11  8a25d8a64c00           -mov ah, byte ptr [0x4ca6d8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0048cd17  80fc08                 +cmp ah, 8
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cd1a  0f858a000000           -jne 0x48cdaa
    if (!cpu.flags.zf)
    {
        goto L_0x0048cdaa;
    }
L_0x0048cd20:
    // 0048cd20  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cd24  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cd28  0f8f5ffeffff           -jg 0x48cb8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048cb8d;
    }
    // 0048cd2e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048cd30  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048cd32  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cd35  8b0de8a64c00           -mov ecx, dword ptr [0x4ca6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048cd3b  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 0048cd3e  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048cd44  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0048cd46  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cd4a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048cd4e  40                     -inc eax
    (cpu.eax)++;
    // 0048cd4f  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cd51  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048cd55  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048cd57  7dc7                   -jge 0x48cd20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048cd20;
    }
    // 0048cd59  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048cd5d  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cd60  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048cd64  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048cd66  01ce                   +add esi, ecx
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
    // 0048cd68  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048cd6b  ebb3                   -jmp 0x48cd20
    goto L_0x0048cd20;
L_0x0048cd6d:
    // 0048cd6d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048cd71  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cd75  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048cd79  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048cd7d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cd81  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cd84  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048cd87  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048cd8b  e93cffffff             -jmp 0x48cccc
    goto L_0x0048cccc;
L_0x0048cd90:
    // 0048cd90  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048cd92  f7d8                   +neg eax
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
    // 0048cd94  e944ffffff             -jmp 0x48ccdd
    goto L_0x0048ccdd;
L_0x0048cd99:
    // 0048cd99  f7da                   +neg edx
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
    // 0048cd9b  e951ffffff             -jmp 0x48ccf1
    goto L_0x0048ccf1;
L_0x0048cda0:
    // 0048cda0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048cda5  e963ffffff             -jmp 0x48cd0d
    goto L_0x0048cd0d;
L_0x0048cdaa:
    // 0048cdaa  80fc0f                 +cmp ah, 0xf
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cdad  754f                   -jne 0x48cdfe
    if (!cpu.flags.zf)
    {
        goto L_0x0048cdfe;
    }
L_0x0048cdaf:
    // 0048cdaf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cdb3  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cdb7  0f8fd0fdffff           -jg 0x48cb8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048cb8d;
    }
    // 0048cdbd  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048cdbf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048cdc1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cdc4  8b0de8a64c00           -mov ecx, dword ptr [0x4ca6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048cdca  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 0048cdcd  0315dca64c00           -add edx, dword ptr [0x4ca6dc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048cdd3  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 0048cdd7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cddb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048cddf  40                     -inc eax
    (cpu.eax)++;
    // 0048cde0  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cde2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048cde6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048cde8  7dc5                   -jge 0x48cdaf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048cdaf;
    }
    // 0048cdea  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048cdee  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cdf1  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048cdf5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048cdf7  01ce                   +add esi, ecx
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
    // 0048cdf9  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048cdfc  ebb1                   -jmp 0x48cdaf
    goto L_0x0048cdaf;
L_0x0048cdfe:
    // 0048cdfe  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048ce01  74ac                   -je 0x48cdaf
    if (cpu.flags.zf)
    {
        goto L_0x0048cdaf;
    }
L_0x0048ce03:
    // 0048ce03  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ce07  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ce0b  0f8f7cfdffff           -jg 0x48cb8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048cb8d;
    }
    // 0048ce11  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048ce12  0f8475fdffff           -je 0x48cb8d
    if (cpu.flags.zf)
    {
        goto L_0x0048cb8d;
    }
    // 0048ce18  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048ce1a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ce1c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ce1f  e8ac380100             -call 0x4a06d0
    cpu.esp -= 4;
    sub_4a06d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ce24  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ce28  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048ce2c  43                     -inc ebx
    (cpu.ebx)++;
    // 0048ce2d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ce2f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048ce33  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048ce35  7dcc                   -jge 0x48ce03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ce03;
    }
    // 0048ce37  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048ce3b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ce3e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048ce42  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ce44  01d6                   +add esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ce46  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048ce49  ebb8                   -jmp 0x48ce03
    goto L_0x0048ce03;
}

/* align: skip  */
void Application::sub_48ce4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce4b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ce4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce4d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048ce50  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ce52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ce54  7514                   -jne 0x48ce6a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce6a;
    }
    // 0048ce56  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce5c  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ce5f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048ce61  7507                   -jne 0x48ce6a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce6a;
    }
L_0x0048ce63:
    // 0048ce63  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048ce65  e97f000000             -jmp 0x48cee9
    goto L_0x0048cee9;
L_0x0048ce6a:
    // 0048ce6a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048ce6c  e816390100             -call 0x4a0787
    cpu.esp -= 4;
    sub_4a0787(app, cpu);
    if (cpu.terminate) return;
    // 0048ce71  eb1f                   -jmp 0x48ce92
    goto L_0x0048ce92;
L_0x0048ce73:
    // 0048ce73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ce75  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0048ce78  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ce7a  8a0c04                 -mov cl, byte ptr [esp + eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 0048ce7d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ce7f  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0048ce82  8a808c1d4c00           -mov al, byte ptr [eax + 0x4c1d8c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4988300) /* 0x4c1d8c */);
    // 0048ce88  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048ce8d  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 0048ce8f  7409                   -je 0x48ce9a
    if (cpu.flags.zf)
    {
        goto L_0x0048ce9a;
    }
    // 0048ce91  43                     -inc ebx
    (cpu.ebx)++;
L_0x0048ce92:
    // 0048ce92  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ce94  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0048ce96  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ce98  75d9                   -jne 0x48ce73
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce73;
    }
L_0x0048ce9a:
    // 0048ce9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ce9c  74c5                   -je 0x48ce63
    if (cpu.flags.zf)
    {
        goto L_0x0048ce63;
    }
    // 0048ce9e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048cea0  eb30                   -jmp 0x48ced2
    goto L_0x0048ced2;
L_0x0048cea2:
    // 0048cea2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048cea4  c1e903                 -shr ecx, 3
    cpu.ecx >>= 3 /*0x3*/ % 32;
    // 0048cea7  8a0c0c                 -mov cl, byte ptr [esp + ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1);
    // 0048ceaa  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0048cead  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048ceb3  8a808c1d4c00           -mov al, byte ptr [eax + 0x4c1d8c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4988300) /* 0x4c1d8c */);
    // 0048ceb9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048cebe  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 0048cec0  740f                   -je 0x48ced1
    if (cpu.flags.zf)
    {
        goto L_0x0048ced1;
    }
    // 0048cec2  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0048cec5  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048cec6  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cecc  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048cecf  eb16                   -jmp 0x48cee7
    goto L_0x0048cee7;
L_0x0048ced1:
    // 0048ced1  42                     -inc edx
    (cpu.edx)++;
L_0x0048ced2:
    // 0048ced2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ced4  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0048ced6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ced8  75c8                   -jne 0x48cea2
    if (!cpu.flags.zf)
    {
        goto L_0x0048cea2;
    }
    // 0048ceda  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cee0  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0048cee7:
    // 0048cee7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0048cee9:
    // 0048cee9  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048ceec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ceed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ceee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ceef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ceef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cef0  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048cef2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cef3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cef4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cef5  83ec08                 +sub esp, 8
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
    // 0048cef8  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0048cefb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cefc  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048ceff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cf00  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048cf03  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cf04  e8bd380100             -call 0x4a07c6
    cpu.esp -= 4;
    sub_4a07c6(app, cpu);
    if (cpu.terminate) return;
    // 0048cf09  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0048cf0b  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0048cf0d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048cf0f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0048cf10  760c                   -jbe 0x48cf1e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048cf1e;
    }
    // 0048cf12  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0048cf15  dc05b00b4c00           -fadd qword ptr [0x4c0bb0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4983728) /* 0x4c0bb0 */));
    // 0048cf1b  dd5dec                 -fstp qword ptr [ebp - 0x14]
    app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0048cf1e:
    // 0048cf1e  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0048cf21  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0048cf24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf26  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf28  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_48cf2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cf2b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cf2c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048cf2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cf2f  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 0048cf32  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048cf35  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0048cf37  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048cf3a  e8b0ffffff             -call 0x48ceef
    cpu.esp -= 4;
    sub_48ceef(app, cpu);
    if (cpu.terminate) return;
    // 0048cf3f  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0048cf41  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf43  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48cf50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cf50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cf51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cf52  e8c5affeff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0048cf57  8b15ccca4c00           -mov edx, dword ptr [0x4ccacc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032652) /* 0x4ccacc */);
    // 0048cf5d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cf5f  7548                   -jne 0x48cfa9
    if (!cpu.flags.zf)
    {
        goto L_0x0048cfa9;
    }
    // 0048cf61  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cf62  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0048cf67  e85c3cffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048cf6c  a1b4d75100             -mov eax, dword ptr [0x51d7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363636) /* 0x51d7b4 */);
    // 0048cf71  e82abeffff             -call 0x488da0
    cpu.esp -= 4;
    sub_488da0(app, cpu);
    if (cpu.terminate) return;
    // 0048cf76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cf78  7521                   -jne 0x48cf9b
    if (!cpu.flags.zf)
    {
        goto L_0x0048cf9b;
    }
    // 0048cf7a  833dc0d7510000         +cmp dword ptr [0x51d7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5363648) /* 0x51d7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cf81  7418                   -je 0x48cf9b
    if (cpu.flags.zf)
    {
        goto L_0x0048cf9b;
    }
    // 0048cf83  803dd3d7510001         +cmp byte ptr [0x51d7d3], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363667) /* 0x51d7d3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cf8a  7626                   -jbe 0x48cfb2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048cfb2;
    }
    // 0048cf8c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048cf91  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 0048cf96  e8fdb6ffff             -call 0x488698
    cpu.esp -= 4;
    sub_488698(app, cpu);
    if (cpu.terminate) return;
L_0x0048cf9b:
    // 0048cf9b  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0048cfa0  e83b3cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048cfa5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfa6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfa7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfa8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cfa9:
    // 0048cfa9  ff15ccca4c00           -call dword ptr [0x4ccacc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032652) /* 0x4ccacc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cfaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfb0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cfb2:
    // 0048cfb2  8b1db8d75100           -mov ebx, dword ptr [0x51d7b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5363640) /* 0x51d7b8 */);
    // 0048cfb8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048cfba  7533                   -jne 0x48cfef
    if (!cpu.flags.zf)
    {
        goto L_0x0048cfef;
    }
    // 0048cfbc  a1bcd75100             -mov eax, dword ptr [0x51d7bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363644) /* 0x51d7bc */);
    // 0048cfc1  e842b0feff             -call 0x478008
    cpu.esp -= 4;
    sub_478008(app, cpu);
    if (cpu.terminate) return;
    // 0048cfc6  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
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
    // 0048cfcd  7459                   -je 0x48d028
    if (cpu.flags.zf)
    {
        goto L_0x0048d028;
    }
    // 0048cfcf  a1c0d75100             -mov eax, dword ptr [0x51d7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363648) /* 0x51d7c0 */);
    // 0048cfd4  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048cfd7  e834380100             -call 0x4a0810
    cpu.esp -= 4;
    sub_4a0810(app, cpu);
    if (cpu.terminate) return;
    // 0048cfdc  e83baffeff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0048cfe1  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0048cfe6  e8f53bffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048cfeb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cfee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cfef:
    // 0048cfef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cff1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cff2  8b3d88d35100           -mov edi, dword ptr [0x51d388]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5362568) /* 0x51d388 */);
    // 0048cff8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cff9  8b2d84d35100           -mov ebp, dword ptr [0x51d384]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5362564) /* 0x51d384 */);
    // 0048cfff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d000  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d002  a1b4d75100             -mov eax, dword ptr [0x51d7b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363636) /* 0x51d7b4 */);
    // 0048d007  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d008  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048d00a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048d00c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d00d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d00f  31fa                   -xor edx, edi
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048d011  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d013  e810c0ffff             -call 0x489028
    cpu.esp -= 4;
    sub_489028(app, cpu);
    if (cpu.terminate) return;
    // 0048d018  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d019  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d01a  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0048d01f  e8bc3bffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048d024  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d025  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d026  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d027  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d028:
    // 0048d028  a1c0d75100             -mov eax, dword ptr [0x51d7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363648) /* 0x51d7c0 */);
    // 0048d02d  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048d030  e86b800000             -call 0x4950a0
    cpu.esp -= 4;
    sub_4950a0(app, cpu);
    if (cpu.terminate) return;
    // 0048d035  e8e2aefeff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0048d03a  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0048d03f  e89c3bffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048d044  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d045  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d046  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d047  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d048(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d048  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d049  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d04a  891d78c44c00           -mov dword ptr [0x4cc478], ebx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ebx;
    // 0048d050  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d052  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d053  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0048d054:
    // 0048d054  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048d056  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d058  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0048d05a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d05c  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0048d05f  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0048d064  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0048d067  8b2c9d40825200         -mov ebp, dword ptr [ebx*4 + 0x528240]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407296) /* 0x528240 */ + cpu.ebx * 4);
    // 0048d06e  8b3cbd407e5200         -mov edi, dword ptr [edi*4 + 0x527e40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5406272) /* 0x527e40 */ + cpu.edi * 4);
    // 0048d075  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d078  8b048540805200         -mov eax, dword ptr [eax*4 + 0x528040]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5406784) /* 0x528040 */ + cpu.eax * 4);
    // 0048d07f  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d081  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d083  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d085  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d087  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d089  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0048d08c  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0048d092  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 0048d095  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d09b  8b048578795200         -mov eax, dword ptr [eax*4 + 0x527978]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405048) /* 0x527978 */ + cpu.eax * 4);
    // 0048d0a2  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0048d0a5  8b0c8d60755200         -mov ecx, dword ptr [ecx*4 + 0x527560]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5404000) /* 0x527560 */ + cpu.ecx * 4);
    // 0048d0ac  8b3cbdd86f5200         -mov edi, dword ptr [edi*4 + 0x526fd8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5402584) /* 0x526fd8 */ + cpu.edi * 4);
    // 0048d0b3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d0b5  8b1c9d407e5200         -mov ebx, dword ptr [ebx*4 + 0x527e40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5406272) /* 0x527e40 */ + cpu.ebx * 4);
    // 0048d0bc  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d0be  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d0c0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d0c2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d0c4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048d0c6  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0048d0cc  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0048d0cf  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d0d5  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 0048d0d8  8b0d78c44c00           -mov ecx, dword ptr [0x4cc478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */);
    // 0048d0de  8b048578795200         -mov eax, dword ptr [eax*4 + 0x527978]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405048) /* 0x527978 */ + cpu.eax * 4);
    // 0048d0e5  8b3cbdd86f5200         -mov edi, dword ptr [edi*4 + 0x526fd8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5402584) /* 0x526fd8 */ + cpu.edi * 4);
    // 0048d0ec  8b1c9d60755200         -mov ebx, dword ptr [ebx*4 + 0x527560]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5404000) /* 0x527560 */ + cpu.ebx * 4);
    // 0048d0f3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d0f5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d0f7  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048d0fd  250000ffff             -and eax, 0xffff0000
    cpu.eax &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0048d102  09e8                   +or eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048d104  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048d105  890d78c44c00           -mov dword ptr [0x4cc478], ecx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ecx;
    // 0048d10b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048d10d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048d110  0f853effffff           -jne 0x48d054
    if (!cpu.flags.zf)
    {
        goto L_0x0048d054;
    }
    // 0048d116  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d117  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d118  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d119  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d11a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d11b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d11b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d11c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d11d  891d78c44c00           -mov dword ptr [0x4cc478], ebx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ebx;
    // 0048d123  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d125  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d126  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0048d127:
    // 0048d127  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048d129  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d12b  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0048d12d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d12f  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0048d132  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0048d137  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0048d13a  8b2c9d40825200         -mov ebp, dword ptr [ebx*4 + 0x528240]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407296) /* 0x528240 */ + cpu.ebx * 4);
    // 0048d141  8b3cbd407e5200         -mov edi, dword ptr [edi*4 + 0x527e40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5406272) /* 0x527e40 */ + cpu.edi * 4);
    // 0048d148  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d14b  8b048540805200         -mov eax, dword ptr [eax*4 + 0x528040]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5406784) /* 0x528040 */ + cpu.eax * 4);
    // 0048d152  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d154  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d156  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d158  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d15a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d15c  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0048d15f  81e100f80f00           -and ecx, 0xff800
    cpu.ecx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0048d165  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 0048d168  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d16e  8b048578795200         -mov eax, dword ptr [eax*4 + 0x527978]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405048) /* 0x527978 */ + cpu.eax * 4);
    // 0048d175  8a5efe                 -mov bl, byte ptr [esi - 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0048d178  8b0c8d60755200         -mov ecx, dword ptr [ecx*4 + 0x527560]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5404000) /* 0x527560 */ + cpu.ecx * 4);
    // 0048d17f  8b3cbdd86f5200         -mov edi, dword ptr [edi*4 + 0x526fd8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5402584) /* 0x526fd8 */ + cpu.edi * 4);
    // 0048d186  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d188  8b1c9d407e5200         -mov ebx, dword ptr [ebx*4 + 0x527e40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5406272) /* 0x527e40 */ + cpu.ebx * 4);
    // 0048d18f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d191  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d193  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048d195  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d197  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048d199  81e300f80f00           -and ebx, 0xff800
    cpu.ebx &= x86::reg32(x86::sreg32(1046528 /*0xff800*/));
    // 0048d19f  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 0048d1a2  81e7ff010000           -and edi, 0x1ff
    cpu.edi &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d1a8  c1eb0b                 -shr ebx, 0xb
    cpu.ebx >>= 11 /*0xb*/ % 32;
    // 0048d1ab  8b0d78c44c00           -mov ecx, dword ptr [0x4cc478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */);
    // 0048d1b1  8b048578795200         -mov eax, dword ptr [eax*4 + 0x527978]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405048) /* 0x527978 */ + cpu.eax * 4);
    // 0048d1b8  8b3cbdd86f5200         -mov edi, dword ptr [edi*4 + 0x526fd8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5402584) /* 0x526fd8 */ + cpu.edi * 4);
    // 0048d1bf  8b1c9d60755200         -mov ebx, dword ptr [ebx*4 + 0x527560]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5404000) /* 0x527560 */ + cpu.ebx * 4);
    // 0048d1c6  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d1c8  01d8                   +add eax, ebx
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
    // 0048d1ca  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048d1cb  890d78c44c00           -mov dword ptr [0x4cc478], ecx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ecx;
    // 0048d1d1  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048d1d4  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048d1d7  0f854affffff           -jne 0x48d127
    if (!cpu.flags.zf)
    {
        goto L_0x0048d127;
    }
    // 0048d1dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d1e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d1e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d1e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d1e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d1e6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048d1e8  890d78c44c00           -mov dword ptr [0x4cc478], ecx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ecx;
    // 0048d1ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0048d1ef:
    // 0048d1ef  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048d1f1  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0048d1f3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d1f5  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d1f8  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 0048d1fa  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d1fd  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 0048d202  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d204  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d206  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d208  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0048d20b  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0048d20d  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0048d210  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048d216  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0048d219  8b149540825200         -mov edx, dword ptr [edx*4 + 0x528240]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407296) /* 0x528240 */ + cpu.edx * 4);
    // 0048d220  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048d226  8b0c8d40805200         -mov ecx, dword ptr [ecx*4 + 0x528040]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5406784) /* 0x528040 */ + cpu.ecx * 4);
    // 0048d22d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d22f  8b0485407e5200         -mov eax, dword ptr [eax*4 + 0x527e40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5406272) /* 0x527e40 */ + cpu.eax * 4);
    // 0048d236  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d238  8b2cad407e5200         -mov ebp, dword ptr [ebp*4 + 0x527e40]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5406272) /* 0x527e40 */ + cpu.ebp * 4);
    // 0048d23f  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d241  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d243  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 0048d246  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d248  c1e90b                 -shr ecx, 0xb
    cpu.ecx >>= 11 /*0xb*/ % 32;
    // 0048d24b  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d250  8b149578795200         -mov edx, dword ptr [edx*4 + 0x527978]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405048) /* 0x527978 */ + cpu.edx * 4);
    // 0048d257  81e1ff010000           -and ecx, 0x1ff
    cpu.ecx &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d25d  8b0485d86f5200         -mov eax, dword ptr [eax*4 + 0x526fd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5402584) /* 0x526fd8 */ + cpu.eax * 4);
    // 0048d264  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d267  8b0c8d60755200         -mov ecx, dword ptr [ecx*4 + 0x527560]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5404000) /* 0x527560 */ + cpu.ecx * 4);
    // 0048d26e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d270  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d272  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048d274  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 0048d277  8943f8                 -mov dword ptr [ebx - 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0048d27a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d27c  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d282  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0048d285  8b149578795200         -mov edx, dword ptr [edx*4 + 0x527978]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405048) /* 0x527978 */ + cpu.edx * 4);
    // 0048d28c  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d291  8b2cadd86f5200         -mov ebp, dword ptr [ebp*4 + 0x526fd8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5402584) /* 0x526fd8 */ + cpu.ebp * 4);
    // 0048d298  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d29a  8b0d78c44c00           -mov ecx, dword ptr [0x4cc478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */);
    // 0048d2a0  8b048560755200         -mov eax, dword ptr [eax*4 + 0x527560]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5404000) /* 0x527560 */ + cpu.eax * 4);
    // 0048d2a7  01d0                   +add eax, edx
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
    // 0048d2a9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048d2aa  890d78c44c00           -mov dword ptr [0x4cc478], ecx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ecx;
    // 0048d2b0  90                     -nop 
    ;
    // 0048d2b1  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048d2b4  0f8535ffffff           -jne 0x48d1ef
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1ef;
    }
    // 0048d2ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d2be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d2be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d2bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d2c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d2c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0048d2c2:
    // 0048d2c2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d2c4  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048d2c7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048d2c9  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0048d2cb  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048d2ce  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 0048d2d4  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0048d2d7  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 0048d2dd  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0048d2e3  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d2e5  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d2e7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d2ea  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048d2ec  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d2ef  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0048d2f1  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 0048d2f7  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0048d2f9  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 0048d2ff  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0048d302  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d304  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0048d30a  897afc                 -mov dword ptr [edx - 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0048d30d  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048d30f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048d310  8972f8                 -mov dword ptr [edx - 8], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0048d313  75ad                   -jne 0x48d2c2
    if (!cpu.flags.zf)
    {
        goto L_0x0048d2c2;
    }
    // 0048d315  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d316  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d317  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d318  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d31a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d31a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d31b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d31c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d31d  890d78c44c00           -mov dword ptr [0x4cc478], ecx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ecx;
    // 0048d323  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d325  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d327  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048d329  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d32c  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0048d32e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d331  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 0048d337  893d7cc44c00           -mov dword ptr [0x4cc47c], edi
    app->getMemory<x86::reg32>(x86::reg32(5031036) /* 0x4cc47c */) = cpu.edi;
L_0x0048d33d:
    // 0048d33d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d33f  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d341  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048d343  8b357cc44c00           -mov esi, dword ptr [0x4cc47c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5031036) /* 0x4cc47c */);
    // 0048d349  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0048d34b  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d34e  81e77f7f7f7f           -and edi, 0x7f7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 0048d354  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048d356  893d7cc44c00           -mov dword ptr [0x4cc47c], edi
    app->getMemory<x86::reg32>(x86::reg32(5031036) /* 0x4cc47c */) = cpu.edi;
    // 0048d35c  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0048d35e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048d361  81e77f7f0000           -and edi, 0x7f7f
    cpu.edi &= x86::reg32(x86::sreg32(32639 /*0x7f7f*/));
    // 0048d367  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0048d36a  81e10000007f           -and ecx, 0x7f000000
    cpu.ecx &= x86::reg32(x86::sreg32(2130706432 /*0x7f000000*/));
    // 0048d370  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0048d376  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d378  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d37a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d37d  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048d37f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d382  d1ef                   -shr edi, 1
    cpu.edi >>= 1 /*0x1*/ % 32;
    // 0048d384  81e67f7f007f           -and esi, 0x7f007f7f
    cpu.esi &= x86::reg32(x86::sreg32(2130739071 /*0x7f007f7f*/));
    // 0048d38a  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0048d38c  81e77f7f7f00           -and edi, 0x7f7f7f
    cpu.edi &= x86::reg32(x86::sreg32(8355711 /*0x7f7f7f*/));
    // 0048d392  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0048d395  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d397  81e500007f00           -and ebp, 0x7f0000
    cpu.ebp &= x86::reg32(x86::sreg32(8323072 /*0x7f0000*/));
    // 0048d39d  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0048d3a0  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048d3a2  8b0d78c44c00           -mov ecx, dword ptr [0x4cc478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */);
    // 0048d3a8  8973f8                 -mov dword ptr [ebx - 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0048d3ab  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048d3ac  890d78c44c00           -mov dword ptr [0x4cc478], ecx
    app->getMemory<x86::reg32>(x86::reg32(5031032) /* 0x4cc478 */) = cpu.ecx;
    // 0048d3b2  7589                   -jne 0x48d33d
    if (!cpu.flags.zf)
    {
        goto L_0x0048d33d;
    }
    // 0048d3b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d3b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d3b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d3b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d3ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d3bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d3bc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d3be  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048d3c0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048d3c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d3c4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d3c6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d3c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048d3ca:
    // 0048d3ca  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048d3cc  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048d3cf  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0048d3d2  8a5603                 -mov dl, byte ptr [esi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0048d3d5  8a8080c44c00           -mov al, byte ptr [eax + 0x4cc480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d3db  8a9b80c44c00           -mov bl, byte ptr [ebx + 0x4cc480]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d3e1  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0048d3e4  8a8980c44c00           -mov cl, byte ptr [ecx + 0x4cc480]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d3ea  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0048d3ed  8a9280c44c00           -mov dl, byte ptr [edx + 0x4cc480]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d3f3  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d3f5  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d3f7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048d3fa  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d3fd  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d3ff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d401  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048d403  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d405  8a4efc                 -mov cl, byte ptr [esi - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0048d408  8a56fd                 -mov dl, byte ptr [esi - 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */);
    // 0048d40b  8a46fe                 -mov al, byte ptr [esi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */);
    // 0048d40e  8a5eff                 -mov bl, byte ptr [esi - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0048d411  8a8980c44c00           -mov cl, byte ptr [ecx + 0x4cc480]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d417  8a9280c44c00           -mov dl, byte ptr [edx + 0x4cc480]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d41d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048d420  8a8080c44c00           -mov al, byte ptr [eax + 0x4cc480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d426  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0048d429  8a9b80c44c00           -mov bl, byte ptr [ebx + 0x4cc480]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5031040) /* 0x4cc480 */);
    // 0048d42f  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d431  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d433  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048d436  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d439  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d43b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d43d  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0048d440  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d442  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d445  7f83                   -jg 0x48d3ca
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048d3ca;
    }
    // 0048d447  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d448  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d449  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d44a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d44b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_48d450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d450  83ec04                 +sub esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d453  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0048d455  d85c2408               +fcomp dword ptr [esp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0048d459  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048d45b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0048d45c  771b                   -ja 0x48d479
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048d479;
    }
    // 0048d45e  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0048d462  dc05000c4c00           -fadd qword ptr [0x4c0c00]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4983808) /* 0x4c0c00 */));
    // 0048d468  e8a3ebfeff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0048d46d  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0048d470  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d473  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d476  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048d479:
    // 0048d479  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0048d47d  dc05f80b4c00           -fadd qword ptr [0x4c0bf8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4983800) /* 0x4c0bf8 */));
    // 0048d483  e888ebfeff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0048d488  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0048d48b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d48e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d491  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_48d494(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d494  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d495  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d496  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d497  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d498  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d499  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d49a  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048d49d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048d4a1  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 0048d4a6  bb71000000             -mov ebx, 0x71
    cpu.ebx = 113 /*0x71*/;
    // 0048d4ab  bf00180200             -mov edi, 0x21800
    cpu.edi = 137216 /*0x21800*/;
    // 0048d4b0  be0000802c             -mov esi, 0x2c800000
    cpu.esi = 746586112 /*0x2c800000*/;
    // 0048d4b5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048d4b7:
    // 0048d4b7  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048d4bb  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0048d4be  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0048d4c2  dc05280c4c00           -fadd qword ptr [0x4c0c28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4983848) /* 0x4c0c28 */));
    // 0048d4c8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d4ca  dd1424                 -fst qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    // 0048d4cd  dc0d080c4c00           -fmul qword ptr [0x4c0c08]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4983816) /* 0x4c0c08 */));
    // 0048d4d3  8982407e5200           -mov dword ptr [edx + 0x527e40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5406272) /* 0x527e40 */) = cpu.eax;
    // 0048d4d9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d4dc  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048d4df  e86cffffff             -call 0x48d450
    cpu.esp -= 4;
    sub_48d450(app, cpu);
    if (cpu.terminate) return;
    // 0048d4e4  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048d4e7  dc0d100c4c00           -fmul qword ptr [0x4c0c10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4983824) /* 0x4c0c10 */));
    // 0048d4ed  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d4f0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d4f2  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048d4f5  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d4fb  e850ffffff             -call 0x48d450
    cpu.esp -= 4;
    sub_48d450(app, cpu);
    if (cpu.terminate) return;
    // 0048d500  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048d503  c1e50b                 -shl ebp, 0xb
    cpu.ebp <<= 11 /*0xb*/ % 32;
    // 0048d506  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d50b  dc0d180c4c00           -fmul qword ptr [0x4c0c18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4983832) /* 0x4c0c18 */));
    // 0048d511  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d513  898240805200           -mov dword ptr [edx + 0x528040], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5406784) /* 0x528040 */) = cpu.eax;
    // 0048d519  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d51c  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048d51f  e82cffffff             -call 0x48d450
    cpu.esp -= 4;
    sub_48d450(app, cpu);
    if (cpu.terminate) return;
    // 0048d524  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048d527  dc0d200c4c00           -fmul qword ptr [0x4c0c20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4983840) /* 0x4c0c20 */));
    // 0048d52d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d530  81c700080000           -add edi, 0x800
    (cpu.edi) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 0048d536  81c600008000           -add esi, 0x800000
    (cpu.esi) += x86::reg32(x86::sreg32(8388608 /*0x800000*/));
    // 0048d53c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048d540  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d543  41                     -inc ecx
    (cpu.ecx)++;
    // 0048d544  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048d547  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d54b  e800ffffff             -call 0x48d450
    cpu.esp -= 4;
    sub_48d450(app, cpu);
    if (cpu.terminate) return;
    // 0048d550  81e5ff010000           -and ebp, 0x1ff
    cpu.ebp &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d556  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048d55b  c1e00b                 -shl eax, 0xb
    cpu.eax <<= 11 /*0xb*/ % 32;
    // 0048d55e  c1e517                 -shl ebp, 0x17
    cpu.ebp <<= 23 /*0x17*/ % 32;
    // 0048d561  43                     -inc ebx
    (cpu.ebx)++;
    // 0048d562  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d564  89823c825200           -mov dword ptr [edx + 0x52823c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5407292) /* 0x52823c */) = cpu.eax;
    // 0048d56a  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d56d  0f8c44ffffff           -jl 0x48d4b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d4b7;
    }
    // 0048d573  ba67ffffff             -mov edx, 0xffffff67
    cpu.edx = 4294967143 /*0xffffff67*/;
    // 0048d578  b99cfdffff             -mov ecx, 0xfffffd9c
    cpu.ecx = 4294966684 /*0xfffffd9c*/;
    // 0048d57d  be1f000000             -mov esi, 0x1f
    cpu.esi = 31 /*0x1f*/;
    // 0048d582  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d586  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048d588:
    // 0048d588  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048d58b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 0048d590  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d592  0f8c08010000           -jl 0x48d6a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d6a0;
    }
    // 0048d598  3dff000000             +cmp eax, 0xff
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
    // 0048d59d  7e05                   -jle 0x48d5a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d5a4;
    }
    // 0048d59f  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0048d5a4:
    // 0048d5a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d5a6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d5a9  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048d5ac  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0048d5af  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d5b2  7e02                   -jle 0x48d5b6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d5b6;
    }
    // 0048d5b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0048d5b6:
    // 0048d5b6  83fd0f                 +cmp ebp, 0xf
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d5b9  0f85e8000000           -jne 0x48d6a7
    if (!cpu.flags.zf)
    {
        goto L_0x0048d6a7;
    }
    // 0048d5bf  c1e31a                 -shl ebx, 0x1a
    cpu.ebx <<= 26 /*0x1a*/ % 32;
    // 0048d5c2  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
L_0x0048d5c5:
    // 0048d5c5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d5c7  8981dc7b5200           -mov dword ptr [ecx + 0x527bdc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5405660) /* 0x527bdc */) = cpu.eax;
    // 0048d5cd  42                     -inc edx
    (cpu.edx)++;
    // 0048d5ce  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d5d1  81fa99000000           +cmp edx, 0x99
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153 /*0x99*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d5d7  7caf                   -jl 0x48d588
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d588;
    }
    // 0048d5d9  ba7dffffff             -mov edx, 0xffffff7d
    cpu.edx = 4294967165 /*0xffffff7d*/;
    // 0048d5de  b9f4fdffff             -mov ecx, 0xfffffdf4
    cpu.ecx = 4294966772 /*0xfffffdf4*/;
    // 0048d5e3  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0048d5e8  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 0048d5ed  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048d5ef:
    // 0048d5ef  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048d5f2  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 0048d5f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d5f9  0f8cb3000000           -jl 0x48d6b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d6b2;
    }
    // 0048d5ff  3dff000000             +cmp eax, 0xff
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
    // 0048d604  7e02                   -jle 0x48d608
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d608;
    }
    // 0048d606  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0048d608:
    // 0048d608  837c24080f             +cmp dword ptr [esp + 8], 0xf
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d60d  0f85a6000000           -jne 0x48d6b9
    if (!cpu.flags.zf)
    {
        goto L_0x0048d6b9;
    }
    // 0048d613  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d615  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d618  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048d61b  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0048d61e  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d621  7e05                   -jle 0x48d628
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d628;
    }
    // 0048d623  b81f000000             -mov eax, 0x1f
    cpu.eax = 31 /*0x1f*/;
L_0x0048d628:
    // 0048d628  c1e315                 -shl ebx, 0x15
    cpu.ebx <<= 21 /*0x15*/ % 32;
    // 0048d62b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048d62e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d631  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d633  42                     -inc edx
    (cpu.edx)++;
    // 0048d634  898168775200           -mov dword ptr [ecx + 0x527768], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5404520) /* 0x527768 */) = cpu.eax;
    // 0048d63a  81fa83000000           +cmp edx, 0x83
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d640  7cad                   -jl 0x48d5ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d5ef;
    }
    // 0048d642  ba4fffffff             -mov edx, 0xffffff4f
    cpu.edx = 4294967119 /*0xffffff4f*/;
    // 0048d647  b93cfdffff             -mov ecx, 0xfffffd3c
    cpu.ecx = 4294966588 /*0xfffffd3c*/;
    // 0048d64c  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 0048d651  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
    // 0048d656  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048d658:
    // 0048d658  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0048d65b  0581000000             -add eax, 0x81
    (cpu.eax) += x86::reg32(x86::sreg32(129 /*0x81*/));
    // 0048d660  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d662  7c70                   -jl 0x48d6d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d6d4;
    }
    // 0048d664  3dff000000             +cmp eax, 0xff
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
    // 0048d669  7e02                   -jle 0x48d66d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d66d;
    }
    // 0048d66b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0048d66d:
    // 0048d66d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d66f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d672  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048d675  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0048d678  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d67b  7e02                   -jle 0x48d67f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d67f;
    }
    // 0048d67d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0048d67f:
    // 0048d67f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0048d682  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d685  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d687  42                     -inc edx
    (cpu.edx)++;
    // 0048d688  898198725200           -mov dword ptr [ecx + 0x527298], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5403288) /* 0x527298 */) = cpu.eax;
    // 0048d68e  81fab1000000           +cmp edx, 0xb1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(177 /*0xb1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d694  7cc2                   -jl 0x48d658
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d658;
    }
    // 0048d696  83c410                 +add esp, 0x10
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
    // 0048d699  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d69a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d69b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d69c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d69d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d69e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d69f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d6a0:
    // 0048d6a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d6a2  e9fdfeffff             -jmp 0x48d5a4
    goto L_0x0048d5a4;
L_0x0048d6a7:
    // 0048d6a7  c1e31b                 -shl ebx, 0x1b
    cpu.ebx <<= 27 /*0x1b*/ % 32;
    // 0048d6aa  c1e00b                 +shl eax, 0xb
    {
        x86::reg8 tmp = 11 /*0xb*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0048d6ad  e913ffffff             -jmp 0x48d5c5
    goto L_0x0048d5c5;
L_0x0048d6b2:
    // 0048d6b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d6b4  e94fffffff             -jmp 0x48d608
    goto L_0x0048d608;
L_0x0048d6b9:
    // 0048d6b9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d6bb  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048d6be  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048d6c1  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 0048d6c4  83f83f                 +cmp eax, 0x3f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d6c7  0f8e5bffffff           -jle 0x48d628
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d628;
    }
    // 0048d6cd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d6cf  e954ffffff             -jmp 0x48d628
    goto L_0x0048d628;
L_0x0048d6d4:
    // 0048d6d4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d6d6  eb95                   -jmp 0x48d66d
    goto L_0x0048d66d;
}

/* align: skip  */
void Application::sub_48d6d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d6d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d6d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d6da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d6db  81ec480a0000           -sub esp, 0xa48
    (cpu.esp) -= x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048d6e1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d6e3  899424100a0000         -mov dword ptr [esp + 0xa10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.edx;
    // 0048d6ea  899c240c0a0000         -mov dword ptr [esp + 0xa0c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebx;
    // 0048d6f1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048d6f3  8b94245c0a0000         -mov edx, dword ptr [esp + 0xa5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 0048d6fa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d6fc  0f85e8010000           -jne 0x48d8ea
    if (!cpu.flags.zf)
    {
        goto L_0x0048d8ea;
    }
    // 0048d702  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0048d707:
    // 0048d707  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d709  8a15d8a64c00           -mov dl, byte ptr [0x4ca6d8]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0048d70f  83fa0f                 +cmp edx, 0xf
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d712  7409                   -je 0x48d71d
    if (cpu.flags.zf)
    {
        goto L_0x0048d71d;
    }
    // 0048d714  83fa10                 +cmp edx, 0x10
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
    // 0048d717  0f85f7010000           -jne 0x48d914
    if (!cpu.flags.zf)
    {
        goto L_0x0048d914;
    }
L_0x0048d71d:
    // 0048d71d  3b1540845200           +cmp edx, dword ptr [0x528440]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5407808) /* 0x528440 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d723  740d                   -je 0x48d732
    if (cpu.flags.zf)
    {
        goto L_0x0048d732;
    }
    // 0048d725  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d727  e868fdffff             -call 0x48d494
    cpu.esp -= 4;
    sub_48d494(app, cpu);
    if (cpu.terminate) return;
    // 0048d72c  891540845200           -mov dword ptr [0x528440], edx
    app->getMemory<x86::reg32>(x86::reg32(5407808) /* 0x528440 */) = cpu.edx;
L_0x0048d732:
    // 0048d732  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d734  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d736  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0048d73c  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048d73f  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048d745  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048d748  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048d74e  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048d751  6683e6fe               -and si, 0xfffe
    cpu.si &= x86::reg16(x86::sreg16(65534 /*0xfffe*/));
    // 0048d755  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048d757  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d759  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d75b  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0048d75e  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0048d761  8b8424580a0000         -mov eax, dword ptr [esp + 0xa58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2648) /* 0xa58 */);
    // 0048d768  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048d76b  899424080a0000         -mov dword ptr [esp + 0xa08], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edx;
    // 0048d772  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d779  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d77b  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
    // 0048d782  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048d784  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d786  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048d789  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d78b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048d78d  8b15c8a64c00           -mov edx, dword ptr [0x4ca6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0048d793  898424040a0000         -mov dword ptr [esp + 0xa04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */) = cpu.eax;
    // 0048d79a  39d6                   +cmp esi, edx
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
    // 0048d79c  7d22                   -jge 0x48d7c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d7c0;
    }
    // 0048d79e  8d1c09                 -lea ebx, [ecx + ecx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 0048d7a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d7a3  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0048d7a6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d7a8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d7aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d7ac  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048d7af  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048d7b1  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048d7b4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d7b7  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d7b9  0184240c0a0000         -add dword ptr [esp + 0xa0c], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048d7c0:
    // 0048d7c0  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048d7c7  8b3dd0a64c00           -mov edi, dword ptr [0x4ca6d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 0048d7cd  39f8                   +cmp eax, edi
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
    // 0048d7cf  7e07                   -jle 0x48d7d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d7d8;
    }
    // 0048d7d1  89bc24080a0000         -mov dword ptr [esp + 0xa08], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */) = cpu.edi;
L_0x0048d7d8:
    // 0048d7d8  8b8424100a0000         -mov eax, dword ptr [esp + 0xa10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d7df  8b2dcca64c00           -mov ebp, dword ptr [0x4ca6cc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0048d7e5  39e8                   +cmp eax, ebp
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
    // 0048d7e7  7d47                   -jge 0x48d830
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d830;
    }
    // 0048d7e9  8b9424100a0000         -mov edx, dword ptr [esp + 0xa10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d7f0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d7f2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d7f4  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0048d7f7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d7f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d7fb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048d7fe  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048d800  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d802  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048d805  0faf8424040a0000       -imul eax, dword ptr [esp + 0xa04]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */))));
    // 0048d80d  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d814  8bac240c0a0000         -mov ebp, dword ptr [esp + 0xa0c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048d81b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d81e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d820  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d822  899c24100a0000         -mov dword ptr [esp + 0xa10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */) = cpu.ebx;
    // 0048d829  89ac240c0a0000         -mov dword ptr [esp + 0xa0c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */) = cpu.ebp;
L_0x0048d830:
    // 0048d830  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048d837  8b15d4a64c00           -mov edx, dword ptr [0x4ca6d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 0048d83d  39d0                   +cmp eax, edx
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
    // 0048d83f  7e07                   -jle 0x48d848
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d848;
    }
    // 0048d841  899424440a0000         -mov dword ptr [esp + 0xa44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */) = cpu.edx;
L_0x0048d848:
    // 0048d848  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048d84f  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d851  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d853  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d855  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048d858  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048d85a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d85c  83f802                 +cmp eax, 2
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
    // 0048d85f  0f8c77000000           -jl 0x48d8dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d8dc;
    }
    // 0048d865  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048d86c  8b8c245c0a0000         -mov ecx, dword ptr [esp + 0xa5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
    // 0048d873  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d876  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d878  0f85a7000000           -jne 0x48d925
    if (!cpu.flags.zf)
    {
        goto L_0x0048d925;
    }
    // 0048d87e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d885  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048d88c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048d893  39dd                   +cmp ebp, ebx
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
    // 0048d895  7d45                   -jge 0x48d8dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d8dc;
    }
    // 0048d897  898424200a0000         -mov dword ptr [esp + 0xa20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */) = cpu.eax;
L_0x0048d89e:
    // 0048d89e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048d8a0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d8a2  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0048d8a8  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048d8ab  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048d8b1  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048d8b4  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048d8ba  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048d8bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d8be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d8c0  45                     -inc ebp
    (cpu.ebp)++;
    // 0048d8c1  e882f7ffff             -call 0x48d048
    cpu.esp -= 4;
    sub_48d048(app, cpu);
    if (cpu.terminate) return;
    // 0048d8c6  8b8424200a0000         -mov eax, dword ptr [esp + 0xa20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2592) /* 0xa20 */);
    // 0048d8cd  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048d8d4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d8d6  39d5                   +cmp ebp, edx
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
    // 0048d8d8  7cc4                   -jl 0x48d89e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d89e;
    }
    // 0048d8da  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048d8dc:
    // 0048d8dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d8de  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048d8e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d8e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d8e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d8e7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d8ea:
    // 0048d8ea  83fa01                 +cmp edx, 1
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
    // 0048d8ed  750a                   -jne 0x48d8f9
    if (!cpu.flags.zf)
    {
        goto L_0x0048d8f9;
    }
L_0x0048d8ef:
    // 0048d8ef  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048d8f4  e90efeffff             -jmp 0x48d707
    goto L_0x0048d707;
L_0x0048d8f9:
    // 0048d8f9  83fa02                 +cmp edx, 2
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
    // 0048d8fc  74f1                   -je 0x48d8ef
    if (cpu.flags.zf)
    {
        goto L_0x0048d8ef;
    }
    // 0048d8fe  83fa03                 +cmp edx, 3
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
    // 0048d901  74ec                   -je 0x48d8ef
    if (cpu.flags.zf)
    {
        goto L_0x0048d8ef;
    }
    // 0048d903  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048d908  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048d90e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d90f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d910  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d911  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d914:
    // 0048d914  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0048d919  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048d91f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d920  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d921  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d922  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d925:
    // 0048d925  83f903                 +cmp ecx, 3
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
    // 0048d928  0f8578010000           -jne 0x48daa6
    if (!cpu.flags.zf)
    {
        goto L_0x0048daa6;
    }
    // 0048d92e  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d935  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048d93c  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048d943  39dd                   +cmp ebp, ebx
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
    // 0048d945  7d71                   -jge 0x48d9b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d9b8;
    }
    // 0048d947  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048d949  4a                     -dec edx
    (cpu.edx)--;
    // 0048d94a  899424180a0000         -mov dword ptr [esp + 0xa18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */) = cpu.edx;
    // 0048d951  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0048d954  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048d957  898424140a0000         -mov dword ptr [esp + 0xa14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */) = cpu.eax;
    // 0048d95e  899424280a0000         -mov dword ptr [esp + 0xa28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */) = cpu.edx;
L_0x0048d965:
    // 0048d965  8b9c24180a0000         -mov ebx, dword ptr [esp + 0xa18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2584) /* 0xa18 */);
    // 0048d96c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048d96e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d970  e849f9ffff             -call 0x48d2be
    cpu.esp -= 4;
    sub_48d2be(app, cpu);
    if (cpu.terminate) return;
    // 0048d975  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048d977  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d979  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0048d97f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048d982  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048d988  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048d98b  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048d991  8b9c24280a0000         -mov ebx, dword ptr [esp + 0xa28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2600) /* 0xa28 */);
    // 0048d998  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d99a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d99c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048d99f  e8a4f6ffff             -call 0x48d048
    cpu.esp -= 4;
    sub_48d048(app, cpu);
    if (cpu.terminate) return;
    // 0048d9a4  8b8424140a0000         -mov eax, dword ptr [esp + 0xa14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2580) /* 0xa14 */);
    // 0048d9ab  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048d9b2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d9b4  39d5                   +cmp ebp, edx
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
    // 0048d9b6  7cad                   -jl 0x48d965
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d965;
    }
L_0x0048d9b8:
    // 0048d9b8  8b9424080a0000         -mov edx, dword ptr [esp + 0xa08]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048d9bf  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048d9c6  8b8c24100a0000         -mov ecx, dword ptr [esp + 0xa10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d9cd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d9cf  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d9d1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048d9d4  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d9d9  0f8fae000000           -jg 0x48da8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048da8d;
    }
L_0x0048d9df:
    // 0048d9df  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048d9e6  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0048d9e9  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048d9f0  899424340a0000         -mov dword ptr [esp + 0xa34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */) = cpu.edx;
    // 0048d9f7  8b9424040a0000         -mov edx, dword ptr [esp + 0xa04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048d9fe  45                     -inc ebp
    (cpu.ebp)++;
    // 0048d9ff  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048da02  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048da04  899424240a0000         -mov dword ptr [esp + 0xa24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */) = cpu.edx;
    // 0048da0b  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048da12  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048da15  4a                     -dec edx
    (cpu.edx)--;
    // 0048da16  89bc24300a0000         -mov dword ptr [esp + 0xa30], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */) = cpu.edi;
    // 0048da1d  899424380a0000         -mov dword ptr [esp + 0xa38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */) = cpu.edx;
    // 0048da24  39d5                   +cmp ebp, edx
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
    // 0048da26  0f8db0feffff           -jge 0x48d8dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d8dc;
    }
L_0x0048da2c:
    // 0048da2c  8bbc24240a0000         -mov edi, dword ptr [esp + 0xa24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 0048da33  8b8c24340a0000         -mov ecx, dword ptr [esp + 0xa34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 0048da3a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048da3c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048da3e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048da40  e8d5f8ffff             -call 0x48d31a
    cpu.esp -= 4;
    sub_48d31a(app, cpu);
    if (cpu.terminate) return;
    // 0048da45  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048da47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048da49  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0048da4f  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048da52  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048da58  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048da5b  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048da61  8b9c24300a0000         -mov ebx, dword ptr [esp + 0xa30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2608) /* 0xa30 */);
    // 0048da68  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048da6a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048da6c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048da6f  e8d4f5ffff             -call 0x48d048
    cpu.esp -= 4;
    sub_48d048(app, cpu);
    if (cpu.terminate) return;
    // 0048da74  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048da76  3bac24380a0000         +cmp ebp, dword ptr [esp + 0xa38]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2616) /* 0xa38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048da7d  7cad                   -jl 0x48da2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048da2c;
    }
    // 0048da7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048da81  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048da87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da8a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048da8d:
    // 0048da8d  e8c6c2feff             -call 0x479d58
    cpu.esp -= 4;
    sub_479d58(app, cpu);
    if (cpu.terminate) return;
    // 0048da92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048da94  0f8545ffffff           -jne 0x48d9df
    if (!cpu.flags.zf)
    {
        goto L_0x0048d9df;
    }
    // 0048da9a  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048daa0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048daa1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048daa2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048daa3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048daa6:
    // 0048daa6  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048daad  8b9c24440a0000         -mov ebx, dword ptr [esp + 0xa44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048dab4  8b8c240c0a0000         -mov ecx, dword ptr [esp + 0xa0c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048dabb  39dd                   +cmp ebp, ebx
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
    // 0048dabd  7d45                   -jge 0x48db04
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048db04;
    }
    // 0048dabf  8984241c0a0000         -mov dword ptr [esp + 0xa1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */) = cpu.eax;
L_0x0048dac6:
    // 0048dac6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048dac8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048daca  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0048dad0  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048dad3  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048dad9  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048dadc  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048dae2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048dae4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048dae6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048dae8  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048daeb  e82bf6ffff             -call 0x48d11b
    cpu.esp -= 4;
    sub_48d11b(app, cpu);
    if (cpu.terminate) return;
    // 0048daf0  8b84241c0a0000         -mov eax, dword ptr [esp + 0xa1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2588) /* 0xa1c */);
    // 0048daf7  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048dafe  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048db00  39d5                   +cmp ebp, edx
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
    // 0048db02  7cc2                   -jl 0x48dac6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048dac6;
    }
L_0x0048db04:
    // 0048db04  83bc245c0a000002       +cmp dword ptr [esp + 0xa5c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2652) /* 0xa5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048db0c  0f85cafdffff           -jne 0x48d8dc
    if (!cpu.flags.zf)
    {
        goto L_0x0048d8dc;
    }
    // 0048db12  8b8424080a0000         -mov eax, dword ptr [esp + 0xa08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2568) /* 0xa08 */);
    // 0048db19  8b9424440a0000         -mov edx, dword ptr [esp + 0xa44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048db20  8b9c24100a0000         -mov ebx, dword ptr [esp + 0xa10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048db27  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048db29  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048db2b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048db2e  3d00580200             +cmp eax, 0x25800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(153600 /*0x25800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048db33  0f8fab000000           -jg 0x48dbe4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048dbe4;
    }
L_0x0048db39:
    // 0048db39  8b84240c0a0000         -mov eax, dword ptr [esp + 0xa0c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2572) /* 0xa0c */);
    // 0048db40  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 0048db47  8b8424040a0000         -mov eax, dword ptr [esp + 0xa04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2564) /* 0xa04 */);
    // 0048db4e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048db51  8984242c0a0000         -mov dword ptr [esp + 0xa2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */) = cpu.eax;
    // 0048db58  8b8424440a0000         -mov eax, dword ptr [esp + 0xa44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2628) /* 0xa44 */);
    // 0048db5f  8bac24100a0000         -mov ebp, dword ptr [esp + 0xa10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2576) /* 0xa10 */);
    // 0048db66  48                     -dec eax
    (cpu.eax)--;
    // 0048db67  45                     -inc ebp
    (cpu.ebp)++;
    // 0048db68  8984243c0a0000         -mov dword ptr [esp + 0xa3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */) = cpu.eax;
    // 0048db6f  39c5                   +cmp ebp, eax
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
    // 0048db71  0f8d65fdffff           -jge 0x48d8dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d8dc;
    }
L_0x0048db77:
    // 0048db77  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048db79  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048db7b  8b8c242c0a0000         -mov ecx, dword ptr [esp + 0xa2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2604) /* 0xa2c */);
    // 0048db82  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0048db88  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0048db8b  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0048db91  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0048db94  0305dca64c00           -add eax, dword ptr [0x4ca6dc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0048db9a  8b9424400a0000         -mov edx, dword ptr [esp + 0xa40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 0048dba1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048dba3  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048dba6  8b8424400a0000         -mov eax, dword ptr [esp + 0xa40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */);
    // 0048dbad  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dbaf  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048dbb1  899424000a0000         -mov dword ptr [esp + 0xa00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */) = cpu.edx;
    // 0048dbb8  e825f6ffff             -call 0x48d1e2
    cpu.esp -= 4;
    sub_48d1e2(app, cpu);
    if (cpu.terminate) return;
    // 0048dbbd  8b8424000a0000         -mov eax, dword ptr [esp + 0xa00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2560) /* 0xa00 */);
    // 0048dbc4  8b9c243c0a0000         -mov ebx, dword ptr [esp + 0xa3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2620) /* 0xa3c */);
    // 0048dbcb  898424400a0000         -mov dword ptr [esp + 0xa40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2624) /* 0xa40 */) = cpu.eax;
    // 0048dbd2  39dd                   +cmp ebp, ebx
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
    // 0048dbd4  7ca1                   -jl 0x48db77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048db77;
    }
    // 0048dbd6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dbd8  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048dbde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbe0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbe1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048dbe4:
    // 0048dbe4  e86fc1feff             -call 0x479d58
    cpu.esp -= 4;
    sub_479d58(app, cpu);
    if (cpu.terminate) return;
    // 0048dbe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048dbeb  0f8548ffffff           -jne 0x48db39
    if (!cpu.flags.zf)
    {
        goto L_0x0048db39;
    }
    // 0048dbf1  81c4480a0000           -add esp, 0xa48
    (cpu.esp) += x86::reg32(x86::sreg32(2632 /*0xa48*/));
    // 0048dbf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbf8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbf9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbfa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48dc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dc01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dc02  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048dc04  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048dc06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048dc08  7505                   -jne 0x48dc0f
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc0f;
    }
L_0x0048dc0a:
    // 0048dc0a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dc0f:
    // 0048dc0f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048dc14  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048dc16  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048dc18  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048dc1a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048dc21  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048dc23  3dfbc00000             +cmp eax, 0xc0fb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49403 /*0xc0fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dc28  750a                   -jne 0x48dc34
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc34;
    }
    // 0048dc2a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048dc2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dc34:
    // 0048dc34  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048dc39  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048dc3b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048dc3d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048dc3f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048dc41  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048dc48  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048dc4a  3d46474942             +cmp eax, 0x42494746
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1112098630 /*0x42494746*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dc4f  75b9                   -jne 0x48dc0a
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc0a;
    }
    // 0048dc51  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0048dc56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48dc5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc5c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dc5d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048dc5f  e89cffffff             -call 0x48dc00
    cpu.esp -= 4;
    sub_48dc00(app, cpu);
    if (cpu.terminate) return;
    // 0048dc64  83f801                 +cmp eax, 1
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
    // 0048dc67  7207                   -jb 0x48dc70
    if (cpu.flags.cf)
    {
        goto L_0x0048dc70;
    }
    // 0048dc69  7609                   -jbe 0x48dc74
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048dc74;
    }
    // 0048dc6b  83f802                 +cmp eax, 2
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
    // 0048dc6e  7420                   -je 0x48dc90
    if (cpu.flags.zf)
    {
        goto L_0x0048dc90;
    }
L_0x0048dc70:
    // 0048dc70  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dc72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dc74:
    // 0048dc74  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0048dc77  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048dc7c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048dc7e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048dc80  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048dc82  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048dc89  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048dc8b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dc8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dc90:
    // 0048dc90  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048dc93  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048dc98  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048dc9a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048dc9c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048dc9e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048dca5  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048dca7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dca8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48dcac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dcac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dcad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dcae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dcaf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048dcb2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048dcb4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048dcb6  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048dcba  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048dcbd  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048dcc1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048dcc3  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048dcc7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048dcc9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048dccb  e88cffffff             -call 0x48dc5c
    cpu.esp -= 4;
    sub_48dc5c(app, cpu);
    if (cpu.terminate) return;
    // 0048dcd0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048dcd2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048dcd4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048dcd6  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0048dcda  e821ffffff             -call 0x48dc00
    cpu.esp -= 4;
    sub_48dc00(app, cpu);
    if (cpu.terminate) return;
    // 0048dcdf  83f801                 +cmp eax, 1
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
    // 0048dce2  7327                   -jae 0x48dd0b
    if (!cpu.flags.cf)
    {
        goto L_0x0048dd0b;
    }
L_0x0048dce4:
    // 0048dce4  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0048dce7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048dce9  7406                   -je 0x48dcf1
    if (cpu.flags.zf)
    {
        goto L_0x0048dcf1;
    }
    // 0048dceb  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x0048dcf1:
    // 0048dcf1  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048dcf5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048dcf7  7407                   -je 0x48dd00
    if (cpu.flags.zf)
    {
        goto L_0x0048dd00;
    }
    // 0048dcf9  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
L_0x0048dd00:
    // 0048dd00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dd02  83c410                 +add esp, 0x10
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
    // 0048dd05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd08  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048dd0b:
    // 0048dd0b  0f8777000000           -ja 0x48dd88
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048dd88;
    }
    // 0048dd11  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048dd15  8d5f06                 -lea ebx, [edi + 6]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0048dd18  39f3                   +cmp ebx, esi
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
    // 0048dd1a  73c8                   -jae 0x48dce4
    if (!cpu.flags.cf)
    {
        goto L_0x0048dce4;
    }
L_0x0048dd1c:
    // 0048dd1c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048dd1e  0f85e0000000           -jne 0x48de04
    if (!cpu.flags.zf)
    {
        goto L_0x0048de04;
    }
L_0x0048dd24:
    // 0048dd24  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048dd26  0f8558010000           -jne 0x48de84
    if (!cpu.flags.zf)
    {
        goto L_0x0048de84;
    }
    // 0048dd2c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048dd30  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dd34  0f854a010000           -jne 0x48de84
    if (!cpu.flags.zf)
    {
        goto L_0x0048de84;
    }
L_0x0048dd3a:
    // 0048dd3a  833c2400               +cmp dword ptr [esp], 0
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
    // 0048dd3e  741b                   -je 0x48dd5b
    if (cpu.flags.zf)
    {
        goto L_0x0048dd5b;
    }
    // 0048dd40  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0048dd45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048dd47  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048dd49  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048dd4b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048dd4d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048dd54  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048dd56  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048dd59  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0048dd5b:
    // 0048dd5b  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048dd5f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048dd61  7419                   -je 0x48dd7c
    if (cpu.flags.zf)
    {
        goto L_0x0048dd7c;
    }
    // 0048dd63  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0048dd68  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0048dd6b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048dd6d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048dd6f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048dd71  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048dd78  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048dd7a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0048dd7c:
    // 0048dd7c  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0048dd7f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048dd82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd85  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048dd88:
    // 0048dd88  83f802                 +cmp eax, 2
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
    // 0048dd8b  0f8553ffffff           -jne 0x48dce4
    if (!cpu.flags.zf)
    {
        goto L_0x0048dce4;
    }
    // 0048dd91  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048dd95  8d5f10                 -lea ebx, [edi + 0x10]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0048dd98  39cb                   +cmp ebx, ecx
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
    // 0048dd9a  0f8344ffffff           -jae 0x48dce4
    if (!cpu.flags.cf)
    {
        goto L_0x0048dce4;
    }
L_0x0048dda0:
    // 0048dda0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048dda2  0f851e010000           -jne 0x48dec6
    if (!cpu.flags.zf)
    {
        goto L_0x0048dec6;
    }
    // 0048dda8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048ddac  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ddb0  0f8510010000           -jne 0x48dec6
    if (!cpu.flags.zf)
    {
        goto L_0x0048dec6;
    }
L_0x0048ddb6:
    // 0048ddb6  833c2400               +cmp dword ptr [esp], 0
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
    // 0048ddba  741b                   -je 0x48ddd7
    if (cpu.flags.zf)
    {
        goto L_0x0048ddd7;
    }
    // 0048ddbc  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ddc1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ddc3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ddc5  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ddc7  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ddc9  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ddd0  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ddd2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ddd5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0048ddd7:
    // 0048ddd7  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048dddb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048dddd  7419                   -je 0x48ddf8
    if (cpu.flags.zf)
    {
        goto L_0x0048ddf8;
    }
    // 0048dddf  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048dde4  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048dde7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048dde9  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ddeb  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048dded  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ddf4  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ddf6  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0048ddf8:
    // 0048ddf8  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048ddfb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048ddfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de01  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048de04:
    // 0048de04  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048de08  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0048de0a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048de0c  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048de0e  81ce20202020           -or esi, 0x20202020
    cpu.esi |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
L_0x0048de14:
    // 0048de14  39d7                   +cmp edi, edx
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
    // 0048de16  7d65                   -jge 0x48de7d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048de7d;
    }
    // 0048de18  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0048de1b  0d20202020             -or eax, 0x20202020
    cpu.eax |= x86::reg32(x86::sreg32(538976288 /*0x20202020*/));
    // 0048de20  39f0                   +cmp eax, esi
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
    // 0048de22  7459                   -je 0x48de7d
    if (cpu.flags.zf)
    {
        goto L_0x0048de7d;
    }
    // 0048de24  8b470a                 -mov eax, dword ptr [edi + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0048de27  8d7f0e                 -lea edi, [edi + 0xe]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(14) /* 0xe */);
    // 0048de2a  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 0048de2f  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0048de34  7522                   -jne 0x48de58
    if (!cpu.flags.zf)
    {
        goto L_0x0048de58;
    }
    // 0048de36  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048de38  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048de3b  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 0048de40  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0048de45  7511                   -jne 0x48de58
    if (!cpu.flags.zf)
    {
        goto L_0x0048de58;
    }
L_0x0048de47:
    // 0048de47  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048de49  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048de4c  2d01010101             -sub eax, 0x1010101
    (cpu.eax) -= x86::reg32(x86::sreg32(16843009 /*0x1010101*/));
    // 0048de51  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0048de56  74ef                   -je 0x48de47
    if (cpu.flags.zf)
    {
        goto L_0x0048de47;
    }
L_0x0048de58:
    // 0048de58  8a47fc                 -mov al, byte ptr [edi - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0048de5b  8d7ffd                 -lea edi, [edi - 3]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(-3) /* -0x3 */);
    // 0048de5e  3c00                   +cmp al, 0
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
    // 0048de60  74b2                   -je 0x48de14
    if (cpu.flags.zf)
    {
        goto L_0x0048de14;
    }
    // 0048de62  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0048de64  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048de67  3c00                   +cmp al, 0
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
    // 0048de69  74a9                   -je 0x48de14
    if (cpu.flags.zf)
    {
        goto L_0x0048de14;
    }
    // 0048de6b  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0048de6d  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048de70  3c00                   +cmp al, 0
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
    // 0048de72  74a0                   -je 0x48de14
    if (cpu.flags.zf)
    {
        goto L_0x0048de14;
    }
    // 0048de74  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0048de76  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048de79  3c00                   +cmp al, 0
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
    // 0048de7b  7497                   -je 0x48de14
    if (cpu.flags.zf)
    {
        goto L_0x0048de14;
    }
L_0x0048de7d:
    // 0048de7d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048de7f  e9a0feffff             -jmp 0x48dd24
    goto L_0x0048dd24;
L_0x0048de84:
    // 0048de84  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048de86  7412                   -je 0x48de9a
    if (cpu.flags.zf)
    {
        goto L_0x0048de9a;
    }
    // 0048de88  8d4306                 -lea eax, [ebx + 6]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0048de8b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048de8d  e8511b0000             -call 0x48f9e3
    cpu.esp -= 4;
    sub_48f9e3(app, cpu);
    if (cpu.terminate) return;
    // 0048de92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048de94  0f84a0feffff           -je 0x48dd3a
    if (cpu.flags.zf)
    {
        goto L_0x0048dd3a;
    }
L_0x0048de9a:
    // 0048de9a  8d7b06                 -lea edi, [ebx + 6]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0048de9d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048de9f  49                     -dec ecx
    (cpu.ecx)--;
    // 0048dea0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048dea2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048dea4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048dea6  49                     -dec ecx
    (cpu.ecx)--;
    // 0048dea7  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048deab  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048deaf  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048deb1  47                     -inc edi
    (cpu.edi)++;
    // 0048deb2  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0048deb5  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048deb9  39c3                   +cmp ebx, eax
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
    // 0048debb  0f825bfeffff           -jb 0x48dd1c
    if (cpu.flags.cf)
    {
        goto L_0x0048dd1c;
    }
    // 0048dec1  e91efeffff             -jmp 0x48dce4
    goto L_0x0048dce4;
L_0x0048dec6:
    // 0048dec6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048dec8  7412                   -je 0x48dedc
    if (cpu.flags.zf)
    {
        goto L_0x0048dedc;
    }
    // 0048deca  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048decd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048decf  e80f1b0000             -call 0x48f9e3
    cpu.esp -= 4;
    sub_48f9e3(app, cpu);
    if (cpu.terminate) return;
    // 0048ded4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ded6  0f84dafeffff           -je 0x48ddb6
    if (cpu.flags.zf)
    {
        goto L_0x0048ddb6;
    }
L_0x0048dedc:
    // 0048dedc  8d7b08                 -lea edi, [ebx + 8]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048dedf  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dee1  49                     -dec ecx
    (cpu.ecx)--;
    // 0048dee2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048dee4  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048dee6  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048dee8  49                     -dec ecx
    (cpu.ecx)--;
    // 0048dee9  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048deed  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048def1  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048def3  47                     -inc edi
    (cpu.edi)++;
    // 0048def4  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0048def7  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048defb  39c3                   +cmp ebx, eax
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
    // 0048defd  0f829dfeffff           -jb 0x48dda0
    if (cpu.flags.cf)
    {
        goto L_0x0048dda0;
    }
    // 0048df03  e9dcfdffff             -jmp 0x48dce4
    goto L_0x0048dce4;
}

/* align: skip  */
void Application::sub_48df08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048df09  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048df0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048df0d  6844845200             -push 0x528444
    app->getMemory<x86::reg32>(cpu.esp-4) = 5407812 /*0x528444*/;
    cpu.esp -= 4;
    // 0048df12  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048df16  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048df18  e88ffdffff             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0048df1d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048df20  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048df23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48df28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048df29  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048df2e  e8d5ffffff             -call 0x48df08
    cpu.esp -= 4;
    sub_48df08(app, cpu);
    if (cpu.terminate) return;
    // 0048df33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48df38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048df39  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048df3b  e8c8ffffff             -call 0x48df08
    cpu.esp -= 4;
    sub_48df08(app, cpu);
    if (cpu.terminate) return;
    // 0048df40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48df44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048df45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048df46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048df48  e8bbffffff             -call 0x48df08
    cpu.esp -= 4;
    sub_48df08(app, cpu);
    if (cpu.terminate) return;
    // 0048df4d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048df4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048df51  7403                   -je 0x48df56
    if (cpu.flags.zf)
    {
        goto L_0x0048df56;
    }
    // 0048df53  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
L_0x0048df56:
    // 0048df56  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048df58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48df5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048df5d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048df62  e8ddffffff             -call 0x48df44
    cpu.esp -= 4;
    sub_48df44(app, cpu);
    if (cpu.terminate) return;
    // 0048df67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48df6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048df6d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048df6f  e8d0ffffff             -call 0x48df44
    cpu.esp -= 4;
    sub_48df44(app, cpu);
    if (cpu.terminate) return;
    // 0048df74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48df78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df78  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048df79  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048df7a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048df7b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048df7e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048df81  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048df83  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0048df85:
    // 0048df85  b22c                   -mov dl, 0x2c
    cpu.dl = 44 /*0x2c*/;
    // 0048df87  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0048df89:
    // 0048df89  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048df8b  3ac2                   +cmp al, dl
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
    // 0048df8d  7412                   -je 0x48dfa1
    if (cpu.flags.zf)
    {
        goto L_0x0048dfa1;
    }
    // 0048df8f  3c00                   +cmp al, 0
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
    // 0048df91  740c                   -je 0x48df9f
    if (cpu.flags.zf)
    {
        goto L_0x0048df9f;
    }
    // 0048df93  46                     -inc esi
    (cpu.esi)++;
    // 0048df94  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048df96  3ac2                   +cmp al, dl
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
    // 0048df98  7407                   -je 0x48dfa1
    if (cpu.flags.zf)
    {
        goto L_0x0048dfa1;
    }
    // 0048df9a  46                     -inc esi
    (cpu.esi)++;
    // 0048df9b  3c00                   +cmp al, 0
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
    // 0048df9d  75ea                   -jne 0x48df89
    if (!cpu.flags.zf)
    {
        goto L_0x0048df89;
    }
L_0x0048df9f:
    // 0048df9f  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048dfa1:
    // 0048dfa1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048dfa3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048dfa5  7403                   -je 0x48dfaa
    if (cpu.flags.zf)
    {
        goto L_0x0048dfaa;
    }
    // 0048dfa7  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
L_0x0048dfaa:
    // 0048dfaa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048dfad  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048dfaf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048dfb1  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dfb4  e88bffffff             -call 0x48df44
    cpu.esp -= 4;
    sub_48df44(app, cpu);
    if (cpu.terminate) return;
    // 0048dfb9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048dfbc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048dfbe  7406                   -je 0x48dfc6
    if (cpu.flags.zf)
    {
        goto L_0x0048dfc6;
    }
    // 0048dfc0  c6012c                 -mov byte ptr [ecx], 0x2c
    app->getMemory<x86::reg8>(cpu.ecx) = 44 /*0x2c*/;
    // 0048dfc3  41                     -inc ecx
    (cpu.ecx)++;
    // 0048dfc4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0048dfc6:
    // 0048dfc6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048dfc8  75bb                   -jne 0x48df85
    if (!cpu.flags.zf)
    {
        goto L_0x0048df85;
    }
    // 0048dfca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dfcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48dfd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dfd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dfd5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048dfda  e899ffffff             -call 0x48df78
    cpu.esp -= 4;
    sub_48df78(app, cpu);
    if (cpu.terminate) return;
    // 0048dfdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfe0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48dfe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dfe4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dfe5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dfe7  e88cffffff             -call 0x48df78
    cpu.esp -= 4;
    sub_48df78(app, cpu);
    if (cpu.terminate) return;
    // 0048dfec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48dff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dff2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048dff3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048dff5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048dff7  e804fcffff             -call 0x48dc00
    cpu.esp -= 4;
    sub_48dc00(app, cpu);
    if (cpu.terminate) return;
    // 0048dffc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048dffe  83f801                 +cmp eax, 1
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
    // 0048e001  7207                   -jb 0x48e00a
    if (cpu.flags.cf)
    {
        goto L_0x0048e00a;
    }
    // 0048e003  760b                   -jbe 0x48e010
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048e010;
    }
    // 0048e005  83f802                 +cmp eax, 2
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
    // 0048e008  7421                   -je 0x48e02b
    if (cpu.flags.zf)
    {
        goto L_0x0048e02b;
    }
L_0x0048e00a:
    // 0048e00a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048e00c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e00d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e00e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e00f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e010:
    // 0048e010  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048e013  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048e018  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e01a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048e01c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048e01e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048e025  d3e8                   +shr eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0048e027  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048e029  ebdf                   -jmp 0x48e00a
    goto L_0x0048e00a;
L_0x0048e02b:
    // 0048e02b  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048e02e  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048e033  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e035  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048e037  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048e039  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048e040  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048e042  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048e044  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048e046  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e047  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e048  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e049  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e04c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e04c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e04d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e04e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e04f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048e052  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e054  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048e056  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e05a  6844845200             -push 0x528444
    app->getMemory<x86::reg32>(cpu.esp-4) = 5407812 /*0x528444*/;
    cpu.esp -= 4;
    // 0048e05f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048e061  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e063  e844fcffff             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0048e068  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e06a  7405                   -je 0x48e071
    if (cpu.flags.zf)
    {
        goto L_0x0048e071;
    }
    // 0048e06c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e06f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0048e071:
    // 0048e071  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048e074  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e075  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e076  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e077  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e078  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e079  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e07a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048e07c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048e07e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048e080  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048e082  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e084  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e086  e821fcffff             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0048e08b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e08d  7507                   -jne 0x48e096
    if (!cpu.flags.zf)
    {
        goto L_0x0048e096;
    }
    // 0048e08f  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 0048e093  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e094  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e095  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e096:
    // 0048e096  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e097  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e098  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e09a  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0048e09c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048e09d:
    // 0048e09d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048e09f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048e0a1  3c00                   +cmp al, 0
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
    // 0048e0a3  7410                   -je 0x48e0b5
    if (cpu.flags.zf)
    {
        goto L_0x0048e0b5;
    }
    // 0048e0a5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048e0a8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e0ab  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048e0ae  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e0b1  3c00                   +cmp al, 0
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
    // 0048e0b3  75e8                   -jne 0x48e09d
    if (!cpu.flags.zf)
    {
        goto L_0x0048e09d;
    }
L_0x0048e0b5:
    // 0048e0b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0b6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e0b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48e0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048e0c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e0c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e0c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e0c4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048e0c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e0c8  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048e0ca  7d05                   -jge 0x48e0d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e0d1;
    }
    // 0048e0cc  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048e0cf  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x0048e0d1:
    // 0048e0d1  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048e0d3  7d05                   -jge 0x48e0da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e0da;
    }
    // 0048e0d5  83cb10                 -or ebx, 0x10
    cpu.ebx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048e0d8  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0048e0da:
    // 0048e0da  39ca                   +cmp edx, ecx
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
    // 0048e0dc  7c07                   -jl 0x48e0e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e0e5;
    }
    // 0048e0de  741d                   -je 0x48e0fd
    if (cpu.flags.zf)
    {
        goto L_0x0048e0fd;
    }
    // 0048e0e0  87d1                   -xchg ecx, edx
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.edx;
        cpu.edx = tmp;
    }
    // 0048e0e2  83cb04                 -or ebx, 4
    cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0048e0e5:
    // 0048e0e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e0e7  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0048e0e9  c1e818                 +shr eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0048e0ec  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e0ef  0fb680a0e54c00         -movzx eax, byte ptr [eax + 0x4ce5a0]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5039520) /* 0x4ce5a0 */));
    // 0048e0f6  2effa309e14800         -jmp dword ptr cs:[ebx + 0x48e109]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + 4776201); goto dynamic_jump;
L_0x0048e0fd:
    // 0048e0fd  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 0048e102  2effa309e14800         -jmp dword ptr cs:[ebx + 0x48e109]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + 4776201); goto dynamic_jump;
  case 0x0048e129:
    // 0048e129  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048e12b  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
  [[fallthrough]];
  case 0x0048e130:
    // 0048e130  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e131  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e132  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048e133:
    // 0048e133  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048e135  0500020000             -add eax, 0x200
    (cpu.eax) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0048e13a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e13b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e13c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048e13d:
    // 0048e13d  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0048e142  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e143  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e144  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048e145:
    // 0048e145  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048e147  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e148  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e149  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048e14a:
    // 0048e14a  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0048e14f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e150  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e151  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048e152:
    // 0048e152  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0048e157  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e158  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e159  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048e15a:
    // 0048e15a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048e15c  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0048e161  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e162  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e163  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48e170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e171  39d0                   +cmp eax, edx
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
    // 0048e173  7526                   -jne 0x48e19b
    if (!cpu.flags.zf)
    {
        goto L_0x0048e19b;
    }
    // 0048e175  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048e178  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048e17b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048e17e  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048e181  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048e184  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048e187  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0048e18a  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048e18d  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048e190  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048e193  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0048e196  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048e199  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e19a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e19b:
    // 0048e19b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e19d  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048e19f  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048e1a2  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048e1a5  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048e1a8  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048e1ab  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048e1ae  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048e1b1  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048e1b4  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048e1b7  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048e1ba  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0048e1bd  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048e1c0  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0048e1c3  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048e1c6  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0048e1c9  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048e1cc  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048e1cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e1d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48e1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e1e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e1e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e1e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e1e3  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0048e1e9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e1eb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048e1ed  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048e1ef  e894f0feff             -call 0x47d288
    cpu.esp -= 4;
    sub_47d288(app, cpu);
    if (cpu.terminate) return;
    // 0048e1f4  8d43f8                 -lea eax, [ebx - 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-8) /* -0x8 */);
    // 0048e1f7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e1f9  3d00010000             +cmp eax, 0x100
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
    // 0048e1fe  7d05                   -jge 0x48e205
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e205;
    }
    // 0048e200  83f808                 +cmp eax, 8
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
    // 0048e203  7e35                   -jle 0x48e23a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e23a;
    }
L_0x0048e205:
    // 0048e205  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048e208  3d00010000             +cmp eax, 0x100
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
    // 0048e20d  7d24                   -jge 0x48e233
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e233;
    }
L_0x0048e20f:
    // 0048e20f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048e211:
    // 0048e211  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e213  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e215  e85ef0feff             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 0048e21a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e21c  7523                   -jne 0x48e241
    if (!cpu.flags.zf)
    {
        goto L_0x0048e241;
    }
L_0x0048e21e:
    // 0048e21e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048e220  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e222  e861f0feff             -call 0x47d288
    cpu.esp -= 4;
    sub_47d288(app, cpu);
    if (cpu.terminate) return;
    // 0048e227  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e229  81c400010000           +add esp, 0x100
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e22f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e230  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e231  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e232  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e233:
    // 0048e233  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0048e238  ebd5                   -jmp 0x48e20f
    goto L_0x0048e20f;
L_0x0048e23a:
    // 0048e23a  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0048e23f  ebd0                   -jmp 0x48e211
    goto L_0x0048e211;
L_0x0048e241:
    // 0048e241  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048e243  e80c100000             -call 0x48f254
    cpu.esp -= 4;
    sub_48f254(app, cpu);
    if (cpu.terminate) return;
    // 0048e248  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e24a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e24c  75d0                   -jne 0x48e21e
    if (!cpu.flags.zf)
    {
        goto L_0x0048e21e;
    }
    // 0048e24e  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048e250  ebcc                   -jmp 0x48e21e
    goto L_0x0048e21e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e254  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e255  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048e25a  e811000000             -call 0x48e270
    cpu.esp -= 4;
    sub_48e270(app, cpu);
    if (cpu.terminate) return;
    // 0048e25f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e260  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e264(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e264  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e265  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e267  e804000000             -call 0x48e270
    cpu.esp -= 4;
    sub_48e270(app, cpu);
    if (cpu.terminate) return;
    // 0048e26c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e26d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e270  e823000000             -call 0x48e298
    cpu.esp -= 4;
    sub_48e298(app, cpu);
    if (cpu.terminate) return;
    // 0048e275  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e277  7402                   -je 0x48e27b
    if (cpu.flags.zf)
    {
        goto L_0x0048e27b;
    }
    // 0048e279  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0048e27b:
    // 0048e27b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e27c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e27c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e27d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048e282  e811000000             -call 0x48e298
    cpu.esp -= 4;
    sub_48e298(app, cpu);
    if (cpu.terminate) return;
    // 0048e287  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e288  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e28c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e28c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e28d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e28f  e804000000             -call 0x48e298
    cpu.esp -= 4;
    sub_48e298(app, cpu);
    if (cpu.terminate) return;
    // 0048e294  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e295  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e298(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e298  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e299  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e29a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e29b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e29c  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048e29f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e2a1  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048e2a5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048e2a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e2a9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048e2ad  e8c29d0000             -call 0x498074
    cpu.esp -= 4;
    sub_498074(app, cpu);
    if (cpu.terminate) return;
    // 0048e2b2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e2b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e2b8  7419                   -je 0x48e2d3
    if (cpu.flags.zf)
    {
        goto L_0x0048e2d3;
    }
L_0x0048e2ba:
    // 0048e2ba  833d80ce4c0000         +cmp dword ptr [0x4cce80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033600) /* 0x4cce80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e2c1  0f85a1000000           -jne 0x48e368
    if (!cpu.flags.zf)
    {
        goto L_0x0048e368;
    }
    // 0048e2c7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e2cb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048e2ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e2d3:
    // 0048e2d3  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e2d7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e2d9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e2da  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e2dc  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e2e0  e88feefeff             -call 0x47d174
    cpu.esp -= 4;
    sub_47d174(app, cpu);
    if (cpu.terminate) return;
    // 0048e2e5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e2e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e2e9  74cf                   -je 0x48e2ba
    if (cpu.flags.zf)
    {
        goto L_0x0048e2ba;
    }
    // 0048e2eb  e8640f0000             -call 0x48f254
    cpu.esp -= 4;
    sub_48f254(app, cpu);
    if (cpu.terminate) return;
    // 0048e2f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e2f2  7540                   -jne 0x48e334
    if (!cpu.flags.zf)
    {
        goto L_0x0048e334;
    }
    // 0048e2f4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048e2f6  7432                   -je 0x48e32a
    if (cpu.flags.zf)
    {
        goto L_0x0048e32a;
    }
    // 0048e2f8  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0048e2fd  742b                   -je 0x48e32a
    if (cpu.flags.zf)
    {
        goto L_0x0048e32a;
    }
    // 0048e2ff  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e303  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e307  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048e309  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e30b  e854bffeff             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0048e310  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e314  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e316  7412                   -je 0x48e32a
    if (cpu.flags.zf)
    {
        goto L_0x0048e32a;
    }
    // 0048e318  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e31c  e83fbffeff             -call 0x47a260
    cpu.esp -= 4;
    sub_47a260(app, cpu);
    if (cpu.terminate) return;
    // 0048e321  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e323  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e325  e8d632ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
L_0x0048e32a:
    // 0048e32a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e32d  e83eeffeff             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0048e332  eb86                   -jmp 0x48e2ba
    goto L_0x0048e2ba;
L_0x0048e334:
    // 0048e334  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e338  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048e33a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e33c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e33e  e821bffeff             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0048e343  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e347  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e349  74df                   -je 0x48e32a
    if (cpu.flags.zf)
    {
        goto L_0x0048e32a;
    }
    // 0048e34b  e810bffeff             -call 0x47a260
    cpu.esp -= 4;
    sub_47a260(app, cpu);
    if (cpu.terminate) return;
    // 0048e350  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048e352  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e354  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e356  e8450e0000             -call 0x48f1a0
    cpu.esp -= 4;
    sub_48f1a0(app, cpu);
    if (cpu.terminate) return;
    // 0048e35b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e35e  e80deffeff             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0048e363  e952ffffff             -jmp 0x48e2ba
    goto L_0x0048e2ba;
L_0x0048e368:
    // 0048e368  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e36c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e370  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048e372  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048e374  ff1580ce4c00           -call dword ptr [0x4cce80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033600) /* 0x4cce80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e37a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e37e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e382  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048e385  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e386  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e387  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e389  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48e390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e391  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e393  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048e39a  7410                   -je 0x48e3ac
    if (cpu.flags.zf)
    {
        goto L_0x0048e3ac;
    }
    // 0048e39c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048e39e  7c05                   -jl 0x48e3a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e3a5;
    }
    // 0048e3a0  83fa7f                 +cmp edx, 0x7f
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
    // 0048e3a3  7e0e                   -jle 0x48e3b3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e3b3;
    }
L_0x0048e3a5:
    // 0048e3a5  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048e3aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e3ac:
    // 0048e3ac  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048e3b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e3b3:
    // 0048e3b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e3b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e3b5  e8f6a90000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048e3ba  bbd0a75200             -mov ebx, 0x52a7d0
    cpu.ebx = 5416912 /*0x52a7d0*/;
    // 0048e3bf  88152dae5200           -mov byte ptr [0x52ae2d], dl
    app->getMemory<x86::reg8>(x86::reg32(5418541) /* 0x52ae2d */) = cpu.dl;
    // 0048e3c5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048e3c7:
    // 0048e3c7  807b0c01               +cmp byte ptr [ebx + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048e3cb  7519                   -jne 0x48e3e6
    if (!cpu.flags.zf)
    {
        goto L_0x0048e3e6;
    }
    // 0048e3cd  833b00                 +cmp dword ptr [ebx], 0
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
    // 0048e3d0  7c14                   -jl 0x48e3e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e3e6;
    }
    // 0048e3d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e3d4  e817ef0000             -call 0x49d2f0
    cpu.esp -= 4;
    sub_49d2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048e3d9  8b532e                 -mov edx, dword ptr [ebx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 0048e3dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e3de  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048e3e1  e83e1dffff             -call 0x480124
    cpu.esp -= 4;
    sub_480124(app, cpu);
    if (cpu.terminate) return;
L_0x0048e3e6:
    // 0048e3e6  41                     -inc ecx
    (cpu.ecx)++;
    // 0048e3e7  83c360                 -add ebx, 0x60
    (cpu.ebx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048e3ea  83f910                 +cmp ecx, 0x10
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
    // 0048e3ed  7cd8                   -jl 0x48e3c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e3c7;
    }
    // 0048e3ef  e8d0a90000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048e3f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e3f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e3f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48e400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e400  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e401  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048e403:
    // 0048e403  8b82d0a75200           -mov eax, dword ptr [edx + 0x52a7d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5416912) /* 0x52a7d0 */);
    // 0048e409  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048e40c  e8af20ffff             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
    // 0048e411  81fa00060000           +cmp edx, 0x600
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1536 /*0x600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e417  75ea                   -jne 0x48e403
    if (!cpu.flags.zf)
    {
        goto L_0x0048e403;
    }
    // 0048e419  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e41a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48e420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e420  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e421  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e422  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e423  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e425  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048e427  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048e429  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048e42b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e42f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e431  7c05                   -jl 0x48e438
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e438;
    }
    // 0048e433  83f801                 +cmp eax, 1
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
    // 0048e436  7c0b                   -jl 0x48e443
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e443;
    }
L_0x0048e438:
    // 0048e438  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0048e43d:
    // 0048e43d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e43e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e43f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e440  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048e443:
    // 0048e443  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0048e446  05c0a75200             -add eax, 0x52a7c0
    (cpu.eax) += x86::reg32(x86::sreg32(5416896 /*0x52a7c0*/));
    // 0048e44b  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0048e44d  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0048e450  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048e452  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048e455  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e457  e84813ffff             -call 0x47f7a4
    cpu.esp -= 4;
    sub_47f7a4(app, cpu);
    if (cpu.terminate) return;
    // 0048e45c  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048e463  7419                   -je 0x48e47e
    if (cpu.flags.zf)
    {
        goto L_0x0048e47e;
    }
    // 0048e465  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e467  7cd4                   -jl 0x48e43d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e43d;
    }
L_0x0048e469:
    // 0048e469  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048e46b  7502                   -jne 0x48e46f
    if (!cpu.flags.zf)
    {
        goto L_0x0048e46f;
    }
    // 0048e46d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0048e46f:
    // 0048e46f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048e471  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e473  e810000000             -call 0x48e488
    cpu.esp -= 4;
    sub_48e488(app, cpu);
    if (cpu.terminate) return;
    // 0048e478  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e479  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e47a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e47b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048e47e:
    // 0048e47e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e480  7de7                   -jge 0x48e469
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e469;
    }
    // 0048e482  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e483  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e484  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e485  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_48e488(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e488  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e489  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048e48b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e48d  7c0e                   -jl 0x48e49d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e49d;
    }
    // 0048e48f  83f801                 +cmp eax, 1
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
    // 0048e492  7d09                   -jge 0x48e49d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e49d;
    }
    // 0048e494  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048e496  7c05                   -jl 0x48e49d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e49d;
    }
    // 0048e498  83fa7f                 +cmp edx, 0x7f
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
    // 0048e49b  7e07                   -jle 0x48e4a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e4a4;
    }
L_0x0048e49d:
    // 0048e49d  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0048e4a2:
    // 0048e4a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e4a4:
    // 0048e4a4  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0048e4a7  8990c4a75200           -mov dword ptr [eax + 0x52a7c4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416900) /* 0x52a7c4 */) = cpu.edx;
    // 0048e4ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048e4af  e8fc12ffff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 0048e4b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e4b6  7cea                   -jl 0x48e4a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e4a2;
    }
    // 0048e4b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e4b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e4ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e4bb  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0048e4bd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048e4bf:
    // 0048e4bf  6bc160                 -imul eax, ecx, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 0048e4c2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048e4c4  8b9e06a85200           -mov ebx, dword ptr [esi + 0x52a806]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5416966) /* 0x52a806 */);
    // 0048e4ca  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048e4cd  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0048e4d0  8b80d0a75200           -mov eax, dword ptr [eax + 0x52a7d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416912) /* 0x52a7d0 */);
    // 0048e4d6  41                     -inc ecx
    (cpu.ecx)++;
    // 0048e4d7  e894230100             -call 0x4a0870
    cpu.esp -= 4;
    sub_4a0870(app, cpu);
    if (cpu.terminate) return;
    // 0048e4dc  83f910                 +cmp ecx, 0x10
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
    // 0048e4df  7cde                   -jl 0x48e4bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e4bf;
    }
    // 0048e4e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e4e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48e4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e4f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e4f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e4f3  66833d94c54c0000       +cmp word ptr [0x4cc594], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5031316) /* 0x4cc594 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048e4fb  0f8cc3000000           -jl 0x48e5c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e5c4;
    }
    // 0048e501  0fbf0504c54c00         -movsx eax, word ptr [0x4cc504]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */)));
    // 0048e508  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048e50b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e50d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e510  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e512  8b15a0c54c00           -mov edx, dword ptr [0x4cc5a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */);
    // 0048e518  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e51a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e51c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0048e51e  a19cc54c00             -mov eax, dword ptr [0x4cc59c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5031324) /* 0x4cc59c */);
    // 0048e523  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0048e526  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048e52b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048e52e  0fbf1594c54c00         -movsx edx, word ptr [0x4cc594]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031316) /* 0x4cc594 */)));
    // 0048e535  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e537  8b150cc54c00           -mov edx, dword ptr [0x4cc50c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031180) /* 0x4cc50c */);
    // 0048e53d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0048e540  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0048e542  66a304c54c00           -mov word ptr [0x4cc504], ax
    app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */) = cpu.ax;
    // 0048e548  a198c54c00             -mov eax, dword ptr [0x4cc598]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5031320) /* 0x4cc598 */);
    // 0048e54d  a394c54c00             -mov dword ptr [0x4cc594], eax
    app->getMemory<x86::reg32>(x86::reg32(5031316) /* 0x4cc594 */) = cpu.eax;
    // 0048e552  66c70598c54c00ffff     -mov word ptr [0x4cc598], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(5031320) /* 0x4cc598 */) = 65535 /*0xffff*/;
    // 0048e55b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e55d  66890d9ac54c00         -mov word ptr [0x4cc59a], cx
    app->getMemory<x86::reg16>(x86::reg32(5031322) /* 0x4cc59a */) = cpu.cx;
L_0x0048e564:
    // 0048e564  ff0508c54c00           -inc dword ptr [0x4cc508]
    (app->getMemory<x86::reg32>(x86::reg32(5031176) /* 0x4cc508 */))++;
    // 0048e56a  0fbf0504c54c00         -movsx eax, word ptr [0x4cc504]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */)));
    // 0048e571  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048e574  8b1510c54c00           -mov edx, dword ptr [0x4cc510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031184) /* 0x4cc510 */);
    // 0048e57a  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048e57f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e581  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e583  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048e585  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048e587  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048e58e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048e590  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e592  b814c54c00             -mov eax, 0x4cc514
    cpu.eax = 5031188 /*0x4cc514*/;
    // 0048e597  e830d7ffff             -call 0x48bccc
    cpu.esp -= 4;
    sub_48bccc(app, cpu);
    if (cpu.terminate) return;
    // 0048e59c  0fbf0504c54c00         -movsx eax, word ptr [0x4cc504]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */)));
    // 0048e5a3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048e5a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e5a8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e5ab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e5ad  8b15a0c54c00           -mov edx, dword ptr [0x4cc5a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */);
    // 0048e5b3  807c020100             +cmp byte ptr [edx + eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048e5b8  0f869a000000           -jbe 0x48e658
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048e658;
    }
L_0x0048e5be:
    // 0048e5be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e5c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e5c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e5c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e5c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e5c4:
    // 0048e5c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e5c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048e5c8:
    // 0048e5c8  0fbf0d04c54c00         -movsx ecx, word ptr [0x4cc504]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */)));
    // 0048e5cf  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0048e5d2  8b1da0c54c00           -mov ebx, dword ptr [0x4cc5a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */);
    // 0048e5d8  8a4c1901               -mov cl, byte ptr [ecx + ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.ebx * 1);
    // 0048e5dc  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048e5e2  39ca                   +cmp edx, ecx
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
    // 0048e5e4  0f8d7affffff           -jge 0x48e564
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e564;
    }
    // 0048e5ea  0fbf0d04c54c00         -movsx ecx, word ptr [0x4cc504]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */)));
    // 0048e5f1  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0048e5f4  8b1da0c54c00           -mov ebx, dword ptr [0x4cc5a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */);
    // 0048e5fa  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e5fc  8a1d06c54c00           -mov bl, byte ptr [0x4cc506]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5031174) /* 0x4cc506 */);
    // 0048e602  3a5c0104               +cmp bl, byte ptr [ecx + eax + 4]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048e606  7d06                   -jge 0x48e60e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e60e;
    }
L_0x0048e608:
    // 0048e608  83c003                 +add eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e60b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048e60c  ebba                   -jmp 0x48e5c8
    goto L_0x0048e5c8;
L_0x0048e60e:
    // 0048e60e  0fbf1d04c54c00         -movsx ebx, word ptr [0x4cc504]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */)));
    // 0048e615  6bdb1c                 -imul ebx, ebx, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0048e618  8b0da0c54c00           -mov ecx, dword ptr [0x4cc5a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */);
    // 0048e61e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e620  8a1d06c54c00           -mov bl, byte ptr [0x4cc506]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5031174) /* 0x4cc506 */);
    // 0048e626  3a5c0105               +cmp bl, byte ptr [ecx + eax + 5]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */ + cpu.eax * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048e62a  7fdc                   -jg 0x48e608
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048e608;
    }
    // 0048e62c  0fbf1504c54c00         -movsx edx, word ptr [0x4cc504]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */)));
    // 0048e633  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048e636  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048e638  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048e63b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e63d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048e63f  8b15a0c54c00           -mov edx, dword ptr [0x4cc5a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */);
    // 0048e645  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e647  8a440206               -mov al, byte ptr [edx + eax + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */ + cpu.eax * 1);
    // 0048e64b  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0048e64d  66a304c54c00           -mov word ptr [0x4cc504], ax
    app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */) = cpu.ax;
    // 0048e653  e90cffffff             -jmp 0x48e564
    goto L_0x0048e564;
L_0x0048e658:
    // 0048e658  66833d94c54c0000       +cmp word ptr [0x4cc594], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5031316) /* 0x4cc594 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048e660  0f8d58ffffff           -jge 0x48e5be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e5be;
    }
    // 0048e666  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e668  890dbccd4c00           -mov dword ptr [0x4ccdbc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033404) /* 0x4ccdbc */) = cpu.ecx;
    // 0048e66e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e670  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e671  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e672  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e673  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e674  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e675  e8f6dcffff             -call 0x48c370
    cpu.esp -= 4;
    sub_48c370(app, cpu);
    if (cpu.terminate) return;
    // 0048e67a  3b0508c54c00           +cmp eax, dword ptr [0x4cc508]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5031176) /* 0x4cc508 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e680  7d02                   -jge 0x48e684
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e684;
    }
L_0x0048e682:
    // 0048e682  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e683  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e684:
    // 0048e684  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e686  668b1502c54c00         -mov dx, word ptr [0x4cc502]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5031170) /* 0x4cc502 */);
    // 0048e68d  e876d8ffff             -call 0x48bf08
    cpu.esp -= 4;
    sub_48bf08(app, cpu);
    if (cpu.terminate) return;
    // 0048e692  39d0                   +cmp eax, edx
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
    // 0048e694  7dec                   -jge 0x48e682
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e682;
    }
    // 0048e696  e855feffff             -call 0x48e4f0
    cpu.esp -= 4;
    sub_48e4f0(app, cpu);
    if (cpu.terminate) return;
    // 0048e69b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e69c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e6a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e6a2  7506                   -jne 0x48e6aa
    if (!cpu.flags.zf)
    {
        goto L_0x0048e6aa;
    }
    // 0048e6a4  66a100c54c00           -mov ax, word ptr [0x4cc500]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5031168) /* 0x4cc500 */);
L_0x0048e6aa:
    // 0048e6aa  66a302c54c00           -mov word ptr [0x4cc502], ax
    app->getMemory<x86::reg16>(x86::reg32(5031170) /* 0x4cc502 */) = cpu.ax;
    // 0048e6b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e6b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e6b4  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048e6bb  7422                   -je 0x48e6df
    if (cpu.flags.zf)
    {
        goto L_0x0048e6df;
    }
    // 0048e6bd  833d9cc54c0000         +cmp dword ptr [0x4cc59c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5031324) /* 0x4cc59c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e6c4  751f                   -jne 0x48e6e5
    if (!cpu.flags.zf)
    {
        goto L_0x0048e6e5;
    }
    // 0048e6c6  a39cc54c00             -mov dword ptr [0x4cc59c], eax
    app->getMemory<x86::reg32>(x86::reg32(5031324) /* 0x4cc59c */) = cpu.eax;
    // 0048e6cb  813850464478           +cmp dword ptr [eax], 0x78444650
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2017740368 /*0x78444650*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e6d1  7518                   -jne 0x48e6eb
    if (!cpu.flags.zf)
    {
        goto L_0x0048e6eb;
    }
    // 0048e6d3  80780400               +cmp byte ptr [eax + 4], 0
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
    // 0048e6d7  7418                   -je 0x48e6f1
    if (cpu.flags.zf)
    {
        goto L_0x0048e6f1;
    }
    // 0048e6d9  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0048e6de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e6df:
    // 0048e6df  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048e6e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e6e5:
    // 0048e6e5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048e6ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e6eb:
    // 0048e6eb  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048e6f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e6f1:
    // 0048e6f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e6f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e6f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e6f4  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048e6f7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e6f9  8915a0c54c00           -mov dword ptr [0x4cc5a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */) = cpu.edx;
    // 0048e6ff  8a4806                 -mov cl, byte ptr [eax + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0048e702  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0048e705  8d14cd00000000         -lea edx, [ecx*8]
    cpu.edx = x86::reg32(cpu.ecx * 8);
    // 0048e70c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e70e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048e710  8b15a0c54c00           -mov edx, dword ptr [0x4cc5a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031328) /* 0x4cc5a0 */);
    // 0048e716  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e718  89150cc54c00           -mov dword ptr [0x4cc50c], edx
    app->getMemory<x86::reg32>(x86::reg32(5031180) /* 0x4cc50c */) = cpu.edx;
    // 0048e71e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e720  8a500b                 -mov dl, byte ptr [eax + 0xb]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 0048e723  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0048e726  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048e72b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048e72e  8b150cc54c00           -mov edx, dword ptr [0x4cc50c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031180) /* 0x4cc50c */);
    // 0048e734  bbcce84800             -mov ebx, 0x48e8cc
    cpu.ebx = 4778188 /*0x48e8cc*/;
    // 0048e739  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e73b  891ddccd4c00           -mov dword ptr [0x4ccddc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5033436) /* 0x4ccddc */) = cpu.ebx;
    // 0048e741  891510c54c00           -mov dword ptr [0x4cc510], edx
    app->getMemory<x86::reg32>(x86::reg32(5031184) /* 0x4cc510 */) = cpu.edx;
    // 0048e747  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e749  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e74a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e74b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e74c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e750  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e751  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048e754  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048e756  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048e75d  0f84bc000000           -je 0x48e81f
    if (cpu.flags.zf)
    {
        goto L_0x0048e81f;
    }
    // 0048e763  a3a4c54c00             -mov dword ptr [0x4cc5a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5031332) /* 0x4cc5a4 */) = cpu.eax;
    // 0048e768  66891d00c54c00         -mov word ptr [0x4cc500], bx
    app->getMemory<x86::reg16>(x86::reg32(5031168) /* 0x4cc500 */) = cpu.bx;
    // 0048e76f  66891d02c54c00         -mov word ptr [0x4cc502], bx
    app->getMemory<x86::reg16>(x86::reg32(5031170) /* 0x4cc502 */) = cpu.bx;
    // 0048e776  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048e77b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048e77d:
    // 0048e77d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048e780  66899090c54c00         -mov word ptr [eax + 0x4cc590], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5031312) /* 0x4cc590 */) = cpu.dx;
    // 0048e787  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e789  66899892c54c00         -mov word ptr [eax + 0x4cc592], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5031314) /* 0x4cc592 */) = cpu.bx;
    // 0048e790  83f808                 +cmp eax, 8
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
    // 0048e793  75e8                   -jne 0x48e77d
    if (!cpu.flags.zf)
    {
        goto L_0x0048e77d;
    }
    // 0048e795  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e796  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e797  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0048e799  883506c54c00           -mov byte ptr [0x4cc506], dh
    app->getMemory<x86::reg8>(x86::reg32(5031174) /* 0x4cc506 */) = cpu.dh;
    // 0048e79f  a19cc54c00             -mov eax, dword ptr [0x4cc59c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5031324) /* 0x4cc59c */);
    // 0048e7a4  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0048e7a7  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0048e7a9  66a304c54c00           -mov word ptr [0x4cc504], ax
    app->getMemory<x86::reg16>(x86::reg32(5031172) /* 0x4cc504 */) = cpu.ax;
    // 0048e7af  e8bcdbffff             -call 0x48c370
    cpu.esp -= 4;
    sub_48c370(app, cpu);
    if (cpu.terminate) return;
    // 0048e7b4  a308c54c00             -mov dword ptr [0x4cc508], eax
    app->getMemory<x86::reg32>(x86::reg32(5031176) /* 0x4cc508 */) = cpu.eax;
    // 0048e7b9  bf14c54c00             -mov edi, 0x4cc514
    cpu.edi = 5031188 /*0x4cc514*/;
    // 0048e7be  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048e7c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048e7c1:
    // 0048e7c1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048e7c3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048e7c5  3c00                   +cmp al, 0
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
    // 0048e7c7  7410                   -je 0x48e7d9
    if (cpu.flags.zf)
    {
        goto L_0x0048e7d9;
    }
    // 0048e7c9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048e7cc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e7cf  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048e7d2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e7d5  3c00                   +cmp al, 0
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
    // 0048e7d7  75e8                   -jne 0x48e7c1
    if (!cpu.flags.zf)
    {
        goto L_0x0048e7c1;
    }
L_0x0048e7d9:
    // 0048e7d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e7da  ff0508c54c00           -inc dword ptr [0x4cc508]
    (app->getMemory<x86::reg32>(x86::reg32(5031176) /* 0x4cc508 */))++;
    // 0048e7e0  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e7e4  e877c6feff             -call 0x47ae60
    cpu.esp -= 4;
    sub_47ae60(app, cpu);
    if (cpu.terminate) return;
    // 0048e7e9  a1a4c54c00             -mov eax, dword ptr [0x4cc5a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5031332) /* 0x4cc5a4 */);
    // 0048e7ee  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e7f2  e8b9d3ffff             -call 0x48bbb0
    cpu.esp -= 4;
    sub_48bbb0(app, cpu);
    if (cpu.terminate) return;
    // 0048e7f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e7f9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e7fb  bba0e64800             -mov ebx, 0x48e6a0
    cpu.ebx = 4777632 /*0x48e6a0*/;
    // 0048e800  e8c7d4ffff             -call 0x48bccc
    cpu.esp -= 4;
    sub_48bccc(app, cpu);
    if (cpu.terminate) return;
    // 0048e805  b974e64800             -mov ecx, 0x48e674
    cpu.ecx = 4777588 /*0x48e674*/;
    // 0048e80a  891d74c44c00           -mov dword ptr [0x4cc474], ebx
    app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */) = cpu.ebx;
    // 0048e810  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e812  890dbccd4c00           -mov dword ptr [0x4ccdbc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033404) /* 0x4ccdbc */) = cpu.ecx;
    // 0048e818  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e819  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e81a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048e81d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e81e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e81f:
    // 0048e81f  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048e824  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048e827  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e828  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e82c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e82c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e82e  7c05                   -jl 0x48e835
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e835;
    }
    // 0048e830  83f87f                 +cmp eax, 0x7f
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
    // 0048e833  7e06                   -jle 0x48e83b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e83b;
    }
L_0x0048e835:
    // 0048e835  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048e83a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e83b:
    // 0048e83b  a206c54c00             -mov byte ptr [0x4cc506], al
    app->getMemory<x86::reg8>(x86::reg32(5031174) /* 0x4cc506 */) = cpu.al;
    // 0048e840  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48e844(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e844  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e845  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048e84c  7437                   -je 0x48e885
    if (cpu.flags.zf)
    {
        goto L_0x0048e885;
    }
    // 0048e84e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e850  7c3a                   -jl 0x48e88c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e88c;
    }
    // 0048e852  8b0d9cc54c00           -mov ecx, dword ptr [0x4cc59c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5031324) /* 0x4cc59c */);
    // 0048e858  8a4907                 -mov cl, byte ptr [ecx + 7]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0048e85b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048e861  39c8                   +cmp eax, ecx
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
    // 0048e863  7d27                   -jge 0x48e88c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e88c;
    }
    // 0048e865  83fa01                 +cmp edx, 1
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
    // 0048e868  7429                   -je 0x48e893
    if (cpu.flags.zf)
    {
        goto L_0x0048e893;
    }
    // 0048e86a  66833d96c54c0001       +cmp word ptr [0x4cc596], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5031318) /* 0x4cc596 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048e872  7544                   -jne 0x48e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0048e8b8;
    }
    // 0048e874  66a398c54c00           -mov word ptr [0x4cc598], ax
    app->getMemory<x86::reg16>(x86::reg32(5031320) /* 0x4cc598 */) = cpu.ax;
    // 0048e87a  6689159ac54c00         -mov word ptr [0x4cc59a], dx
    app->getMemory<x86::reg16>(x86::reg32(5031322) /* 0x4cc59a */) = cpu.dx;
    // 0048e881  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e883  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e884  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e885:
    // 0048e885  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048e88a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e88b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e88c:
    // 0048e88c  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048e891  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e892  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e893:
    // 0048e893  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e894  66a394c54c00           -mov word ptr [0x4cc594], ax
    app->getMemory<x86::reg16>(x86::reg32(5031316) /* 0x4cc594 */) = cpu.ax;
    // 0048e89a  66891596c54c00         -mov word ptr [0x4cc596], dx
    app->getMemory<x86::reg16>(x86::reg32(5031318) /* 0x4cc596 */) = cpu.dx;
    // 0048e8a1  66c70598c54c00ffff     -mov word ptr [0x4cc598], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(5031320) /* 0x4cc598 */) = 65535 /*0xffff*/;
    // 0048e8aa  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048e8ac  6689359ac54c00         -mov word ptr [0x4cc59a], si
    app->getMemory<x86::reg16>(x86::reg32(5031322) /* 0x4cc59a */) = cpu.si;
    // 0048e8b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e8b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e8b8:
    // 0048e8b8  66a394c54c00           -mov word ptr [0x4cc594], ax
    app->getMemory<x86::reg16>(x86::reg32(5031316) /* 0x4cc594 */) = cpu.ax;
    // 0048e8be  66891596c54c00         -mov word ptr [0x4cc596], dx
    app->getMemory<x86::reg16>(x86::reg32(5031318) /* 0x4cc596 */) = cpu.dx;
    // 0048e8c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e8c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e8cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e8cc  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048e8d3  7506                   -jne 0x48e8db
    if (!cpu.flags.zf)
    {
        goto L_0x0048e8db;
    }
    // 0048e8d5  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048e8da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e8db:
    // 0048e8db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e8dc  e88fd3ffff             -call 0x48bc70
    cpu.esp -= 4;
    sub_48bc70(app, cpu);
    if (cpu.terminate) return;
    // 0048e8e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e8e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e8e5  8915bccd4c00           -mov dword ptr [0x4ccdbc], edx
    app->getMemory<x86::reg32>(x86::reg32(5033404) /* 0x4ccdbc */) = cpu.edx;
    // 0048e8eb  89159cc54c00           -mov dword ptr [0x4cc59c], edx
    app->getMemory<x86::reg32>(x86::reg32(5031324) /* 0x4cc59c */) = cpu.edx;
    // 0048e8f1  891574c44c00           -mov dword ptr [0x4cc474], edx
    app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */) = cpu.edx;
    // 0048e8f7  8915dccd4c00           -mov dword ptr [0x4ccddc], edx
    app->getMemory<x86::reg32>(x86::reg32(5033436) /* 0x4ccddc */) = cpu.edx;
    // 0048e8fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48e900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e902  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e903  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e904  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048e907  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048e90a  e8ada80000             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0048e90f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e911  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e913  7c5a                   -jl 0x48e96f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e96f;
    }
    // 0048e915  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048e91c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e91e  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0048e921  81c2d0a75200           -add edx, 0x52a7d0
    (cpu.edx) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 0048e927  0fb6723b               -movzx esi, byte ptr [edx + 0x3b]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 0048e92b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048e92d  0f8466000000           -je 0x48e999
    if (cpu.flags.zf)
    {
        goto L_0x0048e999;
    }
    // 0048e933  b9d0a75200             -mov ecx, 0x52a7d0
    cpu.ecx = 5416912 /*0x52a7d0*/;
    // 0048e938  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e93b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048e93d:
    // 0048e93d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e93f  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0048e942  39f2                   +cmp edx, esi
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
    // 0048e944  7514                   -jne 0x48e95a
    if (!cpu.flags.zf)
    {
        goto L_0x0048e95a;
    }
    // 0048e946  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 0048e94a  750e                   -jne 0x48e95a
    if (!cpu.flags.zf)
    {
        goto L_0x0048e95a;
    }
    // 0048e94c  833900                 +cmp dword ptr [ecx], 0
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
    // 0048e94f  7c09                   -jl 0x48e95a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e95a;
    }
    // 0048e951  31f2                   -xor edx, esi
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048e953  8a5133                 -mov dl, byte ptr [ecx + 0x33]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */);
    // 0048e956  39ea                   +cmp edx, ebp
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
    // 0048e958  751c                   -jne 0x48e976
    if (!cpu.flags.zf)
    {
        goto L_0x0048e976;
    }
L_0x0048e95a:
    // 0048e95a  43                     -inc ebx
    (cpu.ebx)++;
    // 0048e95b  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048e95e  83fb10                 +cmp ebx, 0x10
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
    // 0048e961  7cda                   -jl 0x48e93d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e93d;
    }
L_0x0048e963:
    // 0048e963  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048e965:
    // 0048e965  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e967  83c404                 +add esp, 4
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
    // 0048e96a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e96b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e96c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e96d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e96e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e96f:
    // 0048e96f  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 0048e974  ebef                   -jmp 0x48e965
    goto L_0x0048e965;
L_0x0048e976:
    // 0048e976  6683794200             +cmp word ptr [ecx + 0x42], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048e97b  74dd                   -je 0x48e95a
    if (cpu.flags.zf)
    {
        goto L_0x0048e95a;
    }
    // 0048e97d  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048e980  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 0048e983  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048e985  e836200100             -call 0x4a09c0
    cpu.esp -= 4;
    sub_4a09c0(app, cpu);
    if (cpu.terminate) return;
    // 0048e98a  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048e98d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048e98f  c1fa10                 +sar edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0048e992  e87919ffff             -call 0x480310
    cpu.esp -= 4;
    sub_480310(app, cpu);
    if (cpu.terminate) return;
    // 0048e997  ebc1                   -jmp 0x48e95a
    goto L_0x0048e95a;
L_0x0048e999:
    // 0048e999  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e99b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048e99e  8a4233                 -mov al, byte ptr [edx + 0x33]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */);
    // 0048e9a1  39d8                   +cmp eax, ebx
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
    // 0048e9a3  74be                   -je 0x48e963
    if (cpu.flags.zf)
    {
        goto L_0x0048e963;
    }
    // 0048e9a5  66837a4200             +cmp word ptr [edx + 0x42], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(66) /* 0x42 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048e9aa  74b7                   -je 0x48e963
    if (cpu.flags.zf)
    {
        goto L_0x0048e963;
    }
    // 0048e9ac  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048e9af  884233                 -mov byte ptr [edx + 0x33], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 0048e9b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e9b4  e807200100             -call 0x4a09c0
    cpu.esp -= 4;
    sub_4a09c0(app, cpu);
    if (cpu.terminate) return;
    // 0048e9b9  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048e9bc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e9be  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048e9c1  e84a19ffff             -call 0x480310
    cpu.esp -= 4;
    sub_480310(app, cpu);
    if (cpu.terminate) return;
    // 0048e9c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e9c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e9ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048e9cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e9d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e9d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e9d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e9d7  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048e9de  7410                   -je 0x48e9f0
    if (cpu.flags.zf)
    {
        goto L_0x0048e9f0;
    }
    // 0048e9e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048e9e2  7c05                   -jl 0x48e9e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e9e9;
    }
    // 0048e9e4  83fa7f                 +cmp edx, 0x7f
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
    // 0048e9e7  7e0e                   -jle 0x48e9f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e9f7;
    }
L_0x0048e9e9:
    // 0048e9e9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048e9ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e9f0:
    // 0048e9f0  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048e9f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e9f7:
    // 0048e9f7  e8b4a30000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048e9fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e9fe  e8fdfeffff             -call 0x48e900
    cpu.esp -= 4;
    sub_48e900(app, cpu);
    if (cpu.terminate) return;
    // 0048ea03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ea05  e8baa30000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048ea0a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ea0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ea0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_48ea10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ea10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ea11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ea12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ea13  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ea16  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ea18  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048ea1a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048ea1c  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0048ea22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ea24  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048ea26  750c                   -jne 0x48ea34
    if (!cpu.flags.zf)
    {
        goto L_0x0048ea34;
    }
    // 0048ea28  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048ea2d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ea30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ea31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ea32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ea33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ea34:
    // 0048ea34  e877a30000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048ea39  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048ea3f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ea41  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048ea47  e870a70000             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0048ea4c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ea4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ea50  7c60                   -jl 0x48eab2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048eab2;
    }
    // 0048ea52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ea53  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048ea56  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ea58  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048ea5b  05d0a75200             -add eax, 0x52a7d0
    (cpu.eax) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 0048ea60  8a403b                 -mov al, byte ptr [eax + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 0048ea63  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0048ea68  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048ea6c  7455                   -je 0x48eac3
    if (cpu.flags.zf)
    {
        goto L_0x0048eac3;
    }
    // 0048ea6e  bed0a75200             -mov esi, 0x52a7d0
    cpu.esi = 5416912 /*0x52a7d0*/;
    // 0048ea73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048ea75:
    // 0048ea75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ea77  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ea7b  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 0048ea7e  39d8                   +cmp eax, ebx
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
    // 0048ea80  7518                   -jne 0x48ea9a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ea9a;
    }
    // 0048ea82  807e0c01               +cmp byte ptr [esi + 0xc], 1
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
    // 0048ea86  7512                   -jne 0x48ea9a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ea9a;
    }
    // 0048ea88  833e00                 +cmp dword ptr [esi], 0
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
    // 0048ea8b  7c0d                   -jl 0x48ea9a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ea9a;
    }
    // 0048ea8d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048ea8f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ea91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ea93  e8ec15ffff             -call 0x480084
    cpu.esp -= 4;
    sub_480084(app, cpu);
    if (cpu.terminate) return;
    // 0048ea98  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0048ea9a:
    // 0048ea9a  41                     -inc ecx
    (cpu.ecx)++;
    // 0048ea9b  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048ea9e  83f910                 +cmp ecx, 0x10
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
    // 0048eaa1  7cd2                   -jl 0x48ea75
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ea75;
    }
    // 0048eaa3  e81ca30000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048eaa8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048eaaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eaab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048eaae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eaaf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eab0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eab1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eab2:
    // 0048eab2  e80da30000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048eab7  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048eabc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048eabf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eac0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eac1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eac2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eac3:
    // 0048eac3  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048eac5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048eac7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048eac9  e8b615ffff             -call 0x480084
    cpu.esp -= 4;
    sub_480084(app, cpu);
    if (cpu.terminate) return;
    // 0048eace  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ead0  e8efa20000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048ead5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ead7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ead8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048eadb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eadc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eadd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eade  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48eae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eae0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eae1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048eae2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048eae5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048eae7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048eaeb  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0048eaf2  7416                   -je 0x48eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0048eb0a;
    }
    // 0048eaf4  83fa7f                 +cmp edx, 0x7f
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
    // 0048eaf7  7f04                   -jg 0x48eafd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048eafd;
    }
    // 0048eaf9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048eafb  7d14                   -jge 0x48eb11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eb11;
    }
L_0x0048eafd:
    // 0048eafd  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x0048eb02:
    // 0048eb02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048eb04  83c408                 +add esp, 8
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
    // 0048eb07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eb0a:
    // 0048eb0a  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 0048eb0f  ebf1                   -jmp 0x48eb02
    goto L_0x0048eb02;
L_0x0048eb11:
    // 0048eb11  e89aa20000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048eb16  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048eb18  e89fa60000             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0048eb1d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048eb1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048eb21  0f8ca2000000           -jl 0x48ebc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ebc9;
    }
    // 0048eb27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048eb28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048eb29  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb2a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048eb2d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb2f  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048eb32  05d0a75200             -add eax, 0x52a7d0
    (cpu.eax) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 0048eb37  0fb6783b               -movzx edi, byte ptr [eax + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */));
    // 0048eb3b  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048eb3e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048eb40  0f849d000000           -je 0x48ebe3
    if (cpu.flags.zf)
    {
        goto L_0x0048ebe3;
    }
    // 0048eb46  b9d0a75200             -mov ecx, 0x52a7d0
    cpu.ecx = 5416912 /*0x52a7d0*/;
    // 0048eb4b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048eb4f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048eb51  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0048eb53:
    // 0048eb53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048eb55  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0048eb58  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048eb5a  39f8                   +cmp eax, edi
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
    // 0048eb5c  7550                   -jne 0x48ebae
    if (!cpu.flags.zf)
    {
        goto L_0x0048ebae;
    }
    // 0048eb5e  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 0048eb62  754a                   -jne 0x48ebae
    if (!cpu.flags.zf)
    {
        goto L_0x0048ebae;
    }
    // 0048eb64  3b29                   +cmp ebp, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eb66  7f46                   -jg 0x48ebae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048ebae;
    }
    // 0048eb68  8a6137                 -mov ah, byte ptr [ecx + 0x37]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */);
    // 0048eb6b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048eb6f  80fc01                 +cmp ah, 1
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
    // 0048eb72  7410                   -je 0x48eb84
    if (cpu.flags.zf)
    {
        goto L_0x0048eb84;
    }
    // 0048eb74  8b5134                 -mov edx, dword ptr [ecx + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0048eb77  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048eb7b  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048eb7e  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048eb81  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x0048eb84:
    // 0048eb84  8b462f                 -mov eax, dword ptr [esi + 0x2f]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(47) /* 0x2f */);
    // 0048eb87  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0048eb8a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048eb8c  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048eb8f  83fa7f                 +cmp edx, 0x7f
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
    // 0048eb92  7e47                   -jle 0x48ebdb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ebdb;
    }
    // 0048eb94  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x0048eb99:
    // 0048eb99  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0048eb9c  39c5                   +cmp ebp, eax
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
    // 0048eb9e  7404                   -je 0x48eba4
    if (cpu.flags.zf)
    {
        goto L_0x0048eba4;
    }
    // 0048eba0  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
L_0x0048eba4:
    // 0048eba4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048eba6  88560f                 -mov byte ptr [esi + 0xf], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 0048eba9  e82614ffff             -call 0x47ffd4
    cpu.esp -= 4;
    sub_47ffd4(app, cpu);
    if (cpu.terminate) return;
L_0x0048ebae:
    // 0048ebae  43                     -inc ebx
    (cpu.ebx)++;
    // 0048ebaf  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048ebb2  83fb10                 +cmp ebx, 0x10
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
    // 0048ebb5  7c9c                   -jl 0x48eb53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048eb53;
    }
    // 0048ebb7  e808a20000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048ebbc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ebbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebc1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ebc3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ebc6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ebc9:
    // 0048ebc9  e8f6a10000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048ebce  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 0048ebd3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ebd5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ebd8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ebdb:
    // 0048ebdb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ebdd  7dba                   -jge 0x48eb99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eb99;
    }
    // 0048ebdf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ebe1  ebb6                   -jmp 0x48eb99
    goto L_0x0048eb99;
L_0x0048ebe3:
    // 0048ebe3  80783701               +cmp byte ptr [eax + 0x37], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(55) /* 0x37 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048ebe7  7410                   -je 0x48ebf9
    if (cpu.flags.zf)
    {
        goto L_0x0048ebf9;
    }
    // 0048ebe9  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0048ebec  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0048ebef  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ebf2  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048ebf5  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0048ebf9:
    // 0048ebf9  8b502f                 -mov edx, dword ptr [eax + 0x2f]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 0048ebfc  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048ec00  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048ec03  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048ec05  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048ec08  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048ec0c  83fa7f                 +cmp edx, 0x7f
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
    // 0048ec0f  7e41                   -jle 0x48ec52
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ec52;
    }
    // 0048ec11  c74424107f000000       -mov dword ptr [esp + 0x10], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
L_0x0048ec19:
    // 0048ec19  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048ec1c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048ec1e  740e                   -je 0x48ec2e
    if (cpu.flags.zf)
    {
        goto L_0x0048ec2e;
    }
    // 0048ec20  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048ec24  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0048ec27  0fbe12                 -movsx edx, byte ptr [edx]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 0048ec2a  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0048ec2e:
    // 0048ec2e  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048ec32  88500f                 -mov byte ptr [eax + 0xf], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 0048ec35  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048ec39  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ec3b  e89413ffff             -call 0x47ffd4
    cpu.esp -= 4;
    sub_47ffd4(app, cpu);
    if (cpu.terminate) return;
    // 0048ec40  e87fa10000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048ec45  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ec47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ec4c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ec4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ec52:
    // 0048ec52  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ec54  7dc3                   -jge 0x48ec19
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ec19;
    }
    // 0048ec56  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048ec58  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048ec5c  ebbb                   -jmp 0x48ec19
    goto L_0x0048ec19;
}

/* align: skip 0x00 0x00 */
void Application::sub_48ec60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ec61  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ec66  e811000000             -call 0x48ec7c
    cpu.esp -= 4;
    sub_48ec7c(app, cpu);
    if (cpu.terminate) return;
    // 0048ec6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ec70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ec71  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ec73  e804000000             -call 0x48ec7c
    cpu.esp -= 4;
    sub_48ec7c(app, cpu);
    if (cpu.terminate) return;
    // 0048ec78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ec7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec7e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048ec81  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ec85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ec86  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ec8a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ec8e  e8f5e2feff             -call 0x47cf88
    cpu.esp -= 4;
    sub_47cf88(app, cpu);
    if (cpu.terminate) return;
    // 0048ec93  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ec96  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ec98  750a                   -jne 0x48eca4
    if (!cpu.flags.zf)
    {
        goto L_0x0048eca4;
    }
    // 0048ec9a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ec9e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048eca1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eca2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eca3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eca4:
    // 0048eca4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048eca6  e8c5e5feff             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0048ecab  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ecaf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048ecb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ecb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ecb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48ecc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ecc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ecc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ecc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ecc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ecc4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ecc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ecc8  7f07                   -jg 0x48ecd1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048ecd1;
    }
    // 0048ecca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048eccc:
    // 0048eccc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eccd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ecce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eccf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ecd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ecd1:
    // 0048ecd1  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048ecd4  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048ecd9  b81c0d4c00             -mov eax, 0x4c0d1c
    cpu.eax = 4984092 /*0x4c0d1c*/;
    // 0048ecde  e845b5feff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0048ece3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ece5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ece7  74e3                   -je 0x48eccc
    if (cpu.flags.zf)
    {
        goto L_0x0048eccc;
    }
    // 0048ece9  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ecee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ecf0  b8380d4c00             -mov eax, 0x4c0d38
    cpu.eax = 4984120 /*0x4c0d38*/;
    // 0048ecf5  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ecf8  e80329ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048ecfd  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ed02  b8400d4c00             -mov eax, 0x4c0d40
    cpu.eax = 4984128 /*0x4c0d40*/;
    // 0048ed07  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0048ed0a  8971fc                 -mov dword ptr [ecx - 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0048ed0d  e8ee28ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048ed12  8b15a8c54c00           -mov edx, dword ptr [0x4cc5a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031336) /* 0x4cc5a8 */);
    // 0048ed18  42                     -inc edx
    (cpu.edx)++;
    // 0048ed19  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ed1b  8915a8c54c00           -mov dword ptr [0x4cc5a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5031336) /* 0x4cc5a8 */) = cpu.edx;
    // 0048ed21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ed28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ed28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ed29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ed2a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ed2b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ed2c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ed2d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ed2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ed30  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ed35  bf380d4c00             -mov edi, 0x4c0d38
    cpu.edi = 4984120 /*0x4c0d38*/;
    // 0048ed3a  8d70f8                 -lea esi, [eax - 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0048ed3d  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0048ed40  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048ed42  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 0048ed44  7405                   -je 0x48ed4b
    if (cpu.flags.zf)
    {
        goto L_0x0048ed4b;
    }
    // 0048ed46  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ed48  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0048ed4b:
    // 0048ed4b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048ed4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ed4f  7557                   -jne 0x48eda8
    if (!cpu.flags.zf)
    {
        goto L_0x0048eda8;
    }
    // 0048ed51  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048ed53  7e53                   -jle 0x48eda8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048eda8;
    }
    // 0048ed55  81fb00000002           +cmp ebx, 0x2000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33554432 /*0x2000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ed5b  7d4b                   -jge 0x48eda8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eda8;
    }
    // 0048ed5d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ed62  bf400d4c00             -mov edi, 0x4c0d40
    cpu.edi = 4984128 /*0x4c0d40*/;
    // 0048ed67  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0048ed6a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048ed6c  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 0048ed6e  7405                   -je 0x48ed75
    if (cpu.flags.zf)
    {
        goto L_0x0048ed75;
    }
    // 0048ed70  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ed72  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0048ed75:
    // 0048ed75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ed77  752f                   -jne 0x48eda8
    if (!cpu.flags.zf)
    {
        goto L_0x0048eda8;
    }
    // 0048ed79  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0048ed7e:
    // 0048ed7e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ed83  8d4af8                 -lea ecx, [edx - 8]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0048ed86  b8480d4c00             -mov eax, 0x4c0d48
    cpu.eax = 4984136 /*0x4c0d48*/;
    // 0048ed8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048ed8d  e86e28ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048ed92  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ed94  e8f3b8feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0048ed99  ff0da8c54c00           -dec dword ptr [0x4cc5a8]
    (app->getMemory<x86::reg32>(x86::reg32(5031336) /* 0x4cc5a8 */))--;
    // 0048ed9f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048eda1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eda2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eda3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eda4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eda5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eda6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eda7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eda8:
    // 0048eda8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048edaa  75d2                   -jne 0x48ed7e
    if (!cpu.flags.zf)
    {
        goto L_0x0048ed7e;
    }
    // 0048edac  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048edb1  bf480d4c00             -mov edi, 0x4c0d48
    cpu.edi = 4984136 /*0x4c0d48*/;
    // 0048edb6  8d72f8                 -lea esi, [edx - 8]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0048edb9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048edbb  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 0048edbd  7405                   -je 0x48edc4
    if (cpu.flags.zf)
    {
        goto L_0x0048edc4;
    }
    // 0048edbf  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048edc1  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0048edc4:
    // 0048edc4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048edc6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edcb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048edcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48edd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048edd0  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048edd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48edd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048edd4  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048edd7  7305                   -jae 0x48edde
    if (!cpu.flags.cf)
    {
        goto L_0x0048edde;
    }
    // 0048edd9  0344d014               -add eax, dword ptr [eax + edx*8 + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */ + cpu.edx * 8)));
    // 0048eddd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048edde:
    // 0048edde  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ede0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ede1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ede1  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ede4  7307                   -jae 0x48eded
    if (!cpu.flags.cf)
    {
        goto L_0x0048eded;
    }
    // 0048ede6  8b44d010               -mov eax, dword ptr [eax + edx*8 + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */ + cpu.edx * 8);
    // 0048edea  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048edec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eded:
    // 0048eded  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0048edf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48ee20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048ee20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ee21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ee22  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ee25  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ee27  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ee29  7c1f                   -jl 0x48ee4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ee4a;
    }
L_0x0048ee2b:
    // 0048ee2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ee2d  7c24                   -jl 0x48ee53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ee53;
    }
L_0x0048ee2f:
    // 0048ee2f  39d0                   +cmp eax, edx
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
    // 0048ee31  7527                   -jne 0x48ee5a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ee5a;
    }
    // 0048ee33  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0048ee38  83f907                 +cmp ecx, 7
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
    // 0048ee3b  7707                   -ja 0x48ee44
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048ee44;
    }
    // 0048ee3d  ff248d00ee4800         -jmp dword ptr [ecx*4 + 0x48ee00]
    cpu.ip = app->getMemory<x86::reg32>(4779520 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0048ee44:
L_0x0048ee44:
    // 0048ee44  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ee47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ee48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ee49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ee4a:
    // 0048ee4a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048ee4f  f7da                   +neg edx
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
    // 0048ee51  ebd8                   -jmp 0x48ee2b
    goto L_0x0048ee2b;
L_0x0048ee53:
    // 0048ee53  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0048ee56  f7d8                   +neg eax
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
    // 0048ee58  ebd5                   -jmp 0x48ee2f
    goto L_0x0048ee2f;
L_0x0048ee5a:
    // 0048ee5a  39c2                   +cmp edx, eax
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
    // 0048ee5c  7d09                   -jge 0x48ee67
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ee67;
    }
    // 0048ee5e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ee60  80c901                 -or cl, 1
    cpu.cl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048ee63  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ee65  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0048ee67:
    // 0048ee67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ee68  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ee69  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ee6d  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0048ee72  e831200100             -call 0x4a0ea8
    cpu.esp -= 4;
    sub_4a0ea8(app, cpu);
    if (cpu.terminate) return;
    // 0048ee77  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048ee7b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ee7c  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048ee80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ee81  e89e1c0100             -call 0x4a0b24
    cpu.esp -= 4;
    sub_4a0b24(app, cpu);
    if (cpu.terminate) return;
    // 0048ee86  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ee88  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0048ee8b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048ee92  c1ee08                 -shr esi, 8
    cpu.esi >>= 8 /*0x8*/ % 32;
    // 0048ee95  8b82a4e64c00           -mov eax, dword ptr [edx + 0x4ce6a4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5039780) /* 0x4ce6a4 */);
    // 0048ee9b  8b92a8e64c00           -mov edx, dword ptr [edx + 0x4ce6a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5039784) /* 0x4ce6a8 */);
    // 0048eea1  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048eea7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048eea9  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0048eeac  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0048eeaf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048eeb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eeb2  83f907                 +cmp ecx, 7
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
    // 0048eeb5  778d                   -ja 0x48ee44
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048ee44;
    }
    // 0048eeb7  ff248d00ee4800         -jmp dword ptr [ecx*4 + 0x48ee00]
    cpu.ip = app->getMemory<x86::reg32>(4779520 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0048eebe:
    // 0048eebe  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
  [[fallthrough]];
  case 0x0048eec0:
    // 0048eec0  0500400000             -add eax, 0x4000
    (cpu.eax) += x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0048eec5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048eec8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eec9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eeca  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048eecb:
    // 0048eecb  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048eecd  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048eed2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048eed5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eed6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eed7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048eed8:
    // 0048eed8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048eeda  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048eedd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eede  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eedf  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048eee0:
    // 0048eee0  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0048eee5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048eee8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eeea  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048eeeb:
    // 0048eeeb  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 0048eef0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048eef3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eef4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eef5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048eef6:
    // 0048eef6  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048eef8  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0048eefd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ef00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef02  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48ef10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ef10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ef11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ef12  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ef15  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ef17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ef19  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048ef1b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ef1f  e83c200100             -call 0x4a0f60
    cpu.esp -= 4;
    sub_4a0f60(app, cpu);
    if (cpu.terminate) return;
    // 0048ef24  c70100000100           -mov dword ptr [ecx], 0x10000
    app->getMemory<x86::reg32>(cpu.ecx) = 65536 /*0x10000*/;
    // 0048ef2a  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048ef31  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048ef38  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048ef3f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ef42  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048ef45  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ef49  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048ef50  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048ef53  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ef57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ef59  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048ef5c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0048ef5e  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0048ef61  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ef64  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048ef67  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ef6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ef70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ef70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ef71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ef72  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ef75  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ef77  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ef79  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048ef7b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ef7f  e8dc1f0100             -call 0x4a0f60
    cpu.esp -= 4;
    sub_4a0f60(app, cpu);
    if (cpu.terminate) return;
    // 0048ef84  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ef87  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048ef8e  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048ef90  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ef94  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048ef9b  c7411000000100         -mov dword ptr [ecx + 0x10], 0x10000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 65536 /*0x10000*/;
    // 0048efa2  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048efa9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048efab  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048efae  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0048efb0  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048efb3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048efb7  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048efbe  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048efc1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048efc4  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048efc7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048efca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048efcb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048efcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48efd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048efd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048efd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048efd2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048efd5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048efd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048efd9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048efdb  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048efdf  e87c1f0100             -call 0x4a0f60
    cpu.esp -= 4;
    sub_4a0f60(app, cpu);
    if (cpu.terminate) return;
    // 0048efe4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048efe7  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048efe9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048efed  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048eff4  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048eff7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048effb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048effd  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048f000  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0048f002  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048f005  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f008  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048f00f  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048f016  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048f01d  c7412000000100         -mov dword ptr [ecx + 0x20], 0x10000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 65536 /*0x10000*/;
    // 0048f024  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048f027  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048f02a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f02b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f02c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48f030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f034  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0048f037  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0048f03b  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0048f03f  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048f043  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f045  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048f049  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0048f04d  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0048f050:
    // 0048f050  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f054  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048f058  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048f05c  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x0048f05f:
    // 0048f05f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f061  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048f063  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f065  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f068  c1e810                 +shr eax, 0x10
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
    // 0048f06b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f06d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f06f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048f072  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048f075  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f077  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f07a  c1e810                 +shr eax, 0x10
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
    // 0048f07d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f07f  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048f082  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f084  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048f087  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f08a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f08c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f08f  c1e810                 +shr eax, 0x10
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
    // 0048f092  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f094  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f096  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f099  895c3cfc               -mov dword ptr [esp + edi - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1) = cpu.ebx;
    // 0048f09d  39e9                   +cmp ecx, ebp
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
    // 0048f09f  75be                   -jne 0x48f05f
    if (!cpu.flags.zf)
    {
        goto L_0x0048f05f;
    }
    // 0048f0a1  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f0a5  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048f0a9  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048f0ac  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048f0af  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0048f0b3  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0048f0b7  83fb09                 +cmp ebx, 9
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
    // 0048f0ba  7c94                   -jl 0x48f050
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f050;
    }
    // 0048f0bc  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 0048f0c1  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f0c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f0c7  e83425ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048f0cc  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0048f0cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48f0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f0e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f0e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f0e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f0e3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048f0e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048f0e8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048f0ea  e8798f0000             -call 0x498068
    cpu.esp -= 4;
    sub_498068(app, cpu);
    if (cpu.terminate) return;
    // 0048f0ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f0f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f0f3  752c                   -jne 0x48f121
    if (!cpu.flags.zf)
    {
        goto L_0x0048f121;
    }
    // 0048f0f5  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 0048f0fa  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048f0fc  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f100  e86f9a0000             -call 0x498b74
    cpu.esp -= 4;
    sub_498b74(app, cpu);
    if (cpu.terminate) return;
    // 0048f105  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f106  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f108  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f10c  e877defeff             -call 0x47cf88
    cpu.esp -= 4;
    sub_47cf88(app, cpu);
    if (cpu.terminate) return;
    // 0048f111  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f114  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048f116  7522                   -jne 0x48f13a
    if (!cpu.flags.zf)
    {
        goto L_0x0048f13a;
    }
    // 0048f118  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048f11a:
    // 0048f11a  83c40c                 +add esp, 0xc
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
    // 0048f11d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f11e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f11f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f120  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f121:
    // 0048f121  e8feb9feff             -call 0x47ab24
    cpu.esp -= 4;
    sub_47ab24(app, cpu);
    if (cpu.terminate) return;
    // 0048f126  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f128  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f12a  e8d124ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048f12f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f131  e856b5feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0048f136  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f138  ebe0                   -jmp 0x48f11a
    goto L_0x0048f11a;
L_0x0048f13a:
    // 0048f13a  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 0048f13f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f141  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f144  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f146  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0048f14b  e8249a0000             -call 0x498b74
    cpu.esp -= 4;
    sub_498b74(app, cpu);
    if (cpu.terminate) return;
    // 0048f150  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048f152  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f155  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f159  e81ae1feff             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 0048f15e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f161  a340a44c00             -mov dword ptr [0x4ca440], eax
    app->getMemory<x86::reg32>(x86::reg32(5022784) /* 0x4ca440 */) = cpu.eax;
    // 0048f166  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f16a  e801e1feff             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0048f16f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f171  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048f174  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f175  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f176  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f177  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f178(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f178  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f179  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f17e  e85dffffff             -call 0x48f0e0
    cpu.esp -= 4;
    sub_48f0e0(app, cpu);
    if (cpu.terminate) return;
    // 0048f183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f184  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f188  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f189  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f18b  e850ffffff             -call 0x48f0e0
    cpu.esp -= 4;
    sub_48f0e0(app, cpu);
    if (cpu.terminate) return;
    // 0048f190  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f191  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48f1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f1a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f1a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f1a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f1a3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048f1a5  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0048f1aa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f1ac  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f1af  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f1b1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048f1b3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048f1b5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048f1bc  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048f1be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f1c0  8a6701                 -mov ah, byte ptr [edi + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048f1c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f1c5  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f1c8  7518                   -jne 0x48f1e2
    if (!cpu.flags.zf)
    {
        goto L_0x0048f1e2;
    }
L_0x0048f1ca:
    // 0048f1ca  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f1cc  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048f1ce  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f1d0  7317                   -jae 0x48f1e9
    if (!cpu.flags.cf)
    {
        goto L_0x0048f1e9;
    }
    // 0048f1d2  3c10                   +cmp al, 0x10
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
    // 0048f1d4  7206                   -jb 0x48f1dc
    if (cpu.flags.cf)
    {
        goto L_0x0048f1dc;
    }
    // 0048f1d6  763c                   -jbe 0x48f214
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f214;
    }
    // 0048f1d8  3c30                   +cmp al, 0x30
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
    // 0048f1da  7417                   -je 0x48f1f3
    if (cpu.flags.zf)
    {
        goto L_0x0048f1f3;
    }
L_0x0048f1dc:
    // 0048f1dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f1de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f1e2:
    // 0048f1e2  80fc32                 +cmp ah, 0x32
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f1e5  74e3                   -je 0x48f1ca
    if (cpu.flags.zf)
    {
        goto L_0x0048f1ca;
    }
    // 0048f1e7  ebf3                   -jmp 0x48f1dc
    goto L_0x0048f1dc;
L_0x0048f1e9:
    // 0048f1e9  7608                   -jbe 0x48f1f3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f1f3;
    }
    // 0048f1eb  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f1ed  7314                   -jae 0x48f203
    if (!cpu.flags.cf)
    {
        goto L_0x0048f203;
    }
    // 0048f1ef  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f1f1  75e9                   -jne 0x48f1dc
    if (!cpu.flags.zf)
    {
        goto L_0x0048f1dc;
    }
L_0x0048f1f3:
    // 0048f1f3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f1f8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f1fa  e8c11d0100             -call 0x4a0fc0
    cpu.esp -= 4;
    sub_4a0fc0(app, cpu);
    if (cpu.terminate) return;
    // 0048f1ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f201  ebd9                   -jmp 0x48f1dc
    goto L_0x0048f1dc;
L_0x0048f203:
    // 0048f203  7623                   -jbe 0x48f228
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f228;
    }
    // 0048f205  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f207  75d3                   -jne 0x48f1dc
    if (!cpu.flags.zf)
    {
        goto L_0x0048f1dc;
    }
    // 0048f209  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f20b  e870310100             -call 0x4a2380
    cpu.esp -= 4;
    sub_4a2380(app, cpu);
    if (cpu.terminate) return;
    // 0048f210  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048f212  ebc8                   -jmp 0x48f1dc
    goto L_0x0048f1dc;
L_0x0048f214:
    // 0048f214  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f219  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f21b  e8f4320100             -call 0x4a2514
    cpu.esp -= 4;
    sub_4a2514(app, cpu);
    if (cpu.terminate) return;
    // 0048f220  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f222  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f224  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f225  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f226  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f227  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f228:
    // 0048f228  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f22a  e899340100             -call 0x4a26c8
    cpu.esp -= 4;
    sub_4a26c8(app, cpu);
    if (cpu.terminate) return;
    // 0048f22f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f231  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f233  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f234  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f235  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f236  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48f238(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f238  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f239  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f23e  e85dffffff             -call 0x48f1a0
    cpu.esp -= 4;
    sub_48f1a0(app, cpu);
    if (cpu.terminate) return;
    // 0048f243  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f244  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f248  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f249  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f24b  e850ffffff             -call 0x48f1a0
    cpu.esp -= 4;
    sub_48f1a0(app, cpu);
    if (cpu.terminate) return;
    // 0048f250  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f251  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48f254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f254  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f255  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f256  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f257  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f258  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f25a  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0048f25f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f261  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f264  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f266  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048f268  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048f26a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048f271  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048f273  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f275  8a6201                 -mov ah, byte ptr [edx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0048f278  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f27a  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f27d  7519                   -jne 0x48f298
    if (!cpu.flags.zf)
    {
        goto L_0x0048f298;
    }
L_0x0048f27f:
    // 0048f27f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f281  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048f283  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f285  7318                   -jae 0x48f29f
    if (!cpu.flags.cf)
    {
        goto L_0x0048f29f;
    }
    // 0048f287  3c30                   +cmp al, 0x30
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
    // 0048f289  7324                   -jae 0x48f2af
    if (!cpu.flags.cf)
    {
        goto L_0x0048f2af;
    }
    // 0048f28b  3c10                   +cmp al, 0x10
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
    // 0048f28d  7502                   -jne 0x48f291
    if (!cpu.flags.zf)
    {
        goto L_0x0048f291;
    }
L_0x0048f28f:
    // 0048f28f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x0048f291:
    // 0048f291  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f293  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f294  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f295  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f296  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f297  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f298:
    // 0048f298  80fc32                 +cmp ah, 0x32
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f29b  74e2                   -je 0x48f27f
    if (cpu.flags.zf)
    {
        goto L_0x0048f27f;
    }
    // 0048f29d  ebf2                   -jmp 0x48f291
    goto L_0x0048f291;
L_0x0048f29f:
    // 0048f29f  76ee                   -jbe 0x48f28f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f28f;
    }
    // 0048f2a1  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f2a3  7306                   -jae 0x48f2ab
    if (!cpu.flags.cf)
    {
        goto L_0x0048f2ab;
    }
    // 0048f2a5  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f2a7  74e6                   -je 0x48f28f
    if (cpu.flags.zf)
    {
        goto L_0x0048f28f;
    }
    // 0048f2a9  ebe6                   -jmp 0x48f291
    goto L_0x0048f291;
L_0x0048f2ab:
    // 0048f2ab  76e2                   -jbe 0x48f28f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f28f;
    }
    // 0048f2ad  ebe2                   -jmp 0x48f291
    goto L_0x0048f291;
L_0x0048f2af:
    // 0048f2af  76de                   -jbe 0x48f28f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f28f;
    }
    // 0048f2b1  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f2b3  74da                   -je 0x48f28f
    if (cpu.flags.zf)
    {
        goto L_0x0048f28f;
    }
    // 0048f2b5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f2b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_48f2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048f2d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f2d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f2d2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f2d4  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0048f2d7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048f2da  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048f2df  83f903                 +cmp ecx, 3
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
    // 0048f2e2  7720                   -ja 0x48f304
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048f304;
    }
    // 0048f2e4  ff248dc0f24800         -jmp dword ptr [ecx*4 + 0x48f2c0]
    cpu.ip = app->getMemory<x86::reg32>(4780736 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0048f2eb:
    // 0048f2eb  8b0c8500ab4c00         -mov ecx, dword ptr [eax*4 + 0x4cab00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048f2f2  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048f2f4  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0048f2f9  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f2fb  8b049500ab4c00         -mov eax, dword ptr [edx*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.edx * 4);
    // 0048f302  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0048f304:
    // 0048f304  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f305  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f306  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048f307:
    // 0048f307  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 0048f30c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f30e  8b0c8d00ab4c00         -mov ecx, dword ptr [ecx*4 + 0x4cab00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.ecx * 4);
    // 0048f315  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048f317  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048f31e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f320  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048f322  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0048f324  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 0048f326  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f327  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f328  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048f329:
    // 0048f329  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f32a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f32b  8b0c8500ab4c00         -mov ecx, dword ptr [eax*4 + 0x4cab00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048f332  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048f334  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048f336  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0048f338  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0048f33a  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0048f33f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f341  8b049500ab4c00         -mov eax, dword ptr [edx*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.edx * 4);
    // 0048f348  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048f34a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048f34c  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 0048f34e  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0048f350  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f351  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f352  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f353  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f354  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048f355:
    // 0048f355  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 0048f35a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f35c  8b0c8d00ab4c00         -mov ecx, dword ptr [ecx*4 + 0x4cab00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.ecx * 4);
    // 0048f363  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048f365  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048f367  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048f369  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048f370  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048f372  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f373  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f374  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48f378(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f378  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f379  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f37a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f37b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f37c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f37e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048f380  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048f382  f72f                   -imul dword ptr [edi]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 0048f384  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f386  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048f389  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048f38b  f76f0c                 -imul dword ptr [edi + 0xc]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 0048f38e  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f390  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048f393  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f395  f76f18                 -imul dword ptr [edi + 0x18]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */))));
    // 0048f398  01e8                   +add eax, ebp
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
    // 0048f39a  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048f39c  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048f3a0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048f3a2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048f3a4  f76f04                 -imul dword ptr [edi + 4]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 0048f3a7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f3a9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048f3ac  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048f3ae  f76f10                 -imul dword ptr [edi + 0x10]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))));
    // 0048f3b1  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f3b3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048f3b6  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f3b8  f76f1c                 -imul dword ptr [edi + 0x1c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))));
    // 0048f3bb  01e8                   +add eax, ebp
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
    // 0048f3bd  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048f3bf  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048f3c3  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048f3c6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048f3c8  f76f08                 -imul dword ptr [edi + 8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 0048f3cb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f3cd  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048f3d0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048f3d2  f76f14                 -imul dword ptr [edi + 0x14]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */))));
    // 0048f3d5  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f3d7  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048f3da  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f3dc  f76f20                 -imul dword ptr [edi + 0x20]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */))));
    // 0048f3df  01e8                   +add eax, ebp
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
    // 0048f3e1  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048f3e3  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048f3e7  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048f3ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48f3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f3f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f3f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f3f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f3f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f3f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f3f6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048f3f8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048f3fa  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0048f3fd:
    // 0048f3fd  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f400  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f402  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f404  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f407  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f409  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f40c  8953fc                 -mov dword ptr [ebx - 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048f40f  39f0                   +cmp eax, esi
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
    // 0048f411  75ea                   -jne 0x48f3fd
    if (!cpu.flags.zf)
    {
        goto L_0x0048f3fd;
    }
    // 0048f413  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f415  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f416  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f417  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f418  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f419  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48f41c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f41c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f41d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f41e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f41f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f420  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f422  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048f424  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048f426  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0048f429:
    // 0048f429  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f42c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f42e  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f430  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f433  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f435  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f438  8953fc                 -mov dword ptr [ebx - 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048f43b  39f0                   +cmp eax, esi
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
    // 0048f43d  75ea                   -jne 0x48f429
    if (!cpu.flags.zf)
    {
        goto L_0x0048f429;
    }
    // 0048f43f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f441  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f442  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f443  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f444  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f445  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48f448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f448  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f449  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f44a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f44b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f44c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048f44e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048f450  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f452  8d7824                 -lea edi, [eax + 0x24]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0048f455:
    // 0048f455  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048f457  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f459  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f45c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f45e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f461  c1e810                 +shr eax, 0x10
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
    // 0048f464  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f466  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f469  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048f46c  39f9                   +cmp ecx, edi
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
    // 0048f46e  75e5                   -jne 0x48f455
    if (!cpu.flags.zf)
    {
        goto L_0x0048f455;
    }
    // 0048f470  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f472  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f473  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f474  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f475  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48f478(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f478  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f479  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f47a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f47b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f47c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f47d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f47e  81ecbc000000           -sub esp, 0xbc
    (cpu.esp) -= x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 0048f484  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0048f48b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f48d  899424b4000000         -mov dword ptr [esp + 0xb4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.edx;
L_0x0048f494:
    // 0048f494  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f498  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048f49f  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048f4a6  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048f4ab  e8c0ecffff             -call 0x48e170
    cpu.esp -= 4;
    sub_48e170(app, cpu);
    if (cpu.terminate) return;
    // 0048f4b0  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048f4b7  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f4bb  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048f4bd  e86efbffff             -call 0x48f030
    cpu.esp -= 4;
    sub_48f030(app, cpu);
    if (cpu.terminate) return;
    // 0048f4c2  8d5c246c               -lea ebx, [esp + 0x6c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048f4c6  baacc54c00             -mov edx, 0x4cc5ac
    cpu.edx = 5031340 /*0x4cc5ac*/;
    // 0048f4cb  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048f4d2  beacc54c00             -mov esi, 0x4cc5ac
    cpu.esi = 5031340 /*0x4cc5ac*/;
    // 0048f4d7  e840ffffff             -call 0x48f41c
    cpu.esp -= 4;
    sub_48f41c(app, cpu);
    if (cpu.terminate) return;
    // 0048f4dc  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f4de  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048f4e3  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f4e7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0048f4e9  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 0048f4ee  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0048f4f0:
    // 0048f4f0  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f4f4  8d54246c               -lea edx, [esp + 0x6c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048f4f8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f4fa  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048f4ff  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048f501  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f505  e826fbffff             -call 0x48f030
    cpu.esp -= 4;
    sub_48f030(app, cpu);
    if (cpu.terminate) return;
    // 0048f50a  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048f511  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f513  8b95d0c54c00           -mov edx, dword ptr [ebp + 0x4cc5d0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5031376) /* 0x4cc5d0 */);
    // 0048f519  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f51b  e828ffffff             -call 0x48f448
    cpu.esp -= 4;
    sub_48f448(app, cpu);
    if (cpu.terminate) return;
    // 0048f520  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f524  8d942490000000         -lea edx, [esp + 0x90]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048f52b  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f52f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f532  e8b9feffff             -call 0x48f3f0
    cpu.esp -= 4;
    sub_48f3f0(app, cpu);
    if (cpu.terminate) return;
    // 0048f537  83fd10                 +cmp ebp, 0x10
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
    // 0048f53a  75b4                   -jne 0x48f4f0
    if (!cpu.flags.zf)
    {
        goto L_0x0048f4f0;
    }
    // 0048f53c  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048f541  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f545  8bb424b8000000         -mov esi, dword ptr [esp + 0xb8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048f54c  8b9c24b8000000         -mov ebx, dword ptr [esp + 0xb8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048f553  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f555  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f559  8b8c24b4000000         -mov ecx, dword ptr [esp + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048f560  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f564  41                     -inc ecx
    (cpu.ecx)++;
    // 0048f565  e8c6faffff             -call 0x48f030
    cpu.esp -= 4;
    sub_48f030(app, cpu);
    if (cpu.terminate) return;
    // 0048f56a  898c24b4000000         -mov dword ptr [esp + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 0048f571  83f904                 +cmp ecx, 4
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
    // 0048f574  0f8c1affffff           -jl 0x48f494
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f494;
    }
    // 0048f57a  81c4bc000000           -add esp, 0xbc
    (cpu.esp) += x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 0048f580  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f581  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f582  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f583  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f584  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f585  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f586  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48f588(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f588  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f589  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f58a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f58b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f58c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048f58f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f591  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048f593  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f595  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048f59b  c0e507                 +shl ch, 7
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
    // 0048f59e  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f5a0  00ed                   +add ch, ch
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
    // 0048f5a2  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048f5a4  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f5a6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048f5ab  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f5ad  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048f5b4  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f5b6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f5b8  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048f5bc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f5be  c0e407                 +shl ah, 7
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
    // 0048f5c1  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f5c3  00e4                   +add ah, ah
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
    // 0048f5c5  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048f5c7  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f5c9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048f5ce  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f5d0  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048f5d7  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f5d9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f5db  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f5dd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048f5df  7518                   -jne 0x48f5f9
    if (!cpu.flags.zf)
    {
        goto L_0x0048f5f9;
    }
    // 0048f5e1  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048f5e6  beacc54c00             -mov esi, 0x4cc5ac
    cpu.esi = 5031340 /*0x4cc5ac*/;
    // 0048f5eb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048f5ed  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f5ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f5f1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048f5f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f5f9:
    // 0048f5f9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048f5fb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f5fd  e86e320100             -call 0x4a2870
    cpu.esp -= 4;
    sub_4a2870(app, cpu);
    if (cpu.terminate) return;
    // 0048f602  bd00000100             -mov ebp, 0x10000
    cpu.ebp = 65536 /*0x10000*/;
    // 0048f607  2b6c2414               -sub ebp, dword ptr [esp + 0x14]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0048f60b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f60e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f610  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f612  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f615  c1e810                 +shr eax, 0x10
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
    // 0048f618  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f61a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f61e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f620  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f622  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f624  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f627  c1e810                 +shr eax, 0x10
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
    // 0048f62a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f62c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f630  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048f632  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f634  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f636  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f639  c1e810                 +shr eax, 0x10
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
    // 0048f63c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f63e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f641  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f643  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f645  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f647  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f64a  c1e810                 +shr eax, 0x10
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
    // 0048f64d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f64f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f653  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048f657  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f659  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f65b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f65e  c1e810                 +shr eax, 0x10
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
    // 0048f661  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f663  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f667  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048f66b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f66d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f66f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f672  c1e810                 +shr eax, 0x10
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
    // 0048f675  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f677  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f67a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f67c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f67e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f680  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f683  c1e810                 +shr eax, 0x10
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
    // 0048f686  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f688  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048f68c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f68e  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0048f690  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f692  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f696  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f698  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f69b  c1e810                 +shr eax, 0x10
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
    // 0048f69e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f6a0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048f6a2  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048f6a5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f6a9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f6ab  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048f6af  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f6b1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f6b4  c1e810                 +shr eax, 0x10
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
    // 0048f6b7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f6b9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f6bb  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048f6be  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f6c1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f6c3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f6c5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f6c8  c1e810                 +shr eax, 0x10
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
    // 0048f6cb  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f6cd  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048f6cf  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048f6d2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f6d6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f6d8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f6da  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f6dd  c1e810                 +shr eax, 0x10
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
    // 0048f6e0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f6e2  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048f6e6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f6e8  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048f6eb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f6ed  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f6f1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f6f3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f6f6  c1e810                 +shr eax, 0x10
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
    // 0048f6f9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f6fb  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048f6ff  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f701  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048f704  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f706  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f709  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f70b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f70e  c1e810                 +shr eax, 0x10
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
    // 0048f711  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f713  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0048f716  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048f719  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f71b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f71f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048f723  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f725  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f728  c1e810                 +shr eax, 0x10
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
    // 0048f72b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f72d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048f72f  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048f732  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f736  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f738  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f73a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f73d  c1e810                 +shr eax, 0x10
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
    // 0048f740  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f742  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048f746  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f748  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048f74b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048f74d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048f750  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f751  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f752  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f753  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f754  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f755(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f755  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f75b  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048f75e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f75f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f75f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f760  e8f0ffffff             -call 0x48f755
    cpu.esp -= 4;
    sub_48f755(app, cpu);
    if (cpu.terminate) return;
    // 0048f765  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f767  7418                   -je 0x48f781
    if (cpu.flags.zf)
    {
        goto L_0x0048f781;
    }
    // 0048f769  69106d4ec641           -imul edx, dword ptr [eax], 0x41c64e6d
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))) * x86::sreg64(x86::sreg32(1103515245 /*0x41c64e6d*/)));
    // 0048f76f  81c239300000           -add edx, 0x3039
    (cpu.edx) += x86::reg32(x86::sreg32(12345 /*0x3039*/));
    // 0048f775  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0048f777  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f779  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0048f77c  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
L_0x0048f781:
    // 0048f781  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f782  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f783(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f783  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f784  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f786  e8caffffff             -call 0x48f755
    cpu.esp -= 4;
    sub_48f755(app, cpu);
    if (cpu.terminate) return;
    // 0048f78b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f78d  7402                   -je 0x48f791
    if (cpu.flags.zf)
    {
        goto L_0x0048f791;
    }
    // 0048f78f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0048f791:
    // 0048f791  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f792  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f793(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f793  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f794  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f795  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f796  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048f797  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f798  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048f79a  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048f7a0  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0048f7a6  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048f7a8  8b3550845200           -mov esi, dword ptr [0x528450]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407824) /* 0x528450 */);
    // 0048f7ae  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f7b3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048f7b5  740d                   -je 0x48f7c4
    if (cpu.flags.zf)
    {
        goto L_0x0048f7c4;
    }
    // 0048f7b7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048f7b9  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048f7be  893d50845200           -mov dword ptr [0x528450], edi
    app->getMemory<x86::reg32>(x86::reg32(5407824) /* 0x528450 */) = cpu.edi;
L_0x0048f7c4:
    // 0048f7c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f7c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f7c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f7c7  68b80d4c00             -push 0x4c0db8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4984248 /*0x4c0db8*/;
    cpu.esp -= 4;
    // 0048f7cc  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0048f7d1  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048f7d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f7d5  e8d8310100             -call 0x4a29b2
    cpu.esp -= 4;
    sub_4a29b2(app, cpu);
    if (cpu.terminate) return;
    // 0048f7da  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048f7dd  803dacea4c0000         +cmp byte ptr [0x4ceaac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5040812) /* 0x4ceaac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f7e4  0f84f8000000           -je 0x48f8e2
    if (cpu.flags.zf)
    {
        goto L_0x0048f8e2;
    }
    // 0048f7ea  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048f7ed  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048f7ee  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048f7f0  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048f7f2  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f7f4  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f7f5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f7f7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f7f9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048f7fb  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f7fc  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048f7fd  8d5117                 -lea edx, [ecx + 0x17]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0048f800  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0048f803  e8d5310100             -call 0x4a29dd
    cpu.esp -= 4;
    sub_4a29dd(app, cpu);
    if (cpu.terminate) return;
    // 0048f808  39c2                   +cmp edx, eax
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
    // 0048f80a  733c                   -jae 0x48f848
    if (!cpu.flags.cf)
    {
        goto L_0x0048f848;
    }
    // 0048f80c  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048f80f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048f810  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048f812  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048f814  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f816  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f817  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f819  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f81b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048f81d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f81e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048f81f  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0048f822  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0048f824  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f825  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048f828  e8ff310100             -call 0x4a2a2c
    cpu.esp -= 4;
    sub_4a2a2c(app, cpu);
    if (cpu.terminate) return;
    // 0048f82d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048f82e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048f830  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048f832  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f834  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f835  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f837  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f839  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048f83b  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f83c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048f83d  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0048f840  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0048f842  29c4                   +sub esp, eax
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f844  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048f846  eb02                   -jmp 0x48f84a
    goto L_0x0048f84a;
L_0x0048f848:
    // 0048f848  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048f84a:
    // 0048f84a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048f84c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048f84e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048f850  bed00d4c00             -mov esi, 0x4c0dd0
    cpu.esi = 4984272 /*0x4c0dd0*/;
    // 0048f855  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f856  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f857  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f858  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048f859  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0048f85b  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0048f85c  8d75fe                 -lea esi, [ebp - 2]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048f85f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048f861  894d7e                 -mov dword ptr [ebp + 0x7e], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.ecx;
    // 0048f864  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048f865  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 0048f866  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048f867  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f868  2bc9                   +sub ecx, ecx
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
    // 0048f86a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048f86b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048f86d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f86f  4f                     -dec edi
    (cpu.edi)--;
L_0x0048f870:
    // 0048f870  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f872  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048f874  3c00                   +cmp al, 0
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
    // 0048f876  7410                   -je 0x48f888
    if (cpu.flags.zf)
    {
        goto L_0x0048f888;
    }
    // 0048f878  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048f87b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f87e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048f881  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f884  3c00                   +cmp al, 0
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
    // 0048f886  75e8                   -jne 0x48f870
    if (!cpu.flags.zf)
    {
        goto L_0x0048f870;
    }
L_0x0048f888:
    // 0048f888  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f889  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048f88a  e84e310100             -call 0x4a29dd
    cpu.esp -= 4;
    sub_4a29dd(app, cpu);
    if (cpu.terminate) return;
    // 0048f88f  83f814                 +cmp eax, 0x14
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
    // 0048f892  7612                   -jbe 0x48f8a6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f8a6;
    }
    // 0048f894  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0048f896  e891310100             -call 0x4a2a2c
    cpu.esp -= 4;
    sub_4a2a2c(app, cpu);
    if (cpu.terminate) return;
    // 0048f89b  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0048f8a0  29c4                   +sub esp, eax
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f8a2  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048f8a4  eb02                   -jmp 0x48f8a8
    goto L_0x0048f8a8;
L_0x0048f8a6:
    // 0048f8a6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048f8a8:
    // 0048f8a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f8a9  68e30d4c00             -push 0x4c0de3
    app->getMemory<x86::reg32>(cpu.esp-4) = 4984291 /*0x4c0de3*/;
    cpu.esp -= 4;
    // 0048f8ae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f8af  e82dc7feff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0048f8b4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048f8b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f8b8  2eff1550754b00         -call dword ptr cs:[0x4b7550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945232) /* 0x4b7550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f8bf  803dacea4c0000         +cmp byte ptr [0x4ceaac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5040812) /* 0x4ceaac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f8c6  7436                   -je 0x48f8fe
    if (cpu.flags.zf)
    {
        goto L_0x0048f8fe;
    }
    // 0048f8c8  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048f8ca  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0048f8cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f8d0  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0048f8d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f8d4  cc                     -int3 
    NFS2_ASSERT(false);
    // 0048f8d5  eb06                   -jmp 0x48f8dd
    goto L_0x0048f8dd;
    // 0048f8d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f8d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f8d9  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f8da  44                     -inc esp
    (cpu.esp)++;
    // 0048f8db  45                     -inc ebp
    (cpu.ebp)++;
    // 0048f8dc  4f                     -dec edi
    (cpu.edi)--;
L_0x0048f8dd:
    // 0048f8dd  83c408                 +add esp, 8
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
    // 0048f8e0  eb1c                   -jmp 0x48f8fe
    goto L_0x0048f8fe;
L_0x0048f8e2:
    // 0048f8e2  6800200000             -push 0x2000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 0048f8e7  68f40d4c00             -push 0x4c0df4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4984308 /*0x4c0df4*/;
    cpu.esp -= 4;
    // 0048f8ec  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048f8ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f8f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048f8f2  2eff1500744b00         -call dword ptr cs:[0x4b7400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944896) /* 0x4b7400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f8f9  e862310100             -call 0x4a2a60
    cpu.esp -= 4;
    sub_4a2a60(app, cpu);
    if (cpu.terminate) return;
L_0x0048f8fe:
    // 0048f8fe  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0048f904  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f905  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048f906  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f907  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f908  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f909  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f90a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f90a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f90b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f90d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f90f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048f911  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048f913  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048f915  750f                   -jne 0x48f926
    if (!cpu.flags.zf)
    {
        goto L_0x0048f926;
    }
    // 0048f917  c7055084520001000000   -mov dword ptr [0x528450], 1
    app->getMemory<x86::reg32>(x86::reg32(5407824) /* 0x528450 */) = 1 /*0x1*/;
    // 0048f921  e86dfeffff             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
L_0x0048f926:
    // 0048f926  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f927  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48f930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f933  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048f939  8b842414040000         -mov eax, dword ptr [esp + 0x414]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0048f940  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f942  7415                   -je 0x48f959
    if (cpu.flags.zf)
    {
        goto L_0x0048f959;
    }
    // 0048f944  8b942418040000         -mov edx, dword ptr [esp + 0x418]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0048f94b  3b10                   +cmp edx, dword ptr [eax]
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
    // 0048f94d  7e0a                   -jle 0x48f959
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f959;
    }
L_0x0048f94f:
    // 0048f94f  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048f955  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f956  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f957  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f958  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f959:
    // 0048f959  8d842420040000         -lea eax, [esp + 0x420]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1056) /* 0x420 */);
    // 0048f960  8d9c2400040000         -lea ebx, [esp + 0x400]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0048f967  8b94241c040000         -mov edx, dword ptr [esp + 0x41c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0048f96e  89842400040000         -mov dword ptr [esp + 0x400], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 0048f975  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f977  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f979  e858810000             -call 0x497ad6
    cpu.esp -= 4;
    sub_497ad6(app, cpu);
    if (cpu.terminate) return;
    // 0048f97e  a100c74c00             -mov eax, dword ptr [0x4cc700]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5031680) /* 0x4cc700 */);
    // 0048f983  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 0048f98a  83f802                 +cmp eax, 2
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
    // 0048f98d  7319                   -jae 0x48f9a8
    if (!cpu.flags.cf)
    {
        goto L_0x0048f9a8;
    }
    // 0048f98f  83f801                 +cmp eax, 1
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
    // 0048f992  75bb                   -jne 0x48f94f
    if (!cpu.flags.zf)
    {
        goto L_0x0048f94f;
    }
    // 0048f994  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f996  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f997  2eff1550754b00         -call dword ptr cs:[0x4b7550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945232) /* 0x4b7550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f99e  81c404040000           +add esp, 0x404
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1028 /*0x404*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f9a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f9a8:
    // 0048f9a8  761a                   -jbe 0x48f9c4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048f9c4;
    }
    // 0048f9aa  83f803                 +cmp eax, 3
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
    // 0048f9ad  75a0                   -jne 0x48f94f
    if (!cpu.flags.zf)
    {
        goto L_0x0048f94f;
    }
    // 0048f9af  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f9b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f9b2  e8e95effff             -call 0x4858a0
    cpu.esp -= 4;
    sub_4858a0(app, cpu);
    if (cpu.terminate) return;
    // 0048f9b7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f9ba  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048f9c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f9c4:
    // 0048f9c4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f9c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f9c7  e8d5800000             -call 0x497aa1
    cpu.esp -= 4;
    sub_497aa1(app, cpu);
    if (cpu.terminate) return;
    // 0048f9cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f9cf  b88ee14c00             -mov eax, 0x4ce18e
    cpu.eax = 5038478 /*0x4ce18e*/;
    // 0048f9d4  e89f300100             -call 0x4a2a78
    cpu.esp -= 4;
    sub_4a2a78(app, cpu);
    if (cpu.terminate) return;
    // 0048f9d9  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048f9df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f9e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f9e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f9e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048f9e6:
    // 0048f9e6  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0048f9e8  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0048f9ea  3c41                   +cmp al, 0x41
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f9ec  7206                   -jb 0x48f9f4
    if (cpu.flags.cf)
    {
        goto L_0x0048f9f4;
    }
    // 0048f9ee  3c5a                   +cmp al, 0x5a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f9f0  7702                   -ja 0x48f9f4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048f9f4;
    }
    // 0048f9f2  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0048f9f4:
    // 0048f9f4  80fc41                 +cmp ah, 0x41
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f9f7  7208                   -jb 0x48fa01
    if (cpu.flags.cf)
    {
        goto L_0x0048fa01;
    }
    // 0048f9f9  80fc5a                 +cmp ah, 0x5a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f9fc  7703                   -ja 0x48fa01
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048fa01;
    }
    // 0048f9fe  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0048fa01:
    // 0048fa01  38e0                   +cmp al, ah
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048fa03  7508                   -jne 0x48fa0d
    if (!cpu.flags.zf)
    {
        goto L_0x0048fa0d;
    }
    // 0048fa05  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048fa07  7404                   -je 0x48fa0d
    if (cpu.flags.zf)
    {
        goto L_0x0048fa0d;
    }
    // 0048fa09  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048fa0a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048fa0b  ebd9                   -jmp 0x48f9e6
    goto L_0x0048f9e6;
L_0x0048fa0d:
    // 0048fa0d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fa0f  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0048fa11  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 0048fa13  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048fa18  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fa1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048fa1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_48fa20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fa20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fa21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fa22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fa23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fa24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fa25  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048fa27  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0048fa2a  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0048fa30  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0048fa33  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048fa35  c0e407                 +shl ah, 7
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
    // 0048fa38  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048fa3a  00e4                   +add ah, ah
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
    // 0048fa3c  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048fa3e  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fa40  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048fa45  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fa47  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048fa4e  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fa50  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fa52  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048fa54  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fa56  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048fa5c  c0e507                 +shl ch, 7
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
    // 0048fa5f  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048fa61  00ed                   +add ch, ch
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
    // 0048fa63  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048fa65  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fa67  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048fa6c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fa6e  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048fa75  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fa77  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fa79  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048fa7c  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0048fa7f  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0048fa82  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 0048fa85  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048fa87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa88  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48fa90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fa90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fa91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fa92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fa93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fa94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fa95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048fa97  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0048fa9a  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0048faa0  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0048faa3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048faa5  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048faab  c0e507                 +shl ch, 7
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
    // 0048faae  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048fab0  00ed                   +add ch, ch
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
    // 0048fab2  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048fab4  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fab6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048fabb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fabd  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048fac4  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fac6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fac8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048faca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048facc  c0e407                 +shl ah, 7
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
    // 0048facf  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048fad1  00e4                   +add ah, ah
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
    // 0048fad3  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048fad5  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fad7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048fadc  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fade  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0048fae5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fae7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fae9  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048faeb  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048faee  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0048faf1  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0048faf4  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 0048faf7  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048faf9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fafa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fafb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fafc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fafd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fafe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48fb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fb00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fb01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fb02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048fb03  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048fb06  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048fb0a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048fb0d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048fb11  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0048fb16  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fb18  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0048fb1a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048fb1e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048fb23  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048fb28  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048fb2a  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048fb2e  a368845200             -mov dword ptr [0x528468], eax
    app->getMemory<x86::reg32>(x86::reg32(5407848) /* 0x528468 */) = cpu.eax;
    // 0048fb33  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0048fb35  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048fb39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048fb3e  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fb40  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048fb42  a36c845200             -mov dword ptr [0x52846c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407852) /* 0x52846c */) = cpu.eax;
    // 0048fb47  a168845200             -mov eax, dword ptr [0x528468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407848) /* 0x528468 */);
    // 0048fb4c  a3ac845200             -mov dword ptr [0x5284ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */) = cpu.eax;
    // 0048fb51  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048fb54  8b1568845200           -mov edx, dword ptr [0x528468]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407848) /* 0x528468 */);
    // 0048fb5a  891d64845200           -mov dword ptr [0x528464], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407844) /* 0x528464 */) = cpu.ebx;
    // 0048fb60  a3b0845200             -mov dword ptr [0x5284b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */) = cpu.eax;
    // 0048fb65  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048fb69  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048fb6d  e872070000             -call 0x4902e4
    cpu.esp -= 4;
    sub_4902e4(app, cpu);
    if (cpu.terminate) return;
    // 0048fb72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fb74  8b1d64845200           -mov ebx, dword ptr [0x528464]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407844) /* 0x528464 */);
    // 0048fb7a  891560845200           -mov dword ptr [0x528460], edx
    app->getMemory<x86::reg32>(x86::reg32(5407840) /* 0x528460 */) = cpu.edx;
    // 0048fb80  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048fb82  7e23                   -jle 0x48fba7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fba7;
    }
L_0x0048fb84:
    // 0048fb84  a160845200             -mov eax, dword ptr [0x528460]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407840) /* 0x528460 */);
    // 0048fb89  80b8b8a44c0000         +cmp byte ptr [eax + 0x4ca4b8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022904) /* 0x4ca4b8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048fb90  7524                   -jne 0x48fbb6
    if (!cpu.flags.zf)
    {
        goto L_0x0048fbb6;
    }
L_0x0048fb92:
    // 0048fb92  8b3560845200           -mov esi, dword ptr [0x528460]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407840) /* 0x528460 */);
    // 0048fb98  46                     -inc esi
    (cpu.esi)++;
    // 0048fb99  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048fb9d  893560845200           -mov dword ptr [0x528460], esi
    app->getMemory<x86::reg32>(x86::reg32(5407840) /* 0x528460 */) = cpu.esi;
    // 0048fba3  39fe                   +cmp esi, edi
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
    // 0048fba5  7cdd                   -jl 0x48fb84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fb84;
    }
L_0x0048fba7:
    // 0048fba7  891d64845200           -mov dword ptr [0x528464], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407844) /* 0x528464 */) = cpu.ebx;
    // 0048fbad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048fbb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbb3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048fbb6:
    // 0048fbb6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0048fbb9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048fbbc  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fbbe  0fb67702               -movzx esi, byte ptr [edi + 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */));
    // 0048fbc2  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048fbc6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048fbc8  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0048fbca  0fb66f01               -movzx ebp, byte ptr [edi + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */));
    // 0048fbce  a398845200             -mov dword ptr [0x528498], eax
    app->getMemory<x86::reg32>(x86::reg32(5407896) /* 0x528498 */) = cpu.eax;
    // 0048fbd3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048fbd5  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0048fbd7  0fb63f                 -movzx edi, byte ptr [edi]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0048fbda  a388845200             -mov dword ptr [0x528488], eax
    app->getMemory<x86::reg32>(x86::reg32(5407880) /* 0x528488 */) = cpu.eax;
    // 0048fbdf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048fbe1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048fbe3  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0048fbe5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048fbe8  a38c845200             -mov dword ptr [0x52848c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407884) /* 0x52848c */) = cpu.eax;
    // 0048fbed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fbef  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fbf1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048fbf3  8b0d98845200           -mov ecx, dword ptr [0x528498]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407896) /* 0x528498 */);
    // 0048fbf9  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048fbfc  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0048fbff  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048fc01  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048fc04  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fc06  8b1588845200           -mov edx, dword ptr [0x528488]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407880) /* 0x528488 */);
    // 0048fc0c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048fc0f  890d9c845200           -mov dword ptr [0x52849c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */) = cpu.ecx;
    // 0048fc15  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048fc17  0fafeb                 -imul ebp, ebx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048fc1a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fc1c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fc1e  8b158c845200           -mov edx, dword ptr [0x52848c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407884) /* 0x52848c */);
    // 0048fc24  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048fc27  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fc29  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fc2b  0faffb                 -imul edi, ebx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048fc2e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fc30  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fc32  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048fc35  891594845200           -mov dword ptr [0x528494], edx
    app->getMemory<x86::reg32>(x86::reg32(5407892) /* 0x528494 */) = cpu.edx;
    // 0048fc3b  8b159c845200           -mov edx, dword ptr [0x52849c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */);
    // 0048fc41  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048fc44  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fc46  a194845200             -mov eax, dword ptr [0x528494]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407892) /* 0x528494 */);
    // 0048fc4b  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048fc4e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fc50  a198845200             -mov eax, dword ptr [0x528498]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407896) /* 0x528498 */);
    // 0048fc55  891594845200           -mov dword ptr [0x528494], edx
    app->getMemory<x86::reg32>(x86::reg32(5407892) /* 0x528494 */) = cpu.edx;
    // 0048fc5b  8b156c845200           -mov edx, dword ptr [0x52846c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407852) /* 0x52846c */);
    // 0048fc61  40                     -inc eax
    (cpu.eax)++;
    // 0048fc62  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048fc65  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048fc67  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fc69  a370845200             -mov dword ptr [0x528470], eax
    app->getMemory<x86::reg32>(x86::reg32(5407856) /* 0x528470 */) = cpu.eax;
    // 0048fc6e  a188845200             -mov eax, dword ptr [0x528488]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407880) /* 0x528488 */);
    // 0048fc73  40                     -inc eax
    (cpu.eax)++;
    // 0048fc74  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048fc77  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048fc79  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fc7b  a378845200             -mov dword ptr [0x528478], eax
    app->getMemory<x86::reg32>(x86::reg32(5407864) /* 0x528478 */) = cpu.eax;
    // 0048fc80  a18c845200             -mov eax, dword ptr [0x52848c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407884) /* 0x52848c */);
    // 0048fc85  40                     -inc eax
    (cpu.eax)++;
    // 0048fc86  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048fc89  8b3598845200           -mov esi, dword ptr [0x528498]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407896) /* 0x528498 */);
    // 0048fc8f  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048fc91  0faf35b0845200         -imul esi, dword ptr [0x5284b0]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */))));
    // 0048fc98  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fc9a  a374845200             -mov dword ptr [0x528474], eax
    app->getMemory<x86::reg32>(x86::reg32(5407860) /* 0x528474 */) = cpu.eax;
    // 0048fc9f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048fca3  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0048fcaa  8b15ac845200           -mov edx, dword ptr [0x5284ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */);
    // 0048fcb0  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fcb2  a188845200             -mov eax, dword ptr [0x528488]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407880) /* 0x528488 */);
    // 0048fcb7  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048fcba  890da8845200           -mov dword ptr [0x5284a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */) = cpu.ecx;
    // 0048fcc0  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048fcc4  891d64845200           -mov dword ptr [0x528464], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407844) /* 0x528464 */) = cpu.ebx;
    // 0048fcca  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fccc  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 0048fcd3  8b158c845200           -mov edx, dword ptr [0x52848c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407884) /* 0x52848c */);
    // 0048fcd9  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048fcdb  8b3d8c845200           -mov edi, dword ptr [0x52848c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407884) /* 0x52848c */);
    // 0048fce1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048fce3  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0048fce6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fce8  01fd                   +add ebp, edi
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
    // 0048fcea  891584845200           -mov dword ptr [0x528484], edx
    app->getMemory<x86::reg32>(x86::reg32(5407876) /* 0x528484 */) = cpu.edx;
    // 0048fcf0  892d80845200           -mov dword ptr [0x528480], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407872) /* 0x528480 */) = cpu.ebp;
    // 0048fcf6  e80d000000             -call 0x48fd08
    cpu.esp -= 4;
    sub_48fd08(app, cpu);
    if (cpu.terminate) return;
    // 0048fcfb  8b1d64845200           -mov ebx, dword ptr [0x528464]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407844) /* 0x528464 */);
    // 0048fd01  e98cfeffff             -jmp 0x48fb92
    goto L_0x0048fb92;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48fd08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fd08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fd09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fd0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fd0b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fd0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fd0d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048fd0e  8b1d6c845200           -mov ebx, dword ptr [0x52846c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407852) /* 0x52846c */);
    // 0048fd14  8b0d98845200           -mov ecx, dword ptr [0x528498]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407896) /* 0x528498 */);
    // 0048fd1a  a194845200             -mov eax, dword ptr [0x528494]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407892) /* 0x528494 */);
    // 0048fd1f  8b3570845200           -mov esi, dword ptr [0x528470]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407856) /* 0x528470 */);
    // 0048fd25  8b3d68845200           -mov edi, dword ptr [0x528468]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407848) /* 0x528468 */);
    // 0048fd2b  a39c845200             -mov dword ptr [0x52849c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */) = cpu.eax;
    // 0048fd30  a180845200             -mov eax, dword ptr [0x528480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407872) /* 0x528480 */);
    // 0048fd35  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fd37  a37c845200             -mov dword ptr [0x52847c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */) = cpu.eax;
    // 0048fd3c  a184845200             -mov eax, dword ptr [0x528484]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407876) /* 0x528484 */);
    // 0048fd41  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fd43  a3a0845200             -mov dword ptr [0x5284a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */) = cpu.eax;
    // 0048fd48  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048fd4d  39f9                   +cmp ecx, edi
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
    // 0048fd4f  0f8cc0000000           -jl 0x48fe15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fe15;
    }
L_0x0048fd55:
    // 0048fd55  8b3570845200           -mov esi, dword ptr [0x528470]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407856) /* 0x528470 */);
    // 0048fd5b  a194845200             -mov eax, dword ptr [0x528494]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407892) /* 0x528494 */);
    // 0048fd60  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fd62  8b3db0845200           -mov edi, dword ptr [0x5284b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */);
    // 0048fd68  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048fd6a  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0048fd6d  a39c845200             -mov dword ptr [0x52849c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */) = cpu.eax;
    // 0048fd72  a180845200             -mov eax, dword ptr [0x528480]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407872) /* 0x528480 */);
    // 0048fd77  8b0d98845200           -mov ecx, dword ptr [0x528498]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407896) /* 0x528498 */);
    // 0048fd7d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048fd7f  8b2db0845200           -mov ebp, dword ptr [0x5284b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */);
    // 0048fd85  a37c845200             -mov dword ptr [0x52847c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */) = cpu.eax;
    // 0048fd8a  a184845200             -mov eax, dword ptr [0x528484]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407876) /* 0x528484 */);
    // 0048fd8f  49                     -dec ecx
    (cpu.ecx)--;
    // 0048fd90  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048fd92  8935b4845200           -mov dword ptr [0x5284b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */) = cpu.esi;
    // 0048fd98  a3a0845200             -mov dword ptr [0x5284a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */) = cpu.eax;
    // 0048fd9d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048fda2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048fda4  7c60                   -jl 0x48fe06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fe06;
    }
L_0x0048fda6:
    // 0048fda6  e8f5000000             -call 0x48fea0
    cpu.esp -= 4;
    sub_48fea0(app, cpu);
    if (cpu.terminate) return;
    // 0048fdab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fdad  0f84dd000000           -je 0x48fe90
    if (cpu.flags.zf)
    {
        goto L_0x0048fe90;
    }
    // 0048fdb3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048fdb8:
    // 0048fdb8  a1b0845200             -mov eax, dword ptr [0x5284b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */);
    // 0048fdbd  8b357c845200           -mov esi, dword ptr [0x52847c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */);
    // 0048fdc3  8b3da0845200           -mov edi, dword ptr [0x5284a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */);
    // 0048fdc9  8b2d9c845200           -mov ebp, dword ptr [0x52849c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */);
    // 0048fdcf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048fdd2  49                     -dec ecx
    (cpu.ecx)--;
    // 0048fdd3  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fdd5  a1b0845200             -mov eax, dword ptr [0x5284b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */);
    // 0048fdda  89357c845200           -mov dword ptr [0x52847c], esi
    app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */) = cpu.esi;
    // 0048fde0  8b35b4845200           -mov esi, dword ptr [0x5284b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */);
    // 0048fde6  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fde8  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fdea  893da0845200           -mov dword ptr [0x5284a0], edi
    app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */) = cpu.edi;
    // 0048fdf0  8935b4845200           -mov dword ptr [0x5284b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */) = cpu.esi;
    // 0048fdf6  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048fdf8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048fdfa  892d9c845200           -mov dword ptr [0x52849c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */) = cpu.ebp;
    // 0048fe00  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048fe02  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048fe04  7da0                   -jge 0x48fda6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fda6;
    }
L_0x0048fe06:
    // 0048fe06  8b35b4845200           -mov esi, dword ptr [0x5284b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */);
    // 0048fe0c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048fe0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fe15:
    // 0048fe15  8935b4845200           -mov dword ptr [0x5284b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */) = cpu.esi;
L_0x0048fe1b:
    // 0048fe1b  e880000000             -call 0x48fea0
    cpu.esp -= 4;
    sub_48fea0(app, cpu);
    if (cpu.terminate) return;
    // 0048fe20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fe22  745c                   -je 0x48fe80
    if (cpu.flags.zf)
    {
        goto L_0x0048fe80;
    }
    // 0048fe24  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048fe29  8b35b4845200           -mov esi, dword ptr [0x5284b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */);
L_0x0048fe2f:
    // 0048fe2f  a1b0845200             -mov eax, dword ptr [0x5284b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */);
    // 0048fe34  8b2d7c845200           -mov ebp, dword ptr [0x52847c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */);
    // 0048fe3a  8b3da0845200           -mov edi, dword ptr [0x5284a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */);
    // 0048fe40  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048fe43  41                     -inc ecx
    (cpu.ecx)++;
    // 0048fe44  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fe46  a1b0845200             -mov eax, dword ptr [0x5284b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407920) /* 0x5284b0 */);
    // 0048fe4b  892d7c845200           -mov dword ptr [0x52847c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */) = cpu.ebp;
    // 0048fe51  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fe53  8b2d9c845200           -mov ebp, dword ptr [0x52849c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */);
    // 0048fe59  893da0845200           -mov dword ptr [0x5284a0], edi
    app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */) = cpu.edi;
    // 0048fe5f  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048fe61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fe63  8b3d68845200           -mov edi, dword ptr [0x528468]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407848) /* 0x528468 */);
    // 0048fe69  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fe6b  892d9c845200           -mov dword ptr [0x52849c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */) = cpu.ebp;
    // 0048fe71  8935b4845200           -mov dword ptr [0x5284b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */) = cpu.esi;
    // 0048fe77  39f9                   +cmp ecx, edi
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
    // 0048fe79  7ca0                   -jl 0x48fe1b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fe1b;
    }
    // 0048fe7b  e9d5feffff             -jmp 0x48fd55
    goto L_0x0048fd55;
L_0x0048fe80:
    // 0048fe80  8b35b4845200           -mov esi, dword ptr [0x5284b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407924) /* 0x5284b4 */);
    // 0048fe86  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fe88  0f85c7feffff           -jne 0x48fd55
    if (!cpu.flags.zf)
    {
        goto L_0x0048fd55;
    }
    // 0048fe8e  eb9f                   -jmp 0x48fe2f
    goto L_0x0048fe2f;
L_0x0048fe90:
    // 0048fe90  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fe92  0f856effffff           -jne 0x48fe06
    if (!cpu.flags.zf)
    {
        goto L_0x0048fe06;
    }
    // 0048fe98  e91bffffff             -jmp 0x48fdb8
    goto L_0x0048fdb8;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48fea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fea4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fea5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048fea6  8b356c845200           -mov esi, dword ptr [0x52846c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407852) /* 0x52846c */);
    // 0048feac  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048feae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048feb0  0f855d020000           -jne 0x490113
    if (!cpu.flags.zf)
    {
        goto L_0x00490113;
    }
L_0x0048feb6:
    // 0048feb6  8b0db8845200           -mov ecx, dword ptr [0x5284b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407928) /* 0x5284b8 */);
    // 0048febc  a19c845200             -mov eax, dword ptr [0x52849c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */);
    // 0048fec1  8b1dc4845200           -mov ebx, dword ptr [0x5284c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407940) /* 0x5284c4 */);
    // 0048fec7  a3a8845200             -mov dword ptr [0x5284a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */) = cpu.eax;
    // 0048fecc  a3cc845200             -mov dword ptr [0x5284cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */) = cpu.eax;
    // 0048fed1  a17c845200             -mov eax, dword ptr [0x52847c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */);
    // 0048fed6  8b3dc0845200           -mov edi, dword ptr [0x5284c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407936) /* 0x5284c0 */);
    // 0048fedc  a390845200             -mov dword ptr [0x528490], eax
    app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */) = cpu.eax;
    // 0048fee1  a3d0845200             -mov dword ptr [0x5284d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */) = cpu.eax;
    // 0048fee6  a1a0845200             -mov eax, dword ptr [0x5284a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */);
    // 0048feeb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048feed  a3a4845200             -mov dword ptr [0x5284a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */) = cpu.eax;
    // 0048fef2  a3d4845200             -mov dword ptr [0x5284d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */) = cpu.eax;
    // 0048fef7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048fefc  39f9                   +cmp ecx, edi
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
    // 0048fefe  0f8fce000000           -jg 0x48ffd2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048ffd2;
    }
    // 0048ff04  891dc8845200           -mov dword ptr [0x5284c8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */) = cpu.ebx;
L_0x0048ff0a:
    // 0048ff0a  e84d020000             -call 0x49015c
    cpu.esp -= 4;
    sub_49015c(app, cpu);
    if (cpu.terminate) return;
    // 0048ff0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ff11  0f8428020000           -je 0x49013f
    if (cpu.flags.zf)
    {
        goto L_0x0049013f;
    }
    // 0048ff17  8b1dc8845200           -mov ebx, dword ptr [0x5284c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */);
    // 0048ff1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ff1f  7537                   -jne 0x48ff58
    if (!cpu.flags.zf)
    {
        goto L_0x0048ff58;
    }
    // 0048ff21  3b0db8845200           +cmp ecx, dword ptr [0x5284b8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5407928) /* 0x5284b8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ff27  7e2a                   -jle 0x48ff53
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ff53;
    }
    // 0048ff29  a1d0845200             -mov eax, dword ptr [0x5284d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */);
    // 0048ff2e  a37c845200             -mov dword ptr [0x52847c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */) = cpu.eax;
    // 0048ff33  a1d4845200             -mov eax, dword ptr [0x5284d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */);
    // 0048ff38  890db8845200           -mov dword ptr [0x5284b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407928) /* 0x5284b8 */) = cpu.ecx;
    // 0048ff3e  a3a0845200             -mov dword ptr [0x5284a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */) = cpu.eax;
    // 0048ff43  a1cc845200             -mov eax, dword ptr [0x5284cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */);
    // 0048ff48  891dc4845200           -mov dword ptr [0x5284c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407940) /* 0x5284c4 */) = cpu.ebx;
    // 0048ff4e  a39c845200             -mov dword ptr [0x52849c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */) = cpu.eax;
L_0x0048ff53:
    // 0048ff53  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048ff58:
    // 0048ff58  a1ac845200             -mov eax, dword ptr [0x5284ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */);
    // 0048ff5d  8b2d90845200           -mov ebp, dword ptr [0x528490]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */);
    // 0048ff63  8b3dd0845200           -mov edi, dword ptr [0x5284d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */);
    // 0048ff69  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048ff6c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048ff6d  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ff6f  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ff71  a1ac845200             -mov eax, dword ptr [0x5284ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */);
    // 0048ff76  892d90845200           -mov dword ptr [0x528490], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */) = cpu.ebp;
    // 0048ff7c  893dd0845200           -mov dword ptr [0x5284d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */) = cpu.edi;
    // 0048ff82  8b2da4845200           -mov ebp, dword ptr [0x5284a4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */);
    // 0048ff88  8b3dd4845200           -mov edi, dword ptr [0x5284d4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */);
    // 0048ff8e  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ff90  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ff92  892da4845200           -mov dword ptr [0x5284a4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */) = cpu.ebp;
    // 0048ff98  893dd4845200           -mov dword ptr [0x5284d4], edi
    app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */) = cpu.edi;
    // 0048ff9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ffa0  8b2da8845200           -mov ebp, dword ptr [0x5284a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */);
    // 0048ffa6  8b3dcc845200           -mov edi, dword ptr [0x5284cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */);
    // 0048ffac  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ffae  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ffb0  892da8845200           -mov dword ptr [0x5284a8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */) = cpu.ebp;
    // 0048ffb6  893dcc845200           -mov dword ptr [0x5284cc], edi
    app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */) = cpu.edi;
    // 0048ffbc  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048ffbe  8b2dc0845200           -mov ebp, dword ptr [0x5284c0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407936) /* 0x5284c0 */);
    // 0048ffc4  891dc8845200           -mov dword ptr [0x5284c8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */) = cpu.ebx;
    // 0048ffca  39e9                   +cmp ecx, ebp
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
    // 0048ffcc  0f8e38ffffff           -jle 0x48ff0a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ff0a;
    }
L_0x0048ffd2:
    // 0048ffd2  8b0db8845200           -mov ecx, dword ptr [0x5284b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407928) /* 0x5284b8 */);
    // 0048ffd8  8b1dc4845200           -mov ebx, dword ptr [0x5284c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407940) /* 0x5284c4 */);
    // 0048ffde  a19c845200             -mov eax, dword ptr [0x52849c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */);
    // 0048ffe3  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048ffe5  8b3dac845200           -mov edi, dword ptr [0x5284ac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */);
    // 0048ffeb  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ffed  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0048fff0  a3a8845200             -mov dword ptr [0x5284a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */) = cpu.eax;
    // 0048fff5  a3cc845200             -mov dword ptr [0x5284cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */) = cpu.eax;
    // 0048fffa  a17c845200             -mov eax, dword ptr [0x52847c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */);
    // 0048ffff  8b2dbc845200           -mov ebp, dword ptr [0x5284bc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407932) /* 0x5284bc */);
    // 00490005  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00490007  8b3dac845200           -mov edi, dword ptr [0x5284ac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */);
    // 0049000d  a390845200             -mov dword ptr [0x528490], eax
    app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */) = cpu.eax;
    // 00490012  a3d0845200             -mov dword ptr [0x5284d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */) = cpu.eax;
    // 00490017  a1a0845200             -mov eax, dword ptr [0x5284a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */);
    // 0049001c  49                     -dec ecx
    (cpu.ecx)--;
    // 0049001d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049001f  891dc8845200           -mov dword ptr [0x5284c8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */) = cpu.ebx;
    // 00490025  a3a4845200             -mov dword ptr [0x5284a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */) = cpu.eax;
    // 0049002a  a3d4845200             -mov dword ptr [0x5284d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */) = cpu.eax;
    // 0049002f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00490034  39e9                   +cmp ecx, ebp
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
    // 00490036  0f8cc8000000           -jl 0x490104
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490104;
    }
L_0x0049003c:
    // 0049003c  e81b010000             -call 0x49015c
    cpu.esp -= 4;
    sub_49015c(app, cpu);
    if (cpu.terminate) return;
    // 00490041  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490043  0f8409010000           -je 0x490152
    if (cpu.flags.zf)
    {
        goto L_0x00490152;
    }
    // 00490049  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049004b  7535                   -jne 0x490082
    if (!cpu.flags.zf)
    {
        goto L_0x00490082;
    }
    // 0049004d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00490052  a1d0845200             -mov eax, dword ptr [0x5284d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */);
    // 00490057  8b1dc8845200           -mov ebx, dword ptr [0x5284c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */);
    // 0049005d  a37c845200             -mov dword ptr [0x52847c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407868) /* 0x52847c */) = cpu.eax;
    // 00490062  a1d4845200             -mov eax, dword ptr [0x5284d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */);
    // 00490067  890db8845200           -mov dword ptr [0x5284b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407928) /* 0x5284b8 */) = cpu.ecx;
    // 0049006d  a3a0845200             -mov dword ptr [0x5284a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407904) /* 0x5284a0 */) = cpu.eax;
    // 00490072  a1cc845200             -mov eax, dword ptr [0x5284cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */);
    // 00490077  891dc4845200           -mov dword ptr [0x5284c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407940) /* 0x5284c4 */) = cpu.ebx;
    // 0049007d  a39c845200             -mov dword ptr [0x52849c], eax
    app->getMemory<x86::reg32>(x86::reg32(5407900) /* 0x52849c */) = cpu.eax;
L_0x00490082:
    // 00490082  a1ac845200             -mov eax, dword ptr [0x5284ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */);
    // 00490087  8b1d90845200           -mov ebx, dword ptr [0x528490]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */);
    // 0049008d  8b3dd0845200           -mov edi, dword ptr [0x5284d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */);
    // 00490093  8b2da4845200           -mov ebp, dword ptr [0x5284a4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */);
    // 00490099  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049009c  49                     -dec ecx
    (cpu.ecx)--;
    // 0049009d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049009f  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004900a1  a1ac845200             -mov eax, dword ptr [0x5284ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407916) /* 0x5284ac */);
    // 004900a6  891d90845200           -mov dword ptr [0x528490], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */) = cpu.ebx;
    // 004900ac  893dd0845200           -mov dword ptr [0x5284d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5407952) /* 0x5284d0 */) = cpu.edi;
    // 004900b2  8b1dd4845200           -mov ebx, dword ptr [0x5284d4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */);
    // 004900b8  8b3da8845200           -mov edi, dword ptr [0x5284a8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */);
    // 004900be  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004900c0  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004900c2  891dd4845200           -mov dword ptr [0x5284d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407956) /* 0x5284d4 */) = cpu.ebx;
    // 004900c8  8b1dc8845200           -mov ebx, dword ptr [0x5284c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */);
    // 004900ce  892da4845200           -mov dword ptr [0x5284a4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */) = cpu.ebp;
    // 004900d4  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004900d6  8b2dcc845200           -mov ebp, dword ptr [0x5284cc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */);
    // 004900dc  891dc8845200           -mov dword ptr [0x5284c8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */) = cpu.ebx;
    // 004900e2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004900e4  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004900e6  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004900e8  893da8845200           -mov dword ptr [0x5284a8], edi
    app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */) = cpu.edi;
    // 004900ee  892dcc845200           -mov dword ptr [0x5284cc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407948) /* 0x5284cc */) = cpu.ebp;
    // 004900f4  8b3dbc845200           -mov edi, dword ptr [0x5284bc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407932) /* 0x5284bc */);
    // 004900fa  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004900fc  39f9                   +cmp ecx, edi
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
    // 004900fe  0f8d38ffffff           -jge 0x49003c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049003c;
    }
L_0x00490104:
    // 00490104  8b1dc8845200           -mov ebx, dword ptr [0x5284c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */);
    // 0049010a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049010c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049010d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049010e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049010f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490110  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490111  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490112  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490113:
    // 00490113  a188845200             -mov eax, dword ptr [0x528488]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407880) /* 0x528488 */);
    // 00490118  a3b8845200             -mov dword ptr [0x5284b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5407928) /* 0x5284b8 */) = cpu.eax;
    // 0049011d  a168845200             -mov eax, dword ptr [0x528468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407848) /* 0x528468 */);
    // 00490122  48                     -dec eax
    (cpu.eax)--;
    // 00490123  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00490125  a3c0845200             -mov dword ptr [0x5284c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407936) /* 0x5284c0 */) = cpu.eax;
    // 0049012a  a178845200             -mov eax, dword ptr [0x528478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407864) /* 0x528478 */);
    // 0049012f  890dbc845200           -mov dword ptr [0x5284bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407932) /* 0x5284bc */) = cpu.ecx;
    // 00490135  a3c4845200             -mov dword ptr [0x5284c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407940) /* 0x5284c4 */) = cpu.eax;
    // 0049013a  e977fdffff             -jmp 0x48feb6
    goto L_0x0048feb6;
L_0x0049013f:
    // 0049013f  8b1dc8845200           -mov ebx, dword ptr [0x5284c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407944) /* 0x5284c8 */);
    // 00490145  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490147  0f8585feffff           -jne 0x48ffd2
    if (!cpu.flags.zf)
    {
        goto L_0x0048ffd2;
    }
    // 0049014d  e906feffff             -jmp 0x48ff58
    goto L_0x0048ff58;
L_0x00490152:
    // 00490152  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490154  75ae                   -jne 0x490104
    if (!cpu.flags.zf)
    {
        goto L_0x00490104;
    }
    // 00490156  e927ffffff             -jmp 0x490082
    goto L_0x00490082;
}

/* align: skip 0x90 */
void Application::sub_49015c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049015c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049015d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049015e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049015f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490160  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490161  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490162  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490165  8b1560845200           -mov edx, dword ptr [0x528460]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407840) /* 0x528460 */);
    // 0049016b  8b2d6c845200           -mov ebp, dword ptr [0x52846c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5407852) /* 0x52846c */);
    // 00490171  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00490175  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00490177  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490179  0f8582000000           -jne 0x490201
    if (!cpu.flags.zf)
    {
        goto L_0x00490201;
    }
L_0x0049017f:
    // 0049017f  8b0dd8845200           -mov ecx, dword ptr [0x5284d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407960) /* 0x5284d8 */);
    // 00490185  8b15a8845200           -mov edx, dword ptr [0x5284a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */);
    // 0049018b  8b35e4845200           -mov esi, dword ptr [0x5284e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407972) /* 0x5284e4 */);
    // 00490191  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490193  a190845200             -mov eax, dword ptr [0x528490]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */);
    // 00490198  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049019b  8b1de0845200           -mov ebx, dword ptr [0x5284e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407968) /* 0x5284e0 */);
    // 004901a1  8b3da4845200           -mov edi, dword ptr [0x5284a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */);
    // 004901a7  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004901ab  39d9                   +cmp ecx, ebx
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
    // 004901ad  7f34                   -jg 0x4901e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004901e3;
    }
L_0x004901af:
    // 004901af  3b10                   +cmp edx, dword ptr [eax]
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
    // 004901b1  0f8376000000           -jae 0x49022d
    if (!cpu.flags.cf)
    {
        goto L_0x0049022d;
    }
    // 004901b7  3b0dd8845200           +cmp ecx, dword ptr [0x5284d8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5407960) /* 0x5284d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004901bd  7e1d                   -jle 0x4901dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004901dc;
    }
    // 004901bf  890dd8845200           -mov dword ptr [0x5284d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407960) /* 0x5284d8 */) = cpu.ecx;
    // 004901c5  a390845200             -mov dword ptr [0x528490], eax
    app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */) = cpu.eax;
    // 004901ca  893da4845200           -mov dword ptr [0x5284a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */) = cpu.edi;
    // 004901d0  8915a8845200           -mov dword ptr [0x5284a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */) = cpu.edx;
    // 004901d6  8935e4845200           -mov dword ptr [0x5284e4], esi
    app->getMemory<x86::reg32>(x86::reg32(5407972) /* 0x5284e4 */) = cpu.esi;
L_0x004901dc:
    // 004901dc  c7042401000000         -mov dword ptr [esp], 1
    app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
L_0x004901e3:
    // 004901e3  3b4c240c               +cmp ecx, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004901e7  7f5b                   -jg 0x490244
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00490244;
    }
    // 004901e9  3b10                   +cmp edx, dword ptr [eax]
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
    // 004901eb  7357                   -jae 0x490244
    if (!cpu.flags.cf)
    {
        goto L_0x00490244;
    }
    // 004901ed  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004901f1  41                     -inc ecx
    (cpu.ecx)++;
    // 004901f2  47                     -inc edi
    (cpu.edi)++;
    // 004901f3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004901f5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004901f8  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004901fa  885fff                 -mov byte ptr [edi - 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 004901fd  01ee                   +add esi, ebp
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004901ff  ebe2                   -jmp 0x4901e3
    goto L_0x004901e3;
L_0x00490201:
    // 00490201  a18c845200             -mov eax, dword ptr [0x52848c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407884) /* 0x52848c */);
    // 00490206  a3d8845200             -mov dword ptr [0x5284d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5407960) /* 0x5284d8 */) = cpu.eax;
    // 0049020b  a168845200             -mov eax, dword ptr [0x528468]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407848) /* 0x528468 */);
    // 00490210  48                     -dec eax
    (cpu.eax)--;
    // 00490211  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00490213  a3e0845200             -mov dword ptr [0x5284e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407968) /* 0x5284e0 */) = cpu.eax;
    // 00490218  a174845200             -mov eax, dword ptr [0x528474]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407860) /* 0x528474 */);
    // 0049021d  890ddc845200           -mov dword ptr [0x5284dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407964) /* 0x5284dc */) = cpu.ecx;
    // 00490223  a3e4845200             -mov dword ptr [0x5284e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407972) /* 0x5284e4 */) = cpu.eax;
    // 00490228  e952ffffff             -jmp 0x49017f
    goto L_0x0049017f;
L_0x0049022d:
    // 0049022d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490231  41                     -inc ecx
    (cpu.ecx)++;
    // 00490232  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490235  47                     -inc edi
    (cpu.edi)++;
    // 00490236  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00490238  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049023a  39d9                   +cmp ecx, ebx
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
    // 0049023c  0f8e6dffffff           -jle 0x4901af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004901af;
    }
    // 00490242  eb9f                   -jmp 0x4901e3
    goto L_0x004901e3;
L_0x00490244:
    // 00490244  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490247  a1dc845200             -mov eax, dword ptr [0x5284dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407964) /* 0x5284dc */);
    // 0049024c  8b35d8845200           -mov esi, dword ptr [0x5284d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407960) /* 0x5284d8 */);
    // 00490252  8b0de4845200           -mov ecx, dword ptr [0x5284e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407972) /* 0x5284e4 */);
    // 00490258  8b1590845200           -mov edx, dword ptr [0x528490]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */);
    // 0049025e  8b3da4845200           -mov edi, dword ptr [0x5284a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */);
    // 00490264  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00490268  4e                     -dec esi
    (cpu.esi)--;
    // 00490269  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049026c  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049026e  a1a8845200             -mov eax, dword ptr [0x5284a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */);
    // 00490273  4f                     -dec edi
    (cpu.edi)--;
    // 00490274  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490276  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490278  7506                   -jne 0x490280
    if (!cpu.flags.zf)
    {
        goto L_0x00490280;
    }
L_0x0049027a:
    // 0049027a  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049027e  7d1e                   -jge 0x49029e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049029e;
    }
L_0x00490280:
    // 00490280  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490284  7c4e                   -jl 0x4902d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004902d4;
    }
    // 00490286  3b02                   +cmp eax, dword ptr [edx]
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
    // 00490288  734a                   -jae 0x4902d4
    if (!cpu.flags.cf)
    {
        goto L_0x004902d4;
    }
    // 0049028a  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049028e  4e                     -dec esi
    (cpu.esi)--;
    // 0049028f  4f                     -dec edi
    (cpu.edi)--;
    // 00490290  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00490292  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00490294  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490297  29c8                   +sub eax, ecx
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
    // 00490299  885f01                 -mov byte ptr [edi + 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049029c  ebe2                   -jmp 0x490280
    goto L_0x00490280;
L_0x0049029e:
    // 0049029e  3b02                   +cmp eax, dword ptr [edx]
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
    // 004902a0  720b                   -jb 0x4902ad
    if (cpu.flags.cf)
    {
        goto L_0x004902ad;
    }
    // 004902a2  4e                     -dec esi
    (cpu.esi)--;
    // 004902a3  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004902a6  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004902a8  4f                     -dec edi
    (cpu.edi)--;
    // 004902a9  29c8                   +sub eax, ecx
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
    // 004902ab  ebcd                   -jmp 0x49027a
    goto L_0x0049027a;
L_0x004902ad:
    // 004902ad  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004902b2  8935d8845200           -mov dword ptr [0x5284d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5407960) /* 0x5284d8 */) = cpu.esi;
    // 004902b8  891590845200           -mov dword ptr [0x528490], edx
    app->getMemory<x86::reg32>(x86::reg32(5407888) /* 0x528490 */) = cpu.edx;
    // 004902be  893da4845200           -mov dword ptr [0x5284a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5407908) /* 0x5284a4 */) = cpu.edi;
    // 004902c4  a3a8845200             -mov dword ptr [0x5284a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5407912) /* 0x5284a8 */) = cpu.eax;
    // 004902c9  890de4845200           -mov dword ptr [0x5284e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5407972) /* 0x5284e4 */) = cpu.ecx;
    // 004902cf  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004902d2  ebac                   -jmp 0x490280
    goto L_0x00490280;
L_0x004902d4:
    // 004902d4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004902d7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004902da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4902e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004902e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004902e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004902e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004902e9  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004902ec  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004902ef  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004902f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004902f3  7e0f                   -jle 0x490304
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490304;
    }
L_0x004902f5:
    // 004902f5  48                     -dec eax
    (cpu.eax)--;
    // 004902f6  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 004902fc  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004902ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490301  7ff2                   -jg 0x4902f5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004902f5;
    }
    // 00490303  90                     -nop 
    ;
L_0x00490304:
    // 00490304  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490305  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
