#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495854(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495854  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049585b  740f                   -je 0x49586c
    if (cpu.flags.zf)
    {
        goto L_0x0049586c;
    }
    // 0049585d  803dd9ce4d0002         +cmp byte ptr [0x4dced9], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495864  750c                   -jne 0x495872
    if (!cpu.flags.zf)
    {
        goto L_0x00495872;
    }
    // 00495866  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049586b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049586c:
    // 0049586c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00495871  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495872:
    // 00495872  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495873  a2dbce4d00             -mov byte ptr [0x4dcedb], al
    app->getMemory<x86::reg8>(x86::reg32(5099227) /* 0x4dcedb */) = cpu.al;
    // 00495878  8815dece4d00           -mov byte ptr [0x4dcede], dl
    app->getMemory<x86::reg8>(x86::reg32(5099230) /* 0x4dcede */) = cpu.dl;
    // 0049587e  b1ff                   -mov cl, 0xff
    cpu.cl = 255 /*0xff*/;
    // 00495880  880ddfce4d00           -mov byte ptr [0x4dcedf], cl
    app->getMemory<x86::reg8>(x86::reg32(5099231) /* 0x4dcedf */) = cpu.cl;
    // 00495886  880de0ce4d00           -mov byte ptr [0x4dcee0], cl
    app->getMemory<x86::reg8>(x86::reg32(5099232) /* 0x4dcee0 */) = cpu.cl;
    // 0049588c  880de1ce4d00           -mov byte ptr [0x4dcee1], cl
    app->getMemory<x86::reg8>(x86::reg32(5099233) /* 0x4dcee1 */) = cpu.cl;
    // 00495892  e8690e0000             -call 0x496700
    cpu.esp -= 4;
    sub_496700(app, cpu);
    if (cpu.terminate) return;
    // 00495897  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495898  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4958a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004958a0  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 004958a7  740f                   -je 0x4958b8
    if (cpu.flags.zf)
    {
        goto L_0x004958b8;
    }
    // 004958a9  803dd9ce4d0000         +cmp byte ptr [0x4dced9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004958b0  750c                   -jne 0x4958be
    if (!cpu.flags.zf)
    {
        goto L_0x004958be;
    }
    // 004958b2  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004958b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004958b8:
    // 004958b8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004958bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004958be:
    // 004958be  a170ce4d00             -mov eax, dword ptr [0x4dce70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099120) /* 0x4dce70 */);
    // 004958c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4958d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004958d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004958d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004958d2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004958d4  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 004958db  7411                   -je 0x4958ee
    if (cpu.flags.zf)
    {
        goto L_0x004958ee;
    }
    // 004958dd  833d90da4d0000         +cmp dword ptr [0x4dda90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102224) /* 0x4dda90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958e4  7410                   -je 0x4958f6
    if (cpu.flags.zf)
    {
        goto L_0x004958f6;
    }
    // 004958e6  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 004958eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004958ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004958ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004958ee:
    // 004958ee  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004958f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004958f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004958f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004958f6:
    // 004958f6  e865fa0000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 004958fb  e83032ffff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 00495900  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495902  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495904  7c7d                   -jl 0x495983
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495983;
    }
    // 00495906  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495907  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00495909  a25ccf4d00             -mov byte ptr [0x4dcf5c], al
    app->getMemory<x86::reg8>(x86::reg32(5099356) /* 0x4dcf5c */) = cpu.al;
    // 0049590e  c605dcce4d0001         -mov byte ptr [0x4dcedc], 1
    app->getMemory<x86::reg8>(x86::reg32(5099228) /* 0x4dcedc */) = 1 /*0x1*/;
    // 00495915  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00495917  893568ce4d00           -mov dword ptr [0x4dce68], esi
    app->getMemory<x86::reg32>(x86::reg32(5099112) /* 0x4dce68 */) = cpu.esi;
    // 0049591d  8a4208                 -mov al, byte ptr [edx + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00495920  a2dece4d00             -mov byte ptr [0x4dcede], al
    app->getMemory<x86::reg8>(x86::reg32(5099230) /* 0x4dcede */) = cpu.al;
    // 00495925  8a4207                 -mov al, byte ptr [edx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 00495928  a2dfce4d00             -mov byte ptr [0x4dcedf], al
    app->getMemory<x86::reg8>(x86::reg32(5099231) /* 0x4dcedf */) = cpu.al;
    // 0049592d  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 00495930  a2e0ce4d00             -mov byte ptr [0x4dcee0], al
    app->getMemory<x86::reg8>(x86::reg32(5099232) /* 0x4dcee0 */) = cpu.al;
    // 00495935  8a420a                 -mov al, byte ptr [edx + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 00495938  a2e1ce4d00             -mov byte ptr [0x4dcee1], al
    app->getMemory<x86::reg8>(x86::reg32(5099233) /* 0x4dcee1 */) = cpu.al;
    // 0049593d  891d58ce4d00           -mov dword ptr [0x4dce58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */) = cpu.ebx;
    // 00495943  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00495945  8815d8ce4d00           -mov byte ptr [0x4dced8], dl
    app->getMemory<x86::reg8>(x86::reg32(5099224) /* 0x4dced8 */) = cpu.dl;
    // 0049594b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0049594d  8835e5ce4d00           -mov byte ptr [0x4dcee5], dh
    app->getMemory<x86::reg8>(x86::reg32(5099237) /* 0x4dcee5 */) = cpu.dh;
    // 00495953  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00495955  881de6ce4d00           -mov byte ptr [0x4dcee6], bl
    app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */) = cpu.bl;
    // 0049595b  c705f0ce4d000f000000   -mov dword ptr [0x4dcef0], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5099248) /* 0x4dcef0 */) = 15 /*0xf*/;
    // 00495965  c605e7ce4d00ff         -mov byte ptr [0x4dcee7], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */) = 255 /*0xff*/;
    // 0049596c  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0049596e  a2e8ce4d00             -mov byte ptr [0x4dcee8], al
    app->getMemory<x86::reg8>(x86::reg32(5099240) /* 0x4dcee8 */) = cpu.al;
    // 00495973  e8d40c0000             -call 0x49664c
    cpu.esp -= 4;
    sub_49664c(app, cpu);
    if (cpu.terminate) return;
    // 00495978  e8f7f90000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049597d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049597f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495980  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495981  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495982  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495983:
    // 00495983  e8ecf90000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495988  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049598a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049598b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049598c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495990  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495991  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495993  e8c8f60000             -call 0x4a5060
    cpu.esp -= 4;
    sub_4a5060(app, cpu);
    if (cpu.terminate) return;
    // 00495998  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0049599f  7410                   -je 0x4959b1
    if (cpu.flags.zf)
    {
        goto L_0x004959b1;
    }
    // 004959a1  833d90da4d0000         +cmp dword ptr [0x4dda90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102224) /* 0x4dda90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004959a8  750e                   -jne 0x4959b8
    if (!cpu.flags.zf)
    {
        goto L_0x004959b8;
    }
    // 004959aa  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 004959af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004959b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004959b1:
    // 004959b1  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004959b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004959b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004959b8:
    // 004959b8  e86f010000             -call 0x495b2c
    cpu.esp -= 4;
    sub_495b2c(app, cpu);
    if (cpu.terminate) return;
    // 004959bd  803de4ce4d0000         +cmp byte ptr [0x4dcee4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099236) /* 0x4dcee4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004959c4  7412                   -je 0x4959d8
    if (cpu.flags.zf)
    {
        goto L_0x004959d8;
    }
    // 004959c6  b814634900             -mov eax, 0x496314
    cpu.eax = 4809492 /*0x496314*/;
    // 004959cb  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004959cd  e892e4feff             -call 0x483e64
    cpu.esp -= 4;
    sub_483e64(app, cpu);
    if (cpu.terminate) return;
    // 004959d2  8835e4ce4d00           -mov byte ptr [0x4dcee4], dh
    app->getMemory<x86::reg8>(x86::reg32(5099236) /* 0x4dcee4 */) = cpu.dh;
L_0x004959d8:
    // 004959d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004959d9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004959db  890d90da4d00           -mov dword ptr [0x4dda90], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102224) /* 0x4dda90 */) = cpu.ecx;
    // 004959e1  e84a31ffff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 004959e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004959e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004959e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004959ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4959ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004959ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004959ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004959ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004959ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004959f1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004959f3  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 004959f9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004959fb  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004959fd  750b                   -jne 0x495a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00495a0a;
    }
    // 004959ff  bff6ffffff             -mov edi, 0xfffffff6
    cpu.edi = 4294967286 /*0xfffffff6*/;
    // 00495a04  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495a06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495a0a:
    // 00495a0a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495a0b  e850f90000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00495a10  803dd9ce4d0000         +cmp byte ptr [0x4dced9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495a17  7567                   -jne 0x495a80
    if (!cpu.flags.zf)
    {
        goto L_0x00495a80;
    }
    // 00495a19  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495a1b  7549                   -jne 0x495a66
    if (!cpu.flags.zf)
    {
        goto L_0x00495a66;
    }
    // 00495a1d  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495a22  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495a24  e8e3e1ffff             -call 0x493c0c
    cpu.esp -= 4;
    sub_493c0c(app, cpu);
    if (cpu.terminate) return;
L_0x00495a29:
    // 00495a29  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 00495a2b  e81c0c0000             -call 0x49664c
    cpu.esp -= 4;
    sub_49664c(app, cpu);
    if (cpu.terminate) return;
    // 00495a30  8835d9ce4d00           -mov byte ptr [0x4dced9], dh
    app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */) = cpu.dh;
L_0x00495a36:
    // 00495a36  a0e5ce4d00             -mov al, byte ptr [0x4dcee5]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099237) /* 0x4dcee5 */);
    // 00495a3b  fe05e5ce4d00           -inc byte ptr [0x4dcee5]
    (app->getMemory<x86::reg8>(x86::reg32(5099237) /* 0x4dcee5 */))++;
    // 00495a41  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00495a46  b85ccf4d00             -mov eax, 0x4dcf5c
    cpu.eax = 5099356 /*0x4dcf5c*/;
    // 00495a4b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495a4d  e88a0affff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 00495a52  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 00495a54  883ddbcf4d00           -mov byte ptr [0x4dcfdb], bh
    app->getMemory<x86::reg8>(x86::reg32(5099483) /* 0x4dcfdb */) = cpu.bh;
    // 00495a5a  e815f90000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495a5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495a62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495a66:
    // 00495a66  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495a6b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495a6d  e81ae2ffff             -call 0x493c8c
    cpu.esp -= 4;
    sub_493c8c(app, cpu);
    if (cpu.terminate) return;
    // 00495a72  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495a77  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00495a79  e86ee2ffff             -call 0x493cec
    cpu.esp -= 4;
    sub_493cec(app, cpu);
    if (cpu.terminate) return;
    // 00495a7e  eba9                   -jmp 0x495a29
    goto L_0x00495a29;
L_0x00495a80:
    // 00495a80  0fbe15e5ce4d00         -movsx edx, byte ptr [0x4dcee5]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099237) /* 0x4dcee5 */)));
    // 00495a87  0fbe05e6ce4d00         -movsx eax, byte ptr [0x4dcee6]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */)));
    // 00495a8e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495a90  83f813                 +cmp eax, 0x13
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
    // 00495a93  7c11                   -jl 0x495aa6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495aa6;
    }
    // 00495a95  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 00495a9a  e8d5f80000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495a9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495aa0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495aa2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495aa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495aa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495aa5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495aa6:
    // 00495aa6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00495aa8  7530                   -jne 0x495ada
    if (!cpu.flags.zf)
    {
        goto L_0x00495ada;
    }
    // 00495aaa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495aaf  e8bcfbffff             -call 0x495670
    cpu.esp -= 4;
    sub_495670(app, cpu);
    if (cpu.terminate) return;
    // 00495ab4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495ab6  7511                   -jne 0x495ac9
    if (!cpu.flags.zf)
    {
        goto L_0x00495ac9;
    }
    // 00495ab8  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 00495abd  e8b2f80000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495ac2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ac3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495ac5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ac6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ac7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ac8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495ac9:
    // 00495ac9  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495ace  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495ad0  e807e1ffff             -call 0x493bdc
    cpu.esp -= 4;
    sub_493bdc(app, cpu);
    if (cpu.terminate) return;
    // 00495ad5  e95cffffff             -jmp 0x495a36
    goto L_0x00495a36;
L_0x00495ada:
    // 00495ada  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00495adf  e88cfbffff             -call 0x495670
    cpu.esp -= 4;
    sub_495670(app, cpu);
    if (cpu.terminate) return;
    // 00495ae4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495ae6  7511                   -jne 0x495af9
    if (!cpu.flags.zf)
    {
        goto L_0x00495af9;
    }
    // 00495ae8  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 00495aed  e882f80000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495af2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495af3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495af5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495af6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495af7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495af8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495af9:
    // 00495af9  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00495afe  b85ccf4d00             -mov eax, 0x4dcf5c
    cpu.eax = 5099356 /*0x4dcf5c*/;
    // 00495b03  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495b05  e8365effff             -call 0x48b940
    cpu.esp -= 4;
    sub_48b940(app, cpu);
    if (cpu.terminate) return;
    // 00495b0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495b0c  740c                   -je 0x495b1a
    if (cpu.flags.zf)
    {
        goto L_0x00495b1a;
    }
    // 00495b0e  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495b13  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00495b15  e842e1ffff             -call 0x493c5c
    cpu.esp -= 4;
    sub_493c5c(app, cpu);
    if (cpu.terminate) return;
L_0x00495b1a:
    // 00495b1a  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495b1f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00495b21  e8c6e1ffff             -call 0x493cec
    cpu.esp -= 4;
    sub_493cec(app, cpu);
    if (cpu.terminate) return;
    // 00495b26  e90bffffff             -jmp 0x495a36
    goto L_0x00495a36;
}

/* align: skip 0x90 */
void Application::sub_495b2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495b2c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495b2d  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 00495b34  7507                   -jne 0x495b3d
    if (!cpu.flags.zf)
    {
        goto L_0x00495b3d;
    }
    // 00495b36  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00495b3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495b3d:
    // 00495b3d  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 00495b42  e8f93cffff             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
    // 00495b47  8b1508c65900           -mov edx, dword ptr [0x59c608]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5883400) /* 0x59c608 */);
    // 00495b4d  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
L_0x00495b53:
    // 00495b53  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 00495b58  e8e304ffff             -call 0x486040
    cpu.esp -= 4;
    sub_486040(app, cpu);
    if (cpu.terminate) return;
    // 00495b5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495b5f  7516                   -jne 0x495b77
    if (!cpu.flags.zf)
    {
        goto L_0x00495b77;
    }
    // 00495b61  3b1508c65900           +cmp edx, dword ptr [0x59c608]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5883400) /* 0x59c608 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b67  7207                   -jb 0x495b70
    if (cpu.flags.cf)
    {
        goto L_0x00495b70;
    }
    // 00495b69  e842e3feff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00495b6e  ebe3                   -jmp 0x495b53
    goto L_0x00495b53;
L_0x00495b70:
    // 00495b70  b8efffffff             -mov eax, 0xffffffef
    cpu.eax = 4294967279 /*0xffffffef*/;
    // 00495b75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495b77:
    // 00495b77  e8e4f70000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00495b7c  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 00495b7e  e869020000             -call 0x495dec
    cpu.esp -= 4;
    sub_495dec(app, cpu);
    if (cpu.terminate) return;
    // 00495b83  8815e7ce4d00           -mov byte ptr [0x4dcee7], dl
    app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */) = cpu.dl;
    // 00495b89  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00495b8b  8835e8ce4d00           -mov byte ptr [0x4dcee8], dh
    app->getMemory<x86::reg8>(x86::reg32(5099240) /* 0x4dcee8 */) = cpu.dh;
    // 00495b91  8835e5ce4d00           -mov byte ptr [0x4dcee5], dh
    app->getMemory<x86::reg8>(x86::reg32(5099237) /* 0x4dcee5 */) = cpu.dh;
    // 00495b97  8835e6ce4d00           -mov byte ptr [0x4dcee6], dh
    app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */) = cpu.dh;
    // 00495b9d  8835d9ce4d00           -mov byte ptr [0x4dced9], dh
    app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */) = cpu.dh;
    // 00495ba3  88355ccf4d00           -mov byte ptr [0x4dcf5c], dh
    app->getMemory<x86::reg8>(x86::reg32(5099356) /* 0x4dcf5c */) = cpu.dh;
    // 00495ba9  8835d8ce4d00           -mov byte ptr [0x4dced8], dh
    app->getMemory<x86::reg8>(x86::reg32(5099224) /* 0x4dced8 */) = cpu.dh;
    // 00495baf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495bb1  e8aaf40000             -call 0x4a5060
    cpu.esp -= 4;
    sub_4a5060(app, cpu);
    if (cpu.terminate) return;
    // 00495bb6  803de4ce4d0000         +cmp byte ptr [0x4dcee4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099236) /* 0x4dcee4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495bbd  7410                   -je 0x495bcf
    if (cpu.flags.zf)
    {
        goto L_0x00495bcf;
    }
    // 00495bbf  b814634900             -mov eax, 0x496314
    cpu.eax = 4809492 /*0x496314*/;
    // 00495bc4  e89be2feff             -call 0x483e64
    cpu.esp -= 4;
    sub_483e64(app, cpu);
    if (cpu.terminate) return;
    // 00495bc9  8835e4ce4d00           -mov byte ptr [0x4dcee4], dh
    app->getMemory<x86::reg8>(x86::reg32(5099236) /* 0x4dcee4 */) = cpu.dh;
L_0x00495bcf:
    // 00495bcf  e8a0f70000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495bd4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495bd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495bd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495bd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495bd8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495bd9  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 00495bdf  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 00495be4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00495be6  7509                   -jne 0x495bf1
    if (!cpu.flags.zf)
    {
        goto L_0x00495bf1;
    }
    // 00495be8  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 00495bed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495bef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495bf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495bf1:
    // 00495bf1  e86af70000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00495bf6  803dd9ce4d0000         +cmp byte ptr [0x4dced9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495bfd  741e                   -je 0x495c1d
    if (cpu.flags.zf)
    {
        goto L_0x00495c1d;
    }
    // 00495bff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495c01  a0dbce4d00             -mov al, byte ptr [0x4dcedb]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099227) /* 0x4dcedb */);
    // 00495c06  e8252fffff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 00495c0b  8b1574ce4d00           -mov edx, dword ptr [0x4dce74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */);
    // 00495c11  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00495c13  803de9ce4d0002         +cmp byte ptr [0x4dcee9], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495c1a  7501                   -jne 0x495c1d
    if (!cpu.flags.zf)
    {
        goto L_0x00495c1d;
    }
    // 00495c1c  4a                     -dec edx
    (cpu.edx)--;
L_0x00495c1d:
    // 00495c1d  e852f70000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495c22  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495c24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495c28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495c28  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 00495c2f  7506                   -jne 0x495c37
    if (!cpu.flags.zf)
    {
        goto L_0x00495c37;
    }
    // 00495c31  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00495c36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495c37:
    // 00495c37  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495c38  e823f70000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00495c3d  803dd9ce4d0000         +cmp byte ptr [0x4dced9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495c44  750e                   -jne 0x495c54
    if (!cpu.flags.zf)
    {
        goto L_0x00495c54;
    }
L_0x00495c46:
    // 00495c46  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 00495c4b  e824f70000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495c50  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495c52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495c54:
    // 00495c54  803dd9ce4d0001         +cmp byte ptr [0x4dced9], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495c5b  74e9                   -je 0x495c46
    if (cpu.flags.zf)
    {
        goto L_0x00495c46;
    }
    // 00495c5d  803ddbce4d0000         +cmp byte ptr [0x4dcedb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099227) /* 0x4dcedb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495c64  750e                   -jne 0x495c74
    if (!cpu.flags.zf)
    {
        goto L_0x00495c74;
    }
    // 00495c66  baf9ffffff             -mov edx, 0xfffffff9
    cpu.edx = 4294967289 /*0xfffffff9*/;
    // 00495c6b  e804f70000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495c70  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495c72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495c74:
    // 00495c74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495c75  e85effffff             -call 0x495bd8
    cpu.esp -= 4;
    sub_495bd8(app, cpu);
    if (cpu.terminate) return;
    // 00495c7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495c7c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00495c7f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00495c81  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00495c84  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495c86  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00495c89  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495c8b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00495c8e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495c90  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00495c92  8a0ddbce4d00           -mov cl, byte ptr [0x4dcedb]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5099227) /* 0x4dcedb */);
    // 00495c98  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495c9a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00495c9d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00495c9f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495ca1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ca2  e8cdf60000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495ca7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495ca9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495caa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495cac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495cad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495caf  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 00495cb6  7404                   -je 0x495cbc
    if (cpu.flags.zf)
    {
        goto L_0x00495cbc;
    }
    // 00495cb8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495cba  7f02                   -jg 0x495cbe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495cbe;
    }
L_0x00495cbc:
    // 00495cbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495cbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495cbe:
    // 00495cbe  e8b5e2feff             -call 0x483f78
    cpu.esp -= 4;
    sub_483f78(app, cpu);
    if (cpu.terminate) return;
    // 00495cc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495cc5  7509                   -jne 0x495cd0
    if (!cpu.flags.zf)
    {
        goto L_0x00495cd0;
    }
    // 00495cc7  e85cffffff             -call 0x495c28
    cpu.esp -= 4;
    sub_495c28(app, cpu);
    if (cpu.terminate) return;
    // 00495ccc  39d0                   +cmp eax, edx
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
    // 00495cce  7d47                   -jge 0x495d17
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495d17;
    }
L_0x00495cd0:
    // 00495cd0  e857f8ffff             -call 0x49552c
    cpu.esp -= 4;
    sub_49552c(app, cpu);
    if (cpu.terminate) return;
    // 00495cd5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495cd7  753e                   -jne 0x495d17
    if (!cpu.flags.zf)
    {
        goto L_0x00495d17;
    }
    // 00495cd9  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495cde  e8a1f8ffff             -call 0x495584
    cpu.esp -= 4;
    sub_495584(app, cpu);
    if (cpu.terminate) return;
    // 00495ce3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495ce5  7417                   -je 0x495cfe
    if (cpu.flags.zf)
    {
        goto L_0x00495cfe;
    }
    // 00495ce7  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495cec  e823f8ffff             -call 0x495514
    cpu.esp -= 4;
    sub_495514(app, cpu);
    if (cpu.terminate) return;
    // 00495cf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495cf3  7509                   -jne 0x495cfe
    if (!cpu.flags.zf)
    {
        goto L_0x00495cfe;
    }
    // 00495cf5  e87ee2feff             -call 0x483f78
    cpu.esp -= 4;
    sub_483f78(app, cpu);
    if (cpu.terminate) return;
    // 00495cfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495cfc  741e                   -je 0x495d1c
    if (cpu.flags.zf)
    {
        goto L_0x00495d1c;
    }
L_0x00495cfe:
    // 00495cfe  891548cf4d00           -mov dword ptr [0x4dcf48], edx
    app->getMemory<x86::reg32>(x86::reg32(5099336) /* 0x4dcf48 */) = cpu.edx;
    // 00495d04  833de0cf4d0000         +cmp dword ptr [0x4dcfe0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d0b  74af                   -je 0x495cbc
    if (cpu.flags.zf)
    {
        goto L_0x00495cbc;
    }
    // 00495d0d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495d0f  ff15e0cf4d00           -call dword ptr [0x4dcfe0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495d15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d17:
    // 00495d17  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00495d1c:
    // 00495d1c  e8d7f30000             -call 0x4a50f8
    cpu.esp -= 4;
    sub_4a50f8(app, cpu);
    if (cpu.terminate) return;
    // 00495d21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495d24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495d24  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495d25  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495d26  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495d28  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 00495d2e  b9f1ffffff             -mov ecx, 0xfffffff1
    cpu.ecx = 4294967281 /*0xfffffff1*/;
    // 00495d33  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00495d35  750a                   -jne 0x495d41
    if (!cpu.flags.zf)
    {
        goto L_0x00495d41;
    }
    // 00495d37  b9f6ffffff             -mov ecx, 0xfffffff6
    cpu.ecx = 4294967286 /*0xfffffff6*/;
    // 00495d3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495d3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d41:
    // 00495d41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495d42  e819f60000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00495d47  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00495d49  81fb5343446c           +cmp ebx, 0x6c444353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816413011 /*0x6c444353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d4f  7514                   -jne 0x495d65
    if (!cpu.flags.zf)
    {
        goto L_0x00495d65;
    }
    // 00495d51  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495d53  e814010000             -call 0x495e6c
    cpu.esp -= 4;
    sub_495e6c(app, cpu);
    if (cpu.terminate) return;
    // 00495d58  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495d5a  e815f60000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495d5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d60  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495d62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d65:
    // 00495d65  81fb5343486c           +cmp ebx, 0x6c484353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816675155 /*0x6c484353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d6b  742c                   -je 0x495d99
    if (cpu.flags.zf)
    {
        goto L_0x00495d99;
    }
    // 00495d6d  81fb5343436c           +cmp ebx, 0x6c434353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816347475 /*0x6c434353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d73  7438                   -je 0x495dad
    if (cpu.flags.zf)
    {
        goto L_0x00495dad;
    }
    // 00495d75  81fb53434c6c           +cmp ebx, 0x6c4c4353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816937299 /*0x6c4c4353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d7b  7444                   -je 0x495dc1
    if (cpu.flags.zf)
    {
        goto L_0x00495dc1;
    }
    // 00495d7d  81fb5343456c           +cmp ebx, 0x6c454353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816478547 /*0x6c454353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d83  7550                   -jne 0x495dd5
    if (!cpu.flags.zf)
    {
        goto L_0x00495dd5;
    }
    // 00495d85  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495d87  e8d0020000             -call 0x49605c
    cpu.esp -= 4;
    sub_49605c(app, cpu);
    if (cpu.terminate) return;
    // 00495d8c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495d8e  e8e1f50000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495d93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d94  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495d96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d99:
    // 00495d99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495d9b  e820010000             -call 0x495ec0
    cpu.esp -= 4;
    sub_495ec0(app, cpu);
    if (cpu.terminate) return;
    // 00495da0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495da2  e8cdf50000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495da7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495da8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495daa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495dad:
    // 00495dad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495daf  e814020000             -call 0x495fc8
    cpu.esp -= 4;
    sub_495fc8(app, cpu);
    if (cpu.terminate) return;
    // 00495db4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495db6  e8b9f50000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495dbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dbc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495dbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495dc1:
    // 00495dc1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495dc3  e86c020000             -call 0x496034
    cpu.esp -= 4;
    sub_496034(app, cpu);
    if (cpu.terminate) return;
    // 00495dc8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495dca  e8a5f50000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495dcf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dd0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495dd2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dd3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495dd4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495dd5:
    // 00495dd5  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495dda  e821f7ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 00495ddf  e890f50000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495de4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495de5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495de7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495de8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495de9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495dec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495dec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495ded  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495dee  e86df50000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00495df3  833d5cce4d0000         +cmp dword ptr [0x4dce5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495dfa  7454                   -je 0x495e50
    if (cpu.flags.zf)
    {
        goto L_0x00495e50;
    }
L_0x00495dfc:
    // 00495dfc  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00495e01  3b0560ce4d00           +cmp eax, dword ptr [0x4dce60]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e07  741e                   -je 0x495e27
    if (cpu.flags.zf)
    {
        goto L_0x00495e27;
    }
    // 00495e09  8b155cce4d00           -mov edx, dword ptr [0x4dce5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00495e0f  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00495e14  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00495e16  a35cce4d00             -mov dword ptr [0x4dce5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */) = cpu.eax;
    // 00495e1b  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495e20  e8dbf6ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 00495e25  ebd5                   -jmp 0x495dfc
    goto L_0x00495dfc;
L_0x00495e27:
    // 00495e27  8b155cce4d00           -mov edx, dword ptr [0x4dce5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00495e2d  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495e32  e8c9f6ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 00495e37  833d64ce4d0000         +cmp dword ptr [0x4dce64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e3e  7410                   -je 0x495e50
    if (cpu.flags.zf)
    {
        goto L_0x00495e50;
    }
    // 00495e40  8b1564ce4d00           -mov edx, dword ptr [0x4dce64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */);
    // 00495e46  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495e4b  e8b0f6ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
L_0x00495e50:
    // 00495e50  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00495e52  89355cce4d00           -mov dword ptr [0x4dce5c], esi
    app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */) = cpu.esi;
    // 00495e58  893560ce4d00           -mov dword ptr [0x4dce60], esi
    app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */) = cpu.esi;
    // 00495e5e  893564ce4d00           -mov dword ptr [0x4dce64], esi
    app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */) = cpu.esi;
    // 00495e64  e80bf50000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00495e69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495e6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495e6d  8b1574ce4d00           -mov edx, dword ptr [0x4dce74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */);
    // 00495e73  ff0574ce4d00           -inc dword ptr [0x4dce74]
    (app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */))++;
    // 00495e79  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495e7c  011578ce4d00           -add dword ptr [0x4dce78], edx
    (app->getMemory<x86::reg32>(x86::reg32(5099128) /* 0x4dce78 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495e82  8338ff                 +cmp dword ptr [eax], -1
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
    // 00495e85  751a                   -jne 0x495ea1
    if (!cpu.flags.zf)
    {
        goto L_0x00495ea1;
    }
L_0x00495e87:
    // 00495e87  833d5cce4d0000         +cmp dword ptr [0x4dce5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495e8e  7519                   -jne 0x495ea9
    if (!cpu.flags.zf)
    {
        goto L_0x00495ea9;
    }
    // 00495e90  a35cce4d00             -mov dword ptr [0x4dce5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */) = cpu.eax;
    // 00495e95  a360ce4d00             -mov dword ptr [0x4dce60], eax
    app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */) = cpu.eax;
    // 00495e9a  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00495e9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ea0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495ea1:
    // 00495ea1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00495ea7  ebde                   -jmp 0x495e87
    goto L_0x00495e87;
L_0x00495ea9:
    // 00495ea9  8b1560ce4d00           -mov edx, dword ptr [0x4dce60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */);
    // 00495eaf  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00495eb1  a360ce4d00             -mov dword ptr [0x4dce60], eax
    app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */) = cpu.eax;
    // 00495eb6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00495ebb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ebc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495ec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495ec2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495ec3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495ec4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495ec5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495ec6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00495ec9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00495ecb  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00495ed0  803de7ce4d0000         +cmp byte ptr [0x4dcee7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495ed7  7e0b                   -jle 0x495ee4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495ee4;
    }
    // 00495ed9  a0e7ce4d00             -mov al, byte ptr [0x4dcee7]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */);
    // 00495ede  fe0de7ce4d00           -dec byte ptr [0x4dcee7]
    (app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */))--;
