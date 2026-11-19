#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_4c0cdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0cdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0cdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0cde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0cdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0ce0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0ce2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c0ce4  e83b17fcff             -call 0x482424
    cpu.esp -= 4;
    sub_482424(app, cpu);
    if (cpu.terminate) return;
    // 004c0ce9  8b157cab4d00           -mov edx, dword ptr [0x4dab7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004c0cef  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0cf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c0cf3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004c0cf6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0cf8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004c0cfa  8b3decd64d00           -mov edi, dword ptr [0x4dd6ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */);
    // 004c0d00  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c0d02  8b35f0d64d00           -mov esi, dword ptr [0x4dd6f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5101296) /* 0x4dd6f0 */);
    // 004c0d08  e8eb64fcff             -call 0x4871f8
    cpu.esp -= 4;
    sub_4871f8(app, cpu);
    if (cpu.terminate) return;
    // 004c0d0d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0d0f  e8c45afcff             -call 0x4867d8
    cpu.esp -= 4;
    sub_4867d8(app, cpu);
    if (cpu.terminate) return;
    // 004c0d14  893decd64d00           -mov dword ptr [0x4dd6ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */) = cpu.edi;
    // 004c0d1a  8935f0d64d00           -mov dword ptr [0x4dd6f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5101296) /* 0x4dd6f0 */) = cpu.esi;
    // 004c0d20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c0d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0d31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0d32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c0d33  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c0d36  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c0d39  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c0d3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c0d3c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0d3e  e83dfeffff             -call 0x4c0b80
    cpu.esp -= 4;
    sub_4c0b80(app, cpu);
    if (cpu.terminate) return;
    // 004c0d43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0d46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c0d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0d50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0d51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0d52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0d54  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c0d56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0d58  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c0d5a  e881cafdff             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 004c0d5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c0d61  7f59                   -jg 0x4c0dbc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c0dbc;
    }
    // 004c0d63  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c0d65  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c0d67  e874cafdff             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 004c0d6c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0d6e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x004c0d70:
    // 004c0d70  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c0d72  81fa00010000           +cmp edx, 0x100
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
    // 004c0d78  7e07                   -jle 0x4c0d81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0d81;
    }
    // 004c0d7a  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 004c0d7f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x004c0d81:
    // 004c0d81  3d80000000             +cmp eax, 0x80
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
    // 004c0d86  7e45                   -jle 0x4c0dcd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0dcd;
    }
    // 004c0d88  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c0d8a  7e3d                   -jle 0x4c0dc9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0dc9;
    }
L_0x004c0d8c:
    // 004c0d8c  c0e407                 +shl ah, 7
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
    // 004c0d8f  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c0d91  00e4                   +add ah, ah
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
    // 004c0d93  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004c0d95  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0d97  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c0d9c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0d9e  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
L_0x004c0da5:
    // 004c0da5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0da7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c0dab  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 004c0dae  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004c0db0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c0db2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c0db4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004c0db7  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004c0db9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0dba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0dbb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c0dbc:
    // 004c0dbc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c0dbe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c0dc0  e81bcafdff             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 004c0dc5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c0dc7  eba7                   -jmp 0x4c0d70
    goto L_0x004c0d70;
L_0x004c0dc9:
    // 004c0dc9  f7db                   +neg ebx
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
    // 004c0dcb  ebbf                   -jmp 0x4c0d8c
    goto L_0x004c0d8c;
L_0x004c0dcd:
    // 004c0dcd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c0dcf  7e23                   -jle 0x4c0df4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c0df4;
    }
L_0x004c0dd1:
    // 004c0dd1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004c0dd3  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004c0dd9  c0e507                 +shl ch, 7
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
    // 004c0ddc  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c0dde  00ed                   +add ch, ch
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
    // 004c0de0  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004c0de2  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0de4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c0de9  29c8                   +sub eax, ecx
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
    // 004c0deb  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 004c0df2  ebb1                   -jmp 0x4c0da5
    goto L_0x004c0da5;
L_0x004c0df4:
    // 004c0df4  f7d9                   +neg ecx
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
    // 004c0df6  ebd9                   -jmp 0x4c0dd1
    goto L_0x004c0dd1;
}

/* align: skip  */
void Application::sub_4c0df8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c0dfa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c0dfa  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004c0dfc  750b                   -jne 0x4c0e09
    if (!cpu.flags.zf)
    {
        goto L_0x004c0e09;
    }
    // 004c0dfe  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0e00  7505                   -jne 0x4c0e07
    if (!cpu.flags.zf)
    {
        goto L_0x004c0e07;
    }
    // 004c0e02  e94a320000             -jmp 0x4c4051
    return sub_4c4051(app, cpu);
L_0x004c0e07:
    // 004c0e07  d1d9                   -rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c0e09:
    // 004c0e09  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c0e0b  7507                   -jne 0x4c0e14
    if (!cpu.flags.zf)
    {
        goto L_0x004c0e14;
    }
    // 004c0e0d  01d2                   +add edx, edx
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
    // 004c0e0f  7501                   -jne 0x4c0e12
    if (!cpu.flags.zf)
    {
        goto L_0x004c0e12;
    }
    // 004c0e11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c0e12:
    // 004c0e12  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c0e14:
    // 004c0e14  803d3db54d0000         +cmp byte ptr [0x4db53d], 0
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
    // 004c0e1b  7430                   -je 0x4c0e4d
    if (cpu.flags.zf)
    {
        goto L_0x004c0e4d;
    }
    // 004c0e1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c0e1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c0e1f  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004c0e22  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c0e23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0e24  f605a0014e0001         +test byte ptr [0x4e01a0], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5112224) /* 0x4e01a0 */) & 1 /*0x1*/));
    // 004c0e2b  7407                   -je 0x4c0e34
    if (cpu.flags.zf)
    {
        goto L_0x004c0e34;
    }
    // 004c0e2d  e89a0b0000             -call 0x4c19cc
    cpu.esp -= 4;
    sub_4c19cc(app, cpu);
    if (cpu.terminate) return;
    // 004c0e32  eb06                   -jmp 0x4c0e3a
    goto L_0x004c0e3a;
L_0x004c0e34:
    // 004c0e34  dc3424                 -fdiv qword ptr [esp]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<double>(cpu.esp));
    // 004c0e37  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004c0e3a:
    // 004c0e3a  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c0e3d  9b                     -wait 
    /*nothing*/;
    // 004c0e3e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0e3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0e40  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c0e46  7504                   -jne 0x4c0e4c
    if (!cpu.flags.zf)
    {
        goto L_0x004c0e4c;
    }
    // 004c0e48  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c0e4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c0e4c:
    // 004c0e4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c0e4d:
    // 004c0e4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c0e4e  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c0e50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0e51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0e52  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c0e54  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c0e56  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 004c0e59  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 004c0e5c  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c0e62  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c0e68  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c0e6b  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c0e6e  6601cf                 -add di, cx
    (cpu.di) += x86::reg16(x86::sreg16(cpu.cx));
    // 004c0e71  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c0e74  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c0e77  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c0e7d  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c0e83  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 004c0e86  7408                   -je 0x4c0e90
    if (cpu.flags.zf)
    {
        goto L_0x004c0e90;
    }
    // 004c0e88  81ca00001000           +or edx, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 004c0e8e  eb0e                   -jmp 0x4c0e9e
    goto L_0x004c0e9e;
L_0x004c0e90:
    // 004c0e90  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0e92  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c0e94  664f                   -dec di
    (cpu.di)--;
    // 004c0e96  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 004c0e9c  74f2                   -je 0x4c0e90
    if (cpu.flags.zf)
    {
        goto L_0x004c0e90;
    }
L_0x004c0e9e:
    // 004c0e9e  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 004c0ea1  7408                   -je 0x4c0eab
    if (cpu.flags.zf)
    {
        goto L_0x004c0eab;
    }
    // 004c0ea3  81ce00001000           +or esi, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 004c0ea9  eb0e                   -jmp 0x4c0eb9
    goto L_0x004c0eb9;
L_0x004c0eab:
    // 004c0eab  01db                   +add ebx, ebx
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
    // 004c0ead  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 004c0eaf  6649                   -dec cx
    (cpu.cx)--;
    // 004c0eb1  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 004c0eb7  74f2                   -je 0x4c0eab
    if (cpu.flags.zf)
    {
        goto L_0x004c0eab;
    }
L_0x004c0eb9:
    // 004c0eb9  6629cf                 -sub di, cx
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.cx));
    // 004c0ebc  6681c7ff03             +add di, 0x3ff
    {
        x86::reg16& tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) == (1 & (tmp2 >> 15));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0ec1  7811                   -js 0x4c0ed4
    if (cpu.flags.sf)
    {
        goto L_0x004c0ed4;
    }
    // 004c0ec3  6681ffff07             +cmp di, 0x7ff
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c0ec8  720a                   -jb 0x4c0ed4
    if (cpu.flags.cf)
    {
        goto L_0x004c0ed4;
    }
    // 004c0eca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c0ecc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0ecd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0ece  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0ecf  e989310000             -jmp 0x4c405d
    return sub_4c405d(app, cpu);
L_0x004c0ed4:
    // 004c0ed4  6683ffcc               +cmp di, -0x34
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-52 /*-0x34*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c0ed8  7d08                   -jge 0x4c0ee2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c0ee2;
    }
    // 004c0eda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0edb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0edc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0edd  e95e310000             -jmp 0x4c4040
    return sub_4c4040(app, cpu);
L_0x004c0ee2:
    // 004c0ee2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c0ee3  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 004c0ee5  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 004c0ee8  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 004c0eeb  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 004c0ef0  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 004c0ef3  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 004c0ef6  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 004c0efc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c0efd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c0efe  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004c0f00  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c0f02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c0f04  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c0f06  39d1                   +cmp ecx, edx
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
    // 004c0f08  7703                   -ja 0x4c0f0d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c0f0d;
    }
    // 004c0f0a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0f0c  40                     -inc eax
    (cpu.eax)++;
L_0x004c0f0d:
    // 004c0f0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c0f0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0f10  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004c0f12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c0f13  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c0f14  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004c0f16  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c0f17  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 004c0f19  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 004c0f1b  01d8                   +add eax, ebx
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
    // 004c0f1d  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c0f20  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004c0f23  f645e801               +test byte ptr [ebp - 0x18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) & 1 /*0x1*/));
    // 004c0f27  7405                   -je 0x4c0f2e
    if (cpu.flags.zf)
    {
        goto L_0x004c0f2e;
    }
    // 004c0f29  01d8                   +add eax, ebx
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
    // 004c0f2b  1355f0                 -adc edx, dword ptr [ebp - 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) + cpu.flags.cf);
L_0x004c0f2e:
    // 004c0f2e  f7d9                   +neg ecx
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
    // 004c0f30  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f32  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f34  7412                   -je 0x4c0f48
    if (cpu.flags.zf)
    {
        goto L_0x004c0f48;
    }
L_0x004c0f36:
    // 004c0f36  836de401               +sub dword ptr [ebp - 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f3a  835de800               -sbb dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c0f3e  01d9                   +add ecx, ebx
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
    // 004c0f40  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f43  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f46  75ee                   -jne 0x4c0f36
    if (!cpu.flags.zf)
    {
        goto L_0x004c0f36;
    }
L_0x004c0f48:
    // 004c0f48  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c0f4a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c0f4c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c0f4f  39f9                   +cmp ecx, edi
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
    // 004c0f51  770a                   -ja 0x4c0f5d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c0f5d;
    }
    // 004c0f53  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c0f55  8345e401               +add dword ptr [ebp - 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f59  8355e800               -adc dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x004c0f5d:
    // 004c0f5d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004c0f5f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c0f61  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004c0f63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c0f64  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c0f66  742c                   -je 0x4c0f94
    if (cpu.flags.zf)
    {
        goto L_0x004c0f94;
    }
    // 004c0f68  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c0f69  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004c0f6b  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c0f6c  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 004c0f6e  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 004c0f70  01d8                   +add eax, ebx
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
    // 004c0f72  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c0f75  f7d9                   +neg ecx
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
    // 004c0f77  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f79  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f7b  7417                   -je 0x4c0f94
    if (cpu.flags.zf)
    {
        goto L_0x004c0f94;
    }
L_0x004c0f7d:
    // 004c0f7d  836de001               +sub dword ptr [ebp - 0x20], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f81  835de400               +sbb dword ptr [ebp - 0x1c], 0
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f85  835de800               -sbb dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c0f89  034dec                 +add ecx, dword ptr [ebp - 0x14]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f8c  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f8f  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0f92  75e9                   -jne 0x4c0f7d
    if (!cpu.flags.zf)
    {
        goto L_0x004c0f7d;
    }
L_0x004c0f94:
    // 004c0f94  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0f95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0f96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0f97  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c0f9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0f9b  664f                   -dec di
    (cpu.di)--;
    // 004c0f9d  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c0f9f  7305                   -jae 0x4c0fa6
    if (!cpu.flags.cf)
    {
        goto L_0x004c0fa6;
    }
    // 004c0fa1  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c0fa3  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c0fa5  47                     -inc edi
    (cpu.edi)++;
L_0x004c0fa6:
    // 004c0fa6  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c0fa8  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 004c0faa  0fadd0                 +shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        cpu.flags.cf = 1 & (destination >> (cpu.cl - 1));
        cpu.flags.of = 1 & (destination >> (32 - 1));
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
        cpu.flags.of ^= 1 & (destination >> (32 - 1));
        cpu.set_szp(destination);
    }
    // 004c0fad  d1de                   -rcr esi, 1
    {
        x86::reg32& op = cpu.esi;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c0faf  0fadf2                 -shrd edx, esi, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.esi  << (32 - (cpu.cl % 32));
    }
    // 004c0fb2  81ca0000f0ff           -or edx, 0xfff00000
    cpu.edx |= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 004c0fb8  01f6                   +add esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0fba  83d000                 +adc eax, 0
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
    // 004c0fbd  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0fc0  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c0fc3  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 004c0fc6  7f1d                   -jg 0x4c0fe5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c0fe5;
    }
    // 004c0fc8  7504                   -jne 0x4c0fce
    if (!cpu.flags.zf)
    {
        goto L_0x004c0fce;
    }
    // 004c0fca  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 004c0fcc  eb06                   -jmp 0x4c0fd4
    goto L_0x004c0fd4;
L_0x004c0fce:
    // 004c0fce  66f7df                 -neg di
    cpu.di = ~cpu.di + 1;
    // 004c0fd1  6689f9                 -mov cx, di
    cpu.cx = cpu.di;
L_0x004c0fd4:
    // 004c0fd4  81e2ffff1f00           -and edx, 0x1fffff
    cpu.edx &= x86::reg32(x86::sreg32(2097151 /*0x1fffff*/));
    // 004c0fda  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c0fdc  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 004c0fdf  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 004c0fe2  6629ff                 -sub di, di
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.di));
L_0x004c0fe5:
    // 004c0fe5  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c0feb  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004c0fed  c1cf0b                 -ror edi, 0xb
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004c0ff0  01f6                   +add esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c0ff2  d1df                   -rcr edi, 1
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c0ff4  81e70000f0ff           -and edi, 0xfff00000
    cpu.edi &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 004c0ffa  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004c0ffc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0ffd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0ffe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c0fff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1000  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c1006  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004c1008  7506                   -jne 0x4c1010
    if (!cpu.flags.zf)
    {
        goto L_0x004c1010;
    }
    // 004c100a  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c100c  740e                   -je 0x4c101c
    if (cpu.flags.zf)
    {
        goto L_0x004c101c;
    }
    // 004c100e  d1d9                   -rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c1010:
    // 004c1010  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c1012  750b                   -jne 0x4c101f
    if (!cpu.flags.zf)
    {
        goto L_0x004c101f;
    }
    // 004c1014  01d2                   +add edx, edx
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
    // 004c1016  7505                   -jne 0x4c101d
    if (!cpu.flags.zf)
    {
        goto L_0x004c101d;
    }
    // 004c1018  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c101a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004c101c:
    // 004c101c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c101d:
    // 004c101d  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c101f:
    // 004c101f  803d3db54d0000         +cmp byte ptr [0x4db53d], 0
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
    // 004c1026  7421                   -je 0x4c1049
    if (cpu.flags.zf)
    {
        goto L_0x004c1049;
    }
    // 004c1028  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1029  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c102a  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004c102d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c102e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c102f  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esp));
    // 004c1032  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1036  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c1039  9b                     -wait 
    /*nothing*/;
    // 004c103a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c103b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c103c  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1042  7504                   -jne 0x4c1048
    if (!cpu.flags.zf)
    {
        goto L_0x004c1048;
    }
    // 004c1044  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1046  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c1048:
    // 004c1048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1049:
    // 004c1049  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c104a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c104b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c104c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c104e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c1050  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 004c1053  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 004c1056  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c105c  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c1062  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004c1064  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1067  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c106a  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 004c106d  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1070  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1073  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c1079  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c107f  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 004c1082  7406                   -je 0x4c108a
    if (cpu.flags.zf)
    {
        goto L_0x004c108a;
    }
    // 004c1084  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x004c108a:
    // 004c108a  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 004c108d  7406                   -je 0x4c1095
    if (cpu.flags.zf)
    {
        goto L_0x004c1095;
    }
    // 004c108f  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x004c1095:
    // 004c1095  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1097  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c1099  01db                   +add ebx, ebx
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
    // 004c109b  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 004c109d  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c10a0  742f                   -je 0x4c10d1
    if (cpu.flags.zf)
    {
        goto L_0x004c10d1;
    }
    // 004c10a2  7308                   -jae 0x4c10ac
    if (!cpu.flags.cf)
    {
        goto L_0x004c10ac;
    }
    // 004c10a4  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004c10a6  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 004c10a9  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c10aa  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x004c10ac:
    // 004c10ac  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c10b0  761f                   -jbe 0x4c10d1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c10d1;
    }
    // 004c10b2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004c10b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c10b6  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c10b8  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c10ba  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c10bc  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 004c10c2  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004c10c5  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c10cb  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c10cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c10ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c10cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c10d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c10d1:
    // 004c10d1  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c10d3  790d                   -jns 0x4c10e2
    if (!cpu.flags.sf)
    {
        goto L_0x004c10e2;
    }
    // 004c10d5  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004c10d7  f7db                   +neg ebx
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
    // 004c10d9  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c10dc  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x004c10e2:
    // 004c10e2  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004c10e4  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c10e7  7423                   -je 0x4c110c
    if (cpu.flags.zf)
    {
        goto L_0x004c110c;
    }
    // 004c10e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c10ea  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c10ec  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c10ef  720d                   -jb 0x4c10fe
    if (cpu.flags.cf)
    {
        goto L_0x004c10fe;
    }
    // 004c10f1  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c10f3  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 004c10f6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004c10f8  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c10fa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c10fc  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x004c10fe:
    // 004c10fe  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 004c1101  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1103  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1105  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 004c1108  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 004c110b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c110c:
    // 004c110c  01d8                   +add eax, ebx
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
    // 004c110e  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1110  7923                   -jns 0x4c1135
    if (!cpu.flags.sf)
    {
        goto L_0x004c1135;
    }
    // 004c1112  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1115  7211                   -jb 0x4c1128
    if (cpu.flags.cf)
    {
        goto L_0x004c1128;
    }
    // 004c1117  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 004c111d  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 004c1120  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c1122  83d000                 +adc eax, 0
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
    // 004c1125  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x004c1128:
    // 004c1128  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004c112a  f7d8                   +neg eax
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
    // 004c112c  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c112f  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x004c1135:
    // 004c1135  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1137  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c1139  746a                   -je 0x4c11a5
    if (cpu.flags.zf)
    {
        goto L_0x004c11a5;
    }
    // 004c113b  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 004c113e  7469                   -je 0x4c11a9
    if (cpu.flags.zf)
    {
        goto L_0x004c11a9;
    }
L_0x004c1140:
    // 004c1140  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 004c1146  750a                   -jne 0x4c1152
    if (!cpu.flags.zf)
    {
        goto L_0x004c1152;
    }
    // 004c1148  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 004c114a  745d                   -je 0x4c11a9
    if (cpu.flags.zf)
    {
        goto L_0x004c11a9;
    }
    // 004c114c  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c114e  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1150  ebee                   -jmp 0x4c1140
    goto L_0x004c1140;
L_0x004c1152:
    // 004c1152  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 004c1158  7410                   -je 0x4c116a
    if (cpu.flags.zf)
    {
        goto L_0x004c116a;
    }
    // 004c115a  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c115c  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c115e  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1161  6645                   -inc bp
    (cpu.bp)++;
    // 004c1163  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c1168  7449                   -je 0x4c11b3
    if (cpu.flags.zf)
    {
        goto L_0x004c11b3;
    }
L_0x004c116a:
    // 004c116a  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c116c  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c116e  7324                   -jae 0x4c1194
    if (!cpu.flags.cf)
    {
        goto L_0x004c1194;
    }
    // 004c1170  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 004c1172  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 004c1175  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1177  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c1179  83d000                 +adc eax, 0
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
    // 004c117c  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c117f  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 004c1185  740d                   -je 0x4c1194
    if (cpu.flags.zf)
    {
        goto L_0x004c1194;
    }
    // 004c1187  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c1189  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c118b  6645                   -inc bp
    (cpu.bp)++;
    // 004c118d  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c1192  741f                   -je 0x4c11b3
    if (cpu.flags.zf)
    {
        goto L_0x004c11b3;
    }
L_0x004c1194:
    // 004c1194  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c119a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004c119c  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 004c119f  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c11a1  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c11a3  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004c11a5:
    // 004c11a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c11a9:
    // 004c11a9  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c11ab  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c11ad  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c11af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c11b3:
    // 004c11b3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c11b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b8  e9a02e0000             -jmp 0x4c405d
    return sub_4c405d(app, cpu);
}

/* align: skip  */
void Application::sub_4c1032(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c1032;
    // 004c1000  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c1006  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004c1008  7506                   -jne 0x4c1010
    if (!cpu.flags.zf)
    {
        goto L_0x004c1010;
    }
    // 004c100a  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c100c  740e                   -je 0x4c101c
    if (cpu.flags.zf)
    {
        goto L_0x004c101c;
    }
    // 004c100e  d1d9                   -rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c1010:
    // 004c1010  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c1012  750b                   -jne 0x4c101f
    if (!cpu.flags.zf)
    {
        goto L_0x004c101f;
    }
    // 004c1014  01d2                   +add edx, edx
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
    // 004c1016  7505                   -jne 0x4c101d
    if (!cpu.flags.zf)
    {
        goto L_0x004c101d;
    }
    // 004c1018  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c101a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004c101c:
    // 004c101c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c101d:
    // 004c101d  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c101f:
    // 004c101f  803d3db54d0000         +cmp byte ptr [0x4db53d], 0
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
    // 004c1026  7421                   -je 0x4c1049
    if (cpu.flags.zf)
    {
        goto L_0x004c1049;
    }
    // 004c1028  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1029  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c102a  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004c102d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c102e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c102f  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esp));
L_entry_0x004c1032:
    // 004c1032  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1036  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c1039  9b                     -wait 
    /*nothing*/;
    // 004c103a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c103b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c103c  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1042  7504                   -jne 0x4c1048
    if (!cpu.flags.zf)
    {
        goto L_0x004c1048;
    }
    // 004c1044  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1046  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c1048:
    // 004c1048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1049:
    // 004c1049  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c104a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c104b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c104c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c104e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c1050  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 004c1053  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 004c1056  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c105c  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c1062  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004c1064  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1067  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c106a  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 004c106d  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1070  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1073  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c1079  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c107f  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 004c1082  7406                   -je 0x4c108a
    if (cpu.flags.zf)
    {
        goto L_0x004c108a;
    }
    // 004c1084  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x004c108a:
    // 004c108a  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 004c108d  7406                   -je 0x4c1095
    if (cpu.flags.zf)
    {
        goto L_0x004c1095;
    }
    // 004c108f  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x004c1095:
    // 004c1095  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1097  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c1099  01db                   +add ebx, ebx
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
    // 004c109b  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 004c109d  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c10a0  742f                   -je 0x4c10d1
    if (cpu.flags.zf)
    {
        goto L_0x004c10d1;
    }
    // 004c10a2  7308                   -jae 0x4c10ac
    if (!cpu.flags.cf)
    {
        goto L_0x004c10ac;
    }
    // 004c10a4  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004c10a6  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 004c10a9  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c10aa  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x004c10ac:
    // 004c10ac  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c10b0  761f                   -jbe 0x4c10d1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c10d1;
    }
    // 004c10b2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004c10b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c10b6  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c10b8  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c10ba  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c10bc  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 004c10c2  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004c10c5  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c10cb  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c10cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c10ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c10cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c10d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c10d1:
    // 004c10d1  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c10d3  790d                   -jns 0x4c10e2
    if (!cpu.flags.sf)
    {
        goto L_0x004c10e2;
    }
    // 004c10d5  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004c10d7  f7db                   +neg ebx
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
    // 004c10d9  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c10dc  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x004c10e2:
    // 004c10e2  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004c10e4  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c10e7  7423                   -je 0x4c110c
    if (cpu.flags.zf)
    {
        goto L_0x004c110c;
    }
    // 004c10e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c10ea  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c10ec  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c10ef  720d                   -jb 0x4c10fe
    if (cpu.flags.cf)
    {
        goto L_0x004c10fe;
    }
    // 004c10f1  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c10f3  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 004c10f6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004c10f8  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c10fa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c10fc  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x004c10fe:
    // 004c10fe  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 004c1101  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1103  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1105  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 004c1108  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 004c110b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c110c:
    // 004c110c  01d8                   +add eax, ebx
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
    // 004c110e  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1110  7923                   -jns 0x4c1135
    if (!cpu.flags.sf)
    {
        goto L_0x004c1135;
    }
    // 004c1112  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c1115  7211                   -jb 0x4c1128
    if (cpu.flags.cf)
    {
        goto L_0x004c1128;
    }
    // 004c1117  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 004c111d  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 004c1120  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c1122  83d000                 +adc eax, 0
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
    // 004c1125  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x004c1128:
    // 004c1128  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004c112a  f7d8                   +neg eax
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
    // 004c112c  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c112f  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x004c1135:
    // 004c1135  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1137  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c1139  746a                   -je 0x4c11a5
    if (cpu.flags.zf)
    {
        goto L_0x004c11a5;
    }
    // 004c113b  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 004c113e  7469                   -je 0x4c11a9
    if (cpu.flags.zf)
    {
        goto L_0x004c11a9;
    }
L_0x004c1140:
    // 004c1140  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 004c1146  750a                   -jne 0x4c1152
    if (!cpu.flags.zf)
    {
        goto L_0x004c1152;
    }
    // 004c1148  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 004c114a  745d                   -je 0x4c11a9
    if (cpu.flags.zf)
    {
        goto L_0x004c11a9;
    }
    // 004c114c  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c114e  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1150  ebee                   -jmp 0x4c1140
    goto L_0x004c1140;
