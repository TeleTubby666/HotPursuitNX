#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_4a40c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a40c0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a40c2  e9815efeff             -jmp 0x489f48
    return sub_489f48(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4a40c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a40c8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a40ca  e9915efeff             -jmp 0x489f60
    return sub_489f60(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_4a40d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a40d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a40d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a40d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a40d3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a40d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a40d7  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a40d9  7412                   -je 0x4a40ed
    if (cpu.flags.zf)
    {
        goto L_0x004a40ed;
    }
L_0x004a40db:
    // 004a40db  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a40dd  80f95c                 +cmp cl, 0x5c
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a40e0  7511                   -jne 0x4a40f3
    if (!cpu.flags.zf)
    {
        goto L_0x004a40f3;
    }
L_0x004a40e2:
    // 004a40e2  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a40e5  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a40e8  40                     -inc eax
    (cpu.eax)++;
    // 004a40e9  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004a40eb  75ee                   -jne 0x4a40db
    if (!cpu.flags.zf)
    {
        goto L_0x004a40db;
    }
L_0x004a40ed:
    // 004a40ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a40ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a40f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a40f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a40f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a40f3:
    // 004a40f3  80f93a                 +cmp cl, 0x3a
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a40f6  74ea                   -je 0x4a40e2
    if (cpu.flags.zf)
    {
        goto L_0x004a40e2;
    }
    // 004a40f8  80f92f                 +cmp cl, 0x2f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a40fb  74e5                   -je 0x4a40e2
    if (cpu.flags.zf)
    {
        goto L_0x004a40e2;
    }
    // 004a40fd  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a4100  40                     -inc eax
    (cpu.eax)++;
    // 004a4101  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004a4103  75d6                   -jne 0x4a40db
    if (!cpu.flags.zf)
    {
        goto L_0x004a40db;
    }
    // 004a4105  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4107  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4108  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4109  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a410a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a4110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4113  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4115  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a411a  e8a1ffffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a411f  804a1940               -or byte ptr [edx + 0x19], 0x40
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004a4123  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004a4128  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a412b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a412d  ba444e4542             -mov edx, 0x42454e44
    cpu.edx = 1111838276 /*0x42454e44*/;
    // 004a4132  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4134  e81b7ffeff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 004a4139  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a413e  e885ffffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a4143  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4144  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4145  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4146  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a4148(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4148  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4149  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a414a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a414b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a414d  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4152  e869ffffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a4157  8a6219                 -mov ah, byte ptr [edx + 0x19]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */);
    // 004a415a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a415f  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004a4162  7510                   -jne 0x4a4174
    if (!cpu.flags.zf)
    {
        goto L_0x004a4174;
    }
L_0x004a4164:
    // 004a4164  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4169  e85affffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a416e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a4170  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4171  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4172  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4173  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4174:
    // 004a4174  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4176  034214                 -add eax, dword ptr [edx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
    // 004a4179  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004a417e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4180  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a4182  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a4184  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a418b  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a418d  3d444e4542             +cmp eax, 0x42454e44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1111838276 /*0x42454e44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4192  74d0                   -je 0x4a4164
    if (cpu.flags.zf)
    {
        goto L_0x004a4164;
    }
    // 004a4194  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4196  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a419b  e828ffffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a41a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a41a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a41a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a41a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a41a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a41a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a41a8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a41ad  eb05                   -jmp 0x4a41b4
    return sub_4a41b4(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4a41b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a41b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a41b2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a41b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a41b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a41b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a41b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a41b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a41b9  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a41be  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a41c3  e8f8feffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a41c8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a41ca  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a41cc:
    // 004a41cc  3bbe843d5600           +cmp edi, dword ptr [esi + 0x563d84]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651844) /* 0x563d84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41d2  7420                   -je 0x4a41f4
    if (cpu.flags.zf)
    {
        goto L_0x004a41f4;
    }
    // 004a41d4  8b96803d5600           -mov edx, dword ptr [esi + 0x563d80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651840) /* 0x563d80 */);
    // 004a41da  8b9e843d5600           -mov ebx, dword ptr [esi + 0x563d84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651844) /* 0x563d84 */);
L_0x004a41e0:
    // 004a41e0  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a41e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a41e5  e85effffff             -call 0x4a4148
    cpu.esp -= 4;
    sub_4a4148(app, cpu);
    if (cpu.terminate) return;
    // 004a41ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a41ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a41ee  7404                   -je 0x4a41f4
    if (cpu.flags.zf)
    {
        goto L_0x004a41f4;
    }
    // 004a41f0  39da                   +cmp edx, ebx
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
    // 004a41f2  75ec                   -jne 0x4a41e0
    if (!cpu.flags.zf)
    {
        goto L_0x004a41e0;
    }
L_0x004a41f4:
    // 004a41f4  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a41f7  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41fd  7d04                   -jge 0x4a4203
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4203;
    }
    // 004a41ff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a4201  75c9                   -jne 0x4a41cc
    if (!cpu.flags.zf)
    {
        goto L_0x004a41cc;
    }
L_0x004a4203:
    // 004a4203  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4208  e8bbfeffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a420d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a420f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4210  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4211  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4212  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4213  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4214  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a41b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a41b4;
    // 004a41b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a41b2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004a41b4:
    // 004a41b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a41b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a41b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a41b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a41b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a41b9  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a41be  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a41c3  e8f8feffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a41c8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a41ca  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a41cc:
    // 004a41cc  3bbe843d5600           +cmp edi, dword ptr [esi + 0x563d84]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651844) /* 0x563d84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41d2  7420                   -je 0x4a41f4
    if (cpu.flags.zf)
    {
        goto L_0x004a41f4;
    }
    // 004a41d4  8b96803d5600           -mov edx, dword ptr [esi + 0x563d80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651840) /* 0x563d80 */);
    // 004a41da  8b9e843d5600           -mov ebx, dword ptr [esi + 0x563d84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651844) /* 0x563d84 */);
L_0x004a41e0:
    // 004a41e0  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a41e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a41e5  e85effffff             -call 0x4a4148
    cpu.esp -= 4;
    sub_4a4148(app, cpu);
    if (cpu.terminate) return;
    // 004a41ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a41ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a41ee  7404                   -je 0x4a41f4
    if (cpu.flags.zf)
    {
        goto L_0x004a41f4;
    }
    // 004a41f0  39da                   +cmp edx, ebx
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
    // 004a41f2  75ec                   -jne 0x4a41e0
    if (!cpu.flags.zf)
    {
        goto L_0x004a41e0;
    }
L_0x004a41f4:
    // 004a41f4  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a41f7  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a41fd  7d04                   -jge 0x4a4203
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4203;
    }
    // 004a41ff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a4201  75c9                   -jne 0x4a41cc
    if (!cpu.flags.zf)
    {
        goto L_0x004a41cc;
    }
L_0x004a4203:
    // 004a4203  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4208  e8bbfeffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a420d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a420f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4210  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4211  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4212  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4213  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4214  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a4220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4221  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4226  e895feffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a422b  a1ecb14d00             -mov eax, dword ptr [0x4db1ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 004a4230  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4232  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a4235  e80e000000             -call 0x4a4248
    cpu.esp -= 4;
    sub_4a4248(app, cpu);
    if (cpu.terminate) return;
    // 004a423a  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a423f  e884feffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a4244  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a4248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4248  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4249  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a424a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a424b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a424c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a424d  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a4250  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4252  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a4254  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4256  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a4259  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a425d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a425f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
L_0x004a4261:
    // 004a4261  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004a4263:
    // 004a4263  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a4265  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a4268  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a426a  39d3                   +cmp ebx, edx
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
    // 004a426c  731b                   -jae 0x4a4289
    if (!cpu.flags.cf)
    {
        goto L_0x004a4289;
    }
    // 004a426e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a4270  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a4272  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a4274  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a4276:
    // 004a4276  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a4278  741a                   -je 0x4a4294
    if (cpu.flags.zf)
    {
        goto L_0x004a4294;
    }
L_0x004a427a:
    // 004a427a  39fe                   +cmp esi, edi
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
    // 004a427c  7416                   -je 0x4a4294
    if (cpu.flags.zf)
    {
        goto L_0x004a4294;
    }
    // 004a427e  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 004a4282  751d                   -jne 0x4a42a1
    if (!cpu.flags.zf)
    {
        goto L_0x004a42a1;
    }
    // 004a4284  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a4287  ebf1                   -jmp 0x4a427a
    goto L_0x004a427a;
L_0x004a4289:
    // 004a4289  39f9                   +cmp ecx, edi
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
    // 004a428b  74e9                   -je 0x4a4276
    if (cpu.flags.zf)
    {
        goto L_0x004a4276;
    }
    // 004a428d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a428f  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004a4292  ebcf                   -jmp 0x4a4263
    goto L_0x004a4263;
L_0x004a4294:
    // 004a4294  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a4298  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a429b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a429c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a429d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a429e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a429f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a42a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a42a1:
    // 004a42a1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a42a3  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a42a6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a42a8  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a42ab  8d1c2a                 -lea ebx, [edx + ebp]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 004a42ae  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a42b2  3b1424                 +cmp edx, dword ptr [esp]
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
    // 004a42b5  7412                   -je 0x4a42c9
    if (cpu.flags.zf)
    {
        goto L_0x004a42c9;
    }
    // 004a42b7  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a42ba  39d5                   +cmp ebp, edx
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
    // 004a42bc  7d2f                   -jge 0x4a42ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a42ed;
    }
    // 004a42be  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a42c0  39f9                   +cmp ecx, edi
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
    // 004a42c2  74d0                   -je 0x4a4294
    if (cpu.flags.zf)
    {
        goto L_0x004a4294;
    }
    // 004a42c4  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004a42c7  eb98                   -jmp 0x4a4261
    goto L_0x004a4261;
L_0x004a42c9:
    // 004a42c9  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a42cd  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a42d0  29d5                   +sub ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a42d2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a42d4  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a42d6  e8a566feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a42db  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a42e0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a42e2  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 004a42e4  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a42e8  e974ffffff             -jmp 0x4a4261
    goto L_0x004a4261;
L_0x004a42ed:
    // 004a42ed  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a42f1  29d5                   +sub ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a42f3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a42f5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a42f7  e88466feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a42fc  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a42ff  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a4302  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 004a4304  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a4307  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a430a  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a430d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a4310  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a4313  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004a4316  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a4319  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004a431c  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004a4321  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004a4324  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a4328  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a432a  e932ffffff             -jmp 0x4a4261
    goto L_0x004a4261;
}

/* align: skip 0x90 */
void Application::sub_4a4330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4330  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4331  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4336  e885fdffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a433b  a1ecb14d00             -mov eax, dword ptr [0x4db1ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 004a4340  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a4343  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4345  e80e000000             -call 0x4a4358
    cpu.esp -= 4;
    sub_4a4358(app, cpu);
    if (cpu.terminate) return;
    // 004a434a  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a434f  e874fdffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a4354  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4355  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a4358(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4358  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4359  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a435a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a435b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a435c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a435d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a435f  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a4361  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4363  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a4366  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a4369  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a436b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004a436d:
    // 004a436d  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a436f:
    // 004a436f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a4371  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4373  39d7                   +cmp edi, edx
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
L_0x004a4375:
    // 004a4375  7217                   -jb 0x4a438e
    if (cpu.flags.cf)
    {
        goto L_0x004a438e;
    }
    // 004a4377  39e9                   +cmp ecx, ebp
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
    // 004a4379  751b                   -jne 0x4a4396
    if (!cpu.flags.zf)
    {
        goto L_0x004a4396;
    }
L_0x004a437b:
    // 004a437b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a437d  7425                   -je 0x4a43a4
    if (cpu.flags.zf)
    {
        goto L_0x004a43a4;
    }
L_0x004a437f:
    // 004a437f  39ee                   +cmp esi, ebp
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
    // 004a4381  7421                   -je 0x4a43a4
    if (cpu.flags.zf)
    {
        goto L_0x004a43a4;
    }
    // 004a4383  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 004a4387  7523                   -jne 0x4a43ac
    if (!cpu.flags.zf)
    {
        goto L_0x004a43ac;
    }
    // 004a4389  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a438c  ebf1                   -jmp 0x4a437f
    goto L_0x004a437f;
L_0x004a438e:
    // 004a438e  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a4390  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a4392  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4394  ebe5                   -jmp 0x4a437b
    goto L_0x004a437b;
L_0x004a4396:
    // 004a4396  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a4398  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a439b  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a439e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a43a0  3b39                   +cmp edi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a43a2  ebd1                   -jmp 0x4a4375
    goto L_0x004a4375;
L_0x004a43a4:
    // 004a43a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a43a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a43ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a43ac:
    // 004a43ac  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a43ae  7415                   -je 0x4a43c5
    if (cpu.flags.zf)
    {
        goto L_0x004a43c5;
    }
    // 004a43b0  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a43b3  39d0                   +cmp eax, edx
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
    // 004a43b5  7d28                   -jge 0x4a43df
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a43df;
    }
    // 004a43b7  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a43b9  037910                 -add edi, dword ptr [ecx + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 004a43bc  39e9                   +cmp ecx, ebp
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
    // 004a43be  74e4                   -je 0x4a43a4
    if (cpu.flags.zf)
    {
        goto L_0x004a43a4;
    }
    // 004a43c0  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a43c3  ebaa                   -jmp 0x4a436f
    goto L_0x004a436f;
L_0x004a43c5:
    // 004a43c5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a43c7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a43c9  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a43cc  e8af65feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a43d1  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a43d4  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004a43d6  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a43d8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a43dd  eb90                   -jmp 0x4a436f
    goto L_0x004a436f;
L_0x004a43df:
    // 004a43df  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a43e1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a43e3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a43e5  e89665feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a43ea  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a43ed  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a43f0  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004a43f2  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004a43f5  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a43f8  894324                 -mov dword ptr [ebx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a43fb  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004a43fe  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004a4401  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a4404  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004a4407  897124                 -mov dword ptr [ecx + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004a440a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a440d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a4412  e956ffffff             -jmp 0x4a436d
    goto L_0x004a436d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a4420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4420  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4421  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a4426  e8c104feff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 004a442b  e81c000000             -call 0x4a444c
    cpu.esp -= 4;
    sub_4a444c(app, cpu);
    if (cpu.terminate) return;
    // 004a4430  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4431  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a4434(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4434  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4435  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a443a  e80d000000             -call 0x4a444c
    cpu.esp -= 4;
    sub_4a444c(app, cpu);
    if (cpu.terminate) return;
    // 004a443f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4440  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a4444(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4444  e8a304feff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 004a4449  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004a444c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a444d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a444f  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4454  e867fcffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a4459  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a445c  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a445e  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004a4460  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4462  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a4465  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a446a  e859fcffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a446f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4471  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4472  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a444c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a444c;
    // 004a4444  e8a304feff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 004a4449  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x004a444c:
    // 004a444c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a444d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a444f  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a4454  e867fcffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a4459  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a445c  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a445e  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004a4460  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4462  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a4465  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a446a  e859fcffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a446f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4471  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4472  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a4474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4474  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4475  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4476  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4477  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4478  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a447a  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004a4480  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004a4483  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a448a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a448c  bf803d5600             -mov edi, 0x563d80
    cpu.edi = 5651840 /*0x563d80*/;
    // 004a4491  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a4494  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4496  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4498  e833fcffff             -call 0x4a40d0
    cpu.esp -= 4;
    sub_4a40d0(app, cpu);
    if (cpu.terminate) return;
    // 004a449d  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a449f  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a44a2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a44a4  39d1                   +cmp ecx, edx
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
    // 004a44a6  7421                   -je 0x4a44c9
    if (cpu.flags.zf)
    {
        goto L_0x004a44c9;
    }
L_0x004a44a8:
    // 004a44a8  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004a44ad  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a44b0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a44b2  e88974feff             -call 0x48b940
    cpu.esp -= 4;
    sub_48b940(app, cpu);
    if (cpu.terminate) return;
    // 004a44b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a44b9  7506                   -jne 0x4a44c1
    if (!cpu.flags.zf)
    {
        goto L_0x004a44c1;
    }
    // 004a44bb  f6411808               +test byte ptr [ecx + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 004a44bf  750f                   -jne 0x4a44d0
    if (!cpu.flags.zf)
    {
        goto L_0x004a44d0;
    }
L_0x004a44c1:
    // 004a44c1  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a44c4  3b4f04                 +cmp ecx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a44c7  75df                   -jne 0x4a44a8
    if (!cpu.flags.zf)
    {
        goto L_0x004a44a8;
    }
L_0x004a44c9:
    // 004a44c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a44cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a44d0:
    // 004a44d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a44d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a44d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a44d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a44d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a44db  e894ffffff             -call 0x4a4474
    cpu.esp -= 4;
    sub_4a4474(app, cpu);
    if (cpu.terminate) return;
    // 004a44e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a44e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a44e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a44e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a44e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a44e7  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a44ec  e8cffbffff             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004a44f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a44f3  e810000000             -call 0x4a4508
    cpu.esp -= 4;
    sub_4a4508(app, cpu);
    if (cpu.terminate) return;
    // 004a44f8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a44fa  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004a44ff  e8c4fbffff             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004a4504  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4506  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4507  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4508(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4508  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4509  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a450a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a450b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a450c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a450d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a450e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4511  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4513  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a4515  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004a451b  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004a451e  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a4525  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4527  bb803d5600             -mov ebx, 0x563d80
    cpu.ebx = 5651840 /*0x563d80*/;
    // 004a452c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a452f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4531  837b1000               +cmp dword ptr [ebx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4535  0f8484000000           -je 0x4a45bf
    if (cpu.flags.zf)
    {
        goto L_0x004a45bf;
    }
    // 004a453b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a453d  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a453f  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a4541  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a4544  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a4547  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a4549:
    // 004a4549  f6461808               +test byte ptr [esi + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 004a454d  7422                   -je 0x4a4571
    if (cpu.flags.zf)
    {
        goto L_0x004a4571;
    }
    // 004a454f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a4552  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a4555  39f8                   +cmp eax, edi
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
    // 004a4557  0f866b000000           -jbe 0x4a45c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a45c8;
    }
L_0x004a455d:
    // 004a455d  a100b24d00             -mov eax, dword ptr [0x4db200]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 004a4562  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004a4564  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a4567  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a456a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a456c  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a456f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a4571:
    // 004a4571  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a4574  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a4577  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4579  75ce                   -jne 0x4a4549
    if (!cpu.flags.zf)
    {
        goto L_0x004a4549;
    }
    // 004a457b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a457d  7434                   -je 0x4a45b3
    if (cpu.flags.zf)
    {
        goto L_0x004a45b3;
    }
    // 004a457f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4581  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a4583:
    // 004a4583  40                     -inc eax
    (cpu.eax)++;
    // 004a4584  8a5a04                 -mov bl, byte ptr [edx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a4587  42                     -inc edx
    (cpu.edx)++;
    // 004a4588  885c04ff               -mov byte ptr [esp + eax - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = cpu.bl;
    // 004a458c  83f80c                 +cmp eax, 0xc
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
    // 004a458f  7cf2                   -jl 0x4a4583
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4583;
    }
    // 004a4591  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004a4593  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
L_0x004a4597:
    // 004a4597  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a4599  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a459c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a459f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a45a1  80cb08                 -or bl, 8
    cpu.bl |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004a45a4  e867fffdff             -call 0x484510
    cpu.esp -= 4;
    sub_484510(app, cpu);
    if (cpu.terminate) return;
    // 004a45a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a45ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a45ad  7429                   -je 0x4a45d8
    if (cpu.flags.zf)
    {
        goto L_0x004a45d8;
    }
    // 004a45af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a45b1  7540                   -jne 0x4a45f3
    if (!cpu.flags.zf)
    {
        goto L_0x004a45f3;
    }
L_0x004a45b3:
    // 004a45b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a45b5:
    // 004a45b5  83c410                 +add esp, 0x10
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
    // 004a45b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a45bf:
    // 004a45bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a45c1  e83a04feff             -call 0x484a00
    cpu.esp -= 4;
    sub_484a00(app, cpu);
    if (cpu.terminate) return;
    // 004a45c6  ebed                   -jmp 0x4a45b5
    goto L_0x004a45b5;
L_0x004a45c8:
    // 004a45c8  75a7                   -jne 0x4a4571
    if (!cpu.flags.zf)
    {
        goto L_0x004a4571;
    }
    // 004a45ca  a100b24d00             -mov eax, dword ptr [0x4db200]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 004a45cf  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 004a45d2  39d0                   +cmp eax, edx
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
    // 004a45d4  7387                   -jae 0x4a455d
    if (!cpu.flags.cf)
    {
        goto L_0x004a455d;
    }
    // 004a45d6  eb99                   -jmp 0x4a4571
    goto L_0x004a4571;
L_0x004a45d8:
    // 004a45d8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a45da  e829ffffff             -call 0x4a4508
    cpu.esp -= 4;
    sub_4a4508(app, cpu);
    if (cpu.terminate) return;
    // 004a45df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a45e1  75b4                   -jne 0x4a4597
    if (!cpu.flags.zf)
    {
        goto L_0x004a4597;
    }
    // 004a45e3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a45e5  750c                   -jne 0x4a45f3
    if (!cpu.flags.zf)
    {
        goto L_0x004a45f3;
    }
    // 004a45e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a45e9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a45ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a45f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a45f3:
    // 004a45f3  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a45f6  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a45f8  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a45fb  e88063feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a4600  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a4602  e84103feff             -call 0x484948
    cpu.esp -= 4;
    sub_484948(app, cpu);
    if (cpu.terminate) return;
    // 004a4607  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a460c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a460f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4610  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4611  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4612  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4613  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4614  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4615  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a4618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4618  e807000000             -call 0x4a4624
    cpu.esp -= 4;
    sub_4a4624(app, cpu);
    if (cpu.terminate) return;
    // 004a461d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a461f  7402                   -je 0x4a4623
    if (cpu.flags.zf)
    {
        goto L_0x004a4623;
    }
    // 004a4621  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004a4623:
    // 004a4623  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4624(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4624  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4625  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4626  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4627  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4628  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4629  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a462b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a462d  e842feffff             -call 0x4a4474
    cpu.esp -= 4;
    sub_4a4474(app, cpu);
    if (cpu.terminate) return;
    // 004a4632  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4634  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4636  7537                   -jne 0x4a466f
    if (!cpu.flags.zf)
    {
        goto L_0x004a466f;
    }
    // 004a4638  8b1decb14d00           -mov ebx, dword ptr [0x4db1ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 004a463e  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
L_0x004a4641:
    // 004a4641  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a4643  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4645  e82afeffff             -call 0x4a4474
    cpu.esp -= 4;
    sub_4a4474(app, cpu);
    if (cpu.terminate) return;
    // 004a464a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a464c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a464e  7561                   -jne 0x4a46b1
    if (!cpu.flags.zf)
    {
        goto L_0x004a46b1;
    }
    // 004a4650  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004a4656  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004a4659  6bdb18                 -imul ebx, ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(24 /*0x18*/)));
    // 004a465c  81c3803d5600           -add ebx, 0x563d80
    (cpu.ebx) += x86::reg32(x86::sreg32(5651840 /*0x563d80*/));
    // 004a4662  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a4665  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4667  75d8                   -jne 0x4a4641
    if (!cpu.flags.zf)
    {
        goto L_0x004a4641;
    }
L_0x004a4669:
    // 004a4669  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a466a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a466b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a466c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a466d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a466e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a466f:
    // 004a466f  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a4672  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a4675  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 004a4678  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004a467b  7404                   -je 0x4a4681
    if (cpu.flags.zf)
    {
        goto L_0x004a4681;
    }
    // 004a467d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a467f  ebe8                   -jmp 0x4a4669
    goto L_0x004a4669;
L_0x004a4681:
    // 004a4681  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4683  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a4686  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a4689  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a468b  e880fefdff             -call 0x484510
    cpu.esp -= 4;
    sub_484510(app, cpu);
    if (cpu.terminate) return;
    // 004a4690  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a4692  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4694  7504                   -jne 0x4a469a
    if (!cpu.flags.zf)
    {
        goto L_0x004a469a;
    }
    // 004a4696  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4698  ebcf                   -jmp 0x4a4669
    goto L_0x004a4669;