L_0x00495ee4:
    // 00495ee4  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00495ee7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495ee9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00495eed  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00495eef  803ddcce4d0000         +cmp byte ptr [0x4dcedc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099228) /* 0x4dcedc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495ef6  7551                   -jne 0x495f49
    if (!cpu.flags.zf)
    {
        goto L_0x00495f49;
    }
L_0x00495ef8:
    // 00495ef8  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495efc  bf7cce4d00             -mov edi, 0x4dce7c
    cpu.edi = 5099132 /*0x4dce7c*/;
    // 00495f01  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00495f03  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00495f08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495f09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495f0b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00495f0e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00495f10  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00495f12  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00495f15  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00495f17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f18  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00495f1a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00495f1d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495f1f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495f21  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00495f23  e8f8ec0000             -call 0x4a4c20
    cpu.esp -= 4;
    sub_4a4c20(app, cpu);
    if (cpu.terminate) return;
    // 00495f28  882dd8ce4d00           -mov byte ptr [0x4dced8], ch
    app->getMemory<x86::reg8>(x86::reg32(5099224) /* 0x4dced8 */) = cpu.ch;
    // 00495f2e  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00495f33  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00495f35  e8c6f5ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 00495f3a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495f3f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00495f42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495f49:
    // 00495f49  a0e6ce4d00             -mov al, byte ptr [0x4dcee6]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */);
    // 00495f4e  fe05e6ce4d00           -inc byte ptr [0x4dcee6]
    (app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */))++;
    // 00495f54  a0e5ce4d00             -mov al, byte ptr [0x4dcee5]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099237) /* 0x4dcee5 */);
    // 00495f59  fe0de5ce4d00           -dec byte ptr [0x4dcee5]
    (app->getMemory<x86::reg8>(x86::reg32(5099237) /* 0x4dcee5 */))--;
    // 00495f5f  bf4ccf4d00             -mov edi, 0x4dcf4c
    cpu.edi = 5099340 /*0x4dcf4c*/;
    // 00495f64  be54cf4d00             -mov esi, 0x4dcf54
    cpu.esi = 5099348 /*0x4dcf54*/;
    // 00495f69  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00495f6a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00495f6b  ba54cf4d00             -mov edx, 0x4dcf54
    cpu.edx = 5099348 /*0x4dcf54*/;
    // 00495f70  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495f72  e8c9750100             -call 0x4ad540
    cpu.esp -= 4;
    sub_4ad540(app, cpu);
    if (cpu.terminate) return;
    // 00495f77  803de8ce4d0000         +cmp byte ptr [0x4dcee8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099240) /* 0x4dcee8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495f7e  743c                   -je 0x495fbc
    if (cpu.flags.zf)
    {
        goto L_0x00495fbc;
    }
    // 00495f80  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00495f85  bf4ccf4d00             -mov edi, 0x4dcf4c
    cpu.edi = 5099340 /*0x4dcf4c*/;
    // 00495f8a  be54cf4d00             -mov esi, 0x4dcf54
    cpu.esi = 5099348 /*0x4dcf54*/;
    // 00495f8f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00495f91  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 00495f93  7405                   -je 0x495f9a
    if (cpu.flags.zf)
    {
        goto L_0x00495f9a;
    }
    // 00495f95  19c0                   +sbb eax, eax
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
    // 00495f97  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00495f9a:
    // 00495f9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495f9c  741e                   -je 0x495fbc
    if (cpu.flags.zf)
    {
        goto L_0x00495fbc;
    }
    // 00495f9e  803dd9ce4d0002         +cmp byte ptr [0x4dced9], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495fa5  740e                   -je 0x495fb5
    if (cpu.flags.zf)
    {
        goto L_0x00495fb5;
    }
    // 00495fa7  803dd9ce4d0003         +cmp byte ptr [0x4dced9], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495fae  7405                   -je 0x495fb5
    if (cpu.flags.zf)
    {
        goto L_0x00495fb5;
    }
    // 00495fb0  e84b070000             -call 0x496700
    cpu.esp -= 4;
    sub_496700(app, cpu);
    if (cpu.terminate) return;
L_0x00495fb5:
    // 00495fb5  c605d9ce4d0003         -mov byte ptr [0x4dced9], 3
    app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */) = 3 /*0x3*/;
L_0x00495fbc:
    // 00495fbc  c605e8ce4d0001         -mov byte ptr [0x4dcee8], 1
    app->getMemory<x86::reg8>(x86::reg32(5099240) /* 0x4dcee8 */) = 1 /*0x1*/;
    // 00495fc3  e930ffffff             -jmp 0x495ef8
    goto L_0x00495ef8;
}

/* align: skip  */
void Application::sub_495fc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495fc9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495fca  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00495fcd  8a0deace4d00           -mov cl, byte ptr [0x4dceea]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */);
    // 00495fd3  3a0debce4d00           +cmp cl, byte ptr [0x4dceeb]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495fd9  7511                   -jne 0x495fec
    if (!cpu.flags.zf)
    {
        goto L_0x00495fec;
    }
    // 00495fdb  0fbe0deace4d00         -movsx ecx, byte ptr [0x4dceea]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */)));
    // 00495fe2  833c8df8ce4d0000       +cmp dword ptr [ecx*4 + 0x4dcef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.ecx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495fea  7e0c                   -jle 0x495ff8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495ff8;
    }
L_0x00495fec:
    // 00495fec  8a0debce4d00           -mov cl, byte ptr [0x4dceeb]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */);
    // 00495ff2  fe05ebce4d00           -inc byte ptr [0x4dceeb]
    (app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */))++;
L_0x00495ff8:
    // 00495ff8  803debce4d0014         +cmp byte ptr [0x4dceeb], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495fff  7c0a                   -jl 0x49600b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049600b;
    }
    // 00496001  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496002  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00496004  881debce4d00           -mov byte ptr [0x4dceeb], bl
    app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */) = cpu.bl;
    // 0049600a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049600b:
    // 0049600b  0fbe0debce4d00         -movsx ecx, byte ptr [0x4dceeb]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */)));
    // 00496012  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00496014  89148df8ce4d00         -mov dword ptr [ecx*4 + 0x4dcef8], edx
    app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.ecx * 4) = cpu.edx;
    // 0049601b  8b0d58ce4d00           -mov ecx, dword ptr [0x4dce58]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00496021  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496023  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496025  e8d6f4ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 0049602a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049602f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496030  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496031  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_496034(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496034  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496035  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496036  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496038  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049603b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049603d  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00496042  e86ddcffff             -call 0x493cb4
    cpu.esp -= 4;
    sub_493cb4(app, cpu);
    if (cpu.terminate) return;
    // 00496047  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049604c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049604e  e8adf4ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 00496053  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00496058  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496059  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049605a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49605c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049605c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049605d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049605e  ff0554ce4d00           -inc dword ptr [0x4dce54]
    (app->getMemory<x86::reg32>(x86::reg32(5099092) /* 0x4dce54 */))++;
    // 00496064  803ddace4d0000         +cmp byte ptr [0x4dceda], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099226) /* 0x4dceda */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049606b  750c                   -jne 0x496079
    if (!cpu.flags.zf)
    {
        goto L_0x00496079;
    }
    // 0049606d  8b0d60ce4d00           -mov ecx, dword ptr [0x4dce60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */);
    // 00496073  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
L_0x00496079:
    // 00496079  8b0d58ce4d00           -mov ecx, dword ptr [0x4dce58]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049607f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496081  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496083  e878f4ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 00496088  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049608d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049608e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049608f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496090  a154ce4d00             -mov eax, dword ptr [0x4dce54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099092) /* 0x4dce54 */);
    // 00496095  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_496098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496098  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496099  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049609a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049609b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049609c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049609d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049609f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004960a1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004960a3  803de9ce4d0002         +cmp byte ptr [0x4dcee9], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004960aa  0f850e010000           -jne 0x4961be
    if (!cpu.flags.zf)
    {
        goto L_0x004961be;
    }
L_0x004960b0:
    // 004960b0  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 004960b5  3b0560ce4d00           +cmp eax, dword ptr [0x4dce60]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004960bb  0f8482000000           -je 0x496143
    if (cpu.flags.zf)
    {
        goto L_0x00496143;
    }
    // 004960c1  8b3d5cce4d00           -mov edi, dword ptr [0x4dce5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 004960c7  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 004960cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004960ce  a35cce4d00             -mov dword ptr [0x4dce5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */) = cpu.eax;
    // 004960d3  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004960d6  833d64ce4d0000         +cmp dword ptr [0x4dce64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004960dd  7410                   -je 0x4960ef
    if (cpu.flags.zf)
    {
        goto L_0x004960ef;
    }
    // 004960df  8b1564ce4d00           -mov edx, dword ptr [0x4dce64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */);
    // 004960e5  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 004960ea  e811f4ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
L_0x004960ef:
    // 004960ef  893d64ce4d00           -mov dword ptr [0x4dce64], edi
    app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */) = cpu.edi;
    // 004960f5  a174ce4d00             -mov eax, dword ptr [0x4dce74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */);
    // 004960fa  ff0d74ce4d00           -dec dword ptr [0x4dce74]
    (app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */))--;
    // 00496100  292d78ce4d00           -sub dword ptr [0x4dce78], ebp
    (app->getMemory<x86::reg32>(x86::reg32(5099128) /* 0x4dce78 */)) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496106  a170ce4d00             -mov eax, dword ptr [0x4dce70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099120) /* 0x4dce70 */);
    // 0049610b  ff0570ce4d00           -inc dword ptr [0x4dce70]
    (app->getMemory<x86::reg32>(x86::reg32(5099120) /* 0x4dce70 */))++;
    // 00496111  0fbe05eace4d00         -movsx eax, byte ptr [0x4dceea]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */)));
    // 00496118  8b1485f8ce4d00         -mov edx, dword ptr [eax*4 + 0x4dcef8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.eax * 4);
    // 0049611f  ff0c85f8ce4d00         -dec dword ptr [eax*4 + 0x4dcef8]
    (app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.eax * 4))--;
    // 00496126  0fbe05eace4d00         -movsx eax, byte ptr [0x4dceea]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */)));
    // 0049612d  833c85f8ce4d0000       +cmp dword ptr [eax*4 + 0x4dcef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496135  0f8e95000000           -jle 0x4961d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004961d0;
    }
L_0x0049613b:
    // 0049613b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049613d  8825e9ce4d00           -mov byte ptr [0x4dcee9], ah
    app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */) = cpu.ah;
L_0x00496143:
    // 00496143  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496148  3b0560ce4d00           +cmp eax, dword ptr [0x4dce60]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049614e  0f85e0000000           -jne 0x496234
    if (!cpu.flags.zf)
    {
        goto L_0x00496234;
    }
    // 00496154  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496159  8338ff                 +cmp dword ptr [eax], -1
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
    // 0049615c  0f84ae000000           -je 0x496210
    if (cpu.flags.zf)
    {
        goto L_0x00496210;
    }
    // 00496162  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496167  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049616a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049616c  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496171  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00496174  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00496176  803de9ce4d0001         +cmp byte ptr [0x4dcee9], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049617d  7519                   -jne 0x496198
    if (!cpu.flags.zf)
    {
        goto L_0x00496198;
    }
    // 0049617f  0fbe3dddce4d00         -movsx edi, byte ptr [0x4dcedd]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099229) /* 0x4dcedd */)));
    // 00496186  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00496188  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049618a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049618c  e84f35ffff             -call 0x4896e0
    cpu.esp -= 4;
    sub_4896e0(app, cpu);
    if (cpu.terminate) return;
    // 00496191  c605e9ce4d0002         -mov byte ptr [0x4dcee9], 2
    app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */) = 2 /*0x2*/;
L_0x00496198:
    // 00496198  803de9ce4d0000         +cmp byte ptr [0x4dcee9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049619f  7507                   -jne 0x4961a8
    if (!cpu.flags.zf)
    {
        goto L_0x004961a8;
    }
    // 004961a1  c605e9ce4d0001         -mov byte ptr [0x4dcee9], 1
    app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */) = 1 /*0x1*/;
L_0x004961a8:
    // 004961a8  803de9ce4d0002         +cmp byte ptr [0x4dcee9], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004961af  7505                   -jne 0x4961b6
    if (!cpu.flags.zf)
    {
        goto L_0x004961b6;
    }
    // 004961b1  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004961b6:
    // 004961b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004961b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004961be:
    // 004961be  803de9ce4d0001         +cmp byte ptr [0x4dcee9], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004961c5  0f84e5feffff           -je 0x4960b0
    if (cpu.flags.zf)
    {
        goto L_0x004960b0;
    }
    // 004961cb  e973ffffff             -jmp 0x496143
    goto L_0x00496143;
L_0x004961d0:
    // 004961d0  a0e6ce4d00             -mov al, byte ptr [0x4dcee6]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */);
    // 004961d5  fe0de6ce4d00           -dec byte ptr [0x4dcee6]
    (app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */))--;
    // 004961db  a0eace4d00             -mov al, byte ptr [0x4dceea]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */);
    // 004961e0  3a05ebce4d00           +cmp al, byte ptr [0x4dceeb]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004961e6  0f844fffffff           -je 0x49613b
    if (cpu.flags.zf)
    {
        goto L_0x0049613b;
    }
    // 004961ec  a0eace4d00             -mov al, byte ptr [0x4dceea]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */);
    // 004961f1  fe05eace4d00           -inc byte ptr [0x4dceea]
    (app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */))++;
    // 004961f7  803deace4d0014         +cmp byte ptr [0x4dceea], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004961fe  0f8c37ffffff           -jl 0x49613b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049613b;
    }
    // 00496204  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00496206  a2eace4d00             -mov byte ptr [0x4dceea], al
    app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */) = cpu.al;
    // 0049620b  e92bffffff             -jmp 0x49613b
    goto L_0x0049613b;
L_0x00496210:
    // 00496210  8b155cce4d00           -mov edx, dword ptr [0x4dce5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496216  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049621b  e8e0f2ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
    // 00496220  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00496226  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0049622c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049622e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049622f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496230  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496231  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496232  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496233  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496234:
    // 00496234  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496239  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049623c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049623e  8b1d5cce4d00           -mov ebx, dword ptr [0x4dce5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496244  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00496247  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496249  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049624b  a15cce4d00             -mov eax, dword ptr [0x4dce5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */);
    // 00496250  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496252  a35cce4d00             -mov dword ptr [0x4dce5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */) = cpu.eax;
    // 00496257  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049625a  833d64ce4d0000         +cmp dword ptr [0x4dce64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496261  7410                   -je 0x496273
    if (cpu.flags.zf)
    {
        goto L_0x00496273;
    }
    // 00496263  8b1564ce4d00           -mov edx, dword ptr [0x4dce64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */);
    // 00496269  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049626e  e88df2ffff             -call 0x495500
    cpu.esp -= 4;
    sub_495500(app, cpu);
    if (cpu.terminate) return;
L_0x00496273:
    // 00496273  891d64ce4d00           -mov dword ptr [0x4dce64], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099108) /* 0x4dce64 */) = cpu.ebx;
    // 00496279  a174ce4d00             -mov eax, dword ptr [0x4dce74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */);
    // 0049627e  ff0d74ce4d00           -dec dword ptr [0x4dce74]
    (app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */))--;
    // 00496284  290d78ce4d00           -sub dword ptr [0x4dce78], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5099128) /* 0x4dce78 */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049628a  a170ce4d00             -mov eax, dword ptr [0x4dce70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099120) /* 0x4dce70 */);
    // 0049628f  ff0570ce4d00           -inc dword ptr [0x4dce70]
    (app->getMemory<x86::reg32>(x86::reg32(5099120) /* 0x4dce70 */))++;
    // 00496295  0fbe05eace4d00         -movsx eax, byte ptr [0x4dceea]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */)));
    // 0049629c  8b1485f8ce4d00         -mov edx, dword ptr [eax*4 + 0x4dcef8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.eax * 4);
    // 004962a3  ff0c85f8ce4d00         -dec dword ptr [eax*4 + 0x4dcef8]
    (app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.eax * 4))--;
    // 004962aa  0fbe05eace4d00         -movsx eax, byte ptr [0x4dceea]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */)));
    // 004962b1  833c85f8ce4d0000       +cmp dword ptr [eax*4 + 0x4dcef8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004962b9  0f8ff7feffff           -jg 0x4961b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004961b6;
    }
    // 004962bf  a0e6ce4d00             -mov al, byte ptr [0x4dcee6]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */);
    // 004962c4  fe0de6ce4d00           -dec byte ptr [0x4dcee6]
    (app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */))--;
    // 004962ca  a0eace4d00             -mov al, byte ptr [0x4dceea]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */);
    // 004962cf  3a05ebce4d00           +cmp al, byte ptr [0x4dceeb]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004962d5  0f84dbfeffff           -je 0x4961b6
    if (cpu.flags.zf)
    {
        goto L_0x004961b6;
    }
    // 004962db  a0eace4d00             -mov al, byte ptr [0x4dceea]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */);
    // 004962e0  fe05eace4d00           -inc byte ptr [0x4dceea]
    (app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */))++;
    // 004962e6  803deace4d0014         +cmp byte ptr [0x4dceea], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004962ed  0f8cc3feffff           -jl 0x4961b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004961b6;
    }
    // 004962f3  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004962f5  880deace4d00           -mov byte ptr [0x4dceea], cl
    app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */) = cpu.cl;
    // 004962fb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004962fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004962ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496300  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496301  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496302  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_496314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00496314  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496315  e85edcfeff             -call 0x483f78
    cpu.esp -= 4;
    sub_483f78(app, cpu);
    if (cpu.terminate) return;
    // 0049631a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049631c  7404                   -je 0x496322
    if (cpu.flags.zf)
    {
        goto L_0x00496322;
    }
    // 0049631e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496320  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496321  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496322:
    // 00496322  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496323  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496324  e837f00000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00496329  a0d9ce4d00             -mov al, byte ptr [0x4dced9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
    // 0049632e  3c03                   +cmp al, 3
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
    // 00496330  770c                   -ja 0x49633e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 00496332  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00496337  ff248504634900         -jmp dword ptr [eax*4 + 0x496304]
    cpu.ip = app->getMemory<x86::reg32>(4809476 + cpu.eax * 4); goto dynamic_jump;
  case 0x0049633e:
L_0x0049633e:
    // 0049633e  e831f00000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00496343  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496345  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496346  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496347  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496348  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00496349:
    // 00496349  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049634b:
    // 0049634b  3a0ddcce4d00           +cmp cl, byte ptr [0x4dcedc]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5099228) /* 0x4dcedc */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00496351  750d                   -jne 0x496360
    if (!cpu.flags.zf)
    {
        goto L_0x00496360;
    }
    // 00496353  a1ecce4d00             -mov eax, dword ptr [0x4dceec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099244) /* 0x4dceec */);
    // 00496358  3b05f0ce4d00           +cmp eax, dword ptr [0x4dcef0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099248) /* 0x4dcef0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049635e  7dde                   -jge 0x49633e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049633e;
    }
L_0x00496360:
    // 00496360  3a0de7ce4d00           +cmp cl, byte ptr [0x4dcee7]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00496366  7526                   -jne 0x49638e
    if (!cpu.flags.zf)
    {
        goto L_0x0049638e;
    }
    // 00496368  833df4ce4d00ff         +cmp dword ptr [0x4dcef4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099252) /* 0x4dcef4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049636f  74cd                   -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 00496371  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00496376  e899f1ffff             -call 0x495514
    cpu.esp -= 4;
    sub_495514(app, cpu);
    if (cpu.terminate) return;
    // 0049637b  3b05f4ce4d00           +cmp eax, dword ptr [0x4dcef4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099252) /* 0x4dcef4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496381  0f8c8f000000           -jl 0x496416
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496416;
    }
L_0x00496387:
    // 00496387  c605e7ce4d00ff         -mov byte ptr [0x4dcee7], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */) = 255 /*0xff*/;
L_0x0049638e:
    // 0049638e  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 00496393  e844f0ffff             -call 0x4953dc
    cpu.esp -= 4;
    sub_4953dc(app, cpu);
    if (cpu.terminate) return;
    // 00496398  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049639a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049639c  0f8e91000000           -jle 0x496433
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496433;
    }
L_0x004963a2:
    // 004963a2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004963a4  e87bf9ffff             -call 0x495d24
    cpu.esp -= 4;
    sub_495d24(app, cpu);
    if (cpu.terminate) return;
    // 004963a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004963ab  7c0f                   -jl 0x4963bc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004963bc;
    }
    // 004963ad  83f803                 +cmp eax, 3
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
    // 004963b0  0f85b8000000           -jne 0x49646e
    if (!cpu.flags.zf)
    {
        goto L_0x0049646e;
    }
    // 004963b6  ff05ecce4d00           -inc dword ptr [0x4dceec]
    (app->getMemory<x86::reg32>(x86::reg32(5099244) /* 0x4dceec */))++;
L_0x004963bc:
    // 004963bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004963be  7f8b                   -jg 0x49634b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049634b;
    }
    // 004963c0  83faf6                 +cmp edx, -0xa
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
    // 004963c3  7e86                   -jle 0x49634b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049634b;
    }
    // 004963c5  803ddcce4d0000         +cmp byte ptr [0x4dcedc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099228) /* 0x4dcedc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004963cc  0f846cffffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 004963d2  a1ecce4d00             -mov eax, dword ptr [0x4dceec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099244) /* 0x4dceec */);
    // 004963d7  3b05f0ce4d00           +cmp eax, dword ptr [0x4dcef0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099248) /* 0x4dcef0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004963dd  7d27                   -jge 0x496406
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496406;
    }
    // 004963df  833decce4d0000         +cmp dword ptr [0x4dceec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099244) /* 0x4dceec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004963e6  0f859d000000           -jne 0x496489
    if (!cpu.flags.zf)
    {
        goto L_0x00496489;
    }
L_0x004963ec:
    // 004963ec  833decce4d0000         +cmp dword ptr [0x4dceec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099244) /* 0x4dceec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004963f3  0f8445ffffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 004963f9  e82ef1ffff             -call 0x49552c
    cpu.esp -= 4;
    sub_49552c(app, cpu);
    if (cpu.terminate) return;
    // 004963fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496400  0f8438ffffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
L_0x00496406:
    // 00496406  e8f5020000             -call 0x496700
    cpu.esp -= 4;
    sub_496700(app, cpu);
    if (cpu.terminate) return;
    // 0049640b  e864ef0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00496410  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496412  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496414  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496415  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496416:
    // 00496416  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049641b  e864f1ffff             -call 0x495584
    cpu.esp -= 4;
    sub_495584(app, cpu);
    if (cpu.terminate) return;
    // 00496420  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496422  0f855fffffff           -jne 0x496387
    if (!cpu.flags.zf)
    {
        goto L_0x00496387;
    }
    // 00496428  e847ef0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049642d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049642f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496430  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496431  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496432  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496433:
    // 00496433  83f8f6                 +cmp eax, -0xa
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
    // 00496436  0f8e66ffffff           -jle 0x4963a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004963a2;
    }
    // 0049643c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049643e  0f8478ffffff           -je 0x4963bc
    if (cpu.flags.zf)
    {
        goto L_0x004963bc;
    }
    // 00496444  833decce4d0000         +cmp dword ptr [0x4dceec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099244) /* 0x4dceec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049644b  0f84edfeffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 00496451  803ddcce4d0000         +cmp byte ptr [0x4dcedc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099228) /* 0x4dcedc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00496458  0f84e0feffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 0049645e  e89d020000             -call 0x496700
    cpu.esp -= 4;
    sub_496700(app, cpu);
    if (cpu.terminate) return;
    // 00496463  e80cef0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00496468  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049646a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049646b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049646c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049646d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049646e:
    // 0049646e  83f801                 +cmp eax, 1
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
    // 00496471  0f8545ffffff           -jne 0x4963bc
    if (!cpu.flags.zf)
    {
        goto L_0x004963bc;
    }
    // 00496477  803dd9ce4d0001         +cmp byte ptr [0x4dced9], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049647e  0f85bafeffff           -jne 0x49633e
    if (!cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 00496484  e933ffffff             -jmp 0x4963bc
    goto L_0x004963bc;
L_0x00496489:
    // 00496489  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049648e  e8f1f0ffff             -call 0x495584
    cpu.esp -= 4;
    sub_495584(app, cpu);
    if (cpu.terminate) return;
    // 00496493  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496495  0f856bffffff           -jne 0x496406
    if (!cpu.flags.zf)
    {
        goto L_0x00496406;
    }
    // 0049649b  e94cffffff             -jmp 0x4963ec
    goto L_0x004963ec;
  case 0x004964a0:
    // 004964a0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004964a2:
    // 004964a2  3a0de7ce4d00           +cmp cl, byte ptr [0x4dcee7]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004964a8  7526                   -jne 0x4964d0
    if (!cpu.flags.zf)
    {
        goto L_0x004964d0;
    }
    // 004964aa  833df4ce4d00ff         +cmp dword ptr [0x4dcef4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099252) /* 0x4dcef4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004964b1  0f8487feffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 004964b7  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 004964bc  e853f0ffff             -call 0x495514
    cpu.esp -= 4;
    sub_495514(app, cpu);
    if (cpu.terminate) return;
    // 004964c1  3b05f4ce4d00           +cmp eax, dword ptr [0x4dcef4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099252) /* 0x4dcef4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004964c7  7c6f                   -jl 0x496538
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496538;
    }
L_0x004964c9:
    // 004964c9  c605e7ce4d00ff         -mov byte ptr [0x4dcee7], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5099239) /* 0x4dcee7 */) = 255 /*0xff*/;
L_0x004964d0:
    // 004964d0  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 004964d5  e802efffff             -call 0x4953dc
    cpu.esp -= 4;
    sub_4953dc(app, cpu);
    if (cpu.terminate) return;
    // 004964da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004964dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004964de  7e71                   -jle 0x496551
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496551;
    }
L_0x004964e0:
    // 004964e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004964e2  e83df8ffff             -call 0x495d24
    cpu.esp -= 4;
    sub_495d24(app, cpu);
    if (cpu.terminate) return;
    // 004964e7  83f801                 +cmp eax, 1
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
    // 004964ea  756a                   -jne 0x496556
    if (!cpu.flags.zf)
    {
        goto L_0x00496556;
    }
L_0x004964ec:
    // 004964ec  833d48cf4d0000         +cmp dword ptr [0x4dcf48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099336) /* 0x4dcf48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004964f3  0f8445feffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 004964f9  e82af7ffff             -call 0x495c28
    cpu.esp -= 4;
    sub_495c28(app, cpu);
    if (cpu.terminate) return;
    // 004964fe  3b0548cf4d00           +cmp eax, dword ptr [0x4dcf48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5099336) /* 0x4dcf48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496504  7c63                   -jl 0x496569
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496569;
    }
    // 00496506  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496508  891d48cf4d00           -mov dword ptr [0x4dcf48], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099336) /* 0x4dcf48 */) = cpu.ebx;
    // 0049650e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00496513  e8e0eb0000             -call 0x4a50f8
    cpu.esp -= 4;
    sub_4a50f8(app, cpu);
    if (cpu.terminate) return;
    // 00496518  833de0cf4d0000         +cmp dword ptr [0x4dcfe0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049651f  0f8419feffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 00496525  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496527  ff15e0cf4d00           -call dword ptr [0x4dcfe0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049652d  e842ee0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00496532  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496534  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496535  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496536  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496537  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496538:
    // 00496538  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049653d  e842f0ffff             -call 0x495584
    cpu.esp -= 4;
    sub_495584(app, cpu);
    if (cpu.terminate) return;
    // 00496542  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496544  7583                   -jne 0x4964c9
    if (!cpu.flags.zf)
    {
        goto L_0x004964c9;
    }
    // 00496546  e829ee0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0049654b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049654d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049654e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049654f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496550  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496551:
    // 00496551  83f8f6                 +cmp eax, -0xa
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
    // 00496554  7e8a                   -jle 0x4964e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004964e0;
    }
L_0x00496556:
    // 00496556  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496558  0f8f44ffffff           -jg 0x4964a2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004964a2;
    }
    // 0049655e  83faf6                 +cmp edx, -0xa
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
    // 00496561  0f8e3bffffff           -jle 0x4964a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004964a2;
    }
    // 00496567  eb83                   -jmp 0x4964ec
    goto L_0x004964ec;