L_0x004c1152:
    // 004c1152  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 004c1158  7410                   -je 0x4c116a
    if (cpu.flags.zf)
    {
        goto L_0x004c116a;
    }
    // 004c115a  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c115c  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c115e  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1161  6645                   -inc bp
    (cpu.bp)++;
    // 004c1163  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c1168  7449                   -je 0x4c11b3
    if (cpu.flags.zf)
    {
        goto L_0x004c11b3;
    }
L_0x004c116a:
    // 004c116a  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c116c  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c116e  7324                   -jae 0x4c1194
    if (!cpu.flags.cf)
    {
        goto L_0x004c1194;
    }
    // 004c1170  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 004c1172  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 004c1175  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1177  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c1179  83d000                 +adc eax, 0
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
    // 004c117c  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c117f  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 004c1185  740d                   -je 0x4c1194
    if (cpu.flags.zf)
    {
        goto L_0x004c1194;
    }
    // 004c1187  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c1189  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c118b  6645                   -inc bp
    (cpu.bp)++;
    // 004c118d  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c1192  741f                   -je 0x4c11b3
    if (cpu.flags.zf)
    {
        goto L_0x004c11b3;
    }
L_0x004c1194:
    // 004c1194  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c119a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004c119c  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 004c119f  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c11a1  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c11a3  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004c11a5:
    // 004c11a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c11a9:
    // 004c11a9  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c11ab  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c11ad  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c11af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c11b3:
    // 004c11b3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c11b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c11b8  e9a02e0000             -jmp 0x4c405d
    return sub_4c405d(app, cpu);
}

/* align: skip  */
void Application::sub_4c11bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c11bd  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c11bf  7507                   -jne 0x4c11c8
    if (!cpu.flags.zf)
    {
        goto L_0x004c11c8;
    }
    // 004c11c1  01d2                   +add edx, edx
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
    // 004c11c3  7501                   -jne 0x4c11c6
    if (!cpu.flags.zf)
    {
        goto L_0x004c11c6;
    }
    // 004c11c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c11c6:
    // 004c11c6  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c11c8:
    // 004c11c8  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004c11ca  750b                   -jne 0x4c11d7
    if (!cpu.flags.zf)
    {
        goto L_0x004c11d7;
    }
    // 004c11cc  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c11ce  7505                   -jne 0x4c11d5
    if (!cpu.flags.zf)
    {
        goto L_0x004c11d5;
    }
    // 004c11d0  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c11d2  29d2                   +sub edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c11d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c11d5:
    // 004c11d5  d1d9                   -rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
L_0x004c11d7:
    // 004c11d7  803d3db54d0000         +cmp byte ptr [0x4db53d], 0
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
    // 004c11de  740f                   -je 0x4c11ef
    if (cpu.flags.zf)
    {
        goto L_0x004c11ef;
    }
    // 004c11e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c11e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c11e2  dd0424                 +fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004c11e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c11e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c11e7  dc0c24                 +fmul qword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp));
    // 004c11ea  e943feffff             -jmp 0x4c1032
    return sub_4c1032(app, cpu);
L_0x004c11ef:
    // 004c11ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c11f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c11f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c11f2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c11f4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c11f6  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 004c11f9  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 004c11fc  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c1202  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 004c1208  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c120b  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c120e  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 004c1211  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1214  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004c1217  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c121d  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c1223  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 004c1226  7510                   -jne 0x4c1238
    if (!cpu.flags.zf)
    {
        goto L_0x004c1238;
    }
    // 004c1228  6647                   -inc di
    (cpu.di)++;
L_0x004c122a:
    // 004c122a  664f                   -dec di
    (cpu.di)--;
    // 004c122c  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c122e  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c1230  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 004c1236  74f2                   -je 0x4c122a
    if (cpu.flags.zf)
    {
        goto L_0x004c122a;
    }
L_0x004c1238:
    // 004c1238  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 004c123e  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 004c1241  7510                   -jne 0x4c1253
    if (!cpu.flags.zf)
    {
        goto L_0x004c1253;
    }
    // 004c1243  6641                   -inc cx
    (cpu.cx)++;
L_0x004c1245:
    // 004c1245  6649                   -dec cx
    (cpu.cx)--;
    // 004c1247  01db                   +add ebx, ebx
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
    // 004c1249  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 004c124b  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 004c1251  74f2                   -je 0x4c1245
    if (cpu.flags.zf)
    {
        goto L_0x004c1245;
    }
L_0x004c1253:
    // 004c1253  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 004c1259  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 004c125c  6681e9ff03             +sub cx, 0x3ff
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1261  7811                   -js 0x4c1274
    if (cpu.flags.sf)
    {
        goto L_0x004c1274;
    }
    // 004c1263  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c1268  720a                   -jb 0x4c1274
    if (cpu.flags.cf)
    {
        goto L_0x004c1274;
    }
    // 004c126a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c126c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c126d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c126e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c126f  e9e92d0000             -jmp 0x4c405d
    return sub_4c405d(app, cpu);
L_0x004c1274:
    // 004c1274  6683f9cb               +cmp cx, -0x35
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-53 /*-0x35*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c1278  7d08                   -jge 0x4c1282
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c1282;
    }
    // 004c127a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c127b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c127c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c127d  e9be2d0000             -jmp 0x4c4040
    return sub_4c4040(app, cpu);
L_0x004c1282:
    // 004c1282  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1283  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 004c1285  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 004c1288  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 004c128b  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 004c1290  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 004c1293  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 004c1296  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 004c129c  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c129e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c129f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c12a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c12a1  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004c12a3  96                     -xchg esi, eax
    {
        x86::reg32 tmp = cpu.esi;
        cpu.esi = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c12a4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c12a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c12a7  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 004c12a9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c12ab  01c1                   +add ecx, eax
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
    // 004c12ad  11ef                   +adc edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c12af  11ed                   -adc ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 004c12b1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c12b2  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c12b3  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004c12b5  01c1                   +add ecx, eax
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
    // 004c12b7  11d7                   +adc edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c12b9  83d500                 -adc ebp, 0
    (cpu.ebp) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c12bc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c12be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c12bf  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 004c12c1  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c12c3  11ea                   -adc edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 004c12c5  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c12c7  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 004c12c9  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 004c12cc  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 004c12cf  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 004c12d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c12d3:
    // 004c12d3  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 004c12d9  7411                   -je 0x4c12ec
    if (cpu.flags.zf)
    {
        goto L_0x004c12ec;
    }
    // 004c12db  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c12dd  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c12df  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c12e1  6641                   -inc cx
    (cpu.cx)++;
    // 004c12e3  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c12e8  7466                   -je 0x4c1350
    if (cpu.flags.zf)
    {
        goto L_0x004c1350;
    }
    // 004c12ea  ebe7                   -jmp 0x4c12d3
    goto L_0x004c12d3;
L_0x004c12ec:
    // 004c12ec  01db                   +add ebx, ebx
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
    // 004c12ee  732a                   -jae 0x4c131a
    if (!cpu.flags.cf)
    {
        goto L_0x004c131a;
    }
    // 004c12f0  750d                   -jne 0x4c12ff
    if (!cpu.flags.zf)
    {
        goto L_0x004c12ff;
    }
    // 004c12f2  09f6                   +or esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.esi))));
    // 004c12f4  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 004c12f7  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c12f9  7204                   -jb 0x4c12ff
    if (cpu.flags.cf)
    {
        goto L_0x004c12ff;
    }
    // 004c12fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c12fd  d1ee                   +shr esi, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
L_0x004c12ff:
    // 004c12ff  83d000                 +adc eax, 0
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
    // 004c1302  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1305  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 004c130b  740d                   -je 0x4c131a
    if (cpu.flags.zf)
    {
        goto L_0x004c131a;
    }
    // 004c130d  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004c130f  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c1311  6641                   -inc cx
    (cpu.cx)++;
    // 004c1313  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c1318  7436                   -je 0x4c1350
    if (cpu.flags.zf)
    {
        goto L_0x004c1350;
    }
L_0x004c131a:
    // 004c131a  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 004c131d  7f16                   -jg 0x4c1335
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c1335;
    }
    // 004c131f  7504                   -jne 0x4c1325
    if (!cpu.flags.zf)
    {
        goto L_0x004c1325;
    }
    // 004c1321  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 004c1323  eb05                   -jmp 0x4c132a
    goto L_0x004c132a;
L_0x004c1325:
    // 004c1325  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 004c1328  6649                   -dec cx
    (cpu.cx)--;
L_0x004c132a:
    // 004c132a  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c132c  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 004c132f  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 004c1332  6629c9                 -sub cx, cx
    (cpu.cx) -= x86::reg16(x86::sreg16(cpu.cx));
L_0x004c1335:
    // 004c1335  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004c133b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c133d  c1c90b                 -ror ecx, 0xb
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004c1340  01f6                   +add esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1342  d1d9                   -rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c1344  81e10000f0ff           -and ecx, 0xfff00000
    cpu.ecx &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 004c134a  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c134c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c134d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c134e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c134f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1350:
    // 004c1350  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1352  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1353  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1354  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1355  e9032d0000             -jmp 0x4c405d
    return sub_4c405d(app, cpu);
}

/* align: skip  */
void Application::sub_4c135a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c135a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c135b  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 004c1361  7502                   -jne 0x4c1365
    if (!cpu.flags.zf)
    {
        goto L_0x004c1365;
    }
    // 004c1363  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x004c1365:
    // 004c1365  f7c10000f07f           +test ecx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 2146435072 /*0x7ff00000*/));
    // 004c136b  7502                   -jne 0x4c136f
    if (!cpu.flags.zf)
    {
        goto L_0x004c136f;
    }
    // 004c136d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004c136f:
    // 004c136f  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004c1371  31d5                   +xor ebp, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c1373  bd00000000             -mov ebp, 0
    cpu.ebp = 0 /*0x0*/;
    // 004c1378  780c                   -js 0x4c1386
    if (cpu.flags.sf)
    {
        goto L_0x004c1386;
    }
    // 004c137a  39ca                   +cmp edx, ecx
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
    // 004c137c  7502                   -jne 0x4c1380
    if (!cpu.flags.zf)
    {
        goto L_0x004c1380;
    }
    // 004c137e  39d8                   +cmp eax, ebx
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
L_0x004c1380:
    // 004c1380  740c                   -je 0x4c138e
    if (cpu.flags.zf)
    {
        goto L_0x004c138e;
    }
    // 004c1382  d1d9                   -rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c1384  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004c1386:
    // 004c1386  01d2                   +add edx, edx
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
    // 004c1388  83dd00                 -sbb ebp, 0
    (cpu.ebp) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c138b  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004c138d  45                     -inc ebp
    (cpu.ebp)++;
L_0x004c138e:
    // 004c138e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1390  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1391  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4c1394(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1394  db6c2410               -fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c1398  db6c2404               -fld xword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */)));
L_0x004c139c:
    // 004c139c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c13a0  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c13a2  0f8386000000           -jae 0x4c142e
    if (!cpu.flags.cf)
    {
        goto L_0x004c142e;
    }
    // 004c13a8  350000000e             -xor eax, 0xe000000
    cpu.eax ^= x86::reg32(x86::sreg32(234881024 /*0xe000000*/));
    // 004c13ad  a90000000e             +test eax, 0xe000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 234881024 /*0xe000000*/));
    // 004c13b2  7403                   -je 0x4c13b7
    if (cpu.flags.zf)
    {
        goto L_0x004c13b7;
    }
    // 004c13b4  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c13b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c13b7:
    // 004c13b7  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 004c13ba  80b8184e4e0000         +cmp byte ptr [eax + 0x4e4e18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5131800) /* 0x4e4e18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c13c1  7503                   -jne 0x4c13c6
    if (!cpu.flags.zf)
    {
        goto L_0x004c13c6;
    }
    // 004c13c3  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c13c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c13c6:
    // 004c13c6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c13ca  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 004c13cf  7467                   -je 0x4c1438
    if (cpu.flags.zf)
    {
        goto L_0x004c1438;
    }
    // 004c13d1  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c13d6  7460                   -je 0x4c1438
    if (cpu.flags.zf)
    {
        goto L_0x004c1438;
    }
    // 004c13d8  d97c241c               -fnstcw word ptr [esp + 0x1c]
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 004c13dc  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c13e0  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 004c13e5  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 004c13ea  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004c13ee  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004c13f2  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004c13f6  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 004c13fb  83f801                 +cmp eax, 1
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
    // 004c13fe  7417                   -je 0x4c1417
    if (cpu.flags.zf)
    {
        goto L_0x004c1417;
    }
    // 004c1400  d80d284e4e00           -fmul dword ptr [0x4e4e28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5131816) /* 0x4e4e28 */));
    // 004c1406  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1408  d80d284e4e00           -fmul dword ptr [0x4e4e28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5131816) /* 0x4e4e28 */));
    // 004c140e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1410  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c1414  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c1416  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1417:
    // 004c1417  d80d2c4e4e00           -fmul dword ptr [0x4e4e2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5131820) /* 0x4e4e2c */));
    // 004c141d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c141f  d80d2c4e4e00           -fmul dword ptr [0x4e4e2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5131820) /* 0x4e4e2c */));
    // 004c1425  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1427  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c142b  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c142d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c142e:
    // 004c142e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1432  0b442408               +or eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 004c1436  7503                   -jne 0x4c143b
    if (!cpu.flags.zf)
    {
        goto L_0x004c143b;
    }
L_0x004c1438:
    // 004c1438  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c143a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c143b:
    // 004c143b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c143f  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 004c1444  75f2                   -jne 0x4c1438
    if (!cpu.flags.zf)
    {
        goto L_0x004c1438;
    }
    // 004c1446  d97c241c               -fnstcw word ptr [esp + 0x1c]
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 004c144a  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c144e  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 004c1453  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 004c1458  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004c145c  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004c1460  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004c1464  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 004c1469  7411                   -je 0x4c147c
    if (cpu.flags.zf)
    {
        goto L_0x004c147c;
    }
    // 004c146b  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1470  7432                   -je 0x4c14a4
    if (cpu.flags.zf)
    {
        goto L_0x004c14a4;
    }
    // 004c1472  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c1476  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1478  732a                   -jae 0x4c14a4
    if (!cpu.flags.cf)
    {
        goto L_0x004c14a4;
    }
    // 004c147a  eb08                   -jmp 0x4c1484
    goto L_0x004c1484;
L_0x004c147c:
    // 004c147c  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c1480  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1482  7220                   -jb 0x4c14a4
    if (cpu.flags.cf)
    {
        goto L_0x004c14a4;
    }
L_0x004c1484:
    // 004c1484  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1486  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1488  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c148a  d80d304e4e00           +fmul dword ptr [0x4e4e30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5131824) /* 0x4e4e30 */));
    // 004c1490  db7c2404               +fstp xword ptr [esp + 4]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1494  db6c2410               +fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c1498  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c149a  9b                     -wait 
    /*nothing*/;
    // 004c149b  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c149f  e9f8feffff             -jmp 0x4c139c
    goto L_0x004c139c;
L_0x004c14a4:
    // 004c14a4  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c14a8  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c14aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c14ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004c14ab  83ec2c                 +sub esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c14ae  ff2485344e4e00         -jmp dword ptr [eax*4 + 0x4e4e34]
    cpu.ip = app->getMemory<x86::reg32>(5131828 + cpu.eax * 4); goto dynamic_jump;
  case 0x004c14b5:
    // 004c14b5  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 004c14b7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14ba  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c14bb:
    // 004c14bb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14be  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c14c0:
    // 004c14c0  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 004c14c2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14c5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c14c6:
    // 004c14c6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14c9  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c14cb:
    // 004c14cb  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 004c14cd  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14d0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c14d1:
    // 004c14d1  def8                   -fdivp st(0)
    cpu.fpu.st(0) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c14d3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14d6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c14d7:
    // 004c14d7  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 004c14d9  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14dc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c14dd:
    // 004c14dd  def0                   -fdivrp st(0)
    cpu.fpu.st(0) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c14df  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14e2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c14e3:
    // 004c14e3  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c14e7  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c14e9  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c14ec  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c14f0  e89ffeffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c14f5  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c14f9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c14fb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c14fe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c14ff:
    // 004c14ff  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1502  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c1504:
    // 004c1504  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1507  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c150b  e884feffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1510  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c1514  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1516  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1519  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c151a:
    // 004c151a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c151d  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c151f:
    // 004c151f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1521  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1525  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c1527  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c152a  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c152e  e861feffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1533  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c1537  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c153a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c153b:
    // 004c153b  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c153e  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1542  e84dfeffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1547  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c154a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c154b:
    // 004c154b  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c154f  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1552  e83dfeffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1557  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c155b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c155e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c155f:
    // 004c155f  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1563  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1566  e829feffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c156b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c156e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c156f:
    // 004c156f  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1573  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1575  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c1577  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c157a  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c157e  e811feffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1583  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1585  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c1589  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c158b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c158e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c158f:
    // 004c158f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1592  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c1594:
    // 004c1594  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1597  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1599  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c159d  e8f2fdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c15a2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c15a4  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c15a8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c15aa  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c15ad  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c15ae:
    // 004c15ae  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c15b1  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c15b3:
    // 004c15b3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c15b5  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c15b9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c15bb  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c15bd  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c15c0  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c15c4  e8cbfdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c15c9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c15cb  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c15cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c15d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c15d3:
    // 004c15d3  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c15d6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c15d8  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c15dc  e8b3fdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c15e1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c15e3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c15e6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c15e7:
    // 004c15e7  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c15eb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c15ed  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c15f0  e89ffdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c15f5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c15f7  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c15fb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c15fe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c15ff:
    // 004c15ff  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1603  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1605  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1608  e887fdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c160d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c160f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1612  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1613:
    // 004c1613  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1617  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c1619  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c161b  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c161e  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1622  e86dfdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1627  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c1629  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c162d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c162f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1632  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1633:
    // 004c1633  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1636  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c1638:
    // 004c1638  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c163b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c163d  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1641  e84efdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1646  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c1648  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c164c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c164e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1651  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1652:
    // 004c1652  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1655  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c1657:
    // 004c1657  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c1659  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c165d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c165f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c1661  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1664  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1668  e827fdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c166d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c166f  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c1673  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1676  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1677:
    // 004c1677  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c167a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c167c  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1680  e80ffdffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1685  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c1687  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c168a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c168b:
    // 004c168b  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c168f  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c1691  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1694  e8fbfcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1699  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c169b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c169f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c16a2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c16a3:
    // 004c16a3  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c16a7  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c16a9  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c16ac  e8e3fcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c16b1  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c16b3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c16b6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c16b7:
    // 004c16b7  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c16bb  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c16bd  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c16bf  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c16c2  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c16c6  e8c9fcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c16cb  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c16cd  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c16d1  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c16d3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c16d6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c16d7:
    // 004c16d7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c16da  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c16dc:
    // 004c16dc  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c16df  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c16e1  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c16e5  e8aafcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c16ea  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c16ec  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c16f0  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c16f2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c16f5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c16f6:
    // 004c16f6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c16f9  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c16fb:
    // 004c16fb  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c16fd  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1701  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c1703  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c1705  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1708  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c170c  e883fcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1711  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c1713  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c1717  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c171a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c171b:
    // 004c171b  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c171e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c1720  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1724  e86bfcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1729  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c172b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c172e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c172f:
    // 004c172f  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1733  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c1735  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1738  e857fcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c173d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c173f  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c1743  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1746  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1747:
    // 004c1747  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c174b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c174d  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1750  e83ffcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1755  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004c1757  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c175a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c175b:
    // 004c175b  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c175f  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c1761  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c1763  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1766  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c176a  e825fcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c176f  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c1771  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c1775  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1777  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c177a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c177b:
    // 004c177b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c177e  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c1780:
    // 004c1780  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1783  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c1785  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1789  e806fcffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c178e  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c1790  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c1794  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1796  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1799  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c179a:
    // 004c179a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c179d  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c179f:
    // 004c179f  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c17a1  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17a5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17a7  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c17a9  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17ac  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17b0  e8dffbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c17b5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17b7  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c17bb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c17be  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c17bf:
    // 004c17bf  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17c2  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17c4  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17c8  e8c7fbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c17cd  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17cf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c17d2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c17d3:
    // 004c17d3  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17d7  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17d9  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17dc  e8b3fbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c17e1  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17e3  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c17e7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c17ea  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c17eb:
    // 004c17eb  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17ef  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17f1  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c17f4  e89bfbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c17f9  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004c17fb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c17fe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c17ff:
    // 004c17ff  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1803  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1805  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c1807  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c180a  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c180e  e881fbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1813  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1815  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c1819  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c181b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c181e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c181f:
    // 004c181f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1822  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c1824:
    // 004c1824  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1827  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1829  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c182d  e862fbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1832  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1834  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c1838  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c183a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c183d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c183e:
    // 004c183e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1841  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c1843:
    // 004c1843  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c1845  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1849  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c184b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c184d  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1850  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1854  e83bfbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1859  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c185b  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c185f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1862  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1863:
    // 004c1863  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1866  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1868  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c186c  e823fbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1871  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1873  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1876  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1877:
    // 004c1877  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c187b  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c187d  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1880  e80ffbffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1885  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1887  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c188b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c188e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c188f:
    // 004c188f  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1893  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c1895  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1898  e8f7faffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c189d  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004c189f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c18a2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c18a3:
    // 004c18a3  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18a7  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c18a9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c18ab  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18ae  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18b2  e8ddfaffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c18b7  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c18b9  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c18bd  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 004c18bf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c18c2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c18c3:
    // 004c18c3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c18c6  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c18c8:
    // 004c18c8  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18cb  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c18cd  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18d1  e8befaffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c18d6  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c18d8  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c18dc  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 004c18de  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c18e1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c18e2:
    // 004c18e2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c18e5  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x004c18e7:
    // 004c18e7  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 004c18e9  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18ed  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c18ef  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c18f1  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18f4  db7c2420               -fstp xword ptr [esp + 0x20]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c18f8  e897faffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c18fd  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c18ff  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c1903  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1906  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1907:
    // 004c1907  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c190a  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c190c  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1910  e87ffaffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1915  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c1917  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c191a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c191b:
    // 004c191b  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c191f  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c1921  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1924  e86bfaffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1929  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c192b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c192f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1932  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c1933:
    // 004c1933  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1937  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c1939  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c193c  e853faffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1941  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 004c1943  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1946  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4c1947(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1947  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c194a  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c194d  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1951  e83efaffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1956  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1959  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c195a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c195a  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c195d  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1961  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1964  e82bfaffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c1969  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c196c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c196d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c196d  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c1970  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1974  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1977  e818faffff             -call 0x4c1394
    cpu.esp -= 4;
    sub_4c1394(app, cpu);
    if (cpu.terminate) return;
    // 004c197c  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c197f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1980  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1981  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1985  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 004c198a  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c198f  7433                   -je 0x4c19c4
    if (cpu.flags.zf)
    {
        goto L_0x004c19c4;
    }
    // 004c1991  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004c1993  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 004c1998  740d                   -je 0x4c19a7
    if (cpu.flags.zf)
    {
        goto L_0x004c19a7;
    }
    // 004c199a  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c199e  e8a4ffffff             -call 0x4c1947
    cpu.esp -= 4;
    sub_4c1947(app, cpu);
    if (cpu.terminate) return;
    // 004c19a3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c19a4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004c19a7:
    // 004c19a7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c19a9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c19ac  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c19af  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c19b3  e88fffffff             -call 0x4c1947
    cpu.esp -= 4;
    sub_4c1947(app, cpu);
    if (cpu.terminate) return;
    // 004c19b8  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 004c19bb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c19bd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c19c0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c19c1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004c19c4:
    // 004c19c4  d8742408               -fdiv dword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004c19c8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c19c9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4c19cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c19cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c19cd  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c19d1  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c19d6  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c19db  7433                   -je 0x4c1a10
    if (cpu.flags.zf)
    {
        goto L_0x004c1a10;
    }
    // 004c19dd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004c19df  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 004c19e4  740d                   -je 0x4c19f3
    if (cpu.flags.zf)
    {
        goto L_0x004c19f3;
    }
    // 004c19e6  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c19ea  e858ffffff             -call 0x4c1947
    cpu.esp -= 4;
    sub_4c1947(app, cpu);
    if (cpu.terminate) return;
    // 004c19ef  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c19f0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004c19f3:
    // 004c19f3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c19f5  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c19f8  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c19fb  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c19ff  e843ffffff             -call 0x4c1947
    cpu.esp -= 4;
    sub_4c1947(app, cpu);
    if (cpu.terminate) return;
    // 004c1a04  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 004c1a07  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1a09  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1a0c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a0d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004c1a10:
    // 004c1a10  dc742408               -fdiv qword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 004c1a14  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a15  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4c1a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1a18  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1a19  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1a1d  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 004c1a22  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1a27  7433                   -je 0x4c1a5c
    if (cpu.flags.zf)
    {
        goto L_0x004c1a5c;
    }
    // 004c1a29  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004c1a2b  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 004c1a30  740d                   -je 0x4c1a3f
    if (cpu.flags.zf)
    {
        goto L_0x004c1a3f;
    }
    // 004c1a32  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c1a36  e81fffffff             -call 0x4c195a
    cpu.esp -= 4;
    sub_4c195a(app, cpu);
    if (cpu.terminate) return;
    // 004c1a3b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a3c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004c1a3f:
    // 004c1a3f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1a41  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1a44  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1a47  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c1a4b  e80affffff             -call 0x4c195a
    cpu.esp -= 4;
    sub_4c195a(app, cpu);
    if (cpu.terminate) return;
    // 004c1a50  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 004c1a53  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1a55  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1a58  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a59  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004c1a5c:
    // 004c1a5c  d87c2408               -fdivr dword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 004c1a60  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a61  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4c1a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1a64  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1a65  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1a69  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c1a6e  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1a73  7433                   -je 0x4c1aa8
    if (cpu.flags.zf)
    {
        goto L_0x004c1aa8;
    }
    // 004c1a75  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004c1a77  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 004c1a7c  740d                   -je 0x4c1a8b
    if (cpu.flags.zf)
    {
        goto L_0x004c1a8b;
    }
    // 004c1a7e  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c1a82  e8d3feffff             -call 0x4c195a
    cpu.esp -= 4;
    sub_4c195a(app, cpu);
    if (cpu.terminate) return;
    // 004c1a87  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1a88  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004c1a8b:
    // 004c1a8b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1a8d  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1a90  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c1a93  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c1a97  e8befeffff             -call 0x4c195a
    cpu.esp -= 4;
    sub_4c195a(app, cpu);
    if (cpu.terminate) return;
    // 004c1a9c  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 004c1a9f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c1aa1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1aa4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1aa5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004c1aa8:
    // 004c1aa8  dc7c2408               -fdivr qword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 004c1aac  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1aad  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4c1ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1ab0  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c1ab2  781e                   -js 0x4c1ad2
    if (cpu.flags.sf)
    {
        goto L_0x004c1ad2;
    }
    // 004c1ab4  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c1ab6  7806                   -js 0x4c1abe
    if (cpu.flags.sf)
    {
        goto L_0x004c1abe;
    }
    // 004c1ab8  e848000000             -call 0x4c1b05
    cpu.esp -= 4;
    sub_4c1b05(app, cpu);
    if (cpu.terminate) return;
    // 004c1abd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1abe:
    // 004c1abe  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004c1ac0  f7db                   +neg ebx
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
    // 004c1ac2  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1ac5  e83b000000             -call 0x4c1b05
    cpu.esp -= 4;
    sub_4c1b05(app, cpu);
    if (cpu.terminate) return;
    // 004c1aca  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004c1acc  f7d8                   +neg eax
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
    // 004c1ace  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1ad1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1ad2:
    // 004c1ad2  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004c1ad4  f7d8                   +neg eax
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
    // 004c1ad6  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1ad9  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c1adb  7914                   -jns 0x4c1af1
    if (!cpu.flags.sf)
    {
        goto L_0x004c1af1;
    }
    // 004c1add  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004c1adf  f7db                   +neg ebx
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
    // 004c1ae1  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1ae4  e81c000000             -call 0x4c1b05
    cpu.esp -= 4;
    sub_4c1b05(app, cpu);
    if (cpu.terminate) return;
    // 004c1ae9  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004c1aeb  f7db                   +neg ebx
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
    // 004c1aed  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1af0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1af1:
    // 004c1af1  e80f000000             -call 0x4c1b05
    cpu.esp -= 4;
    sub_4c1b05(app, cpu);
    if (cpu.terminate) return;
    // 004c1af6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004c1af8  f7db                   +neg ebx
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
    // 004c1afa  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1afd  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004c1aff  f7d8                   +neg eax
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
    // 004c1b01  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 004c1b04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1b05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1b05  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c1b07  751a                   -jne 0x4c1b23
    if (!cpu.flags.zf)
    {
        goto L_0x004c1b23;
    }
    // 004c1b09  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004c1b0a  7416                   -je 0x4c1b22
    if (cpu.flags.zf)
    {
        goto L_0x004c1b22;
    }
    // 004c1b0c  43                     -inc ebx
    (cpu.ebx)++;
    // 004c1b0d  39d3                   +cmp ebx, edx
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
    // 004c1b0f  7709                   -ja 0x4c1b1a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c1b1a;
    }
    // 004c1b11  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c1b13  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c1b15  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1b17  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004c1b19  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