L_0x004a469a:
    // 004a469a  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a469d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a469f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a46a1  e8da62feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a46a6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a46a8  e87b02feff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
    // 004a46ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a46af  ebb8                   -jmp 0x4a4669
    goto L_0x004a4669;
L_0x004a46b1:
    // 004a46b1  806018f7               -and byte ptr [eax + 0x18], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a46b5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a46b7  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a46ba  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a46bd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a46bf  e84cfefdff             -call 0x484510
    cpu.esp -= 4;
    sub_484510(app, cpu);
    if (cpu.terminate) return;
    // 004a46c4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a46c6  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a46c9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a46cb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a46cd  e8ae62feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a46d2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a46d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a46d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a46dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a46dc  e807000000             -call 0x4a46e8
    cpu.esp -= 4;
    sub_4a46e8(app, cpu);
    if (cpu.terminate) return;
    // 004a46e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a46e3  7402                   -je 0x4a46e7
    if (cpu.flags.zf)
    {
        goto L_0x004a46e7;
    }
    // 004a46e5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004a46e7:
    // 004a46e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a46e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a46e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a46e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a46ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a46eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a46ec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a46ee  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a46f0  e87ffdffff             -call 0x4a4474
    cpu.esp -= 4;
    sub_4a4474(app, cpu);
    if (cpu.terminate) return;
    // 004a46f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a46f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a46f9  7528                   -jne 0x4a4723
    if (!cpu.flags.zf)
    {
        goto L_0x004a4723;
    }
    // 004a46fb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a46fd  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004a4703  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004a4706  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a470d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a470f  ba803d5600             -mov edx, 0x563d80
    cpu.edx = 5651840 /*0x563d80*/;
    // 004a4714  8b54c210               -mov edx, dword ptr [edx + eax*8 + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */ + cpu.eax * 8);
    // 004a4718  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a471a  754b                   -jne 0x4a4767
    if (!cpu.flags.zf)
    {
        goto L_0x004a4767;
    }
    // 004a471c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a471e:
    // 004a471e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a471f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4720  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4721  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4722  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4723:
    // 004a4723  8a5018                 -mov dl, byte ptr [eax + 0x18]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a4726  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a4729  885018                 -mov byte ptr [eax + 0x18], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.dl;
    // 004a472c  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004a472f  75ed                   -jne 0x4a471e
    if (!cpu.flags.zf)
    {
        goto L_0x004a471e;
    }
    // 004a4731  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a4734  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a4737  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4739  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a473b  e8d0fdfdff             -call 0x484510
    cpu.esp -= 4;
    sub_484510(app, cpu);
    if (cpu.terminate) return;
    // 004a4740  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a4742  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4744  7507                   -jne 0x4a474d
    if (!cpu.flags.zf)
    {
        goto L_0x004a474d;
    }
    // 004a4746  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4748  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4749  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a474a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a474b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a474c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a474d:
    // 004a474d  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a4750  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4752  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4754  e82762feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a4759  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a475b  e8c801feff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
    // 004a4760  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a4762  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4763  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4764  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4765  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4766  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4767:
    // 004a4767  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4769  e806fdffff             -call 0x4a4474
    cpu.esp -= 4;
    sub_4a4474(app, cpu);
    if (cpu.terminate) return;
    // 004a476e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4770  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4772  74aa                   -je 0x4a471e
    if (cpu.flags.zf)
    {
        goto L_0x004a471e;
    }
    // 004a4774  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a4777  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a477a  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a477d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a477f  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 004a4782  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a4784  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a4787  e884fdfdff             -call 0x484510
    cpu.esp -= 4;
    sub_484510(app, cpu);
    if (cpu.terminate) return;
    // 004a478c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a478e  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a4791  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4793  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a4795  e8e661feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a479a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a479c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a479d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a479e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a479f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a47a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a47b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a47b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a47b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a47b2  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a47b5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a47b7  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a47bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a47bd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a47c1  2eff1538654c00         -call dword ptr cs:[0x4c6538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006648) /* 0x4c6538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a47c8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a47cc  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a47cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a47d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a47d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a47d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a47d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a47d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a47d6  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a47d9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a47db  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a47e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a47e1  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a47e5  2eff1538654c00         -call dword ptr cs:[0x4c6538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006648) /* 0x4c6538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a47ec  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a47f0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a47f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a47f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a47f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a47f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a47f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a47f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a47fa  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a47fd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a47ff  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004a4804  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4805  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a4809  2eff1538654c00         -call dword ptr cs:[0x4c6538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006648) /* 0x4c6538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4810  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4814  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a4817  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4818  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4819  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a481c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a481c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a481d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a481e  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a4821  ba00006000             -mov edx, 0x600000
    cpu.edx = 6291456 /*0x600000*/;
    // 004a4826  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a4828  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a482d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a482e  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a4832  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a4836  2eff1538654c00         -call dword ptr cs:[0x4c6538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006648) /* 0x4c6538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a483d  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a4841  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4842  683f000f00             -push 0xf003f
    app->getMemory<x86::reg32>(cpu.esp-4) = 983103 /*0xf003f*/;
    cpu.esp -= 4;
    // 004a4847  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a4849  6834144d00             -push 0x4d1434
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051444 /*0x4d1434*/;
    cpu.esp -= 4;
    // 004a484e  6806000080             -push 0x80000006
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483654 /*0x80000006*/;
    cpu.esp -= 4;
    // 004a4853  2eff15a0634c00         -call dword ptr cs:[0x4c63a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006240) /* 0x4c63a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a485a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a485c  740e                   -je 0x4a486c
    if (cpu.flags.zf)
    {
        goto L_0x004a486c;
    }
    // 004a485e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4862  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a4866  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a4869  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a486a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a486b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a486c:
    // 004a486c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a486d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a486e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a486f  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a4873  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4874  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a4878  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4879  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a487b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a487d  6848144d00             -push 0x4d1448
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051464 /*0x4d1448*/;
    cpu.esp -= 4;
    // 004a4882  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a4886  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004a488b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a488c  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004a4890  2eff15a4634c00         -call dword ptr cs:[0x4c63a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006244) /* 0x4c63a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a4897  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a489b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a489c  2eff1598634c00         -call dword ptr cs:[0x4c6398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006232) /* 0x4c6398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a48a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48a6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a48aa  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a48ae  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a48b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a48b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a48c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a48c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a48c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a48c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a48c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a48c4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a48c6  8b0cc5b0c55900         -mov ecx, dword ptr [eax*8 + 0x59c5b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.eax * 8);
    // 004a48cd  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a48d2  bf80000000             -mov edi, 0x80
    cpu.edi = 128 /*0x80*/;
    // 004a48d7  80790401               +cmp byte ptr [ecx + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a48db  7206                   -jb 0x4a48e3
    if (cpu.flags.cf)
    {
        goto L_0x004a48e3;
    }
    // 004a48dd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a48df  668b7906               -mov di, word ptr [ecx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
L_0x004a48e3:
    // 004a48e3  e82c1afeff             -call 0x486314
    cpu.esp -= 4;
    sub_486314(app, cpu);
    if (cpu.terminate) return;
    // 004a48e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a48ea  754d                   -jne 0x4a4939
    if (!cpu.flags.zf)
    {
        goto L_0x004a4939;
    }
    // 004a48ec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a48ee  7c49                   -jl 0x4a4939
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4939;
    }
    // 004a48f0  39fe                   +cmp esi, edi
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
    // 004a48f2  7d45                   -jge 0x4a4939
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4939;
    }
    // 004a48f4  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004a48fb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a48fd  80790402               +cmp byte ptr [ecx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4901  7240                   -jb 0x4a4943
    if (cpu.flags.cf)
    {
        goto L_0x004a4943;
    }
    // 004a4903  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a4905  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x004a4908:
    // 004a4908  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a490a  742d                   -je 0x4a4939
    if (cpu.flags.zf)
    {
        goto L_0x004a4939;
    }
    // 004a490c  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 004a4912  7534                   -jne 0x4a4948
    if (!cpu.flags.zf)
    {
        goto L_0x004a4948;
    }
    // 004a4914  e84f000000             -call 0x4a4968
    cpu.esp -= 4;
    sub_4a4968(app, cpu);
    if (cpu.terminate) return;
L_0x004a4919:
    // 004a4919  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a491b:
    // 004a491b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a491d  7c13                   -jl 0x4a4932
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4932;
    }
    // 004a491f  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a4922  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004a4925  80fc02                 +cmp ah, 2
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4928  722e                   -jb 0x4a4958
    if (cpu.flags.cf)
    {
        goto L_0x004a4958;
    }
    // 004a492a  c7442e0c00000000       -mov dword ptr [esi + ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 1) = 0 /*0x0*/;
L_0x004a4932:
    // 004a4932  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a4934  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4935  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4936  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4937  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4938  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4939:
    // 004a4939  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a493e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a493f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4940  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4941  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4942  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4943:
    // 004a4943  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a4946  ebc0                   -jmp 0x4a4908
    goto L_0x004a4908;
L_0x004a4948:
    // 004a4948  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a494d  75cc                   -jne 0x4a491b
    if (!cpu.flags.zf)
    {
        goto L_0x004a491b;
    }
    // 004a494f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a4951  e85a400000             -call 0x4a89b0
    cpu.esp -= 4;
    sub_4a89b0(app, cpu);
    if (cpu.terminate) return;
    // 004a4956  ebc1                   -jmp 0x4a4919
    goto L_0x004a4919;
L_0x004a4958:
    // 004a4958  c744310800000000       -mov dword ptr [ecx + esi + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.esi * 1) = 0 /*0x0*/;
    // 004a4960  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4962  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4963  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4964  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4965  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a4968(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4968  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4969  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a496a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a496b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a496d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a496f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4971  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4973  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004a4976  39c2                   +cmp edx, eax
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
    // 004a4978  7c06                   -jl 0x4a4980
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4980;
    }
    // 004a497a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a497c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a497d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a497e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a497f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4980:
    // 004a4980  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a4983  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4985  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a4988  42                     -inc edx
    (cpu.edx)++;
    // 004a4989  e8a241feff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 004a498e  83c144                 -add ecx, 0x44
    (cpu.ecx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004a4991  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4993  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 004a4996  39c2                   +cmp edx, eax
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
    // 004a4998  7ce6                   -jl 0x4a4980
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4980;
    }
    // 004a499a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a499c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a499d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a499e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a499f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a49a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a49a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a49a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a49a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a49a3  81ec080c0000           -sub esp, 0xc08
    (cpu.esp) -= x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a49a9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a49ab  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a49ad  899c24000c0000         -mov dword ptr [esp + 0xc00], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.ebx;
    // 004a49b4  898c24040c0000         -mov dword ptr [esp + 0xc04], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.ecx;
    // 004a49bb  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 004a49c1  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004a49c6  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a49c8  750f                   -jne 0x4a49d9
    if (!cpu.flags.zf)
    {
        goto L_0x004a49d9;
    }
    // 004a49ca  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004a49cf  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a49d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a49d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a49d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a49d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a49d9:
    // 004a49d9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a49db  e83419feff             -call 0x486314
    cpu.esp -= 4;
    sub_486314(app, cpu);
    if (cpu.terminate) return;
    // 004a49e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a49e2  0f8562000000           -jne 0x4a4a4a
    if (!cpu.flags.zf)
    {
        goto L_0x004a4a4a;
    }
    // 004a49e8  83bc24000c000000       +cmp dword ptr [esp + 0xc00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a49f0  7458                   -je 0x4a4a4a
    if (cpu.flags.zf)
    {
        goto L_0x004a4a4a;
    }
    // 004a49f2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a49f4  7454                   -je 0x4a4a4a
    if (cpu.flags.zf)
    {
        goto L_0x004a4a4a;
    }
    // 004a49f6  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004a49fb:
    // 004a49fb  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a49fe  895404f4               -mov dword ptr [esp + eax - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.eax * 1) = cpu.edx;
    // 004a4a02  3d000c0000             +cmp eax, 0xc00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4a07  75f2                   -jne 0x4a49fb
    if (!cpu.flags.zf)
    {
        goto L_0x004a49fb;
    }
    // 004a4a09  8b34f5b0c55900         -mov esi, dword ptr [esi*8 + 0x59c5b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.esi * 8);
    // 004a4a10  807e0401               +cmp byte ptr [esi + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4a14  7206                   -jb 0x4a4a1c
    if (cpu.flags.cf)
    {
        goto L_0x004a4a1c;
    }
    // 004a4a16  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4a18  668b5e06               -mov bx, word ptr [esi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x004a4a1c:
    // 004a4a1c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4a1e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4a20  7e19                   -jle 0x4a4a3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4a3b;
    }
    // 004a4a22  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a4a24:
    // 004a4a24  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4a28  722f                   -jb 0x4a4a59
    if (cpu.flags.cf)
    {
        goto L_0x004a4a59;
    }
    // 004a4a2a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a4a2c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x004a4a2f:
    // 004a4a2f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a4a31  742b                   -je 0x4a4a5e
    if (cpu.flags.zf)
    {
        goto L_0x004a4a5e;
    }
    // 004a4a33  41                     -inc ecx
    (cpu.ecx)++;
    // 004a4a34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a4a37  39d9                   +cmp ecx, ebx
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
    // 004a4a39  7ce9                   -jl 0x4a4a24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4a24;
    }
L_0x004a4a3b:
    // 004a4a3b  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 004a4a40  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a4a46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4a4a:
    // 004a4a4a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a4a4f  81c4080c0000           +add esp, 0xc08
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3080 /*0xc08*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4a55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4a59:
    // 004a4a59  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a4a5c  ebd1                   -jmp 0x4a4a2f
    goto L_0x004a4a2f;
L_0x004a4a5e:
    // 004a4a5e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a4a60  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 004a4a67  8b8424000c0000         -mov eax, dword ptr [esp + 0xc00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004a4a6e  e8ad010000             -call 0x4a4c20
    cpu.esp -= 4;
    sub_4a4c20(app, cpu);
    if (cpu.terminate) return;
    // 004a4a73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4a75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4a77  7c29                   -jl 0x4a4aa2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4aa2;
    }
    // 004a4a79  8a5e04                 -mov bl, byte ptr [esi + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a4a7c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004a4a83  80fb02                 +cmp bl, 2
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4a86  722b                   -jb 0x4a4ab3
    if (cpu.flags.cf)
    {
        goto L_0x004a4ab3;
    }
    // 004a4a88  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004a4a8f  895c070c               -mov dword ptr [edi + eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ebx;
    // 004a4a93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4a95  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004a4a98  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a4a9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4a9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4aa0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4aa1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4aa2:
    // 004a4aa2  c74500ffffffff         -mov dword ptr [ebp], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp) = 4294967295 /*0xffffffff*/;
    // 004a4aa9  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a4aaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ab0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ab1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ab2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4ab3:
    // 004a4ab3  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004a4aba  895c0608               -mov dword ptr [esi + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 004a4abe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4ac0  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 004a4ac3  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 004a4ac9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4aca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4acb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4acc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a4ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4ad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4ad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4ad2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4ad3  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004a4ad9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4adb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a4add  bab0bf5900             -mov edx, 0x59bfb0
    cpu.edx = 5881776 /*0x59bfb0*/;
    // 004a4ae2  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x004a4ae8:
    // 004a4ae8  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 004a4aeb  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a4aee  39f0                   +cmp eax, esi
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
    // 004a4af0  7511                   -jne 0x4a4b03
    if (!cpu.flags.zf)
    {
        goto L_0x004a4b03;
    }
    // 004a4af2  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a4af4  668b4208               -mov ax, word ptr [edx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a4af8  39c8                   +cmp eax, ecx
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
    // 004a4afa  7507                   -jne 0x4a4b03
    if (!cpu.flags.zf)
    {
        goto L_0x004a4b03;
    }
    // 004a4afc  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004a4afe  e83d4dfeff             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
L_0x004a4b03:
    // 004a4b03  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a4b06  39da                   +cmp edx, ebx
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
    // 004a4b08  75de                   -jne 0x4a4ae8
    if (!cpu.flags.zf)
    {
        goto L_0x004a4ae8;
    }
    // 004a4b0a  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4b0c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x004a4b11:
    // 004a4b11  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a4b14  895c14f4               -mov dword ptr [esp + edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.edx * 1) = cpu.ebx;
    // 004a4b18  81fa000c0000           +cmp edx, 0xc00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4b1e  75f1                   -jne 0x4a4b11
    if (!cpu.flags.zf)
    {
        goto L_0x004a4b11;
    }
    // 004a4b20  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a4b22  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a4b24  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4b26  e895fdffff             -call 0x4a48c0
    cpu.esp -= 4;
    sub_4a48c0(app, cpu);
    if (cpu.terminate) return;
    // 004a4b2b  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004a4b31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4b32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4b33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4b34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a4b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4b40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4b41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4b42  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a4b45  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a4b47  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a4b49  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a4b4d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a4b52  8a6005                 -mov ah, byte ptr [eax + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004a4b55  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a4b58  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a4b5a  0f856a000000           -jne 0x4a4bca
    if (!cpu.flags.zf)
    {
        goto L_0x004a4bca;
    }
    // 004a4b60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4b61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4b62  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a4b65  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a4b68  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a4b6a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4b6c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a4b6e  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004a4b71:
    // 004a4b71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4b73  8a4107                 -mov al, byte ptr [ecx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004a4b76  39c6                   +cmp esi, eax
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
    // 004a4b78  7d5d                   -jge 0x4a4bd7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4bd7;
    }
    // 004a4b7a  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a4b7d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a4b7f  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4b83  7406                   -je 0x4a4b8b
    if (cpu.flags.zf)
    {
        goto L_0x004a4b8b;
    }
    // 004a4b85  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a4b88  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a4b8b:
    // 004a4b8b  83781c00               +cmp dword ptr [eax + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4b8f  7406                   -je 0x4a4b97
    if (cpu.flags.zf)
    {
        goto L_0x004a4b97;
    }
    // 004a4b91  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a4b94  01501c                 -add dword ptr [eax + 0x1c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a4b97:
    // 004a4b97  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 004a4b9b  7406                   -je 0x4a4ba3
    if (cpu.flags.zf)
    {
        goto L_0x004a4ba3;
    }
    // 004a4b9d  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a4ba0  015020                 -add dword ptr [eax + 0x20], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a4ba3:
    // 004a4ba3  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a4ba6  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a4ba9  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a4bac  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4bae  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a4bb0  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004a4bb3  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4bb7  e82441feff             -call 0x488ce0
    cpu.esp -= 4;
    sub_488ce0(app, cpu);
    if (cpu.terminate) return;
    // 004a4bbc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a4bc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4bc2  7c0e                   -jl 0x4a4bd2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4bd2;
    }
    // 004a4bc4  83c744                 +add edi, 0x44
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4bc7  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4bc8  eba7                   -jmp 0x4a4b71
    goto L_0x004a4b71;
L_0x004a4bca:
    // 004a4bca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4bcc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a4bcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4bd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4bd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4bd2:
    // 004a4bd2  4e                     -dec esi
    (cpu.esi)--;
    // 004a4bd3  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004a4bd7:
    // 004a4bd7  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4bdb  83feff                 +cmp esi, -1
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
    // 004a4bde  7e30                   -jle 0x4a4c10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4c10;
    }
    // 004a4be0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a4be2  7c20                   -jl 0x4a4c04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c04;
    }
    // 004a4be4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a4be6  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004a4be9  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4beb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4bed  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
L_0x004a4bf0:
    // 004a4bf0  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a4bf3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4bf5  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a4bf8  83c244                 -add edx, 0x44
    (cpu.edx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004a4bfb  e8303ffeff             -call 0x488b30
    cpu.esp -= 4;
    sub_488b30(app, cpu);
    if (cpu.terminate) return;
    // 004a4c00  39f2                   +cmp edx, esi
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
    // 004a4c02  7eec                   -jle 0x4a4bf0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4bf0;
    }
L_0x004a4c04:
    // 004a4c04  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4c08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c0a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a4c0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a4c10:
    // 004a4c10  c6410501               -mov byte ptr [ecx + 5], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 1 /*0x1*/;
    // 004a4c14  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4c18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c1a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a4c1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4c1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4c20  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 004a4c26  0f8414ffffff           -je 0x4a4b40
    if (cpu.flags.zf)
    {
        return sub_4a4b40(app, cpu);
    }
    // 004a4c2c  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a4c31  0f84cd3c0000           -je 0x4a8904
    if (cpu.flags.zf)
    {
        return sub_4a8904(app, cpu);
    }
    // 004a4c37  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a4c3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a4c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4c40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4c41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4c42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a4c43  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4c46  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a4c48  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a4c4b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a4c4d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a4c4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4c51  7446                   -je 0x4a4c99
    if (cpu.flags.zf)
    {
        goto L_0x004a4c99;
    }
    // 004a4c53  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 004a4c59  754c                   -jne 0x4a4ca7
    if (!cpu.flags.zf)
    {
        goto L_0x004a4ca7;
    }
    // 004a4c5b  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a4c5f  754d                   -jne 0x4a4cae
    if (!cpu.flags.zf)
    {
        goto L_0x004a4cae;
    }
    // 004a4c61  83f9ff                 +cmp ecx, -1
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
    // 004a4c64  754f                   -jne 0x4a4cb5
    if (!cpu.flags.zf)
    {
        goto L_0x004a4cb5;
    }
    // 004a4c66  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x004a4c6b:
    // 004a4c6b  83fbff                 +cmp ebx, -1
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
    // 004a4c6e  7550                   -jne 0x4a4cc0
    if (!cpu.flags.zf)
    {
        goto L_0x004a4cc0;
    }
    // 004a4c70  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
L_0x004a4c75:
    // 004a4c75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4c77  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a4c79:
    // 004a4c79  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4c7b  8a4f07                 -mov cl, byte ptr [edi + 7]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 004a4c7e  39c8                   +cmp eax, ecx
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
    // 004a4c80  0f8d60000000           -jge 0x4a4ce6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4ce6;
    }
    // 004a4c86  8b770c                 -mov esi, dword ptr [edi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a4c89  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4c8b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4c8d  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a4c8f  39cd                   +cmp ebp, ecx
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
    // 004a4c91  7d38                   -jge 0x4a4ccb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4ccb;
    }
L_0x004a4c93:
    // 004a4c93  83c244                 +add edx, 0x44
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a4c96  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a4c97  ebe0                   -jmp 0x4a4c79
    goto L_0x004a4c79;
L_0x004a4c99:
    // 004a4c99  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004a4c9e:
    // 004a4c9e  83c410                 +add esp, 0x10
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
    // 004a4ca1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ca2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ca3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4ca4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a4ca7:
    // 004a4ca7  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a4cac  ebf0                   -jmp 0x4a4c9e
    goto L_0x004a4c9e;
L_0x004a4cae:
    // 004a4cae  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 004a4cb3  ebe9                   -jmp 0x4a4c9e
    goto L_0x004a4c9e;
L_0x004a4cb5:
    // 004a4cb5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a4cb7  7ce0                   -jl 0x4a4c99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c99;
    }
    // 004a4cb9  83f97f                 +cmp ecx, 0x7f
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
    // 004a4cbc  7ead                   -jle 0x4a4c6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4c6b;
    }
    // 004a4cbe  ebd9                   -jmp 0x4a4c99
    goto L_0x004a4c99;
L_0x004a4cc0:
    // 004a4cc0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a4cc2  7cd5                   -jl 0x4a4c99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c99;
    }
    // 004a4cc4  83fb7f                 +cmp ebx, 0x7f
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
    // 004a4cc7  7eac                   -jle 0x4a4c75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4c75;
    }
    // 004a4cc9  ebce                   -jmp 0x4a4c99
    goto L_0x004a4c99;