L_0x00496569:
    // 00496569  a158ce4d00             -mov eax, dword ptr [0x4dce58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099096) /* 0x4dce58 */);
    // 0049656e  e811f0ffff             -call 0x495584
    cpu.esp -= 4;
    sub_495584(app, cpu);
    if (cpu.terminate) return;
    // 00496573  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496575  7444                   -je 0x4965bb
    if (cpu.flags.zf)
    {
        goto L_0x004965bb;
    }
    // 00496577  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496579  a0dbce4d00             -mov al, byte ptr [0x4dcedb]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099227) /* 0x4dcedb */);
    // 0049657e  e8ad25ffff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 00496583  83f801                 +cmp eax, 1
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
    // 00496586  0f8fb2fdffff           -jg 0x49633e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049633e;
    }
    // 0049658c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049658e  891548cf4d00           -mov dword ptr [0x4dcf48], edx
    app->getMemory<x86::reg32>(x86::reg32(5099336) /* 0x4dcf48 */) = cpu.edx;
    // 00496594  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496596  e85deb0000             -call 0x4a50f8
    cpu.esp -= 4;
    sub_4a50f8(app, cpu);
    if (cpu.terminate) return;
    // 0049659b  833de0cf4d0000         +cmp dword ptr [0x4dcfe0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004965a2  0f8496fdffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 004965a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004965aa  ff15e0cf4d00           -call dword ptr [0x4dcfe0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004965b0  e8bfed0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004965b5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004965b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004965bb:
    // 004965bb  e86cefffff             -call 0x49552c
    cpu.esp -= 4;
    sub_49552c(app, cpu);
    if (cpu.terminate) return;
    // 004965c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004965c2  0f8476fdffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 004965c8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004965ca  892d48cf4d00           -mov dword ptr [0x4dcf48], ebp
    app->getMemory<x86::reg32>(x86::reg32(5099336) /* 0x4dcf48 */) = cpu.ebp;
    // 004965d0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004965d5  e81eeb0000             -call 0x4a50f8
    cpu.esp -= 4;
    sub_4a50f8(app, cpu);
    if (cpu.terminate) return;
    // 004965da  833de0cf4d0000         +cmp dword ptr [0x4dcfe0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004965e1  0f8457fdffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 004965e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004965e9  ff15e0cf4d00           -call dword ptr [0x4dcfe0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099488) /* 0x4dcfe0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004965ef  e880ed0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004965f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004965f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965f9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004965fa:
    // 004965fa  e8d9f5ffff             -call 0x495bd8
    cpu.esp -= 4;
    sub_495bd8(app, cpu);
    if (cpu.terminate) return;
    // 004965ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496601  0f8f37fdffff           -jg 0x49633e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049633e;
    }
    // 00496607  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 0049660c  e82f32ffff             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
    // 00496611  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 00496616  e825fafeff             -call 0x486040
    cpu.esp -= 4;
    sub_486040(app, cpu);
    if (cpu.terminate) return;
    // 0049661b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049661d  0f841bfdffff           -je 0x49633e
    if (cpu.flags.zf)
    {
        goto L_0x0049633e;
    }
    // 00496623  a0e6ce4d00             -mov al, byte ptr [0x4dcee6]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */);
    // 00496628  fe0de6ce4d00           -dec byte ptr [0x4dcee6]
    (app->getMemory<x86::reg8>(x86::reg32(5099238) /* 0x4dcee6 */))--;
    // 0049662e  e8b9f7ffff             -call 0x495dec
    cpu.esp -= 4;
    sub_495dec(app, cpu);
    if (cpu.terminate) return;
    // 00496633  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00496635  e812000000             -call 0x49664c
    cpu.esp -= 4;
    sub_49664c(app, cpu);
    if (cpu.terminate) return;
    // 0049663a  8815d9ce4d00           -mov byte ptr [0x4dced9], dl
    app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */) = cpu.dl;
    // 00496640  e82fed0000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00496645  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496647  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496648  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496649  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049664a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_49664c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049664c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049664d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049664e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049664f  ba98604900             -mov edx, 0x496098
    cpu.edx = 4808856 /*0x496098*/;
    // 00496654  b990594900             -mov ecx, 0x495990
    cpu.ecx = 4807056 /*0x495990*/;
    // 00496659  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049665b  8915dccf4d00           -mov dword ptr [0x4dcfdc], edx
    app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */) = cpu.edx;
    // 00496661  890d90da4d00           -mov dword ptr [0x4dda90], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102224) /* 0x4dda90 */) = cpu.ecx;
    // 00496667  891decce4d00           -mov dword ptr [0x4dceec], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099244) /* 0x4dceec */) = cpu.ebx;
    // 0049666d  891d70ce4d00           -mov dword ptr [0x4dce70], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099120) /* 0x4dce70 */) = cpu.ebx;
    // 00496673  891d74ce4d00           -mov dword ptr [0x4dce74], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099124) /* 0x4dce74 */) = cpu.ebx;
    // 00496679  891d78ce4d00           -mov dword ptr [0x4dce78], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099128) /* 0x4dce78 */) = cpu.ebx;
    // 0049667f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496681  891d5cce4d00           -mov dword ptr [0x4dce5c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099100) /* 0x4dce5c */) = cpu.ebx;
    // 00496687  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496689  891d60ce4d00           -mov dword ptr [0x4dce60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099104) /* 0x4dce60 */) = cpu.ebx;
    // 0049668f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00496694  890d6cce4d00           -mov dword ptr [0x4dce6c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */) = cpu.ecx;
    // 0049669a  30fc                   -xor ah, bh
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0049669c  8825d9ce4d00           -mov byte ptr [0x4dced9], ah
    app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */) = cpu.ah;
    // 004966a2  30da                   -xor dl, bl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004966a4  8815eace4d00           -mov byte ptr [0x4dceea], dl
    app->getMemory<x86::reg8>(x86::reg32(5099242) /* 0x4dceea */) = cpu.dl;
    // 004966aa  30fe                   -xor dh, bh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004966ac  8835ebce4d00           -mov byte ptr [0x4dceeb], dh
    app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */) = cpu.dh;
    // 004966b2  0fbe05ebce4d00         -movsx eax, byte ptr [0x4dceeb]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099243) /* 0x4dceeb */)));
    // 004966b9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004966bb  890c85f8ce4d00         -mov dword ptr [eax*4 + 0x4dcef8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5099256) /* 0x4dcef8 */ + cpu.eax * 4) = cpu.ecx;
    // 004966c2  c605dace4d0001         -mov byte ptr [0x4dceda], 1
    app->getMemory<x86::reg8>(x86::reg32(5099226) /* 0x4dceda */) = 1 /*0x1*/;
    // 004966c9  30ef                   -xor bh, ch
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004966cb  883de9ce4d00           -mov byte ptr [0x4dcee9], bh
    app->getMemory<x86::reg8>(x86::reg32(5099241) /* 0x4dcee9 */) = cpu.bh;
    // 004966d1  803de4ce4d0000         +cmp byte ptr [0x4dcee4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5099236) /* 0x4dcee4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004966d8  7406                   -je 0x4966e0
    if (cpu.flags.zf)
    {
        goto L_0x004966e0;
    }
    // 004966da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004966dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004966e0:
    // 004966e0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004966e5  b814634900             -mov eax, 0x496314
    cpu.eax = 4809492 /*0x496314*/;
    // 004966ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004966ec  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 004966ee  e8ddd6feff             -call 0x483dd0
    cpu.esp -= 4;
    sub_483dd0(app, cpu);
    if (cpu.terminate) return;
    // 004966f3  882de4ce4d00           -mov byte ptr [0x4dcee4], ch
    app->getMemory<x86::reg8>(x86::reg32(5099236) /* 0x4dcee4 */) = cpu.ch;
    // 004966f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004966fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004966fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_496700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496700  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496703  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 00496708  e833f9feff             -call 0x486040
    cpu.esp -= 4;
    sub_486040(app, cpu);
    if (cpu.terminate) return;
    // 0049670d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049670f  7509                   -jne 0x49671a
    if (!cpu.flags.zf)
    {
        goto L_0x0049671a;
    }
    // 00496711  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00496716  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496719  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049671a:
    // 0049671a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049671b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049671f  e85cecfeff             -call 0x485380
    cpu.esp -= 4;
    sub_485380(app, cpu);
    if (cpu.terminate) return;
    // 00496724  a0dece4d00             -mov al, byte ptr [0x4dcede]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099230) /* 0x4dcede */);
    // 00496729  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0049672d  a0dfce4d00             -mov al, byte ptr [0x4dcedf]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099231) /* 0x4dcedf */);
    // 00496732  8844240b               -mov byte ptr [esp + 0xb], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) = cpu.al;
    // 00496736  a0e0ce4d00             -mov al, byte ptr [0x4dcee0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099232) /* 0x4dcee0 */);
    // 0049673b  8844240d               -mov byte ptr [esp + 0xd], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0049673f  a0e1ce4d00             -mov al, byte ptr [0x4dcee1]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5099233) /* 0x4dcee1 */);
    // 00496744  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496748  8844240e               -mov byte ptr [esp + 0xe], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */) = cpu.al;
    // 0049674c  b87cce4d00             -mov eax, 0x4dce7c
    cpu.eax = 5099132 /*0x4dce7c*/;
    // 00496751  e8aae80000             -call 0x4a5000
    cpu.esp -= 4;
    sub_4a5000(app, cpu);
    if (cpu.terminate) return;
    // 00496756  a36cce4d00             -mov dword ptr [0x4dce6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */) = cpu.eax;
    // 0049675b  833d6cce4d0000         +cmp dword ptr [0x4dce6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496762  7c5b                   -jl 0x4967bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004967bf;
    }
    // 00496764  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496765  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 0049676a  e8fdef0000             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 0049676f  a2ddce4d00             -mov byte ptr [0x4dcedd], al
    app->getMemory<x86::reg8>(x86::reg32(5099229) /* 0x4dcedd */) = cpu.al;
    // 00496774  0fbe15ddce4d00         -movsx edx, byte ptr [0x4dcedd]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5099229) /* 0x4dcedd */)));
    // 0049677b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00496782  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496784  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00496787  8a80bbbf5900           -mov al, byte ptr [eax + 0x59bfbb]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881787) /* 0x59bfbb */);
    // 0049678d  a2dbce4d00             -mov byte ptr [0x4dcedb], al
    app->getMemory<x86::reg8>(x86::reg32(5099227) /* 0x4dcedb */) = cpu.al;
    // 00496792  c605d9ce4d0002         -mov byte ptr [0x4dced9], 2
    app->getMemory<x86::reg8>(x86::reg32(5099225) /* 0x4dced9 */) = 2 /*0x2*/;
    // 00496799  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0049679b  8815d8ce4d00           -mov byte ptr [0x4dced8], dl
    app->getMemory<x86::reg8>(x86::reg32(5099224) /* 0x4dced8 */) = cpu.dl;
    // 004967a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004967a3  66891de2ce4d00         -mov word ptr [0x4dcee2], bx
    app->getMemory<x86::reg16>(x86::reg32(5099234) /* 0x4dcee2 */) = cpu.bx;
    // 004967aa  b8ac5c4900             -mov eax, 0x495cac
    cpu.eax = 4807852 /*0x495cac*/;
    // 004967af  e8ace80000             -call 0x4a5060
    cpu.esp -= 4;
    sub_4a5060(app, cpu);
    if (cpu.terminate) return;
    // 004967b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004967b5  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 004967ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004967bb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004967be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004967bf:
    // 004967bf  66a1e2ce4d00           -mov ax, word ptr [0x4dcee2]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5099234) /* 0x4dcee2 */);
    // 004967c5  66ff05e2ce4d00         -inc word ptr [0x4dcee2]
    (app->getMemory<x86::reg16>(x86::reg32(5099234) /* 0x4dcee2 */))++;
    // 004967cc  a16cce4d00             -mov eax, dword ptr [0x4dce6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 004967d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004967d2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004967d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4967e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004967e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004967e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004967e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004967e3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004967e6  8b7c2438               -mov edi, dword ptr [esp + 0x38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004967ea  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004967ed  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004967f1  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004967f5  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004967f9  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004967fd  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496801  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496805  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496807  bdd0070000             -mov ebp, 0x7d0
    cpu.ebp = 2000 /*0x7d0*/;
    // 0049680c  e87f6e0100             -call 0x4ad690
    cpu.esp -= 4;
    sub_4ad690(app, cpu);
    if (cpu.terminate) return;
    // 00496811  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496813  0f8494000000           -je 0x4968ad
    if (cpu.flags.zf)
    {
        goto L_0x004968ad;
    }
    // 00496819  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049681d  2b1424                 -sub edx, dword ptr [esp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00496820  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496822  0f8c8e000000           -jl 0x4968b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004968b6;
    }
    // 00496828  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049682a:
    // 0049682a  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049682e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496830  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496834  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00496836  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496838  0f8c81000000           -jl 0x4968bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004968bf;
    }
    // 0049683e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00496840:
    // 00496840  39cb                   +cmp ebx, ecx
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
    // 00496842  0f8e9c010000           -jle 0x4969e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004969e4;
    }
    // 00496848  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049684a  0f8c78000000           -jl 0x4968c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004968c8;
    }
L_0x00496850:
    // 00496850  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496854  2b0424                 -sub eax, dword ptr [esp]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00496857  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496859  0f8c8c000000           -jl 0x4968eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004968eb;
    }
L_0x0049685f:
    // 0049685f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496863  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00496867  2b4c2404               -sub ecx, dword ptr [esp + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049686b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049686d  0f8c7f000000           -jl 0x4968f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004968f2;
    }
    // 00496873  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00496875:
    // 00496875  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00496879  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049687d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049687f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00496882  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496884  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00496886  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496888  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049688a  7c6f                   -jl 0x4968fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004968fb;
    }
    // 0049688c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00496891:
    // 00496891  8a1d5cb24d00           -mov bl, byte ptr [0x4db25c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 00496897  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049689b  80fb08                 +cmp bl, 8
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
    // 0049689e  0f85a3000000           -jne 0x496947
    if (!cpu.flags.zf)
    {
        goto L_0x00496947;
    }
L_0x004968a4:
    // 004968a4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004968a7  3b442408               +cmp eax, dword ptr [esp + 8]
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
    // 004968ab  7e55                   -jle 0x496902
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496902;
    }
L_0x004968ad:
    // 004968ad  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004968b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004968b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004968b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004968b3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004968b6:
    // 004968b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004968b8  f7d8                   +neg eax
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
    // 004968ba  e96bffffff             -jmp 0x49682a
    goto L_0x0049682a;
L_0x004968bf:
    // 004968bf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004968c1  f7d9                   +neg ecx
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
    // 004968c3  e978ffffff             -jmp 0x496840
    goto L_0x00496840;
L_0x004968c8:
    // 004968c8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004968cc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004968cf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004968d2  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004968d6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004968da  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004968de  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004968e2  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004968e6  e965ffffff             -jmp 0x496850
    goto L_0x00496850;
L_0x004968eb:
    // 004968eb  f7d8                   +neg eax
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
    // 004968ed  e96dffffff             -jmp 0x49685f
    goto L_0x0049685f;
L_0x004968f2:
    // 004968f2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004968f4  f7d8                   +neg eax
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
    // 004968f6  e97affffff             -jmp 0x496875
    goto L_0x00496875;
L_0x004968fb:
    // 004968fb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00496900  eb8f                   -jmp 0x496891
    goto L_0x00496891;
L_0x00496902:
    // 00496902  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496906  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00496908  8b0d6cb24d00           -mov ecx, dword ptr [0x4db26c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 0049690e  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 00496911  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 00496917  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00496919  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049691c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496920  40                     -inc eax
    (cpu.eax)++;
    // 00496921  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496923  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00496926  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496928  0f8d76ffffff           -jge 0x4968a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004968a4;
    }
    // 0049692e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00496932  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496936  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049693a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049693c  01ce                   +add esi, ecx
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
    // 0049693e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00496942  e95dffffff             -jmp 0x4968a4
    goto L_0x004968a4;
L_0x00496947:
    // 00496947  80fb0f                 +cmp bl, 0xf
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
    // 0049694a  754d                   -jne 0x496999
    if (!cpu.flags.zf)
    {
        goto L_0x00496999;
    }
L_0x0049694c:
    // 0049694c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049694f  3b442408               +cmp eax, dword ptr [esp + 8]
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
    // 00496953  0f8f54ffffff           -jg 0x4968ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004968ad;
    }
    // 00496959  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049695d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049695f  8b0d6cb24d00           -mov ecx, dword ptr [0x4db26c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00496965  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00496968  031560b24d00           -add edx, dword ptr [0x4db260]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 0049696e  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 00496972  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00496975  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496979  40                     -inc eax
    (cpu.eax)++;
    // 0049697a  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049697c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049697f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496981  7dc9                   -jge 0x49694c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049694c;
    }
    // 00496983  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00496987  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049698b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049698f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496991  01ce                   +add esi, ecx
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
    // 00496993  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00496997  ebb3                   -jmp 0x49694c
    goto L_0x0049694c;
L_0x00496999:
    // 00496999  80fb10                 +cmp bl, 0x10
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
    // 0049699c  74ae                   -je 0x49694c
    if (cpu.flags.zf)
    {
        goto L_0x0049694c;
    }
L_0x0049699e:
    // 0049699e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004969a1  3b442408               +cmp eax, dword ptr [esp + 8]
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
    // 004969a5  0f8f02ffffff           -jg 0x4968ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004968ad;
    }
    // 004969ab  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004969ac  0f84fbfeffff           -je 0x4968ad
    if (cpu.flags.zf)
    {
        goto L_0x004968ad;
    }
    // 004969b2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004969b6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004969b8  e8b36e0100             -call 0x4ad870
    cpu.esp -= 4;
    sub_4ad870(app, cpu);
    if (cpu.terminate) return;
    // 004969bd  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004969c0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004969c4  43                     -inc ebx
    (cpu.ebx)++;
    // 004969c5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004969c7  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004969ca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004969cc  7dd0                   -jge 0x49699e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049699e;
    }
    // 004969ce  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004969d2  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004969d6  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004969da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004969dc  01d6                   +add esi, edx
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
    // 004969de  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004969e2  ebba                   -jmp 0x49699e
    goto L_0x0049699e;
L_0x004969e4:
    // 004969e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004969e6  0f8ca1000000           -jl 0x496a8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496a8d;
    }
L_0x004969ec:
    // 004969ec  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004969f0  2b0c24                 -sub ecx, dword ptr [esp]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004969f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004969f5  0f8cb5000000           -jl 0x496ab0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496ab0;
    }
    // 004969fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004969fd:
    // 004969fd  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496a01  2b542404               -sub edx, dword ptr [esp + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00496a05  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00496a09  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496a0b  0f8ca8000000           -jl 0x496ab9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496ab9;
    }
L_0x00496a11:
    // 00496a11  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00496a15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496a17  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00496a1a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496a1c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00496a1e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496a20  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00496a22  0f8c98000000           -jl 0x496ac0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496ac0;
    }
    // 00496a28  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00496a2d:
    // 00496a2d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00496a31  8a255cb24d00           -mov ah, byte ptr [0x4db25c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 00496a37  80fc08                 +cmp ah, 8
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
    // 00496a3a  0f858a000000           -jne 0x496aca
    if (!cpu.flags.zf)
    {
        goto L_0x00496aca;
    }
L_0x00496a40:
    // 00496a40  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496a44  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 00496a48  0f8f5ffeffff           -jg 0x4968ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004968ad;
    }
    // 00496a4e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00496a50  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496a52  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00496a55  8b0d6cb24d00           -mov ecx, dword ptr [0x4db26c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00496a5b  030491                 -add eax, dword ptr [ecx + edx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4)));
    // 00496a5e  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 00496a64  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00496a66  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496a6a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496a6e  40                     -inc eax
    (cpu.eax)++;
    // 00496a6f  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496a71  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00496a75  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496a77  7dc7                   -jge 0x496a40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496a40;
    }
    // 00496a79  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00496a7d  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496a80  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00496a84  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496a86  01ce                   +add esi, ecx
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
    // 00496a88  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00496a8b  ebb3                   -jmp 0x496a40
    goto L_0x00496a40;
L_0x00496a8d:
    // 00496a8d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496a91  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496a95  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00496a99  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00496a9d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496aa1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496aa4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00496aa7  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00496aab  e93cffffff             -jmp 0x4969ec
    goto L_0x004969ec;
L_0x00496ab0:
    // 00496ab0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496ab2  f7d8                   +neg eax
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
    // 00496ab4  e944ffffff             -jmp 0x4969fd
    goto L_0x004969fd;
L_0x00496ab9:
    // 00496ab9  f7da                   +neg edx
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
    // 00496abb  e951ffffff             -jmp 0x496a11
    goto L_0x00496a11;
L_0x00496ac0:
    // 00496ac0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00496ac5  e963ffffff             -jmp 0x496a2d
    goto L_0x00496a2d;
L_0x00496aca:
    // 00496aca  80fc0f                 +cmp ah, 0xf
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
    // 00496acd  754f                   -jne 0x496b1e
    if (!cpu.flags.zf)
    {
        goto L_0x00496b1e;
    }
L_0x00496acf:
    // 00496acf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496ad3  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 00496ad7  0f8fd0fdffff           -jg 0x4968ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004968ad;
    }
    // 00496add  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00496adf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496ae1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00496ae4  8b0d6cb24d00           -mov ecx, dword ptr [0x4db26c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 00496aea  8b1491                 -mov edx, dword ptr [ecx + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4);
    // 00496aed  031560b24d00           -add edx, dword ptr [0x4db260]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 00496af3  66891c42               -mov word ptr [edx + eax*2], bx
    app->getMemory<x86::reg16>(cpu.edx + cpu.eax * 2) = cpu.bx;
    // 00496af7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496afb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496aff  40                     -inc eax
    (cpu.eax)++;
    // 00496b00  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496b02  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00496b06  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496b08  7dc5                   -jge 0x496acf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496acf;
    }
    // 00496b0a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00496b0e  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496b11  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00496b15  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496b17  01ce                   +add esi, ecx
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
    // 00496b19  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00496b1c  ebb1                   -jmp 0x496acf
    goto L_0x00496acf;
L_0x00496b1e:
    // 00496b1e  80fc10                 +cmp ah, 0x10
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
    // 00496b21  74ac                   -je 0x496acf
    if (cpu.flags.zf)
    {
        goto L_0x00496acf;
    }
L_0x00496b23:
    // 00496b23  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496b27  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 00496b2b  0f8f7cfdffff           -jg 0x4968ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004968ad;
    }
    // 00496b31  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00496b32  0f8475fdffff           -je 0x4968ad
    if (cpu.flags.zf)
    {
        goto L_0x004968ad;
    }
    // 00496b38  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00496b3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496b3c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00496b3f  e82c6d0100             -call 0x4ad870
    cpu.esp -= 4;
    sub_4ad870(app, cpu);
    if (cpu.terminate) return;
    // 00496b44  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496b48  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496b4c  43                     -inc ebx
    (cpu.ebx)++;
    // 00496b4d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496b4f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00496b53  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496b55  7dcc                   -jge 0x496b23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496b23;
    }
    // 00496b57  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00496b5b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496b5e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00496b62  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496b64  01d6                   +add esi, edx
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
    // 00496b66  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00496b69  ebb8                   -jmp 0x496b23
    goto L_0x00496b23;
}

/* align: skip  */
void Application::sub_496b6b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496b6b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496b6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496b6d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00496b70  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00496b72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496b74  7514                   -jne 0x496b8a
    if (!cpu.flags.zf)
    {
        goto L_0x00496b8a;
    }
    // 00496b76  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496b7c  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00496b7f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496b81  7507                   -jne 0x496b8a
    if (!cpu.flags.zf)
    {
        goto L_0x00496b8a;
    }
L_0x00496b83:
    // 00496b83  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00496b85  e97f000000             -jmp 0x496c09
    goto L_0x00496c09;
L_0x00496b8a:
    // 00496b8a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00496b8c  e8966d0100             -call 0x4ad927
    cpu.esp -= 4;
    sub_4ad927(app, cpu);
    if (cpu.terminate) return;
    // 00496b91  eb1f                   -jmp 0x496bb2
    goto L_0x00496bb2;
L_0x00496b93:
    // 00496b93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496b95  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00496b98  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496b9a  8a0c04                 -mov cl, byte ptr [esp + eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00496b9d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496b9f  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00496ba2  8a80a41f4d00           -mov al, byte ptr [eax + 0x4d1fa4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5054372) /* 0x4d1fa4 */);
    // 00496ba8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496bad  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00496baf  7409                   -je 0x496bba
    if (cpu.flags.zf)
    {
        goto L_0x00496bba;
    }
    // 00496bb1  43                     -inc ebx
    (cpu.ebx)++;
L_0x00496bb2:
    // 00496bb2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496bb4  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00496bb6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496bb8  75d9                   -jne 0x496b93
    if (!cpu.flags.zf)
    {
        goto L_0x00496b93;
    }
L_0x00496bba:
    // 00496bba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496bbc  74c5                   -je 0x496b83
    if (cpu.flags.zf)
    {
        goto L_0x00496b83;
    }
    // 00496bbe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00496bc0  eb30                   -jmp 0x496bf2
    goto L_0x00496bf2;
L_0x00496bc2:
    // 00496bc2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496bc4  c1e903                 -shr ecx, 3
    cpu.ecx >>= 3 /*0x3*/ % 32;
    // 00496bc7  8a0c0c                 -mov cl, byte ptr [esp + ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1);
    // 00496bca  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00496bcd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496bd3  8a80a41f4d00           -mov al, byte ptr [eax + 0x4d1fa4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5054372) /* 0x4d1fa4 */);
    // 00496bd9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00496bde  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00496be0  740f                   -je 0x496bf1
    if (cpu.flags.zf)
    {
        goto L_0x00496bf1;
    }
    // 00496be2  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00496be5  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00496be6  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496bec  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00496bef  eb16                   -jmp 0x496c07
    goto L_0x00496c07;
L_0x00496bf1:
    // 00496bf1  42                     -inc edx
    (cpu.edx)++;