L_0x004c1b1a:
    // 004c1b1a  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004c1b1c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c1b1e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c1b20  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004c1b22:
    // 004c1b22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1b23:
    // 004c1b23  39d1                   +cmp ecx, edx
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
    // 004c1b25  721c                   -jb 0x4c1b43
    if (cpu.flags.cf)
    {
        goto L_0x004c1b43;
    }
    // 004c1b27  7512                   -jne 0x4c1b3b
    if (!cpu.flags.zf)
    {
        goto L_0x004c1b3b;
    }
    // 004c1b29  39c3                   +cmp ebx, eax
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
    // 004c1b2b  770e                   -ja 0x4c1b3b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c1b3b;
    }
    // 004c1b2d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1b2f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1b31  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1b33  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1b35  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c1b3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1b3b:
    // 004c1b3b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1b3d  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1b3f  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004c1b40  87ca                   -xchg edx, ecx
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.ecx;
        cpu.ecx = tmp;
    }
    // 004c1b42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1b43:
    // 004c1b43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1b44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1b45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1b46  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c1b48  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c1b4a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004c1b4c:
    // 004c1b4c  01db                   +add ebx, ebx
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
    // 004c1b4e  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1b50  7213                   -jb 0x4c1b65
    if (cpu.flags.cf)
    {
        goto L_0x004c1b65;
    }
    // 004c1b52  45                     -inc ebp
    (cpu.ebp)++;
    // 004c1b53  39d1                   +cmp ecx, edx
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
    // 004c1b55  72f5                   -jb 0x4c1b4c
    if (cpu.flags.cf)
    {
        goto L_0x004c1b4c;
    }
    // 004c1b57  7704                   -ja 0x4c1b5d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c1b5d;
    }
    // 004c1b59  39c3                   +cmp ebx, eax
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
    // 004c1b5b  76ef                   -jbe 0x4c1b4c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c1b4c;
    }
L_0x004c1b5d:
    // 004c1b5d  f8                     +clc 
    cpu.flags.cf = 0;
L_0x004c1b5e:
    // 004c1b5e  11f6                   +adc esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1b60  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1b62  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004c1b63  7822                   -js 0x4c1b87
    if (cpu.flags.sf)
    {
        goto L_0x004c1b87;
    }
L_0x004c1b65:
    // 004c1b65  d1d9                   +rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c1b67  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c1b69  29d8                   +sub eax, ebx
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
    // 004c1b6b  19ca                   +sbb edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1b6d  f5                     +cmc 
    cpu.flags.cf ^= 1;
    // 004c1b6e  72ee                   -jb 0x4c1b5e
    if (cpu.flags.cf)
    {
        goto L_0x004c1b5e;
    }
L_0x004c1b70:
    // 004c1b70  01f6                   +add esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1b72  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1b74  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004c1b75  780c                   -js 0x4c1b83
    if (cpu.flags.sf)
    {
        goto L_0x004c1b83;
    }
    // 004c1b77  d1e9                   +shr ecx, 1
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
    // 004c1b79  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c1b7b  01d8                   +add eax, ebx
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
    // 004c1b7d  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c1b7f  73ef                   -jae 0x4c1b70
    if (!cpu.flags.cf)
    {
        goto L_0x004c1b70;
    }
    // 004c1b81  ebdb                   -jmp 0x4c1b5e
    goto L_0x004c1b5e;
L_0x004c1b83:
    // 004c1b83  01d8                   +add eax, ebx
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
    // 004c1b85  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
L_0x004c1b87:
    // 004c1b87  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1b89  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c1b8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c1b8d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004c1b8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1b92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c1ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1ba0  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c1ba3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1ba4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1ba5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1ba8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c1baa  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c1bad  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c1bb0  3b4508                 +cmp eax, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1bb3  7328                   -jae 0x4c1bdd
    if (!cpu.flags.cf)
    {
        goto L_0x004c1bdd;
    }
    // 004c1bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1bb6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1bba  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004c1bbd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c1bbf  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c1bc2  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c1bc5  39ca                   +cmp edx, ecx
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
    // 004c1bc7  731e                   -jae 0x4c1be7
    if (!cpu.flags.cf)
    {
        goto L_0x004c1be7;
    }
    // 004c1bc9  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c1bcc  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004c1bcf  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1bd1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c1bd3  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004c1bd5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1bd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1bd8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1bdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1bdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1bdd:
    // 004c1bdd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c1be2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1be5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1be6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1be7:
    // 004c1be7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1be8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1be9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004c1beb  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004c1bee  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1bf0  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c1bf3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004c1bf5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1bf7  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004c1bf9  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c1bfb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004c1bfd  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1bff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c1c01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1c02  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1c04  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1c07  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1c09  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1c0b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1c0e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1c10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c11  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1c15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c1c17  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c1c1a  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1c1c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1c1e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004c1c20  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1c22  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c1c24  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c1c26  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1c28  e8020afdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c1c2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c2f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1c31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c32  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1c35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1c36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4c1c38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1c38  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c1c3f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004c1c41  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004c1c43  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004c1c46  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004c1c49  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1c4d  c700a41b4c00           -mov dword ptr [eax], 0x4c1ba4
    app->getMemory<x86::reg32>(cpu.eax) = 4987812 /*0x4c1ba4*/;
    // 004c1c53  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1c57  c700a01b4c00           -mov dword ptr [eax], 0x4c1ba0
    app->getMemory<x86::reg32>(cpu.eax) = 4987808 /*0x4c1ba0*/;
    // 004c1c5d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004c1c62  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c1c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1c70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1c71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1c72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1c73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1c74  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1c77  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c1c79  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1c7b  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004c1c7e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c1c81  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c1c84  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004c1c86  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c1c88  39f1                   +cmp ecx, esi
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
    // 004c1c8a  765c                   -jbe 0x4c1ce8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c1ce8;
    }
L_0x004c1c8c:
    // 004c1c8c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c1c8e  7e69                   -jle 0x4c1cf9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c1cf9;
    }
    // 004c1c90  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004c1c93  2b5a04                 -sub ebx, dword ptr [edx + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004c1c96  43                     -inc ebx
    (cpu.ebx)++;
    // 004c1c97  39dd                   +cmp ebp, ebx
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
    // 004c1c99  7d02                   -jge 0x4c1c9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c1c9d;
    }
    // 004c1c9b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x004c1c9d:
    // 004c1c9d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004c1c9f  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004c1ca2  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004c1ca5  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004c1ca7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1ca9  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004c1cab  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004c1cae  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1cb0  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004c1cb2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c1cb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1cb5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1cb7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1cba  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1cbc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1cbe  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1cc1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1cc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1cc4  015a04                 -add dword ptr [edx + 4], ebx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1cc7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c1cc9  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004c1ccc  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1cce  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1cd0  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004c1cd3  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004c1cd6  8b7a0c                 -mov edi, dword ptr [edx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004c1cd9  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004c1cdc  39f8                   +cmp eax, edi
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
    // 004c1cde  76ac                   -jbe 0x4c1c8c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c1c8c;
    }
    // 004c1ce0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004c1ce3  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c1ce6  eba4                   -jmp 0x4c1c8c
    goto L_0x004c1c8c;
L_0x004c1ce8:
    // 004c1ce8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c1ceb  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004c1cee  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c1cf0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c1cf2  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c1cf4  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 004c1cf6  016804                 -add dword ptr [eax + 4], ebp
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x004c1cf9:
    // 004c1cf9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1cfb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1cfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1cff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1d00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1d01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1d02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4c1d04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1d04  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c1d0b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004c1d0d  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004c1d10  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1d14  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004c1d17  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004c1d19  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004c1d1c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1d20  c700701c4c00           -mov dword ptr [eax], 0x4c1c70
    app->getMemory<x86::reg32>(cpu.eax) = 4988016 /*0x4c1c70*/;
    // 004c1d26  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 004c1d2b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4c1d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1d30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1d31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1d32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1d33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1d34  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1d37  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004c1d3b  833800                 +cmp dword ptr [eax], 0
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
    // 004c1d3e  0f8499000000           -je 0x4c1ddd
    if (cpu.flags.zf)
    {
        goto L_0x004c1ddd;
    }
    // 004c1d44  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1d46  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1d4a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c1d4e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c1d51  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c1d54  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1d56  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c1d58  39f2                   +cmp edx, esi
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
    // 004c1d5a  0f8e8a000000           -jle 0x4c1dea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c1dea;
    }
    // 004c1d60  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c1d63  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004c1d66:
    // 004c1d66  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004c1d6b  0f8e8e000000           -jle 0x4c1dff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c1dff;
    }
    // 004c1d71  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c1d74  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1d77  0f8d8c000000           -jge 0x4c1e09
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c1e09;
    }
L_0x004c1d7d:
    // 004c1d7d  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004c1d80  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c1d83  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1d87  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1d89  39f2                   +cmp edx, esi
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
    // 004c1d8b  0f8fc1000000           -jg 0x4c1e52
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c1e52;
    }
L_0x004c1d91:
    // 004c1d91  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1d95  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c1d97  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c1d9a  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c1d9d  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004c1da0  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004c1da2  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1da4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004c1da6  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c1da8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1da9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c1dab  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c1dae  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c1db0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c1db2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c1db5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c1db7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1db8  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1dbc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c1dbe  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c1dc1  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c1dc4  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c1dc6  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1dc8  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1dca  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1dce  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004c1dd2  01c1                   +add ecx, eax
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
    // 004c1dd4  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004c1dd7  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004c1ddb  eb89                   -jmp 0x4c1d66
    goto L_0x004c1d66;
L_0x004c1ddd:
    // 004c1ddd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c1de2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1de5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1de6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1de7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1de8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1de9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1dea:
    // 004c1dea  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c1ded  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c1df0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c1df2  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004c1df4  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c1df6  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004c1df8  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1dfc  015008                 -add dword ptr [eax + 8], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004c1dff:
    // 004c1dff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1e01  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1e04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1e09:
    // 004c1e09  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004c1e0c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c1e0e  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c1e14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c1e16  750e                   -jne 0x4c1e26
    if (!cpu.flags.zf)
    {
        goto L_0x004c1e26;
    }
    // 004c1e18  837d0000               +cmp dword ptr [ebp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1e1c  7408                   -je 0x4c1e26
    if (cpu.flags.zf)
    {
        goto L_0x004c1e26;
    }
    // 004c1e1e  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c1e21  e957ffffff             -jmp 0x4c1d7d
    goto L_0x004c1d7d;
L_0x004c1e26:
    // 004c1e26  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1e2a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c1e2e  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c1e31  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1e33  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004c1e35  e8f507fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c1e3a  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004c1e41  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c1e48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1e4a  83c40c                 +add esp, 0xc
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
    // 004c1e4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1e51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1e52:
    // 004c1e52  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004c1e54  e938ffffff             -jmp 0x4c1d91
    goto L_0x004c1d91;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4c1e5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1e5c  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 004c1e62  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c1e69  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004c1e6b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004c1e72  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004c1e75  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004c1e7a  c703301d4c00           -mov dword ptr [ebx], 0x4c1d30
    app->getMemory<x86::reg32>(cpu.ebx) = 4988208 /*0x4c1d30*/;
    // 004c1e80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c1e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1e90  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c1e93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c1e94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1e94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1e95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1e96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1e97  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004c1e99  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c1e9c  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c1e9f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c1ea1  39ca                   +cmp edx, ecx
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
    // 004c1ea3  7338                   -jae 0x4c1edd
    if (!cpu.flags.cf)
    {
        goto L_0x004c1edd;
    }
    // 004c1ea5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1ea6  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004c1ea9  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004c1eac  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004c1eae  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c1eb1  39cf                   +cmp edi, ecx
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
    // 004c1eb3  734d                   -jae 0x4c1f02
    if (!cpu.flags.cf)
    {
        goto L_0x004c1f02;
    }
    // 004c1eb5  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1eb9  742b                   -je 0x4c1ee6
    if (cpu.flags.zf)
    {
        goto L_0x004c1ee6;
    }
    // 004c1ebb  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1ebd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1ebe  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c1ec1  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c1ec3  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c1ec5  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1ec7  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004c1eca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1ecb  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004c1ecd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1ece  e8d5210000             -call 0x4c40a8
    cpu.esp -= 4;
    sub_4c40a8(app, cpu);
    if (cpu.terminate) return;
L_0x004c1ed3:
    // 004c1ed3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1ed6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1ed8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1ed9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1eda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1edb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1edc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1edd:
    // 004c1edd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c1ee2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1ee3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1ee4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1ee5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1ee6:
    // 004c1ee6  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1ee8  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c1eeb  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c1eed  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c1eef  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004c1ef1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1ef2  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c1ef4  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004c1ef7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1ef8  d3e6                   +shl esi, cl
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
    // 004c1efa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1efb  e814220000             -call 0x4c4114
    cpu.esp -= 4;
    sub_4c4114(app, cpu);
    if (cpu.terminate) return;
    // 004c1f00  ebd1                   -jmp 0x4c1ed3
    goto L_0x004c1ed3;
L_0x004c1f02:
    // 004c1f02  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004c1f04  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004c1f07  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1f09  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c1f0b  7440                   -je 0x4c1f4d
    if (cpu.flags.zf)
    {
        goto L_0x004c1f4d;
    }
    // 004c1f0d  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1f0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1f10  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c1f13  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c1f15  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c1f17  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1f19  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004c1f1c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c1f1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1f1f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1f21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1f22  e881210000             -call 0x4c40a8
    cpu.esp -= 4;
    sub_4c40a8(app, cpu);
    if (cpu.terminate) return;
L_0x004c1f27:
    // 004c1f27  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1f2a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c1f2c  8a4d10                 -mov cl, byte ptr [ebp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004c1f2f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1f31  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004c1f33  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004c1f35  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004c1f37  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1f39  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c1f3b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1f3d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c1f3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c1f41  e8e906fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c1f46  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c1f48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1f49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1f4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1f4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1f4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c1f4d:
    // 004c1f4d  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1f4f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1f50  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c1f53  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c1f55  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c1f57  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c1f59  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004c1f5c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c1f5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c1f5f  d3e0                   +shl eax, cl
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
    // 004c1f61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1f62  e8ad210000             -call 0x4c4114
    cpu.esp -= 4;
    sub_4c4114(app, cpu);
    if (cpu.terminate) return;
    // 004c1f67  ebbe                   -jmp 0x4c1f27
    goto L_0x004c1f27;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4c1f6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1f6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1f6d  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c1f71  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c1f78  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004c1f7a  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004c1f7d  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 004c1f80  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004c1f83  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004c1f86  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004c1f89  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004c1f8c  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004c1f8f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c1f93  c700941e4c00           -mov dword ptr [eax], 0x4c1e94
    app->getMemory<x86::reg32>(cpu.eax) = 4988564 /*0x4c1e94*/;
    // 004c1f99  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c1f9d  c700901e4c00           -mov dword ptr [eax], 0x4c1e90
    app->getMemory<x86::reg32>(cpu.eax) = 4988560 /*0x4c1e90*/;
    // 004c1fa3  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004c1fa8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c1fa9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4c1fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c1fb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c1fb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c1fb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c1fb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1fb4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c1fb6  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004c1fb8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c1fba  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004c1fbd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c1fbf  7e5a                   -jle 0x4c201b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c201b;
    }
L_0x004c1fc1:
    // 004c1fc1  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004c1fc4  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004c1fc7  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c1fca  39f7                   +cmp edi, esi
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
    // 004c1fcc  7d02                   -jge 0x4c1fd0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c1fd0;
    }
    // 004c1fce  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004c1fd0:
    // 004c1fd0  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c1fd4  744c                   -je 0x4c2022
    if (cpu.flags.zf)
    {
        goto L_0x004c2022;
    }
    // 004c1fd6  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c1fd9  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c1fdc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c1fde  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1fe0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c1fe1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c1fe3  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004c1fe6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1fe7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c1fe9  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c1feb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c1fec  e8b7200000             -call 0x4c40a8
    cpu.esp -= 4;
    sub_4c40a8(app, cpu);
    if (cpu.terminate) return;
L_0x004c1ff1:
    // 004c1ff1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c1ff4  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c1ff7  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c1ff9  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004c1ffc  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c1fff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c2001  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c2003  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004c2006  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c2008  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c200b  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c200d  39d0                   +cmp eax, edx
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
    // 004c200f  7606                   -jbe 0x4c2017
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c2017;
    }
    // 004c2011  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004c2014  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004c2017:
    // 004c2017  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004c2019  7fa6                   -jg 0x4c1fc1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c1fc1;
    }
L_0x004c201b:
    // 004c201b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c201d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c201e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c201f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2020  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2021  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2022:
    // 004c2022  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c2025  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c2028  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c202a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c202c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c202d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c202f  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004c2032  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c2033  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c2035  d3e0                   +shl eax, cl
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
    // 004c2037  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c2038  e8d7200000             -call 0x4c4114
    cpu.esp -= 4;
    sub_4c4114(app, cpu);
    if (cpu.terminate) return;
    // 004c203d  ebb2                   -jmp 0x4c1ff1
    goto L_0x004c1ff1;
}

/* align: skip 0x90 */
void Application::sub_4c2040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2040  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c2041  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c2045  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c204c  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004c204e  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004c2051  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c2055  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004c2058  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c205a  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004c205d  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004c2060  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004c2063  89701c                 -mov dword ptr [eax + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004c2066  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c206a  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004c206d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c2071  c700b01f4c00           -mov dword ptr [eax], 0x4c1fb0
    app->getMemory<x86::reg32>(cpu.eax) = 4988848 /*0x4c1fb0*/;
    // 004c2077  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004c207c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c207d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c2080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c2081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c2082  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c2083  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2084  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2087  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c2089  833800                 +cmp dword ptr [eax], 0
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
    // 004c208c  746e                   -je 0x4c20fc
    if (cpu.flags.zf)
    {
        goto L_0x004c20fc;
    }
    // 004c208e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c2090  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c2093  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c2096  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c2098  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c209a  39ca                   +cmp edx, ecx
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
    // 004c209c  7e6b                   -jle 0x4c2109
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c2109;
    }
    // 004c209e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c20a1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004c20a4:
    // 004c20a4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004c20a6  0f8e84000000           -jle 0x4c2130
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c2130;
    }
    // 004c20ac  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004c20af  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c20b2  0f8dad000000           -jge 0x4c2165
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c2165;
    }
L_0x004c20b8:
    // 004c20b8  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c20bb  2b5e08                 -sub ebx, dword ptr [esi + 8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 004c20be  39df                   +cmp edi, ebx
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
    // 004c20c0  7d02                   -jge 0x4c20c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c20c4;
    }
    // 004c20c2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x004c20c4:
    // 004c20c4  837e1400               +cmp dword ptr [esi + 0x14], 0
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
    // 004c20c8  0f84db000000           -je 0x4c21a9
    if (cpu.flags.zf)
    {
        goto L_0x004c21a9;
    }
    // 004c20ce  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004c20d1  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c20d4  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c20d6  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c20d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c20d9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c20db  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004c20de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c20df  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c20e1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c20e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c20e4  e8bf1f0000             -call 0x4c40a8
    cpu.esp -= 4;
    sub_4c40a8(app, cpu);
    if (cpu.terminate) return;
L_0x004c20e9:
    // 004c20e9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c20ec  015e08                 -add dword ptr [esi + 8], ebx
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c20ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c20f1  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004c20f4  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c20f6  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c20f8  01c5                   +add ebp, eax
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
    // 004c20fa  eba8                   -jmp 0x4c20a4
    goto L_0x004c20a4;
L_0x004c20fc:
    // 004c20fc  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c2101  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2104  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2105  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2106  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2107  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2108  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2109:
    // 004c2109  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c210d  742b                   -je 0x4c213a
    if (cpu.flags.zf)
    {
        goto L_0x004c213a;
    }
    // 004c210f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2110  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c2113  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c2116  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c2118  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004c211a  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004c211d  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c211f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c2121  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c2122  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c2124  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c2125  e87e1f0000             -call 0x4c40a8
    cpu.esp -= 4;
    sub_4c40a8(app, cpu);
    if (cpu.terminate) return;
    // 004c212a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c212d  017e08                 -add dword ptr [esi + 8], edi
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004c2130:
    // 004c2130  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c2132  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2135  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2136  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2137  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2138  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2139  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c213a:
    // 004c213a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c213b  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c213e  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004c2141  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c2143  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c2145  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004c2148  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c214a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c214c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c214d  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c214f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c2150  e8bf1f0000             -call 0x4c4114
    cpu.esp -= 4;
    sub_4c4114(app, cpu);
    if (cpu.terminate) return;
    // 004c2155  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c2158  017e08                 -add dword ptr [esi + 8], edi
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c215b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c215d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2160  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2161  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2163  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2164  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2165:
    // 004c2165  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004c2168  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c216a  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c2170  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2172  750d                   -jne 0x4c2181
    if (!cpu.flags.zf)
    {
        goto L_0x004c2181;
    }
    // 004c2174  833e00                 +cmp dword ptr [esi], 0
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
    // 004c2177  7408                   -je 0x4c2181
    if (cpu.flags.zf)
    {
        goto L_0x004c2181;
    }
    // 004c2179  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c217c  e937ffffff             -jmp 0x4c20b8
    goto L_0x004c20b8;
L_0x004c2181:
    // 004c2181  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004c2183  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c2185  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004c2188  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c218a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004c218c  e89e04fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c2191  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004c2198  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c219f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c21a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c21a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c21a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c21a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c21a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c21a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c21a9:
    // 004c21a9  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004c21ac  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c21af  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c21b1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004c21b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c21b4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c21b6  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004c21b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c21ba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c21bc  d3e0                   +shl eax, cl
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
    // 004c21be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c21bf  e8501f0000             -call 0x4c4114
    cpu.esp -= 4;
    sub_4c4114(app, cpu);
    if (cpu.terminate) return;
    // 004c21c4  e920ffffff             -jmp 0x4c20e9
    goto L_0x004c20e9;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4c21cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c21cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c21cd  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 004c21d3  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c21da  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004c21e1  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004c21e4  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004c21e7  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004c21ea  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004c21ed  897010                 -mov dword ptr [eax + 0x10], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004c21f0  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004c21f3  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004c21f8  c70180204c00           -mov dword ptr [ecx], 0x4c2080
    app->getMemory<x86::reg32>(cpu.ecx) = 4989056 /*0x4c2080*/;
    // 004c21fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c21ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2200  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2201  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c2203  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004c2204  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c2207  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004c220a  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c220d  0f6e5e04               -movd mm3, dword ptr [esi + 4]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) };
    // 004c2211  ba0000ff7f             -mov edx, 0x7fff0000
    cpu.edx = 2147418112 /*0x7fff0000*/;
    // 004c2216  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 004c221b  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004c221e  0f6ee8                 -movd mm5, eax
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004c2221  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004c2223:
    // 004c2223  833e00                 +cmp dword ptr [esi], 0
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
    // 004c2226  0f8ea3000000           -jle 0x4c22cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c22cf;
    }
    // 004c222c  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c222e  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c2230  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004c2233  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004c2236  83c338                 -add ebx, 0x38
    (cpu.ebx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004c2239  0f6e0c8558054e00       -movd mm1, dword ptr [eax*4 + 0x4e0558]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5113176) /* 0x4e0558 */ + cpu.eax * 4)) };
    // 004c2241  0f6e148568054e00       -movd mm2, dword ptr [eax*4 + 0x4e0568]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5113192) /* 0x4e0568 */ + cpu.eax * 4)) };
    // 004c2249  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c224b  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 004c2250  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004c2253  83c70f                 -add edi, 0xf
    (cpu.edi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004c2256  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004c2259:
    // 004c2259  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004c225c  0f6ff3                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 004c225f  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 004c2262  0ff5f1                 -pmaddwd mm6, mm1
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm1) };
    // 004c2265  0f6e849064985b00       -movd mm0, dword ptr [eax + edx*4 + 0x5b9864]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6002788) /* 0x5b9864 */ + cpu.edx * 4)) };
    // 004c226d  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 004c2270  0f7ef5                 -movd ebp, mm6
    cpu.ebp = _mm_cvtsi128_si32(cpu.mmx.mm6);
    // 004c2273  81fd00ff7f00           +cmp ebp, 0x7fff00
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388352 /*0x7fff00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2279  7f5e                   -jg 0x4c22d9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c22d9;
    }
    // 004c227b  81fd000080ff           +cmp ebp, 0xff800000
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2281  7c5b                   -jl 0x4c22de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c22de;
    }
    // 004c2283  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
L_0x004c2287:
    // 004c2287  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004c228a  0f61f3                 -punpcklwd mm6, mm3
    cpu.mmx.mm6 = { _mm_unpacklo_epi16(cpu.mmx.mm6, cpu.mmx.mm3) };
    // 004c228d  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004c2290  0f73d620               -psrlq mm6, 0x20
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 32 /*0x20*/) };
    // 004c2294  0f6fde                 -movq mm3, mm6
    cpu.mmx.mm3 = cpu.mmx.mm6;
    // 004c2297  0ff5f2                 -pmaddwd mm6, mm2
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm2) };
    // 004c229a  0f6e849064985b00       -movd mm0, dword ptr [eax + edx*4 + 0x5b9864]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6002788) /* 0x5b9864 */ + cpu.edx * 4)) };
    // 004c22a2  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 004c22a5  0f7ef5                 -movd ebp, mm6
    cpu.ebp = _mm_cvtsi128_si32(cpu.mmx.mm6);
    // 004c22a8  81fd00ff7f00           +cmp ebp, 0x7fff00
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388352 /*0x7fff00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c22ae  7f33                   -jg 0x4c22e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c22e3;
    }
    // 004c22b0  81fd000080ff           +cmp ebp, 0xff800000
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c22b6  7c30                   -jl 0x4c22e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c22e8;
    }
    // 004c22b8  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
L_0x004c22bc:
    // 004c22bc  0f73d610               -psrlq mm6, 0x10
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 16 /*0x10*/) };
    // 004c22c0  0f61de                 -punpcklwd mm3, mm6
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 004c22c3  0f7e1c8b               -movd dword ptr [ebx + ecx*4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4), cpu.mmx.mm3);
    // 004c22c7  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c22c8  7c8f                   -jl 0x4c2259
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c2259;
    }
    // 004c22ca  e954ffffff             -jmp 0x4c2223
    goto L_0x004c2223;