L_0x004a4ccb:
    // 004a4ccb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4ccd  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a4cd0  39cd                   +cmp ebp, ecx
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
    // 004a4cd2  7fbf                   -jg 0x4a4c93
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4c93;
    }
    // 004a4cd4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4cd6  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a4cd9  39cb                   +cmp ebx, ecx
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
    // 004a4cdb  7cb6                   -jl 0x4a4c93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c93;
    }
    // 004a4cdd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a4cdf  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a4ce2  39cb                   +cmp ebx, ecx
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
    // 004a4ce4  7fad                   -jg 0x4a4c93
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a4c93;
    }
L_0x004a4ce6:
    // 004a4ce6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4ce8  8a5707                 -mov dl, byte ptr [edi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 004a4ceb  39d0                   +cmp eax, edx
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
    // 004a4ced  0f8482020000           -je 0x4a4f75
    if (cpu.flags.zf)
    {
        goto L_0x004a4f75;
    }
    // 004a4cf3  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a4cf7  83f8ff                 +cmp eax, -1
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
    // 004a4cfa  0f8583020000           -jne 0x4a4f83
    if (!cpu.flags.zf)
    {
        goto L_0x004a4f83;
    }
    // 004a4d00  c74424247f000000       -mov dword ptr [esp + 0x24], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 127 /*0x7f*/;
L_0x004a4d08:
    // 004a4d08  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a4d0c  83faff                 +cmp edx, -1
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
    // 004a4d0f  0f858d020000           -jne 0x4a4fa2
    if (!cpu.flags.zf)
    {
        goto L_0x004a4fa2;
    }
    // 004a4d15  c744242040000000       -mov dword ptr [esp + 0x20], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 64 /*0x40*/;
L_0x004a4d1d:
    // 004a4d1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4d1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4d21  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004a4d24  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a4d27  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4d29  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a4d2c  8a5611                 -mov dl, byte ptr [esi + 0x11]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 004a4d2f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a4d33  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a4d35  7415                   -je 0x4a4d4c
    if (cpu.flags.zf)
    {
        goto L_0x004a4d4c;
    }
    // 004a4d37  8b460e                 -mov eax, dword ptr [esi + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a4d3a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a4d3d  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4d41  e83af10000             -call 0x4b3e80
    cpu.esp -= 4;
    sub_4b3e80(app, cpu);
    if (cpu.terminate) return;
    // 004a4d46  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4d48  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004a4d4c:
    // 004a4d4c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4d50  83f87f                 +cmp eax, 0x7f
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
    // 004a4d53  0f8e68020000           -jle 0x4a4fc1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4fc1;
    }
    // 004a4d59  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
L_0x004a4d61:
    // 004a4d61  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4d65  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a4d69  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a4d6c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a4d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4d72  0f8c5c020000           -jl 0x4a4fd4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4fd4;
    }
    // 004a4d78  83f87f                 +cmp eax, 0x7f
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
    // 004a4d7b  7e08                   -jle 0x4a4d85
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4d85;
    }
    // 004a4d7d  c74424207f000000       -mov dword ptr [esp + 0x20], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 127 /*0x7f*/;
L_0x004a4d85:
    // 004a4d85  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a4d88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4d8a  740b                   -je 0x4a4d97
    if (cpu.flags.zf)
    {
        goto L_0x004a4d97;
    }
    // 004a4d8c  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a4d90  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a4d93  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004a4d97:
    // 004a4d97  837c2428ff             +cmp dword ptr [esp + 0x28], -1
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
    // 004a4d9c  7509                   -jne 0x4a4da7
    if (!cpu.flags.zf)
    {
        goto L_0x004a4da7;
    }
    // 004a4d9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4da0  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a4da3  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004a4da7:
    // 004a4da7  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a4daa  8b5612                 -mov edx, dword ptr [esi + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004a4dad  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a4db0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a4db3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4db5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4db7  8a5609                 -mov dl, byte ptr [esi + 9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 004a4dba  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4dbc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a4dc0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a4dc7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4dc9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a4dcc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a4dce  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4dd2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a4dd5  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4dd7  668b5616               -mov dx, word ptr [esi + 0x16]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 004a4ddb  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a4ddf  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004a4de2  7412                   -je 0x4a4df6
    if (cpu.flags.zf)
    {
        goto L_0x004a4df6;
    }
    // 004a4de4  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a4de7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a4dea  e891f00000             -call 0x4b3e80
    cpu.esp -= 4;
    sub_4b3e80(app, cpu);
    if (cpu.terminate) return;
    // 004a4def  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a4df2  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x004a4df6:
    // 004a4df6  e865050000             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 004a4dfb  b910c65900             -mov ecx, 0x59c610
    cpu.ecx = 5883408 /*0x59c610*/;
    // 004a4e00  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a4e03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a4e05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4e07  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a4e0a  8a560f                 -mov dl, byte ptr [esi + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 004a4e0d  e8aa050000             -call 0x4a53bc
    cpu.esp -= 4;
    sub_4a53bc(app, cpu);
    if (cpu.terminate) return;
    // 004a4e12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4e14  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a4e18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4e1a  0f8cbf010000           -jl 0x4a4fdf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4fdf;
    }
    // 004a4e20  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a4e23  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4e25  bbb0bf5900             -mov ebx, 0x59bfb0
    cpu.ebx = 5881776 /*0x59bfb0*/;
    // 004a4e2a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a4e2d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4e2f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a4e32  89434c                 -mov dword ptr [ebx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004a4e35  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a4e38  894350                 -mov dword ptr [ebx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004a4e3b  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004a4e3e  894354                 -mov dword ptr [ebx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 004a4e41  8a4706                 -mov al, byte ptr [edi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a4e44  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a4e47  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a4e4b  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a4e52  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4e55  894320                 -mov dword ptr [ebx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a4e58  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a4e5b  8b560f                 -mov edx, dword ptr [esi + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 004a4e5e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a4e61  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a4e64  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a4e67  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004a4e6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4e6e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a4e71  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a4e73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4e75  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a4e78  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a4e7b  e800f00000             -call 0x4b3e80
    cpu.esp -= 4;
    sub_4b3e80(app, cpu);
    if (cpu.terminate) return;
    // 004a4e80  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a4e82  39ca                   +cmp edx, ecx
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
    // 004a4e84  0f8e65010000           -jle 0x4a4fef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4fef;
    }
    // 004a4e8a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004a4e8c:
    // 004a4e8c  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a4e8f  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
    // 004a4e94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4e96  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a4e99  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a4e9b  884330                 -mov byte ptr [ebx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 004a4e9e  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a4ea2  884332                 -mov byte ptr [ebx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 004a4ea5  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a4ea9  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a4eac  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a4eb0  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004a4eb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a4eb6  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004a4eb9  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004a4ebc  66894342               -mov word ptr [ebx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 004a4ec0  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a4ec4  884333                 -mov byte ptr [ebx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 004a4ec7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a4ecb  e860be0000             -call 0x4b0d30
    cpu.esp -= 4;
    sub_4b0d30(app, cpu);
    if (cpu.terminate) return;
    // 004a4ed0  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004a4ed3  894348                 -mov dword ptr [ebx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004a4ed6  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004a4ed9  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004a4ee0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4ee2  89432c                 -mov dword ptr [ebx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a4ee5  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004a4ee8  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a4eeb  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a4eee  c6433500               -mov byte ptr [ebx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 004a4ef2  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a4ef5  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004a4ef8  884334                 -mov byte ptr [ebx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 004a4efb  8a460b                 -mov al, byte ptr [esi + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */);
    // 004a4efe  884336                 -mov byte ptr [ebx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 004a4f01  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004a4f04  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4f06  88430a                 -mov byte ptr [ebx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 004a4f09  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a4f0d  c6430b0f               -mov byte ptr [ebx + 0xb], 0xf
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = 15 /*0xf*/;
    // 004a4f11  e8da3c0000             -call 0x4a8bf0
    cpu.esp -= 4;
    sub_4a8bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a4f16  8b0da4bf5900           -mov ecx, dword ptr [0x59bfa4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5881764) /* 0x59bfa4 */);
    // 004a4f1c  8a560e                 -mov dl, byte ptr [esi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a4f1f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a4f22  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4f24  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a4f27  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a4f29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4f2a  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a4f2d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a4f30  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a4f34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4f35  8b432e                 -mov eax, dword ptr [ebx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 004a4f38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a4f3a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a4f3d  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a4f40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a4f41  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a4f45  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004a4f48  e8af3dfeff             -call 0x488cfc
    cpu.esp -= 4;
    sub_488cfc(app, cpu);
    if (cpu.terminate) return;
    // 004a4f4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a4f4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4f51  7d0f                   -jge 0x4a4f62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4f62;
    }
    // 004a4f53  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a4f57  e81c070000             -call 0x4a5678
    cpu.esp -= 4;
    sub_4a5678(app, cpu);
    if (cpu.terminate) return;
    // 004a4f5c  891510c65900           -mov dword ptr [0x59c610], edx
    app->getMemory<x86::reg32>(x86::reg32(5883408) /* 0x59c610 */) = cpu.edx;
L_0x004a4f62:
    // 004a4f62  e80d040000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004a4f67  a110c65900             -mov eax, dword ptr [0x59c610]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883408) /* 0x59c610 */);
    // 004a4f6c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4f6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f72  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a4f75:
    // 004a4f75  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a4f7a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4f7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f80  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a4f83:
    // 004a4f83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4f85  0f8c0efdffff           -jl 0x4a4c99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c99;
    }
    // 004a4f8b  83f87f                 +cmp eax, 0x7f
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
    // 004a4f8e  0f8e74fdffff           -jle 0x4a4d08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4d08;
    }
    // 004a4f94  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a4f99  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4f9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4f9f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a4fa2:
    // 004a4fa2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a4fa4  0f8ceffcffff           -jl 0x4a4c99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a4c99;
    }
    // 004a4faa  83fa7f                 +cmp edx, 0x7f
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
    // 004a4fad  0f8e6afdffff           -jle 0x4a4d1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a4d1d;
    }
    // 004a4fb3  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a4fb8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4fbb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fbe  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a4fc1:
    // 004a4fc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a4fc3  0f8d98fdffff           -jge 0x4a4d61
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4d61;
    }
    // 004a4fc9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a4fcb  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a4fcf  e98dfdffff             -jmp 0x4a4d61
    goto L_0x004a4d61;
L_0x004a4fd4:
    // 004a4fd4  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a4fd6  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004a4fda  e9a6fdffff             -jmp 0x4a4d85
    goto L_0x004a4d85;
L_0x004a4fdf:
    // 004a4fdf  e890030000             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004a4fe4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a4fe6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a4fe9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4feb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4fec  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a4fef:
    // 004a4fef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a4ff1  0f8d95feffff           -jge 0x4a4e8c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4e8c;
    }
    // 004a4ff7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a4ff9  e98efeffff             -jmp 0x4a4e8c
    goto L_0x004a4e8c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a5000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5000  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5002  7419                   -je 0x4a501d
    if (cpu.flags.zf)
    {
        goto L_0x004a501d;
    }
    // 004a5004  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 004a500a  7417                   -je 0x4a5023
    if (cpu.flags.zf)
    {
        goto L_0x004a5023;
    }
    // 004a500c  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a5011  0f840d350000           -je 0x4a8524
    if (cpu.flags.zf)
    {
        return sub_4a8524(app, cpu);
    }
    // 004a5017  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004a501c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a501d:
    // 004a501d  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a5022  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5023:
    // 004a5023  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5024  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5025  8b4a06                 -mov ecx, dword ptr [edx + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004a5028  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a502b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a502c  8b4a05                 -mov ecx, dword ptr [edx + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a502f  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a5032  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5033  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5036  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a5039  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a503c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a503f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5040  8b4a03                 -mov ecx, dword ptr [edx + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a5043  8b5201                 -mov edx, dword ptr [edx + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a5046  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004a5049  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a504c  e8effbffff             -call 0x4a4c40
    cpu.esp -= 4;
    sub_4a4c40(app, cpu);
    if (cpu.terminate) return;
    // 004a5051  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5052  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5053  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a5060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5060  a314c65900             -mov dword ptr [0x59c614], eax
    app->getMemory<x86::reg32>(x86::reg32(5883412) /* 0x59c614 */) = cpu.eax;
    // 004a5065  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a5068(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5068  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5069  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a506a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a506c  833da8da4d0000         +cmp dword ptr [0x4ddaa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5073  741c                   -je 0x4a5091
    if (cpu.flags.zf)
    {
        goto L_0x004a5091;
    }
L_0x004a5075:
    // 004a5075  833d14c6590000         +cmp dword ptr [0x59c614], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5883412) /* 0x59c614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a507c  741f                   -je 0x4a509d
    if (cpu.flags.zf)
    {
        goto L_0x004a509d;
    }
    // 004a507e  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a5080  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5082  893da4da4d00           -mov dword ptr [0x4ddaa4], edi
    app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */) = cpu.edi;
    // 004a5088  ff1514c65900           -call dword ptr [0x59c614]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5883412) /* 0x59c614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a508e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a508f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5090  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5091:
    // 004a5091  e8764dfeff             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 004a5096  a3a8da4d00             -mov dword ptr [0x4ddaa8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */) = cpu.eax;
    // 004a509b  ebd8                   -jmp 0x4a5075
    goto L_0x004a5075;
L_0x004a509d:
    // 004a509d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a509e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a50a3  8b15a8da4d00           -mov edx, dword ptr [0x4ddaa8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */);
    // 004a50a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a50ab  8935a4da4d00           -mov dword ptr [0x4ddaa4], esi
    app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */) = cpu.esi;
    // 004a50b1  e86a4dfeff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 004a50b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a50ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a50ba  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a50bc  e8efedfdff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 004a50c1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a50c3  8b2dccab4d00           -mov ebp, dword ptr [0x4dabcc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 004a50c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a50cb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a50ce  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a50d0  e8c74afeff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 004a50d5  e979000000             -jmp 0x4a5153
    return sub_4a5153(app, cpu);
}

/* align: skip  */
void Application::sub_4a50da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a50da  8b15a8da4d00           -mov edx, dword ptr [0x4ddaa8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */);
    // 004a50e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a50e2  0f8481000000           -je 0x4a5169
    if (cpu.flags.zf)
    {
        return sub_4a5169(app, cpu);
    }
    // 004a50e8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a50ea  e86d4dfeff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004a50ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a50f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a50f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a50f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a50f9  8b15a8da4d00           -mov edx, dword ptr [0x4ddaa8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */);
    // 004a50ff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a5101  7502                   -jne 0x4a5105
    if (!cpu.flags.zf)
    {
        goto L_0x004a5105;
    }
    // 004a5103  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5104  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5105:
    // 004a5105  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5106  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a510b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a510d  890da4da4d00           -mov dword ptr [0x4ddaa4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */) = cpu.ecx;
    // 004a5113  e8084dfeff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 004a5118  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5119  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a511a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a511c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a511c  a1a4da4d00             -mov eax, dword ptr [0x4ddaa4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */);
    // 004a5121  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a5124(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5124  833d14c6590000         +cmp dword ptr [0x59c614], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5883412) /* 0x59c614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a512b  7409                   -je 0x4a5136
    if (cpu.flags.zf)
    {
        goto L_0x004a5136;
    }
    // 004a512d  833dccab4d0000         +cmp dword ptr [0x4dabcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5134  7501                   -jne 0x4a5137
    if (!cpu.flags.zf)
    {
        goto L_0x004a5137;
    }
L_0x004a5136:
    // 004a5136  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5137:
    // 004a5137  e82cffffff             -call 0x4a5068
    cpu.esp -= 4;
    sub_4a5068(app, cpu);
    if (cpu.terminate) return;
    // 004a513c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a513d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a513e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a513f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5140  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5141  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5143  e8a04afeff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004a5148  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a514a  748e                   -je 0x4a50da
    if (cpu.flags.zf)
    {
        return sub_4a50da(app, cpu);
    }
    // 004a514c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a5151  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5153  3b0da8da4d00           +cmp ecx, dword ptr [0x4ddaa8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5159  740e                   -je 0x4a5169
    if (cpu.flags.zf)
    {
        goto L_0x004a5169;
    }
    // 004a515b  8b3da4da4d00           -mov edi, dword ptr [0x4ddaa4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */);
    // 004a5161  39f9                   +cmp ecx, edi
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
    // 004a5163  0f8451ffffff           -je 0x4a50ba
    if (cpu.flags.zf)
    {
        return sub_4a50ba(app, cpu);
    }
L_0x004a5169:
    // 004a5169  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5169(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a5169;
    // 004a5124  833d14c6590000         +cmp dword ptr [0x59c614], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5883412) /* 0x59c614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a512b  7409                   -je 0x4a5136
    if (cpu.flags.zf)
    {
        goto L_0x004a5136;
    }
    // 004a512d  833dccab4d0000         +cmp dword ptr [0x4dabcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5134  7501                   -jne 0x4a5137
    if (!cpu.flags.zf)
    {
        goto L_0x004a5137;
    }
L_0x004a5136:
    // 004a5136  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5137:
    // 004a5137  e82cffffff             -call 0x4a5068
    cpu.esp -= 4;
    sub_4a5068(app, cpu);
    if (cpu.terminate) return;
    // 004a513c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a513d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a513e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a513f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5140  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5141  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5143  e8a04afeff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004a5148  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a514a  748e                   -je 0x4a50da
    if (cpu.flags.zf)
    {
        return sub_4a50da(app, cpu);
    }
    // 004a514c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a5151  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5153  3b0da8da4d00           +cmp ecx, dword ptr [0x4ddaa8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5159  740e                   -je 0x4a5169
    if (cpu.flags.zf)
    {
        goto L_0x004a5169;
    }
    // 004a515b  8b3da4da4d00           -mov edi, dword ptr [0x4ddaa4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */);
    // 004a5161  39f9                   +cmp ecx, edi
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
    // 004a5163  0f8451ffffff           -je 0x4a50ba
    if (cpu.flags.zf)
    {
        return sub_4a50ba(app, cpu);
    }
L_0x004a5169:
L_entry_0x004a5169:
    // 004a5169  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5153(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a5153;
    // 004a5124  833d14c6590000         +cmp dword ptr [0x59c614], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5883412) /* 0x59c614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a512b  7409                   -je 0x4a5136
    if (cpu.flags.zf)
    {
        goto L_0x004a5136;
    }
    // 004a512d  833dccab4d0000         +cmp dword ptr [0x4dabcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5134  7501                   -jne 0x4a5137
    if (!cpu.flags.zf)
    {
        goto L_0x004a5137;
    }
L_0x004a5136:
    // 004a5136  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5137:
    // 004a5137  e82cffffff             -call 0x4a5068
    cpu.esp -= 4;
    sub_4a5068(app, cpu);
    if (cpu.terminate) return;
    // 004a513c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a513d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a513e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a513f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5140  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5141  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5143  e8a04afeff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004a5148  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a514a  748e                   -je 0x4a50da
    if (cpu.flags.zf)
    {
        return sub_4a50da(app, cpu);
    }
    // 004a514c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a5151  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004a5153:
    // 004a5153  3b0da8da4d00           +cmp ecx, dword ptr [0x4ddaa8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5159  740e                   -je 0x4a5169
    if (cpu.flags.zf)
    {
        goto L_0x004a5169;
    }
    // 004a515b  8b3da4da4d00           -mov edi, dword ptr [0x4ddaa4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */);
    // 004a5161  39f9                   +cmp ecx, edi
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
    // 004a5163  0f8451ffffff           -je 0x4a50ba
    if (cpu.flags.zf)
    {
        return sub_4a50ba(app, cpu);
    }
L_0x004a5169:
    // 004a5169  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a513c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a513c;
    // 004a5124  833d14c6590000         +cmp dword ptr [0x59c614], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5883412) /* 0x59c614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a512b  7409                   -je 0x4a5136
    if (cpu.flags.zf)
    {
        goto L_0x004a5136;
    }
    // 004a512d  833dccab4d0000         +cmp dword ptr [0x4dabcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5134  7501                   -jne 0x4a5137
    if (!cpu.flags.zf)
    {
        goto L_0x004a5137;
    }
L_0x004a5136:
    // 004a5136  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5137:
    // 004a5137  e82cffffff             -call 0x4a5068
    cpu.esp -= 4;
    sub_4a5068(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004a513c:
    // 004a513c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a513d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a513e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a513f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5140  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5141  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5143  e8a04afeff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004a5148  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a514a  748e                   -je 0x4a50da
    if (cpu.flags.zf)
    {
        return sub_4a50da(app, cpu);
    }
    // 004a514c  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004a5151  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5153  3b0da8da4d00           +cmp ecx, dword ptr [0x4ddaa8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102248) /* 0x4ddaa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5159  740e                   -je 0x4a5169
    if (cpu.flags.zf)
    {
        goto L_0x004a5169;
    }
    // 004a515b  8b3da4da4d00           -mov edi, dword ptr [0x4ddaa4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102244) /* 0x4ddaa4 */);
    // 004a5161  39f9                   +cmp ecx, edi
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
    // 004a5163  0f8451ffffff           -je 0x4a50ba
    if (cpu.flags.zf)
    {
        return sub_4a50ba(app, cpu);
    }
L_0x004a5169:
    // 004a5169  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a516e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a5170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a5173  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5174  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5175  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5176  ff05b4da4d00           -inc dword ptr [0x4ddab4]
    (app->getMemory<x86::reg32>(x86::reg32(5102260) /* 0x4ddab4 */))++;
    // 004a517c  ff0508c65900           -inc dword ptr [0x59c608]
    (app->getMemory<x86::reg32>(x86::reg32(5883400) /* 0x59c608 */))++;
    // 004a5182  e87541feff             -call 0x4892fc
    cpu.esp -= 4;
    sub_4892fc(app, cpu);
    if (cpu.terminate) return;
    // 004a5187  833d84da4d0000         +cmp dword ptr [0x4dda84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102212) /* 0x4dda84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a518e  0f8524010000           -jne 0x4a52b8
    if (!cpu.flags.zf)
    {
        goto L_0x004a52b8;
    }
L_0x004a5194:
    // 004a5194  833d78da4d0000         +cmp dword ptr [0x4dda78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102200) /* 0x4dda78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a519b  7406                   -je 0x4a51a3
    if (cpu.flags.zf)
    {
        goto L_0x004a51a3;
    }
    // 004a519d  ff1578da4d00           -call dword ptr [0x4dda78]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102200) /* 0x4dda78 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a51a3:
    // 004a51a3  833d7cda4d0000         +cmp dword ptr [0x4dda7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102204) /* 0x4dda7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a51aa  0f8513010000           -jne 0x4a52c3
    if (!cpu.flags.zf)
    {
        goto L_0x004a52c3;
    }
L_0x004a51b0:
    // 004a51b0  beb0bf5900             -mov esi, 0x59bfb0
    cpu.esi = 5881776 /*0x59bfb0*/;
    // 004a51b5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a51b7:
    // 004a51b7  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a51ba  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a51bc  80fc01                 +cmp ah, 1
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
    // 004a51bf  0f85ba000000           -jne 0x4a527f
    if (!cpu.flags.zf)
    {
        goto L_0x004a527f;
    }
    // 004a51c5  833e00                 +cmp dword ptr [esi], 0
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
    // 004a51c8  0f8cb1000000           -jl 0x4a527f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a527f;
    }
    // 004a51ce  837e5c00               +cmp dword ptr [esi + 0x5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a51d2  7425                   -je 0x4a51f9
    if (cpu.flags.zf)
    {
        goto L_0x004a51f9;
    }
    // 004a51d4  8a563f                 -mov dl, byte ptr [esi + 0x3f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */);
    // 004a51d7  fec2                   -inc dl
    (cpu.dl)++;
    // 004a51d9  88563f                 -mov byte ptr [esi + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = cpu.dl;
    // 004a51dc  3a563d                 +cmp dl, byte ptr [esi + 0x3d]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a51df  7204                   -jb 0x4a51e5
    if (cpu.flags.cf)
    {
        goto L_0x004a51e5;
    }
    // 004a51e1  c6463f00               -mov byte ptr [esi + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