L_0x00496bf2:
    // 00496bf2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496bf4  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00496bf6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496bf8  75c8                   -jne 0x496bc2
    if (!cpu.flags.zf)
    {
        goto L_0x00496bc2;
    }
    // 00496bfa  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496c00  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x00496c07:
    // 00496c07  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00496c09:
    // 00496c09  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00496c0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496c0f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496c0f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496c10  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00496c12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496c13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496c14  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496c15  83ec08                 +sub esp, 8
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
    // 00496c18  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00496c1b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496c1c  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00496c1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496c20  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00496c23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496c24  e83d6d0100             -call 0x4ad966
    cpu.esp -= 4;
    sub_4ad966(app, cpu);
    if (cpu.terminate) return;
    // 00496c29  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00496c2b  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00496c2d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00496c2f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00496c30  760c                   -jbe 0x496c3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496c3e;
    }
    // 00496c32  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00496c35  dc05e8074d00           -fadd qword ptr [0x4d07e8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5048296) /* 0x4d07e8 */));
    // 00496c3b  dd5dec                 -fstp qword ptr [ebp - 0x14]
    app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00496c3e:
    // 00496c3e  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00496c41  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00496c44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c46  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c48  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_496c4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496c4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496c4c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00496c4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496c4f  dd4508                 -fld qword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00496c52  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00496c55  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00496c57  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00496c5a  e8b0ffffff             -call 0x496c0f
    cpu.esp -= 4;
    sub_496c0f(app, cpu);
    if (cpu.terminate) return;
    // 00496c5f  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00496c61  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c63  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_496c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496c70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496c71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496c72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496c73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496c74  68f0074d00             -push 0x4d07f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048304 /*0x4d07f0*/;
    cpu.esp -= 4;
    // 00496c79  2eff1544654c00         -call dword ptr cs:[0x4c6544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006660) /* 0x4c6544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496c80  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496c82  a3fccf4d00             -mov dword ptr [0x4dcffc], eax
    app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */) = cpu.eax;
    // 00496c87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496c89  7507                   -jne 0x496c92
    if (!cpu.flags.zf)
    {
        goto L_0x00496c92;
    }
    // 00496c8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00496c8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496c91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496c92:
    // 00496c92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496c93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496c94  68fc074d00             -push 0x4d07fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048316 /*0x4d07fc*/;
    cpu.esp -= 4;
    // 00496c99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496c9a  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496ca1  680c084d00             -push 0x4d080c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048332 /*0x4d080c*/;
    cpu.esp -= 4;
    // 00496ca6  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496cac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496cad  a3e0ed5600             -mov dword ptr [0x56ede0], eax
    app->getMemory<x86::reg32>(x86::reg32(5696992) /* 0x56ede0 */) = cpu.eax;
    // 00496cb2  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496cb9  6824084d00             -push 0x4d0824
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048356 /*0x4d0824*/;
    cpu.esp -= 4;
    // 00496cbe  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496cc4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496cc5  a3e4ed5600             -mov dword ptr [0x56ede4], eax
    app->getMemory<x86::reg32>(x86::reg32(5696996) /* 0x56ede4 */) = cpu.eax;
    // 00496cca  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496cd1  6838084d00             -push 0x4d0838
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048376 /*0x4d0838*/;
    cpu.esp -= 4;
    // 00496cd6  8b1dfccf4d00           -mov ebx, dword ptr [0x4dcffc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496cdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496cdd  a3e8ed5600             -mov dword ptr [0x56ede8], eax
    app->getMemory<x86::reg32>(x86::reg32(5697000) /* 0x56ede8 */) = cpu.eax;
    // 00496ce2  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496ce9  6848084d00             -push 0x4d0848
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048392 /*0x4d0848*/;
    cpu.esp -= 4;
    // 00496cee  8b35fccf4d00           -mov esi, dword ptr [0x4dcffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496cf4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496cf5  a3eced5600             -mov dword ptr [0x56edec], eax
    app->getMemory<x86::reg32>(x86::reg32(5697004) /* 0x56edec */) = cpu.eax;
    // 00496cfa  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496d01  685c084d00             -push 0x4d085c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048412 /*0x4d085c*/;
    cpu.esp -= 4;
    // 00496d06  8b3dfccf4d00           -mov edi, dword ptr [0x4dcffc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496d0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496d0d  a3f0ed5600             -mov dword ptr [0x56edf0], eax
    app->getMemory<x86::reg32>(x86::reg32(5697008) /* 0x56edf0 */) = cpu.eax;
    // 00496d12  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496d19  6870084d00             -push 0x4d0870
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048432 /*0x4d0870*/;
    cpu.esp -= 4;
    // 00496d1e  8b2dfccf4d00           -mov ebp, dword ptr [0x4dcffc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496d24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496d25  a3f4ed5600             -mov dword ptr [0x56edf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5697012) /* 0x56edf4 */) = cpu.eax;
    // 00496d2a  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496d31  6888084d00             -push 0x4d0888
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048456 /*0x4d0888*/;
    cpu.esp -= 4;
    // 00496d36  a3f8ed5600             -mov dword ptr [0x56edf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5697016) /* 0x56edf8 */) = cpu.eax;
    // 00496d3b  a1fccf4d00             -mov eax, dword ptr [0x4dcffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496d40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496d41  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496d48  689c084d00             -push 0x4d089c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048476 /*0x4d089c*/;
    cpu.esp -= 4;
    // 00496d4d  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496d53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496d54  a3fced5600             -mov dword ptr [0x56edfc], eax
    app->getMemory<x86::reg32>(x86::reg32(5697020) /* 0x56edfc */) = cpu.eax;
    // 00496d59  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496d60  68bc084d00             -push 0x4d08bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048508 /*0x4d08bc*/;
    cpu.esp -= 4;
    // 00496d65  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496d6b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496d6c  a300ee5600             -mov dword ptr [0x56ee00], eax
    app->getMemory<x86::reg32>(x86::reg32(5697024) /* 0x56ee00 */) = cpu.eax;
    // 00496d71  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496d78  68d4084d00             -push 0x4d08d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048532 /*0x4d08d4*/;
    cpu.esp -= 4;
    // 00496d7d  8b1dfccf4d00           -mov ebx, dword ptr [0x4dcffc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496d83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496d84  a304ee5600             -mov dword ptr [0x56ee04], eax
    app->getMemory<x86::reg32>(x86::reg32(5697028) /* 0x56ee04 */) = cpu.eax;
    // 00496d89  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496d90  68e8084d00             -push 0x4d08e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048552 /*0x4d08e8*/;
    cpu.esp -= 4;
    // 00496d95  8b35fccf4d00           -mov esi, dword ptr [0x4dcffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496d9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496d9c  a308ee5600             -mov dword ptr [0x56ee08], eax
    app->getMemory<x86::reg32>(x86::reg32(5697032) /* 0x56ee08 */) = cpu.eax;
    // 00496da1  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496da8  68fc084d00             -push 0x4d08fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048572 /*0x4d08fc*/;
    cpu.esp -= 4;
    // 00496dad  8b3dfccf4d00           -mov edi, dword ptr [0x4dcffc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496db3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496db4  a30cee5600             -mov dword ptr [0x56ee0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697036) /* 0x56ee0c */) = cpu.eax;
    // 00496db9  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496dc0  a310ee5600             -mov dword ptr [0x56ee10], eax
    app->getMemory<x86::reg32>(x86::reg32(5697040) /* 0x56ee10 */) = cpu.eax;
    // 00496dc5  680c094d00             -push 0x4d090c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048588 /*0x4d090c*/;
    cpu.esp -= 4;
    // 00496dca  8b2dfccf4d00           -mov ebp, dword ptr [0x4dcffc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496dd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496dd1  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496dd8  681c094d00             -push 0x4d091c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048604 /*0x4d091c*/;
    cpu.esp -= 4;
    // 00496ddd  a314ee5600             -mov dword ptr [0x56ee14], eax
    app->getMemory<x86::reg32>(x86::reg32(5697044) /* 0x56ee14 */) = cpu.eax;
    // 00496de2  a1fccf4d00             -mov eax, dword ptr [0x4dcffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496de7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496de8  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496def  682c094d00             -push 0x4d092c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048620 /*0x4d092c*/;
    cpu.esp -= 4;
    // 00496df4  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496dfa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496dfb  a318ee5600             -mov dword ptr [0x56ee18], eax
    app->getMemory<x86::reg32>(x86::reg32(5697048) /* 0x56ee18 */) = cpu.eax;
    // 00496e00  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496e07  683c094d00             -push 0x4d093c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048636 /*0x4d093c*/;
    cpu.esp -= 4;
    // 00496e0c  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496e12  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496e13  a31cee5600             -mov dword ptr [0x56ee1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697052) /* 0x56ee1c */) = cpu.eax;
    // 00496e18  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496e1f  6850094d00             -push 0x4d0950
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048656 /*0x4d0950*/;
    cpu.esp -= 4;
    // 00496e24  8b1dfccf4d00           -mov ebx, dword ptr [0x4dcffc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496e2a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496e2b  a320ee5600             -mov dword ptr [0x56ee20], eax
    app->getMemory<x86::reg32>(x86::reg32(5697056) /* 0x56ee20 */) = cpu.eax;
    // 00496e30  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496e37  6864094d00             -push 0x4d0964
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048676 /*0x4d0964*/;
    cpu.esp -= 4;
    // 00496e3c  8b35fccf4d00           -mov esi, dword ptr [0x4dcffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496e42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496e43  a324ee5600             -mov dword ptr [0x56ee24], eax
    app->getMemory<x86::reg32>(x86::reg32(5697060) /* 0x56ee24 */) = cpu.eax;
    // 00496e48  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496e4f  6878094d00             -push 0x4d0978
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048696 /*0x4d0978*/;
    cpu.esp -= 4;
    // 00496e54  8b3dfccf4d00           -mov edi, dword ptr [0x4dcffc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496e5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496e5b  a328ee5600             -mov dword ptr [0x56ee28], eax
    app->getMemory<x86::reg32>(x86::reg32(5697064) /* 0x56ee28 */) = cpu.eax;
    // 00496e60  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496e67  6894094d00             -push 0x4d0994
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048724 /*0x4d0994*/;
    cpu.esp -= 4;
    // 00496e6c  8b2dfccf4d00           -mov ebp, dword ptr [0x4dcffc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496e72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496e73  a32cee5600             -mov dword ptr [0x56ee2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697068) /* 0x56ee2c */) = cpu.eax;
    // 00496e78  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496e7f  68a4094d00             -push 0x4d09a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048740 /*0x4d09a4*/;
    cpu.esp -= 4;
    // 00496e84  a330ee5600             -mov dword ptr [0x56ee30], eax
    app->getMemory<x86::reg32>(x86::reg32(5697072) /* 0x56ee30 */) = cpu.eax;
    // 00496e89  a1fccf4d00             -mov eax, dword ptr [0x4dcffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496e8e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496e8f  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496e96  68b8094d00             -push 0x4d09b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048760 /*0x4d09b8*/;
    cpu.esp -= 4;
    // 00496e9b  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496ea1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496ea2  a334ee5600             -mov dword ptr [0x56ee34], eax
    app->getMemory<x86::reg32>(x86::reg32(5697076) /* 0x56ee34 */) = cpu.eax;
    // 00496ea7  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496eae  68c8094d00             -push 0x4d09c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048776 /*0x4d09c8*/;
    cpu.esp -= 4;
    // 00496eb3  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496eb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496eba  a338ee5600             -mov dword ptr [0x56ee38], eax
    app->getMemory<x86::reg32>(x86::reg32(5697080) /* 0x56ee38 */) = cpu.eax;
    // 00496ebf  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496ec6  68dc094d00             -push 0x4d09dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048796 /*0x4d09dc*/;
    cpu.esp -= 4;
    // 00496ecb  8b1dfccf4d00           -mov ebx, dword ptr [0x4dcffc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496ed1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496ed2  a33cee5600             -mov dword ptr [0x56ee3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697084) /* 0x56ee3c */) = cpu.eax;
    // 00496ed7  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496ede  68f4094d00             -push 0x4d09f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048820 /*0x4d09f4*/;
    cpu.esp -= 4;
    // 00496ee3  8b35fccf4d00           -mov esi, dword ptr [0x4dcffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496ee9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496eea  a340ee5600             -mov dword ptr [0x56ee40], eax
    app->getMemory<x86::reg32>(x86::reg32(5697088) /* 0x56ee40 */) = cpu.eax;
    // 00496eef  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496ef6  a344ee5600             -mov dword ptr [0x56ee44], eax
    app->getMemory<x86::reg32>(x86::reg32(5697092) /* 0x56ee44 */) = cpu.eax;
    // 00496efb  680c0a4d00             -push 0x4d0a0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048844 /*0x4d0a0c*/;
    cpu.esp -= 4;
    // 00496f00  8b3dfccf4d00           -mov edi, dword ptr [0x4dcffc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496f06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496f07  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f0e  68280a4d00             -push 0x4d0a28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048872 /*0x4d0a28*/;
    cpu.esp -= 4;
    // 00496f13  8b2dfccf4d00           -mov ebp, dword ptr [0x4dcffc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496f19  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496f1a  a348ee5600             -mov dword ptr [0x56ee48], eax
    app->getMemory<x86::reg32>(x86::reg32(5697096) /* 0x56ee48 */) = cpu.eax;
    // 00496f1f  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f26  68380a4d00             -push 0x4d0a38
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048888 /*0x4d0a38*/;
    cpu.esp -= 4;
    // 00496f2b  a34cee5600             -mov dword ptr [0x56ee4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697100) /* 0x56ee4c */) = cpu.eax;
    // 00496f30  a1fccf4d00             -mov eax, dword ptr [0x4dcffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496f35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496f36  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f3d  684c0a4d00             -push 0x4d0a4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048908 /*0x4d0a4c*/;
    cpu.esp -= 4;
    // 00496f42  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496f48  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496f49  a350ee5600             -mov dword ptr [0x56ee50], eax
    app->getMemory<x86::reg32>(x86::reg32(5697104) /* 0x56ee50 */) = cpu.eax;
    // 00496f4e  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f55  685c0a4d00             -push 0x4d0a5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048924 /*0x4d0a5c*/;
    cpu.esp -= 4;
    // 00496f5a  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496f61  a354ee5600             -mov dword ptr [0x56ee54], eax
    app->getMemory<x86::reg32>(x86::reg32(5697108) /* 0x56ee54 */) = cpu.eax;
    // 00496f66  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f6d  686c0a4d00             -push 0x4d0a6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048940 /*0x4d0a6c*/;
    cpu.esp -= 4;
    // 00496f72  8b1dfccf4d00           -mov ebx, dword ptr [0x4dcffc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496f78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496f79  a358ee5600             -mov dword ptr [0x56ee58], eax
    app->getMemory<x86::reg32>(x86::reg32(5697112) /* 0x56ee58 */) = cpu.eax;
    // 00496f7e  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f85  687c0a4d00             -push 0x4d0a7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048956 /*0x4d0a7c*/;
    cpu.esp -= 4;
    // 00496f8a  8b35fccf4d00           -mov esi, dword ptr [0x4dcffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496f90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496f91  a35cee5600             -mov dword ptr [0x56ee5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697116) /* 0x56ee5c */) = cpu.eax;
    // 00496f96  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f9d  688c0a4d00             -push 0x4d0a8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048972 /*0x4d0a8c*/;
    cpu.esp -= 4;
    // 00496fa2  8b3dfccf4d00           -mov edi, dword ptr [0x4dcffc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496fa8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496fa9  a360ee5600             -mov dword ptr [0x56ee60], eax
    app->getMemory<x86::reg32>(x86::reg32(5697120) /* 0x56ee60 */) = cpu.eax;
    // 00496fae  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496fb5  68a40a4d00             -push 0x4d0aa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048996 /*0x4d0aa4*/;
    cpu.esp -= 4;
    // 00496fba  8b2dfccf4d00           -mov ebp, dword ptr [0x4dcffc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496fc0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496fc1  a364ee5600             -mov dword ptr [0x56ee64], eax
    app->getMemory<x86::reg32>(x86::reg32(5697124) /* 0x56ee64 */) = cpu.eax;
    // 00496fc6  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496fcd  68b80a4d00             -push 0x4d0ab8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049016 /*0x4d0ab8*/;
    cpu.esp -= 4;
    // 00496fd2  a368ee5600             -mov dword ptr [0x56ee68], eax
    app->getMemory<x86::reg32>(x86::reg32(5697128) /* 0x56ee68 */) = cpu.eax;
    // 00496fd7  a1fccf4d00             -mov eax, dword ptr [0x4dcffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496fdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496fdd  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496fe4  68cc0a4d00             -push 0x4d0acc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049036 /*0x4d0acc*/;
    cpu.esp -= 4;
    // 00496fe9  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00496fef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496ff0  a36cee5600             -mov dword ptr [0x56ee6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */) = cpu.eax;
    // 00496ff5  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496ffc  68dc0a4d00             -push 0x4d0adc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049052 /*0x4d0adc*/;
    cpu.esp -= 4;
    // 00497001  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00497007  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497008  a370ee5600             -mov dword ptr [0x56ee70], eax
    app->getMemory<x86::reg32>(x86::reg32(5697136) /* 0x56ee70 */) = cpu.eax;
    // 0049700d  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497014  68ec0a4d00             -push 0x4d0aec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049068 /*0x4d0aec*/;
    cpu.esp -= 4;
    // 00497019  8b1dfccf4d00           -mov ebx, dword ptr [0x4dcffc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 0049701f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497020  a374ee5600             -mov dword ptr [0x56ee74], eax
    app->getMemory<x86::reg32>(x86::reg32(5697140) /* 0x56ee74 */) = cpu.eax;
    // 00497025  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049702c  a378ee5600             -mov dword ptr [0x56ee78], eax
    app->getMemory<x86::reg32>(x86::reg32(5697144) /* 0x56ee78 */) = cpu.eax;
    // 00497031  68080b4d00             -push 0x4d0b08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049096 /*0x4d0b08*/;
    cpu.esp -= 4;
    // 00497036  8b35fccf4d00           -mov esi, dword ptr [0x4dcffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 0049703c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049703d  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497044  681c0b4d00             -push 0x4d0b1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049116 /*0x4d0b1c*/;
    cpu.esp -= 4;
    // 00497049  8b3dfccf4d00           -mov edi, dword ptr [0x4dcffc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 0049704f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497050  a37cee5600             -mov dword ptr [0x56ee7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697148) /* 0x56ee7c */) = cpu.eax;
    // 00497055  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049705c  68300b4d00             -push 0x4d0b30
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049136 /*0x4d0b30*/;
    cpu.esp -= 4;
    // 00497061  8b2dfccf4d00           -mov ebp, dword ptr [0x4dcffc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00497067  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497068  a380ee5600             -mov dword ptr [0x56ee80], eax
    app->getMemory<x86::reg32>(x86::reg32(5697152) /* 0x56ee80 */) = cpu.eax;
    // 0049706d  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497074  68440b4d00             -push 0x4d0b44
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049156 /*0x4d0b44*/;
    cpu.esp -= 4;
    // 00497079  a384ee5600             -mov dword ptr [0x56ee84], eax
    app->getMemory<x86::reg32>(x86::reg32(5697156) /* 0x56ee84 */) = cpu.eax;
    // 0049707e  a1fccf4d00             -mov eax, dword ptr [0x4dcffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00497083  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497084  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049708b  68600b4d00             -push 0x4d0b60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049184 /*0x4d0b60*/;
    cpu.esp -= 4;
    // 00497090  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00497096  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497097  a388ee5600             -mov dword ptr [0x56ee88], eax
    app->getMemory<x86::reg32>(x86::reg32(5697160) /* 0x56ee88 */) = cpu.eax;
    // 0049709c  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004970a3  68780b4d00             -push 0x4d0b78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049208 /*0x4d0b78*/;
    cpu.esp -= 4;
    // 004970a8  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 004970ae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004970af  a38cee5600             -mov dword ptr [0x56ee8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697164) /* 0x56ee8c */) = cpu.eax;
    // 004970b4  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004970bb  688c0b4d00             -push 0x4d0b8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049228 /*0x4d0b8c*/;
    cpu.esp -= 4;
    // 004970c0  8b1dfccf4d00           -mov ebx, dword ptr [0x4dcffc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 004970c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004970c7  a390ee5600             -mov dword ptr [0x56ee90], eax
    app->getMemory<x86::reg32>(x86::reg32(5697168) /* 0x56ee90 */) = cpu.eax;
    // 004970cc  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004970d3  68a00b4d00             -push 0x4d0ba0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049248 /*0x4d0ba0*/;
    cpu.esp -= 4;
    // 004970d8  8b35fccf4d00           -mov esi, dword ptr [0x4dcffc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 004970de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004970df  a394ee5600             -mov dword ptr [0x56ee94], eax
    app->getMemory<x86::reg32>(x86::reg32(5697172) /* 0x56ee94 */) = cpu.eax;
    // 004970e4  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004970eb  68b00b4d00             -push 0x4d0bb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049264 /*0x4d0bb0*/;
    cpu.esp -= 4;
    // 004970f0  8b3dfccf4d00           -mov edi, dword ptr [0x4dcffc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 004970f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004970f7  a398ee5600             -mov dword ptr [0x56ee98], eax
    app->getMemory<x86::reg32>(x86::reg32(5697176) /* 0x56ee98 */) = cpu.eax;
    // 004970fc  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497103  68c40b4d00             -push 0x4d0bc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049284 /*0x4d0bc4*/;
    cpu.esp -= 4;
    // 00497108  8b2dfccf4d00           -mov ebp, dword ptr [0x4dcffc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 0049710e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049710f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00497114  a39cee5600             -mov dword ptr [0x56ee9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697180) /* 0x56ee9c */) = cpu.eax;
    // 00497119  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497120  a3a0ee5600             -mov dword ptr [0x56eea0], eax
    app->getMemory<x86::reg32>(x86::reg32(5697184) /* 0x56eea0 */) = cpu.eax;
    // 00497125  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497126  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497127  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497129  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049712a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049712b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049712c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049712d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497133  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 00497139  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049713b  750c                   -jne 0x497149
    if (!cpu.flags.zf)
    {
        goto L_0x00497149;
    }
    // 0049713d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049713f  891dfccf4d00           -mov dword ptr [0x4dcffc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */) = cpu.ebx;
    // 00497145  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497146  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497147  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497148  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497149:
    // 00497149  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049714a  2eff159c644c00         -call dword ptr cs:[0x4c649c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006492) /* 0x4c649c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497151  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497153  891dfccf4d00           -mov dword ptr [0x4dcffc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */) = cpu.ebx;
    // 00497159  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049715a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049715b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049715c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497161  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00497164  e807fbffff             -call 0x496c70
    cpu.esp -= 4;
    sub_496c70(app, cpu);
    if (cpu.terminate) return;
    // 00497169  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049716b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049716d  7507                   -jne 0x497176
    if (!cpu.flags.zf)
    {
        goto L_0x00497176;
    }
    // 0049716f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497171  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00497174  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497175  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497176:
    // 00497176  ff15e0ed5600           -call dword ptr [0x56ede0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5696992) /* 0x56ede0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049717c  68a4ee5600             -push 0x56eea4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697188 /*0x56eea4*/;
    cpu.esp -= 4;
    // 00497181  ff15e4ed5600           -call dword ptr [0x56ede4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5696996) /* 0x56ede4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497187  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00497189  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049718b  744f                   -je 0x4971dc
    if (cpu.flags.zf)
    {
        goto L_0x004971dc;
    }
    // 0049718d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049718f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497190  ff15a0ee5600           -call dword ptr [0x56eea0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697184) /* 0x56eea0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497196  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00497199  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049719b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0049719d  7414                   -je 0x4971b3
    if (cpu.flags.zf)
    {
        goto L_0x004971b3;
    }
L_0x0049719f:
    // 0049719f  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 004971a2  fec2                   -inc dl
    (cpu.dl)++;
    // 004971a4  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004971aa  f68264ef4d0020         +test byte ptr [edx + 0x4def64], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */) & 32 /*0x20*/));
    // 004971b1  7452                   -je 0x497205
    if (cpu.flags.zf)
    {
        goto L_0x00497205;
    }
L_0x004971b3:
    // 004971b3  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004971b5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004971b7  badc0b4d00             -mov edx, 0x4d0bdc
    cpu.edx = 5049308 /*0x4d0bdc*/;
    // 004971bc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004971be  e85dc5feff             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 004971c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004971c5  7c49                   -jl 0x497210
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497210;
    }
    // 004971c7  badc0b4d00             -mov edx, 0x4d0bdc
    cpu.edx = 5049308 /*0x4d0bdc*/;
    // 004971cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004971ce  e84dc5feff             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 004971d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004971d5  7e40                   -jle 0x497217
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497217;
    }
    // 004971d7  bb5f000000             -mov ebx, 0x5f
    cpu.ebx = 95 /*0x5f*/;
L_0x004971dc:
    // 004971dc  ff15e8ed5600           -call dword ptr [0x56ede8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697000) /* 0x56ede8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004971e2  8b15fccf4d00           -mov edx, dword ptr [0x4dcffc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 004971e8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004971ea  7408                   -je 0x4971f4
    if (cpu.flags.zf)
    {
        goto L_0x004971f4;
    }
    // 004971ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004971ed  2eff159c644c00         -call dword ptr cs:[0x4c649c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006492) /* 0x4c649c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004971f4:
    // 004971f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004971f5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004971f7  8935fccf4d00           -mov dword ptr [0x4dcffc], esi
    app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */) = cpu.esi;
    // 004971fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004971fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497200  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00497203  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497204  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497205:
    // 00497205  8a740401               -mov dh, byte ptr [esp + eax + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00497209  40                     -inc eax
    (cpu.eax)++;
    // 0049720a  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0049720c  7591                   -jne 0x49719f
    if (!cpu.flags.zf)
    {
        goto L_0x0049719f;
    }
    // 0049720e  eba3                   -jmp 0x4971b3
    goto L_0x004971b3;
L_0x00497210:
    // 00497210  bb5a000000             -mov ebx, 0x5a
    cpu.ebx = 90 /*0x5a*/;
    // 00497215  ebc5                   -jmp 0x4971dc
    goto L_0x004971dc;
L_0x00497217:
    // 00497217  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0049721c  ebbe                   -jmp 0x4971dc
    goto L_0x004971dc;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497220  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497224  8b15a4ee5600           -mov edx, dword ptr [0x56eea4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697188) /* 0x56eea4 */);
    // 0049722a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049722c  39d1                   +cmp ecx, edx
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
    // 0049722e  7c03                   -jl 0x497233
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497233;
    }
    // 00497230  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00497233:
    // 00497233  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497234  ff15eced5600           -call dword ptr [0x56edec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697004) /* 0x56edec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049723a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049723f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497244(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497244  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497247  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00497249  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049724b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049724d:
    // 0049724d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00497250  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497253  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00497256  40                     -inc eax
    (cpu.eax)++;
    // 00497257  d99adce95600           -fstp dword ptr [edx + 0x56e9dc]
    app->getMemory<float>(cpu.edx + x86::reg32(5695964) /* 0x56e9dc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049725d  3d00010000             +cmp eax, 0x100
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
    // 00497262  7ce9                   -jl 0x49724d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049724d;
    }
    // 00497264  e807faffff             -call 0x496c70
    cpu.esp -= 4;
    sub_496c70(app, cpu);
    if (cpu.terminate) return;
    // 00497269  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049726b  7506                   -jne 0x497273
    if (!cpu.flags.zf)
    {
        goto L_0x00497273;
    }
L_0x0049726d:
    // 0049726d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049726f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497272  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497273:
    // 00497273  ff15e0ed5600           -call dword ptr [0x56ede0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5696992) /* 0x56ede0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497279  68a4ee5600             -push 0x56eea4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697188 /*0x56eea4*/;
    cpu.esp -= 4;
    // 0049727e  ff15e4ed5600           -call dword ptr [0x56ede4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5696996) /* 0x56ede4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497284  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497286  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497288  74e3                   -je 0x49726d
    if (cpu.flags.zf)
    {
        goto L_0x0049726d;
    }
    // 0049728a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049728c  e88fffffff             -call 0x497220
    cpu.esp -= 4;
    sub_497220(app, cpu);
    if (cpu.terminate) return;
    // 00497291  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00497293  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497295  74d6                   -je 0x49726d
    if (cpu.flags.zf)
    {
        goto L_0x0049726d;
    }
    // 00497297  8b0da4ee5600           -mov ecx, dword ptr [0x56eea4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697188) /* 0x56eea4 */);
    // 0049729d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049729f  74cc                   -je 0x49726d
    if (cpu.flags.zf)
    {
        goto L_0x0049726d;
    }
    // 004972a1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004972a6  b8bc724900             -mov eax, 0x4972bc
    cpu.eax = 4813500 /*0x4972bc*/;
    // 004972ab  8915e4cf4d00           -mov dword ptr [0x4dcfe4], edx
    app->getMemory<x86::reg32>(x86::reg32(5099492) /* 0x4dcfe4 */) = cpu.edx;
    // 004972b1  e8c9660100             -call 0x4ad97f
    cpu.esp -= 4;
    sub_4ad97f(app, cpu);
    if (cpu.terminate) return;
    // 004972b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004972b8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004972bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4972bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004972bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004972bd  8b15e4cf4d00           -mov edx, dword ptr [0x4dcfe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099492) /* 0x4dcfe4 */);
    // 004972c3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004972c8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004972ca  7504                   -jne 0x4972d0
    if (!cpu.flags.zf)
    {
        goto L_0x004972d0;
    }
    // 004972cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004972ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004972d0:
    // 004972d0  ff15e8ed5600           -call dword ptr [0x56ede8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697000) /* 0x56ede8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004972d6  8b0dfccf4d00           -mov ecx, dword ptr [0x4dcffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */);
    // 004972dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004972de  7408                   -je 0x4972e8
    if (cpu.flags.zf)
    {
        goto L_0x004972e8;
    }
    // 004972e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004972e1  2eff159c644c00         -call dword ptr cs:[0x4c649c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006492) /* 0x4c649c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004972e8:
    // 004972e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004972e9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004972eb  893dfccf4d00           -mov dword ptr [0x4dcffc], edi
    app->getMemory<x86::reg32>(x86::reg32(5099516) /* 0x4dcffc */) = cpu.edi;
    // 004972f1  893de4cf4d00           -mov dword ptr [0x4dcfe4], edi
    app->getMemory<x86::reg32>(x86::reg32(5099492) /* 0x4dcfe4 */) = cpu.edi;
    // 004972f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004972fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4972fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004972fc  f605e4cf4d0002         +test byte ptr [0x4dcfe4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5099492) /* 0x4dcfe4 */) & 2 /*0x2*/));
    // 00497303  7501                   -jne 0x497306
    if (!cpu.flags.zf)
    {
        goto L_0x00497306;
    }
    // 00497305  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497306:
    // 00497306  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497307  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497308  ff15f0ed5600           -call dword ptr [0x56edf0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697008) /* 0x56edf0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049730e  8025e4cf4d00fd         -and byte ptr [0x4dcfe4], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(5099492) /* 0x4dcfe4 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00497315  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497316  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497317  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497318(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497318  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497319  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049731d  e8daffffff             -call 0x4972fc
    cpu.esp -= 4;
    sub_4972fc(app, cpu);
    if (cpu.terminate) return;
    // 00497322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497323  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00497327  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497328  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049732a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049732c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00497330  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497332  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497334  8a8200d04d00           -mov al, byte ptr [edx + 0x4dd000]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5099520) /* 0x4dd000 */);
    // 0049733a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049733b  e89097ffff             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 00497340  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497341  ff15f4ed5600           -call dword ptr [0x56edf4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697012) /* 0x56edf4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497347  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00497349  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049734b  7506                   -jne 0x497353
    if (!cpu.flags.zf)
    {
        goto L_0x00497353;
    }
    // 0049734d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049734f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497350  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00497353:
    // 00497353  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497354  e857020000             -call 0x4975b0
    cpu.esp -= 4;
    sub_4975b0(app, cpu);
    if (cpu.terminate) return;
    // 00497359  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049735b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049735d  ff15f8ed5600           -call dword ptr [0x56edf8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697016) /* 0x56edf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497363  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497365  ff15fced5600           -call dword ptr [0x56edfc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697020) /* 0x56edfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049736b  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0049736d  ff1500ee5600           -call dword ptr [0x56ee00]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697024) /* 0x56ee00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497373  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497375  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497377  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497379  ff1534ee5600           -call dword ptr [0x56ee34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697076) /* 0x56ee34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049737f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497381  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497383  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497385  ff1580ee5600           -call dword ptr [0x56ee80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697152) /* 0x56ee80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049738b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049738d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049738f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497391  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497393  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497395  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497397  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497399  ff1584ee5600           -call dword ptr [0x56ee84]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697156) /* 0x56ee84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049739f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973a1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004973a3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973a5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973a7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004973a9  ff1524ee5600           -call dword ptr [0x56ee24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697060) /* 0x56ee24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004973af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973b1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004973b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973b7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004973b9  ff1528ee5600           -call dword ptr [0x56ee28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697064) /* 0x56ee28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004973bf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973c1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973c3  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004973c5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004973c7  ff152cee5600           -call dword ptr [0x56ee2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697068) /* 0x56ee2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004973cd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973cf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004973d1  e862030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 004973d6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004973d8  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004973da  e859030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 004973df  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004973e1  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004973e3  e850030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 004973e8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004973ea  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004973ec  e847030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 004973f1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004973f3  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004973f5  e83e030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 004973fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004973fc  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004973fe  e835030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 00497403  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497405  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00497407  e82c030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 0049740c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049740e  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00497410  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00497414  e81f030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 00497419  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049741b  7443                   -je 0x497460
    if (cpu.flags.zf)
    {
        goto L_0x00497460;
    }
    // 0049741d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00497422:
    // 00497422  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497423  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00497425  e80e030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 0049742a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049742c  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 0049742e  e805030000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 00497433  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00497435  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00497437  e8fc020000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 0049743c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049743e  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00497440  e8f3020000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 00497445  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 0049744a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049744b  6a65                   -push 0x65
    app->getMemory<x86::reg32>(cpu.esp-4) = 101 /*0x65*/;
    cpu.esp -= 4;
    // 0049744d  e8e6020000             -call 0x497738
    cpu.esp -= 4;
    sub_497738(app, cpu);
    if (cpu.terminate) return;
    // 00497452  800de4cf4d0002         -or byte ptr [0x4dcfe4], 2
    app->getMemory<x86::reg8>(x86::reg32(5099492) /* 0x4dcfe4 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00497459  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049745a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049745c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049745d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00497460:
    // 00497460  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00497462  ebbe                   -jmp 0x497422
    goto L_0x00497422;
}

/* align: skip  */
void Application::sub_497464(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497464  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497465  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497466  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497467  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497468  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049746c  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00497470  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00497472  39ef                   +cmp edi, ebp
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
    // 00497474  7e63                   -jle 0x4974d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004974d9;
    }
    // 00497476  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00497478:
    // 00497478  e873650100             -call 0x4ad9f0
    cpu.esp -= 4;
    sub_4ad9f0(app, cpu);
    if (cpu.terminate) return;
    // 0049747d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049747f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00497481  e86a650100             -call 0x4ad9f0
    cpu.esp -= 4;
    sub_4ad9f0(app, cpu);
    if (cpu.terminate) return;
    // 00497486  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00497488  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049748a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049748e  e85d650100             -call 0x4ad9f0
    cpu.esp -= 4;
    sub_4ad9f0(app, cpu);
    if (cpu.terminate) return;
    // 00497493  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00497495  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497497  8a821dd04d00           -mov al, byte ptr [edx + 0x4dd01d]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5099549) /* 0x4dd01d */);
    // 0049749d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049749e  0fb6af19d04d00         -movzx ebp, byte ptr [edi + 0x4dd019]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5099545) /* 0x4dd019 */));
    // 004974a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004974a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004974a8  8a830dd04d00           -mov al, byte ptr [ebx + 0x4dd00d]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5099533) /* 0x4dd00d */);
    // 004974ae  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004974b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004974b3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004974b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004974b6  ff1588ee5600           -call dword ptr [0x56ee88]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697160) /* 0x56ee88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004974bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004974be  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004974c0  ff1594ee5600           -call dword ptr [0x56ee94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697172) /* 0x56ee94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004974c6  2b0538ef5600           -sub eax, dword ptr [0x56ef38]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */)));
    // 004974cc  39f8                   +cmp eax, edi
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
    // 004974ce  770d                   -ja 0x4974dd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004974dd;
    }
L_0x004974d0:
    // 004974d0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004974d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004974d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004974d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004974d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004974d6  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x004974d9:
    // 004974d9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004974db  eb9b                   -jmp 0x497478
    goto L_0x00497478;
L_0x004974dd:
    // 004974dd  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004974e2  e8dcf00000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004974e7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004974e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004974eb  74e3                   -je 0x4974d0
    if (cpu.flags.zf)
    {
        goto L_0x004974d0;
    }
    // 004974ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004974ef  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004974f3  8a930dd04d00           -mov dl, byte ptr [ebx + 0x4dd00d]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5099533) /* 0x4dd00d */);
    // 004974f9  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004974fb  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004974fd  8a9b0dd04d00           -mov bl, byte ptr [ebx + 0x4dd00d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5099533) /* 0x4dd00d */);
    // 00497503  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00497509  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0049750c  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00497510  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00497513  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497515  8a9a1dd04d00           -mov bl, byte ptr [edx + 0x4dd01d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5099549) /* 0x4dd01d */);
    // 0049751b  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00497522  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00497525  8b1d38ef5600           -mov ebx, dword ptr [0x56ef38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */);
    // 0049752b  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0049752e  8b1df8cf4d00           -mov ebx, dword ptr [0x4dcff8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5099512) /* 0x4dcff8 */);
    // 00497534  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00497537  8b1d38ef5600           -mov ebx, dword ptr [0x56ef38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */);
    // 0049753d  c7401803000000         -mov dword ptr [eax + 0x18], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
    // 00497544  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00497546  a3f8cf4d00             -mov dword ptr [0x4dcff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5099512) /* 0x4dcff8 */) = cpu.eax;
    // 0049754b  891d38ef5600           -mov dword ptr [0x56ef38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */) = cpu.ebx;
    // 00497551  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497553  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497554  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497555  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497556  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497557  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49755c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049755c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049755d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049755e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00497562  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00497566  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497568  750f                   -jne 0x497579
    if (!cpu.flags.zf)
    {
        goto L_0x00497579;
    }
    // 0049756a  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049756e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00497570  752a                   -jne 0x49759c
    if (!cpu.flags.zf)
    {
        goto L_0x0049759c;
    }
    // 00497572  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497574  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497575  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497576  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00497579:
    // 00497579  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049757a  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0049757d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049757e  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00497581  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497582  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497584  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00497587  ff158cee5600           -call dword ptr [0x56ee8c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697164) /* 0x56ee8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049758d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00497591  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00497593  7507                   -jne 0x49759c
    if (!cpu.flags.zf)
    {
        goto L_0x0049759c;
    }
    // 00497595  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497597  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497598  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497599  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049759c:
    // 0049759c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049759d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049759f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004975a1  ff1504ee5600           -call dword ptr [0x56ee04]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697028) /* 0x56ee04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004975a7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004975a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004975aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004975ab  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4975b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004975b0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004975b2  ff1590ee5600           -call dword ptr [0x56ee90]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697168) /* 0x56ee90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004975b8  8b15f8cf4d00           -mov edx, dword ptr [0x4dcff8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099512) /* 0x4dcff8 */);
    // 004975be  a338ef5600             -mov dword ptr [0x56ef38], eax
    app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */) = cpu.eax;
    // 004975c3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004975c5  7419                   -je 0x4975e0
    if (cpu.flags.zf)
    {
        goto L_0x004975e0;
    }