L_0x004c22cf:
    // 004c22cf  0f7e5e04               -movd dword ptr [esi + 4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */), cpu.mmx.mm3);
    // 004c22d3  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004c22d6  61                     -popal 
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
    // 004c22d7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c22d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c22d9:
    // 004c22d9  0f6ff4                 -movq mm6, mm4
    cpu.mmx.mm6 = cpu.mmx.mm4;
    // 004c22dc  eba9                   -jmp 0x4c2287
    goto L_0x004c2287;
L_0x004c22de:
    // 004c22de  0f6ff5                 -movq mm6, mm5
    cpu.mmx.mm6 = cpu.mmx.mm5;
    // 004c22e1  eba4                   -jmp 0x4c2287
    goto L_0x004c2287;
L_0x004c22e3:
    // 004c22e3  0f6ff4                 -movq mm6, mm4
    cpu.mmx.mm6 = cpu.mmx.mm4;
    // 004c22e6  ebd4                   -jmp 0x4c22bc
    goto L_0x004c22bc;
L_0x004c22e8:
    // 004c22e8  0f6ff5                 -movq mm6, mm5
    cpu.mmx.mm6 = cpu.mmx.mm5;
    // 004c22eb  ebcf                   -jmp 0x4c22bc
    goto L_0x004c22bc;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4c22f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c22f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c22f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c22f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c22f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c22f4  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c22f7  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004c22fb  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c22fe  8b4302                 -mov eax, dword ptr [ebx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004c2301  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004c2304  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004c2307  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c2309  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004c230d  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004c2310  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004c2313  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004c2316  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004c2319  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c231d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c231f  0f8ee5010000           -jle 0x4c250a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c250a;
    }
L_0x004c2325:
    // 004c2325  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c2327  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004c232a  83ed1c                 -sub ebp, 0x1c
    (cpu.ebp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004c232d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c232f  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004c2331  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c2333  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004c2336  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004c233a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c233c  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004c233f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2345  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004c2349  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004c234d  8b0c95fc0a4e00         -mov ecx, dword ptr [edx*4 + 0x4e0afc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114620) /* 0x4e0afc */ + cpu.edx * 4);
    // 004c2354  8b14950c0b4e00         -mov edx, dword ptr [edx*4 + 0x4e0b0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114636) /* 0x4e0b0c */ + cpu.edx * 4);
    // 004c235b  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004c235f  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004c2363  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004c2367  8b0c95fc0a4e00         -mov ecx, dword ptr [edx*4 + 0x4e0afc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114620) /* 0x4e0afc */ + cpu.edx * 4);
    // 004c236e  8b14950c0b4e00         -mov edx, dword ptr [edx*4 + 0x4e0b0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114636) /* 0x4e0b0c */ + cpu.edx * 4);
    // 004c2375  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004c2379  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c237b  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c237e  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004c2381  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c2384  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004c2388  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c238b  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004c238f  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004c2392  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2398  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c239b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c239e  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004c23a2  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c23a5  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c23a8  83c270                 -add edx, 0x70
    (cpu.edx) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004c23ab  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c23ae  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c23b1  39d0                   +cmp eax, edx
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
    // 004c23b3  0f8348010000           -jae 0x4c2501
    if (!cpu.flags.cf)
    {
        goto L_0x004c2501;
    }
L_0x004c23b9:
    // 004c23b9  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004c23bc  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004c23be  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c23c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c23c5  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004c23c8  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004c23cc  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 004c23cf  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004c23d1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c23d3  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004c23d7  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004c23da  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c23de  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c23e0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c23e4  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004c23e7  c1e01c                 -shl eax, 0x1c
    cpu.eax <<= 28 /*0x1c*/ % 32;
    // 004c23ea  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c23ec  8a4c2428               -mov cl, byte ptr [esp + 0x28]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004c23f0  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004c23f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c23f4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004c23f8  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004c23fb  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004c23ff  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c2401  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c2405  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004c2408  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c240a  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004c2410  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004c2415  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004c2418  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004c241b  81fa0080ffff           +cmp edx, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2421  0f8d03010000           -jge 0x4c252a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c252a;
    }
    // 004c2427  ba0080ffff             -mov edx, 0xffff8000
    cpu.edx = 4294934528 /*0xffff8000*/;
L_0x004c242c:
    // 004c242c  3d0080ffff             +cmp eax, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2431  0f8d09010000           -jge 0x4c2540
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c2540;
    }
    // 004c2437  b80080ffff             -mov eax, 0xffff8000
    cpu.eax = 4294934528 /*0xffff8000*/;
L_0x004c243c:
    // 004c243c  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c243f  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 004c2442  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c2445  66894102               -mov word ptr [ecx + 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004c2449  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004c244c  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004c2450  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c2454  8a4901                 -mov cl, byte ptr [ecx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004c2457  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c245d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004c2461  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 004c2464  c1e11c                 -shl ecx, 0x1c
    cpu.ecx <<= 28 /*0x1c*/ % 32;
    // 004c2467  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004c246b  8a4c2424               -mov cl, byte ptr [esp + 0x24]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004c246f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c2473  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 004c2475  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004c2477  0faf542420             -imul edx, dword ptr [esp + 0x20]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 004c247c  0faf442418             -imul eax, dword ptr [esp + 0x18]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004c2481  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c2483  0faf742414             -imul esi, dword ptr [esp + 0x14]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 004c2488  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c248a  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c248e  8a4c2428               -mov cl, byte ptr [esp + 0x28]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004c2492  c1e61c                 -shl esi, 0x1c
    cpu.esi <<= 28 /*0x1c*/ % 32;
    // 004c2495  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004c2497  0faf7c241c             -imul edi, dword ptr [esp + 0x1c]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 004c249c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c249e  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c24a0  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004c24a6  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004c24ab  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004c24ae  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004c24b1  81fa0080ffff           +cmp edx, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c24b7  0f8d98000000           -jge 0x4c2555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c2555;
    }
    // 004c24bd  ba0080ffff             -mov edx, 0xffff8000
    cpu.edx = 4294934528 /*0xffff8000*/;
L_0x004c24c2:
    // 004c24c2  3d0080ffff             +cmp eax, 0xffff8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c24c7  0f8d9e000000           -jge 0x4c256b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c256b;
    }
    // 004c24cd  b80080ffff             -mov eax, 0xffff8000
    cpu.eax = 4294934528 /*0xffff8000*/;
L_0x004c24d2:
    // 004c24d2  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c24d5  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004c24d9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004c24db  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c24de  66894206               -mov word ptr [edx + 6], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004c24e2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c24e4  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004c24e7  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c24ea  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c24ed  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c24f0  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004c24f3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004c24f6  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004c24f9  39d5                   +cmp ebp, edx
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
    // 004c24fb  0f82b8feffff           -jb 0x4c23b9
    if (cpu.flags.cf)
    {
        goto L_0x004c23b9;
    }
L_0x004c2501:
    // 004c2501  833b00                 +cmp dword ptr [ebx], 0
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
    // 004c2504  0f8f1bfeffff           -jg 0x4c2325
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c2325;
    }
L_0x004c250a:
    // 004c250a  66897306               -mov word ptr [ebx + 6], si
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.si;
    // 004c250e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c2512  66897b0a               -mov word ptr [ebx + 0xa], di
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.di;
    // 004c2516  66894304               -mov word ptr [ebx + 4], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004c251a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c251e  66894308               -mov word ptr [ebx + 8], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004c2522  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004c2525  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2526  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2527  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2528  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2529  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c252a:
    // 004c252a  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2530  0f8ef6feffff           -jle 0x4c242c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c242c;
    }
    // 004c2536  baff7f0000             -mov edx, 0x7fff
    cpu.edx = 32767 /*0x7fff*/;
    // 004c253b  e9ecfeffff             -jmp 0x4c242c
    goto L_0x004c242c;
L_0x004c2540:
    // 004c2540  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2545  0f8ef1feffff           -jle 0x4c243c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c243c;
    }
    // 004c254b  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
    // 004c2550  e9e7feffff             -jmp 0x4c243c
    goto L_0x004c243c;
L_0x004c2555:
    // 004c2555  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c255b  0f8e61ffffff           -jle 0x4c24c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c24c2;
    }
    // 004c2561  baff7f0000             -mov edx, 0x7fff
    cpu.edx = 32767 /*0x7fff*/;
    // 004c2566  e957ffffff             -jmp 0x4c24c2
    goto L_0x004c24c2;
L_0x004c256b:
    // 004c256b  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2570  0f8e5cffffff           -jle 0x4c24d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c24d2;
    }
    // 004c2576  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
    // 004c257b  e952ffffff             -jmp 0x4c24d2
    goto L_0x004c24d2;
}

/* align: skip  */
void Application::sub_4c2580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2580  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2581  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c2583  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004c2584  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c2587  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c258a  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004c258d  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c2590  89151c0b4e00           -mov dword ptr [0x4e0b1c], edx
    app->getMemory<x86::reg32>(x86::reg32(5114652) /* 0x4e0b1c */) = cpu.edx;
    // 004c2596  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004c2599  8915200b4e00           -mov dword ptr [0x4e0b20], edx
    app->getMemory<x86::reg32>(x86::reg32(5114656) /* 0x4e0b20 */) = cpu.edx;
L_0x004c259f:
    // 004c259f  833e00                 +cmp dword ptr [esi], 0
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
    // 004c25a2  0f8ea7000000           -jle 0x4c264f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c264f;
    }
    // 004c25a8  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004c25ab  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c25ad  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c25af  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004c25b2  d9048548054e00         -fld dword ptr [eax*4 + 0x4e0548]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5113160) /* 0x4e0548 */ + cpu.eax * 4)));
    // 004c25b9  d9048538054e00         -fld dword ptr [eax*4 + 0x4e0538]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5113144) /* 0x4e0538 */ + cpu.eax * 4)));
    // 004c25c0  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c25c2  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004c25c5  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 004c25c8  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004c25cb  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c25cd  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 004c25d2  d905200b4e00           -fld dword ptr [0x4e0b20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114656) /* 0x4e0b20 */)));
    // 004c25d8  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004c25da  d9051c0b4e00           -fld dword ptr [0x4e0b1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114652) /* 0x4e0b1c */)));
    // 004c25e0  d9051c0b4e00           -fld dword ptr [0x4e0b1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114652) /* 0x4e0b1c */)));
    // 004c25e6  d905200b4e00           -fld dword ptr [0x4e0b20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114656) /* 0x4e0b20 */)));
    // 004c25ec  83c70e                 -add edi, 0xe
    (cpu.edi) += x86::reg32(x86::sreg32(14 /*0xe*/));
    // 004c25ef  83c370                 -add ebx, 0x70
    (cpu.ebx) += x86::reg32(x86::sreg32(112 /*0x70*/));
L_0x004c25f2:
    // 004c25f2  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c25f4  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004c25f6  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004c25f9  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 004c25fc  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c25fe  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004c2600  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2602  d8849064945b00         -fadd dword ptr [eax + edx*4 + 0x5b9464]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(6001764) /* 0x5b9464 */ + cpu.edx * 4));
    // 004c2609  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c260b  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 004c260e  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c2610  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c2612  d914cb                 -fst dword ptr [ebx + ecx*8]
    app->getMemory<float>(cpu.ebx + cpu.ecx * 8) = float(cpu.fpu.st(0));
    // 004c2615  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004c2617  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2619  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004c261b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c261d  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c261f  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 004c2622  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c2624  d8849064945b00         +fadd dword ptr [eax + edx*4 + 0x5b9464]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(6001764) /* 0x5b9464 */ + cpu.edx * 4));
    // 004c262b  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c262d  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c262f  d954cb04               +fst dword ptr [ebx + ecx*8 + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8) = float(cpu.fpu.st(0));
    // 004c2633  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004c2635  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c2636  7cba                   -jl 0x4c25f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c25f2;
    }
    // 004c2638  d91d200b4e00           +fstp dword ptr [0x4e0b20]
    app->getMemory<float>(x86::reg32(5114656) /* 0x4e0b20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c263e  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2640  d91d1c0b4e00           +fstp dword ptr [0x4e0b1c]
    app->getMemory<float>(x86::reg32(5114652) /* 0x4e0b1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2646  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004c2648  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c264a  e950ffffff             -jmp 0x4c259f
    goto L_0x004c259f;
L_0x004c264f:
    // 004c264f  8b151c0b4e00           -mov edx, dword ptr [0x4e0b1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114652) /* 0x4e0b1c */);
    // 004c2655  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c2658  8b15200b4e00           -mov edx, dword ptr [0x4e0b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114656) /* 0x4e0b20 */);
    // 004c265e  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004c2661  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004c2664  61                     -popal 
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
    // 004c2665  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2666  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c2668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2668  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2669  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c266b  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004c266c  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c266f  8b7e14                 -mov edi, dword ptr [esi + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004c2672  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004c2675  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c2678  8915240b4e00           -mov dword ptr [0x4e0b24], edx
    app->getMemory<x86::reg32>(x86::reg32(5114660) /* 0x4e0b24 */) = cpu.edx;
    // 004c267e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004c2681  8915280b4e00           -mov dword ptr [0x4e0b28], edx
    app->getMemory<x86::reg32>(x86::reg32(5114664) /* 0x4e0b28 */) = cpu.edx;
    // 004c2687  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c268a  89152c0b4e00           -mov dword ptr [0x4e0b2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5114668) /* 0x4e0b2c */) = cpu.edx;
    // 004c2690  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004c2693  8915300b4e00           -mov dword ptr [0x4e0b30], edx
    app->getMemory<x86::reg32>(x86::reg32(5114672) /* 0x4e0b30 */) = cpu.edx;
L_0x004c2699:
    // 004c2699  833e00                 +cmp dword ptr [esi], 0
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
    // 004c269c  0f8e17010000           -jle 0x4c27b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c27b9;
    }
    // 004c26a2  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004c26a5  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c26a7  33db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c26a9  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c26ab  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004c26ad  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004c26b0  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004c26b3  d9049d48054e00         -fld dword ptr [ebx*4 + 0x4e0548]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5113160) /* 0x4e0548 */ + cpu.ebx * 4)));
    // 004c26ba  d9049d38054e00         -fld dword ptr [ebx*4 + 0x4e0538]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5113144) /* 0x4e0538 */ + cpu.ebx * 4)));
    // 004c26c1  d9048548054e00         -fld dword ptr [eax*4 + 0x4e0548]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5113160) /* 0x4e0548 */ + cpu.eax * 4)));
    // 004c26c8  d9048538054e00         -fld dword ptr [eax*4 + 0x4e0538]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5113144) /* 0x4e0538 */ + cpu.eax * 4)));
    // 004c26cf  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c26d2  8a5f01                 -mov bl, byte ptr [edi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c26d5  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004c26d8  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004c26db  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 004c26de  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 004c26e1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c26e4  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c26e6  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004c26eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c26ec  8bf3                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x004c26ee:
    // 004c26ee  d905240b4e00           -fld dword ptr [0x4e0b24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114660) /* 0x4e0b24 */)));
    // 004c26f4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004c26f6  d9052c0b4e00           -fld dword ptr [0x4e0b2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114668) /* 0x4e0b2c */)));
    // 004c26fc  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004c26fe  d905280b4e00           -fld dword ptr [0x4e0b28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114664) /* 0x4e0b28 */)));
    // 004c2704  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004c2706  d905300b4e00           -fld dword ptr [0x4e0b30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114672) /* 0x4e0b30 */)));
    // 004c270c  d8cf                   -fmul st(7)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(7));
    // 004c270e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2710  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2712  8a17                   -mov dl, byte ptr [edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi);
    // 004c2714  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004c2716  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 004c2719  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004c271c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c271e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2720  d8849064945b00         -fadd dword ptr [eax + edx*4 + 0x5b9464]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(6001764) /* 0x5b9464 */ + cpu.edx * 4));
    // 004c2727  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2729  d8849e64945b00         -fadd dword ptr [esi + ebx*4 + 0x5b9464]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(6001764) /* 0x5b9464 */ + cpu.ebx * 4));
    // 004c2730  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2732  d95500                 -fst dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    // 004c2735  d91d280b4e00           -fstp dword ptr [0x4e0b28]
    app->getMemory<float>(x86::reg32(5114664) /* 0x4e0b28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c273b  d95504                 -fst dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 004c273e  d91d300b4e00           -fstp dword ptr [0x4e0b30]
    app->getMemory<float>(x86::reg32(5114672) /* 0x4e0b30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2744  d905280b4e00           -fld dword ptr [0x4e0b28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114664) /* 0x4e0b28 */)));
    // 004c274a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004c274c  d905300b4e00           -fld dword ptr [0x4e0b30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114672) /* 0x4e0b30 */)));
    // 004c2752  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004c2754  d905240b4e00           -fld dword ptr [0x4e0b24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114660) /* 0x4e0b24 */)));
    // 004c275a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004c275c  d9052c0b4e00           -fld dword ptr [0x4e0b2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114668) /* 0x4e0b2c */)));
    // 004c2762  d8cf                   -fmul st(7)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(7));
    // 004c2764  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2766  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2768  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c276b  8a5f01                 -mov bl, byte ptr [edi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c276e  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 004c2771  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004c2774  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2776  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2778  d8849064945b00         -fadd dword ptr [eax + edx*4 + 0x5b9464]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(6001764) /* 0x5b9464 */ + cpu.edx * 4));
    // 004c277f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2781  d8849e64945b00         -fadd dword ptr [esi + ebx*4 + 0x5b9464]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(6001764) /* 0x5b9464 */ + cpu.ebx * 4));
    // 004c2788  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c278a  d95508                 -fst dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 004c278d  d91d240b4e00           -fstp dword ptr [0x4e0b24]
    app->getMemory<float>(x86::reg32(5114660) /* 0x4e0b24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2793  d9550c                 -fst dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    // 004c2796  d91d2c0b4e00           -fstp dword ptr [0x4e0b2c]
    app->getMemory<float>(x86::reg32(5114668) /* 0x4e0b2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c279c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c279f  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c27a2  83e902                 +sub ecx, 2
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
    // 004c27a5  0f8f43ffffff           -jg 0x4c26ee
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c26ee;
    }
    // 004c27ab  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c27ad  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c27af  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c27b1  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c27b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c27b4  e9e0feffff             -jmp 0x4c2699
    goto L_0x004c2699;
L_0x004c27b9:
    // 004c27b9  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004c27bc  8b15240b4e00           -mov edx, dword ptr [0x4e0b24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114660) /* 0x4e0b24 */);
    // 004c27c2  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c27c5  8b15280b4e00           -mov edx, dword ptr [0x4e0b28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114664) /* 0x4e0b28 */);
    // 004c27cb  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004c27ce  8b152c0b4e00           -mov edx, dword ptr [0x4e0b2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114668) /* 0x4e0b2c */);
    // 004c27d4  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004c27d7  8b15300b4e00           -mov edx, dword ptr [0x4e0b30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114672) /* 0x4e0b30 */);
    // 004c27dd  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004c27e0  61                     -popal 
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
    // 004c27e1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c27e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4c27f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c27f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c27f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c27f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c27f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c27f4  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c27f7  8b1c95340b4e00         -mov ebx, dword ptr [edx*4 + 0x4e0b34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114676) /* 0x4e0b34 */ + cpu.edx * 4);
    // 004c27fe  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c2801  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c2804  21cb                   -and ebx, ecx
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c2806  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2808  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004c280a  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004c280d  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 004c280f  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004c2812  83ff08                 +cmp edi, 8
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
    // 004c2815  7c07                   -jl 0x4c281e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c281e;
    }
    // 004c2817  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c2819  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c281a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c281b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c281c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c281d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c281e:
    // 004c281e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c2820  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c2822  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2828  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c282b  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004c282d  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c2830  46                     -inc esi
    (cpu.esi)++;
    // 004c2831  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c2834  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004c2836  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c2838  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c283b  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004c283e  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2840  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004c2843  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c2845  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2846  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2847  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2848  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2849  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4c284c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c284c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c284d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c284e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c284f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2850  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004c2852  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c2855  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c2858  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 004c285a  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c285c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004c285f  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004c2862  83fe08                 +cmp esi, 8
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
    // 004c2865  7c05                   -jl 0x4c286c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c286c;
    }
    // 004c2867  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2868  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2869  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c286a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c286b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c286c:
    // 004c286c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c286e  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c2870  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2876  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c2879  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004c287c  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004c287e  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c2881  09d5                   -or ebp, edx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2883  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c2886  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c2888  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004c288b  42                     -inc edx
    (cpu.edx)++;
    // 004c288c  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004c288f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004c2891  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2892  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2893  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2894  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2895  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4c28a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004c28a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c28a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c28aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c28ab  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c28ae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c28b0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004c28b2  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004c28b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c28b6  753a                   -jne 0x4c28f2
    if (!cpu.flags.zf)
    {
        goto L_0x004c28f2;
    }
    // 004c28b8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c28ba  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
L_0x004c28bf:
    // 004c28bf  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c28c2  21d8                   -and eax, ebx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c28c4  83f803                 +cmp eax, 3
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
    // 004c28c7  771b                   -ja 0x4c28e4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c28e4;
    }
    // 004c28c9  ff248598284c00         -jmp dword ptr [eax*4 + 0x4c2898]
    cpu.ip = app->getMemory<x86::reg32>(4991128 + cpu.eax * 4); goto dynamic_jump;
  case 0x004c28d0:
    // 004c28d0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c28d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c28d7  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
L_0x004c28df:
    // 004c28df  e868ffffff             -call 0x4c284c
    cpu.esp -= 4;
    sub_4c284c(app, cpu);
    if (cpu.terminate) return;
L_0x004c28e4:
    // 004c28e4  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c28e6  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c28e9  7cd4                   -jl 0x4c28bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c28bf;
    }
    // 004c28eb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c28ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c28ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c28f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c28f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c28f2:
    // 004c28f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c28f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c28f6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x004c28f9:
    // 004c28f9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c28fc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004c28ff  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c2904  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004c2907  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c2909  8a9c02580c4e00         -mov bl, byte ptr [edx + eax + 0x4e0c58]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5114968) /* 0x4e0c58 */ + cpu.eax * 1);
    // 004c2910  6bc30c                 -imul eax, ebx, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 004c2913  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c2917  8b80580e4e00           -mov eax, dword ptr [eax + 0x4e0e58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5115480) /* 0x4e0e58 */);
    // 004c291d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c2921  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004c2924  8b925c0e4e00           -mov edx, dword ptr [edx + 0x4e0e5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5115484) /* 0x4e0e5c */);
    // 004c292a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c292c  e81bffffff             -call 0x4c284c
    cpu.esp -= 4;
    sub_4c284c(app, cpu);
    if (cpu.terminate) return;
    // 004c2931  83fb03                 +cmp ebx, 3
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
    // 004c2934  7e1c                   -jle 0x4c2952
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c2952;
    }
    // 004c2936  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c293a  8b82600e4e00           -mov eax, dword ptr [edx + 0x4e0e60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5115488) /* 0x4e0e60 */);
    // 004c2940  89448d00               -mov dword ptr [ebp + ecx*4], eax
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = cpu.eax;
    // 004c2944  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004c2946:
    // 004c2946  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2949  7cae                   -jl 0x4c28f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c28f9;
    }
    // 004c294b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c294e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c294f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2950  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2951  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2952:
    // 004c2952  83fb01                 +cmp ebx, 1
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
    // 004c2955  7f1a                   -jg 0x4c2971
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c2971;
    }
    // 004c2957  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
L_0x004c295c:
    // 004c295c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c2961  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c2963  e888feffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c2968  83f801                 +cmp eax, 1
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
    // 004c296b  7560                   -jne 0x4c29cd
    if (!cpu.flags.zf)
    {
        goto L_0x004c29cd;
    }
    // 004c296d  01c3                   +add ebx, eax
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
    // 004c296f  ebeb                   -jmp 0x4c295c
    goto L_0x004c295c;
L_0x004c2971:
    // 004c2971  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004c2976  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c2978  e873feffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c297d  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004c2980  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c2984  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004c2987  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c2989  83f86c                 +cmp eax, 0x6c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c298c  7e12                   -jle 0x4c29a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c29a0;
    }
    // 004c298e  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 004c2993  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c2995  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c2997  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004c299a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004c299c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004c29a0:
    // 004c29a0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c29a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c29a6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c29a8  7e9c                   -jle 0x4c2946
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c2946;
    }
    // 004c29aa  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004c29ae:
    // 004c29ae  40                     -inc eax
    (cpu.eax)++;
    // 004c29af  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
    // 004c29b7  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c29b9  39d0                   +cmp eax, edx
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
    // 004c29bb  7cf1                   -jl 0x4c29ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c29ae;
    }
    // 004c29bd  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c29c0  0f8c33ffffff           -jl 0x4c28f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c28f9;
    }
    // 004c29c6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c29c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c29ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c29cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c29cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c29cd:
    // 004c29cd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c29d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c29d4  e817feffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c29d9  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004c29e0  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004c29e2  83f801                 +cmp eax, 1
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
    // 004c29e5  751c                   -jne 0x4c2a03
    if (!cpu.flags.zf)
    {
        goto L_0x004c2a03;
    }
    // 004c29e7  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004c29eb  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004c29ef  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c29f1  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c29f3  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c29f6  0f8cfdfeffff           -jl 0x4c28f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c28f9;
    }
    // 004c29fc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c29ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c2a03:
    // 004c2a03  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004c2a05  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004c2a09  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004c2a0d  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2a0f  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004c2a11  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2a14  0f8cdffeffff           -jl 0x4c28f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c28f9;
    }
    // 004c2a1a  83c410                 +add esp, 0x10
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
    // 004c2a1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a20  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004c2a21:
    // 004c2a21  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c2a26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c2a28  c7448d00000000c0       -mov dword ptr [ebp + ecx*4], 0xc0000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 3221225472 /*0xc0000000*/;
    // 004c2a30  e9aafeffff             -jmp 0x4c28df
    goto L_0x004c28df;
  case 0x004c2a35:
    // 004c2a35  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c2a3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c2a3c  c7448d0000000040       -mov dword ptr [ebp + ecx*4], 0x40000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 1073741824 /*0x40000000*/;
    // 004c2a44  e996feffff             -jmp 0x4c28df
    goto L_0x004c28df;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4c2a4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2a4c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c2a4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c2a4f  8d90b0010000           -lea edx, [eax + 0x1b0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(432) /* 0x1b0 */);
    // 004c2a55  dd05681e4d00           -fld qword ptr [0x4d1e68]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5054056) /* 0x4d1e68 */)));
    // 004c2a5b  dd05601e4d00           -fld qword ptr [0x4d1e60]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5054048) /* 0x4d1e60 */)));
    // 004c2a61  dd05581e4d00           -fld qword ptr [0x4d1e58]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5054040) /* 0x4d1e58 */)));