L_0x004a51e5:
    // 004a51e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a51e7  e844bb0000             -call 0x4b0d30
    cpu.esp -= 4;
    sub_4b0d30(app, cpu);
    if (cpu.terminate) return;
    // 004a51ec  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a51ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a51f1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a51f4  e89744feff             -call 0x489690
    cpu.esp -= 4;
    sub_489690(app, cpu);
    if (cpu.terminate) return;
L_0x004a51f9:
    // 004a51f9  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 004a51fc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a51fe  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a5200  7418                   -je 0x4a521a
    if (cpu.flags.zf)
    {
        goto L_0x004a521a;
    }
    // 004a5202  8a413e                 -mov al, byte ptr [ecx + 0x3e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 004a5205  fec0                   -inc al
    (cpu.al)++;
    // 004a5207  88413e                 -mov byte ptr [ecx + 0x3e], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.al;
    // 004a520a  8a613c                 -mov ah, byte ptr [ecx + 0x3c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 004a520d  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a5212  38e0                   +cmp al, ah
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
    // 004a5214  7204                   -jb 0x4a521a
    if (cpu.flags.cf)
    {
        goto L_0x004a521a;
    }
    // 004a5216  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
L_0x004a521a:
    // 004a521a  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a521d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a521f  7431                   -je 0x4a5252
    if (cpu.flags.zf)
    {
        goto L_0x004a5252;
    }
    // 004a5221  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a5224  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a5229  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a522b  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a522e  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a5231  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a5233  0f8c95000000           -jl 0x4a52ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a52ce;
    }
    // 004a5239  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a523b  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a523e  39d0                   +cmp eax, edx
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
    // 004a5240  7c0a                   -jl 0x4a524c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a524c;
    }
    // 004a5242  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a5249  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x004a524c:
    // 004a524c  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 004a5250  7c26                   -jl 0x4a5278
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5278;
    }
L_0x004a5252:
    // 004a5252  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004a5255  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a5257  7408                   -je 0x4a5261
    if (cpu.flags.zf)
    {
        goto L_0x004a5261;
    }
    // 004a5259  015128                 -add dword ptr [ecx + 0x28], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a525c  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004a5261:
    // 004a5261  83792c00               +cmp dword ptr [ecx + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5265  0f85ac000000           -jne 0x4a5317
    if (!cpu.flags.zf)
    {
        goto L_0x004a5317;
    }
    // 004a526b  8a5135                 -mov dl, byte ptr [ecx + 0x35]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 004a526e  fec2                   -inc dl
    (cpu.dl)++;
    // 004a5270  885135                 -mov byte ptr [ecx + 0x35], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = cpu.dl;
    // 004a5273  3a5134                 +cmp dl, byte ptr [ecx + 0x34]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5276  7c70                   -jl 0x4a52e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a52e8;
    }
L_0x004a5278:
    // 004a5278  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a527a  e8c145feff             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
L_0x004a527f:
    // 004a527f  43                     -inc ebx
    (cpu.ebx)++;
    // 004a5280  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a5283  83fb10                 +cmp ebx, 0x10
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
    // 004a5286  0f8c2bffffff           -jl 0x4a51b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a51b7;
    }
    // 004a528c  833d80da4d0000         +cmp dword ptr [0x4dda80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102208) /* 0x4dda80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5293  7416                   -je 0x4a52ab
    if (cpu.flags.zf)
    {
        goto L_0x004a52ab;
    }
    // 004a5295  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004a529a  a108c65900             -mov eax, dword ptr [0x59c608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883400) /* 0x59c608 */);
    // 004a529f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a52a1  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a52a3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a52a5  0f84a2000000           -je 0x4a534d
    if (cpu.flags.zf)
    {
        goto L_0x004a534d;
    }
L_0x004a52ab:
    // 004a52ab  ff0db4da4d00           +dec dword ptr [0x4ddab4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5102260) /* 0x4ddab4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a52b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a52b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a52b8:
    // 004a52b8  ff1584da4d00           -call dword ptr [0x4dda84]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102212) /* 0x4dda84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a52be  e9d1feffff             -jmp 0x4a5194
    goto L_0x004a5194;
L_0x004a52c3:
    // 004a52c3  ff157cda4d00           -call dword ptr [0x4dda7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102204) /* 0x4dda7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a52c9  e9e2feffff             -jmp 0x4a51b0
    goto L_0x004a51b0;
L_0x004a52ce:
    // 004a52ce  8b691c                 -mov ebp, dword ptr [ecx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a52d1  39ea                   +cmp edx, ebp
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
    // 004a52d3  0f8f73ffffff           -jg 0x4a524c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a524c;
    }
    // 004a52d9  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004a52e0  896920                 -mov dword ptr [ecx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004a52e3  e964ffffff             -jmp 0x4a524c
    goto L_0x004a524c;
L_0x004a52e8:
    // 004a52e8  8b4132                 -mov eax, dword ptr [ecx + 0x32]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(50) /* 0x32 */);
    // 004a52eb  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a52ee  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004a52f1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a52f4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a52f6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a52f8  89512c                 -mov dword ptr [ecx + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004a52fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a52fd  7c45                   -jl 0x4a5344
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5344;
    }
L_0x004a52ff:
    // 004a52ff  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a5302  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004a5305  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a5308  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a530a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a530c  8b692c                 -mov ebp, dword ptr [ecx + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004a530f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5312  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a5314  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004a5317:
    // 004a5317  ff492c                 -dec dword ptr [ecx + 0x2c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */))--;
    // 004a531a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a531c  0f845dffffff           -je 0x4a527f
    if (cpu.flags.zf)
    {
        goto L_0x004a527f;
    }
    // 004a5322  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5324  e8c7380000             -call 0x4a8bf0
    cpu.esp -= 4;
    sub_4a8bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a5329  833900                 +cmp dword ptr [ecx], 0
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
    // 004a532c  0f8c4dffffff           -jl 0x4a527f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a527f;
    }
    // 004a5332  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004a5335  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5337  c1fa18                 +sar edx, 0x18
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
    // 004a533a  e86541feff             -call 0x4894a4
    cpu.esp -= 4;
    sub_4894a4(app, cpu);
    if (cpu.terminate) return;
    // 004a533f  e93bffffff             -jmp 0x4a527f
    goto L_0x004a527f;
L_0x004a5344:
    // 004a5344  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 004a534b  ebb2                   -jmp 0x4a52ff
    goto L_0x004a52ff;
L_0x004a534d:
    // 004a534d  ff1580da4d00           -call dword ptr [0x4dda80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102208) /* 0x4dda80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5353  ff0db4da4d00           -dec dword ptr [0x4ddab4]
    (app->getMemory<x86::reg32>(x86::reg32(5102260) /* 0x4ddab4 */))--;
    // 004a5359  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a535a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a535b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a535c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a535d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a535e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a535f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5360  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 004a5365  e8de4bfeff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a536a  ff05b8da4d00           -inc dword ptr [0x4ddab8]
    (app->getMemory<x86::reg32>(x86::reg32(5102264) /* 0x4ddab8 */))++;
    // 004a5370  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a5374(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5374  ff0db8da4d00           +dec dword ptr [0x4ddab8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5102264) /* 0x4ddab8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a537a  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 004a537f  e9dc4bfeff             -jmp 0x489f60
    return sub_489f60(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a5390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a5392  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5394  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a5396  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5398  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a539a  7e12                   -jle 0x4a53ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a53ae;
    }
L_0x004a539c:
    // 004a539c  8b9015c65900           -mov edx, dword ptr [eax + 0x59c615]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5883413) /* 0x59c615 */);
    // 004a53a2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a53a5  39da                   +cmp edx, ebx
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
    // 004a53a7  740a                   -je 0x4a53b3
    if (cpu.flags.zf)
    {
        goto L_0x004a53b3;
    }
    // 004a53a9  40                     -inc eax
    (cpu.eax)++;
    // 004a53aa  39c8                   +cmp eax, ecx
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
    // 004a53ac  7cee                   -jl 0x4a539c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a539c;
    }
L_0x004a53ae:
    // 004a53ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a53b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a53b3:
    // 004a53b3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a53b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a53ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a53bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a53bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a53bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a53be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a53bf  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a53c2  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a53c6  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a53ca  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a53ce  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004a53d2  baf7ffffff             -mov edx, 0xfffffff7
    cpu.edx = 4294967287 /*0xfffffff7*/;
    // 004a53d7  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a53db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a53dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a53df  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a53e3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a53e6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a53e8  7e12                   -jle 0x4a53fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a53fc;
    }
    // 004a53ea  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 004a53ec  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x004a53f0:
    // 004a53f0  40                     -inc eax
    (cpu.eax)++;
    // 004a53f1  889017c65900           -mov byte ptr [eax + 0x59c617], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5883415) /* 0x59c617 */) = cpu.dl;
    // 004a53f7  39f0                   +cmp eax, esi
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
    // 004a53f9  7cf5                   -jl 0x4a53f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a53f0;
    }
    // 004a53fb  90                     -nop 
    ;
L_0x004a53fc:
    // 004a53fc  8b3dbcda4d00           -mov edi, dword ptr [0x4ddabc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102268) /* 0x4ddabc */);
    // 004a5402  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a5405  893dbcda4d00           -mov dword ptr [0x4ddabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5102268) /* 0x4ddabc */) = cpu.edi;
    // 004a540b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a540d  7c2b                   -jl 0x4a543a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a543a;
    }
L_0x004a540f:
    // 004a540f  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5413  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5415  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a5417:
    // 004a5417  a172da4d00             -mov eax, dword ptr [0x4dda72]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102194) /* 0x4dda72 */);
    // 004a541c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a541f  39c3                   +cmp ebx, eax
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
    // 004a5421  7d4a                   -jge 0x4a546d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a546d;
    }
    // 004a5423  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a5428  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a542a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a542e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a5430  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004a5432  750f                   -jne 0x4a5443
    if (!cpu.flags.zf)
    {
        goto L_0x004a5443;
    }
L_0x004a5434:
    // 004a5434  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5437  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a5438  ebdd                   -jmp 0x4a5417
    goto L_0x004a5417;
L_0x004a543a:
    // 004a543a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a543c  a3bcda4d00             -mov dword ptr [0x4ddabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5102268) /* 0x4ddabc */) = cpu.eax;
    // 004a5441  ebcc                   -jmp 0x4a540f
    goto L_0x004a540f;
L_0x004a5443:
    // 004a5443  80bebcbf590000         +cmp byte ptr [esi + 0x59bfbc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5881788) /* 0x59bfbc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a544a  75e8                   -jne 0x4a5434
    if (!cpu.flags.zf)
    {
        goto L_0x004a5434;
    }
    // 004a544c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a544f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5451  e83affffff             -call 0x4a5390
    cpu.esp -= 4;
    sub_4a5390(app, cpu);
    if (cpu.terminate) return;
    // 004a5456  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5458  75da                   -jne 0x4a5434
    if (!cpu.flags.zf)
    {
        goto L_0x004a5434;
    }
    // 004a545a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a545d  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a5460  889818c65900           -mov byte ptr [eax + 0x59c618], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5883416) /* 0x59c618 */) = cpu.bl;
    // 004a5466  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a5469  39f9                   +cmp ecx, edi
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
    // 004a546b  7cc7                   -jl 0x4a5434
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5434;
    }
L_0x004a546d:
    // 004a546d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5470  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5474  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a5478  39e8                   +cmp eax, ebp
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
    // 004a547a  0f8d94000000           -jge 0x4a5514
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5514;
    }
L_0x004a5480:
    // 004a5480  bf66000000             -mov edi, 0x66
    cpu.edi = 102 /*0x66*/;
    // 004a5485  bdffffff7f             -mov ebp, 0x7fffffff
    cpu.ebp = 2147483647 /*0x7fffffff*/;
    // 004a548a  beb0bf5900             -mov esi, 0x59bfb0
    cpu.esi = 5881776 /*0x59bfb0*/;
    // 004a548f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5491  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5493  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
L_0x004a5497:
    // 004a5497  a172da4d00             -mov eax, dword ptr [0x4dda72]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102194) /* 0x4dda72 */);
    // 004a549c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a549f  39c3                   +cmp ebx, eax
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
    // 004a54a1  7d48                   -jge 0x4a54eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a54eb;
    }
    // 004a54a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a54a8  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a54aa  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a54ae  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a54b0  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004a54b2  7506                   -jne 0x4a54ba
    if (!cpu.flags.zf)
    {
        goto L_0x004a54ba;
    }
L_0x004a54b4:
    // 004a54b4  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a54b7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a54b8  ebdd                   -jmp 0x4a5497
    goto L_0x004a5497;
L_0x004a54ba:
    // 004a54ba  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a54bd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a54bf  e8ccfeffff             -call 0x4a5390
    cpu.esp -= 4;
    sub_4a5390(app, cpu);
    if (cpu.terminate) return;
    // 004a54c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a54c6  75ec                   -jne 0x4a54b4
    if (!cpu.flags.zf)
    {
        goto L_0x004a54b4;
    }
    // 004a54c8  8a460e                 -mov al, byte ptr [esi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a54cb  39f8                   +cmp eax, edi
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
    // 004a54cd  7d0b                   -jge 0x4a54da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a54da;
    }
    // 004a54cf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a54d1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a54d5  8b6e14                 -mov ebp, dword ptr [esi + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a54d8  ebda                   -jmp 0x4a54b4
    goto L_0x004a54b4;
L_0x004a54da:
    // 004a54da  75d8                   -jne 0x4a54b4
    if (!cpu.flags.zf)
    {
        goto L_0x004a54b4;
    }
    // 004a54dc  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a54df  39cd                   +cmp ebp, ecx
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
    // 004a54e1  7ed1                   -jle 0x4a54b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a54b4;
    }
    // 004a54e3  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a54e5  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a54e9  ebc9                   -jmp 0x4a54b4
    goto L_0x004a54b4;
L_0x004a54eb:
    // 004a54eb  3b7c2410               +cmp edi, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a54ef  0f8fe2000000           -jg 0x4a55d7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a55d7;
    }
    // 004a54f5  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a54f9  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a54fc  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5500  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a5503  888318c65900           -mov byte ptr [ebx + 0x59c618], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5883416) /* 0x59c618 */) = cpu.al;
    // 004a5509  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a550c  39fe                   +cmp esi, edi
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
    // 004a550e  0f8cc3000000           -jl 0x4a55d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a55d7;
    }
L_0x004a5514:
    // 004a5514  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5517  3b442418               +cmp eax, dword ptr [esp + 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a551b  0f85ab000000           -jne 0x4a55cc
    if (!cpu.flags.zf)
    {
        goto L_0x004a55cc;
    }
    // 004a5521  8b1d15c65900           -mov ebx, dword ptr [0x59c615]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5883413) /* 0x59c615 */);
    // 004a5527  a1bcda4d00             -mov eax, dword ptr [0x4ddabc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102268) /* 0x4ddabc */);
    // 004a552c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a552f  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5531  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5535  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a5537  8b1d15c65900           -mov ebx, dword ptr [0x59c615]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5883413) /* 0x59c615 */);
    // 004a553d  8b3dbcda4d00           -mov edi, dword ptr [0x4ddabc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102268) /* 0x4ddabc */);
    // 004a5543  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a5546  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5548  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a554f  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5552  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5554  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a5558  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a555b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a555d  89b8b0bf5900           -mov dword ptr [eax + 0x59bfb0], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881776) /* 0x59bfb0 */) = cpu.edi;
    // 004a5563  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5565  0f8eb4000000           -jle 0x4a561f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a561f;
    }
L_0x004a556b:
    // 004a556b  8b8315c65900           -mov eax, dword ptr [ebx + 0x59c615]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5883413) /* 0x59c615 */);
    // 004a5571  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a5574  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a5577  bfb0bf5900             -mov edi, 0x59bfb0
    cpu.edi = 5881776 /*0x59bfb0*/;
    // 004a557c  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a557e  8a4f0c                 -mov cl, byte ptr [edi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a5581  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 004a5583  80f901                 +cmp cl, 1
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5586  0f8576000000           -jne 0x4a5602
    if (!cpu.flags.zf)
    {
        goto L_0x004a5602;
    }
    // 004a558c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a558e  7c61                   -jl 0x4a55f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a55f1;
    }
L_0x004a5590:
    // 004a5590  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5592  e8a942feff             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
    // 004a5597  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5599  e8a20afeff             -call 0x486040
    cpu.esp -= 4;
    sub_486040(app, cpu);
    if (cpu.terminate) return;
    // 004a559e  83f801                 +cmp eax, 1
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
    // 004a55a1  745f                   -je 0x4a5602
    if (cpu.flags.zf)
    {
        goto L_0x004a5602;
    }
    // 004a55a3  4b                     -dec ebx
    (cpu.ebx)--;
    // 004a55a4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a55a6  7c1c                   -jl 0x4a55c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a55c4;
    }
    // 004a55a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a55aa:
    // 004a55aa  8b8315c65900           -mov eax, dword ptr [ebx + 0x59c615]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5883413) /* 0x59c615 */);
    // 004a55b0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a55b3  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a55b6  05b0bf5900             -add eax, 0x59bfb0
    (cpu.eax) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 004a55bb  4b                     -dec ebx
    (cpu.ebx)--;
    // 004a55bc  88500c                 -mov byte ptr [eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004a55bf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a55c1  7de7                   -jge 0x4a55aa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a55aa;
    }
    // 004a55c3  90                     -nop 
    ;
L_0x004a55c4:
    // 004a55c4  c744240cf7ffffff       -mov dword ptr [esp + 0xc], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 4294967287 /*0xfffffff7*/;
L_0x004a55cc:
    // 004a55cc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a55d0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a55d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a55d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a55d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a55d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a55d7:
    // 004a55d7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a55db  40                     -inc eax
    (cpu.eax)++;
    // 004a55dc  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a55e0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a55e4  39d0                   +cmp eax, edx
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
    // 004a55e6  0f8c94feffff           -jl 0x4a5480
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5480;
    }
    // 004a55ec  e923ffffff             -jmp 0x4a5514
    goto L_0x004a5514;
L_0x004a55f1:
    // 004a55f1  8b4741                 -mov eax, dword ptr [edi + 0x41]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(65) /* 0x41 */);
    // 004a55f4  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a55f7  6bc060                 +imul eax, eax, 0x60
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004a55fa  8bb0b0bf5900           -mov esi, dword ptr [eax + 0x59bfb0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881776) /* 0x59bfb0 */);
    // 004a5600  eb8e                   -jmp 0x4a5590
    goto L_0x004a5590;
L_0x004a5602:
    // 004a5602  a108c65900             -mov eax, dword ptr [0x59c608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883400) /* 0x59c608 */);
    // 004a5607  c6470c01               -mov byte ptr [edi + 0xc], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004a560b  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a560e  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5612  43                     -inc ebx
    (cpu.ebx)++;
    // 004a5613  88470e                 -mov byte ptr [edi + 0xe], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004a5616  3b1c24                 +cmp ebx, dword ptr [esp]
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
    // 004a5619  0f8c4cffffff           -jl 0x4a556b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a556b;
    }
L_0x004a561f:
    // 004a561f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a5624  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004a5627  7da3                   -jge 0x4a55cc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a55cc;
    }
    // 004a5629  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004a562c:
    // 004a562c  8b1d15c65900           -mov ebx, dword ptr [0x59c615]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5883413) /* 0x59c615 */);
    // 004a5632  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a5635  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a5638  8a9018c65900           -mov dl, byte ptr [eax + 0x59c618]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5883416) /* 0x59c618 */);
    // 004a563e  889403b3bf5900         -mov byte ptr [ebx + eax + 0x59bfb3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5881779) /* 0x59bfb3 */ + cpu.eax * 1) = cpu.dl;
    // 004a5645  8b9815c65900           -mov ebx, dword ptr [eax + 0x59c615]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5883413) /* 0x59c615 */);
    // 004a564b  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a564e  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004a5651  c783b0bf5900ffffffff   -mov dword ptr [ebx + 0x59bfb0], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5881776) /* 0x59bfb0 */) = 4294967295 /*0xffffffff*/;
    // 004a565b  8a1518c65900           -mov dl, byte ptr [0x59c618]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5883416) /* 0x59c618 */);
    // 004a5661  40                     -inc eax
    (cpu.eax)++;
    // 004a5662  8893f4bf5900           -mov byte ptr [ebx + 0x59bff4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5881844) /* 0x59bff4 */) = cpu.dl;
    // 004a5668  39c8                   +cmp eax, ecx
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
    // 004a566a  7cc0                   -jl 0x4a562c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a562c;
    }
    // 004a566c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5670  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a5673  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5674  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5675  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5676  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a5678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5679  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a567a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a567b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a567c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a567d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a567e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a5680  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004a5687  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004a568c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a568e  b8b0bf5900             -mov eax, 0x59bfb0
    cpu.eax = 5881776 /*0x59bfb0*/;
    // 004a5693  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004a5696  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5698  8a5c023b               -mov bl, byte ptr [edx + eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1);
    // 004a569c  0fb67c023b             -movzx edi, byte ptr [edx + eax + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1));
    // 004a56a1  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a56a3  0f84b4000000           -je 0x4a575d
    if (cpu.flags.zf)
    {
        goto L_0x004a575d;
    }
    // 004a56a9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a56ab:
    // 004a56ab  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a56ad  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004a56b0  39fb                   +cmp ebx, edi
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
    // 004a56b2  7515                   -jne 0x4a56c9
    if (!cpu.flags.zf)
    {
        goto L_0x004a56c9;
    }
    // 004a56b4  833800                 +cmp dword ptr [eax], 0
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
    // 004a56b7  7c10                   -jl 0x4a56c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a56c9;
    }
    // 004a56b9  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a56bd  740a                   -je 0x4a56c9
    if (cpu.flags.zf)
    {
        goto L_0x004a56c9;
    }
    // 004a56bf  8a783a                 -mov bh, byte ptr [eax + 0x3a]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 004a56c2  41                     -inc ecx
    (cpu.ecx)++;
    // 004a56c3  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004a56c5  7402                   -je 0x4a56c9
    if (cpu.flags.zf)
    {
        goto L_0x004a56c9;
    }
    // 004a56c7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004a56c9:
    // 004a56c9  42                     -inc edx
    (cpu.edx)++;
    // 004a56ca  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a56cd  83fa10                 +cmp edx, 0x10
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
    // 004a56d0  7cd9                   -jl 0x4a56ab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a56ab;
    }
    // 004a56d2  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 004a56d9  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a56db  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004a56de  83f901                 +cmp ecx, 1
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
    // 004a56e1  7445                   -je 0x4a5728
    if (cpu.flags.zf)
    {
        goto L_0x004a5728;
    }
    // 004a56e3  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004a56ea  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a56ec  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a56ef  80b8bcbf590002         +cmp byte ptr [eax + 0x59bfbc], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881788) /* 0x59bfbc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a56f6  7509                   -jne 0x4a5701
    if (!cpu.flags.zf)
    {
        goto L_0x004a5701;
    }
    // 004a56f8  39f5                   +cmp ebp, esi
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
    // 004a56fa  7405                   -je 0x4a5701
    if (cpu.flags.zf)
    {
        goto L_0x004a5701;
    }
    // 004a56fc  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a56ff  7431                   -je 0x4a5732
    if (cpu.flags.zf)
    {
        goto L_0x004a5732;
    }
L_0x004a5701:
    // 004a5701  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004a5708  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a570a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a570d  80b8bcbf590001         +cmp byte ptr [eax + 0x59bfbc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881788) /* 0x59bfbc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5714  752c                   -jne 0x4a5742
    if (!cpu.flags.zf)
    {
        goto L_0x004a5742;
    }
    // 004a5716  39f5                   +cmp ebp, esi
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
    // 004a5718  7528                   -jne 0x4a5742
    if (!cpu.flags.zf)
    {
        goto L_0x004a5742;
    }
    // 004a571a  c680bcbf590002         -mov byte ptr [eax + 0x59bfbc], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881788) /* 0x59bfbc */) = 2 /*0x2*/;