L_0x004975c7:
    // 004975c7  a1f8cf4d00             -mov eax, dword ptr [0x4dcff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099512) /* 0x4dcff8 */);
    // 004975cc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004975cf  e8243f0100             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004975d4  8915f8cf4d00           -mov dword ptr [0x4dcff8], edx
    app->getMemory<x86::reg32>(x86::reg32(5099512) /* 0x4dcff8 */) = cpu.edx;
    // 004975da  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004975dc  75e9                   -jne 0x4975c7
    if (!cpu.flags.zf)
    {
        goto L_0x004975c7;
    }
    // 004975de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004975e0:
    // 004975e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004975e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4975e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004975e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004975e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004975ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004975eb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004975ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004975f1  7514                   -jne 0x497607
    if (!cpu.flags.zf)
    {
        goto L_0x00497607;
    }
    // 004975f3  833d28d04d0000         +cmp dword ptr [0x4dd028], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099560) /* 0x4dd028 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004975fa  7552                   -jne 0x49764e
    if (!cpu.flags.zf)
    {
        goto L_0x0049764e;
    }
L_0x004975fc:
    // 004975fc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497601  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497602  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497603  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497604  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00497607:
    // 00497607  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497608  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049760b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049760c  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049760f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497610  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497612  ff1598ee5600           -call dword ptr [0x56ee98]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697176) /* 0x56ee98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497618  833d28d04d0001         +cmp dword ptr [0x4dd028], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099560) /* 0x4dd028 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049761f  74db                   -je 0x4975fc
    if (cpu.flags.zf)
    {
        goto L_0x004975fc;
    }
    // 00497621  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497623  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497625  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497627  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497629  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0049762b  ff1524ee5600           -call dword ptr [0x56ee24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697060) /* 0x56ee24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497631  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497633  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497635  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497637  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497639  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0049763b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00497640  ff1528ee5600           -call dword ptr [0x56ee28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697064) /* 0x56ee28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497646  892d28d04d00           -mov dword ptr [0x4dd028], ebp
    app->getMemory<x86::reg32>(x86::reg32(5099560) /* 0x4dd028 */) = cpu.ebp;
    // 0049764c  ebae                   -jmp 0x4975fc
    goto L_0x004975fc;
L_0x0049764e:
    // 0049764e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049764f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00497651  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497652  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497653  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497655  ff1524ee5600           -call dword ptr [0x56ee24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697060) /* 0x56ee24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049765b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049765d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049765f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497661  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497663  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497665  ff1528ee5600           -call dword ptr [0x56ee28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697064) /* 0x56ee28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049766b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049766d  890d28d04d00           -mov dword ptr [0x4dd028], ecx
    app->getMemory<x86::reg32>(x86::reg32(5099560) /* 0x4dd028 */) = cpu.ecx;
    // 00497673  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497678  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497679  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049767a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049767b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497680  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497684  48                     -dec eax
    (cpu.eax)--;
    // 00497685  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497686  a3f0cf4d00             -mov dword ptr [0x4dcff0], eax
    app->getMemory<x86::reg32>(x86::reg32(5099504) /* 0x4dcff0 */) = cpu.eax;
    // 0049768b  ff1508ee5600           -call dword ptr [0x56ee08]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697032) /* 0x56ee08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497691  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497696  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49769c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049769c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049769e  66a1eccf4d00           -mov ax, word ptr [0x4dcfec]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5099500) /* 0x4dcfec */);
    // 004976a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004976a5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004976a7  8b15e8cf4d00           -mov edx, dword ptr [0x4dcfe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099496) /* 0x4dcfe8 */);
    // 004976ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004976ae  ff150cee5600           -call dword ptr [0x56ee0c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697036) /* 0x56ee0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004976b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4976b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004976b8  8b15f4cf4d00           -mov edx, dword ptr [0x4dcff4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099508) /* 0x4dcff4 */);
    // 004976be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004976bf  ff1510ee5600           -call dword ptr [0x56ee10]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697040) /* 0x56ee10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004976c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4976c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004976c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004976c9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004976cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004976cf  83f801                 +cmp eax, 1
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
    // 004976d2  7227                   -jb 0x4976fb
    if (cpu.flags.cf)
    {
        goto L_0x004976fb;
    }
    // 004976d4  762d                   -jbe 0x497703
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497703;
    }
    // 004976d6  83f802                 +cmp eax, 2
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
    // 004976d9  7520                   -jne 0x4976fb
    if (!cpu.flags.zf)
    {
        goto L_0x004976fb;
    }
    // 004976db  ff1514ee5600           -call dword ptr [0x56ee14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697044) /* 0x56ee14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004976e1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004976e3  c1eb0c                 -shr ebx, 0xc
    cpu.ebx >>= 12 /*0xc*/ % 32;
    // 004976e6  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004976eb  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004976f1  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004976f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004976f5:
    // 004976f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004976f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004976f8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004976fb:
    // 004976fb  ff1518ee5600           -call dword ptr [0x56ee18]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697048) /* 0x56ee18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497701  ebf2                   -jmp 0x4976f5
    goto L_0x004976f5;
L_0x00497703:
    // 00497703  ff151cee5600           -call dword ptr [0x56ee1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697052) /* 0x56ee1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497709  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049770b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049770d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049770e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497714(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497714  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497715  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497716  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049771a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049771b  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049771f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497720  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00497724  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497725  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00497729  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049772a  ff1520ee5600           -call dword ptr [0x56ee20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697056) /* 0x56ee20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497730  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497731  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497732  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497738(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497738  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497739  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049773a  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0049773d  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00497741  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497743  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497746  7325                   -jae 0x49776d
    if (!cpu.flags.cf)
    {
        goto L_0x0049776d;
    }
    // 00497748  83fa04                 +cmp edx, 4
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
    // 0049774b  0f83e8000000           -jae 0x497839
    if (!cpu.flags.cf)
    {
        goto L_0x00497839;
    }
    // 00497751  83fa02                 +cmp edx, 2
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
    // 00497754  0f834f010000           -jae 0x4978a9
    if (!cpu.flags.cf)
    {
        goto L_0x004978a9;
    }
    // 0049775a  83fa01                 +cmp edx, 1
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
    // 0049775d  0f8460010000           -je 0x4978c3
    if (cpu.flags.zf)
    {
        goto L_0x004978c3;
    }
L_0x00497763:
    // 00497763  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00497765:
    // 00497765  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00497768  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497769  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049776a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049776d:
    // 0049776d  76f4                   -jbe 0x497763
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497763;
    }
    // 0049776f  83fa0f                 +cmp edx, 0xf
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
    // 00497772  732d                   -jae 0x4977a1
    if (!cpu.flags.cf)
    {
        goto L_0x004977a1;
    }
    // 00497774  83fa0d                 +cmp edx, 0xd
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497777  0f8390000000           -jae 0x49780d
    if (!cpu.flags.cf)
    {
        goto L_0x0049780d;
    }
    // 0049777d  83fa0a                 +cmp edx, 0xa
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
    // 00497780  75e1                   -jne 0x497763
    if (!cpu.flags.zf)
    {
        goto L_0x00497763;
    }
    // 00497782  8b742458               -mov esi, dword ptr [esp + 0x58]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00497786  83fe01                 +cmp esi, 1
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
    // 00497789  0f8396010000           -jae 0x497925
    if (!cpu.flags.cf)
    {
        goto L_0x00497925;
    }
    // 0049778f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00497791  0f84c7010000           -je 0x49795e
    if (cpu.flags.zf)
    {
        goto L_0x0049795e;
    }
    // 00497797  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497799  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049779c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049779d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049779e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004977a1:
    // 004977a1  7724                   -ja 0x4977c7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004977c7;
    }
    // 004977a3  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 004977a8  7505                   -jne 0x4977af
    if (!cpu.flags.zf)
    {
        goto L_0x004977af;
    }
    // 004977aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004977af:
    // 004977af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977b0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004977b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004977b4  ff159cee5600           -call dword ptr [0x56ee9c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697180) /* 0x56ee9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004977ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004977bf  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004977c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004977c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004977c4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004977c7:
    // 004977c7  83fa66                 +cmp edx, 0x66
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004977ca  731c                   -jae 0x4977e8
    if (!cpu.flags.cf)
    {
        goto L_0x004977e8;
    }
    // 004977cc  83fa65                 +cmp edx, 0x65
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004977cf  7592                   -jne 0x497763
    if (!cpu.flags.zf)
    {
        goto L_0x00497763;
    }
    // 004977d1  ff742458               -push dword ptr [esp + 0x58]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    // 004977d5  ff1578ee5600           -call dword ptr [0x56ee78]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697144) /* 0x56ee78 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004977db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004977e0  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004977e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004977e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004977e5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004977e8:
    // 004977e8  0f86fe010000           -jbe 0x4979ec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004979ec;
    }
    // 004977ee  83fa67                 +cmp edx, 0x67
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004977f1  0f856cffffff           -jne 0x497763
    if (!cpu.flags.zf)
    {
        goto L_0x00497763;
    }
    // 004977f7  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004977fb  a3f4cf4d00             -mov dword ptr [0x4dcff4], eax
    app->getMemory<x86::reg32>(x86::reg32(5099508) /* 0x4dcff4 */) = cpu.eax;
    // 00497800  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497805  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00497808  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497809  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049780a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049780d:
    // 0049780d  0f87ad010000           -ja 0x4979c0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004979c0;
    }
    // 00497813  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 00497818  0f84ba010000           -je 0x4979d8
    if (cpu.flags.zf)
    {
        goto L_0x004979d8;
    }
    // 0049781e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00497820  ff1554ee5600           -call dword ptr [0x56ee54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697108) /* 0x56ee54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497826  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00497828  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497829  ff1558ee5600           -call dword ptr [0x56ee58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697112) /* 0x56ee58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049782f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497831  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00497834  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497835  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497836  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00497839:
    // 00497839  0f866b010000           -jbe 0x4979aa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004979aa;
    }
    // 0049783f  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497842  7329                   -jae 0x49786d
    if (!cpu.flags.cf)
    {
        goto L_0x0049786d;
    }
    // 00497844  83fa06                 +cmp edx, 6
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
    // 00497847  0f8516ffffff           -jne 0x497763
    if (!cpu.flags.zf)
    {
        goto L_0x00497763;
    }
    // 0049784d  837c245800             +cmp dword ptr [esp + 0x58], 0
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
    // 00497852  7405                   -je 0x497859
    if (cpu.flags.zf)
    {
        goto L_0x00497859;
    }
    // 00497854  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00497859:
    // 00497859  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049785a  ff1538ee5600           -call dword ptr [0x56ee38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697080) /* 0x56ee38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497860  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497865  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00497868  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497869  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049786a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049786d:
    // 0049786d  0f86f0feffff           -jbe 0x497763
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497763;
    }
    // 00497873  8b5c2458               -mov ebx, dword ptr [esp + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00497877  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00497879  7475                   -je 0x4978f0
    if (cpu.flags.zf)
    {
        goto L_0x004978f0;
    }
    // 0049787b  83fb01                 +cmp ebx, 1
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
    // 0049787e  0f8488000000           -je 0x49790c
    if (cpu.flags.zf)
    {
        goto L_0x0049790c;
    }
    // 00497884  83fb02                 +cmp ebx, 2
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
    // 00497887  0f85d8feffff           -jne 0x497765
    if (!cpu.flags.zf)
    {
        goto L_0x00497765;
    }
    // 0049788d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049788e  ff153cee5600           -call dword ptr [0x56ee3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697084) /* 0x56ee3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497894  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00497896  ff1540ee5600           -call dword ptr [0x56ee40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697088) /* 0x56ee40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049789c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004978a1  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004978a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978a6  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004978a9:
    // 004978a9  772a                   -ja 0x4978d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004978d5;
    }
    // 004978ab  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004978af  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004978b0  ff1530ee5600           -call dword ptr [0x56ee30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697072) /* 0x56ee30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004978b6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004978bb  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004978be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978c0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004978c3:
    // 004978c3  8b5c2458               -mov ebx, dword ptr [esp + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004978c7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004978c8  e81bfdffff             -call 0x4975e8
    cpu.esp -= 4;
    sub_4975e8(app, cpu);
    if (cpu.terminate) return;
    // 004978cd  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004978d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978d2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004978d5:
    // 004978d5  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004978d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004978da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004978db  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004978dd  ff1534ee5600           -call dword ptr [0x56ee34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697076) /* 0x56ee34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004978e3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004978e8  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004978eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004978ed  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004978f0:
    // 004978f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004978f1  ff153cee5600           -call dword ptr [0x56ee3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697084) /* 0x56ee3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004978f7  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004978f9  ff1540ee5600           -call dword ptr [0x56ee40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697088) /* 0x56ee40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004978ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497904  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00497907  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497908  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497909  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049790c:
    // 0049790c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049790d  ff153cee5600           -call dword ptr [0x56ee3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697084) /* 0x56ee3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497913  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00497915  ff1540ee5600           -call dword ptr [0x56ee40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697088) /* 0x56ee40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049791b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049791d  83c448                 +add esp, 0x48
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00497920  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497921  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497922  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00497925:
    // 00497925  7653                   -jbe 0x49797a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049797a;
    }
    // 00497927  83fe02                 +cmp esi, 2
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
    // 0049792a  0f8533feffff           -jne 0x497763
    if (!cpu.flags.zf)
    {
        goto L_0x00497763;
    }
    // 00497930  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497931  ff1544ee5600           -call dword ptr [0x56ee44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697092) /* 0x56ee44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497937  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00497939  ff1548ee5600           -call dword ptr [0x56ee48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697096) /* 0x56ee48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049793f  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 00497944  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497946  a3eccf4d00             -mov dword ptr [0x4dcfec], eax
    app->getMemory<x86::reg32>(x86::reg32(5099500) /* 0x4dcfec */) = cpu.eax;
    // 0049794b  ff154cee5600           -call dword ptr [0x56ee4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697100) /* 0x56ee4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497951  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497956  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00497959  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049795a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049795b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049795e:
    // 0049795e  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00497960  ff1548ee5600           -call dword ptr [0x56ee48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697096) /* 0x56ee48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497966  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497967  ff154cee5600           -call dword ptr [0x56ee4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697100) /* 0x56ee4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049796d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497972  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00497975  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497976  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497977  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049797a:
    // 0049797a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049797c  ff1544ee5600           -call dword ptr [0x56ee44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697092) /* 0x56ee44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497982  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00497984  ff1548ee5600           -call dword ptr [0x56ee48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697096) /* 0x56ee48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049798a  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 0049798f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497991  8915eccf4d00           -mov dword ptr [0x4dcfec], edx
    app->getMemory<x86::reg32>(x86::reg32(5099500) /* 0x4dcfec */) = cpu.edx;
    // 00497997  ff154cee5600           -call dword ptr [0x56ee4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697100) /* 0x56ee4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049799d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004979a2  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004979a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979a7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004979aa:
    // 004979aa  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004979ae  a3e8cf4d00             -mov dword ptr [0x4dcfe8], eax
    app->getMemory<x86::reg32>(x86::reg32(5099496) /* 0x4dcfe8 */) = cpu.eax;
    // 004979b3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004979b8  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004979bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979bd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004979c0:
    // 004979c0  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004979c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004979c5  ff1550ee5600           -call dword ptr [0x56ee50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697104) /* 0x56ee50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004979cb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004979d0  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004979d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979d5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004979d8:
    // 004979d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004979d9  ff1554ee5600           -call dword ptr [0x56ee54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697108) /* 0x56ee54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004979df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004979e4  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004979e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979e9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004979ec:
    // 004979ec  d9442458               -fld dword ptr [esp + 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(88) /* 0x58 */)));
    // 004979f0  e83bebfeff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 004979f5  db5c2440               -fistp dword ptr [esp + 0x40]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004979f9  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004979fd  6689442444             -mov word ptr [esp + 0x44], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00497a02  8b442442               -mov eax, dword ptr [esp + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(66) /* 0x42 */);
    // 00497a06  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00497a09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497a0a  ff157cee5600           -call dword ptr [0x56ee7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697148) /* 0x56ee7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497a10  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00497a15  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00497a18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a1a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497a20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497a21  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00497a24  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00497a26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497a27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497a29  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497a2a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497a2b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497a2c  8b0df0cf4d00           -mov ecx, dword ptr [0x4dcff0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099504) /* 0x4dcff0 */);
    // 00497a32  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497a33  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00497a38  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497a3a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00497a3e  ff155cee5600           -call dword ptr [0x56ee5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697116) /* 0x56ee5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497a44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497a46  7507                   -jne 0x497a4f
    if (!cpu.flags.zf)
    {
        goto L_0x00497a4f;
    }
L_0x00497a48:
    // 00497a48  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497a4a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00497a4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497a4f:
    // 00497a4f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00497a54  e86aeb0000             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 00497a59  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497a5b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00497a5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497a5f  74e7                   -je 0x497a48
    if (cpu.flags.zf)
    {
        goto L_0x00497a48;
    }
    // 00497a61  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497a65  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00497a67  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497a6b  c742080a000000         -mov dword ptr [edx + 8], 0xa
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 10 /*0xa*/;
    // 00497a72  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00497a75  a1f0cf4d00             -mov eax, dword ptr [0x4dcff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099504) /* 0x4dcff0 */);
    // 00497a7a  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00497a7d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497a7f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00497a82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497a84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497a84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497a85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497a86  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00497a8a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00497a8f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00497a91  7507                   -jne 0x497a9a
    if (!cpu.flags.zf)
    {
        goto L_0x00497a9a;
    }
    // 00497a93  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497a95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a97  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00497a9a:
    // 00497a9a  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00497a9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497a9e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497a9f  ff1560ee5600           -call dword ptr [0x56ee60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697120) /* 0x56ee60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497aa5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497aa7  e84c3a0100             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 00497aac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497aae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497aaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ab0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_497ab4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497ab4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497ab5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497ab6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497ab7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497ab8  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00497abc  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00497ac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497ac1  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00497ac4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497ac5  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497ac9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497aca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497acb  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497acf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497ad0  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497ad4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497ad5  8b2df0cf4d00           -mov ebp, dword ptr [0x4dcff0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099504) /* 0x4dcff0 */);
    // 00497adb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497adc  ff1568ee5600           -call dword ptr [0x56ee68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697128) /* 0x56ee68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497ae2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ae3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ae4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ae5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ae6  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497aec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497aec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497aed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497aee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497aef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497af0  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00497af4  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00497af8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497af9  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00497afc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497afd  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497b01  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497b02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497b03  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00497b05  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00497b09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497b0a  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00497b0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497b0f  8b2df0cf4d00           -mov ebp, dword ptr [0x4dcff0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099504) /* 0x4dcff0 */);
    // 00497b15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497b16  ff1564ee5600           -call dword ptr [0x56ee64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697124) /* 0x56ee64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497b1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b20  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_497b24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497b25  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00497b2b  8b9424f8000000         -mov edx, dword ptr [esp + 0xf8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    // 00497b32  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00497b39  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497b3c  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497b42  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497b45  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497b4b  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497b4d  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497b53  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497b56  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497b5c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497b5e  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497b60  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497b63  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497b66  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497b69  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497b6c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497b6e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497b70  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497b73  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497b7a  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497b7d  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497b80  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497b87  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497b8a  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497b8d  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497b90  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497b93  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497b9a  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497b9d  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497ba0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497ba7  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497baa  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497bad  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497bb0  8b9424fc000000         -mov edx, dword ptr [esp + 0xfc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 00497bb7  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00497bbb  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497bbe  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497bc4  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497bc7  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497bcd  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497bcf  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497bd5  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497bd8  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497bde  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497be0  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497be2  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497be5  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497be8  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497beb  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497bee  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497bf0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497bf2  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497bf5  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497bfc  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497bff  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497c02  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497c09  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497c0c  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c0f  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497c12  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497c15  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497c1c  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497c1f  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497c22  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497c29  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497c2c  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c2f  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c32  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00497c39  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00497c3b  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497c3e  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497c44  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497c47  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497c4d  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497c4f  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497c55  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497c58  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497c5e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497c60  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c62  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c65  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497c68  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497c6b  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497c6e  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497c70  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497c72  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497c75  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497c7c  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497c7f  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497c82  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497c89  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497c8c  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c8f  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497c92  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497c95  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497c9c  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497c9f  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497ca2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497ca9  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497cac  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497caf  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497cb2  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00497cb9  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00497cbd  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497cc0  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497cc6  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497cc9  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497ccf  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497cd1  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497cd7  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497cda  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497ce0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497ce2  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497ce4  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497ce7  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497cea  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497ced  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497cf0  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497cf2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497cf4  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497cf7  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497cfe  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497d01  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497d04  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497d0b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497d0e  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497d11  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497d14  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497d17  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497d1e  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497d21  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497d24  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497d2b  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497d2e  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497d31  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497d34  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00497d36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497d37  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00497d3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497d3c  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00497d43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497d44  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497d4a  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00497d4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497d4f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497d53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497d54  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00497d5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497d5c  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497d62  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00497d68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497d69  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_497d6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497d6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497d6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497d6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497d6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497d70  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00497d76  8bac2404010000         -mov ebp, dword ptr [esp + 0x104]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00497d7d  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00497d84  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00497d8b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00497d8d  0f8e45020000           -jle 0x497fd8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497fd8;
    }
L_0x00497d93:
    // 00497d93  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00497d96  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00497d99  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00497d9d  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00497d9f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497da2  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497da8  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497dab  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497db1  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497db3  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497db9  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497dbc  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497dc2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497dc4  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497dc6  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497dc9  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497dcc  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497dcf  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497dd2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497dd4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497dd6  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497dd9  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497de0  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497de3  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497de6  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497ded  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497df0  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497df3  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497df6  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497df9  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497e00  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497e03  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497e06  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497e0d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497e10  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497e13  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497e16  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00497e19  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00497e1c  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00497e20  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00497e22  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497e25  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497e2b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497e2e  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497e34  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497e36  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497e3c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497e3f  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497e45  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497e47  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497e49  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497e4c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497e4f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497e52  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497e55  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497e57  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497e59  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497e5c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497e63  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497e66  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497e69  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497e70  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497e73  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497e76  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497e79  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497e7c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497e83  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497e86  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497e89  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497e90  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497e93  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497e96  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497e99  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00497e9c  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00497e9f  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00497ea6  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00497ea8  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497eab  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497eb1  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497eb4  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497eba  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497ebc  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497ec2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497ec5  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497ecb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497ecd  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497ecf  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497ed2  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497ed5  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497ed8  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497edb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497edd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497edf  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497ee2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497ee9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497eec  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497eef  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497ef6  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497ef9  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497efc  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497eff  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497f02  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497f09  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497f0c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497f0f  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497f16  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497f19  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497f1c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497f1f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00497f21  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00497f24  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00497f26  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00497f28  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00497f2b  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00497f31  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00497f34  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00497f3a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00497f3c  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497f42  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00497f45  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00497f4b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497f4d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497f4f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497f52  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497f55  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00497f58  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00497f5b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00497f5d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497f5f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00497f62  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497f69  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00497f6c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00497f6f  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497f76  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497f79  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497f7c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00497f7f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00497f82  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497f89  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497f8c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497f8f  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00497f96  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00497f99  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497f9c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497f9f  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00497fa3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497fa4  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00497fa8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497fa9  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497fad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497fae  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497fb4  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00497fbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497fbc  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00497fc0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497fc1  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497fc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497fc6  83c610                 +add esi, 0x10
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00497fc9  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497fcf  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00497fd0  0f85bdfdffff           -jne 0x497d93
    if (!cpu.flags.zf)
    {
        goto L_0x00497d93;
    }
    // 00497fd6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00497fd8:
    // 00497fd8  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00497fde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497fdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497fe0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497fe1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497fe2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497fe8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497fe8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497fe9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497fea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497feb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497fec  81ecf0000000           -sub esp, 0xf0
    (cpu.esp) -= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00497ff2  8bac2404010000         -mov ebp, dword ptr [esp + 0x104]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00497ff9  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00498000  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00498007  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498009  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049800c  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498010  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00498012  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498015  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 0049801b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049801e  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498024  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498026  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049802c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049802f  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498035  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498037  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498039  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049803c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049803f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498042  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498045  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498047  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498049  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049804c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498053  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498056  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498059  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498060  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498063  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498066  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498069  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049806c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498073  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498076  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498079  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498080  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498083  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498086  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498089  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049808c  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049808f  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00498093  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00498095  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00498098  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049809b  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004980a1  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004980a4  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004980aa  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004980ac  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004980b2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004980b5  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004980bb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004980bd  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004980bf  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004980c2  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004980c5  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004980c8  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004980cb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004980cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004980cf  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004980d2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004980d9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004980dc  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004980df  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004980e6  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004980e9  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004980ec  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004980ef  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004980f2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004980f9  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004980fc  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004980ff  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498106  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498109  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049810c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049810f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498111  0f8e3e010000           -jle 0x498255
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498255;
    }
L_0x00498117:
    // 00498117  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498119  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049811c  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00498123  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00498125  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498128  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 0049812e  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498131  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498137  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498139  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049813f  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498142  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498148  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049814a  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049814c  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049814f  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498152  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498155  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498158  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049815a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049815c  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049815f  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498166  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498169  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049816c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498173  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498176  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498179  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049817c  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049817f  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498186  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498189  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049818c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498193  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498196  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498199  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049819c  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049819f  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004981a2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004981a4  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004981a6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004981a9  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004981af  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004981b2  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004981b8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004981ba  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004981c0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004981c3  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004981c9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004981cb  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004981cd  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004981d0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004981d3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004981d6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004981d9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004981db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004981dd  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004981e0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004981e7  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004981ea  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004981ed  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004981f4  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004981f7  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004981fa  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004981fd  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498200  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498207  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049820a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049820d  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498214  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498217  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049821a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049821d  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00498224  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498225  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00498229  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049822a  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049822e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049822f  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498235  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0049823c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049823d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498241  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498242  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00498249  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049824a  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498250  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498253  7d0d                   -jge 0x498262
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498262;
    }