L_0x004c2a67:
    // 004c2a67  d940fc                 -fld dword ptr [eax - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */)));
    // 004c2a6a  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 004c2a6d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004c2a6f  d940f4                 -fld dword ptr [eax - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-12) /* -0xc */)));
    // 004c2a72  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 004c2a75  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004c2a77  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2a79  d940ec                 -fld dword ptr [eax - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-20) /* -0x14 */)));
    // 004c2a7c  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 004c2a7f  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004c2a81  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2a83  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c2a86  d958f8                 -fstp dword ptr [eax - 8]
    app->getMemory<float>(cpu.eax + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2a89  39d0                   +cmp eax, edx
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
    // 004c2a8b  75da                   -jne 0x4c2a67
    if (!cpu.flags.zf)
    {
        goto L_0x004c2a67;
    }
    // 004c2a8d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2a8f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2a91  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2a93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2a94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4c2a98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2a98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c2a99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c2a9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c2a9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c2a9c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c2a9d  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004c2aa0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c2aa2  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 004c2aa6  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004c2aab  8d5528                 -lea edx, [ebp + 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
L_0x004c2aae:
    // 004c2aae  48                     -dec eax
    (cpu.eax)--;
    // 004c2aaf  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004c2ab1  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2ab4  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2ab8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2aba  7df2                   -jge 0x4c2aae
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c2aae;
    }
    // 004c2abc  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 004c2ac1  8b7c2464               -mov edi, dword ptr [esp + 0x64]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004c2ac5  8d4528                 -lea eax, [ebp + 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 004c2ac8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c2aca  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004c2acc  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004c2ad0  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x004c2ad4:
    // 004c2ad4  d9452c                 -fld dword ptr [ebp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 004c2ad7  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004c2ad9  d84c245c               -fmul dword ptr [esp + 0x5c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(92) /* 0x5c */));
    // 004c2add  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004c2ae2  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004c2ae6  d9542468               -fst dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
L_0x004c2aea:
    // 004c2aea  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004c2aec  d84c8430               -fmul dword ptr [esp + eax*4 + 0x30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 4));
    // 004c2af0  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2af2  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004c2af4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004c2af6  48                     -dec eax
    (cpu.eax)--;
    // 004c2af7  d8448434               -fadd dword ptr [esp + eax*4 + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.eax * 4));
    // 004c2afb  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2afe  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2b02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c2b04  7de4                   -jge 0x4c2aea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c2aea;
    }
    // 004c2b06  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2b0a  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004c2b0e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c2b10  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004c2b14  890434                 -mov dword ptr [esp + esi], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.esi * 1) = cpu.eax;
    // 004c2b17  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c2b19  7e21                   -jle 0x4c2b3c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c2b3c;
    }
    // 004c2b1b  d9442468               -fld dword ptr [esp + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 004c2b1f  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004c2b23  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004c2b25:
    // 004c2b25  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004c2b27  d84c04fc               -fmul dword ptr [esp + eax - 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1));
    // 004c2b2b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2b2e  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2b31  41                     -inc ecx
    (cpu.ecx)++;
    // 004c2b32  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2b34  39d9                   +cmp ecx, ebx
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
    // 004c2b36  7ced                   -jl 0x4c2b25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c2b25;
    }
    // 004c2b38  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004c2b3c:
    // 004c2b3c  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004c2b40  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2b43  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c2b46  43                     -inc ebx
    (cpu.ebx)++;
    // 004c2b47  8947fc                 -mov dword ptr [edi - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004c2b4a  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c2b4d  7c85                   -jl 0x4c2ad4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c2ad4;
    }
    // 004c2b4f  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004c2b52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2b53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2b54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2b55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2b56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c2b57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c2b58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c2b58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c2b59  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c2b5a  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004c2b5d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c2b5f  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c2b61  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c2b63  0f859e070000           -jne 0x4c3307
    if (!cpu.flags.zf)
    {
        goto L_0x004c3307;
    }
    // 004c2b69  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
L_0x004c2b6d:
    // 004c2b6d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c2b6f  8d8614010000           -lea eax, [esi + 0x114]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 004c2b75  e81effffff             -call 0x4c2a98
    cpu.esp -= 4;
    sub_4c2a98(app, cpu);
    if (cpu.terminate) return;
    // 004c2b7a  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004c2b81  8d9684060000           -lea edx, [esi + 0x684]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1668) /* 0x684 */);
    // 004c2b87  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c2b89  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c2b8b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c2b8d  0f8e6e070000           -jle 0x4c3301
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c3301;
    }
L_0x004c2b93:
    // 004c2b93  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2b96  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c2b9c  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004c2b9e  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2ba2  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c2ba8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2baa  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2bae  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c2bb4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2bb6  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c2bba  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c2bc0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2bc2  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c2bc6  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c2bcc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2bce  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c2bd2  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2bd8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2bda  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c2bde  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2be4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2be6  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c2bea  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c2bf0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2bf2  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c2bf6  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c2bfc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2bfe  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c2c02  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c2c08  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c0a  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c2c0e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c2c14  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c16  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c2c1a  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c2c20  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c22  d99670010000           -fst dword ptr [esi + 0x170]
    app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */) = float(cpu.fpu.st(0));
    // 004c2c28  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004c2c2c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c2c2e  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c2c30  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2c32  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2c35  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c2c3b  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 004c2c3e  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2c42  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c2c48  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c4a  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2c4e  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c2c54  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c56  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c2c5a  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c2c60  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c62  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c2c66  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c2c6c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c6e  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c2c72  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c2c78  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c7a  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c2c7e  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2c84  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c86  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c2c8a  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2c90  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c92  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c2c96  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c2c9c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2c9e  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c2ca2  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c2ca8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2caa  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c2cae  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c2cb4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2cb6  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c2cba  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c2cc0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2cc2  d9966c010000           -fst dword ptr [esi + 0x16c]
    app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */) = float(cpu.fpu.st(0));
    // 004c2cc8  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c2cca  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2ccd  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2cd0  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c2cd6  d84008                 -fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004c2cd9  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2cdd  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c2ce3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2ce5  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2ce9  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c2cef  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2cf1  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c2cf5  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c2cfb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2cfd  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c2d01  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c2d07  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d09  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c2d0d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c2d13  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d15  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c2d19  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c2d1f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d21  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c2d25  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2d2b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d2d  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c2d31  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2d37  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d39  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c2d3d  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c2d43  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d45  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c2d49  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c2d4f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d51  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c2d55  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c2d5b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d5d  d99668010000           -fst dword ptr [esi + 0x168]
    app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */) = float(cpu.fpu.st(0));
    // 004c2d63  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d65  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2d68  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2d6b  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c2d71  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 004c2d74  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2d78  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c2d7e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d80  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2d84  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c2d8a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d8c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c2d90  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c2d96  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2d98  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c2d9c  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c2da2  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2da4  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c2da8  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c2dae  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2db0  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c2db4  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c2dba  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2dbc  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c2dc0  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c2dc6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2dc8  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c2dcc  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2dd2  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2dd4  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c2dd8  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2dde  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2de0  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c2de4  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c2dea  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2dec  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c2df0  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c2df6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2df8  d99e64010000           -fstp dword ptr [esi + 0x164]
    app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2dfe  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004c2e02  d98664010000           -fld dword ptr [esi + 0x164]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */)));
    // 004c2e08  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c2e0a  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2e0d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2e10  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c2e16  d84010                 -fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 004c2e19  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2e1d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c2e23  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e25  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2e29  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c2e2f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e31  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c2e35  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c2e3b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e3d  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c2e41  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c2e47  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e49  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c2e4d  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c2e53  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e55  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c2e59  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c2e5f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e61  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c2e65  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c2e6b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e6d  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c2e71  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c2e77  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e79  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c2e7d  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2e83  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e85  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c2e89  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2e8f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e91  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c2e95  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c2e9b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2e9d  d99660010000           -fst dword ptr [esi + 0x160]
    app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */) = float(cpu.fpu.st(0));
    // 004c2ea3  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c2ea5  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2ea8  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2eab  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c2eb1  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 004c2eb4  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2eb8  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c2ebe  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2ec0  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2ec4  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c2eca  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2ecc  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c2ed0  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c2ed6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2ed8  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c2edc  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c2ee2  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2ee4  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c2ee8  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c2eee  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2ef0  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c2ef4  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c2efa  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2efc  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c2f00  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c2f06  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f08  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c2f0c  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c2f12  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f14  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c2f18  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c2f1e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f20  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c2f24  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2f2a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f2c  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c2f30  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2f36  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f38  d9965c010000           -fst dword ptr [esi + 0x15c]
    app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */) = float(cpu.fpu.st(0));
    // 004c2f3e  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c2f40  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2f43  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2f46  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2f4c  d84018                 -fadd dword ptr [eax + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */));
    // 004c2f4f  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2f53  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c2f59  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f5b  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2f5f  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c2f65  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f67  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c2f6b  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c2f71  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f73  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c2f77  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c2f7d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f7f  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c2f83  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c2f89  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f8b  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c2f8f  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c2f95  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2f97  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c2f9b  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c2fa1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2fa3  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c2fa7  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c2fad  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2faf  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c2fb3  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c2fb9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2fbb  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c2fbf  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c2fc5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2fc7  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c2fcb  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2fd1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2fd3  d99658010000           -fst dword ptr [esi + 0x158]
    app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */) = float(cpu.fpu.st(0));
    // 004c2fd9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2fdb  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c2fde  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c2fe1  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c2fe7  d8401c                 -fadd dword ptr [eax + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004c2fea  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c2fee  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c2ff4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c2ff6  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c2ffa  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c3000  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3002  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c3006  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c300c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c300e  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c3012  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c3018  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c301a  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c301e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c3024  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3026  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c302a  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c3030  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3032  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c3036  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c303c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c303e  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c3042  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c3048  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c304a  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c304e  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c3054  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3056  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c305a  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c3060  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3062  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c3066  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c306c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c306e  d99654010000           -fst dword ptr [esi + 0x154]
    app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */) = float(cpu.fpu.st(0));
    // 004c3074  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004c3078  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004c307a  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c307c  d9581c                 -fstp dword ptr [eax + 0x1c]
    app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c307f  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c3082  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c3088  d84020                 -fadd dword ptr [eax + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */));
    // 004c308b  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c308f  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c3095  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3097  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c309b  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c30a1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30a3  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c30a7  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c30ad  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30af  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c30b3  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c30b9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30bb  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c30bf  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c30c5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30c7  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c30cb  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c30d1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30d3  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c30d7  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c30dd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30df  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c30e3  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c30e9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30eb  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c30ef  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c30f5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c30f7  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c30fb  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c3101  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3103  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c3107  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c310d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c310f  d99650010000           -fst dword ptr [esi + 0x150]
    app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */) = float(cpu.fpu.st(0));
    // 004c3115  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c3117  d95820                 -fstp dword ptr [eax + 0x20]
    app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c311a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c311d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c3123  d84024                 -fadd dword ptr [eax + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 004c3126  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c312a  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c3130  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3132  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c3136  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c313c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c313e  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c3142  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c3148  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c314a  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c314e  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c3154  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3156  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c315a  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c3160  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3162  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c3166  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c316c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c316e  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c3172  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c3178  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c317a  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c317e  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c3184  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3186  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c318a  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c3190  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3192  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c3196  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c319c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c319e  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c31a2  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c31a8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c31aa  d9964c010000           -fst dword ptr [esi + 0x14c]
    app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */) = float(cpu.fpu.st(0));
    // 004c31b0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c31b2  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c31b5  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c31b8  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c31be  d84028                 -fadd dword ptr [eax + 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 004c31c1  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c31c5  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c31cb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c31cd  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c31d1  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c31d7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c31d9  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c31dd  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c31e3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c31e5  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c31e9  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c31ef  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c31f1  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c31f5  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c31fb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c31fd  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c3201  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c3207  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3209  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c320d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c3213  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3215  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c3219  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c321f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3221  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c3225  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c322b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c322d  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c3231  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c3237  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3239  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c323d  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c3243  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3245  d99e48010000           -fstp dword ptr [esi + 0x148]
    app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c324b  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 004c324f  d98648010000           -fld dword ptr [esi + 0x148]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */)));
    // 004c3255  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004c3257  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c325a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004c325d  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 004c3263  d8402c                 -fadd dword ptr [eax + 0x2c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 004c3266  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004c326a  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 004c3270  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3272  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c3276  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 004c327c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c327e  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004c3282  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 004c3288  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c328a  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004c328e  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 004c3294  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3296  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004c329a  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 004c32a0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32a2  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004c32a6  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 004c32ac  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32ae  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004c32b2  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 004c32b8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32ba  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004c32be  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 004c32c4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32c6  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 004c32ca  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 004c32d0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32d2  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004c32d6  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 004c32dc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32de  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004c32e2  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 004c32e8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32ea  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004c32ed  d99644010000           -fst dword ptr [esi + 0x144]
    app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */) = float(cpu.fpu.st(0));
    // 004c32f3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c32f5  42                     -inc edx
    (cpu.edx)++;
    // 004c32f6  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c32f9  39da                   +cmp edx, ebx
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
    // 004c32fb  0f8c92f8ffff           -jl 0x4c2b93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c2b93;
    }
L_0x004c3301:
    // 004c3301  83c434                 +add esp, 0x34
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3304  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3305  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3306  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3307:
    // 004c3307  c74424300000404b       -mov dword ptr [esp + 0x30], 0x4b400000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = 1262485504 /*0x4b400000*/;
    // 004c330f  e959f8ffff             -jmp 0x4c2b6d
    goto L_0x004c2b6d;
}

/* align: skip  */
void Application::sub_4c3314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3314  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3315  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3316  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c3319  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c331b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c331d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c331e  ff15d0de4d00           -call dword ptr [0x4dded0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103312) /* 0x4dded0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c3324  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3326  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c332b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c332d  c7430808000000         -mov dword ptr [ebx + 8], 8
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004c3334  46                     -inc esi
    (cpu.esi)++;
    // 004c3335  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c3338  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c333a  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004c333c  e8aff4ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c3341  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004c3346  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c3349  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c334b  e8a0f4ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c3350  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004c3355  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3357  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3359  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004c335c  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004c3361  e88af4ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c3366  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c3368  40                     -inc eax
    (cpu.eax)++;
    // 004c3369  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004c336d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c3371  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c3373  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004c3377  dc0d701e4d00           -fmul qword ptr [0x4d1e70]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5054064) /* 0x4d1e70 */));
    // 004c337d  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004c3381  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004c3386  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3388  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c338b  e860f4ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c3390  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c3394  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004c3398  dc0d781e4d00           -fmul qword ptr [0x4d1e78]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5054072) /* 0x4d1e78 */));
    // 004c339e  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c33a1  dc05801e4d00           -fadd qword ptr [0x4d1e80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5054080) /* 0x4d1e80 */));
    // 004c33a7  8d9300010000           -lea edx, [ebx + 0x100]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(256) /* 0x100 */);
    // 004c33ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c33ae:
    // 004c33ae  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 004c33b1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004c33b3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c33b6  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c33b9  39d0                   +cmp eax, edx
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
    // 004c33bb  75f1                   -jne 0x4c33ae
    if (!cpu.flags.zf)
    {
        goto L_0x004c33ae;
    }
    // 004c33bd  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c33bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c33c1  8d5330                 -lea edx, [ebx + 0x30]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
L_0x004c33c4:
    // 004c33c4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c33c7  c7801001000000000000   -mov dword ptr [eax + 0x110], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = 0 /*0x0*/;
    // 004c33d1  c7804001000000000000   -mov dword ptr [eax + 0x140], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(320) /* 0x140 */) = 0 /*0x0*/;
    // 004c33db  39d0                   +cmp eax, edx
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
    // 004c33dd  75e5                   -jne 0x4c33c4
    if (!cpu.flags.zf)
    {
        goto L_0x004c33c4;
    }
    // 004c33df  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c33e1  81c310050000           -add ebx, 0x510
    (cpu.ebx) += x86::reg32(x86::sreg32(1296 /*0x510*/));
L_0x004c33e7:
    // 004c33e7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c33ea  c7807001000000000000   -mov dword ptr [eax + 0x170], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = 0 /*0x0*/;
    // 004c33f4  39d8                   +cmp eax, ebx
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
    // 004c33f6  75ef                   -jne 0x4c33e7
    if (!cpu.flags.zf)
    {
        goto L_0x004c33e7;
    }
    // 004c33f8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c33fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c33fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c33fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4c3400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3402  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3403  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3404  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3405  81ec30020000           -sub esp, 0x230
    (cpu.esp) -= x86::reg32(x86::sreg32(560 /*0x230*/));
    // 004c340b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c340d  89942414020000         -mov dword ptr [esp + 0x214], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.edx;
    // 004c3414  ff15d0de4d00           -call dword ptr [0x4dded0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5103312) /* 0x4dded0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c341a  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004c341f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3421  e8caf3ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c3426  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004c3429  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c342b  39c8                   +cmp eax, ecx
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
    // 004c342d  0f838b020000           -jae 0x4c36be
    if (!cpu.flags.cf)
    {
        goto L_0x004c36be;
    }
    // 004c3433  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x004c3438:
    // 004c3438  d90495580b4e00         -fld dword ptr [edx*4 + 0x4e0b58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114712) /* 0x4e0b58 */ + cpu.edx * 4)));
    // 004c343f  d8a614010000           -fsub dword ptr [esi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */));
    // 004c3445  dc0d881e4d00           -fmul qword ptr [0x4d1e88]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5054088) /* 0x4d1e88 */));
    // 004c344b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004c3450  8d7e04                 -lea edi, [esi + 4]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c3453  d99c24d8010000         -fstp dword ptr [esp + 0x1d8]
    app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c345a  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x004c345f:
    // 004c345f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c3461  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3463  e888f3ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c3468  d90485580b4e00         -fld dword ptr [eax*4 + 0x4e0b58]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114712) /* 0x4e0b58 */ + cpu.eax * 4)));
    // 004c346f  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 004c3475  dc0d881e4d00           -fmul qword ptr [0x4d1e88]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5054088) /* 0x4d1e88 */));
    // 004c347b  41                     -inc ecx
    (cpu.ecx)++;
    // 004c347c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c347f  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c3486  83f904                 +cmp ecx, 4
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
    // 004c3489  7cd4                   -jl 0x4c345f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c345f;
    }
    // 004c348b  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004c3490  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 004c3495  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
L_0x004c3498:
    // 004c3498  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c349a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c349c  e84ff3ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c34a1  d90485980b4e00         -fld dword ptr [eax*4 + 0x4e0b98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114776) /* 0x4e0b98 */ + cpu.eax * 4)));
    // 004c34a8  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 004c34ae  dc0d881e4d00           -fmul qword ptr [0x4d1e88]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5054088) /* 0x4d1e88 */));
    // 004c34b4  41                     -inc ecx
    (cpu.ecx)++;
    // 004c34b5  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c34b8  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c34bf  83f90c                 +cmp ecx, 0xc
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
    // 004c34c2  7cd4                   -jl 0x4c3498
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c3498;
    }
    // 004c34c4  bbd8000000             -mov ebx, 0xd8
    cpu.ebx = 216 /*0xd8*/;
    // 004c34c9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004c34cb  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
L_0x004c34d2:
    // 004c34d2  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004c34d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c34d9  e812f3ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c34de  8b942420020000         -mov edx, dword ptr [esp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004c34e5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c34e7  8994242c020000         -mov dword ptr [esp + 0x22c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */) = cpu.edx;
    // 004c34ee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c34f0  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004c34f5  e8f6f2ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c34fa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c34fc  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 004c3503  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 004c350a  dfac2408020000         -fild qword ptr [esp + 0x208]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(520) /* 0x208 */))));
    // 004c3511  dc0d901e4d00           -fmul qword ptr [0x4d1e90]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5054096) /* 0x4d1e90 */));
    // 004c3517  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3519  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004c351e  d99c2424020000         -fstp dword ptr [esp + 0x224]
    app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c3525  e8c6f2ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c352a  8b448614               -mov eax, dword ptr [esi + eax*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.eax * 4);
    // 004c352e  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c3531  89842428020000         -mov dword ptr [esp + 0x228], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */) = cpu.eax;
    // 004c3538  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c353a  0f8585010000           -jne 0x4c36c5
    if (!cpu.flags.zf)
    {
        goto L_0x004c36c5;
    }
    // 004c3540  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004c3545  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c3549  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c354b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c354d  e856f3ffff             -call 0x4c28a8
    cpu.esp -= 4;
    sub_4c28a8(app, cpu);
    if (cpu.terminate) return;
L_0x004c3552:
    // 004c3552  8b94242c020000         -mov edx, dword ptr [esp + 0x22c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */);
    // 004c3559  8d0c3e                 -lea ecx, [esi + edi]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004c355c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004c355f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3561  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004c3563  d9842428020000         -fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 004c356a  d9842424020000         -fld dword ptr [esp + 0x224]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */)));
L_0x004c3571:
    // 004c3571  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c3573  d88a74010000           -fmul dword ptr [edx + 0x174]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(372) /* 0x174 */));
    // 004c3579  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 004c357b  d84c0414               -fmul dword ptr [esp + eax + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */ + cpu.eax * 1));
    // 004c357f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3582  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3585  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004c3587  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c358a  d99980060000           -fstp dword ptr [ecx + 0x680]
    app->getMemory<float>(cpu.ecx + x86::reg32(1664) /* 0x680 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c3590  3db0010000             +cmp eax, 0x1b0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(432 /*0x1b0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3595  75da                   -jne 0x4c3571
    if (!cpu.flags.zf)
    {
        goto L_0x004c3571;
    }
    // 004c3597  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c3599  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004c35a0  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c35a2  83c36c                 -add ebx, 0x6c
    (cpu.ebx) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004c35a5  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c35a7  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
    // 004c35ae  81ffc0060000           +cmp edi, 0x6c0
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1728 /*0x6c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c35b4  0f8518ffffff           -jne 0x4c34d2
    if (!cpu.flags.zf)
    {
        goto L_0x004c34d2;
    }
    // 004c35ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c35bc  8d9610050000           -lea edx, [esi + 0x510]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1296) /* 0x510 */);
L_0x004c35c2:
    // 004c35c2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c35c5  8b8830080000           -mov ecx, dword ptr [eax + 0x830]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2096) /* 0x830 */);
    // 004c35cb  898870010000           -mov dword ptr [eax + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 004c35d1  39d0                   +cmp eax, edx
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
    // 004c35d3  75ed                   -jne 0x4c35c2
    if (!cpu.flags.zf)
    {
        goto L_0x004c35c2;
    }
    // 004c35d5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c35d7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004c35d9:
    // 004c35d9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c35dc  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 004c35e3  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 004c35e9  40                     -inc eax
    (cpu.eax)++;
    // 004c35ea  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c35f0  83f80c                 +cmp eax, 0xc
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
    // 004c35f3  7ce4                   -jl 0x4c35d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c35d9;
    }
    // 004c35f5  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004c35fc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c3601  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3603  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c3605  e84ef5ffff             -call 0x4c2b58
    cpu.esp -= 4;
    sub_4c2b58(app, cpu);
    if (cpu.terminate) return;
    // 004c360a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c360c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004c360e:
    // 004c360e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3611  d98494d8010000         -fld dword ptr [esp + edx*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.edx * 4)));
    // 004c3618  d88010010000           -fadd dword ptr [eax + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */));
    // 004c361e  42                     -inc edx
    (cpu.edx)++;
    // 004c361f  d99810010000           -fstp dword ptr [eax + 0x110]
    app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c3625  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3628  7ce4                   -jl 0x4c360e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c360e;
    }
    // 004c362a  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004c3631  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c3636  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 004c363b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c363d  e816f5ffff             -call 0x4c2b58
    cpu.esp -= 4;
    sub_4c2b58(app, cpu);
    if (cpu.terminate) return;
    // 004c3642  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004c3644  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c3646:
    // 004c3646  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3649  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 004c3650  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 004c3656  40                     -inc eax
    (cpu.eax)++;
    // 004c3657  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c365d  83f80c                 +cmp eax, 0xc
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
    // 004c3660  7ce4                   -jl 0x4c3646
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c3646;
    }
    // 004c3662  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004c3669  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c366e  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004c3673  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3675  e8def4ffff             -call 0x4c2b58
    cpu.esp -= 4;
    sub_4c2b58(app, cpu);
    if (cpu.terminate) return;
    // 004c367a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004c367c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c367e:
    // 004c367e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3681  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 004c3688  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 004c368e  40                     -inc eax
    (cpu.eax)++;
    // 004c368f  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c3695  83f80c                 +cmp eax, 0xc
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
    // 004c3698  7ce4                   -jl 0x4c367e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c367e;
    }
    // 004c369a  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004c36a1  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 004c36a6  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 004c36ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c36ad  e8a6f4ffff             -call 0x4c2b58
    cpu.esp -= 4;
    sub_4c2b58(app, cpu);
    if (cpu.terminate) return;
    // 004c36b2  81c430020000           -add esp, 0x230
    (cpu.esp) += x86::reg32(x86::sreg32(560 /*0x230*/));
    // 004c36b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c36b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c36ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c36bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c36bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c36bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c36be:
    // 004c36be  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004c36c0  e973fdffff             -jmp 0x4c3438
    goto L_0x004c3438;