L_0x004a5721:
    // 004a5721  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5722  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5723  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5724  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5725  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5726  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5727  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a5728:
    // 004a5728  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a572a  8883bcbf5900           -mov byte ptr [ebx + 0x59bfbc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5881788) /* 0x59bfbc */) = cpu.al;
    // 004a5730  ebef                   -jmp 0x4a5721
    goto L_0x004a5721;
L_0x004a5732:
    // 004a5732  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 004a5734  888bbcbf5900           -mov byte ptr [ebx + 0x59bfbc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5881788) /* 0x59bfbc */) = cpu.cl;
    // 004a573a  8888bcbf5900           -mov byte ptr [eax + 0x59bfbc], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881788) /* 0x59bfbc */) = cpu.cl;
    // 004a5740  ebdf                   -jmp 0x4a5721
    goto L_0x004a5721;
L_0x004a5742:
    // 004a5742  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004a5749  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a574b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a574e  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004a5750  8898bcbf5900           -mov byte ptr [eax + 0x59bfbc], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881788) /* 0x59bfbc */) = cpu.bl;
    // 004a5756  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5757  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5758  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5759  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a575a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a575b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a575c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a575d:
    // 004a575d  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004a575f  88babcbf5900           -mov byte ptr [edx + 0x59bfbc], bh
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5881788) /* 0x59bfbc */) = cpu.bh;
    // 004a5765  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5766  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5767  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5768  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5769  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a576a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a576b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a576c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a576c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a576d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a576e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5770  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5772  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a5775  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a577c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a577e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a5781  05b0bf5900             -add eax, 0x59bfb0
    (cpu.eax) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 004a5786  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a578a  7404                   -je 0x4a5790
    if (cpu.flags.zf)
    {
        goto L_0x004a5790;
    }
    // 004a578c  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a578e  7405                   -je 0x4a5795
    if (cpu.flags.zf)
    {
        goto L_0x004a5795;
    }
L_0x004a5790:
    // 004a5790  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x004a5795:
    // 004a5795  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5797  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5798  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5799  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a579a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a579a  9b                     -wait 
    /*nothing*/;
    // 004a579b  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 004a579d  9b                     -wait 
    /*nothing*/;
    // 004a579e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a579f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a579f  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 004a57a1  9b                     -wait 
    /*nothing*/;
    // 004a57a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a57a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004a57a3:
    // 004a57a3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a57a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a57a5  803d3db54d0000         +cmp byte ptr [0x4db53d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092669) /* 0x4db53d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a57ac  7416                   -je 0x4a57c4
    if (cpu.flags.zf)
    {
        goto L_0x004a57c4;
    }
    // 004a57ae  ba9a574a00             -mov edx, 0x4a579a
    cpu.edx = 4872090 /*0x4a579a*/;
    // 004a57b3  bb9f574a00             -mov ebx, 0x4a579f
    cpu.ebx = 4872095 /*0x4a579f*/;
    // 004a57b8  8915a8034e00           -mov dword ptr [0x4e03a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5112744) /* 0x4e03a8 */) = cpu.edx;
    // 004a57be  891dac034e00           -mov dword ptr [0x4e03ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5112748) /* 0x4e03ac */) = cpu.ebx;
L_0x004a57c4:
    // 004a57c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a57c6  66a1b0034e00           -mov ax, word ptr [0x4e03b0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5112752) /* 0x4e03b0 */);
    // 004a57cc  e8e1e60000             -call 0x4b3eb2
    cpu.esp -= 4;
    sub_4b3eb2(app, cpu);
    if (cpu.terminate) return;
    // 004a57d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a57d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a57d3  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004a57d4  803d3db54d0000         +cmp byte ptr [0x4db53d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092669) /* 0x4db53d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a57db  75c6                   -jne 0x4a57a3
    if (!cpu.flags.zf)
    {
        goto L_0x004a57a3;
    }
    // 004a57dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a57de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a57de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a57df  8a253cb54d00           -mov ah, byte ptr [0x4db53c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5092668) /* 0x4db53c */);
    // 004a57e5  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a57e7  7537                   -jne 0x4a5820
    if (!cpu.flags.zf)
    {
        goto L_0x004a5820;
    }
    // 004a57e9  88253db54d00           -mov byte ptr [0x4db53d], ah
    app->getMemory<x86::reg8>(x86::reg32(5092669) /* 0x4db53d */) = cpu.ah;
    // 004a57ef  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004a57f1  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a57f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a57f4  dbe3                   -fninit 
    cpu.fpu.init();
    // 004a57f6  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004a57f9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a57fa  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 004a57fc  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004a57fe  3c03                   +cmp al, 3
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
    // 004a5800  7509                   -jne 0x4a580b
    if (!cpu.flags.zf)
    {
        goto L_0x004a580b;
    }
    // 004a5802  e89cffffff             -call 0x4a57a3
    cpu.esp -= 4;
    sub_4a57a3(app, cpu);
    if (cpu.terminate) return;
    // 004a5807  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 004a5809  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x004a580b:
    // 004a580b  803d00db4d0000         +cmp byte ptr [0x4ddb00], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102336) /* 0x4ddb00 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a5812  750c                   -jne 0x4a5820
    if (!cpu.flags.zf)
    {
        goto L_0x004a5820;
    }
    // 004a5814  88353cb54d00           -mov byte ptr [0x4db53c], dh
    app->getMemory<x86::reg8>(x86::reg32(5092668) /* 0x4db53c */) = cpu.dh;
    // 004a581a  88153db54d00           -mov byte ptr [0x4db53d], dl
    app->getMemory<x86::reg8>(x86::reg32(5092669) /* 0x4db53d */) = cpu.dl;
L_0x004a5820:
    // 004a5820  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5821  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a5822(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5822  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a5830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5830  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5831  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5832  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5833  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a5836  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004a583a  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a583e  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a5842  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a5846  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a5849  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a584b  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a584e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5851  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5853  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5855  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5857  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004a5859  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a585c  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a5860  40                     -inc eax
    (cpu.eax)++;
    // 004a5861  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004a5863  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a5867  8a255eb24d00           -mov ah, byte ptr [0x4db25e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5091934) /* 0x4db25e */);
    // 004a586d  8b2d74d74d00           -mov ebp, dword ptr [0x4dd774]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */);
    // 004a5873  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a5875  0f8585030000           -jne 0x4a5c00
    if (!cpu.flags.zf)
    {
        goto L_0x004a5c00;
    }
    // 004a587b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a587f  3b054cb24d00           +cmp eax, dword ptr [0x4db24c]
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
    // 004a5885  0f8c75030000           -jl 0x4a5c00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a588b  3b0554b24d00           +cmp eax, dword ptr [0x4db254]
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
    // 004a5891  0f8d69030000           -jge 0x4a5c00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a5897  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a589b  3b0550b24d00           +cmp eax, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a58a1  0f8c59030000           -jl 0x4a5c00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a58a7  3b0558b24d00           +cmp eax, dword ptr [0x4db258]
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
    // 004a58ad  0f8d4d030000           -jge 0x4a5c00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a58b3  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a58b7  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a58bb  8b1d4cb24d00           -mov ebx, dword ptr [0x4db24c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004a58c1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a58c3  39d8                   +cmp eax, ebx
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
    // 004a58c5  0f8c35030000           -jl 0x4a5c00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a58cb  3b0554b24d00           +cmp eax, dword ptr [0x4db254]
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
    // 004a58d1  0f8d29030000           -jge 0x4a5c00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a58d7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a58db  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a58df  8b1d50b24d00           -mov ebx, dword ptr [0x4db250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004a58e5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a58e7  39d8                   +cmp eax, ebx
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
    // 004a58e9  0f8c11030000           -jl 0x4a5c00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a58ef  3b0558b24d00           +cmp eax, dword ptr [0x4db258]
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
    // 004a58f5  0f8d05030000           -jge 0x4a5c00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5c00;
    }
    // 004a58fb  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a58ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5901  8a155cb24d00           -mov dl, byte ptr [0x4db25c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004a5907  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5909  80fa10                 +cmp dl, 0x10
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
    // 004a590c  0f8565010000           -jne 0x4a5a77
    if (!cpu.flags.zf)
    {
        goto L_0x004a5a77;
    }
    // 004a5912  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004a5915:
    // 004a5915  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5919  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a591d  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004a5923  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004a5926  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004a592c  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004a592f  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a5935  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a5937  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a593b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004a593f:
    // 004a593f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5941  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a5943  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004a5946  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a594a  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a5950  726b                   -jb 0x4a59bd
    if (cpu.flags.cf)
    {
        goto L_0x004a59bd;
    }
    // 004a5952  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a5958  7340                   -jae 0x4a599a
    if (!cpu.flags.cf)
    {
        goto L_0x004a599a;
    }
    // 004a595a  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a595d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a595f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5961  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004a5964  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a5967  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a5969  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004a596f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a5972  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004a5977  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a597a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a597c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a597e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a5981  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5983  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004a5986  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5988  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a598b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5991  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a5996  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5998  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a599a:
    // 004a599a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a599c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a59a2  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a59a5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a59a7  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a59aa  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004a59b0  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a59b3  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a59b6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a59b8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a59ba  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a59bd:
    // 004a59bd  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a59c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a59c2  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a59c4  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a59c7  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a59cb  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a59d1  726b                   -jb 0x4a5a3e
    if (cpu.flags.cf)
    {
        goto L_0x004a5a3e;
    }
    // 004a59d3  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a59d9  7340                   -jae 0x4a5a1b
    if (!cpu.flags.cf)
    {
        goto L_0x004a5a1b;
    }
    // 004a59db  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a59de  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a59e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a59e2  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004a59e5  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a59e8  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a59ea  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004a59f0  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a59f3  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004a59f8  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a59fb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a59fd  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a59ff  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a5a02  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5a04  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004a5a07  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5a09  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a5a0c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5a12  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a5a17  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5a19  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a5a1b:
    // 004a5a1b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5a1d  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a5a23  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a5a26  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5a28  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a5a2b  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004a5a31  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a5a34  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a5a37  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5a39  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5a3b  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a5a3e:
    // 004a5a3e  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a5a41  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a5a45  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a5a46  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a5a47  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 004a5a4b  0f85eefeffff           -jne 0x4a593f
    if (!cpu.flags.zf)
    {
        goto L_0x004a593f;
    }
    // 004a5a51  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5a54  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5a58  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a5a5c  41                     -inc ecx
    (cpu.ecx)++;
    // 004a5a5d  01d7                   +add edi, edx
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
    // 004a5a5f  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004a5a63  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a5a64  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004a5a68  0f85a7feffff           -jne 0x4a5915
    if (!cpu.flags.zf)
    {
        goto L_0x004a5915;
    }
L_0x004a5a6e:
    // 004a5a6e  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a5a71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5a72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5a73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5a74  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a5a77:
    // 004a5a77  80fa0f                 +cmp dl, 0xf
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
    // 004a5a7a  0f8577010000           -jne 0x4a5bf7
    if (!cpu.flags.zf)
    {
        goto L_0x004a5bf7;
    }
    // 004a5a80  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004a5a84:
    // 004a5a84  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5a88  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a5a8c  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004a5a92  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004a5a95  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004a5a9b  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004a5a9e  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004a5aa4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a5aa6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5aaa  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x004a5aae:
    // 004a5aae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5ab0  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a5ab2  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004a5ab5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a5ab8  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004a5abb  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a5abd  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a5ac3  7273                   -jb 0x4a5b38
    if (cpu.flags.cf)
    {
        goto L_0x004a5b38;
    }
    // 004a5ac5  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a5acb  7348                   -jae 0x4a5b15
    if (!cpu.flags.cf)
    {
        goto L_0x004a5b15;
    }
    // 004a5acd  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a5ad0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5ad2  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004a5ad7  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004a5ada  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a5adc  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004a5ae2  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a5ae5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5ae7  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a5aea  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5aec  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a5aee  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a5af1  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5af7  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a5af9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a5afc  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5afe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5b00  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a5b03  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5b09  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5b0b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a5b0e  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a5b13  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a5b15:
    // 004a5b15  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5b17  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a5b1d  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004a5b20  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5b22  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a5b25  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004a5b2b  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004a5b2e  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a5b31  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5b33  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5b35  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a5b38:
    // 004a5b38  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a5b3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5b3d  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a5b3f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a5b42  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a5b46  81fb00000010           +cmp ebx, 0x10000000
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
    // 004a5b4c  7273                   -jb 0x4a5bc1
    if (cpu.flags.cf)
    {
        goto L_0x004a5bc1;
    }
    // 004a5b4e  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004a5b54  7348                   -jae 0x4a5b9e
    if (!cpu.flags.cf)
    {
        goto L_0x004a5b9e;
    }
    // 004a5b56  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a5b59  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5b5b  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004a5b60  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004a5b63  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a5b65  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004a5b6b  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a5b6e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5b70  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a5b73  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5b75  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a5b77  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004a5b7a  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5b80  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a5b82  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a5b85  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5b87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5b89  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004a5b8c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a5b92  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5b94  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004a5b97  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004a5b9c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a5b9e:
    // 004a5b9e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5ba0  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004a5ba6  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004a5ba9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a5bab  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a5bae  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004a5bb4  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004a5bb7  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a5bba  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5bbc  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5bbe  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004a5bc1:
    // 004a5bc1  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a5bc4  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a5bc8  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a5bc9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a5bca  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004a5bce  0f85dafeffff           -jne 0x4a5aae
    if (!cpu.flags.zf)
    {
        goto L_0x004a5aae;
    }
    // 004a5bd4  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5bd8  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5bdc  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a5be0  40                     -inc eax
    (cpu.eax)++;
    // 004a5be1  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a5be3  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a5be7  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a5be8  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004a5bec  0f847cfeffff           -je 0x4a5a6e
    if (cpu.flags.zf)
    {
        goto L_0x004a5a6e;
    }
    // 004a5bf2  e98dfeffff             -jmp 0x4a5a84
    goto L_0x004a5a84;
L_0x004a5bf7:
    // 004a5bf7  80fa08                 +cmp dl, 8
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
    // 004a5bfa  0f849c000000           -je 0x4a5c9c
    if (cpu.flags.zf)
    {
        goto L_0x004a5c9c;
    }
L_0x004a5c00:
    // 004a5c00  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a5c04  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5c06  0f8e62feffff           -jle 0x4a5a6e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5a6e;
    }
    // 004a5c0c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5c10  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5c14  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a5c18  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5c1a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5c1c  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a5c20  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004a5c24:
    // 004a5c24  8b742448               -mov esi, dword ptr [esp + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a5c28  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5c2a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5c2c  7e51                   -jle 0x4a5c7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5c7f;
    }
    // 004a5c2e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a5c32  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a5c36  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a5c3a  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a5c3e  46                     -inc esi
    (cpu.esi)++;
L_0x004a5c3f:
    // 004a5c3f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5c41  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004a5c43  47                     -inc edi
    (cpu.edi)++;
    // 004a5c44  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a5c46  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a5c49  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004a5c4c  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004a5c50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a5c52  0f858f000000           -jne 0x4a5ce7
    if (!cpu.flags.zf)
    {
        goto L_0x004a5ce7;
    }
L_0x004a5c58:
    // 004a5c58  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a5c5c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a5c5e  7411                   -je 0x4a5c71
    if (cpu.flags.zf)
    {
        goto L_0x004a5c71;
    }
    // 004a5c60  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a5c62  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a5c66  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a5c6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5c6c  e86fe20000             -call 0x4b3ee0
    cpu.esp -= 4;
    sub_4b3ee0(app, cpu);
    if (cpu.terminate) return;
L_0x004a5c71:
    // 004a5c71  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a5c75  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a5c78  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a5c7b  39c1                   +cmp ecx, eax
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
    // 004a5c7d  7cc0                   -jl 0x4a5c3f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5c3f;
    }
L_0x004a5c7f:
    // 004a5c7f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5c83  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a5c87  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5c8b  46                     -inc esi
    (cpu.esi)++;
    // 004a5c8c  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5c8e  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004a5c92  39d6                   +cmp esi, edx
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
    // 004a5c94  0f8dd4fdffff           -jge 0x4a5a6e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5a6e;
    }
    // 004a5c9a  eb88                   -jmp 0x4a5c24
    goto L_0x004a5c24;
L_0x004a5c9c:
    // 004a5c9c  8b1d68b24d00           -mov ebx, dword ptr [0x4db268]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 004a5ca2  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5ca4  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5ca6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a5ca7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5ca8  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a5cac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5cad  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5cb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5cb2  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a5cb6  8b0d6cb24d00           -mov ecx, dword ptr [0x4db26c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004a5cbc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a5cbf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5cc1  a160b24d00             -mov eax, dword ptr [0x4db260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 004a5cc6  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a5cc8  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a5ccc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5cce  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5cd0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a5cd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5cd2  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a5cd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5cd6  e891e40000             -call 0x4b416c
    cpu.esp -= 4;
    sub_4b416c(app, cpu);
    if (cpu.terminate) return;
    // 004a5cdb  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a5cde  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a5ce1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ce2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ce3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5ce4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a5ce7:
    // 004a5ce7  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004a5ceb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a5cef  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5cf3  01c8                   +add eax, ecx
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
    // 004a5cf5  e8e6e10000             -call 0x4b3ee0
    cpu.esp -= 4;
    sub_4b3ee0(app, cpu);
    if (cpu.terminate) return;
    // 004a5cfa  e959ffffff             -jmp 0x4a5c58
    goto L_0x004a5c58;
}

/* align: skip 0x90 */
void Application::sub_4a5d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5d00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5d01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5d02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5d03  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a5d06  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a5d0a  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a5d0e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a5d12  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a5d14  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a5d16  0f8eae000000           -jle 0x4a5dca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5dca;
    }
    // 004a5d1c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a5d1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a5d20  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a5d23  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5d25  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004a5d27  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004a5d2b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a5d2e  6bc700                 -imul eax, edi, 0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a5d31  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 004a5d36  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5d39  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004a5d3d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a5d3f  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a5d41  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a5d43  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a5d47  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004a5d4b:
    // 004a5d4b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5d4f  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5d52  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a5d56  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5d58  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5d5a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5d5c  7e4d                   -jle 0x4a5dab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5dab;
    }
    // 004a5d5e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5d62  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5d66  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a5d6a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a5d6e  46                     -inc esi
    (cpu.esi)++;
L_0x004a5d6f:
    // 004a5d6f  0fb62f                 -movzx ebp, byte ptr [edi]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 004a5d72  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a5d74  47                     -inc edi
    (cpu.edi)++;
    // 004a5d75  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 004a5d78  83e50f                 -and ebp, 0xf
    cpu.ebp &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a5d7b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5d7d  7554                   -jne 0x4a5dd3
    if (!cpu.flags.zf)
    {
        goto L_0x004a5dd3;
    }
L_0x004a5d7f:
    // 004a5d7f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a5d81  741a                   -je 0x4a5d9d
    if (cpu.flags.zf)
    {
        goto L_0x004a5d9d;
    }
    // 004a5d83  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 004a5d8a  81c31cd74d00           -add ebx, 0x4dd71c
    (cpu.ebx) += x86::reg32(x86::sreg32(5101340 /*0x4dd71c*/));
    // 004a5d90  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5d94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a5d96  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a5d98  e8d37a0000             -call 0x4ad870
    cpu.esp -= 4;
    sub_4ad870(app, cpu);
    if (cpu.terminate) return;
L_0x004a5d9d:
    // 004a5d9d  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a5da1  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a5da4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a5da7  39e9                   +cmp ecx, ebp
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
    // 004a5da9  7cc4                   -jl 0x4a5d6f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d6f;
    }
L_0x004a5dab:
    // 004a5dab  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5daf  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5db3  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a5db7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a5dbb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5dbd  41                     -inc ecx
    (cpu.ecx)++;
    // 004a5dbe  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a5dc2  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a5dc6  39d9                   +cmp ecx, ebx
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
    // 004a5dc8  7c81                   -jl 0x4a5d4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5d4b;
    }
L_0x004a5dca:
    // 004a5dca  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a5dcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5dce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5dcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5dd0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a5dd3:
    // 004a5dd3  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004a5dd6  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5dda  81c31cd74d00           -add ebx, 0x4dd71c
    (cpu.ebx) += x86::reg32(x86::sreg32(5101340 /*0x4dd71c*/));
    // 004a5de0  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a5de4  01c8                   +add eax, ecx
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
    // 004a5de6  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a5de8  e8837a0000             -call 0x4ad870
    cpu.esp -= 4;
    sub_4ad870(app, cpu);
    if (cpu.terminate) return;
    // 004a5ded  eb90                   -jmp 0x4a5d7f
    goto L_0x004a5d7f;
}

/* align: skip 0x90 */
void Application::sub_4a5df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a5df0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a5df1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a5df2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a5df3  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a5df6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a5df8  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a5dfc  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a5e00  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a5e04  a05cb24d00             -mov al, byte ptr [0x4db25c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004a5e09  3c10                   +cmp al, 0x10
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
    // 004a5e0b  0f837c010000           -jae 0x4a5f8d
    if (!cpu.flags.cf)
    {
        goto L_0x004a5f8d;
    }
    // 004a5e11  3c08                   +cmp al, 8
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
    // 004a5e13  0f82ac010000           -jb 0x4a5fc5
    if (cpu.flags.cf)
    {
        goto L_0x004a5fc5;
    }
    // 004a5e19  0f8798010000           -ja 0x4a5fb7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5fb7;
    }
    // 004a5e1f  bfec634a00             -mov edi, 0x4a63ec
    cpu.edi = 4875244 /*0x4a63ec*/;
L_0x004a5e24:
    // 004a5e24  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a5e26  0f8499010000           -je 0x4a5fc5
    if (cpu.flags.zf)
    {
        goto L_0x004a5fc5;
    }
    // 004a5e2c  8b2d4cb24d00           -mov ebp, dword ptr [0x4db24c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004a5e32  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5e34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a5e36  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004a5e3a  39ee                   +cmp esi, ebp
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
    // 004a5e3c  7d04                   -jge 0x4a5e42
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5e42;
    }
    // 004a5e3e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a5e40  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a5e42:
    // 004a5e42  8b0d50b24d00           -mov ecx, dword ptr [0x4db250]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004a5e48  39ca                   +cmp edx, ecx
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
    // 004a5e4a  7d06                   -jge 0x4a5e52
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5e52;
    }
    // 004a5e4c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5e4e  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004a5e52:
    // 004a5e52  8b2d54b24d00           -mov ebp, dword ptr [0x4db254]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004a5e58  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004a5e5b  39e9                   +cmp ecx, ebp
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
    // 004a5e5d  7e04                   -jle 0x4a5e63
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5e63;
    }
    // 004a5e5f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a5e61  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a5e63:
    // 004a5e63  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a5e67  8b2d58b24d00           -mov ebp, dword ptr [0x4db258]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004a5e6d  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5e6f  39e9                   +cmp ecx, ebp
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
    // 004a5e71  7e08                   -jle 0x4a5e7b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a5e7b;
    }
    // 004a5e73  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a5e75  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5e77  894c2444               -mov dword ptr [esp + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ecx;
L_0x004a5e7b:
    // 004a5e7b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a5e7d  0f8c42010000           -jl 0x4a5fc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5fc5;
    }
    // 004a5e83  837c244400             +cmp dword ptr [esp + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5e88  0f8c37010000           -jl 0x4a5fc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a5fc5;
    }
    // 004a5e8e  39d8                   +cmp eax, ebx
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
    // 004a5e90  0f8d2f010000           -jge 0x4a5fc5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5fc5;
    }
    // 004a5e96  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5e9a  3b4c2444               +cmp ecx, dword ptr [esp + 0x44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5e9e  0f8d21010000           -jge 0x4a5fc5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5fc5;
    }
    // 004a5ea4  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a5ea8  036c2418               -add ebp, dword ptr [esp + 0x18]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a5eac  0faf6c2448             -imul ebp, dword ptr [esp + 0x48]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */))));
    // 004a5eb1  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a5eb4  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a5eb8  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a5ebb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a5ebd  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004a5ec0  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004a5ec3  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a5ec6  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a5eca  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5ecc  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 004a5ecf  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a5ed3  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004a5ed6  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004a5eda  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 004a5ede  03542418               -add edx, dword ptr [esp + 0x18]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004a5ee2  8b2d6cb24d00           -mov ebp, dword ptr [0x4db26c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004a5ee8  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a5eeb  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a5eed  8b2d60b24d00           -mov ebp, dword ptr [0x4db260]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 004a5ef3  032a                   -add ebp, dword ptr [edx]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004a5ef5  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004a5efb  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5efd  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a5f00  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a5f03  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a5f05  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a5f07  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a5f09  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 004a5f0c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a5f0e  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a5f12  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004a5f15  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a5f19  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a5f1b  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a5f1e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a5f22  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a5f24  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004a5f29  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004a5f2b  b108                   -mov cl, 8
    cpu.cl = 8 /*0x8*/;
    // 004a5f2d  88442424               -mov byte ptr [esp + 0x24], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.al;
    // 004a5f31  2a4c2410               -sub cl, byte ptr [esp + 0x10]
    (cpu.cl) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004a5f35  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 004a5f37  d2e0                   -shl al, cl
    cpu.al <<= cpu.cl % 32;
    // 004a5f39  88442420               -mov byte ptr [esp + 0x20], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.al;