L_0x00498255:
    // 00498255  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 0049825b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049825c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049825d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049825e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049825f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00498262:
    // 00498262  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00498265  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498268  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049826c  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049826e  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498271  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498277  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049827a  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498280  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498282  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498288  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049828b  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498291  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498293  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498295  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498298  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049829b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049829e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004982a1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004982a3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004982a5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004982a8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004982af  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004982b2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004982b5  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004982bc  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004982bf  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004982c2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004982c5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004982c8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004982cf  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004982d2  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004982d5  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004982dc  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004982df  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004982e2  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004982e5  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004982e8  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004982eb  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004982ef  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004982f1  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004982f4  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004982fa  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004982fd  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498303  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498305  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049830b  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049830e  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498314  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498316  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498318  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049831b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049831e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498321  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498324  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498326  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498328  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049832b  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498332  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498335  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498338  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049833f  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498342  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498345  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498348  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049834b  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498352  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498355  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498358  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049835f  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498362  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498365  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498368  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049836c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049836d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498371  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498372  8d8424bc000000         -lea eax, [esp + 0xbc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00498379  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049837a  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498380  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498384  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498385  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00498389  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049838a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049838e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049838f  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00498392  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00498395  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049839b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049839d  0f8f74fdffff           -jg 0x498117
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498117;
    }
    // 004983a3  81c4f0000000           -add esp, 0xf0
    (cpu.esp) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004983a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004983ad  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4983b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004983b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004983b1  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 004983b7  8b9424bc000000         -mov edx, dword ptr [esp + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 004983be  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004983c2  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004983c5  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004983cb  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004983ce  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004983d4  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004983d6  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004983dc  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004983df  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004983e5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004983e7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004983e9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004983ec  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004983ef  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004983f2  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004983f5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004983f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004983f9  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004983fc  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498403  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498406  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498409  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498410  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498413  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498416  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498419  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049841c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498423  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498426  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498429  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498430  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498433  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498436  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498439  8b9424c0000000         -mov edx, dword ptr [esp + 0xc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 00498440  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498442  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498445  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 0049844b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049844e  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498454  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498456  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049845c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049845f  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498465  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498467  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498469  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049846c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049846f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498472  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498475  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498477  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498479  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049847c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498483  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498486  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498489  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498490  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498493  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498496  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498499  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049849c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004984a3  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004984a6  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004984a9  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004984b0  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004984b3  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004984b6  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004984b9  8b9424c4000000         -mov edx, dword ptr [esp + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004984c0  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004984c4  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004984c7  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004984cd  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004984d0  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004984d6  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004984d8  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004984de  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004984e1  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004984e7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004984e9  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004984eb  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004984ee  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004984f1  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004984f4  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004984f7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004984f9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004984fb  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004984fe  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498505  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498508  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049850b  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498512  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498515  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498518  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049851b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049851e  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498525  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498528  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049852b  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498532  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498535  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498538  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049853b  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049853f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498540  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498544  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498545  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0049854c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049854d  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498553  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00498559  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049855a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498561  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498562  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498563  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498564  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0049856a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00498571  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00498578  8bb424d0000000         -mov esi, dword ptr [esp + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 0049857f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498581  0f8ea9010000           -jle 0x498730
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498730;
    }
L_0x00498587:
    // 00498587  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049858a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049858d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049858f  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498591  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498594  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 0049859a  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049859d  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004985a3  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004985a5  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004985ab  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004985ae  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004985b4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004985b6  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004985b8  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004985bb  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004985be  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004985c1  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004985c4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004985c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004985c8  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004985cb  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004985d2  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004985d5  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004985d8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004985df  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004985e2  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004985e5  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004985e8  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004985eb  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004985f2  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004985f5  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004985f8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004985ff  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498602  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498605  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498608  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049860b  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049860e  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498612  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498614  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498617  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 0049861d  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498620  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498626  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498628  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049862e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498631  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498637  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498639  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049863b  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049863e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498641  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498644  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498647  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498649  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049864b  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049864e  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498655  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498658  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049865b  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498662  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498665  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498668  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049866b  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049866e  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498675  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498678  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049867b  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498682  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498685  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498688  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049868b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049868d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498690  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00498694  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498696  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498699  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 0049869f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004986a2  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004986a8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004986aa  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004986b0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004986b3  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004986b9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004986bb  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004986bd  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004986c0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004986c3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004986c6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004986c9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004986cb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004986cd  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004986d0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004986d7  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004986da  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004986dd  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004986e4  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004986e7  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004986ea  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004986ed  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004986f0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004986f7  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004986fa  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004986fd  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498704  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498707  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049870a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049870d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498711  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498712  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498716  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498717  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0049871e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049871f  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00498722  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498728  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00498729  0f8558feffff           -jne 0x498587
    if (!cpu.flags.zf)
    {
        goto L_0x00498587;
    }
    // 0049872f  90                     -nop 
    ;
L_0x00498730:
    // 00498730  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00498736  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498737  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498738  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498739  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049873a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498741  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498742  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498743  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498744  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0049874a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00498751  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00498758  8bb424d0000000         -mov esi, dword ptr [esp + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 0049875f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498761  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498764  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498768  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049876a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049876d  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498773  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498776  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 0049877c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049877e  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498784  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498787  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049878d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049878f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498791  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498794  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498797  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049879a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0049879d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049879f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004987a1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004987a4  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004987ab  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004987ae  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004987b1  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004987b8  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004987bb  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004987be  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004987c1  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004987c4  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004987cb  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004987ce  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004987d1  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004987d8  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004987db  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004987de  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004987e1  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004987e4  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004987e7  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004987eb  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004987ed  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004987f0  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004987f3  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004987f9  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004987fc  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498802  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498804  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049880a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049880d  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498813  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498815  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498817  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049881a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049881d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498820  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498823  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498825  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498827  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049882a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498831  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498834  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498837  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049883e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498841  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498844  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498847  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049884a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498851  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498854  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498857  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049885e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498861  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498864  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498867  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498869  0f8e98000000           -jle 0x498907
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498907;
    }
L_0x0049886f:
    // 0049886f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498871  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498874  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498876  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498878  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049887b  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498881  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498884  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 0049888a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049888c  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498892  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498895  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049889b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049889d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049889f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004988a2  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004988a5  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004988a8  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004988ab  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004988ad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004988af  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004988b2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004988b9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004988bc  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004988bf  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004988c6  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004988c9  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004988cc  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004988cf  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004988d2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004988d9  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004988dc  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004988df  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004988e6  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004988e9  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004988ec  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004988ef  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004988f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004988f2  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004988f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004988f7  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004988fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004988fc  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498902  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498905  7d0d                   -jge 0x498914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498914;
    }
L_0x00498907:
    // 00498907  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0049890d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049890e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049890f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498910  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498911  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00498914:
    // 00498914  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00498917  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049891a  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049891e  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498920  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498923  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498929  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049892c  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498932  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498934  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049893a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049893d  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498943  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498945  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498947  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049894a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049894d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498950  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498953  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498955  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498957  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0049895a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498961  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498964  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498967  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049896e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498971  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498974  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498977  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0049897a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498981  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498984  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498987  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049898e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498991  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498994  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498997  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498999  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049899a  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049899e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049899f  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004989a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004989a7  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004989ad  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004989b0  0f8c51ffffff           -jl 0x498907
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498907;
    }
    // 004989b6  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004989b9  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004989bc  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004989c0  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004989c2  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004989c5  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004989cb  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004989ce  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004989d4  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004989d6  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004989dc  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004989df  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004989e5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004989e7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004989e9  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004989ec  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004989ef  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004989f2  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004989f5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004989f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004989f9  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004989fc  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498a03  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498a06  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498a09  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498a10  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498a13  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498a16  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498a19  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498a1c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498a23  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498a26  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498a29  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498a30  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498a33  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498a36  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498a39  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00498a3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498a3e  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00498a42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498a43  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498a47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498a48  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498a4e  83ff04                 +cmp edi, 4
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
    // 00498a51  0f8cb0feffff           -jl 0x498907
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498907;
    }
    // 00498a57  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00498a5a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498a5d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498a5f  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498a61  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498a64  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498a6a  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498a6d  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498a73  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498a75  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498a7b  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498a7e  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498a84  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498a86  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498a88  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498a8b  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498a8e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498a91  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498a94  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498a96  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498a98  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498a9b  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498aa2  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498aa5  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498aa8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498aaf  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498ab2  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498ab5  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498ab8  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498abb  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498ac2  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498ac5  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498ac8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498acf  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498ad2  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498ad5  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498ad8  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00498adc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498add  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498ae1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498ae2  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00498ae6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498ae7  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498aed  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498af0  0f8c11feffff           -jl 0x498907
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498907;
    }
    // 00498af6  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00498af9  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498afc  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498b00  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498b02  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498b05  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498b0b  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498b0e  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498b14  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498b16  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498b1c  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498b1f  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498b25  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498b27  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498b29  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498b2c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498b2f  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498b32  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498b35  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498b37  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498b39  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498b3c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498b43  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498b46  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498b49  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498b50  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498b53  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498b56  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498b59  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498b5c  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498b63  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498b66  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498b69  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498b70  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498b73  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498b76  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498b79  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498b7d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498b7e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498b82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498b83  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00498b8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498b8b  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498b91  83ff06                 +cmp edi, 6
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498b94  0f8c6dfdffff           -jl 0x498907
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498907;
    }
    // 00498b9a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00498b9d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498ba0  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00498ba4  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498ba6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498ba9  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498baf  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498bb2  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498bb8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498bba  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498bc0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498bc3  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498bc9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498bcb  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498bcd  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498bd0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498bd3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498bd6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498bd9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498bdb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498bdd  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498be0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498be7  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498bea  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498bed  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498bf4  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498bf7  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498bfa  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498bfd  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498c00  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498c07  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498c0a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498c0d  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498c14  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498c17  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498c1a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498c1d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498c21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498c22  8d44247c               -lea eax, [esp + 0x7c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00498c26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498c27  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498c2b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498c2c  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00498c2f  83ef06                 -sub edi, 6
    (cpu.edi) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00498c32  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498c38  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498c3a  0f8f2ffcffff           -jg 0x49886f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049886f;
    }
    // 00498c40  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00498c46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c4a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498c50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498c51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498c52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498c53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498c54  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00498c5a  8bbc24c8000000         -mov edi, dword ptr [esp + 0xc8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 00498c61  8bac24cc000000         -mov ebp, dword ptr [esp + 0xcc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 00498c68  8bb424d0000000         -mov esi, dword ptr [esp + 0xd0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(208) /* 0xd0 */);
    // 00498c6f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498c71  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498c74  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00498c78  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498c7a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498c7d  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498c83  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498c86  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498c8c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498c8e  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498c94  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498c97  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498c9d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498c9f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498ca1  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498ca4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498ca7  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498caa  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498cad  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498caf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498cb1  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498cb4  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498cbb  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498cbe  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498cc1  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498cc8  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498ccb  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498cce  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498cd1  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498cd4  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498cdb  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498cde  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498ce1  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498ce8  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498ceb  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498cee  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498cf1  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00498cf4  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498cf7  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498cfb  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498cfd  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00498d00  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498d03  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498d09  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498d0c  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498d12  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498d14  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498d1a  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498d1d  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498d23  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498d25  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498d27  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498d2a  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498d2d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498d30  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498d33  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498d35  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498d37  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498d3a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498d41  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498d44  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498d47  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498d4e  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498d51  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498d54  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498d57  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498d5a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498d61  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498d64  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498d67  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498d6e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498d71  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498d74  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498d77  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498d79  0f8e9b000000           -jle 0x498e1a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498e1a;
    }
L_0x00498d7f:
    // 00498d7f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498d81  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498d84  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498d86  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498d88  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498d8b  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498d91  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498d94  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498d9a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498d9c  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498da2  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498da5  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498dab  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498dad  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498daf  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498db2  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498db5  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498db8  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498dbb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498dbd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498dbf  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498dc2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498dc9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498dcc  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498dcf  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498dd6  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498dd9  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498ddc  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498ddf  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498de2  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498de9  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498dec  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498def  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498df6  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498df9  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498dfc  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498dff  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498e01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498e02  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00498e06  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498e07  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00498e0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498e0f  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498e15  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498e18  7d0d                   -jge 0x498e27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498e27;
    }
L_0x00498e1a:
    // 00498e1a  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00498e20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e24  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00498e27:
    // 00498e27  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00498e2a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00498e2d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498e31  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00498e33  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498e36  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498e3c  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498e3f  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498e45  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498e47  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498e4d  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498e50  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498e56  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498e58  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498e5a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498e5d  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498e60  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498e63  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498e66  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498e68  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498e6a  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498e6d  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498e74  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498e77  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498e7a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498e81  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498e84  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498e87  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498e8a  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498e8d  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498e94  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498e97  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498e9a  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498ea1  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498ea4  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498ea7  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498eaa  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498eae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498eaf  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00498eb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498eb4  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00498ebb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498ebc  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00498ebf  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00498ec2  ff156cee5600           -call dword ptr [0x56ee6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697132) /* 0x56ee6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498ec8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498eca  0f8faffeffff           -jg 0x498d7f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498d7f;
    }
    // 00498ed0  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00498ed6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ed7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ed8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ed9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498eda  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498ee1  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00498ee4  8b942484000000         -mov edx, dword ptr [esp + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00498eeb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498eed  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498ef0  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498ef6  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498ef9  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498eff  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498f01  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498f07  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498f0a  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498f10  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498f12  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498f14  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498f17  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498f1a  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498f1d  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498f20  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498f22  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498f24  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498f27  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498f2e  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498f31  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498f34  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498f3b  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498f3e  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498f41  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498f44  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498f47  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498f4e  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498f51  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498f54  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498f5b  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498f5e  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498f61  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498f64  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00498f6b  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00498f6f  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00498f72  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00498f78  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00498f7b  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00498f81  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00498f83  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498f89  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00498f8c  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00498f92  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00498f94  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498f96  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498f99  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00498f9c  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00498f9f  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00498fa2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00498fa4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498fa6  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00498fa9  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498fb0  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00498fb3  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00498fb6  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498fbd  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00498fc0  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498fc3  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00498fc6  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00498fc9  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498fd0  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00498fd3  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00498fd6  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00498fdd  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00498fe0  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498fe3  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498fe6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00498fe8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498fe9  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00498fed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498fee  ff1570ee5600           -call dword ptr [0x56ee70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697136) /* 0x56ee70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00498ff4  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00498ff7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ff8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_498ffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498ffc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498ffd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498ffe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498fff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499000  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00499003  8bbc248c000000         -mov edi, dword ptr [esp + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049900a  8bac2490000000         -mov ebp, dword ptr [esp + 0x90]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00499011  8bb42494000000         -mov esi, dword ptr [esp + 0x94]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00499018  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049901a  0f8e20010000           -jle 0x499140
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499140;
    }
L_0x00499020:
    // 00499020  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00499023  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00499026  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049902a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049902c  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049902f  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00499035  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00499038  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 0049903e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00499040  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00499046  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00499049  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049904f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00499051  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499053  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499056  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00499059  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049905c  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0049905f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00499061  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499063  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00499066  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049906d  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00499070  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00499073  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049907a  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049907d  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499080  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00499083  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00499086  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049908d  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00499090  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499093  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049909a  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049909d  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004990a0  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004990a3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004990a5  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004990a8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004990aa  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004990ac  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004990af  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004990b5  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004990b8  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004990be  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004990c0  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004990c6  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004990c9  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004990cf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004990d1  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004990d3  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004990d6  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004990d9  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004990dc  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004990df  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004990e1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004990e3  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004990e6  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004990ed  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004990f0  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004990f3  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004990fa  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004990fd  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499100  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00499103  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00499106  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049910d  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00499110  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499113  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049911a  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049911d  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499120  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499123  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00499127  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499128  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049912c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049912d  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499130  ff1570ee5600           -call dword ptr [0x56ee70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697136) /* 0x56ee70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499136  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00499137  0f85e3feffff           -jne 0x499020
    if (!cpu.flags.zf)
    {
        goto L_0x00499020;
    }
    // 0049913d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00499140:
    // 00499140  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00499143  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499144  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499145  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499146  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499147  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49914c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049914c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049914d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049914e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049914f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499150  83ec78                 -sub esp, 0x78
    (cpu.esp) -= x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00499153  8bbc248c000000         -mov edi, dword ptr [esp + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049915a  8bac2490000000         -mov ebp, dword ptr [esp + 0x90]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00499161  8bb42494000000         -mov esi, dword ptr [esp + 0x94]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00499168  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049916a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049916d  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00499171  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00499173  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499176  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00499179  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 0049917f  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00499182  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00499188  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049918a  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00499190  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00499193  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00499199  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049919b  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049919d  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004991a0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004991a3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004991a6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004991a9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004991ab  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004991ad  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004991b0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004991b7  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004991ba  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004991bd  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004991c4  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004991c7  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004991ca  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004991cd  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004991d0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004991d7  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004991da  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004991dd  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004991e4  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004991e7  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004991ea  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004991ed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004991ef  0f8e93000000           -jle 0x499288
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499288;
    }
L_0x004991f5:
    // 004991f5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004991f7  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004991fa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004991fc  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004991fe  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00499201  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00499207  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0049920a  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 00499210  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 00499212  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00499218  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049921b  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00499221  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00499223  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499225  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499228  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049922b  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049922e  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 00499231  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00499233  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499235  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00499238  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049923f  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00499242  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00499245  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049924c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049924f  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499252  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 00499255  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00499258  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049925f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00499262  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499265  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049926c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049926f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499272  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499275  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499277  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499278  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049927c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049927d  ff1570ee5600           -call dword ptr [0x56ee70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697136) /* 0x56ee70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499283  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499286  7d0a                   -jge 0x499292
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00499292;
    }
L_0x00499288:
    // 00499288  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0049928b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049928c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049928d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049928e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049928f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00499292:
    // 00499292  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00499295  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00499298  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049929c  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049929e  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004992a1  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004992a7  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004992aa  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004992b0  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004992b2  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004992b8  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004992bb  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004992c1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004992c3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004992c5  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004992c8  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004992cb  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004992ce  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004992d1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004992d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004992d5  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004992d8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004992df  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004992e2  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004992e5  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004992ec  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004992ef  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004992f2  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004992f5  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004992f8  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004992ff  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00499302  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499305  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049930c  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049930f  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499312  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499315  8d44243c               -lea eax, [esp + 0x3c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00499319  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049931a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049931e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049931f  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499322  83ef02                 -sub edi, 2
    (cpu.edi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499325  ff1570ee5600           -call dword ptr [0x56ee70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697136) /* 0x56ee70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049932b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049932d  0f8fc2feffff           -jg 0x4991f5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004991f5;
    }
    // 00499333  83c478                 -add esp, 0x78
    (cpu.esp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00499336  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499337  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499338  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499339  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049933a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499341  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00499344  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00499348  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049934a  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049934d  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00499353  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00499356  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 0049935c  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049935e  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00499364  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00499367  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049936d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049936f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499371  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499374  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00499377  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049937a  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0049937d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049937f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499381  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00499384  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 0049938b  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049938e  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 00499391  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00499398  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049939b  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049939e  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004993a1  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004993a4  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004993ab  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004993ae  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004993b1  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004993b8  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004993bb  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004993be  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004993c1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004993c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004993c4  ff1574ee5600           -call dword ptr [0x56ee74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697140) /* 0x56ee74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004993ca  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004993cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004993ce  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4993d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004993d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004993d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004993d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004993d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004993d8  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004993db  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004993df  8b6c2454               -mov ebp, dword ptr [esp + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004993e3  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004993e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004993e9  0f8e91000000           -jle 0x499480
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499480;
    }
L_0x004993ef:
    // 004993ef  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004993f1  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004993f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004993f6  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004993f8  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004993fb  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 00499401  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00499404  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 0049940a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049940c  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 00499412  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 00499415  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 0049941b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049941d  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049941f  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00499422  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00499425  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00499428  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0049942b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049942d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049942f  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00499432  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00499439  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049943c  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 0049943f  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00499446  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00499449  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049944c  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 0049944f  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00499452  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00499459  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049945c  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049945f  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00499466  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00499469  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049946c  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049946f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499470  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499473  ff1574ee5600           -call dword ptr [0x56ee74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697140) /* 0x56ee74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499479  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049947a  0f856fffffff           -jne 0x4993ef
    if (!cpu.flags.zf)
    {
        goto L_0x004993ef;
    }
L_0x00499480:
    // 00499480  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00499483  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499484  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499485  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499486  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499487  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49948c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049948c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049948d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049948e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049948f  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00499492  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00499496  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049949a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049949c  0f8e8e000000           -jle 0x499530
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499530;
    }
L_0x004994a2:
    // 004994a2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004994a4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004994a6  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004994a9  d80d30d04d00           -fmul dword ptr [0x4dd030]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099568) /* 0x4dd030 */));
    // 004994af  d9420c                 -fld dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004994b2  d80d2cd04d00           -fmul dword ptr [0x4dd02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5099564) /* 0x4dd02c */));
    // 004994b8  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004994ba  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004994c0  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004994c3  d80534d04d00           -fadd dword ptr [0x4dd034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5099572) /* 0x4dd034 */));
    // 004994c9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004994cb  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004994cd  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004994d0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004994d3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004994d6  d94218                 -fld dword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 004994d9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004994db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004994dd  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004994e0  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004994e7  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004994ea  8a5a12                 -mov bl, byte ptr [edx + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */);
    // 004994ed  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 004994f4  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004994f7  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004994fa  d84a1c                 -fmul dword ptr [edx + 0x1c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */));
    // 004994fd  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 00499500  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00499507  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049950a  8a5a10                 -mov bl, byte ptr [edx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049950d  8b0c9de0e95600         -mov ecx, dword ptr [ebx*4 + 0x56e9e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */ + cpu.ebx * 4);
    // 00499514  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00499517  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049951a  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049951d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049951e  83c620                 +add esi, 0x20
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499521  ff1574ee5600           -call dword ptr [0x56ee74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697140) /* 0x56ee74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499527  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00499528  0f8574ffffff           -jne 0x4994a2
    if (!cpu.flags.zf)
    {
        goto L_0x004994a2;
    }
    // 0049952e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00499530:
    // 00499530  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00499533  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499534  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499535  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499536  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_499540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499540  43                     -inc ebx
    (cpu.ebx)++;
    // 00499541  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00499543  90                     -nop 
    ;
    // 00499544  e93714ffff             -jmp 0x48a980
    return sub_48a980(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49954c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049954c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049954d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049954e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049954f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499551  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499553  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00499555  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499557  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499559  7e2d                   -jle 0x499588
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499588;
    }
    // 0049955b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0049955d:
    // 0049955d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049955f  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00499561  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00499563  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00499565  7425                   -je 0x49958c
    if (cpu.flags.zf)
    {
        goto L_0x0049958c;
    }
    // 00499567  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499569  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049956b  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0049956e  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00499570  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499572  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00499574  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x00499577:
    // 00499577  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499579  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 0049957b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049957d  42                     -inc edx
    (cpu.edx)++;
    // 0049957e  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00499580  40                     -inc eax
    (cpu.eax)++;
    // 00499581  881c31                 -mov byte ptr [ecx + esi], bl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.bl;
    // 00499584  39f8                   +cmp eax, edi
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
    // 00499586  7cd5                   -jl 0x49955d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049955d;
    }
L_0x00499588:
    // 00499588  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499589  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049958a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049958b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049958c:
    // 0049958c  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049958e  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00499591  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00499593  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499599  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0049959c  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004995a2  ebd3                   -jmp 0x499577
    goto L_0x00499577;
}

/* align: skip  */
void Application::sub_4995a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004995a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004995a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004995a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004995a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004995a9  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004995ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004995ad  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004995af  7e1e                   -jle 0x4995cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004995cf;
    }
L_0x004995b1:
    // 004995b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004995b3  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004995b5  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004995b7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004995b9  7418                   -je 0x4995d3
    if (cpu.flags.zf)
    {
        goto L_0x004995d3;
    }
    // 004995bb  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004995bd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004995c3  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 004995c6  42                     -inc edx
    (cpu.edx)++;
    // 004995c7  40                     -inc eax
    (cpu.eax)++;
    // 004995c8  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004995cb  39f0                   +cmp eax, esi
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
    // 004995cd  7ce2                   -jl 0x4995b1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004995b1;
    }
L_0x004995cf:
    // 004995cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004995d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004995d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004995d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004995d3:
    // 004995d3  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004995d5  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004995d8  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004995de  42                     -inc edx
    (cpu.edx)++;
    // 004995df  40                     -inc eax
    (cpu.eax)++;
    // 004995e0  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004995e3  39f0                   +cmp eax, esi
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
    // 004995e5  7cca                   -jl 0x4995b1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004995b1;
    }
    // 004995e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004995e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004995e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004995ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4995ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004995ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004995ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004995ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004995ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004995f0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004995f3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004995f5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004995f7  8b1d60ac4d00           -mov ebx, dword ptr [0x4dac60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090400) /* 0x4dac60 */);
    // 004995fd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004995ff  7563                   -jne 0x499664
    if (!cpu.flags.zf)
    {
        goto L_0x00499664;
    }
    // 00499601  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499603  7e57                   -jle 0x49965c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049965c;
    }
L_0x00499605:
    // 00499605  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00499608  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049960d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049960f  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00499612  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499615  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00499619  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049961b  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 0049961e  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00499621  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499624  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00499628  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049962c  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00499630  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00499633  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 00499636  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049963c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049963f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499641  42                     -inc edx
    (cpu.edx)++;
    // 00499642  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00499644  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499647  e82090feff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 0049964c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00499650  43                     -inc ebx
    (cpu.ebx)++;
    // 00499651  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00499655  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00499658  39f3                   +cmp ebx, esi
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
    // 0049965a  7ca9                   -jl 0x499605
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499605;
    }
L_0x0049965c:
    // 0049965c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049965f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499660  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499661  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499662  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499663  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499664:
    // 00499664  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499666  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499668  7ef2                   -jle 0x49965c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049965c;
    }
L_0x0049966a:
    // 0049966a  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049966d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00499672  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499674  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00499677  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049967a  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049967d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049967f  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00499682  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499685  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00499688  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049968c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049968f  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00499691  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 00499694  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 00499697  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00499699  0b442404               -or eax, dword ptr [esp + 4]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049969d  8b3d60ac4d00           -mov edi, dword ptr [0x4dac60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090400) /* 0x4dac60 */);
    // 004996a3  42                     -inc edx
    (cpu.edx)++;
    // 004996a4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004996a7  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 004996aa  43                     -inc ebx
    (cpu.ebx)++;
    // 004996ab  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004996ae  39f3                   +cmp ebx, esi
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
    // 004996b0  7cb8                   -jl 0x49966a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049966a;
    }
    // 004996b2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004996b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4996bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004996bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004996bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004996be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004996bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004996c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004996c2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004996c4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004996c6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004996c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004996ca  7e1b                   -jle 0x4996e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004996e7;
    }
L_0x004996cc:
    // 004996cc  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004996ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004996d0  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004996d6  7314                   -jae 0x4996ec
    if (!cpu.flags.cf)
    {
        goto L_0x004996ec;
    }
L_0x004996d8:
    // 004996d8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004996db  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004996de  47                     -inc edi
    (cpu.edi)++;
    // 004996df  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004996e3  39ef                   +cmp edi, ebp
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
    // 004996e5  7ce5                   -jl 0x4996cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004996cc;
    }
L_0x004996e7:
    // 004996e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004996ec:
    // 004996ec  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004996ee  7425                   -je 0x499715
    if (cpu.flags.zf)
    {
        goto L_0x00499715;
    }
    // 004996f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004996f2  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004996f8  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004996fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004996fd  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00499700  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00499706  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00499709  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049970c  01c3                   +add ebx, eax
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
    // 0049970e  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00499715:
    // 00499715  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499717  ebbf                   -jmp 0x4996d8
    goto L_0x004996d8;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49971c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049971c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049971d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049971e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049971f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499720  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499722  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499724  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00499726  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00499728  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049972a  7e3c                   -jle 0x499768
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499768;
    }
L_0x0049972c:
    // 0049972c  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049972e  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00499730  7425                   -je 0x499757
    if (cpu.flags.zf)
    {
        goto L_0x00499757;
    }
    // 00499732  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499734  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0049973a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0049973d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049973f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00499742  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00499748  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0049974b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049974e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499750  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00499757:
    // 00499757  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049975a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049975d  47                     -inc edi
    (cpu.edi)++;
    // 0049975e  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00499762  39ef                   +cmp edi, ebp
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
    // 00499764  7cc6                   -jl 0x49972c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049972c;
    }
    // 00499766  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00499768:
    // 00499768  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499769  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049976a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049976b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049976c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499770  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499772  e90912ffff             -jmp 0x48a980
    return sub_48a980(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_499778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499778  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499779  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049977a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049977c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049977e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499780  7e12                   -jle 0x499794
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499794;
    }
L_0x00499782:
    // 00499782  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499785  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00499788  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049978b  41                     -inc ecx
    (cpu.ecx)++;
    // 0049978c  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00499790  39f1                   +cmp ecx, esi
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
    // 00499792  7cee                   -jl 0x499782
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499782;
    }
L_0x00499794:
    // 00499794  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499795  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499796  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499798(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499798  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499799  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049979a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049979b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049979c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049979e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004997a0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004997a2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004997a4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004997a6  7e1b                   -jle 0x4997c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004997c3;
    }
L_0x004997a8:
    // 004997a8  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004997aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004997ac  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004997b2  7314                   -jae 0x4997c8
    if (!cpu.flags.cf)
    {
        goto L_0x004997c8;
    }
L_0x004997b4:
    // 004997b4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004997b7  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004997ba  47                     -inc edi
    (cpu.edi)++;
    // 004997bb  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004997bf  39ef                   +cmp edi, ebp
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
    // 004997c1  7ce5                   -jl 0x4997a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004997a8;
    }
L_0x004997c3:
    // 004997c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004997c8:
    // 004997c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004997ca  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004997d0  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004997d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004997d5  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004997d8  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004997de  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004997e1  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004997e4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004997e6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004997e8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004997ea  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 004997ed  75c5                   -jne 0x4997b4
    if (!cpu.flags.zf)
    {
        goto L_0x004997b4;
    }
    // 004997ef  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004997f4  ebbe                   -jmp 0x4997b4
    goto L_0x004997b4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4997f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004997f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004997f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004997fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004997fb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004997fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004997fe  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499800  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00499802  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00499804  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499806  7e34                   -jle 0x49983c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049983c;
    }
L_0x00499808:
    // 00499808  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049980a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049980c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00499812  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00499815  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499817  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0049981a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00499820  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00499823  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499826  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499828  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049982a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049982d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499830  47                     -inc edi
    (cpu.edi)++;
    // 00499831  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00499835  39ef                   +cmp edi, ebp
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
    // 00499837  7ccf                   -jl 0x499808
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499808;
    }
    // 00499839  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049983c:
    // 0049983c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049983d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049983e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049983f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499840  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499844(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499844  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499845  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499846  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499847  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049984a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049984e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499850  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499852  7e4c                   -jle 0x4998a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004998a0;
    }
L_0x00499854:
    // 00499854  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00499858  0fb67801               -movzx edi, byte ptr [eax + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 0049985c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049985e  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00499861  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00499864  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00499867  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0049986a  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049986e  c1e60c                 -shl esi, 0xc
    cpu.esi <<= 12 /*0xc*/ % 32;
    // 00499871  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00499874  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00499877  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00499879  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049987d  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00499880  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00499883  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00499886  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00499888  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049988b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049988e  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499890  41                     -inc ecx
    (cpu.ecx)++;
    // 00499891  668932                 -mov word ptr [edx], si
    app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
    // 00499894  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499898  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049989b  39f1                   +cmp ecx, esi
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
    // 0049989d  7cb5                   -jl 0x499854
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499854;
    }
    // 0049989f  90                     -nop 
    ;
L_0x004998a0:
    // 004998a0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004998a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4998a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004998a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004998a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004998aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004998ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004998ac  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004998af  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004998b1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004998b3  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004998b6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004998b8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004998ba  7e3c                   -jle 0x4998f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004998f8;
    }
L_0x004998bc:
    // 004998bc  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004998be  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004998c1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004998c3  81e1000000ff           -and ecx, 0xff000000
    cpu.ecx &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004998c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004998cb  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004998d1  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004998d4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004998d6  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004998d9  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004998df  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004998e2  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004998e5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004998e7  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004998e9  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004998eb  45                     -inc ebp
    (cpu.ebp)++;
    // 004998ec  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004998ee  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004998f1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004998f4  39cd                   +cmp ebp, ecx
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
    // 004998f6  7cc4                   -jl 0x4998bc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004998bc;
    }
L_0x004998f8:
    // 004998f8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004998fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499900  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499901  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499902  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499903  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499904  8b2d44d04d00           -mov ebp, dword ptr [0x4dd044]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */);
    // 0049990a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049990c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049990e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00499910  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499912  7e28                   -jle 0x49993c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049993c;
    }