L_0x004c36c5:
    // 004c36c5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c36ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c36cc  e81ff1ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c36d1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c36d6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c36d8  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 004c36df  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c36e1  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c36e5  e806f1ffff             -call 0x4c27f0
    cpu.esp -= 4;
    sub_4c27f0(app, cpu);
    if (cpu.terminate) return;
    // 004c36ea  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004c36ed  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 004c36f4  898c241c020000         -mov dword ptr [esp + 0x21c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.ecx;
    // 004c36fb  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c36fd  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004c36ff  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004c3704  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3706  e89df1ffff             -call 0x4c28a8
    cpu.esp -= 4;
    sub_4c28a8(app, cpu);
    if (cpu.terminate) return;
    // 004c370b  83bc241002000000       +cmp dword ptr [esp + 0x210], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3713  7424                   -je 0x4c3739
    if (cpu.flags.zf)
    {
        goto L_0x004c3739;
    }
    // 004c3715  8b94241c020000         -mov edx, dword ptr [esp + 0x21c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 004c371c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004c371e  8d4218                 -lea eax, [edx + 0x18]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004c3721  81c2c8010000           -add edx, 0x1c8
    (cpu.edx) += x86::reg32(x86::sreg32(456 /*0x1c8*/));
L_0x004c3727:
    // 004c3727  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c372a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c372c  894c04f8               -mov dword ptr [esp + eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.ecx;
    // 004c3730  39d0                   +cmp eax, edx
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
    // 004c3732  75f3                   -jne 0x4c3727
    if (!cpu.flags.zf)
    {
        goto L_0x004c3727;
    }
    // 004c3734  e919feffff             -jmp 0x4c3552
    goto L_0x004c3552;
L_0x004c3739:
    // 004c3739  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c373b:
    // 004c373b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c373e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c3740  894c04fc               -mov dword ptr [esp + eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ecx;
    // 004c3744  83f814                 +cmp eax, 0x14
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
    // 004c3747  75f2                   -jne 0x4c373b
    if (!cpu.flags.zf)
    {
        goto L_0x004c373b;
    }
    // 004c3749  b8c4010000             -mov eax, 0x1c4
    cpu.eax = 452 /*0x1c4*/;
L_0x004c374e:
    // 004c374e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3751  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c3753  895c04fc               -mov dword ptr [esp + eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ebx;
    // 004c3757  3dd8010000             +cmp eax, 0x1d8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(472 /*0x1d8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c375c  75f0                   -jne 0x4c374e
    if (!cpu.flags.zf)
    {
        goto L_0x004c374e;
    }
    // 004c375e  8b942418020000         -mov edx, dword ptr [esp + 0x218]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 004c3765  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004c3769  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004c376c  29d0                   +sub eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c376e  e8d9f2ffff             -call 0x4c2a4c
    cpu.esp -= 4;
    sub_4c2a4c(app, cpu);
    if (cpu.terminate) return;
    // 004c3773  d9842428020000         +fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 004c377a  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004c377c  dc0d981e4d00           +fmul qword ptr [0x4d1e98]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5054104) /* 0x4d1e98 */));
    // 004c3782  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c3784  d99c2428020000         +fstp dword ptr [esp + 0x228]
    app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c378b  e9c2fdffff             -jmp 0x4c3552
    goto L_0x004c3552;
}

/* align: skip  */
void Application::sub_4c3790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3790  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3792  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3793(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3793  ff15b40f4e00           -call dword ptr [0x4e0fb4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5115828) /* 0x4e0fb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c3799  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c379a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c379a  ff15b80f4e00           -call dword ptr [0x4e0fb8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5115832) /* 0x4e0fb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c37a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c37a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c37a1  ff15bc0f4e00           -call dword ptr [0x4e0fbc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5115836) /* 0x4e0fbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c37a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c37a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c37a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c37a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c37aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c37ac  7410                   -je 0x4c37be
    if (cpu.flags.zf)
    {
        goto L_0x004c37be;
    }
    // 004c37ae  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004c37b0  8b35b40f4e00           -mov esi, dword ptr [0x4e0fb4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5115828) /* 0x4e0fb4 */);
    // 004c37b6  890db40f4e00           -mov dword ptr [0x4e0fb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5115828) /* 0x4e0fb4 */) = cpu.ecx;
    // 004c37bc  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x004c37be:
    // 004c37be  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c37c0  740f                   -je 0x4c37d1
    if (cpu.flags.zf)
    {
        goto L_0x004c37d1;
    }
    // 004c37c2  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004c37c4  8b0db80f4e00           -mov ecx, dword ptr [0x4e0fb8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5115832) /* 0x4e0fb8 */);
    // 004c37ca  a3b80f4e00             -mov dword ptr [0x4e0fb8], eax
    app->getMemory<x86::reg32>(x86::reg32(5115832) /* 0x4e0fb8 */) = cpu.eax;
    // 004c37cf  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x004c37d1:
    // 004c37d1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004c37d3  740f                   -je 0x4c37e4
    if (cpu.flags.zf)
    {
        goto L_0x004c37e4;
    }
    // 004c37d5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c37d7  8b15bc0f4e00           -mov edx, dword ptr [0x4e0fbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5115836) /* 0x4e0fbc */);
    // 004c37dd  a3bc0f4e00             -mov dword ptr [0x4e0fbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5115836) /* 0x4e0fbc */) = cpu.eax;
    // 004c37e2  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004c37e4:
    // 004c37e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c37e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c37e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c37e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c37e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c37e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c37e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c37ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c37eb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c37ee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c37f0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c37f2  8a253cb54d00           -mov ah, byte ptr [0x4db53c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5092668) /* 0x4db53c */);
    // 004c37f8  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004c37fb  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004c37fd  7426                   -je 0x4c3825
    if (cpu.flags.zf)
    {
        goto L_0x004c3825;
    }
    // 004c37ff  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c3801  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004c3804  9b                     -wait 
    /*nothing*/;
    // 004c3805  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c3807  741c                   -je 0x4c3825
    if (cpu.flags.zf)
    {
        goto L_0x004c3825;
    }
    // 004c3809  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c380b  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004c380e  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004c3810  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c3812  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004c3814  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c3816  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c3818  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004c381b  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 004c381e  9b                     -wait 
    /*nothing*/;
    // 004c381f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c3821  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004c3824  9b                     -wait 
    /*nothing*/;
L_0x004c3825:
    // 004c3825  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3827  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004c382b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c382e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c382f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3830  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3831  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3833(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3833  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3834  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004c3838  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004c383b  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c3840  751c                   -jne 0x4c385e
    if (!cpu.flags.zf)
    {
        goto L_0x004c385e;
    }
    // 004c3842  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3849  750c                   -jne 0x4c3857
    if (!cpu.flags.zf)
    {
        goto L_0x004c3857;
    }
    // 004c384b  833800                 +cmp dword ptr [eax], 0
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
    // 004c384e  7507                   -jne 0x4c3857
    if (!cpu.flags.zf)
    {
        goto L_0x004c3857;
    }
    // 004c3850  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004c3855  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3856  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3857:
    // 004c3857  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004c385c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c385d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c385e:
    // 004c385e  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 004c3864  7516                   -jne 0x4c387c
    if (!cpu.flags.zf)
    {
        goto L_0x004c387c;
    }
    // 004c3866  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004c386a  7509                   -jne 0x4c3875
    if (!cpu.flags.zf)
    {
        goto L_0x004c3875;
    }
    // 004c386c  833800                 +cmp dword ptr [eax], 0
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
    // 004c386f  7504                   -jne 0x4c3875
    if (!cpu.flags.zf)
    {
        goto L_0x004c3875;
    }
    // 004c3871  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3873  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3874  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3875:
    // 004c3875  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004c387a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c387b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c387c:
    // 004c387c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c3881  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3882  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c3884(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3884  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3885  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3886  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3887  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3888  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3889  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c388a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c388c  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c388e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c3890  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c3892  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c3894:
    // 004c3894  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c3896  3c00                   +cmp al, 0
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
    // 004c3898  742f                   -je 0x4c38c9
    if (cpu.flags.zf)
    {
        goto L_0x004c38c9;
    }
    // 004c389a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004c389c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004c389e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c38a0  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38a2  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38a4  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c38a6  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38a8  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38aa  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c38ac  01c5                   +add ebp, eax
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
    // 004c38ae  11d9                   +adc ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38b0  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 004c38b2  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38b4  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38b6  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004c38b8  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c38ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004c38bc  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004c38be  01c5                   +add ebp, eax
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
    // 004c38c0  83d100                 +adc ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38c3  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c38c6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c38c7  ebcb                   -jmp 0x4c3894
    goto L_0x004c3894;
L_0x004c38c9:
    // 004c38c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c38cb  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 004c38d0  e811000000             -call 0x4c38e6
    cpu.esp -= 4;
    sub_4c38e6(app, cpu);
    if (cpu.terminate) return;
    // 004c38d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c38d6  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c38d9  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004c38dc  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 004c38e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c38e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c38e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c38e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c38e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c38e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c38e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c38e6  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c38e8  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004c38ea  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c38ec  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004c38ee  7436                   -je 0x4c3926
    if (cpu.flags.zf)
    {
        goto L_0x004c3926;
    }
    // 004c38f0  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c38f2  7509                   -jne 0x4c38fd
    if (!cpu.flags.zf)
    {
        goto L_0x004c38fd;
    }
    // 004c38f4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c38f6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c38f8  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c38fa  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004c38fd:
    // 004c38fd  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c38ff  7509                   -jne 0x4c390a
    if (!cpu.flags.zf)
    {
        goto L_0x004c390a;
    }
    // 004c3901  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3903  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c3905  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c3907  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004c390a:
    // 004c390a  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c390c  7809                   -js 0x4c3917
    if (cpu.flags.sf)
    {
        goto L_0x004c3917;
    }
    // 004c390e  4f                     -dec edi
    (cpu.edi)--;
    // 004c390f  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3911  11c0                   +adc eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3913  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3915  ebf3                   -jmp 0x4c390a
    goto L_0x004c390a;
L_0x004c3917:
    // 004c3917  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3919  83d000                 +adc eax, 0
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
    // 004c391c  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c391f  7303                   -jae 0x4c3924
    if (!cpu.flags.cf)
    {
        goto L_0x004c3924;
    }
    // 004c3921  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004c3923  47                     -inc edi
    (cpu.edi)++;
L_0x004c3924:
    // 004c3924  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004c3926:
    // 004c3926  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3927(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3927  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3928  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c392a  e802000000             -call 0x4c3931
    cpu.esp -= 4;
    sub_4c3931(app, cpu);
    if (cpu.terminate) return;
    // 004c392f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3930  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3931(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3931  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3932  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c3934  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3935  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3936  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004c3939  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c393b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004c393d  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004c3940  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004c3943  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004c3946  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c3948  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004c394b  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c394e  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004c3951  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 004c3954  7407                   -je 0x4c395d
    if (cpu.flags.zf)
    {
        goto L_0x004c395d;
    }
    // 004c3956  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004c395b  eb3a                   -jmp 0x4c3997
    goto L_0x004c3997;
L_0x004c395d:
    // 004c395d  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 004c3960  7407                   -je 0x4c3969
    if (cpu.flags.zf)
    {
        goto L_0x004c3969;
    }
    // 004c3962  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 004c3967  eb2e                   -jmp 0x4c3997
    goto L_0x004c3997;
L_0x004c3969:
    // 004c3969  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 004c396c  7407                   -je 0x4c3975
    if (cpu.flags.zf)
    {
        goto L_0x004c3975;
    }
    // 004c396e  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 004c3973  eb22                   -jmp 0x4c3997
    goto L_0x004c3997;
L_0x004c3975:
    // 004c3975  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004c3978  7407                   -je 0x4c3981
    if (cpu.flags.zf)
    {
        goto L_0x004c3981;
    }
    // 004c397a  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004c397f  eb16                   -jmp 0x4c3997
    goto L_0x004c3997;
L_0x004c3981:
    // 004c3981  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 004c3984  7407                   -je 0x4c398d
    if (cpu.flags.zf)
    {
        goto L_0x004c398d;
    }
    // 004c3986  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 004c398b  eb0a                   -jmp 0x4c3997
    goto L_0x004c3997;
L_0x004c398d:
    // 004c398d  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004c3990  7405                   -je 0x4c3997
    if (cpu.flags.zf)
    {
        goto L_0x004c3997;
    }
    // 004c3992  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
L_0x004c3997:
    // 004c3997  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3999  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004c399c  8b0485bc0f4e00         -mov eax, dword ptr [eax*4 + 0x4e0fbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5115836) /* 0x4e0fbc */ + cpu.eax * 4);
    // 004c39a3  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 004c39a6  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004c39a9  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 004c39ac  740d                   -je 0x4c39bb
    if (cpu.flags.zf)
    {
        goto L_0x004c39bb;
    }
    // 004c39ae  dd05e01f4d00           +fld qword ptr [0x4d1fe0]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5054432) /* 0x4d1fe0 */)));
    // 004c39b4  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004c39b6  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c39b9  eb42                   -jmp 0x4c39fd
    goto L_0x004c39fd;
L_0x004c39bb:
    // 004c39bb  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004c39be  740a                   -je 0x4c39ca
    if (cpu.flags.zf)
    {
        goto L_0x004c39ca;
    }
    // 004c39c0  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004c39c2  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 004c39c5  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004c39c8  eb33                   -jmp 0x4c39fd
    goto L_0x004c39fd;
L_0x004c39ca:
    // 004c39ca  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 004c39cd  740f                   -je 0x4c39de
    if (cpu.flags.zf)
    {
        goto L_0x004c39de;
    }
    // 004c39cf  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c39d1  bb0000f03f             -mov ebx, 0x3ff00000
    cpu.ebx = 1072693248 /*0x3ff00000*/;
    // 004c39d6  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004c39d9  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004c39dc  eb1f                   -jmp 0x4c39fd
    goto L_0x004c39fd;
L_0x004c39de:
    // 004c39de  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 004c39e1  740f                   -je 0x4c39f2
    if (cpu.flags.zf)
    {
        goto L_0x004c39f2;
    }
    // 004c39e3  a1e01f4d00             -mov eax, dword ptr [0x4d1fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054432) /* 0x4d1fe0 */);
    // 004c39e8  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c39eb  a1e41f4d00             -mov eax, dword ptr [0x4d1fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5054436) /* 0x4d1fe4 */);
    // 004c39f0  eb08                   -jmp 0x4c39fa
    goto L_0x004c39fa;
L_0x004c39f2:
    // 004c39f2  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c39f4  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004c39f7  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
L_0x004c39fa:
    // 004c39fa  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x004c39fd:
    // 004c39fd  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004c3a00  e882090000             -call 0x4c4387
    cpu.esp -= 4;
    sub_4c4387(app, cpu);
    if (cpu.terminate) return;
    // 004c3a05  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004c3a08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3a0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3a0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3a0d  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3a14  7421                   -je 0x4c3a37
    if (cpu.flags.zf)
    {
        goto L_0x004c3a37;
    }
    // 004c3a16  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c3a18  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3a1a  8a9bd5a35b00           -mov bl, byte ptr [ebx + 0x5ba3d5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004c3a20  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c3a23  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c3a29  740c                   -je 0x4c3a37
    if (cpu.flags.zf)
    {
        goto L_0x004c3a37;
    }
    // 004c3a2b  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3a2d  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004c3a2f  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c3a32  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 004c3a35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3a37:
    // 004c3a37  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3a39  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c3a3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3a3d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3a3d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3a3e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3a3f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3a40  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3a43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004c3a45:
    // 004c3a45  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c3a47  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3a49  e87b73ffff             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004c3a4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3a50  7531                   -jne 0x4c3a83
    if (!cpu.flags.zf)
    {
        goto L_0x004c3a83;
    }
    // 004c3a52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3a54  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c3a56  e85b090000             -call 0x4c43b6
    cpu.esp -= 4;
    sub_4c43b6(app, cpu);
    if (cpu.terminate) return;
    // 004c3a5b  e891090000             -call 0x4c43f1
    cpu.esp -= 4;
    sub_4c43f1(app, cpu);
    if (cpu.terminate) return;
    // 004c3a60  e8f5090000             -call 0x4c445a
    cpu.esp -= 4;
    sub_4c445a(app, cpu);
    if (cpu.terminate) return;
    // 004c3a65  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c3a67  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004c3a69  e833beffff             -call 0x4bf8a1
    cpu.esp -= 4;
    sub_4bf8a1(app, cpu);
    if (cpu.terminate) return;
    // 004c3a6e  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004c3a71  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c3a73  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3a75  e892ffffff             -call 0x4c3a0c
    cpu.esp -= 4;
    sub_4c3a0c(app, cpu);
    if (cpu.terminate) return;
    // 004c3a7a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3a7c  e88473ffff             -call 0x4bae05
    cpu.esp -= 4;
    sub_4bae05(app, cpu);
    if (cpu.terminate) return;
    // 004c3a81  ebc2                   -jmp 0x4c3a45
    goto L_0x004c3a45;
L_0x004c3a83:
    // 004c3a83  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3a85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c3a88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3a8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3a8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3a8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3a8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3a8e  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c3a90  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3a92  7541                   -jne 0x4c3ad5
    if (!cpu.flags.zf)
    {
        goto L_0x004c3ad5;
    }
    // 004c3a94  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3a9b  741f                   -je 0x4c3abc
    if (cpu.flags.zf)
    {
        goto L_0x004c3abc;
    }
    // 004c3a9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c3a9f  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c3aa1  8a9bd5a35b00           -mov bl, byte ptr [ebx + 0x5ba3d5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004c3aa7  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c3aaa  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c3ab0  740a                   -je 0x4c3abc
    if (cpu.flags.zf)
    {
        goto L_0x004c3abc;
    }
    // 004c3ab2  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c3ab5  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c3ab8  38cb                   +cmp bl, cl
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
    // 004c3aba  7505                   -jne 0x4c3ac1
    if (!cpu.flags.zf)
    {
        goto L_0x004c3ac1;
    }
L_0x004c3abc:
    // 004c3abc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3abe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3abf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ac0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3ac1:
    // 004c3ac1  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004c3ac3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c3ac8  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 004c3aca  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c3ad0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c3ad2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ad3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ad4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3ad5:
    // 004c3ad5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c3ad7  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c3ad9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3adb  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3add  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3adf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3ae1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ae2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ae3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3ae4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3ae4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3ae5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3ae6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3ae7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004c3aea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c3aeb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c3aed  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004c3aef  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004c3af3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c3af5  7402                   -je 0x4c3af9
    if (cpu.flags.zf)
    {
        goto L_0x004c3af9;
    }
    // 004c3af7  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004c3af9:
    // 004c3af9  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004c3afc:
    // 004c3afc  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3afe  fec0                   -inc al
    (cpu.al)++;
    // 004c3b00  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c3b05  f68064ef4d0002         +test byte ptr [eax + 0x4def64], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5107556) /* 0x4def64 */) & 2 /*0x2*/));
    // 004c3b0c  7403                   -je 0x4c3b11
    if (cpu.flags.zf)
    {
        goto L_0x004c3b11;
    }
    // 004c3b0e  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c3b0f  ebeb                   -jmp 0x4c3afc
    goto L_0x004c3afc;
L_0x004c3b11:
    // 004c3b11  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3b13  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b16  7405                   -je 0x4c3b1d
    if (cpu.flags.zf)
    {
        goto L_0x004c3b1d;
    }
    // 004c3b18  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b1b  7501                   -jne 0x4c3b1e
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b1e;
    }
L_0x004c3b1d:
    // 004c3b1d  42                     -inc edx
    (cpu.edx)++;
L_0x004c3b1e:
    // 004c3b1e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c3b20  752c                   -jne 0x4c3b4e
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b4e;
    }
    // 004c3b22  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b25  7514                   -jne 0x4c3b3b
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b3b;
    }
    // 004c3b27  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c3b2a  80f978                 +cmp cl, 0x78
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b2d  7405                   -je 0x4c3b34
    if (cpu.flags.zf)
    {
        goto L_0x004c3b34;
    }
    // 004c3b2f  80f958                 +cmp cl, 0x58
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b32  7507                   -jne 0x4c3b3b
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b3b;
    }
L_0x004c3b34:
    // 004c3b34  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 004c3b39  eb33                   -jmp 0x4c3b6e
    goto L_0x004c3b6e;
L_0x004c3b3b:
    // 004c3b3b  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b3e  7507                   -jne 0x4c3b47
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b47;
    }
    // 004c3b40  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004c3b45  eb3c                   -jmp 0x4c3b83
    goto L_0x004c3b83;
L_0x004c3b47:
    // 004c3b47  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 004c3b4c  eb35                   -jmp 0x4c3b83
    goto L_0x004c3b83;
L_0x004c3b4e:
    // 004c3b4e  83fe02                 +cmp esi, 2
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
    // 004c3b51  7c05                   -jl 0x4c3b58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c3b58;
    }
    // 004c3b53  83fe24                 +cmp esi, 0x24
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3b56  7e11                   -jle 0x4c3b69
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c3b69;
    }
L_0x004c3b58:
    // 004c3b58  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 004c3b5d  e84e2bfeff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004c3b62  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c3b64  e9b3000000             -jmp 0x4c3c1c
    goto L_0x004c3c1c;
L_0x004c3b69:
    // 004c3b69  83fe10                 +cmp esi, 0x10
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
    // 004c3b6c  7515                   -jne 0x4c3b83
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b83;
    }
L_0x004c3b6e:
    // 004c3b6e  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b71  7510                   -jne 0x4c3b83
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b83;
    }
    // 004c3b73  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004c3b76  80ff78                 +cmp bh, 0x78
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b79  7405                   -je 0x4c3b80
    if (cpu.flags.zf)
    {
        goto L_0x004c3b80;
    }
    // 004c3b7b  80ff58                 +cmp bh, 0x58
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3b7e  7503                   -jne 0x4c3b83
    if (!cpu.flags.zf)
    {
        goto L_0x004c3b83;
    }
L_0x004c3b80:
    // 004c3b80  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004c3b83:
    // 004c3b83  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004c3b87  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c3b89  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004c3b8b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004c3b8d  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x004c3b90:
    // 004c3b90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3b92  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3b94  e89c000000             -call 0x4c3c35
    cpu.esp -= 4;
    sub_4c3c35(app, cpu);
    if (cpu.terminate) return;
    // 004c3b99  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c3b9d  39f0                   +cmp eax, esi
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
    // 004c3b9f  7d1c                   -jge 0x4c3bbd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004c3bbd;
    }
    // 004c3ba1  3b9f14104e00           +cmp ebx, dword ptr [edi + 0x4e1014]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5115924) /* 0x4e1014 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3ba7  7602                   -jbe 0x4c3bab
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c3bab;
    }
    // 004c3ba9  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004c3bab:
    // 004c3bab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c3bad  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004c3bb0  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004c3bb4  39c3                   +cmp ebx, eax
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
    // 004c3bb6  7302                   -jae 0x4c3bba
    if (!cpu.flags.cf)
    {
        goto L_0x004c3bba;
    }
    // 004c3bb8  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004c3bba:
    // 004c3bba  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004c3bbb  ebd3                   -jmp 0x4c3b90
    goto L_0x004c3b90;
L_0x004c3bbd:
    // 004c3bbd  3b542404               +cmp edx, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3bc1  7503                   -jne 0x4c3bc6
    if (!cpu.flags.zf)
    {
        goto L_0x004c3bc6;
    }
    // 004c3bc3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004c3bc6:
    // 004c3bc6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c3bc8  7403                   -je 0x4c3bcd
    if (cpu.flags.zf)
    {
        goto L_0x004c3bcd;
    }
    // 004c3bca  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x004c3bcd:
    // 004c3bcd  837c240c01             +cmp dword ptr [esp + 0xc], 1
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
    // 004c3bd2  750f                   -jne 0x4c3be3
    if (!cpu.flags.zf)
    {
        goto L_0x004c3be3;
    }
    // 004c3bd4  81fb00000080           +cmp ebx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c3bda  7207                   -jb 0x4c3be3
    if (cpu.flags.cf)
    {
        goto L_0x004c3be3;
    }
    // 004c3bdc  7509                   -jne 0x4c3be7
    if (!cpu.flags.zf)
    {
        goto L_0x004c3be7;
    }
    // 004c3bde  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3be1  7504                   -jne 0x4c3be7
    if (!cpu.flags.zf)
    {
        goto L_0x004c3be7;
    }
L_0x004c3be3:
    // 004c3be3  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004c3be5  742c                   -je 0x4c3c13
    if (cpu.flags.zf)
    {
        goto L_0x004c3c13;
    }
L_0x004c3be7:
    // 004c3be7  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004c3bec  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c3bf0  e8bb2afeff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004c3bf5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c3bf7  7507                   -jne 0x4c3c00
    if (!cpu.flags.zf)
    {
        goto L_0x004c3c00;
    }
    // 004c3bf9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c3bfe  eb1c                   -jmp 0x4c3c1c
    goto L_0x004c3c1c;
L_0x004c3c00:
    // 004c3c00  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3c03  7507                   -jne 0x4c3c0c
    if (!cpu.flags.zf)
    {
        goto L_0x004c3c0c;
    }
    // 004c3c05  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 004c3c0a  eb10                   -jmp 0x4c3c1c
    goto L_0x004c3c1c;
L_0x004c3c0c:
    // 004c3c0c  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 004c3c11  eb09                   -jmp 0x4c3c1c
    goto L_0x004c3c1c;
L_0x004c3c13:
    // 004c3c13  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3c16  7502                   -jne 0x4c3c1a
    if (!cpu.flags.zf)
    {
        goto L_0x004c3c1a;
    }
    // 004c3c18  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x004c3c1a:
    // 004c3c1a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004c3c1c:
    // 004c3c1c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c3c1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3c23(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3c23  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3c24  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004c3c26  e8b9feffff             -call 0x4c3ae4
    cpu.esp -= 4;
    sub_4c3ae4(app, cpu);
    if (cpu.terminate) return;
    // 004c3c2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3c26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c3c26;
    // 004c3c23  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3c24  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004c3c26:
    // 004c3c26  e8b9feffff             -call 0x4c3ae4
    cpu.esp -= 4;
    sub_4c3ae4(app, cpu);
    if (cpu.terminate) return;
    // 004c3c2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3c2d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3c2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3c2e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004c3c33  ebf1                   -jmp 0x4c3c26
    return sub_4c3c26(app, cpu);
}

/* align: skip  */
void Application::sub_4c3c35(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3c35  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3c36  3c30                   +cmp al, 0x30
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
    // 004c3c38  720e                   -jb 0x4c3c48
    if (cpu.flags.cf)
    {
        goto L_0x004c3c48;
    }
    // 004c3c3a  3c39                   +cmp al, 0x39
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
    // 004c3c3c  770a                   -ja 0x4c3c48
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c3c48;
    }
    // 004c3c3e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c3c43  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004c3c46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3c48:
    // 004c3c48  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c3c4d  e8885bfeff             -call 0x4a97da
    cpu.esp -= 4;
    sub_4a97da(app, cpu);
    if (cpu.terminate) return;
    // 004c3c52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3c54  3c61                   +cmp al, 0x61
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
    // 004c3c56  720d                   -jb 0x4c3c65
    if (cpu.flags.cf)
    {
        goto L_0x004c3c65;
    }
    // 004c3c58  3c69                   +cmp al, 0x69
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
    // 004c3c5a  7709                   -ja 0x4c3c65
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c3c65;
    }
    // 004c3c5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3c5e  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004c3c60  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004c3c63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3c65:
    // 004c3c65  3c6a                   +cmp al, 0x6a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3c67  720e                   -jb 0x4c3c77
    if (cpu.flags.cf)
    {
        goto L_0x004c3c77;
    }
    // 004c3c69  3c72                   +cmp al, 0x72
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
    // 004c3c6b  770a                   -ja 0x4c3c77
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c3c77;
    }