L_0x004a5f3d:
    // 004a5f3d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a5f41  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a5f44  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a5f48  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a5f4c  39f0                   +cmp eax, esi
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
    // 004a5f4e  0f8d71000000           -jge 0x4a5fc5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a5fc5;
    }
    // 004a5f54  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a5f58  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a5f5c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5f60  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a5f62  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
    // 004a5f66  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a5f68  7564                   -jne 0x4a5fce
    if (!cpu.flags.zf)
    {
        goto L_0x004a5fce;
    }
L_0x004a5f6a:
    // 004a5f6a  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a5f6f  0f8591000000           -jne 0x4a6006
    if (!cpu.flags.zf)
    {
        goto L_0x004a6006;
    }
L_0x004a5f75:
    // 004a5f75  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004a5f79  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a5f7d  8b1d68b24d00           -mov ebx, dword ptr [0x4db268]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 004a5f83  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a5f85  01dd                   +add ebp, ebx
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
    // 004a5f87  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004a5f8b  ebb0                   -jmp 0x4a5f3d
    goto L_0x004a5f3d;
L_0x004a5f8d:
    // 004a5f8d  770a                   -ja 0x4a5f99
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5f99;
    }
    // 004a5f8f  bf30644a00             -mov edi, 0x4a6430
    cpu.edi = 4875312 /*0x4a6430*/;
    // 004a5f94  e98bfeffff             -jmp 0x4a5e24
    goto L_0x004a5e24;
L_0x004a5f99:
    // 004a5f99  3c18                   +cmp al, 0x18
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
    // 004a5f9b  7228                   -jb 0x4a5fc5
    if (cpu.flags.cf)
    {
        goto L_0x004a5fc5;
    }
    // 004a5f9d  770a                   -ja 0x4a5fa9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a5fa9;
    }
    // 004a5f9f  bf80644a00             -mov edi, 0x4a6480
    cpu.edi = 4875392 /*0x4a6480*/;
    // 004a5fa4  e97bfeffff             -jmp 0x4a5e24
    goto L_0x004a5e24;
L_0x004a5fa9:
    // 004a5fa9  3c20                   +cmp al, 0x20
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
    // 004a5fab  7518                   -jne 0x4a5fc5
    if (!cpu.flags.zf)
    {
        goto L_0x004a5fc5;
    }
    // 004a5fad  bf10654a00             -mov edi, 0x4a6510
    cpu.edi = 4875536 /*0x4a6510*/;
    // 004a5fb2  e96dfeffff             -jmp 0x4a5e24
    goto L_0x004a5e24;
L_0x004a5fb7:
    // 004a5fb7  3c0f                   +cmp al, 0xf
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
    // 004a5fb9  750a                   -jne 0x4a5fc5
    if (!cpu.flags.zf)
    {
        goto L_0x004a5fc5;
    }
    // 004a5fbb  bf30644a00             -mov edi, 0x4a6430
    cpu.edi = 4875312 /*0x4a6430*/;
    // 004a5fc0  e95ffeffff             -jmp 0x4a5e24
    goto L_0x004a5e24;
L_0x004a5fc5:
    // 004a5fc5  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004a5fc8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5fc9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5fca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a5fcb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a5fce:
    // 004a5fce  8a5c2424               -mov bl, byte ptr [esp + 0x24]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a5fd2  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a5fd4  8b1514d74d00           -mov edx, dword ptr [0x4dd714]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101332) /* 0x4dd714 */);
    // 004a5fda  20d8                   -and al, bl
    cpu.al &= x86::reg8(x86::sreg8(cpu.bl));
    // 004a5fdc  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a5fe1  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a5fe3  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a5fe5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a5fe7  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 004a5fe9  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a5fea  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
L_0x004a5fee:
    // 004a5fee  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a5fef  0f8475ffffff           -je 0x4a5f6a
    if (cpu.flags.zf)
    {
        goto L_0x004a5f6a;
    }
    // 004a5ff5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a5ff7  8b1514d74d00           -mov edx, dword ptr [0x4dd714]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101332) /* 0x4dd714 */);
    // 004a5ffd  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a5fff  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a6000  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6002  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6004  ebe8                   -jmp 0x4a5fee
    goto L_0x004a5fee;
L_0x004a6006:
    // 004a6006  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a6008  8a642428               -mov ah, byte ptr [esp + 0x28]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a600c  8a4c2420               -mov cl, byte ptr [esp + 0x20]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a6010  20e0                   -and al, ah
    cpu.al &= x86::reg8(x86::sreg8(cpu.ah));
    // 004a6012  8b1514d74d00           -mov edx, dword ptr [0x4dd714]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101332) /* 0x4dd714 */);
    // 004a6018  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 004a601a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a601f  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6021  e94fffffff             -jmp 0x4a5f75
    goto L_0x004a5f75;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a6028(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6028  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6029  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a602a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a602b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a602c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a602d  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 004a6033  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004a603a  8994240c030000         -mov dword ptr [esp + 0x30c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */) = cpu.edx;
    // 004a6041  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6043  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a6045:
    // 004a6045  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a6048  8b88600e5700           -mov ecx, dword ptr [eax + 0x570e60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5705312) /* 0x570e60 */);
    // 004a604e  8b98600e5700           -mov ebx, dword ptr [eax + 0x570e60]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5705312) /* 0x570e60 */);
    // 004a6054  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a6057  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a605a  884c14fd               -mov byte ptr [esp + edx - 3], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.edx * 1) = cpu.cl;
    // 004a605e  885c14fe               -mov byte ptr [esp + edx - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1) = cpu.bl;
    // 004a6062  8a98600e5700           -mov bl, byte ptr [eax + 0x570e60]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5705312) /* 0x570e60 */);
    // 004a6068  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a606b  885c14ff               -mov byte ptr [esp + edx - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1) = cpu.bl;
    // 004a606f  3d00040000             +cmp eax, 0x400
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
    // 004a6074  75cf                   -jne 0x4a6045
    if (!cpu.flags.zf)
    {
        goto L_0x004a6045;
    }
    // 004a6076  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004a607d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a607f  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a6082  89bc2404030000         -mov dword ptr [esp + 0x304], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edi;
    // 004a6089  89842408030000         -mov dword ptr [esp + 0x308], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */) = cpu.eax;
L_0x004a6090:
    // 004a6090  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004a6097  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6099  8a0414                 -mov al, byte ptr [esp + edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 004a609c  89842418030000         -mov dword ptr [esp + 0x318], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.eax;
    // 004a60a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a60a5  8a441401               -mov al, byte ptr [esp + edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 004a60a9  89842410030000         -mov dword ptr [esp + 0x310], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.eax;
    // 004a60b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a60b2  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004a60b9  8a441402               -mov al, byte ptr [esp + edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.edx * 1);
    // 004a60bd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a60bf  89842414030000         -mov dword ptr [esp + 0x314], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */) = cpu.eax;
L_0x004a60c6:
    // 004a60c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a60c8  8a5103                 -mov dl, byte ptr [ecx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 004a60cb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a60cd  754b                   -jne 0x4a611a
    if (!cpu.flags.zf)
    {
        goto L_0x004a611a;
    }
    // 004a60cf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a60d1:
    // 004a60d1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a60d3  8b9c240c030000         -mov ebx, dword ptr [esp + 0x30c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 004a60da  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004a60dc  8bac2408030000         -mov ebp, dword ptr [esp + 0x308]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 004a60e3  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a60e5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a60e8  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004a60ee  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004a60f0  39e9                   +cmp ecx, ebp
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
    // 004a60f2  75d2                   -jne 0x4a60c6
    if (!cpu.flags.zf)
    {
        goto L_0x004a60c6;
    }
    // 004a60f4  8b842404030000         -mov eax, dword ptr [esp + 0x304]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004a60fb  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a60fe  47                     -inc edi
    (cpu.edi)++;
    // 004a60ff  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 004a6106  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a610c  7c82                   -jl 0x4a6090
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6090;
    }
    // 004a610e  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 004a6114  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6115  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6116  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6117  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6118  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6119  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a611a:
    // 004a611a  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004a611f  89942424030000         -mov dword ptr [esp + 0x324], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.edx;
    // 004a6126  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6128  8b942418030000         -mov edx, dword ptr [esp + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */);
    // 004a612f  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a6132  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6134  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004a6137  8984241c030000         -mov dword ptr [esp + 0x31c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */) = cpu.eax;
    // 004a613e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6140  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a6142  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 004a614d  89842420030000         -mov dword ptr [esp + 0x320], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 004a6154  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6156  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6159  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a6160  0384241c030000         -add eax, dword ptr [esp + 0x31c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */)));
    // 004a6167  0fb66901               -movzx ebp, byte ptr [ecx + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 004a616b  3dff000000             +cmp eax, 0xff
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
    // 004a6170  7e05                   -jle 0x4a6177
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6177;
    }
    // 004a6172  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004a6177:
    // 004a6177  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 004a617e  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a6181  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 004a618c  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 004a6193  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6195  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6198  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a619f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a61a1  3dff000000             +cmp eax, 0xff
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
    // 004a61a6  7e05                   -jle 0x4a61ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a61ad;
    }
    // 004a61a8  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004a61ad:
    // 004a61ad  8b942414030000         -mov edx, dword ptr [esp + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 004a61b4  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a61b7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a61b9  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004a61be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a61c0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a61c3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a61c5  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 004a61cc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a61ce  39da                   +cmp edx, ebx
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
    // 004a61d0  7e02                   -jle 0x4a61d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a61d4;
    }
    // 004a61d2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004a61d4:
    // 004a61d4  8b842424030000         -mov eax, dword ptr [esp + 0x324]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 004a61db  8b9c2428030000         -mov ebx, dword ptr [esp + 0x328]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */);
    // 004a61e2  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a61e5  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004a61e8  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 004a61eb  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a61ed  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a61ef  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a61f1  e876c4fdff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004a61f6  e9d6feffff             -jmp 0x4a60d1
    goto L_0x004a60d1;
}

/* align: skip 0x90 */
void Application::sub_4a61fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a61fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a61fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a61fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a61ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6200  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6201  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6202  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a6205  8b1574d74d00           -mov edx, dword ptr [0x4dd774]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */);
    // 004a620b  e8d050ffff             -call 0x49b2e0
    cpu.esp -= 4;
    sub_49b2e0(app, cpu);
    if (cpu.terminate) return;
    // 004a6210  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a6212  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6214  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6219  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a621c  6be800                 -imul ebp, eax, 0
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a621f  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004a6222  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6228  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a622c  6bdb00                 -imul ebx, ebx, 0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a622f  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a6232  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a6238  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004a623c  6bff00                 -imul edi, edi, 0
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004a623f  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a6243  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a6245  8d4240                 -lea eax, [edx + 0x40]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004a6248  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a624a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a624e:
    // 004a624e  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a6256  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a6258  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a625a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a625d  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a6261  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a6269  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a626b  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a626e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6270  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6273  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a6277  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a627f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a6281  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a6284  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a6286  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6289  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a628d  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004a6295  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a6297  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a629a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a629c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a629f  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a62a3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a62a6  81c6ff000000           -add esi, 0xff
    (cpu.esi) += x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a62ac  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a62af  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 004a62b2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a62b6  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a62b8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a62bc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a62be  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a62c2  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a62c4  39c1                   +cmp ecx, eax
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
    // 004a62c6  7586                   -jne 0x4a624e
    if (!cpu.flags.zf)
    {
        goto L_0x004a624e;
    }
    // 004a62c8  803d5cb24d0008         +cmp byte ptr [0x4db25c], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a62cf  760a                   -jbe 0x4a62db
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a62db;
    }
    // 004a62d1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a62d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a62db:
    // 004a62db  8b1574d74d00           -mov edx, dword ptr [0x4dd774]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */);
    // 004a62e1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a62e5  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a62e8  e83bfdffff             -call 0x4a6028
    cpu.esp -= 4;
    sub_4a6028(app, cpu);
    if (cpu.terminate) return;
    // 004a62ed  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a62f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a62f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a62f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a62f8  833d74d74d0000         +cmp dword ptr [0x4dd774], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a62ff  7519                   -jne 0x4a631a
    if (!cpu.flags.zf)
    {
        goto L_0x004a631a;
    }
    // 004a6301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6302  b940100000             -mov ecx, 0x1040
    cpu.ecx = 4160 /*0x1040*/;
    // 004a6307  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6309  890d78d74d00           -mov dword ptr [0x4dd778], ecx
    app->getMemory<x86::reg32>(x86::reg32(5101432) /* 0x4dd778 */) = cpu.ecx;
    // 004a630f  e8cc80ffff             -call 0x49e3e0
    cpu.esp -= 4;
    sub_49e3e0(app, cpu);
    if (cpu.terminate) return;
    // 004a6314  a374d74d00             -mov dword ptr [0x4dd774], eax
    app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */) = cpu.eax;
    // 004a6319  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a631a:
    // 004a631a  e835000000             -call 0x4a6354
    cpu.esp -= 4;
    sub_4a6354(app, cpu);
    if (cpu.terminate) return;
    // 004a631f  833dfcd64d0001         +cmp dword ptr [0x4dd6fc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101308) /* 0x4dd6fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6326  7414                   -je 0x4a633c
    if (cpu.flags.zf)
    {
        goto L_0x004a633c;
    }
    // 004a6328  833d00d74d0000         +cmp dword ptr [0x4dd700], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101312) /* 0x4dd700 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a632f  7416                   -je 0x4a6347
    if (cpu.flags.zf)
    {
        goto L_0x004a6347;
    }
    // 004a6331  c7057cd74d0030584a00   -mov dword ptr [0x4dd77c], 0x4a5830
    app->getMemory<x86::reg32>(x86::reg32(5101436) /* 0x4dd77c */) = 4872240 /*0x4a5830*/;
    // 004a633b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a633c:
    // 004a633c  c7057cd74d00f05d4a00   -mov dword ptr [0x4dd77c], 0x4a5df0
    app->getMemory<x86::reg32>(x86::reg32(5101436) /* 0x4dd77c */) = 4873712 /*0x4a5df0*/;
    // 004a6346  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6347:
    // 004a6347  c7057cd74d00005d4a00   -mov dword ptr [0x4dd77c], 0x4a5d00
    app->getMemory<x86::reg32>(x86::reg32(5101436) /* 0x4dd77c */) = 4873472 /*0x4a5d00*/;
    // 004a6351  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a6354(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6354  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6355  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6356  833d98d74d0000         +cmp dword ptr [0x4dd798], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101464) /* 0x4dd798 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a635d  7515                   -jne 0x4a6374
    if (!cpu.flags.zf)
    {
        goto L_0x004a6374;
    }
    // 004a635f  833d00d74d0000         +cmp dword ptr [0x4dd700], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101312) /* 0x4dd700 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6366  7409                   -je 0x4a6371
    if (cpu.flags.zf)
    {
        goto L_0x004a6371;
    }
    // 004a6368  833dfcd64d0004         +cmp dword ptr [0x4dd6fc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101308) /* 0x4dd6fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a636f  7431                   -je 0x4a63a2
    if (cpu.flags.zf)
    {
        goto L_0x004a63a2;
    }
L_0x004a6371:
    // 004a6371  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6372  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6373  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6374:
    // 004a6374  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 004a6379  b81cd74d00             -mov eax, 0x4dd71c
    cpu.eax = 5101340 /*0x4dd71c*/;
    // 004a637e  8b1574d74d00           -mov edx, dword ptr [0x4dd774]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */);
    // 004a6384  e8f745feff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004a6389  803d5cb24d0008         +cmp byte ptr [0x4db25c], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6390  77df                   -ja 0x4a6371
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a6371;
    }
    // 004a6392  a174d74d00             -mov eax, dword ptr [0x4dd774]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */);
    // 004a6397  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004a639a  e889fcffff             -call 0x4a6028
    cpu.esp -= 4;
    sub_4a6028(app, cpu);
    if (cpu.terminate) return;
    // 004a639f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a63a2:
    // 004a63a2  a114d74d00             -mov eax, dword ptr [0x4dd714]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101332) /* 0x4dd714 */);
    // 004a63a7  e850feffff             -call 0x4a61fc
    cpu.esp -= 4;
    sub_4a61fc(app, cpu);
    if (cpu.terminate) return;
    // 004a63ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a63b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a63b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a63b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a63b2  8b1574d74d00           -mov edx, dword ptr [0x4dd774]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */);
    // 004a63b8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a63ba  750b                   -jne 0x4a63c7
    if (!cpu.flags.zf)
    {
        goto L_0x004a63c7;
    }
    // 004a63bc  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a63be  89357cd74d00           -mov dword ptr [0x4dd77c], esi
    app->getMemory<x86::reg32>(x86::reg32(5101436) /* 0x4dd77c */) = cpu.esi;
    // 004a63c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a63c7:
    // 004a63c7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a63c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a63ca  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a63cc  e87780ffff             -call 0x49e448
    cpu.esp -= 4;
    sub_49e448(app, cpu);
    if (cpu.terminate) return;
    // 004a63d1  890d74d74d00           -mov dword ptr [0x4dd774], ecx
    app->getMemory<x86::reg32>(x86::reg32(5101428) /* 0x4dd774 */) = cpu.ecx;
    // 004a63d7  890d78d74d00           -mov dword ptr [0x4dd778], ecx
    app->getMemory<x86::reg32>(x86::reg32(5101432) /* 0x4dd778 */) = cpu.ecx;
    // 004a63dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63de  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a63e0  89357cd74d00           -mov dword ptr [0x4dd77c], esi
    app->getMemory<x86::reg32>(x86::reg32(5101436) /* 0x4dd77c */) = cpu.esi;
    // 004a63e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a63e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a63ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a63ec  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a63ee  7532                   -jne 0x4a6422
    if (!cpu.flags.zf)
    {
        goto L_0x004a6422;
    }
L_0x004a63f0:
    // 004a63f0  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a63f2  7403                   -je 0x4a63f7
    if (cpu.flags.zf)
    {
        goto L_0x004a63f7;
    }
    // 004a63f4  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
L_0x004a63f7:
    // 004a63f7  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a63f9  7403                   -je 0x4a63fe
    if (cpu.flags.zf)
    {
        goto L_0x004a63fe;
    }
    // 004a63fb  885302                 -mov byte ptr [ebx + 2], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x004a63fe:
    // 004a63fe  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a6400  7403                   -je 0x4a6405
    if (cpu.flags.zf)
    {
        goto L_0x004a6405;
    }
    // 004a6402  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x004a6405:
    // 004a6405  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a6407  7403                   -je 0x4a640c
    if (cpu.flags.zf)
    {
        goto L_0x004a640c;
    }
    // 004a6409  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
L_0x004a640c:
    // 004a640c  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a640e  7403                   -je 0x4a6413
    if (cpu.flags.zf)
    {
        goto L_0x004a6413;
    }
    // 004a6410  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
L_0x004a6413:
    // 004a6413  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a6415  7403                   -je 0x4a641a
    if (cpu.flags.zf)
    {
        goto L_0x004a641a;
    }
    // 004a6417  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x004a641a:
    // 004a641a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a641c  7508                   -jne 0x4a6426
    if (!cpu.flags.zf)
    {
        goto L_0x004a6426;
    }
    // 004a641e  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a6421  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6422:
    // 004a6422  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004a6424  ebca                   -jmp 0x4a63f0
    goto L_0x004a63f0;
L_0x004a6426:
    // 004a6426  885307                 -mov byte ptr [ebx + 7], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.dl;
    // 004a6429  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a642c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a6430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6430  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6431  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a6433  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a6435  7539                   -jne 0x4a6470
    if (!cpu.flags.zf)
    {
        goto L_0x004a6470;
    }
L_0x004a6437:
    // 004a6437  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a6439  7404                   -je 0x4a643f
    if (cpu.flags.zf)
    {
        goto L_0x004a643f;
    }
    // 004a643b  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
L_0x004a643f:
    // 004a643f  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a6441  7404                   -je 0x4a6447
    if (cpu.flags.zf)
    {
        goto L_0x004a6447;
    }
    // 004a6443  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x004a6447:
    // 004a6447  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a6449  7404                   -je 0x4a644f
    if (cpu.flags.zf)
    {
        goto L_0x004a644f;
    }
    // 004a644b  66895106               -mov word ptr [ecx + 6], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.dx;
L_0x004a644f:
    // 004a644f  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a6451  7404                   -je 0x4a6457
    if (cpu.flags.zf)
    {
        goto L_0x004a6457;
    }
    // 004a6453  66895108               -mov word ptr [ecx + 8], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.dx;
L_0x004a6457:
    // 004a6457  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a6459  7404                   -je 0x4a645f
    if (cpu.flags.zf)
    {
        goto L_0x004a645f;
    }
    // 004a645b  6689510a               -mov word ptr [ecx + 0xa], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.dx;
L_0x004a645f:
    // 004a645f  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a6461  7404                   -je 0x4a6467
    if (cpu.flags.zf)
    {
        goto L_0x004a6467;
    }
    // 004a6463  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
L_0x004a6467:
    // 004a6467  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a6469  750a                   -jne 0x4a6475
    if (!cpu.flags.zf)
    {
        goto L_0x004a6475;
    }
    // 004a646b  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a646e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a646f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6470:
    // 004a6470  668913                 -mov word ptr [ebx], dx
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.dx;
    // 004a6473  ebc2                   -jmp 0x4a6437
    goto L_0x004a6437;
L_0x004a6475:
    // 004a6475  6689510e               -mov word ptr [ecx + 0xe], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 004a6479  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a647c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a647d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a6480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6480  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6481  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6484  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a6487  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a648a  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004a648d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a6490  88cc                   -mov ah, cl
    cpu.ah = cpu.cl;
    // 004a6492  8a3424                 -mov dh, byte ptr [esp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp);
    // 004a6495  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a6497  755a                   -jne 0x4a64f3
    if (!cpu.flags.zf)
    {
        goto L_0x004a64f3;
    }
L_0x004a6499:
    // 004a6499  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a649b  7409                   -je 0x4a64a6
    if (cpu.flags.zf)
    {
        goto L_0x004a64a6;
    }
    // 004a649d  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
    // 004a64a0  886304                 -mov byte ptr [ebx + 4], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 004a64a3  887305                 -mov byte ptr [ebx + 5], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dh;
L_0x004a64a6:
    // 004a64a6  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a64a8  7409                   -je 0x4a64b3
    if (cpu.flags.zf)
    {
        goto L_0x004a64b3;
    }
    // 004a64aa  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004a64ad  886307                 -mov byte ptr [ebx + 7], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.ah;
    // 004a64b0  887308                 -mov byte ptr [ebx + 8], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.dh;
L_0x004a64b3:
    // 004a64b3  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a64b5  7409                   -je 0x4a64c0
    if (cpu.flags.zf)
    {
        goto L_0x004a64c0;
    }
    // 004a64b7  885309                 -mov byte ptr [ebx + 9], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = cpu.dl;
    // 004a64ba  88630a                 -mov byte ptr [ebx + 0xa], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ah;
    // 004a64bd  88730b                 -mov byte ptr [ebx + 0xb], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = cpu.dh;