L_0x00499914:
    // 00499914  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499916  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499918  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0049991f  8d042b                 -lea eax, [ebx + ebp]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 00499922  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00499925  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00499928  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049992b  41                     -inc ecx
    (cpu.ecx)++;
    // 0049992c  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049992f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00499932  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00499934  46                     -inc esi
    (cpu.esi)++;
    // 00499935  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00499938  39fe                   +cmp esi, edi
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
    // 0049993a  7cd8                   -jl 0x499914
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499914;
    }
L_0x0049993c:
    // 0049993c  892d44d04d00           -mov dword ptr [0x4dd044], ebp
    app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */) = cpu.ebp;
    // 00499942  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499943  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499944  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499945  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499946  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499948(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499948  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499949  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049994a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049994b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049994e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499950  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00499952  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499954  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499956  7e50                   -jle 0x4999a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004999a8;
    }
L_0x00499958:
    // 00499958  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049995b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00499960  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499962  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 00499965  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499968  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0049996b  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049996e  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00499971  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499973  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499976  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00499979  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049997c  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049997f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00499983  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00499986  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049998a  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049998e  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00499991  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499995  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499998  8842fe                 -mov byte ptr [edx - 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 0049999b  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0049999e  43                     -inc ebx
    (cpu.ebx)++;
    // 0049999f  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004999a2  39fb                   +cmp ebx, edi
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
    // 004999a4  7cb2                   -jl 0x499958
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499958;
    }
    // 004999a6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004999a8:
    // 004999a8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004999ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4999b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004999b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004999b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004999b3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004999ba  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004999bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004999be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004999c0  e8bb0fffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004999c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4999c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004999c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004999c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004999ca  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004999cd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004999cf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004999d1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004999d3  7e3b                   -jle 0x499a10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499a10;
    }
L_0x004999d5:
    // 004999d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004999d7  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004999da  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004999dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004999df  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004999e2  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004999e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004999e8  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004999ea  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004999ee  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004999f1  8a5c2408               -mov bl, byte ptr [esp + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004999f5  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 004999f8  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004999fc  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004999ff  885afe                 -mov byte ptr [edx - 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bl;
    // 00499a02  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00499a05  41                     -inc ecx
    (cpu.ecx)++;
    // 00499a06  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00499a09  39f1                   +cmp ecx, esi
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
    // 00499a0b  7cc8                   -jl 0x4999d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004999d5;
    }
    // 00499a0d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00499a10:
    // 00499a10  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00499a13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499a18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499a19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499a1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499a1b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499a1c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499a1f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499a21  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00499a24  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00499a27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499a29  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499a2b  7e48                   -jle 0x499a75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499a75;
    }
L_0x00499a2d:
    // 00499a2d  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00499a30  8b2d3cd04d00           -mov ebp, dword ptr [0x4dd03c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099580) /* 0x4dd03c */);
    // 00499a36  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00499a3b  39e8                   +cmp eax, ebp
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
    // 00499a3d  743e                   -je 0x499a7d
    if (cpu.flags.zf)
    {
        goto L_0x00499a7d;
    }
    // 00499a3f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499a41  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499a43  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 00499a46  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00499a49  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499a4c  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499a4f  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499a52  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00499a55  c1e60b                 -shl esi, 0xb
    cpu.esi <<= 11 /*0xb*/ % 32;
    // 00499a58  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00499a5e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00499a61  09fe                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
    // 00499a63  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00499a65  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x00499a67:
    // 00499a67  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00499a6a  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499a6d  43                     -inc ebx
    (cpu.ebx)++;
    // 00499a6e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499a71  39fb                   +cmp ebx, edi
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
    // 00499a73  7cb8                   -jl 0x499a2d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499a2d;
    }
L_0x00499a75:
    // 00499a75  83c404                 +add esp, 4
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
    // 00499a78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499a7d:
    // 00499a7d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00499a83  ebe2                   -jmp 0x499a67
    goto L_0x00499a67;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499a88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499a88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499a89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499a8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499a8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499a8c  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499a8f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499a91  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00499a95  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499a99  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499a9b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499a9d  7e50                   -jle 0x499aef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499aef;
    }
L_0x00499a9f:
    // 00499a9f  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00499aa2  8b2d3cd04d00           -mov ebp, dword ptr [0x4dd03c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099580) /* 0x4dd03c */);
    // 00499aa8  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00499aad  39e8                   +cmp eax, ebp
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
    // 00499aaf  7446                   -je 0x499af7
    if (cpu.flags.zf)
    {
        goto L_0x00499af7;
    }
    // 00499ab1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499ab3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499ab5  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00499ab8  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499abb  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00499abe  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00499ac1  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499ac4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00499ac7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499ac9  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00499acc  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 00499acf  c1e60a                 -shl esi, 0xa
    cpu.esi <<= 10 /*0xa*/ % 32;
    // 00499ad2  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00499ad7  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00499ad9  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00499adc  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00499ade  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x00499ae0:
    // 00499ae0  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499ae4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499ae7  43                     -inc ebx
    (cpu.ebx)++;
    // 00499ae8  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499aeb  39fb                   +cmp ebx, edi
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
    // 00499aed  7cb0                   -jl 0x499a9f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499a9f;
    }
L_0x00499aef:
    // 00499aef  83c408                 +add esp, 8
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
    // 00499af2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499af3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499af4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499af5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499af6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499af7:
    // 00499af7  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00499afd  ebe1                   -jmp 0x499ae0
    goto L_0x00499ae0;
}

/* align: skip 0x90 */
void Application::sub_499b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499b00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499b01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499b02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499b03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499b04  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499b07  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499b09  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499b0b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00499b0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499b10  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00499b14  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499b16  7e68                   -jle 0x499b80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499b80;
    }
L_0x00499b18:
    // 00499b18  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 00499b1b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00499b20  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499b22  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 00499b25  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00499b28  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499b2a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499b2c  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00499b2f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00499b32  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00499b35  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00499b37  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00499b39  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00499b3c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499b3f  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00499b41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499b43  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499b46  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 00499b49  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00499b4c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00499b4f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00499b52  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00499b54  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00499b57  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 00499b5a  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499b5c  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499b5e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00499b60  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00499b63  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 00499b66  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499b68  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499b6a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00499b6c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b70  8956fc                 -mov dword ptr [esi - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00499b73  40                     -inc eax
    (cpu.eax)++;
    // 00499b74  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499b77  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00499b7b  39d0                   +cmp eax, edx
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
    // 00499b7d  7c99                   -jl 0x499b18
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499b18;
    }
    // 00499b7f  90                     -nop 
    ;
L_0x00499b80:
    // 00499b80  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499b83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499b88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499b88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499b89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499b8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499b8b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00499b8e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499b90  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00499b94  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499b98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499b9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499b9c  7e56                   -jle 0x499bf4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499bf4;
    }
L_0x00499b9e:
    // 00499b9e  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00499ba1  0fb67803               -movzx edi, byte ptr [eax + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00499ba5  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00499bab  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499bad  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 00499bb0  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499bb3  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00499bb6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499bb8  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00499bbb  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00499bbe  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00499bc1  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00499bc5  8d34d500000000         -lea esi, [edx*8]
    cpu.esi = x86::reg32(cpu.edx * 8);
    // 00499bcc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499bcf  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 00499bd2  c1e213                 -shl edx, 0x13
    cpu.edx <<= 19 /*0x13*/ % 32;
    // 00499bd5  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00499bd7  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499bdb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499bde  c1e70a                 -shl edi, 0xa
    cpu.edi <<= 10 /*0xa*/ % 32;
    // 00499be1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499be4  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00499be6  43                     -inc ebx
    (cpu.ebx)++;
    // 00499be7  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00499be9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499bed  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00499bf0  39f3                   +cmp ebx, esi
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
    // 00499bf2  7caa                   -jl 0x499b9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499b9e;
    }
L_0x00499bf4:
    // 00499bf4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00499bf7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499bf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499bf9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499bfa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499bfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499bfc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499bfd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499bfe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499bff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499c00  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499c03  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00499c06  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499c08  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499c0a  7e34                   -jle 0x499c40
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499c40;
    }
L_0x00499c0c:
    // 00499c0c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499c0e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499c11  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00499c14  0fb67001               -movzx esi, byte ptr [eax + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 00499c18  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00499c1a  0fb628                 -movzx ebp, byte ptr [eax]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00499c1d  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 00499c20  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499c22  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00499c28  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00499c2b  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00499c2e  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00499c30  41                     -inc ecx
    (cpu.ecx)++;
    // 00499c31  09eb                   -or ebx, ebp
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499c33  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00499c36  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00499c39  39f1                   +cmp ecx, esi
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
    // 00499c3b  7ccf                   -jl 0x499c0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499c0c;
    }
    // 00499c3d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00499c40:
    // 00499c40  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499c43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499c48  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00499c4b  e9300dffff             -jmp 0x48a980
    return sub_48a980(app, cpu);
}

/* align: skip  */
void Application::sub_499c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499c50  83f80f                 +cmp eax, 0xf
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
    // 00499c53  7312                   -jae 0x499c67
    if (!cpu.flags.cf)
    {
        goto L_0x00499c67;
    }
    // 00499c55  83f804                 +cmp eax, 4
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
    // 00499c58  722c                   -jb 0x499c86
    if (cpu.flags.cf)
    {
        goto L_0x00499c86;
    }
    // 00499c5a  762a                   -jbe 0x499c86
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c5c  83f808                 +cmp eax, 8
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
    // 00499c5f  7525                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c61  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499c66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c67:
    // 00499c67  7620                   -jbe 0x499c89
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c89;
    }
    // 00499c69  83f818                 +cmp eax, 0x18
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
    // 00499c6c  730b                   -jae 0x499c79
    if (!cpu.flags.cf)
    {
        goto L_0x00499c79;
    }
    // 00499c6e  83f810                 +cmp eax, 0x10
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
    // 00499c71  7513                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c73  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00499c78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c79:
    // 00499c79  7614                   -jbe 0x499c8f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c8f;
    }
    // 00499c7b  83f820                 +cmp eax, 0x20
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
    // 00499c7e  7506                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c80  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00499c85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c86:
    // 00499c86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499c88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c89:
    // 00499c89  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00499c8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c8f:
    // 00499c8f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00499c94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499c89(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00499c89;
    // 00499c50  83f80f                 +cmp eax, 0xf
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
    // 00499c53  7312                   -jae 0x499c67
    if (!cpu.flags.cf)
    {
        goto L_0x00499c67;
    }
    // 00499c55  83f804                 +cmp eax, 4
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
    // 00499c58  722c                   -jb 0x499c86
    if (cpu.flags.cf)
    {
        goto L_0x00499c86;
    }
    // 00499c5a  762a                   -jbe 0x499c86
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c5c  83f808                 +cmp eax, 8
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
    // 00499c5f  7525                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c61  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499c66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c67:
    // 00499c67  7620                   -jbe 0x499c89
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c89;
    }
    // 00499c69  83f818                 +cmp eax, 0x18
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
    // 00499c6c  730b                   -jae 0x499c79
    if (!cpu.flags.cf)
    {
        goto L_0x00499c79;
    }
    // 00499c6e  83f810                 +cmp eax, 0x10
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
    // 00499c71  7513                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c73  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00499c78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c79:
    // 00499c79  7614                   -jbe 0x499c8f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c8f;
    }
    // 00499c7b  83f820                 +cmp eax, 0x20
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
    // 00499c7e  7506                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c80  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00499c85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c86:
    // 00499c86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499c88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c89:
L_entry_0x00499c89:
    // 00499c89  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00499c8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c8f:
    // 00499c8f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00499c94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00499c80;
    // 00499c50  83f80f                 +cmp eax, 0xf
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
    // 00499c53  7312                   -jae 0x499c67
    if (!cpu.flags.cf)
    {
        goto L_0x00499c67;
    }
    // 00499c55  83f804                 +cmp eax, 4
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
    // 00499c58  722c                   -jb 0x499c86
    if (cpu.flags.cf)
    {
        goto L_0x00499c86;
    }
    // 00499c5a  762a                   -jbe 0x499c86
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c5c  83f808                 +cmp eax, 8
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
    // 00499c5f  7525                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c61  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499c66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c67:
    // 00499c67  7620                   -jbe 0x499c89
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c89;
    }
    // 00499c69  83f818                 +cmp eax, 0x18
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
    // 00499c6c  730b                   -jae 0x499c79
    if (!cpu.flags.cf)
    {
        goto L_0x00499c79;
    }
    // 00499c6e  83f810                 +cmp eax, 0x10
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
    // 00499c71  7513                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c73  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00499c78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c79:
    // 00499c79  7614                   -jbe 0x499c8f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c8f;
    }
    // 00499c7b  83f820                 +cmp eax, 0x20
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
    // 00499c7e  7506                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
L_entry_0x00499c80:
    // 00499c80  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00499c85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c86:
    // 00499c86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499c88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c89:
    // 00499c89  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00499c8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c8f:
    // 00499c8f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00499c94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499c73(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00499c73;
    // 00499c50  83f80f                 +cmp eax, 0xf
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
    // 00499c53  7312                   -jae 0x499c67
    if (!cpu.flags.cf)
    {
        goto L_0x00499c67;
    }
    // 00499c55  83f804                 +cmp eax, 4
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
    // 00499c58  722c                   -jb 0x499c86
    if (cpu.flags.cf)
    {
        goto L_0x00499c86;
    }
    // 00499c5a  762a                   -jbe 0x499c86
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c5c  83f808                 +cmp eax, 8
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
    // 00499c5f  7525                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c61  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499c66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c67:
    // 00499c67  7620                   -jbe 0x499c89
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c89;
    }
    // 00499c69  83f818                 +cmp eax, 0x18
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
    // 00499c6c  730b                   -jae 0x499c79
    if (!cpu.flags.cf)
    {
        goto L_0x00499c79;
    }
    // 00499c6e  83f810                 +cmp eax, 0x10
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
    // 00499c71  7513                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
L_entry_0x00499c73:
    // 00499c73  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00499c78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c79:
    // 00499c79  7614                   -jbe 0x499c8f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499c8f;
    }
    // 00499c7b  83f820                 +cmp eax, 0x20
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
    // 00499c7e  7506                   -jne 0x499c86
    if (!cpu.flags.zf)
    {
        goto L_0x00499c86;
    }
    // 00499c80  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00499c85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c86:
    // 00499c86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499c88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c89:
    // 00499c89  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00499c8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499c8f:
    // 00499c8f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00499c94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499c98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499c98  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499c9b  730f                   -jae 0x499cac
    if (!cpu.flags.cf)
    {
        goto L_0x00499cac;
    }
    // 00499c9d  83f842                 +cmp eax, 0x42
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(66 /*0x42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499ca0  7335                   -jae 0x499cd7
    if (!cpu.flags.cf)
    {
        goto L_0x00499cd7;
    }
    // 00499ca2  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499ca5  7248                   -jb 0x499cef
    if (cpu.flags.cf)
    {
        goto L_0x00499cef;
    }
    // 00499ca7  7716                   -ja 0x499cbf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00499cbf;
    }
L_0x00499ca9:
    // 00499ca9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499cab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499cac:
    // 00499cac  76c5                   -jbe 0x499c73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_499c73(app, cpu);
    }
    // 00499cae  83f87d                 +cmp eax, 0x7d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499cb1  7312                   -jae 0x499cc5
    if (!cpu.flags.cf)
    {
        goto L_0x00499cc5;
    }
    // 00499cb3  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499cb6  7237                   -jb 0x499cef
    if (cpu.flags.cf)
    {
        goto L_0x00499cef;
    }
    // 00499cb8  76ef                   -jbe 0x499ca9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499ca9;
    }
    // 00499cba  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499cbd  7530                   -jne 0x499cef
    if (!cpu.flags.zf)
    {
        goto L_0x00499cef;
    }
L_0x00499cbf:
    // 00499cbf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00499cc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499cc5:
    // 00499cc5  76b9                   -jbe 0x499c80
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_499c80(app, cpu);
    }
    // 00499cc7  83f87e                 +cmp eax, 0x7e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(126 /*0x7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499cca  76bd                   -jbe 0x499c89
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_499c89(app, cpu);
    }
    // 00499ccc  83f87f                 +cmp eax, 0x7f
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
    // 00499ccf  751e                   -jne 0x499cef
    if (!cpu.flags.zf)
    {
        goto L_0x00499cef;
    }
L_0x00499cd1:
    // 00499cd1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00499cd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499cd7:
    // 00499cd7  7610                   -jbe 0x499ce9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499ce9;
    }
    // 00499cd9  83f843                 +cmp eax, 0x43
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499cdc  76f3                   -jbe 0x499cd1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499cd1;
    }
    // 00499cde  83f86d                 +cmp eax, 0x6d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499ce1  750c                   -jne 0x499cef
    if (!cpu.flags.zf)
    {
        goto L_0x00499cef;
    }
    // 00499ce3  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00499ce8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499ce9:
    // 00499ce9  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00499cee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499cef:
    // 00499cef  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00499cf4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499cf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499cf8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499cf9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499cfa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499cfb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499cfc  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00499d02  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499d04  e817480000             -call 0x49e520
    cpu.esp -= 4;
    sub_49e520(app, cpu);
    if (cpu.terminate) return;
    // 00499d09  bf600e5700             -mov edi, 0x570e60
    cpu.edi = 5705312 /*0x570e60*/;
    // 00499d0e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499d10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499d12  7448                   -je 0x499d5c
    if (cpu.flags.zf)
    {
        goto L_0x00499d5c;
    }
    // 00499d14  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00499d16  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499d1c  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00499d1f  83fe2a                 +cmp esi, 0x2a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d22  7445                   -je 0x499d69
    if (cpu.flags.zf)
    {
        goto L_0x00499d69;
    }
    // 00499d24  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00499d27  c781fc03000000000000   -mov dword ptr [ecx + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00499d31  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499d33  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00499d35  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499d3b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00499d3e  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d41  742a                   -je 0x499d6d
    if (cpu.flags.zf)
    {
        goto L_0x00499d6d;
    }
    // 00499d43  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d46  7432                   -je 0x499d7a
    if (cpu.flags.zf)
    {
        goto L_0x00499d7a;
    }
    // 00499d48  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d4b  7438                   -je 0x499d85
    if (cpu.flags.zf)
    {
        goto L_0x00499d85;
    }
    // 00499d4d  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d50  743e                   -je 0x499d90
    if (cpu.flags.zf)
    {
        goto L_0x00499d90;
    }
    // 00499d52  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d55  7444                   -je 0x499d9b
    if (cpu.flags.zf)
    {
        goto L_0x00499d9b;
    }
    // 00499d57  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d5a  744c                   -je 0x499da8
    if (cpu.flags.zf)
    {
        goto L_0x00499da8;
    }
L_0x00499d5c:
    // 00499d5c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499d5e  81c400020000           +add esp, 0x200
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499d64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499d69:
    // 00499d69  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499d6b  ebef                   -jmp 0x499d5c
    goto L_0x00499d5c;
L_0x00499d6d:
    // 00499d6d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499d6f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499d71  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499d73  e83c3e0100             -call 0x4adbb4
    cpu.esp -= 4;
    sub_4adbb4(app, cpu);
    if (cpu.terminate) return;
    // 00499d78  ebe2                   -jmp 0x499d5c
    goto L_0x00499d5c;
L_0x00499d7a:
    // 00499d7a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499d7c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499d7e  e805fdffff             -call 0x499a88
    cpu.esp -= 4;
    sub_499a88(app, cpu);
    if (cpu.terminate) return;
    // 00499d83  ebd7                   -jmp 0x499d5c
    goto L_0x00499d5c;
L_0x00499d85:
    // 00499d85  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499d87  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499d89  e88afcffff             -call 0x499a18
    cpu.esp -= 4;
    sub_499a18(app, cpu);
    if (cpu.terminate) return;
    // 00499d8e  ebcc                   -jmp 0x499d5c
    goto L_0x00499d5c;
L_0x00499d90:
    // 00499d90  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499d92  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499d94  e8effdffff             -call 0x499b88
    cpu.esp -= 4;
    sub_499b88(app, cpu);
    if (cpu.terminate) return;
    // 00499d99  ebc1                   -jmp 0x499d5c
    goto L_0x00499d5c;
L_0x00499d9b:
    // 00499d9b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499d9d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499d9f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499da1  e81a3d0100             -call 0x4adac0
    cpu.esp -= 4;
    sub_4adac0(app, cpu);
    if (cpu.terminate) return;
    // 00499da6  ebb4                   -jmp 0x499d5c
    goto L_0x00499d5c;
L_0x00499da8:
    // 00499da8  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00499dad  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00499daf  e8e0cd0000             -call 0x4a6b94
    cpu.esp -= 4;
    sub_4a6b94(app, cpu);
    if (cpu.terminate) return;
    // 00499db4  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00499db9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499dbb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499dbd  e856fcffff             -call 0x499a18
    cpu.esp -= 4;
    sub_499a18(app, cpu);
    if (cpu.terminate) return;
    // 00499dc2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499dc4  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00499dca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499dd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499dd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499dd4  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00499dda  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499ddc  e83f470000             -call 0x49e520
    cpu.esp -= 4;
    sub_49e520(app, cpu);
    if (cpu.terminate) return;
    // 00499de1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499de3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499de5  0f84b4000000           -je 0x499e9f
    if (cpu.flags.zf)
    {
        goto L_0x00499e9f;
    }
    // 00499deb  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00499ded  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499df3  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00499df6  83fb29                 +cmp ebx, 0x29
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499df9  7444                   -je 0x499e3f
    if (cpu.flags.zf)
    {
        goto L_0x00499e3f;
    }
    // 00499dfb  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00499dfe  66c781fe0100000000     -mov word ptr [ecx + 0x1fe], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(510) /* 0x1fe */) = 0 /*0x0*/;
    // 00499e07  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499e09  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00499e0b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499e11  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00499e14  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499e17  742a                   -je 0x499e43
    if (cpu.flags.zf)
    {
        goto L_0x00499e43;
    }
    // 00499e19  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499e1c  743d                   -je 0x499e5b
    if (cpu.flags.zf)
    {
        goto L_0x00499e5b;
    }
    // 00499e1e  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499e21  7443                   -je 0x499e66
    if (cpu.flags.zf)
    {
        goto L_0x00499e66;
    }
    // 00499e23  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499e26  7428                   -je 0x499e50
    if (cpu.flags.zf)
    {
        goto L_0x00499e50;
    }
    // 00499e28  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499e2b  7444                   -je 0x499e71
    if (cpu.flags.zf)
    {
        goto L_0x00499e71;
    }
    // 00499e2d  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499e30  7457                   -je 0x499e89
    if (cpu.flags.zf)
    {
        goto L_0x00499e89;
    }
L_0x00499e32:
    // 00499e32  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499e34  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499e3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e3e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499e3f:
    // 00499e3f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499e41  ebef                   -jmp 0x499e32
    goto L_0x00499e32;
L_0x00499e43:
    // 00499e43  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00499e45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499e47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499e49  e8663d0100             -call 0x4adbb4
    cpu.esp -= 4;
    sub_4adbb4(app, cpu);
    if (cpu.terminate) return;
    // 00499e4e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00499e50:
    // 00499e50  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499e52  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499e54  e83ff9ffff             -call 0x499798
    cpu.esp -= 4;
    sub_499798(app, cpu);
    if (cpu.terminate) return;
    // 00499e59  ebd7                   -jmp 0x499e32
    goto L_0x00499e32;
L_0x00499e5b:
    // 00499e5b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499e5d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499e5f  e814f9ffff             -call 0x499778
    cpu.esp -= 4;
    sub_499778(app, cpu);
    if (cpu.terminate) return;
    // 00499e64  ebcc                   -jmp 0x499e32
    goto L_0x00499e32;
L_0x00499e66:
    // 00499e66  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499e68  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499e6a  e8a9fbffff             -call 0x499a18
    cpu.esp -= 4;
    sub_499a18(app, cpu);
    if (cpu.terminate) return;
    // 00499e6f  ebc1                   -jmp 0x499e32
    goto L_0x00499e32;
L_0x00499e71:
    // 00499e71  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00499e73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499e75  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499e77  e8443c0100             -call 0x4adac0
    cpu.esp -= 4;
    sub_4adac0(app, cpu);
    if (cpu.terminate) return;
    // 00499e7c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499e7e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499e80  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499e82  e811f9ffff             -call 0x499798
    cpu.esp -= 4;
    sub_499798(app, cpu);
    if (cpu.terminate) return;
    // 00499e87  eba9                   -jmp 0x499e32
    goto L_0x00499e32;
L_0x00499e89:
    // 00499e89  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00499e8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499e8d  e802cd0000             -call 0x4a6b94
    cpu.esp -= 4;
    sub_4a6b94(app, cpu);
    if (cpu.terminate) return;
    // 00499e92  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499e94  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00499e9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499e9f:
    // 00499e9f  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00499ea4  b8600e5700             -mov eax, 0x570e60
    cpu.eax = 5705312 /*0x570e60*/;
    // 00499ea9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499eab  e8e8f8ffff             -call 0x499798
    cpu.esp -= 4;
    sub_499798(app, cpu);
    if (cpu.terminate) return;
    // 00499eb0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00499eb2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499eb4  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00499eba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ebb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ebc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ebd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ebe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499ec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499ec2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499ec3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499ec4  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00499eca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499ecc  e84f460000             -call 0x49e520
    cpu.esp -= 4;
    sub_49e520(app, cpu);
    if (cpu.terminate) return;
    // 00499ed1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499ed3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499ed5  0f84e1000000           -je 0x499fbc
    if (cpu.flags.zf)
    {
        goto L_0x00499fbc;
    }
    // 00499edb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00499edd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499ee3  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00499ee6  83f92c                 +cmp ecx, 0x2c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499ee9  7445                   -je 0x499f30
    if (cpu.flags.zf)
    {
        goto L_0x00499f30;
    }
    // 00499eeb  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00499eee  c786fc03000000000000   -mov dword ptr [esi + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00499ef8  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499efa  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00499efc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499f02  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00499f05  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499f08  742a                   -je 0x499f34
    if (cpu.flags.zf)
    {
        goto L_0x00499f34;
    }
    // 00499f0a  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499f0d  743d                   -je 0x499f4c
    if (cpu.flags.zf)
    {
        goto L_0x00499f4c;
    }
    // 00499f0f  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499f12  744e                   -je 0x499f62
    if (cpu.flags.zf)
    {
        goto L_0x00499f62;
    }
    // 00499f14  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499f17  7454                   -je 0x499f6d
    if (cpu.flags.zf)
    {
        goto L_0x00499f6d;
    }
    // 00499f19  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499f1c  745a                   -je 0x499f78
    if (cpu.flags.zf)
    {
        goto L_0x00499f78;
    }
    // 00499f1e  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499f21  746d                   -je 0x499f90
    if (cpu.flags.zf)
    {
        goto L_0x00499f90;
    }
L_0x00499f23:
    // 00499f23  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499f25  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499f2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499f30:
    // 00499f30  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499f32  ebef                   -jmp 0x499f23
    goto L_0x00499f23;
L_0x00499f34:
    // 00499f34  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00499f36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499f38  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499f3a  e8753c0100             -call 0x4adbb4
    cpu.esp -= 4;
    sub_4adbb4(app, cpu);
    if (cpu.terminate) return;
    // 00499f3f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499f41  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f43  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499f45  e85ef9ffff             -call 0x4998a8
    cpu.esp -= 4;
    sub_4998a8(app, cpu);
    if (cpu.terminate) return;
    // 00499f4a  ebd7                   -jmp 0x499f23
    goto L_0x00499f23;
L_0x00499f4c:
    // 00499f4c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00499f4e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f50  e833fbffff             -call 0x499a88
    cpu.esp -= 4;
    sub_499a88(app, cpu);
    if (cpu.terminate) return;
    // 00499f55  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499f57  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f59  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499f5b  e848f9ffff             -call 0x4998a8
    cpu.esp -= 4;
    sub_4998a8(app, cpu);
    if (cpu.terminate) return;
    // 00499f60  ebc1                   -jmp 0x499f23
    goto L_0x00499f23;
L_0x00499f62:
    // 00499f62  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00499f64  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f66  e8adfaffff             -call 0x499a18
    cpu.esp -= 4;
    sub_499a18(app, cpu);
    if (cpu.terminate) return;
    // 00499f6b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00499f6d:
    // 00499f6d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f6f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499f71  e832f9ffff             -call 0x4998a8
    cpu.esp -= 4;
    sub_4998a8(app, cpu);
    if (cpu.terminate) return;
    // 00499f76  ebab                   -jmp 0x499f23
    goto L_0x00499f23;
L_0x00499f78:
    // 00499f78  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00499f7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499f7c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499f7e  e83d3b0100             -call 0x4adac0
    cpu.esp -= 4;
    sub_4adac0(app, cpu);
    if (cpu.terminate) return;
    // 00499f83  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499f85  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f87  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499f89  e81af9ffff             -call 0x4998a8
    cpu.esp -= 4;
    sub_4998a8(app, cpu);
    if (cpu.terminate) return;
    // 00499f8e  eb93                   -jmp 0x499f23
    goto L_0x00499f23;
L_0x00499f90:
    // 00499f90  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f92  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499f94  e8fbcb0000             -call 0x4a6b94
    cpu.esp -= 4;
    sub_4a6b94(app, cpu);
    if (cpu.terminate) return;
    // 00499f99  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00499f9b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499f9d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499f9f  e8e4faffff             -call 0x499a88
    cpu.esp -= 4;
    sub_499a88(app, cpu);
    if (cpu.terminate) return;
    // 00499fa4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499fa6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499fa8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499faa  e8f9f8ffff             -call 0x4998a8
    cpu.esp -= 4;
    sub_4998a8(app, cpu);
    if (cpu.terminate) return;
    // 00499faf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499fb1  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00499fb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fbb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499fbc:
    // 00499fbc  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00499fc1  b8600e5700             -mov eax, 0x570e60
    cpu.eax = 5705312 /*0x570e60*/;
    // 00499fc6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499fc8  e8dbf8ffff             -call 0x4998a8
    cpu.esp -= 4;
    sub_4998a8(app, cpu);
    if (cpu.terminate) return;
    // 00499fcd  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00499fcf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499fd1  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00499fd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499fdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499fdc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499fdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499fde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499fdf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499fe0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499fe3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499fe5  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00499fe9  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00499feb  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499ff1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499ff3  e8a0fcffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 00499ff8  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00499fff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a001  e892fcffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a006  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a008  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a00a  8a8148d24d00           -mov al, byte ptr [ecx + 0x4dd248]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5100104) /* 0x4dd248 */);
    // 0049a010  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a012  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049a015  39c2                   +cmp edx, eax
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
    // 0049a017  754d                   -jne 0x49a066
    if (!cpu.flags.zf)
    {
        goto L_0x0049a066;
    }
    // 0049a019  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0049a01e  7550                   -jne 0x49a070
    if (!cpu.flags.zf)
    {
        goto L_0x0049a070;
    }
    // 0049a020  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a022  e871fcffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a027  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0049a02e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a030  e863fcffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a035  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a037  8b2c8548d14d00         -mov ebp, dword ptr [eax*4 + 0x4dd148]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099848) /* 0x4dd148 */ + cpu.eax * 4);
L_0x0049a03e:
    // 0049a03e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a040  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a042  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049a045  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049a04b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a04d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a04f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a051  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049a054  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049a05a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a05c  83f908                 +cmp ecx, 8
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
    // 0049a05f  7f05                   -jg 0x49a066
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a066;
    }
    // 0049a061  83f808                 +cmp eax, 8
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
    // 0049a064  7f2a                   -jg 0x49a090
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a090;
    }