L_0x004c3c6d:
    // 004c3c6d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c3c72  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004c3c75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c3c77:
    // 004c3c77  3c73                   +cmp al, 0x73
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
    // 004c3c79  7204                   -jb 0x4c3c7f
    if (cpu.flags.cf)
    {
        goto L_0x004c3c7f;
    }
    // 004c3c7b  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3c7d  76ee                   -jbe 0x4c3c6d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c3c6d;
    }
L_0x004c3c7f:
    // 004c3c7f  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 004c3c84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3c85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3c86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3c86  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3c87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3c88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3c89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3c8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3c8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3c8c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004c3c8f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c3c91  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c3c96  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c3c9b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c3c9e  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004c3ca3  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004c3ca7  e8c8070000             -call 0x4c4474
    cpu.esp -= 4;
    sub_4c4474(app, cpu);
    if (cpu.terminate) return;
    // 004c3cac  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c3cae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3cb0  7469                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3cb2  39e8                   +cmp eax, ebp
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
    // 004c3cb4  7465                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3cb6  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c3cb8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004c3cbc  40                     -inc eax
    (cpu.eax)++;
    // 004c3cbd  e80129feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3cc2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3cc4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c3cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3cca  744f                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3ccc  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c3cd0  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004c3cd2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c3cd4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c3cd5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c3cd7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c3cd9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3cda  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3cdc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c3cdf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c3ce1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c3ce3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c3ce6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c3ce8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ce9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c3cea  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c3cee  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004c3cf1  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004c3cf5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3cf7  e82bc7feff             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 004c3cfc  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004c3d00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3d02  7446                   -je 0x4c3d4a
    if (cpu.flags.zf)
    {
        goto L_0x004c3d4a;
    }
    // 004c3d04  40                     -inc eax
    (cpu.eax)++;
    // 004c3d05  e8b928feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3d0a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c3d0c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c3d10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3d12  7511                   -jne 0x4c3d25
    if (!cpu.flags.zf)
    {
        goto L_0x004c3d25;
    }
    // 004c3d14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c3d16:
    // 004c3d16  e8dd77feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004c3d1b:
    // 004c3d1b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c3d20  e9af000000             -jmp 0x4c3dd4
    goto L_0x004c3dd4;
L_0x004c3d25:
    // 004c3d25  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c3d29  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c3d2b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c3d2c  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c3d2e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c3d30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3d31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3d33  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c3d36  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c3d38  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c3d3a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c3d3d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c3d3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3d40  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c3d41  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3d45  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004c3d48  eb04                   -jmp 0x4c3d4e
    goto L_0x004c3d4e;
L_0x004c3d4a:
    // 004c3d4a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004c3d4e:
    // 004c3d4e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c3d52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c3d53  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c3d57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3d58  2eff1580654c00         -call dword ptr cs:[0x4c6580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006720) /* 0x4c6580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c3d5f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3d61  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c3d65  e88e77feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c3d6a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c3d6e  e88577feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c3d73  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c3d75  74a4                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3d77  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c3d79  e860000000             -call 0x4c3dde
    cpu.esp -= 4;
    sub_4c3dde(app, cpu);
    if (cpu.terminate) return;
    // 004c3d7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3d80  7599                   -jne 0x4c3d1b
    if (!cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3d82  833d38945b0000         +cmp dword ptr [0x5b9438], 0
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
    // 004c3d89  7449                   -je 0x4c3dd4
    if (cpu.flags.zf)
    {
        goto L_0x004c3dd4;
    }
    // 004c3d8b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c3d8d  e895c6feff             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 004c3d92  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c3d95  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004c3d98  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004c3d9b  e82328feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3da0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c3da2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3da4  750f                   -jne 0x4c3db5
    if (!cpu.flags.zf)
    {
        goto L_0x004c3db5;
    }
    // 004c3da6  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004c3dab  e8b127feff             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 004c3db0  e966ffffff             -jmp 0x4c3d1b
    goto L_0x004c3d1b;
L_0x004c3db5:
    // 004c3db5  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004c3dba  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c3dbc  e888c6feff             -call 0x4b0449
    cpu.esp -= 4;
    sub_4b0449(app, cpu);
    if (cpu.terminate) return;
    // 004c3dc1  83f8ff                 +cmp eax, -1
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
    // 004c3dc4  7507                   -jne 0x4c3dcd
    if (!cpu.flags.zf)
    {
        goto L_0x004c3dcd;
    }
    // 004c3dc6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3dc8  e949ffffff             -jmp 0x4c3d16
    goto L_0x004c3d16;
L_0x004c3dcd:
    // 004c3dcd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3dcf  e871cbffff             -call 0x4c0945
    cpu.esp -= 4;
    sub_4c0945(app, cpu);
    if (cpu.terminate) return;
L_0x004c3dd4:
    // 004c3dd4  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004c3dd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3dd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3dd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3dda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ddb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ddc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ddd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3dd7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c3dd7;
    // 004c3c86  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3c87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3c88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3c89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3c8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3c8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3c8c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004c3c8f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c3c91  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004c3c96  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004c3c9b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004c3c9e  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004c3ca3  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004c3ca7  e8c8070000             -call 0x4c4474
    cpu.esp -= 4;
    sub_4c4474(app, cpu);
    if (cpu.terminate) return;
    // 004c3cac  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c3cae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3cb0  7469                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3cb2  39e8                   +cmp eax, ebp
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
    // 004c3cb4  7465                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3cb6  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c3cb8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004c3cbc  40                     -inc eax
    (cpu.eax)++;
    // 004c3cbd  e80129feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3cc2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3cc4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c3cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3cca  744f                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3ccc  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c3cd0  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004c3cd2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c3cd4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c3cd5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c3cd7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c3cd9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3cda  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3cdc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c3cdf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c3ce1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c3ce3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c3ce6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c3ce8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ce9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c3cea  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004c3cee  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004c3cf1  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004c3cf5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3cf7  e82bc7feff             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 004c3cfc  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004c3d00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3d02  7446                   -je 0x4c3d4a
    if (cpu.flags.zf)
    {
        goto L_0x004c3d4a;
    }
    // 004c3d04  40                     -inc eax
    (cpu.eax)++;
    // 004c3d05  e8b928feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3d0a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c3d0c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004c3d10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3d12  7511                   -jne 0x4c3d25
    if (!cpu.flags.zf)
    {
        goto L_0x004c3d25;
    }
    // 004c3d14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004c3d16:
    // 004c3d16  e8dd77feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004c3d1b:
    // 004c3d1b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c3d20  e9af000000             -jmp 0x4c3dd4
    goto L_0x004c3dd4;
L_0x004c3d25:
    // 004c3d25  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004c3d29  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c3d2b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c3d2c  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c3d2e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c3d30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3d31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3d33  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c3d36  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c3d38  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c3d3a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c3d3d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c3d3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3d40  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c3d41  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3d45  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004c3d48  eb04                   -jmp 0x4c3d4e
    goto L_0x004c3d4e;
L_0x004c3d4a:
    // 004c3d4a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004c3d4e:
    // 004c3d4e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c3d52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c3d53  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c3d57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3d58  2eff1580654c00         -call dword ptr cs:[0x4c6580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006720) /* 0x4c6580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c3d5f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3d61  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c3d65  e88e77feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c3d6a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004c3d6e  e88577feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004c3d73  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c3d75  74a4                   -je 0x4c3d1b
    if (cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3d77  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c3d79  e860000000             -call 0x4c3dde
    cpu.esp -= 4;
    sub_4c3dde(app, cpu);
    if (cpu.terminate) return;
    // 004c3d7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3d80  7599                   -jne 0x4c3d1b
    if (!cpu.flags.zf)
    {
        goto L_0x004c3d1b;
    }
    // 004c3d82  833d38945b0000         +cmp dword ptr [0x5b9438], 0
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
    // 004c3d89  7449                   -je 0x4c3dd4
    if (cpu.flags.zf)
    {
        goto L_0x004c3dd4;
    }
    // 004c3d8b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c3d8d  e895c6feff             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 004c3d92  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c3d95  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004c3d98  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004c3d9b  e82328feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3da0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c3da2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3da4  750f                   -jne 0x4c3db5
    if (!cpu.flags.zf)
    {
        goto L_0x004c3db5;
    }
    // 004c3da6  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004c3dab  e8b127feff             -call 0x4a6561
    cpu.esp -= 4;
    sub_4a6561(app, cpu);
    if (cpu.terminate) return;
    // 004c3db0  e966ffffff             -jmp 0x4c3d1b
    goto L_0x004c3d1b;
L_0x004c3db5:
    // 004c3db5  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004c3dba  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c3dbc  e888c6feff             -call 0x4b0449
    cpu.esp -= 4;
    sub_4b0449(app, cpu);
    if (cpu.terminate) return;
    // 004c3dc1  83f8ff                 +cmp eax, -1
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
    // 004c3dc4  7507                   -jne 0x4c3dcd
    if (!cpu.flags.zf)
    {
        goto L_0x004c3dcd;
    }
    // 004c3dc6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3dc8  e949ffffff             -jmp 0x4c3d16
    goto L_0x004c3d16;
L_0x004c3dcd:
    // 004c3dcd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3dcf  e871cbffff             -call 0x4c0945
    cpu.esp -= 4;
    sub_4c0945(app, cpu);
    if (cpu.terminate) return;
L_0x004c3dd4:
    // 004c3dd4  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_entry_0x004c3dd7:
    // 004c3dd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3dd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3dd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3dda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ddb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ddc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ddd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c3dde(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3dde  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3ddf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3de0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c3de1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3de2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3de3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3de4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004c3de7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c3de8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3dea  750a                   -jne 0x4c3df6
    if (!cpu.flags.zf)
    {
        goto L_0x004c3df6;
    }
L_0x004c3dec:
    // 004c3dec  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004c3df1  e94b010000             -jmp 0x4c3f41
    goto L_0x004c3f41;
L_0x004c3df6:
    // 004c3df6  803800                 +cmp byte ptr [eax], 0
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
    // 004c3df9  7411                   -je 0x4c3e0c
    if (cpu.flags.zf)
    {
        goto L_0x004c3e0c;
    }
    // 004c3dfb  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c3dfe  eb06                   -jmp 0x4c3e06
    goto L_0x004c3e06;
L_0x004c3e00:
    // 004c3e00  80ff3d                 +cmp bh, 0x3d
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3e03  7407                   -je 0x4c3e0c
    if (cpu.flags.zf)
    {
        goto L_0x004c3e0c;
    }
    // 004c3e05  42                     -inc edx
    (cpu.edx)++;
L_0x004c3e06:
    // 004c3e06  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3e08  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004c3e0a  75f4                   -jne 0x4c3e00
    if (!cpu.flags.zf)
    {
        goto L_0x004c3e00;
    }
L_0x004c3e0c:
    // 004c3e0c  803a00                 +cmp byte ptr [edx], 0
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
    // 004c3e0f  74db                   -je 0x4c3dec
    if (cpu.flags.zf)
    {
        goto L_0x004c3dec;
    }
    // 004c3e11  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3e15  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004c3e18  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 004c3e1b  a134945b00             -mov eax, dword ptr [0x5b9434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004c3e20  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c3e24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3e26  7531                   -jne 0x4c3e59
    if (!cpu.flags.zf)
    {
        goto L_0x004c3e59;
    }
    // 004c3e28  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c3e2a  0f8511010000           -jne 0x4c3f41
    if (!cpu.flags.zf)
    {
        goto L_0x004c3f41;
    }
    // 004c3e30  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004c3e35  e88927feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3e3a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c3e3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3e40  74aa                   -je 0x4c3dec
    if (cpu.flags.zf)
    {
        goto L_0x004c3dec;
    }
    // 004c3e42  a334945b00             -mov dword ptr [0x5b9434], eax
    app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */) = cpu.eax;
    // 004c3e47  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 004c3e49  83c008                 +add eax, 8
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
    // 004c3e4c  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 004c3e4f  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
    // 004c3e54  e9cd000000             -jmp 0x4c3f26
    goto L_0x004c3f26;
L_0x004c3e59:
    // 004c3e59  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004c3e5c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004c3e5e  e8e6000000             -call 0x4c3f49
    cpu.esp -= 4;
    sub_4c3f49(app, cpu);
    if (cpu.terminate) return;
    // 004c3e63  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c3e65  0f85d4000000           -jne 0x4c3f3f
    if (!cpu.flags.zf)
    {
        goto L_0x004c3f3f;
    }
    // 004c3e6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3e6d  0f8fb0000000           -jg 0x4c3f23
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c3f23;
    }
    // 004c3e73  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004c3e75  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004c3e77  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004c3e7a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004c3e7c  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004c3e7f  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004c3e82  8b3530945b00           -mov esi, dword ptr [0x5b9430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c3e88  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004c3e8c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004c3e8e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c3e90  7545                   -jne 0x4c3ed7
    if (!cpu.flags.zf)
    {
        goto L_0x004c3ed7;
    }
    // 004c3e92  e82c27feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004c3e97  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3e99  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c3e9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3e9f  0f8447ffffff           -je 0x4c3dec
    if (cpu.flags.zf)
    {
        goto L_0x004c3dec;
    }
    // 004c3ea5  8b3534945b00           -mov esi, dword ptr [0x5b9434]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004c3eab  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c3ead  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c3eae  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c3eb0  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c3eb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3eb3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3eb5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004c3eb8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c3eba  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004c3ebc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004c3ebf  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c3ec1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c3ec2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c3ec3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c3ec7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c3ec9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004c3ecb  a330945b00             -mov dword ptr [0x5b9430], eax
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.eax;
    // 004c3ed0  e85ae7fcff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c3ed5  eb32                   -jmp 0x4c3f09
    goto L_0x004c3f09;
L_0x004c3ed7:
    // 004c3ed7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c3ed9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c3edd  e809cafeff             -call 0x4b08eb
    cpu.esp -= 4;
    sub_4b08eb(app, cpu);
    if (cpu.terminate) return;
    // 004c3ee2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004c3ee6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c3ee8  0f84fefeffff           -je 0x4c3dec
    if (cpu.flags.zf)
    {
        goto L_0x004c3dec;
    }
    // 004c3eee  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c3ef2  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c3ef8  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c3efa  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004c3efc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3efe  e862cafeff             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 004c3f03  890d30945b00           -mov dword ptr [0x5b9430], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.ecx;
L_0x004c3f09:
    // 004c3f09  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c3f0b  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c3f0f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c3f12  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004c3f14  893d34945b00           -mov dword ptr [0x5b9434], edi
    app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */) = cpu.edi;
    // 004c3f1a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004c3f21  eb03                   -jmp 0x4c3f26
    goto L_0x004c3f26;
L_0x004c3f23:
    // 004c3f23  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004c3f26:
    // 004c3f26  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004c3f28  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c3f2c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c3f2f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c3f31  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004c3f34  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004c3f36  a130945b00             -mov eax, dword ptr [0x5b9430]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c3f3b  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x004c3f3f:
    // 004c3f3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c3f41:
    // 004c3f41  83c40c                 +add esp, 0xc
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
    // 004c3f44  e98efeffff             -jmp 0x4c3dd7
    return sub_4c3dd7(app, cpu);
}

/* align: skip  */
void Application::sub_4c3f49(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c3f49  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c3f4a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c3f4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c3f4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c3f4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c3f4e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004c3f50  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c3f52  8b3534945b00           -mov esi, dword ptr [0x5b9434]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004c3f58  e9b2000000             -jmp 0x4c400f
    goto L_0x004c400f;
L_0x004c3f5d:
    // 004c3f5d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004c3f5f  e99f000000             -jmp 0x4c4003
    goto L_0x004c4003;
L_0x004c3f64:
    // 004c3f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3f66  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004c3f68  e8b525fcff             -call 0x486522
    cpu.esp -= 4;
    sub_486522(app, cpu);
    if (cpu.terminate) return;
    // 004c3f6d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c3f6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c3f71  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004c3f73  e8aa25fcff             -call 0x486522
    cpu.esp -= 4;
    sub_486522(app, cpu);
    if (cpu.terminate) return;
    // 004c3f78  39c1                   +cmp ecx, eax
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
    // 004c3f7a  0f858c000000           -jne 0x4c400c
    if (!cpu.flags.zf)
    {
        goto L_0x004c400c;
    }
    // 004c3f80  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3f83  0f8578000000           -jne 0x4c4001
    if (!cpu.flags.zf)
    {
        goto L_0x004c4001;
    }
    // 004c3f89  8b1534945b00           -mov edx, dword ptr [0x5b9434]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004c3f8f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004c3f91  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c3f93  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004c3f96  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004c3f98  7462                   -je 0x4c3ffc
    if (cpu.flags.zf)
    {
        goto L_0x004c3ffc;
    }
    // 004c3f9a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004c3f9c  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c3f9e  eb08                   -jmp 0x4c3fa8
    goto L_0x004c3fa8;
L_0x004c3fa0:
    // 004c3fa0  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004c3fa3  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004c3fa5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004c3fa8:
    // 004c3fa8  833900                 +cmp dword ptr [ecx], 0
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
    // 004c3fab  75f3                   -jne 0x4c3fa0
    if (!cpu.flags.zf)
    {
        goto L_0x004c3fa0;
    }
    // 004c3fad  8b3530945b00           -mov esi, dword ptr [0x5b9430]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c3fb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c3fb5  7441                   -je 0x4c3ff8
    if (cpu.flags.zf)
    {
        goto L_0x004c3ff8;
    }
    // 004c3fb7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c3fb9  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c3fbd  7407                   -je 0x4c3fc6
    if (cpu.flags.zf)
    {
        goto L_0x004c3fc6;
    }
    // 004c3fbf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c3fc1  e83275feff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004c3fc6:
    // 004c3fc6  8b2d34945b00           -mov ebp, dword ptr [0x5b9434]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004c3fcc  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c3fce  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004c3fd0  8b1530945b00           -mov edx, dword ptr [0x5b9430]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */);
    // 004c3fd6  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004c3fd9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c3fdb  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004c3fdd  e883c9feff             -call 0x4b0965
    cpu.esp -= 4;
    sub_4b0965(app, cpu);
    if (cpu.terminate) return;
    // 004c3fe2  890d30945b00           -mov dword ptr [0x5b9430], ecx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.ecx;
    // 004c3fe8  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004c3feb  eb07                   -jmp 0x4c3ff4
    goto L_0x004c3ff4;
L_0x004c3fed:
    // 004c3fed  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c3ff0  47                     -inc edi
    (cpu.edi)++;
    // 004c3ff1  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c3ff3  40                     -inc eax
    (cpu.eax)++;
L_0x004c3ff4:
    // 004c3ff4  39f7                   +cmp edi, esi
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
    // 004c3ff6  7cf5                   -jl 0x4c3fed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004c3fed;
    }
L_0x004c3ff8:
    // 004c3ff8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004c3ffa  eb27                   -jmp 0x4c4023
    goto L_0x004c4023;
L_0x004c3ffc:
    // 004c3ffc  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c3fff  eb22                   -jmp 0x4c4023
    goto L_0x004c4023;
L_0x004c4001:
    // 004c4001  42                     -inc edx
    (cpu.edx)++;
    // 004c4002  43                     -inc ebx
    (cpu.ebx)++;
L_0x004c4003:
    // 004c4003  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004c4006  0f8558ffffff           -jne 0x4c3f64
    if (!cpu.flags.zf)
    {
        goto L_0x004c3f64;
    }
L_0x004c400c:
    // 004c400c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004c400f:
    // 004c400f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004c4011  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c4013  0f8544ffffff           -jne 0x4c3f5d
    if (!cpu.flags.zf)
    {
        goto L_0x004c3f5d;
    }
    // 004c4019  a134945b00             -mov eax, dword ptr [0x5b9434]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004c401e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004c4020  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004c4023:
    // 004c4023  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4024  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4025  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4026  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4027  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4029(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4029  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c402a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004c402c:
    // 004c402c  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004c402f  740c                   -je 0x4c403d
    if (cpu.flags.zf)
    {
        goto L_0x004c403d;
    }
    // 004c4031  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c4033  40                     -inc eax
    (cpu.eax)++;
    // 004c4034  40                     -inc eax
    (cpu.eax)++;
    // 004c4035  66833a00               +cmp word ptr [edx], 0
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
    // 004c4039  75f1                   -jne 0x4c402c
    if (!cpu.flags.zf)
    {
        goto L_0x004c402c;
    }
    // 004c403b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c403d:
    // 004c403d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c403e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c4040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4040  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c4042  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c4044  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4045(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4045  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c404a  e881040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c404f  eb1d                   -jmp 0x4c406e
    goto L_0x004c406e;
    // 004c4051  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c4056  e875040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c405b  eb11                   -jmp 0x4c406e
    goto L_0x004c406e;
    // 004c405d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c405e  e86226feff             -call 0x4a66c5
    cpu.esp -= 4;
    sub_4a66c5(app, cpu);
    if (cpu.terminate) return;
    // 004c4063  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c4068  e863040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c406d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c406e:
    // 004c406e  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c4073  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c4078  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c407a  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c407c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c405d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c405d;
    // 004c4045  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c404a  e881040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c404f  eb1d                   -jmp 0x4c406e
    goto L_0x004c406e;
    // 004c4051  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c4056  e875040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c405b  eb11                   -jmp 0x4c406e
    goto L_0x004c406e;
L_entry_0x004c405d:
    // 004c405d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c405e  e86226feff             -call 0x4a66c5
    cpu.esp -= 4;
    sub_4a66c5(app, cpu);
    if (cpu.terminate) return;
    // 004c4063  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c4068  e863040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c406d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c406e:
    // 004c406e  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c4073  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c4078  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c407a  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c407c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4051(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004c4051;
    // 004c4045  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c404a  e881040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c404f  eb1d                   -jmp 0x4c406e
    goto L_0x004c406e;
L_entry_0x004c4051:
    // 004c4051  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c4056  e875040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c405b  eb11                   -jmp 0x4c406e
    goto L_0x004c406e;
    // 004c405d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c405e  e86226feff             -call 0x4a66c5
    cpu.esp -= 4;
    sub_4a66c5(app, cpu);
    if (cpu.terminate) return;
    // 004c4063  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c4068  e863040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c406d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c406e:
    // 004c406e  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c4073  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 004c4078  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c407a  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c407c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c407d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c407d  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 004c4082  e849040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c4087  eb11                   -jmp 0x4c409a
    goto L_0x004c409a;
    // 004c4089  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c408a  e83626feff             -call 0x4a66c5
    cpu.esp -= 4;
    sub_4a66c5(app, cpu);
    if (cpu.terminate) return;
    // 004c408f  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 004c4094  e837040000             -call 0x4c44d0
    cpu.esp -= 4;
    sub_4c44d0(app, cpu);
    if (cpu.terminate) return;
    // 004c4099  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004c409a:
    // 004c409a  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 004c409f  0d0000807f             -or eax, 0x7f800000
    cpu.eax |= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 004c40a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4c40a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c40a8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c40a9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c40ab  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004c40ac  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c40af  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c40b2  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004c40b5  83f907                 +cmp ecx, 7
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
    // 004c40b8  7e42                   -jle 0x4c40fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c40fc;
    }
    // 004c40ba  83e907                 -sub ecx, 7
    (cpu.ecx) -= x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004c40bd:
    // 004c40bd  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004c40bf  df4702                 -fild word ptr [edi + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */))));
    // 004c40c2  df4704                 -fild word ptr [edi + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 004c40c5  df4706                 -fild word ptr [edi + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */))));
    // 004c40c8  df4708                 -fild word ptr [edi + 8]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 004c40cb  df470a                 -fild word ptr [edi + 0xa]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */))));
    // 004c40ce  df470c                 -fild word ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 004c40d1  df470e                 -fild word ptr [edi + 0xe]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(14) /* 0xe */))));
    // 004c40d4  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 004c40d6  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40d9  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40dc  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40df  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40e2  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40e5  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40e8  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40eb  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c40ee  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c40f1  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004c40f4  83e908                 +sub ecx, 8
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
    // 004c40f7  7fc4                   -jg 0x4c40bd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c40bd;
    }
    // 004c40f9  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004c40fc:
    // 004c40fc  83f900                 +cmp ecx, 0
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
    // 004c40ff  7e10                   -jle 0x4c4111
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c4111;
    }
    // 004c4101  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004c4103  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004c4106  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004c4109  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c410c  83e901                 +sub ecx, 1
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
    // 004c410f  7feb                   -jg 0x4c40fc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c40fc;
    }
L_0x004c4111:
    // 004c4111  61                     -popal 
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
    // 004c4112  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4113  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4114(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4114  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4115  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c4117  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004c4118  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004c411b  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004c411e  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004c4121  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c4123  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c4125  83f903                 +cmp ecx, 3
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
    // 004c4128  7e44                   -jle 0x4c416e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c416e;
    }
    // 004c412a  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004c412d:
    // 004c412d  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c412f  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004c4132  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c4135  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c4138  8b1c85e4a45b00         -mov ebx, dword ptr [eax*4 + 0x5ba4e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6005988) /* 0x5ba4e4 */ + cpu.eax * 4);
    // 004c413f  8b3495e4a45b00         -mov esi, dword ptr [edx*4 + 0x5ba4e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6005988) /* 0x5ba4e4 */ + cpu.edx * 4);
    // 004c4146  8a47fe                 -mov al, byte ptr [edi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 004c4149  8a57ff                 -mov dl, byte ptr [edi - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004c414c  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004c414f  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004c4152  8b1c85e4a45b00         -mov ebx, dword ptr [eax*4 + 0x5ba4e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6005988) /* 0x5ba4e4 */ + cpu.eax * 4);
    // 004c4159  8b3495e4a45b00         -mov esi, dword ptr [edx*4 + 0x5ba4e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6005988) /* 0x5ba4e4 */ + cpu.edx * 4);
    // 004c4160  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004c4163  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004c4166  83e904                 +sub ecx, 4
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
    // 004c4169  7fc2                   -jg 0x4c412d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c412d;
    }
    // 004c416b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004c416e:
    // 004c416e  83f900                 +cmp ecx, 0
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
    // 004c4171  7e17                   -jle 0x4c418a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004c418a;
    }
    // 004c4173  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004c4175  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004c4178  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c417b  8b1c85e4a45b00         -mov ebx, dword ptr [eax*4 + 0x5ba4e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6005988) /* 0x5ba4e4 */ + cpu.eax * 4);
    // 004c4182  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004c4185  83e901                 +sub ecx, 1
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
    // 004c4188  7fe4                   -jg 0x4c416e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004c416e;
    }