L_0x004a64c0:
    // 004a64c0  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a64c2  7409                   -je 0x4a64cd
    if (cpu.flags.zf)
    {
        goto L_0x004a64cd;
    }
    // 004a64c4  88530c                 -mov byte ptr [ebx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004a64c7  88630d                 -mov byte ptr [ebx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004a64ca  88730e                 -mov byte ptr [ebx + 0xe], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.dh;
L_0x004a64cd:
    // 004a64cd  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a64cf  7409                   -je 0x4a64da
    if (cpu.flags.zf)
    {
        goto L_0x004a64da;
    }
    // 004a64d1  88530f                 -mov byte ptr [ebx + 0xf], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 004a64d4  886310                 -mov byte ptr [ebx + 0x10], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 004a64d7  887311                 -mov byte ptr [ebx + 0x11], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = cpu.dh;
L_0x004a64da:
    // 004a64da  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a64dc  7409                   -je 0x4a64e7
    if (cpu.flags.zf)
    {
        goto L_0x004a64e7;
    }
    // 004a64de  885312                 -mov byte ptr [ebx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004a64e1  886313                 -mov byte ptr [ebx + 0x13], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */) = cpu.ah;
    // 004a64e4  887314                 -mov byte ptr [ebx + 0x14], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.dh;
L_0x004a64e7:
    // 004a64e7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a64e9  7512                   -jne 0x4a64fd
    if (!cpu.flags.zf)
    {
        goto L_0x004a64fd;
    }
    // 004a64eb  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004a64ee  83c404                 +add esp, 4
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
    // 004a64f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a64f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a64f3:
    // 004a64f3  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004a64f5  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004a64f8  887302                 -mov byte ptr [ebx + 2], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dh;
    // 004a64fb  eb9c                   -jmp 0x4a6499
    goto L_0x004a6499;
L_0x004a64fd:
    // 004a64fd  885315                 -mov byte ptr [ebx + 0x15], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 004a6500  886316                 -mov byte ptr [ebx + 0x16], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = cpu.ah;
    // 004a6503  887317                 -mov byte ptr [ebx + 0x17], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */) = cpu.dh;
    // 004a6506  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004a6509  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a650c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a650d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a6510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6510  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6511  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a6513  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a6515  7533                   -jne 0x4a654a
    if (!cpu.flags.zf)
    {
        goto L_0x004a654a;
    }
L_0x004a6517:
    // 004a6517  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004a6519  7403                   -je 0x4a651e
    if (cpu.flags.zf)
    {
        goto L_0x004a651e;
    }
    // 004a651b  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004a651e:
    // 004a651e  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004a6520  7403                   -je 0x4a6525
    if (cpu.flags.zf)
    {
        goto L_0x004a6525;
    }
    // 004a6522  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x004a6525:
    // 004a6525  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004a6527  7403                   -je 0x4a652c
    if (cpu.flags.zf)
    {
        goto L_0x004a652c;
    }
    // 004a6529  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004a652c:
    // 004a652c  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004a652e  7403                   -je 0x4a6533
    if (cpu.flags.zf)
    {
        goto L_0x004a6533;
    }
    // 004a6530  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x004a6533:
    // 004a6533  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004a6535  7403                   -je 0x4a653a
    if (cpu.flags.zf)
    {
        goto L_0x004a653a;
    }
    // 004a6537  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x004a653a:
    // 004a653a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a653c  7403                   -je 0x4a6541
    if (cpu.flags.zf)
    {
        goto L_0x004a6541;
    }
    // 004a653e  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004a6541:
    // 004a6541  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a6543  7509                   -jne 0x4a654e
    if (!cpu.flags.zf)
    {
        goto L_0x004a654e;
    }
    // 004a6545  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a6548  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6549  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a654a:
    // 004a654a  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a654c  ebc9                   -jmp 0x4a6517
    goto L_0x004a6517;
L_0x004a654e:
    // 004a654e  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a6551  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a6554  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6555  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6556(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6556  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a6558  7503                   -jne 0x4a655d
    if (!cpu.flags.zf)
    {
        goto L_0x004a655d;
    }
    // 004a655a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a655c:
    // 004a655c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a655d:
    // 004a655d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a655f  74fb                   -je 0x4a655c
    if (cpu.flags.zf)
    {
        goto L_0x004a655c;
    }
    // 004a6561  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6562  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6564  e873010000             -call 0x4a66dc
    cpu.esp -= 4;
    sub_4a66dc(app, cpu);
    if (cpu.terminate) return;
    // 004a6569  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a656c  7507                   -jne 0x4a6575
    if (!cpu.flags.zf)
    {
        goto L_0x004a6575;
    }
    // 004a656e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a6573  eb31                   -jmp 0x4a65a6
    goto L_0x004a65a6;
L_0x004a6575:
    // 004a6575  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a657b  7507                   -jne 0x4a6584
    if (!cpu.flags.zf)
    {
        goto L_0x004a6584;
    }
    // 004a657d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a6582  eb22                   -jmp 0x4a65a6
    goto L_0x004a65a6;
L_0x004a6584:
    // 004a6584  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a658a  7507                   -jne 0x4a6593
    if (!cpu.flags.zf)
    {
        goto L_0x004a6593;
    }
    // 004a658c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004a6591  eb13                   -jmp 0x4a65a6
    goto L_0x004a65a6;
L_0x004a6593:
    // 004a6593  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6596  7605                   -jbe 0x4a659d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a659d;
    }
    // 004a6598  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x004a659d:
    // 004a659d  8b8221db4d00           -mov eax, dword ptr [edx + 0x4ddb21]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5102369) /* 0x4ddb21 */);
    // 004a65a3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x004a65a6:
    // 004a65a6  e805010000             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004a65ab  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a65b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6561(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a6561;
    // 004a6556  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a6558  7503                   -jne 0x4a655d
    if (!cpu.flags.zf)
    {
        goto L_0x004a655d;
    }
    // 004a655a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a655c:
    // 004a655c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a655d:
    // 004a655d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a655f  74fb                   -je 0x4a655c
    if (cpu.flags.zf)
    {
        goto L_0x004a655c;
    }
L_entry_0x004a6561:
    // 004a6561  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6562  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6564  e873010000             -call 0x4a66dc
    cpu.esp -= 4;
    sub_4a66dc(app, cpu);
    if (cpu.terminate) return;
    // 004a6569  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a656c  7507                   -jne 0x4a6575
    if (!cpu.flags.zf)
    {
        goto L_0x004a6575;
    }
    // 004a656e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a6573  eb31                   -jmp 0x4a65a6
    goto L_0x004a65a6;
L_0x004a6575:
    // 004a6575  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a657b  7507                   -jne 0x4a6584
    if (!cpu.flags.zf)
    {
        goto L_0x004a6584;
    }
    // 004a657d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a6582  eb22                   -jmp 0x4a65a6
    goto L_0x004a65a6;
L_0x004a6584:
    // 004a6584  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a658a  7507                   -jne 0x4a6593
    if (!cpu.flags.zf)
    {
        goto L_0x004a6593;
    }
    // 004a658c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004a6591  eb13                   -jmp 0x4a65a6
    goto L_0x004a65a6;
L_0x004a6593:
    // 004a6593  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6596  7605                   -jbe 0x4a659d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a659d;
    }
    // 004a6598  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x004a659d:
    // 004a659d  8b8221db4d00           -mov eax, dword ptr [edx + 0x4ddb21]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5102369) /* 0x4ddb21 */);
    // 004a65a3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x004a65a6:
    // 004a65a6  e805010000             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004a65ab  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a65b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a65b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a65b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a65b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a65b4  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a65bb  e8a1ffffff             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 004a65c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a65c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a65c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a65c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a65c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a65c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a65c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a65c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a65c8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a65c9  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004a65cb  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004a65cd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a65ce  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a65d1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a65d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a65d5  7405                   -je 0x4a65dc
    if (cpu.flags.zf)
    {
        goto L_0x004a65dc;
    }
    // 004a65d7  83f8d4                 +cmp eax, -0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-44 /*-0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a65da  7607                   -jbe 0x4a65e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a65e3;
    }
L_0x004a65dc:
    // 004a65dc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a65de  e9be000000             -jmp 0x4a66a1
    goto L_0x004a66a1;
L_0x004a65e3:
    // 004a65e3  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004a65e6  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 004a65e9  83fd10                 +cmp ebp, 0x10
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
    // 004a65ec  7305                   -jae 0x4a65f3
    if (!cpu.flags.cf)
    {
        goto L_0x004a65f3;
    }
    // 004a65ee  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x004a65f3:
    // 004a65f3  ff1574ed4d00           -call dword ptr [0x4ded74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107060) /* 0x4ded74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a65f9  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a65fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a65fd  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004a6600:
    // 004a6600  3b2d40db4d00           +cmp ebp, dword ptr [0x4ddb40]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102400) /* 0x4ddb40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6606  760c                   -jbe 0x4a6614
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6614;
    }
    // 004a6608  8b0d3cdb4d00           -mov ecx, dword ptr [0x4ddb3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102396) /* 0x4ddb3c */);
    // 004a660e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a6610  7510                   -jne 0x4a6622
    if (!cpu.flags.zf)
    {
        goto L_0x004a6622;
    }
    // 004a6612  eb02                   -jmp 0x4a6616
    goto L_0x004a6616;
L_0x004a6614:
    // 004a6614  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a6616:
    // 004a6616  890d40db4d00           -mov dword ptr [0x4ddb40], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102400) /* 0x4ddb40 */) = cpu.ecx;
    // 004a661c  8b0d38db4d00           -mov ecx, dword ptr [0x4ddb38]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */);
L_0x004a6622:
    // 004a6622  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a6624  743c                   -je 0x4a6662
    if (cpu.flags.zf)
    {
        goto L_0x004a6662;
    }
    // 004a6626  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004a6629  890d3cdb4d00           -mov dword ptr [0x4ddb3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102396) /* 0x4ddb3c */) = cpu.ecx;
    // 004a662f  39fe                   +cmp esi, edi
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
    // 004a6631  721c                   -jb 0x4a664f
    if (cpu.flags.cf)
    {
        goto L_0x004a664f;
    }
    // 004a6633  b838db4d00             -mov eax, 0x4ddb38
    cpu.eax = 5102392 /*0x4ddb38*/;
    // 004a6638  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a663a  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a6640  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a6642  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6644  e837dc0000             -call 0x4b4280
    cpu.esp -= 4;
    sub_4b4280(app, cpu);
    if (cpu.terminate) return;
    // 004a6649  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a664b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a664d  7542                   -jne 0x4a6691
    if (!cpu.flags.zf)
    {
        goto L_0x004a6691;
    }
L_0x004a664f:
    // 004a664f  3b3540db4d00           +cmp esi, dword ptr [0x4ddb40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102400) /* 0x4ddb40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6655  7606                   -jbe 0x4a665d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a665d;
    }
    // 004a6657  893540db4d00           -mov dword ptr [0x4ddb40], esi
    app->getMemory<x86::reg32>(x86::reg32(5102400) /* 0x4ddb40 */) = cpu.esi;
L_0x004a665d:
    // 004a665d  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6660  ebc0                   -jmp 0x4a6622
    goto L_0x004a6622;
L_0x004a6662:
    // 004a6662  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6666  750b                   -jne 0x4a6673
    if (!cpu.flags.zf)
    {
        goto L_0x004a6673;
    }
    // 004a6668  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a666a  e8f7de0000             -call 0x4b4566
    cpu.esp -= 4;
    sub_4b4566(app, cpu);
    if (cpu.terminate) return;
    // 004a666f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6671  7515                   -jne 0x4a6688
    if (!cpu.flags.zf)
    {
        goto L_0x004a6688;
    }
L_0x004a6673:
    // 004a6673  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6675  e847df0000             -call 0x4b45c1
    cpu.esp -= 4;
    sub_4b45c1(app, cpu);
    if (cpu.terminate) return;
    // 004a667a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a667c  7413                   -je 0x4a6691
    if (cpu.flags.zf)
    {
        goto L_0x004a6691;
    }
    // 004a667e  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 004a6680  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 004a6683  e978ffffff             -jmp 0x4a6600
    goto L_0x004a6600;
L_0x004a6688:
    // 004a6688  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 004a668c  e96fffffff             -jmp 0x4a6600
    goto L_0x004a6600;
L_0x004a6691:
    // 004a6691  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004a6693  882d60945b00           -mov byte ptr [0x5b9460], ch
    app->getMemory<x86::reg8>(x86::reg32(6001760) /* 0x5b9460 */) = cpu.ch;
    // 004a6699  ff157ced4d00           -call dword ptr [0x4ded7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a669f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004a66a1:
    // 004a66a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a66a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66a5  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a66a7  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a66a9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a66aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a66b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a66b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a66b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a66b3  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a66b9  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a66bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a66be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a66be  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 004a66c3  ebeb                   -jmp 0x4a66b0
    return sub_4a66b0(app, cpu);
}

/* align: skip  */
void Application::sub_4a66c5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a66c5  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004a66ca  ebe4                   -jmp 0x4a66b0
    return sub_4a66b0(app, cpu);
}

/* align: skip  */
void Application::sub_4a66cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a66cc  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004a66d1  e8daffffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004a66d6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a66db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a66dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a66dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a66dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a66df  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a66e5  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a66e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a66e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a66ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a66ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a66ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a66ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a66ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a66f0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a66f2  8b3d283f5600           -mov edi, dword ptr [0x563f28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5652264) /* 0x563f28 */);
    // 004a66f8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a66fa  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 004a6700  7420                   -je 0x4a6722
    if (cpu.flags.zf)
    {
        goto L_0x004a6722;
    }
    // 004a6702  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6705  7818                   -js 0x4a671f
    if (cpu.flags.sf)
    {
        goto L_0x004a671f;
    }
L_0x004a6707:
    // 004a6707  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a6709  80f9ff                 +cmp cl, 0xff
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
    // 004a670c  7411                   -je 0x4a671f
    if (cpu.flags.zf)
    {
        goto L_0x004a671f;
    }
    // 004a670e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a6711  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 004a6714  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a6717  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a671a  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a671d  79e8                   -jns 0x4a6707
    if (!cpu.flags.sf)
    {
        goto L_0x004a6707;
    }
L_0x004a671f:
    // 004a671f  83c501                 -add ebp, 1
    (cpu.ebp) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a6722:
    // 004a6722  83ed02                 +sub ebp, 2
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
    // 004a6725  7859                   -js 0x4a6780
    if (cpu.flags.sf)
    {
        goto L_0x004a6780;
    }
L_0x004a6727:
    // 004a6727  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a6729  80f9ff                 +cmp cl, 0xff
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
    // 004a672c  7428                   -je 0x4a6756
    if (cpu.flags.zf)
    {
        goto L_0x004a6756;
    }
    // 004a672e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a6731  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a6734  80f9ff                 +cmp cl, 0xff
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
    // 004a6737  7439                   -je 0x4a6772
    if (cpu.flags.zf)
    {
        goto L_0x004a6772;
    }
    // 004a6739  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a673c  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a6742  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a6745  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a6747  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
L_0x004a6749:
    // 004a6749  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a674c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a674f  83ed02                 +sub ebp, 2
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
    // 004a6752  79d3                   -jns 0x4a6727
    if (!cpu.flags.sf)
    {
        goto L_0x004a6727;
    }
    // 004a6754  eb2a                   -jmp 0x4a6780
    goto L_0x004a6780;
L_0x004a6756:
    // 004a6756  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a6759  80f9ff                 +cmp cl, 0xff
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
    // 004a675c  74eb                   -je 0x4a6749
    if (cpu.flags.zf)
    {
        goto L_0x004a6749;
    }
    // 004a675e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a6761  66895a02               -mov word ptr [edx + 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bx;
    // 004a6765  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a6768  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a676b  83ed02                 +sub ebp, 2
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
    // 004a676e  79b7                   -jns 0x4a6727
    if (!cpu.flags.sf)
    {
        goto L_0x004a6727;
    }
    // 004a6770  eb0e                   -jmp 0x4a6780
    goto L_0x004a6780;
L_0x004a6772:
    // 004a6772  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 004a6775  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a6778  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a677b  83ed02                 +sub ebp, 2
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
    // 004a677e  79a7                   -jns 0x4a6727
    if (!cpu.flags.sf)
    {
        goto L_0x004a6727;
    }
L_0x004a6780:
    // 004a6780  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a6783  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6786  7818                   -js 0x4a67a0
    if (cpu.flags.sf)
    {
        goto L_0x004a67a0;
    }
L_0x004a6788:
    // 004a6788  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a678a  80f9ff                 +cmp cl, 0xff
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
    // 004a678d  7411                   -je 0x4a67a0
    if (cpu.flags.zf)
    {
        goto L_0x004a67a0;
    }
    // 004a678f  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a6792  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 004a6795  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a6798  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a679b  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a679e  79e8                   -jns 0x4a6788
    if (!cpu.flags.sf)
    {
        goto L_0x004a6788;
    }
L_0x004a67a0:
    // 004a67a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a67a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a67a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a67a9  ff0d4adc4d00           +dec dword ptr [0x4ddc4a]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5102666) /* 0x4ddc4a */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a67af  753f                   -jne 0x4a67f0
    if (!cpu.flags.zf)
    {
        goto L_0x004a67f0;
    }
    // 004a67b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a67b3  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 004a67b5  7421                   -je 0x4a67d8
    if (cpu.flags.zf)
    {
        goto L_0x004a67d8;
    }
    // 004a67b7  83e27f                 +and edx, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/))));
    // 004a67ba  8a9244db4d00           -mov dl, byte ptr [edx + 0x4ddb44]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5102404) /* 0x4ddb44 */);
L_0x004a67c0:
    // 004a67c0  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a67c1  7c2d                   -jl 0x4a67f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a67f0;
    }
    // 004a67c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a67c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a67c5  ff14954edc4d00         -call dword ptr [edx*4 + 0x4ddc4e]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102670) /* 0x4ddc4e */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a67cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a67d0  ff054adc4d00           -inc dword ptr [0x4ddc4a]
    (app->getMemory<x86::reg32>(x86::reg32(5102666) /* 0x4ddc4a */))++;
    // 004a67d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a67d8:
    // 004a67d8  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 004a67db  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a67e1  7c05                   -jl 0x4a67e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a67e8;
    }
    // 004a67e3  ba84000000             -mov edx, 0x84
    cpu.edx = 132 /*0x84*/;
L_0x004a67e8:
    // 004a67e8  8a92c4db4d00           -mov dl, byte ptr [edx + 0x4ddbc4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5102532) /* 0x4ddbc4 */);
    // 004a67ee  ebd0                   -jmp 0x4a67c0
    goto L_0x004a67c0;
L_0x004a67f0:
    // 004a67f0  ff054adc4d00           -inc dword ptr [0x4ddc4a]
    (app->getMemory<x86::reg32>(x86::reg32(5102666) /* 0x4ddc4a */))++;
    // 004a67f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a67f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a67f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a67f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a67f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a67fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a67fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a67fd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a67ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6801  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004a6806  ba4edc4d00             -mov edx, 0x4ddc4e
    cpu.edx = 5102670 /*0x4ddc4e*/;
L_0x004a680b:
    // 004a680b  3902                   +cmp dword ptr [edx], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a680d  7412                   -je 0x4a6821
    if (cpu.flags.zf)
    {
        goto L_0x004a6821;
    }
    // 004a680f  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a6813  740a                   -je 0x4a681f
    if (cpu.flags.zf)
    {
        goto L_0x004a681f;
    }
    // 004a6815  83c204                 +add edx, 4
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
    // 004a6818  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a6819  75f0                   -jne 0x4a680b
    if (!cpu.flags.zf)
    {
        goto L_0x004a680b;
    }
    // 004a681b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a681c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a681d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a681e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a681f:
    // 004a681f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a6821:
    // 004a6821  b841000000             -mov eax, 0x41
    cpu.eax = 65 /*0x41*/;
    // 004a6826  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a6828:
    // 004a6828  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a682a  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 004a682c  740f                   -je 0x4a683d
    if (cpu.flags.zf)
    {
        goto L_0x004a683d;
    }
    // 004a682e  83fa7f                 +cmp edx, 0x7f
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
    // 004a6831  7f06                   -jg 0x4a6839
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6839;
    }
    // 004a6833  888244db4d00           -mov byte ptr [edx + 0x4ddb44], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5102404) /* 0x4ddb44 */) = cpu.al;
L_0x004a6839:
    // 004a6839  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a683a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a683b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a683c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a683d:
    // 004a683d  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 004a6840  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6846  7ff1                   -jg 0x4a6839
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6839;
    }
    // 004a6848  8882c4db4d00           -mov byte ptr [edx + 0x4ddbc4], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5102532) /* 0x4ddbc4 */) = cpu.al;
    // 004a684e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a684f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6850  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6851  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004a6852  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6854  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6855  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a6857  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a6859  ebcd                   -jmp 0x4a6828
    goto L_0x004a6828;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a6860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6860  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6861  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6862  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6864  42                     -inc edx
    (cpu.edx)++;
    // 004a6865  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6867  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a686a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a686c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a686e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a686f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6870  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a6874(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6874  83f820                 +cmp eax, 0x20
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
    // 004a6877  7c12                   -jl 0x4a688b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a688b;
    }
    // 004a6879  83f87f                 +cmp eax, 0x7f
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
    // 004a687c  7f0d                   -jg 0x4a688b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a688b;
    }
    // 004a687e  668b044514dd4d00       -mov ax, word ptr [eax*2 + 0x4ddd14]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5102868) /* 0x4ddd14 */ + cpu.eax * 2);
    // 004a6886  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x004a688b:
    // 004a688b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a688c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a688c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a688d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a688e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6890  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6892  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a6894  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004a6896  42                     -inc edx
    (cpu.edx)++;
    // 004a6897  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a6899  7416                   -je 0x4a68b1
    if (cpu.flags.zf)
    {
        goto L_0x004a68b1;
    }
    // 004a689b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a689c  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004a689e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a68a1  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a68a3  42                     -inc edx
    (cpu.edx)++;
    // 004a68a4  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a68a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68a7  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a68a9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a68ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a68b1:
    // 004a68b1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a68b6  e8b9ffffff             -call 0x4a6874
    cpu.esp -= 4;
    sub_4a6874(app, cpu);
    if (cpu.terminate) return;
    // 004a68bb  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a68bd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a68c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a68c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a68d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a68d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a68d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a68d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a68d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a68d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a68d6  8b354cb24d00           -mov esi, dword ptr [0x4db24c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004a68dc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a68de  39f0                   +cmp eax, esi
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
    // 004a68e0  7c4e                   -jl 0x4a6930
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6930;
    }
    // 004a68e2  3b0554b24d00           +cmp eax, dword ptr [0x4db254]
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
    // 004a68e8  7d46                   -jge 0x4a6930
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6930;
    }
    // 004a68ea  3b1550b24d00           +cmp edx, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a68f0  7c3e                   -jl 0x4a6930
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6930;
    }
    // 004a68f2  3b1558b24d00           +cmp edx, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a68f8  7d36                   -jge 0x4a6930
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6930;
    }
    // 004a68fa  a16cb24d00             -mov eax, dword ptr [0x4db26c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004a68ff  8b3570b24d00           -mov esi, dword ptr [0x4db270]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004a6905  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004a6908  8b3c9e                 -mov edi, dword ptr [esi + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004a690b  a160b24d00             -mov eax, dword ptr [0x4db260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 004a6910  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a6912  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6914  a05cb24d00             -mov al, byte ptr [0x4db25c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004a6919  3c0f                   +cmp al, 0xf
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
    // 004a691b  731a                   -jae 0x4a6937
    if (!cpu.flags.cf)
    {
        goto L_0x004a6937;
    }
    // 004a691d  3c04                   +cmp al, 4
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
    // 004a691f  720f                   -jb 0x4a6930
    if (cpu.flags.cf)
    {
        goto L_0x004a6930;
    }
    // 004a6921  772f                   -ja 0x4a6952
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a6952;
    }
    // 004a6923  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004a6926  7432                   -je 0x4a695a
    if (cpu.flags.zf)
    {
        goto L_0x004a695a;
    }
    // 004a6928  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a692a  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 004a692d  83e10f                 +and ecx, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/))));