L_0x0049a066:
    // 0049a066  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a068  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049a06b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a06c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a06d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a06e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a06f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a070:
    // 0049a070  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a072  e821fcffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a077  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0049a07e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a080  e813fcffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a085  01c8                   +add eax, ecx
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
    // 0049a087  8b2c8548d04d00         -mov ebp, dword ptr [eax*4 + 0x4dd048]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099592) /* 0x4dd048 */ + cpu.eax * 4);
    // 0049a08e  ebae                   -jmp 0x49a03e
    goto L_0x0049a03e;
L_0x0049a090:
    // 0049a090  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a095  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a097  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049a09c  e857fcffff             -call 0x499cf8
    cpu.esp -= 4;
    sub_499cf8(app, cpu);
    if (cpu.terminate) return;
    // 0049a0a1  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049a0a5  a344d04d00             -mov dword ptr [0x4dd044], eax
    app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */) = cpu.eax;
    // 0049a0aa  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049a0ac  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049a0ae  7432                   -je 0x49a0e2
    if (cpu.flags.zf)
    {
        goto L_0x0049a0e2;
    }
    // 0049a0b0  83fe0f                 +cmp esi, 0xf
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
    // 0049a0b3  7419                   -je 0x49a0ce
    if (cpu.flags.zf)
    {
        goto L_0x0049a0ce;
    }
    // 0049a0b5  83fe10                 +cmp esi, 0x10
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
    // 0049a0b8  75ac                   -jne 0x49a066
    if (!cpu.flags.zf)
    {
        goto L_0x0049a066;
    }
    // 0049a0ba  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a0bf  e8d4f6ffff             -call 0x499798
    cpu.esp -= 4;
    sub_499798(app, cpu);
    if (cpu.terminate) return;
    // 0049a0c4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a0c6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049a0c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a0ce:
    // 0049a0ce  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a0d3  e8e4f5ffff             -call 0x4996bc
    cpu.esp -= 4;
    sub_4996bc(app, cpu);
    if (cpu.terminate) return;
    // 0049a0d8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a0da  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049a0dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a0e2:
    // 0049a0e2  83fe0f                 +cmp esi, 0xf
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
    // 0049a0e5  741d                   -je 0x49a104
    if (cpu.flags.zf)
    {
        goto L_0x0049a104;
    }
    // 0049a0e7  83fe10                 +cmp esi, 0x10
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
    // 0049a0ea  0f8576ffffff           -jne 0x49a066
    if (!cpu.flags.zf)
    {
        goto L_0x0049a066;
    }
    // 0049a0f0  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a0f5  e8fef6ffff             -call 0x4997f8
    cpu.esp -= 4;
    sub_4997f8(app, cpu);
    if (cpu.terminate) return;
    // 0049a0fa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a0fc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049a0ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a100  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a101  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a102  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a103  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a104:
    // 0049a104  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a109  e80ef6ffff             -call 0x49971c
    cpu.esp -= 4;
    sub_49971c(app, cpu);
    if (cpu.terminate) return;
    // 0049a10e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a110  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049a113  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a114  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a115  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a116  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a117  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a118(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a118  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a119  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a11a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a11b  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0049a11e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a120  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0049a124  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0049a128  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0049a12c  e8ef430000             -call 0x49e520
    cpu.esp -= 4;
    sub_49e520(app, cpu);
    if (cpu.terminate) return;
    // 0049a131  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0049a136  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a138  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049a13c  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0049a140  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
L_0x0049a144:
    // 0049a144  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 0049a149  0f8580020000           -jne 0x49a3cf
    if (!cpu.flags.zf)
    {
        goto L_0x0049a3cf;
    }
    // 0049a14f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049a151  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a156  e83dfbffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a15b  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0049a162  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049a166  e82dfbffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a16b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049a16d  8b048548d14d00         -mov eax, dword ptr [eax*4 + 0x4dd148]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099848) /* 0x4dd148 */ + cpu.eax * 4);
L_0x0049a174:
    // 0049a174  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0049a178  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049a17a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a17f  e814fbffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a184  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0049a18b  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049a18f  e804fbffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a194  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a196  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a198  8a8248d24d00           -mov al, byte ptr [edx + 0x4dd248]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5100104) /* 0x4dd248 */);
    // 0049a19e  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049a1a2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a1a4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a1a6  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049a1a9  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049a1af  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a1b1  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049a1b5  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a1b9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a1bb  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049a1be  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049a1c4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049a1c6  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0049a1ca  40                     -inc eax
    (cpu.eax)++;
    // 0049a1cb  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049a1cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a1cf  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0049a1d2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049a1d5  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0049a1d9  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049a1dc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049a1df  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 0049a1e3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a1e5  e8b6f40000             -call 0x4a96a0
    cpu.esp -= 4;
    sub_4a96a0(app, cpu);
    if (cpu.terminate) return;
    // 0049a1ea  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049a1ee  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049a1f2  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a1f5  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0049a1f8  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0049a1fa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049a1fc  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0049a1ff  83f908                 +cmp ecx, 8
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
    // 0049a202  0f8f73000000           -jg 0x49a27b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a27b;
    }
    // 0049a208  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a20b  7e6e                   -jle 0x49a27b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a27b;
    }
    // 0049a20d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049a212  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049a216  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049a218  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a21a  0f84d9010000           -je 0x49a3f9
    if (cpu.flags.zf)
    {
        goto L_0x0049a3f9;
    }
    // 0049a220  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a222  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a224  7e1e                   -jle 0x49a244
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a244;
    }
    // 0049a226  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049a228:
    // 0049a228  0fb6b0e8d54d00         -movzx esi, byte ptr [eax + 0x4dd5e8]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */));
    // 0049a22f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a232  8b34b5600e5700         -mov esi, dword ptr [esi*4 + 0x570e60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.esi * 4);
    // 0049a239  40                     -inc eax
    (cpu.eax)++;
    // 0049a23a  89b138ef5600           -mov dword ptr [ecx + 0x56ef38], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5697336) /* 0x56ef38 */) = cpu.esi;
    // 0049a240  39d8                   +cmp eax, ebx
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
    // 0049a242  7ce4                   -jl 0x49a228
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a228;
    }
L_0x0049a244:
    // 0049a244  c70544d04d003cef5600   -mov dword ptr [0x4dd044], 0x56ef3c
    app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */) = 5697340 /*0x56ef3c*/;
L_0x0049a24e:
    // 0049a24e  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 0049a253  0f84d5010000           -je 0x49a42e
    if (cpu.flags.zf)
    {
        goto L_0x0049a42e;
    }
    // 0049a259  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049a25d  83f80f                 +cmp eax, 0xf
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
    // 0049a260  0f85ab010000           -jne 0x49a411
    if (!cpu.flags.zf)
    {
        goto L_0x0049a411;
    }
    // 0049a266  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a26b  a144d04d00             -mov eax, dword ptr [0x4dd044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */);
    // 0049a270  e847f4ffff             -call 0x4996bc
    cpu.esp -= 4;
    sub_4996bc(app, cpu);
    if (cpu.terminate) return;
L_0x0049a275:
    // 0049a275  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a277  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
L_0x0049a27b:
    // 0049a27b  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049a27f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a280  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049a284  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a285  68d80c4d00             -push 0x4d0cd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049560 /*0x4d0cd8*/;
    cpu.esp -= 4;
    // 0049a28a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a28e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a28f  e86dc2feff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0049a294  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a297  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049a29b  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049a29e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a2a0  8b1de8ab4d00           -mov ebx, dword ptr [0x4dabe8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 0049a2a6  8d5614                 -lea edx, [esi + 0x14]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049a2a9  e8eaa1feff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 0049a2ae  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049a2b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a2b5  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0049a2b9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a2bb  ba50485343             -mov edx, 0x43534850
    cpu.edx = 1129531472 /*0x43534850*/;
    // 0049a2c0  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a2c3  e88c1dffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0049a2c8  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a2cc  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 0049a2cf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a2d4  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049a2d6  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a2d8  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049a2dc  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049a2de  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0049a2e0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a2e6  66894104               -mov word ptr [ecx + 4], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0049a2ea  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049a2ee  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0049a2f0  66894106               -mov word ptr [ecx + 6], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 0049a2f4  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049a2f8  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0049a2fc  668b470a               -mov ax, word ptr [edi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0049a300  668b510c               -mov dx, word ptr [ecx + 0xc]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049a304  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0049a308  81e200f0ffff           -and edx, 0xfffff000
    cpu.edx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0049a30e  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049a311  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 0049a315  25ff0f0000             -and eax, 0xfff
    cpu.eax &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 0049a31a  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049a31d  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a320  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a322  8971fc                 -mov dword ptr [ecx - 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0049a325  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 0049a329  8d7710                 -lea esi, [edi + 0x10]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049a32c  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0049a332  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049a335  668959fe               -mov word ptr [ecx - 2], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 0049a339  250000ff0f             -and eax, 0xfff0000
    cpu.eax &= x86::reg32(x86::sreg32(268369920 /*0xfff0000*/));
    // 0049a33e  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 0049a341  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049a343  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a345  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049a349  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049a34c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a34e  7e1d                   -jle 0x49a36d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a36d;
    }
L_0x0049a350:
    // 0049a350  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049a354  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a356  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a358  ff54244c               -call dword ptr [esp + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a35c  47                     -inc edi
    (cpu.edi)++;
    // 0049a35d  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049a361  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049a365  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a367  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a369  39d7                   +cmp edi, edx
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
    // 0049a36b  7ce3                   -jl 0x49a350
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a350;
    }
L_0x0049a36d:
    // 0049a36d  0faf6c2454             -imul ebp, dword ptr [esp + 0x54]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */))));
    // 0049a372  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049a376  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a378  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049a37d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a380  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049a384  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a386  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049a388  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049a38a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049a391  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049a393  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a395  7407                   -je 0x49a39e
    if (cpu.flags.zf)
    {
        goto L_0x0049a39e;
    }
    // 0049a397  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a399  e85ea5feff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0049a39e:
    // 0049a39e  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049a3a2  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0049a3a6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a3a8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a3aa  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049a3ae  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a3b3  39f0                   +cmp eax, esi
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
    // 0049a3b5  740f                   -je 0x49a3c6
    if (cpu.flags.zf)
    {
        goto L_0x0049a3c6;
    }
    // 0049a3b7  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049a3bb  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049a3bc  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 0049a3c0  0f857efdffff           -jne 0x49a144
    if (!cpu.flags.zf)
    {
        goto L_0x0049a144;
    }
L_0x0049a3c6:
    // 0049a3c6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a3c8  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0049a3cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a3cf:
    // 0049a3cf  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049a3d1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a3d6  e8bdf8ffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a3db  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 0049a3e2  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049a3e6  e8adf8ffff             -call 0x499c98
    cpu.esp -= 4;
    sub_499c98(app, cpu);
    if (cpu.terminate) return;
    // 0049a3eb  01d0                   +add eax, edx
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
    // 0049a3ed  8b048548d04d00         -mov eax, dword ptr [eax*4 + 0x4dd048]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099592) /* 0x4dd048 */ + cpu.eax * 4);
    // 0049a3f4  e97bfdffff             -jmp 0x49a174
    goto L_0x0049a174;
L_0x0049a3f9:
    // 0049a3f9  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a3fe  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049a402  e8f1f8ffff             -call 0x499cf8
    cpu.esp -= 4;
    sub_499cf8(app, cpu);
    if (cpu.terminate) return;
    // 0049a407  a344d04d00             -mov dword ptr [0x4dd044], eax
    app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */) = cpu.eax;
    // 0049a40c  e93dfeffff             -jmp 0x49a24e
    goto L_0x0049a24e;
L_0x0049a411:
    // 0049a411  83f810                 +cmp eax, 0x10
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
    // 0049a414  0f855bfeffff           -jne 0x49a275
    if (!cpu.flags.zf)
    {
        goto L_0x0049a275;
    }
    // 0049a41a  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a41f  a144d04d00             -mov eax, dword ptr [0x4dd044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */);
    // 0049a424  e86ff3ffff             -call 0x499798
    cpu.esp -= 4;
    sub_499798(app, cpu);
    if (cpu.terminate) return;
    // 0049a429  e947feffff             -jmp 0x49a275
    goto L_0x0049a275;
L_0x0049a42e:
    // 0049a42e  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049a432  83f90f                 +cmp ecx, 0xf
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
    // 0049a435  741d                   -je 0x49a454
    if (cpu.flags.zf)
    {
        goto L_0x0049a454;
    }
    // 0049a437  83f910                 +cmp ecx, 0x10
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
    // 0049a43a  0f8535feffff           -jne 0x49a275
    if (!cpu.flags.zf)
    {
        goto L_0x0049a275;
    }
    // 0049a440  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a445  a144d04d00             -mov eax, dword ptr [0x4dd044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */);
    // 0049a44a  e8a9f3ffff             -call 0x4997f8
    cpu.esp -= 4;
    sub_4997f8(app, cpu);
    if (cpu.terminate) return;
    // 0049a44f  e921feffff             -jmp 0x49a275
    goto L_0x0049a275;
L_0x0049a454:
    // 0049a454  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a459  a144d04d00             -mov eax, dword ptr [0x4dd044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */);
    // 0049a45e  e8b9f2ffff             -call 0x49971c
    cpu.esp -= 4;
    sub_49971c(app, cpu);
    if (cpu.terminate) return;
    // 0049a463  e90dfeffff             -jmp 0x49a275
    goto L_0x0049a275;
}

/* align: skip  */
void Application::sub_49a468(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a468  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a469  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a46a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049a46f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a471  e8a2fcffff             -call 0x49a118
    cpu.esp -= 4;
    sub_49a118(app, cpu);
    if (cpu.terminate) return;
    // 0049a476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a477  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a478  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49a47c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a47c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a47d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a47e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a47f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a481  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a483  e8f8260100             -call 0x4acb80
    cpu.esp -= 4;
    sub_4acb80(app, cpu);
    if (cpu.terminate) return;
    // 0049a488  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049a48d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a48f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a491  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a493  e880fcffff             -call 0x49a118
    cpu.esp -= 4;
    sub_49a118(app, cpu);
    if (cpu.terminate) return;
    // 0049a498  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a499  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a49a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a49b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_49a4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a4a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a4a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a4a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a4a3  81ec24020000           -sub esp, 0x224
    (cpu.esp) -= x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0049a4a9  8bb42434020000         -mov esi, dword ptr [esp + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(564) /* 0x234 */);
    // 0049a4b0  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0049a4b7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049a4b9  899c240c020000         -mov dword ptr [esp + 0x20c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.ebx;
    // 0049a4c0  898c2420020000         -mov dword ptr [esp + 0x220], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ecx;
    // 0049a4c7  8bbc2410020000         -mov edi, dword ptr [esp + 0x210]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049a4ce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a4d0  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a4d3  8994241c020000         -mov dword ptr [esp + 0x21c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.edx;
    // 0049a4da  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049a4dd  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049a4e0  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 0049a4e7  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0049a4ea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a4ec  0f84bd000000           -je 0x49a5af
    if (cpu.flags.zf)
    {
        goto L_0x0049a5af;
    }
    // 0049a4f2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a4f4  0f84b5000000           -je 0x49a5af
    if (cpu.flags.zf)
    {
        goto L_0x0049a5af;
    }
    // 0049a4fa  a1a8ab4d00             -mov eax, dword ptr [0x4daba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 0049a4ff  89942404020000         -mov dword ptr [esp + 0x204], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.edx;
    // 0049a506  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a508  7418                   -je 0x49a522
    if (cpu.flags.zf)
    {
        goto L_0x0049a522;
    }
    // 0049a50a  833dacab4d0000         +cmp dword ptr [0x4dabac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a511  0f84a4000000           -je 0x49a5bb
    if (cpu.flags.zf)
    {
        goto L_0x0049a5bb;
    }
    // 0049a517  c784241c02000040924a00 -mov dword ptr [esp + 0x21c], 0x4a9240
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4887104 /*0x4a9240*/;
L_0x0049a522:
    // 0049a522  8b942410020000         -mov edx, dword ptr [esp + 0x210]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049a529  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a52b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049a52d  a05db24d00             -mov al, byte ptr [0x4db25d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091933) /* 0x4db25d */);
    // 0049a532  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a538  39c2                   +cmp edx, eax
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
    // 0049a53a  744c                   -je 0x49a588
    if (cpu.flags.zf)
    {
        goto L_0x0049a588;
    }
    // 0049a53c  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049a543  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a545  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049a548  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0049a54e  83f808                 +cmp eax, 8
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
    // 0049a551  0f8574000000           -jne 0x49a5cb
    if (!cpu.flags.zf)
    {
        goto L_0x0049a5cb;
    }
    // 0049a557  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
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
    // 0049a55e  756b                   -jne 0x49a5cb
    if (!cpu.flags.zf)
    {
        goto L_0x0049a5cb;
    }
    // 0049a560  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049a562  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049a569  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 0049a56e  e85df8ffff             -call 0x499dd0
    cpu.esp -= 4;
    sub_499dd0(app, cpu);
    if (cpu.terminate) return;
    // 0049a573  ba3cef5600             -mov edx, 0x56ef3c
    cpu.edx = 5697340 /*0x56ef3c*/;
    // 0049a578  e80304ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0049a57d  c784241c020000fe904a00 -mov dword ptr [esp + 0x21c], 0x4a90fe
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4886782 /*0x4a90fe*/;
L_0x0049a588:
    // 0049a588  3b2d54b24d00           +cmp ebp, dword ptr [0x4db254]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a58e  7c63                   -jl 0x49a5f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a5f3;
    }
L_0x0049a590:
    // 0049a590  8b942404020000         -mov edx, dword ptr [esp + 0x204]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 0049a597  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a599  7407                   -je 0x49a5a2
    if (cpu.flags.zf)
    {
        goto L_0x0049a5a2;
    }
    // 0049a59b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a59d  e85aa3feff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0049a5a2:
    // 0049a5a2  833dacab4d0000         +cmp dword ptr [0x4dabac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a5a9  0f8582020000           -jne 0x49a831
    if (!cpu.flags.zf)
    {
        goto L_0x0049a831;
    }
L_0x0049a5af:
    // 0049a5af  81c424020000           +add esp, 0x224
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(548 /*0x224*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a5b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a5b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a5b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a5b8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049a5bb:
    // 0049a5bb  c784241c0200001a954a00 -mov dword ptr [esp + 0x21c], 0x4a951a
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4887834 /*0x4a951a*/;
    // 0049a5c6  e957ffffff             -jmp 0x49a522
    goto L_0x0049a522;
L_0x0049a5cb:
    // 0049a5cb  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049a5d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a5d4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a5d6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049a5d8  8a155db24d00           -mov dl, byte ptr [0x4db25d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5091933) /* 0x4db25d */);
    // 0049a5de  e835fbffff             -call 0x49a118
    cpu.esp -= 4;
    sub_49a118(app, cpu);
    if (cpu.terminate) return;
    // 0049a5e3  89842404020000         -mov dword ptr [esp + 0x204], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.eax;
    // 0049a5ea  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0049a5f1  eb95                   -jmp 0x49a588
    goto L_0x0049a588;
L_0x0049a5f3:
    // 0049a5f3  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049a5fa  3b0558b24d00           +cmp eax, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a600  7d8e                   -jge 0x49a590
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a590;
    }
    // 0049a602  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049a609  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a60b  0f8ee9010000           -jle 0x49a7fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a7fa;
    }
    // 0049a611  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049a613:
    // 0049a613  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 0049a619  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a61b  39d0                   +cmp eax, edx
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
    // 0049a61d  0f8e6dffffff           -jle 0x49a590
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a590;
    }
    // 0049a623  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a625  0f8ed8010000           -jle 0x49a803
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a803;
    }
    // 0049a62b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049a62d:
    // 0049a62d  8b8c240c020000         -mov ecx, dword ptr [esp + 0x20c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049a634  8b1d50b24d00           -mov ebx, dword ptr [0x4db250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 0049a63a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a63c  39d8                   +cmp eax, ebx
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
    // 0049a63e  0f8e4cffffff           -jle 0x49a590
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a590;
    }
    // 0049a644  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049a64b  8b942408020000         -mov edx, dword ptr [esp + 0x208]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0049a652  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049a659  e842f00000             -call 0x4a96a0
    cpu.esp -= 4;
    sub_4a96a0(app, cpu);
    if (cpu.terminate) return;
    // 0049a65e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049a661  89842414020000         -mov dword ptr [esp + 0x214], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.eax;
    // 0049a668  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a66a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a66d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a66f  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0049a672  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a674  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049a676  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a678  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a67b  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a67d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a67f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a682  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 0049a689  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a68b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049a68d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a68f  0f8c77010000           -jl 0x49a80c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a80c;
    }
    // 0049a695  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049a697:
    // 0049a697  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a699  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a69b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a69e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a6a0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049a6a2  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049a6a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a6ab  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a6ad  0f8c62010000           -jl 0x49a815
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a815;
    }
L_0x0049a6b3:
    // 0049a6b3  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049a6ba  8b1d50b24d00           -mov ebx, dword ptr [0x4db250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 0049a6c0  39d8                   +cmp eax, ebx
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
    // 0049a6c2  7d23                   -jge 0x49a6e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a6e7;
    }
    // 0049a6c4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a6c6  2b84240c020000         -sub eax, dword ptr [esp + 0x20c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */)));
    // 0049a6cd  8b9c2418020000         -mov ebx, dword ptr [esp + 0x218]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0049a6d4  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049a6d7  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a6d9  a150b24d00             -mov eax, dword ptr [0x4db250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 0049a6de  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a6e0  8984240c020000         -mov dword ptr [esp + 0x20c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.eax;
L_0x0049a6e7:
    // 0049a6e7  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049a6ee  8b1d58b24d00           -mov ebx, dword ptr [0x4db258]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 0049a6f4  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a6f6  39d8                   +cmp eax, ebx
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
    // 0049a6f8  7e0b                   -jle 0x49a705
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a705;
    }
    // 0049a6fa  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049a701  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049a703  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049a705:
    // 0049a705  8b1d4cb24d00           -mov ebx, dword ptr [0x4db24c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 0049a70b  39dd                   +cmp ebp, ebx
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
    // 0049a70d  7d14                   -jge 0x49a723
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a723;
    }
    // 0049a70f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a711  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a713  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049a715  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049a718  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a71a  29842420020000         -sub dword ptr [esp + 0x220], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a721  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0049a723:
    // 0049a723  8b842420020000         -mov eax, dword ptr [esp + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049a72a  8b1d54b24d00           -mov ebx, dword ptr [0x4db254]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 0049a730  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a732  39d8                   +cmp eax, ebx
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
    // 0049a734  7e0b                   -jle 0x49a741
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a741;
    }
    // 0049a736  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a738  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a73a  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x0049a741:
    // 0049a741  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049a748  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a74b  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 0049a752  8b9c2400020000         -mov ebx, dword ptr [esp + 0x200]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0049a759  a16cb24d00             -mov eax, dword ptr [0x4db26c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 0049a75e  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0049a761  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a763  a170b24d00             -mov eax, dword ptr [0x4db270]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 0049a768  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a76a  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a76c  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a76e  8b84241c020000         -mov eax, dword ptr [esp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 0049a775  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a779  750b                   -jne 0x49a786
    if (!cpu.flags.zf)
    {
        goto L_0x0049a786;
    }
    // 0049a77b  c784241c020000658f4a00 -mov dword ptr [esp + 0x21c], 0x4a8f65
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4886373 /*0x4a8f65*/;
L_0x0049a786:
    // 0049a786  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a788  8b842420020000         -mov eax, dword ptr [esp + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049a78f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a790  8b9c240c020000         -mov ebx, dword ptr [esp + 0x20c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0049a797  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a798  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049a79a  b8644f5b00             -mov eax, 0x5b4f64
    cpu.eax = 5984100 /*0x5b4f64*/;
    // 0049a79f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a7a1  e85aef0000             -call 0x4a9700
    cpu.esp -= 4;
    sub_4a9700(app, cpu);
    if (cpu.terminate) return;
    // 0049a7a6  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0049a7ad  ba644f5b00             -mov edx, 0x5b4f64
    cpu.edx = 5984100 /*0x5b4f64*/;
    // 0049a7b2  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a7b5  e8d2e40000             -call 0x4a8c8c
    cpu.esp -= 4;
    sub_4a8c8c(app, cpu);
    if (cpu.terminate) return;
L_0x0049a7ba:
    // 0049a7ba  4e                     -dec esi
    (cpu.esi)--;
    // 0049a7bb  83feff                 +cmp esi, -1
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
    // 0049a7be  0f84ccfdffff           -je 0x49a590
    if (cpu.flags.zf)
    {
        goto L_0x0049a590;
    }
    // 0049a7c4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a7c6  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0049a7cd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049a7d0  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a7d3  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0049a7da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a7db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a7dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a7dd  ff942428020000         -call dword ptr [esp + 0x228]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a7e4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049a7e7  8b1d68b24d00           -mov ebx, dword ptr [0x4db268]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 0049a7ed  8b842418020000         -mov eax, dword ptr [esp + 0x218]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0049a7f4  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a7f6  01c7                   +add edi, eax
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
    // 0049a7f8  ebc0                   -jmp 0x49a7ba
    goto L_0x0049a7ba;
L_0x0049a7fa:
    // 0049a7fa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a7fc  f7d8                   +neg eax
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
    // 0049a7fe  e910feffff             -jmp 0x49a613
    goto L_0x0049a613;
L_0x0049a803:
    // 0049a803  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a805  f7d8                   +neg eax
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
    // 0049a807  e921feffff             -jmp 0x49a62d
    goto L_0x0049a62d;
L_0x0049a80c:
    // 0049a80c  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0049a80e  01c7                   +add edi, eax
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
    // 0049a810  e982feffff             -jmp 0x49a697
    goto L_0x0049a697;
L_0x0049a815:
    // 0049a815  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a817  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049a819  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
    // 0049a820  8b842408020000         -mov eax, dword ptr [esp + 0x208]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0049a827  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049a82a  01c2                   +add edx, eax
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
    // 0049a82c  e982feffff             -jmp 0x49a6b3
    goto L_0x0049a6b3;
L_0x0049a831:
    // 0049a831  0f77                   -emms 
    cpu.mmx.init();
    // 0049a833  81c424020000           -add esp, 0x224
    (cpu.esp) += x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0049a839  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a83a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a83b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a83c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49a840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a840  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a841  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a842  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a843  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049a846  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a848  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049a84a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049a84d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049a84f  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049a852  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049a855  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a857  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049a85b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049a85e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049a862  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a864  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a867  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a869  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049a86c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049a870  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0049a873  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049a876  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a878  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a87a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a87d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a87f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049a881  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a883  7d50                   -jge 0x49a8d5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a8d5;
    }
    // 0049a885  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049a888  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049a88c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049a88f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a891  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a893  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a895  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a897  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049a89a  c1e810                 +shr eax, 0x10
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
    // 0049a89d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049a89f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049a8a1:
    // 0049a8a1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a8a3  7c46                   -jl 0x49a8eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a8eb;
    }
    // 0049a8a5  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049a8a8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a8aa  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049a8ad  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049a8b0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a8b2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049a8b5  c1e810                 +shr eax, 0x10
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
    // 0049a8b8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049a8ba  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049a8bc:
    // 0049a8bc  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049a8c0  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049a8c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a8c3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049a8c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a8c7  e8d4fbffff             -call 0x49a4a0
    cpu.esp -= 4;
    sub_49a4a0(app, cpu);
    if (cpu.terminate) return;
    // 0049a8cc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049a8cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8d2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049a8d5:
    // 0049a8d5  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049a8d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a8da  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049a8dd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a8df  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049a8e2  c1e810                 +shr eax, 0x10
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
    // 0049a8e5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049a8e7  29c5                   +sub ebp, eax
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
    // 0049a8e9  ebb6                   -jmp 0x49a8a1
    goto L_0x0049a8a1;
L_0x0049a8eb:
    // 0049a8eb  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049a8ee  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049a8f1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049a8f4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049a8f7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a8f9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a8fb  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049a8fe  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a900  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049a903  c1e810                 +shr eax, 0x10
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
    // 0049a906  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049a908  01c3                   +add ebx, eax
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
    // 0049a90a  ebb0                   -jmp 0x49a8bc
    goto L_0x0049a8bc;
}

/* align: skip  */
void Application::sub_49a90c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a90c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a90d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a90e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a90f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049a911  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049a914  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049a917  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0049a91a  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0049a91d  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0049a920  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0049a923  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049a925  e876fbffff             -call 0x49a4a0
    cpu.esp -= 4;
    sub_49a4a0(app, cpu);
    if (cpu.terminate) return;
    // 0049a92a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a92b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a92c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49a930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a930  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a931  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a932  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a934  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049a936  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a93a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a93c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a93d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a93f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a941  e85afbffff             -call 0x49a4a0
    cpu.esp -= 4;
    sub_49a4a0(app, cpu);
    if (cpu.terminate) return;
    // 0049a946  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a947  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a948  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49a94c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a94c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a94d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a94e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a950  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049a952  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a956  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a958  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a959  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a95b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a95d  e8defeffff             -call 0x49a840
    cpu.esp -= 4;
    sub_49a840(app, cpu);
    if (cpu.terminate) return;
    // 0049a962  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a963  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a964  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49a968(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a968  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a969  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049a96b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049a96d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a96f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a971  e896ffffff             -call 0x49a90c
    cpu.esp -= 4;
    sub_49a90c(app, cpu);
    if (cpu.terminate) return;
    // 0049a976  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a977  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