L_0x004c418a:
    // 004c418a  61                     -popal 
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
    // 004c418b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c418c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c418d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c418d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c418e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c418f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c4190  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c4191  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004c4193  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004c4195  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4196  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c4198  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004c419b  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004c419e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004c41a0  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004c41a3  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004c41a6  8b15ac675b00           -mov edx, dword ptr [0x5b67ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990316) /* 0x5b67ac */);
    // 004c41ac  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004c41ae  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004c41b1  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004c41b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004c41b6  753e                   -jne 0x4c41f6
    if (!cpu.flags.zf)
    {
        goto L_0x004c41f6;
    }
    // 004c41b8  a150094e00             -mov eax, dword ptr [0x4e0950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004c41bd  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004c41c0  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004c41c2  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004c41c4  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004c41c6  8b1d50094e00           -mov ebx, dword ptr [0x4e0950]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004c41cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c41ce  e85ce4fcff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004c41d3  a150094e00             -mov eax, dword ptr [0x4e0950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114192) /* 0x4e0950 */);
    // 004c41d8  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004c41de  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c41e0  e82443ffff             -call 0x4b8509
    cpu.esp -= 4;
    sub_4b8509(app, cpu);
    if (cpu.terminate) return;
    // 004c41e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c41e7  750d                   -jne 0x4c41f6
    if (!cpu.flags.zf)
    {
        goto L_0x004c41f6;
    }
    // 004c41e9  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004c41ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c41ed  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c41f4  eb32                   -jmp 0x4c4228
    goto L_0x004c4228;
L_0x004c41f6:
    // 004c41f6  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004c41f9  ff1558ed4d00           -call dword ptr [0x4ded58]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107032) /* 0x4ded58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c41ff  8998de000000           -mov dword ptr [eax + 0xde], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */) = cpu.ebx;
    // 004c4205  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004c4208  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c4209  2eff1588654c00         -call dword ptr cs:[0x4c6588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006728) /* 0x4c6588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4210  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004c4213  e8cb4affff             -call 0x4b8ce3
    cpu.esp -= 4;
    sub_4b8ce3(app, cpu);
    if (cpu.terminate) return;
    // 004c4218  ff1598ed4d00           -call dword ptr [0x4ded98]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107096) /* 0x4ded98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c421e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004c4220  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4223  e872f5ffff             -call 0x4c379a
    cpu.esp -= 4;
    sub_4c379a(app, cpu);
    if (cpu.terminate) return;
L_0x004c4228:
    // 004c4228  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004c422a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c422b  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c422d  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c422f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c4230  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4231  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4232  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4234  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c4235  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c4236  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c4237  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004c4238  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4239  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004c423c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c423e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004c4240  833d54ed4d00ff         +cmp dword ptr [0x4ded54], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107028) /* 0x4ded54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4247  7512                   -jne 0x4c425b
    if (!cpu.flags.zf)
    {
        goto L_0x004c425b;
    }
    // 004c4249  e86642ffff             -call 0x4b84b4
    cpu.esp -= 4;
    sub_4b84b4(app, cpu);
    if (cpu.terminate) return;
    // 004c424e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4250  0f84ae000000           -je 0x4c4304
    if (cpu.flags.zf)
    {
        goto L_0x004c4304;
    }
    // 004c4256  e87e43ffff             -call 0x4b85d9
    cpu.esp -= 4;
    sub_4b85d9(app, cpu);
    if (cpu.terminate) return;
L_0x004c425b:
    // 004c425b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004c425f  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004c4263  2eff15d0644c00         -call dword ptr cs:[0x4c64d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006544) /* 0x4c64d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c426a  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004c426e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004c4270  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004c4272  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004c4274  be0c1f4d00             -mov esi, 0x4d1f0c
    cpu.esi = 5054220 /*0x4d1f0c*/;
    // 004c4279  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004c427e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c427f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004c4280  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004c4281  2eff15cc644c00         -call dword ptr cs:[0x4c64cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006540) /* 0x4c64cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4288  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c428c  e8ed78ffff             -call 0x4bbb7e
    cpu.esp -= 4;
    sub_4bbb7e(app, cpu);
    if (cpu.terminate) return;
    // 004c4291  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c4293  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c4294  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c4296  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c4298  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c429a  2eff1558644c00         -call dword ptr cs:[0x4c6458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006424) /* 0x4c6458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c42a1  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004c42a5  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004c42a9  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004c42ad  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004c42b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c42b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c42b4  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004c42b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c42b9  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004c42bf  688d414c00             -push 0x4c418d
    app->getMemory<x86::reg32>(cpu.esp-4) = 4997517 /*0x4c418d*/;
    cpu.esp -= 4;
    // 004c42c4  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 004c42ca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c42cb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c42cd  2eff1568644c00         -call dword ptr cs:[0x4c6468]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006440) /* 0x4c6468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c42d4  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004c42d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c42da  750a                   -jne 0x4c42e6
    if (!cpu.flags.zf)
    {
        goto L_0x004c42e6;
    }
    // 004c42dc  c7442438ffffffff       -mov dword ptr [esp + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 004c42e4  eb0e                   -jmp 0x4c42f4
    goto L_0x004c42f4;
L_0x004c42e6:
    // 004c42e6  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004c42e8  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004c42ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c42ed  2eff15d8654c00         -call dword ptr cs:[0x4c65d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006808) /* 0x4c65d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c42f4:
    // 004c42f4  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004c42f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c42f9  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4300  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
L_0x004c4304:
    // 004c4304  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004c4307  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4308  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004c4309  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c430a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c430b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c430c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c430d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c430d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c430e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c430f  ff159ced4d00           -call dword ptr [0x4ded9c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107100) /* 0x4ded9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4315  e8154affff             -call 0x4b8d2f
    cpu.esp -= 4;
    sub_4b8d2f(app, cpu);
    if (cpu.terminate) return;
    // 004c431a  833dac675b0000         +cmp dword ptr [0x5b67ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5990316) /* 0x5b67ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4321  750a                   -jne 0x4c432d
    if (!cpu.flags.zf)
    {
        goto L_0x004c432d;
    }
    // 004c4323  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c4328  e82b42ffff             -call 0x4b8558
    cpu.esp -= 4;
    sub_4b8558(app, cpu);
    if (cpu.terminate) return;
L_0x004c432d:
    // 004c432d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004c432f  2eff1588644c00         -call dword ptr cs:[0x4c6488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006472) /* 0x4c6488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4336  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4337  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4338  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4339(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4339  a3c4104e00             -mov dword ptr [0x4e10c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5116100) /* 0x4e10c4 */) = cpu.eax;
    // 004c433e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c433f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c433f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c4340  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c4341  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c4342  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004c4344  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c4346  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004c434b  e88d010000             -call 0x4c44dd
    cpu.esp -= 4;
    sub_4c44dd(app, cpu);
    if (cpu.terminate) return;
    // 004c4350  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c4352  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c4354  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c4356  8b0485a8104e00         -mov eax, dword ptr [eax*4 + 0x4e10a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5116072) /* 0x4e10a8 */ + cpu.eax * 4);
    // 004c435d  e89a010000             -call 0x4c44fc
    cpu.esp -= 4;
    sub_4c44fc(app, cpu);
    if (cpu.terminate) return;
    // 004c4362  b89d1f4d00             -mov eax, 0x4d1f9d
    cpu.eax = 5054365 /*0x4d1f9d*/;
    // 004c4367  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c4369  e88e010000             -call 0x4c44fc
    cpu.esp -= 4;
    sub_4c44fc(app, cpu);
    if (cpu.terminate) return;
    // 004c436e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c4370  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c4372  e885010000             -call 0x4c44fc
    cpu.esp -= 4;
    sub_4c44fc(app, cpu);
    if (cpu.terminate) return;
    // 004c4377  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004c437c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c437e  e862edfeff             -call 0x4b30e5
    cpu.esp -= 4;
    sub_4b30e5(app, cpu);
    if (cpu.terminate) return;
    // 004c4383  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4384  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4387(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4387  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c4388  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c4389  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c438b  ff15c4104e00           -call dword ptr [0x4e10c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116100) /* 0x4e10c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4391  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4393  751b                   -jne 0x4c43b0
    if (!cpu.flags.zf)
    {
        goto L_0x004c43b0;
    }
    // 004c4395  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004c4398  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004c439a  e8a0ffffff             -call 0x4c433f
    cpu.esp -= 4;
    sub_4c433f(app, cpu);
    if (cpu.terminate) return;
    // 004c439f  833b01                 +cmp dword ptr [ebx], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c43a2  7507                   -jne 0x4c43ab
    if (!cpu.flags.zf)
    {
        goto L_0x004c43ab;
    }
    // 004c43a4  e81523feff             -call 0x4a66be
    cpu.esp -= 4;
    sub_4a66be(app, cpu);
    if (cpu.terminate) return;
    // 004c43a9  eb05                   -jmp 0x4c43b0
    goto L_0x004c43b0;
L_0x004c43ab:
    // 004c43ab  e81523feff             -call 0x4a66c5
    cpu.esp -= 4;
    sub_4a66c5(app, cpu);
    if (cpu.terminate) return;
L_0x004c43b0:
    // 004c43b0  dd4318                 -fld qword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004c43b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c43b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c43b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c43b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c43b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c43b7  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c43be  7428                   -je 0x4c43e8
    if (cpu.flags.zf)
    {
        goto L_0x004c43e8;
    }
    // 004c43c0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c43c2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c43c4  8a92d5a35b00           -mov dl, byte ptr [edx + 0x5ba3d5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004c43ca  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c43cd  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c43d3  7413                   -je 0x4c43e8
    if (cpu.flags.zf)
    {
        goto L_0x004c43e8;
    }
    // 004c43d5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c43d7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004c43d9  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004c43dc  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004c43df  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c43e4  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004c43e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c43e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c43e8:
    // 004c43e8  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004c43ea  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c43ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c43f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c43f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c43f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c43f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c43f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c43f4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c43f7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c43f9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c43fb  e85a000000             -call 0x4c445a
    cpu.esp -= 4;
    sub_4c445a(app, cpu);
    if (cpu.terminate) return;
    // 004c4400  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c4402  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004c4404  e898b4ffff             -call 0x4bf8a1
    cpu.esp -= 4;
    sub_4bf8a1(app, cpu);
    if (cpu.terminate) return;
    // 004c4409  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004c440c  813d6c0a4e00a4030000   +cmp dword ptr [0x4e0a6c], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114476) /* 0x4e0a6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4416  7526                   -jne 0x4c443e
    if (!cpu.flags.zf)
    {
        goto L_0x004c443e;
    }
    // 004c4418  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c441f  741d                   -je 0x4c443e
    if (cpu.flags.zf)
    {
        goto L_0x004c443e;
    }
    // 004c4421  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c4423  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004c4426  8a80d5a35b00           -mov al, byte ptr [eax + 0x5ba3d5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004c442c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c442e  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c4433  7409                   -je 0x4c443e
    if (cpu.flags.zf)
    {
        goto L_0x004c443e;
    }
    // 004c4435  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c4437  e856010000             -call 0x4c4592
    cpu.esp -= 4;
    sub_4c4592(app, cpu);
    if (cpu.terminate) return;
    // 004c443c  eb15                   -jmp 0x4c4453
    goto L_0x004c4453;
L_0x004c443e:
    // 004c443e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004c4440  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004c4444  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004c4445  2eff15c4634c00         -call dword ptr cs:[0x4c63c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006276) /* 0x4c63c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c444c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c444e  e863ffffff             -call 0x4c43b6
    cpu.esp -= 4;
    sub_4c43b6(app, cpu);
    if (cpu.terminate) return;
L_0x004c4453:
    // 004c4453  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c4456  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4457  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4458  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4459  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c445a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c445a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c445b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c445d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c445f  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 004c4462  740c                   -je 0x4c4470
    if (cpu.flags.zf)
    {
        goto L_0x004c4470;
    }
    // 004c4464  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c4466  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004c4469  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004c446c  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004c446e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c446f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c4470:
    // 004c4470  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004c4472  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4473  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4474  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c4475  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c4476  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c4479  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c447b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004c447d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c447f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004c4481  e8d4ffffff             -call 0x4c445a
    cpu.esp -= 4;
    sub_4c445a(app, cpu);
    if (cpu.terminate) return;
    // 004c4486  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004c4488  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004c448a  e812b4ffff             -call 0x4bf8a1
    cpu.esp -= 4;
    sub_4bf8a1(app, cpu);
    if (cpu.terminate) return;
    // 004c448f  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x004c4492:
    // 004c4492  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c4494  e83069ffff             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004c4499  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c449b  7518                   -jne 0x4c44b5
    if (!cpu.flags.zf)
    {
        goto L_0x004c44b5;
    }
    // 004c449d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004c449f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c44a1  e8e6f5ffff             -call 0x4c3a8c
    cpu.esp -= 4;
    sub_4c3a8c(app, cpu);
    if (cpu.terminate) return;
    // 004c44a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c44a8  740b                   -je 0x4c44b5
    if (cpu.flags.zf)
    {
        goto L_0x004c44b5;
    }
    // 004c44aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c44ac  e85469ffff             -call 0x4bae05
    cpu.esp -= 4;
    sub_4bae05(app, cpu);
    if (cpu.terminate) return;
    // 004c44b1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004c44b3  ebdd                   -jmp 0x4c4492
    goto L_0x004c4492;
L_0x004c44b5:
    // 004c44b5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c44b7  e80d69ffff             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004c44bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c44be  7404                   -je 0x4c44c4
    if (cpu.flags.zf)
    {
        goto L_0x004c44c4;
    }
    // 004c44c0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004c44c2  7504                   -jne 0x4c44c8
    if (!cpu.flags.zf)
    {
        goto L_0x004c44c8;
    }
L_0x004c44c4:
    // 004c44c4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c44c6  eb02                   -jmp 0x4c44ca
    goto L_0x004c44ca;
L_0x004c44c8:
    // 004c44c8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c44ca:
    // 004c44ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004c44cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c44ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c44cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c44d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c44d0  ff151fdb4d00           -call dword ptr [0x4ddb1f]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102367) /* 0x4ddb1f */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c44d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c44d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c44d8  e9c8000000             -jmp 0x4c45a5
    return sub_4c45a5(app, cpu);
}

/* align: skip  */
void Application::sub_4c44dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c44dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c44de  83f803                 +cmp eax, 3
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
    // 004c44e1  7604                   -jbe 0x4c44e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004c44e7;
    }
    // 004c44e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c44e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c44e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c44e7:
    // 004c44e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c44e9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c44ec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004c44ee  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004c44f1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004c44f3  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004c44f5  0544eb4d00             -add eax, 0x4deb44
    (cpu.eax) += x86::reg32(x86::sreg32(5106500 /*0x4deb44*/));
    // 004c44fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c44fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c44fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c44fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004c44fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004c44fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004c44ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004c4500  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4501  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004c4503  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004c4505  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004c4508  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c450e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004c4511  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004c4515  7507                   -jne 0x4c451e
    if (!cpu.flags.zf)
    {
        goto L_0x004c451e;
    }
    // 004c4517  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c4519  e8edbcfeff             -call 0x4b020b
    cpu.esp -= 4;
    sub_4b020b(app, cpu);
    if (cpu.terminate) return;
L_0x004c451e:
    // 004c451e  8a630d                 -mov ah, byte ptr [ebx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004c4521  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004c4523  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004c4526  7415                   -je 0x4c453d
    if (cpu.flags.zf)
    {
        goto L_0x004c453d;
    }
    // 004c4528  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004c452a  80e2f9                 -and dl, 0xf9
    cpu.dl &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004c452d  88530d                 -mov byte ptr [ebx + 0xd], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.dl;
    // 004c4530  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004c4532  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004c4535  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004c453a  88730d                 -mov byte ptr [ebx + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.dh;
L_0x004c453d:
    // 004c453d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004c453f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004c4541:
    // 004c4541  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c4543  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004c4545  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4547  740f                   -je 0x4c4558
    if (cpu.flags.zf)
    {
        goto L_0x004c4558;
    }
    // 004c4549  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004c454b  41                     -inc ecx
    (cpu.ecx)++;
    // 004c454c  e894ebfeff             -call 0x4b30e5
    cpu.esp -= 4;
    sub_4b30e5(app, cpu);
    if (cpu.terminate) return;
    // 004c4551  83f8ff                 +cmp eax, -1
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
    // 004c4554  75eb                   -jne 0x4c4541
    if (!cpu.flags.zf)
    {
        goto L_0x004c4541;
    }
    // 004c4556  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004c4558:
    // 004c4558  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004c455a  741d                   -je 0x4c4579
    if (cpu.flags.zf)
    {
        goto L_0x004c4579;
    }
    // 004c455c  8a430d                 -mov al, byte ptr [ebx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004c455f  24f9                   -and al, 0xf9
    cpu.al &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004c4561  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004c4564  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004c4566  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004c4569  88630d                 -mov byte ptr [ebx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004c456c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c456e  7509                   -jne 0x4c4579
    if (!cpu.flags.zf)
    {
        goto L_0x004c4579;
    }
    // 004c4570  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004c4572  e8186dfeff             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
    // 004c4577  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004c4579:
    // 004c4579  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004c457b  7504                   -jne 0x4c4581
    if (!cpu.flags.zf)
    {
        goto L_0x004c4581;
    }
    // 004c457d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004c457f  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004c4581:
    // 004c4581  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004c4584  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c458a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004c458c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c458d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c458e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c458f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4590  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4591  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c4592(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4592  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c4593  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c4595  e80e000000             -call 0x4c45a8
    cpu.esp -= 4;
    sub_4c45a8(app, cpu);
    if (cpu.terminate) return;
    // 004c459a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c459c  7403                   -je 0x4c45a1
    if (cpu.flags.zf)
    {
        goto L_0x004c45a1;
    }
    // 004c459e  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x004c45a1:
    // 004c45a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c45a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c45a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c45a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c45a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c45a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c45a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c45a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c45a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c45ab  e83b000000             -call 0x4c45eb
    cpu.esp -= 4;
    sub_4c45eb(app, cpu);
    if (cpu.terminate) return;
    // 004c45b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c45b2  741f                   -je 0x4c45d3
    if (cpu.flags.zf)
    {
        goto L_0x004c45d3;
    }
    // 004c45b4  81fa81820000           +cmp edx, 0x8281
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33409 /*0x8281*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c45ba  7211                   -jb 0x4c45cd
    if (cpu.flags.cf)
    {
        goto L_0x004c45cd;
    }
    // 004c45bc  81fa9a820000           +cmp edx, 0x829a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33434 /*0x829a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c45c2  7709                   -ja 0x4c45cd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004c45cd;
    }
    // 004c45c4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004c45c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c45cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c45cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c45cd:
    // 004c45cd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c45cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c45d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c45d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c45d3:
    // 004c45d3  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004c45d5  fec0                   -inc al
    (cpu.al)++;
    // 004c45d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c45d9  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004c45db  8a8264ef4d00           -mov al, byte ptr [edx + 0x4def64]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5107556) /* 0x4def64 */);
    // 004c45e1  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004c45e3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004c45e5  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004c45e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004c45e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c45ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c45eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c45eb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004c45ec  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c45f3  7431                   -je 0x4c4626
    if (cpu.flags.zf)
    {
        goto L_0x004c4626;
    }
    // 004c45f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004c45f7  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004c45fa  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c4600  8a92d5a35b00           -mov dl, byte ptr [edx + 0x5ba3d5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004c4606  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004c4609  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004c460f  7415                   -je 0x4c4626
    if (cpu.flags.zf)
    {
        goto L_0x004c4626;
    }
    // 004c4611  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c4616  e80f000000             -call 0x4c462a
    cpu.esp -= 4;
    sub_4c462a(app, cpu);
    if (cpu.terminate) return;
    // 004c461b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c461d  7407                   -je 0x4c4626
    if (cpu.flags.zf)
    {
        goto L_0x004c4626;
    }
    // 004c461f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c4624  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4625  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c4626:
    // 004c4626  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004c4628  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4629  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4c462a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c462a  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6005712) /* 0x5ba3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4631  7429                   -je 0x4c465c
    if (cpu.flags.zf)
    {
        goto L_0x004c465c;
    }
    // 004c4633  813d6c0a4e00a4030000   +cmp dword ptr [0x4e0a6c], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5114476) /* 0x4e0a6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c463d  740a                   -je 0x4c4649
    if (cpu.flags.zf)
    {
        goto L_0x004c4649;
    }
    // 004c463f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4641  741b                   -je 0x4c465e
    if (cpu.flags.zf)
    {
        goto L_0x004c465e;
    }
    // 004c4643  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004c4648  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c4649:
    // 004c4649  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c464e  8a80c9104e00           -mov al, byte ptr [eax + 0x4e10c9]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5116105) /* 0x4e10c9 */);
    // 004c4654  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004c4656  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004c465b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004c465c:
    // 004c465c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004c465e:
    // 004c465e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4c4660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4660  833d20124e0000         +cmp dword ptr [0x4e1220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116448) /* 0x4e1220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4667  751e                   -jne 0x4c4687
    if (!cpu.flags.zf)
    {
        goto L_0x004c4687;
    }
    // 004c4669  68c8154e00             -push 0x4e15c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117384 /*0x4e15c8*/;
    cpu.esp -= 4;
    // 004c466e  ff1544654c00           -call dword ptr [0x4c6544]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5006660) /* 0x4c6544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c4674  a320124e00             -mov dword ptr [0x4e1220], eax
    app->getMemory<x86::reg32>(x86::reg32(5116448) /* 0x4e1220 */) = cpu.eax;
    // 004c4679  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c467b  750a                   -jne 0x4c4687
    if (!cpu.flags.zf)
    {
        goto L_0x004c4687;
    }
    // 004c467d  c70520124e00ffffffff   -mov dword ptr [0x4e1220], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116448) /* 0x4e1220 */) = 4294967295 /*0xffffffff*/;
L_0x004c4687:
    // 004c4687  833d20124e00ff         +cmp dword ptr [0x4e1220], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116448) /* 0x4e1220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c468e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4693  7420                   -je 0x4c46b5
    if (cpu.flags.zf)
    {
        goto L_0x004c46b5;
    }
    // 004c4695  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c4699  ff3520124e00           -push dword ptr [0x4e1220]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5116448) /* 0x4e1220 */);
    cpu.esp -= 4;
    // 004c469f  ff1514654c00           -call dword ptr [0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004c46a5  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004c46a9  83f801                 +cmp eax, 1
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
    // 004c46ac  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004c46ae  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004c46b0  2549000080             -and eax, 0x80000049
    cpu.eax &= x86::reg32(x86::sreg32(2147483721 /*0x80000049*/));
L_0x004c46b5:
    // 004c46b5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4c46b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c46b8  833d40124e0000         +cmp dword ptr [0x4e1240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116480) /* 0x4e1240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c46bf  751f                   -jne 0x4c46e0
    if (!cpu.flags.zf)
    {
        goto L_0x004c46e0;
    }
    // 004c46c1  6840124e00             -push 0x4e1240
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116480 /*0x4e1240*/;
    cpu.esp -= 4;
    // 004c46c6  6840164e00             -push 0x4e1640
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117504 /*0x4e1640*/;
    cpu.esp -= 4;
    // 004c46cb  e890ffffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c46d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c46d2  740c                   -je 0x4c46e0
    if (cpu.flags.zf)
    {
        goto L_0x004c46e0;
    }
    // 004c46d4  c70540124e00ffffffff   -mov dword ptr [0x4e1240], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116480) /* 0x4e1240 */) = 4294967295 /*0xffffffff*/;
    // 004c46de  eb20                   -jmp 0x4c4700
    goto L_0x004c4700;
L_0x004c46e0:
    // 004c46e0  833d40124e00ff         +cmp dword ptr [0x4e1240], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116480) /* 0x4e1240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c46e7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c46ec  7412                   -je 0x4c4700
    if (cpu.flags.zf)
    {
        goto L_0x004c4700;
    }
    // 004c46ee  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c46f2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c46f6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c46fa  ff1540124e00           -call dword ptr [0x4e1240]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116480) /* 0x4e1240 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4700:
    // 004c4700  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c4703(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4703  833d50124e0000         +cmp dword ptr [0x4e1250], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116496) /* 0x4e1250 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c470a  751f                   -jne 0x4c472b
    if (!cpu.flags.zf)
    {
        goto L_0x004c472b;
    }
    // 004c470c  6850124e00             -push 0x4e1250
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116496 /*0x4e1250*/;
    cpu.esp -= 4;
    // 004c4711  6888164e00             -push 0x4e1688
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117576 /*0x4e1688*/;
    cpu.esp -= 4;
    // 004c4716  e845ffffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c471b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c471d  740c                   -je 0x4c472b
    if (cpu.flags.zf)
    {
        goto L_0x004c472b;
    }
    // 004c471f  c70550124e00ffffffff   -mov dword ptr [0x4e1250], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116496) /* 0x4e1250 */) = 4294967295 /*0xffffffff*/;
    // 004c4729  eb18                   -jmp 0x4c4743
    goto L_0x004c4743;
L_0x004c472b:
    // 004c472b  833d50124e00ff         +cmp dword ptr [0x4e1250], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116496) /* 0x4e1250 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4732  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4737  740a                   -je 0x4c4743
    if (cpu.flags.zf)
    {
        goto L_0x004c4743;
    }
    // 004c4739  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c473d  ff1550124e00           -call dword ptr [0x4e1250]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116496) /* 0x4e1250 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4743:
    // 004c4743  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4c4746(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4746  833d78124e0000         +cmp dword ptr [0x4e1278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116536) /* 0x4e1278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c474d  751f                   -jne 0x4c476e
    if (!cpu.flags.zf)
    {
        goto L_0x004c476e;
    }
    // 004c474f  6878124e00             -push 0x4e1278
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116536 /*0x4e1278*/;
    cpu.esp -= 4;
    // 004c4754  6858174e00             -push 0x4e1758
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117784 /*0x4e1758*/;
    cpu.esp -= 4;
    // 004c4759  e802ffffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c475e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4760  740c                   -je 0x4c476e
    if (cpu.flags.zf)
    {
        goto L_0x004c476e;
    }
    // 004c4762  c70578124e00ffffffff   -mov dword ptr [0x4e1278], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116536) /* 0x4e1278 */) = 4294967295 /*0xffffffff*/;
    // 004c476c  eb18                   -jmp 0x4c4786
    goto L_0x004c4786;
L_0x004c476e:
    // 004c476e  833d78124e00ff         +cmp dword ptr [0x4e1278], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116536) /* 0x4e1278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4775  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c477a  740a                   -je 0x4c4786
    if (cpu.flags.zf)
    {
        goto L_0x004c4786;
    }
    // 004c477c  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c4780  ff1578124e00           -call dword ptr [0x4e1278]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116536) /* 0x4e1278 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4786:
    // 004c4786  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

}