L_0x004a6930:
    // 004a6930  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6932  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6933  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6934  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6935  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6936  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6937:
    // 004a6937  7608                   -jbe 0x4a6941
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6941;
    }
    // 004a6939  3c18                   +cmp al, 0x18
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
    // 004a693b  730b                   -jae 0x4a6948
    if (!cpu.flags.cf)
    {
        goto L_0x004a6948;
    }
    // 004a693d  3c10                   +cmp al, 0x10
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
    // 004a693f  75ef                   -jne 0x4a6930
    if (!cpu.flags.zf)
    {
        goto L_0x004a6930;
    }
L_0x004a6941:
    // 004a6941  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a6943  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a6946  ebe8                   -jmp 0x4a6930
    goto L_0x004a6930;
L_0x004a6948:
    // 004a6948  761c                   -jbe 0x4a6966
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6966;
    }
    // 004a694a  3c20                   +cmp al, 0x20
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
    // 004a694c  75e2                   -jne 0x4a6930
    if (!cpu.flags.zf)
    {
        goto L_0x004a6930;
    }
    // 004a694e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a6950  ebde                   -jmp 0x4a6930
    goto L_0x004a6930;
L_0x004a6952:
    // 004a6952  3c08                   +cmp al, 8
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
    // 004a6954  75da                   -jne 0x4a6930
    if (!cpu.flags.zf)
    {
        goto L_0x004a6930;
    }
    // 004a6956  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a6958  ebd6                   -jmp 0x4a6930
    goto L_0x004a6930;
L_0x004a695a:
    // 004a695a  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a695c  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a695f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6961  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6962  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6963  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6964  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6965  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6966:
    // 004a6966  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004a696b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a696d  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004a6971  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a6973  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a697a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a697c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a697e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a6980  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6981  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6982  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6983  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6984  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a6988(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6988  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6989  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a698a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004a6990  7423                   -je 0x4a69b5
    if (cpu.flags.zf)
    {
        goto L_0x004a69b5;
    }
    // 004a6992  83fb01                 +cmp ebx, 1
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
    // 004a6995  7c1e                   -jl 0x4a69b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a69b5;
    }
    // 004a6997  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a699a  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a699d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a699f  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 004a69a5  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 004a69a7  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a69aa  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a69ac  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a69af  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a69b2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x004a69b5:
    // 004a69b5  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a69b8  7821                   -js 0x4a69db
    if (cpu.flags.sf)
    {
        goto L_0x004a69db;
    }
L_0x004a69ba:
    // 004a69ba  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a69bc  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a69bf  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a69c1  81e1c0ffc0ff           -and ecx, 0xffc0ffc0
    cpu.ecx &= x86::reg32(x86::sreg32(4290838464 /*0xffc0ffc0*/));
    // 004a69c7  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 004a69c9  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004a69cf  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a69d1  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a69d4  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004a69d6  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a69d9  79df                   -jns 0x4a69ba
    if (!cpu.flags.sf)
    {
        goto L_0x004a69ba;
    }
L_0x004a69db:
    // 004a69db  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a69de  7820                   -js 0x4a6a00
    if (cpu.flags.sf)
    {
        goto L_0x004a6a00;
    }
L_0x004a69e0:
    // 004a69e0  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a69e3  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a69e6  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a69e8  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 004a69ee  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 004a69f0  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a69f3  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a69f5  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a69f8  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a69fb  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a69fe  79e0                   -jns 0x4a69e0
    if (!cpu.flags.sf)
    {
        goto L_0x004a69e0;
    }
L_0x004a6a00:
    // 004a6a00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6a03(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6a03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6a04  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6a05  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004a6a0b  7423                   -je 0x4a6a30
    if (cpu.flags.zf)
    {
        goto L_0x004a6a30;
    }
    // 004a6a0d  83fb01                 +cmp ebx, 1
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
    // 004a6a10  7c1e                   -jl 0x4a6a30
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6a30;
    }
    // 004a6a12  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a6a15  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a6a18  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a6a1a  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 004a6a20  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6a22  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a6a25  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a6a27  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a6a2a  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a6a2d  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x004a6a30:
    // 004a6a30  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6a33  7821                   -js 0x4a6a56
    if (cpu.flags.sf)
    {
        goto L_0x004a6a56;
    }
L_0x004a6a35:
    // 004a6a35  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6a37  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a6a3a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a6a3c  81e1e07fe07f           -and ecx, 0x7fe07fe0
    cpu.ecx &= x86::reg32(x86::sreg32(2145419232 /*0x7fe07fe0*/));
    // 004a6a42  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6a44  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004a6a4a  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a6a4c  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6a4f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004a6a51  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a6a54  79df                   -jns 0x4a6a35
    if (!cpu.flags.sf)
    {
        goto L_0x004a6a35;
    }
L_0x004a6a56:
    // 004a6a56  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6a59  7820                   -js 0x4a6a7b
    if (cpu.flags.sf)
    {
        goto L_0x004a6a7b;
    }
L_0x004a6a5b:
    // 004a6a5b  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a6a5e  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a6a61  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a6a63  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 004a6a69  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6a6b  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a6a6e  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a6a70  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6a73  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a6a76  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a6a79  79e0                   -jns 0x4a6a5b
    if (!cpu.flags.sf)
    {
        goto L_0x004a6a5b;
    }
L_0x004a6a7b:
    // 004a6a7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6a7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6a7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6a7f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6a80  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6a81  8b3d44d04d00           -mov edi, dword ptr [0x4dd044]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099588) /* 0x4dd044 */);
    // 004a6a87  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a6a89:
    // 004a6a89  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a6a8b  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6a8e  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a6a91  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a6a94  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 004a6a97  8972fc                 -mov dword ptr [edx - 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004a6a9a  7fed                   -jg 0x4a6a89
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a6a89;
    }
    // 004a6a9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6a9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6aa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6aa1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6aa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6aa3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6aa4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a6aa6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a6aa8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a6aaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6aac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a6aae  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6ab0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6ab2  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6ab5  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 004a6abb  754e                   -jne 0x4a6b0b
    if (!cpu.flags.zf)
    {
        goto L_0x004a6b0b;
    }
    // 004a6abd  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6ac0  7849                   -js 0x4a6b0b
    if (cpu.flags.sf)
    {
        goto L_0x004a6b0b;
    }
    // 004a6ac2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a6ac5  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6ac7  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a6aca  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
L_0x004a6acd:
    // 004a6acd  8b04453aef5600         -mov eax, dword ptr [eax*2 + 0x56ef3a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697338) /* 0x56ef3a */ + cpu.eax * 2);
    // 004a6ad4  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a6ad7  8b0c4d3aef5600         -mov ecx, dword ptr [ecx*2 + 0x56ef3a]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697338) /* 0x56ef3a */ + cpu.ecx * 2);
    // 004a6ade  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a6ae1  668b045d3cef5600       -mov ax, word ptr [ebx*2 + 0x56ef3c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.ebx * 2);
    // 004a6ae9  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6aeb  668b0c553cef5600       -mov cx, word ptr [edx*2 + 0x56ef3c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.edx * 2);
    // 004a6af3  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a6af6  8947f8                 -mov dword ptr [edi - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004a6af9  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a6afc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a6afe  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a6b00  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a6b03  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6b06  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a6b09  79c2                   -jns 0x4a6acd
    if (!cpu.flags.sf)
    {
        goto L_0x004a6acd;
    }
L_0x004a6b0b:
    // 004a6b0b  83c503                 +add ebp, 3
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6b0e  7818                   -js 0x4a6b28
    if (cpu.flags.sf)
    {
        goto L_0x004a6b28;
    }
L_0x004a6b10:
    // 004a6b10  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6b12  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a6b15  668b04553cef5600       -mov ax, word ptr [edx*2 + 0x56ef3c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.edx * 2);
    // 004a6b1d  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a6b20  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a6b23  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6b26  79e8                   -jns 0x4a6b10
    if (!cpu.flags.sf)
    {
        goto L_0x004a6b10;
    }
L_0x004a6b28:
    // 004a6b28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6b2d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6b2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6b2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6b2f  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a6b32  83eb04                 +sub ebx, 4
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
    // 004a6b35  783f                   -js 0x4a6b76
    if (cpu.flags.sf)
    {
        goto L_0x004a6b76;
    }
L_0x004a6b37:
    // 004a6b37  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a6b39  8b4e03                 -mov ecx, dword ptr [esi + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a6b3c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a6b3e  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a6b40  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a6b45  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a6b4b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a6b4d  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a6b50  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004a6b53  8b4e09                 -mov ecx, dword ptr [esi + 9]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 004a6b56  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a6b58  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a6b5a  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a6b5f  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a6b65  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a6b68  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a6b6b  83eb04                 +sub ebx, 4
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
    // 004a6b6e  8d760c                 -lea esi, [esi + 0xc]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a6b71  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a6b74  79c1                   -jns 0x4a6b37
    if (!cpu.flags.sf)
    {
        goto L_0x004a6b37;
    }
L_0x004a6b76:
    // 004a6b76  83c303                 +add ebx, 3
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6b79  7816                   -js 0x4a6b91
    if (cpu.flags.sf)
    {
        goto L_0x004a6b91;
    }
L_0x004a6b7b:
    // 004a6b7b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a6b7d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a6b7f  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004a6b84  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a6b86  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6b89  8d7603                 -lea esi, [esi + 3]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a6b8c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a6b8f  79ea                   -jns 0x4a6b7b
    if (!cpu.flags.sf)
    {
        goto L_0x004a6b7b;
    }
L_0x004a6b91:
    // 004a6b91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6b93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6b94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6b94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6b95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6b96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6b97  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6b9a  782f                   -js 0x4a6bcb
    if (cpu.flags.sf)
    {
        goto L_0x004a6bcb;
    }
L_0x004a6b9c:
    // 004a6b9c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a6b9e  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a6ba0  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 004a6ba6  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 004a6ba9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a6bab  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 004a6bb1  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a6bb3  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004a6bb9  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 004a6bbc  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6bbe  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004a6bc0  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6bc3  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a6bc6  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a6bc9  79d1                   -jns 0x4a6b9c
    if (!cpu.flags.sf)
    {
        goto L_0x004a6b9c;
    }
L_0x004a6bcb:
    // 004a6bcb  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6bce  7831                   -js 0x4a6c01
    if (cpu.flags.sf)
    {
        goto L_0x004a6c01;
    }
L_0x004a6bd0:
    // 004a6bd0  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a6bd3  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a6bd5  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 004a6bdb  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 004a6bde  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a6be0  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 004a6be6  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a6be8  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004a6bee  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 004a6bf1  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6bf3  66893a                 -mov word ptr [edx], di
    app->getMemory<x86::reg16>(cpu.edx) = cpu.di;
    // 004a6bf6  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6bf9  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a6bfc  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a6bff  79cf                   -jns 0x4a6bd0
    if (!cpu.flags.sf)
    {
        goto L_0x004a6bd0;
    }
L_0x004a6c01:
    // 004a6c01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6c04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6c05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6c05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6c06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6c07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6c08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6c09  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a6c0b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a6c0d  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a6c0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6c11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a6c13  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6c15  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6c18  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 004a6c1e  754e                   -jne 0x4a6c6e
    if (!cpu.flags.zf)
    {
        goto L_0x004a6c6e;
    }
    // 004a6c20  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6c23  7849                   -js 0x4a6c6e
    if (cpu.flags.sf)
    {
        goto L_0x004a6c6e;
    }
    // 004a6c25  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6c27  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
L_0x004a6c2a:
    // 004a6c2a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6c2c  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 004a6c2f  8b144d3aef5600         -mov edx, dword ptr [ecx*2 + 0x56ef3a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697338) /* 0x56ef3a */ + cpu.ecx * 2);
    // 004a6c36  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a6c39  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a6c3b  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 004a6c3e  8b0c4d3aef5600         -mov ecx, dword ptr [ecx*2 + 0x56ef3a]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697338) /* 0x56ef3a */ + cpu.ecx * 2);
    // 004a6c45  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a6c48  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a6c4b  668b14453cef5600       -mov dx, word ptr [eax*2 + 0x56ef3c]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.eax * 2);
    // 004a6c53  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6c55  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a6c58  668b0c5d3cef5600       -mov cx, word ptr [ebx*2 + 0x56ef3c]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.ebx * 2);
    // 004a6c60  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a6c63  8957f8                 -mov dword ptr [edi - 8], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004a6c66  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a6c69  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6c6c  79bc                   -jns 0x4a6c2a
    if (!cpu.flags.sf)
    {
        goto L_0x004a6c2a;
    }
L_0x004a6c6e:
    // 004a6c6e  83c502                 +add ebp, 2
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
    // 004a6c71  7827                   -js 0x4a6c9a
    if (cpu.flags.sf)
    {
        goto L_0x004a6c9a;
    }
L_0x004a6c73:
    // 004a6c73  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6c75  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 004a6c78  8b144d3aef5600         -mov edx, dword ptr [ecx*2 + 0x56ef3a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697338) /* 0x56ef3a */ + cpu.ecx * 2);
    // 004a6c7f  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a6c82  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a6c85  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a6c88  668b14453cef5600       -mov dx, word ptr [eax*2 + 0x56ef3c]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.eax * 2);
    // 004a6c90  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6c92  8957fc                 -mov dword ptr [edi - 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a6c95  83ed02                 +sub ebp, 2
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
    // 004a6c98  79d9                   -jns 0x4a6c73
    if (!cpu.flags.sf)
    {
        goto L_0x004a6c73;
    }
L_0x004a6c9a:
    // 004a6c9a  83c501                 +add ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6c9d  780e                   -js 0x4a6cad
    if (cpu.flags.sf)
    {
        goto L_0x004a6cad;
    }
    // 004a6c9f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a6ca2  668b14453cef5600       -mov dx, word ptr [eax*2 + 0x56ef3c]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */ + cpu.eax * 2);
    // 004a6caa  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
L_0x004a6cad:
    // 004a6cad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6cae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6caf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6cb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6cb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6cb2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6cb2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6cb3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6cb4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6cb5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a6cb8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6cba  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a6cbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a6cbd  2eff15f4644c00         -call dword ptr cs:[0x4c64f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006580) /* 0x4c64f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6cc4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6cc6  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004a6cca  2d6c070000             -sub eax, 0x76c
    (cpu.eax) -= x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004a6ccf  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a6cd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6cd4  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004a6cd9  48                     -dec eax
    (cpu.eax)--;
    // 004a6cda  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a6cdd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6cdf  668b442406             -mov ax, word ptr [esp + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004a6ce4  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a6ce7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6ce9  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a6cee  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a6cf1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6cf3  668b44240a             -mov ax, word ptr [esp + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(10) /* 0xa */);
    // 004a6cf8  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a6cfb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6cfd  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a6d02  c74320ffffffff         -mov dword ptr [ebx + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 004a6d09  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a6d0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6d0d  668b44240e             -mov ax, word ptr [esp + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 004a6d12  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a6d15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6d18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6d19(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6d19  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6d1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6d1b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6d1c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6d1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6d1e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6d1f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6d22  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a6d24  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004a6d29  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a6d2c  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a6d2f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6d32  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a6d34  b9ac1f4d00             -mov ecx, 0x4d1fac
    cpu.ecx = 5054380 /*0x4d1fac*/;
    // 004a6d39  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a6d3c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a6d3e  81fea17efbf4           +cmp esi, 0xf4fb7ea1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4110122657 /*0xf4fb7ea1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6d44  7d0a                   -jge 0x4a6d50
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6d50;
    }
L_0x004a6d46:
    // 004a6d46  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a6d4b  e94e010000             -jmp 0x4a6e9e
    goto L_0x004a6e9e;
L_0x004a6d50:
    // 004a6d50  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a6d53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6d55  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6d58  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a6d5a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a6d5c:
    // 004a6d5c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a6d5e  7d06                   -jge 0x4a6d66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6d66;
    }
    // 004a6d60  4e                     -dec esi
    (cpu.esi)--;
    // 004a6d61  83c70c                 +add edi, 0xc
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6d64  ebf6                   -jmp 0x4a6d5c
    goto L_0x004a6d5c;
L_0x004a6d66:
    // 004a6d66  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a6d68  7cdc                   -jl 0x4a6d46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6d46;
    }
    // 004a6d6a  8d866c070000           -lea eax, [esi + 0x76c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1900) /* 0x76c */);
    // 004a6d70  e84fd80000             -call 0x4b45c4
    cpu.esp -= 4;
    sub_4b45c4(app, cpu);
    if (cpu.terminate) return;
    // 004a6d75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6d77  7405                   -je 0x4a6d7e
    if (cpu.flags.zf)
    {
        goto L_0x004a6d7e;
    }
    // 004a6d79  b9c61f4d00             -mov ecx, 0x4d1fc6
    cpu.ecx = 5054406 /*0x4d1fc6*/;
L_0x004a6d7e:
    // 004a6d7e  8d5603                 -lea edx, [esi + 3]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004a6d81  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6d83  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6d86  c1e202                 +shl edx, 2
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
    // 004a6d89  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a6d8b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004a6d8e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6d90  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6d92  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a6d95  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a6d97  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a6d9a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a6d9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6d9e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a6da1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a6da3  8d5663                 -lea edx, [esi + 0x63]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(99) /* 0x63 */);
    // 004a6da6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a6da8  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004a6dad  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a6db0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6db2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6db5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a6db7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a6dba  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6dbc  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a6dbf  8d962b010000           -lea edx, [esi + 0x12b]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(299) /* 0x12b */);
    // 004a6dc5  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 004a6dca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6dcc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a6dcf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a6dd1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a6dd4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6dd6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6dd8  0fbf0441               -movsx eax, word ptr [ecx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2)));
    // 004a6ddc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a6dde  03450c                 -add eax, dword ptr [ebp + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004a6de1  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a6de4  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a6de7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6de9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a6dec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6dee  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a6df1  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004a6df4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6df6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6df8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004a6dfb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6dfd  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a6e00  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a6e03  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a6e05:
    // 004a6e05  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a6e07  7d09                   -jge 0x4a6e12
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6e12;
    }
    // 004a6e09  4f                     -dec edi
    (cpu.edi)--;
    // 004a6e0a  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6e10  ebf3                   -jmp 0x4a6e05
    goto L_0x004a6e05;
L_0x004a6e12:
    // 004a6e12  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a6e14  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a6e16  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6e18  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a6e1a  e8dedb0000             -call 0x4b49fd
    cpu.esp -= 4;
    sub_4b49fd(app, cpu);
    if (cpu.terminate) return;
    // 004a6e1f  e858de0000             -call 0x4b4c7c
    cpu.esp -= 4;
    sub_4b4c7c(app, cpu);
    if (cpu.terminate) return;
    // 004a6e24  8b1d06054e00           -mov ebx, dword ptr [0x4e0506]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113094) /* 0x4e0506 */);
    // 004a6e2a  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004a6e2d  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a6e2f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a6e31  7d07                   -jge 0x4a6e3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6e3a;
    }
    // 004a6e33  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a6e35  e8e4d80000             -call 0x4b471e
    cpu.esp -= 4;
    sub_4b471e(app, cpu);
    if (cpu.terminate) return;
L_0x004a6e3a:
    // 004a6e3a  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6e3e  7e06                   -jle 0x4a6e46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6e46;
    }
    // 004a6e40  2b350e054e00           -sub esi, dword ptr [0x4e050e]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */)));
L_0x004a6e46:
    // 004a6e46  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a6e48  7d09                   -jge 0x4a6e53
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6e53;
    }
    // 004a6e4a  4f                     -dec edi
    (cpu.edi)--;
    // 004a6e4b  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6e51  ebf3                   -jmp 0x4a6e46
    goto L_0x004a6e46;
L_0x004a6e53:
    // 004a6e53  81ffde630000           +cmp edi, 0x63de
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25566 /*0x63de*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6e59  0f8ce7feffff           -jl 0x4a6d46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6d46;
    }
    // 004a6e5f  751d                   -jne 0x4a6e7e
    if (!cpu.flags.zf)
    {
        goto L_0x004a6e7e;
    }
    // 004a6e61  8b1d06054e00           -mov ebx, dword ptr [0x4e0506]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113094) /* 0x4e0506 */);
    // 004a6e67  81ee80510100           -sub esi, 0x15180
    (cpu.esi) -= x86::reg32(x86::sreg32(86400 /*0x15180*/));
    // 004a6e6d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a6e6f  0f8ed1feffff           -jle 0x4a6d46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6d46;
    }
    // 004a6e75  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a6e77  7d23                   -jge 0x4a6e9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a6e9c;
    }
    // 004a6e79  e9c8feffff             -jmp 0x4a6d46
    goto L_0x004a6d46;
L_0x004a6e7e:
    // 004a6e7e  8d87219cffff           -lea eax, [edi - 0x63df]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-25567) /* -0x63df */);
    // 004a6e84  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a6e86  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004a6e89  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6e8b  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 004a6e8e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a6e90  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 004a6e93  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a6e95  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004a6e98  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6e9a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004a6e9c:
    // 004a6e9c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a6e9e:
    // 004a6e9e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a6ea1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ea2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ea3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ea4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ea5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ea6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ea7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6ea8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6ea8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6ea9  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004a6eaa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6eab  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a6ead  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a6eb0  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004a6eb1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6eb2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6eb4  3500002000             -xor eax, 0x200000
    cpu.eax ^= x86::reg32(x86::sreg32(2097152 /*0x200000*/));
    // 004a6eb9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a6eba  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ebb  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004a6ebc  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ebd  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6ebf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a6ec1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ec2  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ec3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ec4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6ec5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6ec5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6ec6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6ec7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6ec8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6ec9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6eca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a6ecb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6ecd  0fa2                   -cpuid 
    cpu.cpuid();
    // 004a6ecf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ed0  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a6ed2  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a6ed5  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a6ed8  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a6edb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6edc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6edd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ede  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6edf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6ee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6ee1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6ee1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6ee3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6ee5  9e                     -sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a6ee6  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a6eeb  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004a6ef0  f6f3                   -div bl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.bl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
    // 004a6ef2  9f                     -lahf 
    cpu.ah = 0x02 | (cpu.flags.lo & 0xD7);
    // 004a6ef3  80fc02                 +cmp ah, 2
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6ef6  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a6efb  7505                   -jne 0x4a6f02
    if (!cpu.flags.zf)
    {
        goto L_0x004a6f02;
    }
    // 004a6efd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a6f02:
    // 004a6f02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6f05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6f05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6f06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6f07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6f08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6f09  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a6f0b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a6f0d  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004a6f12  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a6f14  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a6f16  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6f17  e30b                   -jecxz 0x4a6f24
    if (cpu.ecx == 0)
    {
        goto L_0x004a6f24;
    }
    // 004a6f19  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a6f1b  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004a6f1d  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004a6f1f  7503                   -jne 0x4a6f24
    if (!cpu.flags.zf)
    {
        goto L_0x004a6f24;
    }
    // 004a6f21  4f                     -dec edi
    (cpu.edi)--;
    // 004a6f22  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004a6f26;
L_0x004a6f24:
    // 004a6f24  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004a6f26:
    // 004a6f26  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a6f27  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a6f29:
    // 004a6f29  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a6f2b  740d                   -je 0x4a6f3a
    if (cpu.flags.zf)
    {
        goto L_0x004a6f3a;
    }
    // 004a6f2d  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6f2f  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004a6f31  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a6f33  7405                   -je 0x4a6f3a
    if (cpu.flags.zf)
    {
        goto L_0x004a6f3a;
    }
    // 004a6f35  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a6f36  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a6f37  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a6f38  ebef                   -jmp 0x4a6f29
    goto L_0x004a6f29;
L_0x004a6f3a:
    // 004a6f3a  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004a6f3d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a6f3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a6f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6f50  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
