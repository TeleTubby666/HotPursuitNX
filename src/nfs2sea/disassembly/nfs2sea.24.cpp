#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499752  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499755  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499757  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499759  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049975b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049975f  e8cceaffff             -call 0x498230
    cpu.esp -= 4;
    sub_498230(app, cpu);
    if (cpu.terminate) return;
    // 00499764  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00499767  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00499769  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049976d  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00499774  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00499777  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049977b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049977d  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00499780  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00499782  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00499785  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00499788  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0049978f  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00499796  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0049979d  c7412000000100         -mov dword ptr [ecx + 0x20], 0x10000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 65536 /*0x10000*/;
    // 004997a4  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004997a7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004997aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4997b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004997b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004997b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004997b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004997b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004997b4  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004997b7  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004997bb  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004997bf  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004997c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004997c5  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004997c9  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004997cd  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004997d0:
    // 004997d0  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004997d4  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004997d8  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004997dc  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x004997df:
    // 004997df  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004997e1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004997e3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004997e5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004997e8  c1e810                 +shr eax, 0x10
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
    // 004997eb  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004997ed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004997ef  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004997f2  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004997f5  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004997f7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004997fa  c1e810                 +shr eax, 0x10
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
    // 004997fd  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004997ff  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00499802  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499804  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00499807  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049980a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049980c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049980f  c1e810                 +shr eax, 0x10
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
    // 00499812  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499814  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499816  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499819  895c3cfc               -mov dword ptr [esp + edi - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1) = cpu.ebx;
    // 0049981d  39e9                   +cmp ecx, ebp
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
    // 0049981f  75be                   -jne 0x4997df
    if (!cpu.flags.zf)
    {
        goto L_0x004997df;
    }
    // 00499821  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00499825  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00499829  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049982c  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049982f  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00499833  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00499837  83fb09                 +cmp ebx, 9
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
    // 0049983a  7c94                   -jl 0x4997d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004997d0;
    }
    // 0049983c  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 00499841  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499845  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499847  e8b402ffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049984c  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049984f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499850  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499851  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499852  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499853  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_499860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499860  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499861  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499862  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499863  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499865  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049986a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049986c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049986f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00499871  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00499873  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00499875  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049987c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049987e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499880  8a6701                 -mov ah, byte ptr [edi + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00499883  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499885  80fcfb                 +cmp ah, 0xfb
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
    // 00499888  7518                   -jne 0x4998a2
    if (!cpu.flags.zf)
    {
        goto L_0x004998a2;
    }
L_0x0049988a:
    // 0049988a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049988c  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049988e  3c32                   +cmp al, 0x32
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
    // 00499890  7317                   -jae 0x4998a9
    if (!cpu.flags.cf)
    {
        goto L_0x004998a9;
    }
    // 00499892  3c10                   +cmp al, 0x10
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
    // 00499894  7206                   -jb 0x49989c
    if (cpu.flags.cf)
    {
        goto L_0x0049989c;
    }
    // 00499896  763c                   -jbe 0x4998d4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004998d4;
    }
    // 00499898  3c30                   +cmp al, 0x30
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
    // 0049989a  7417                   -je 0x4998b3
    if (cpu.flags.zf)
    {
        goto L_0x004998b3;
    }
L_0x0049989c:
    // 0049989c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049989e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049989f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004998a2:
    // 004998a2  80fc32                 +cmp ah, 0x32
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
    // 004998a5  74e3                   -je 0x49988a
    if (cpu.flags.zf)
    {
        goto L_0x0049988a;
    }
    // 004998a7  ebf3                   -jmp 0x49989c
    goto L_0x0049989c;
L_0x004998a9:
    // 004998a9  7608                   -jbe 0x4998b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004998b3;
    }
    // 004998ab  3c46                   +cmp al, 0x46
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
    // 004998ad  7314                   -jae 0x4998c3
    if (!cpu.flags.cf)
    {
        goto L_0x004998c3;
    }
    // 004998af  3c34                   +cmp al, 0x34
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
    // 004998b1  75e9                   -jne 0x49989c
    if (!cpu.flags.zf)
    {
        goto L_0x0049989c;
    }
L_0x004998b3:
    // 004998b3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004998b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004998ba  e8d1350100             -call 0x4ace90
    cpu.esp -= 4;
    sub_4ace90(app, cpu);
    if (cpu.terminate) return;
    // 004998bf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004998c1  ebd9                   -jmp 0x49989c
    goto L_0x0049989c;
L_0x004998c3:
    // 004998c3  7623                   -jbe 0x4998e8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004998e8;
    }
    // 004998c5  3c4a                   +cmp al, 0x4a
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
    // 004998c7  75d3                   -jne 0x49989c
    if (!cpu.flags.zf)
    {
        goto L_0x0049989c;
    }
    // 004998c9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004998cb  e880490100             -call 0x4ae250
    cpu.esp -= 4;
    sub_4ae250(app, cpu);
    if (cpu.terminate) return;
    // 004998d0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004998d2  ebc8                   -jmp 0x49989c
    goto L_0x0049989c;
L_0x004998d4:
    // 004998d4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004998d9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004998db  e8044b0100             -call 0x4ae3e4
    cpu.esp -= 4;
    sub_4ae3e4(app, cpu);
    if (cpu.terminate) return;
    // 004998e0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004998e2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004998e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004998e8:
    // 004998e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004998ea  e8a94c0100             -call 0x4ae598
    cpu.esp -= 4;
    sub_4ae598(app, cpu);
    if (cpu.terminate) return;
    // 004998ef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004998f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004998f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4998f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004998f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004998f9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004998fe  e85dffffff             -call 0x499860
    cpu.esp -= 4;
    sub_499860(app, cpu);
    if (cpu.terminate) return;
    // 00499903  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499904  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_499908(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499908  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499909  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049990b  e850ffffff             -call 0x499860
    cpu.esp -= 4;
    sub_499860(app, cpu);
    if (cpu.terminate) return;
    // 00499910  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499911  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499914  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499915  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499916  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499917  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499918  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049991a  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049991f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499921  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499924  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00499926  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00499928  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049992a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00499931  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00499933  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499935  8a6201                 -mov ah, byte ptr [edx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00499938  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049993a  80fcfb                 +cmp ah, 0xfb
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
    // 0049993d  7519                   -jne 0x499958
    if (!cpu.flags.zf)
    {
        goto L_0x00499958;
    }
L_0x0049993f:
    // 0049993f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00499941  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00499943  3c34                   +cmp al, 0x34
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
    // 00499945  7318                   -jae 0x49995f
    if (!cpu.flags.cf)
    {
        goto L_0x0049995f;
    }
    // 00499947  3c30                   +cmp al, 0x30
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
    // 00499949  7324                   -jae 0x49996f
    if (!cpu.flags.cf)
    {
        goto L_0x0049996f;
    }
    // 0049994b  3c10                   +cmp al, 0x10
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
    // 0049994d  7502                   -jne 0x499951
    if (!cpu.flags.zf)
    {
        goto L_0x00499951;
    }
L_0x0049994f:
    // 0049994f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00499951:
    // 00499951  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499953  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499954  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499955  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499956  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499957  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499958:
    // 00499958  80fc32                 +cmp ah, 0x32
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
    // 0049995b  74e2                   -je 0x49993f
    if (cpu.flags.zf)
    {
        goto L_0x0049993f;
    }
    // 0049995d  ebf2                   -jmp 0x499951
    goto L_0x00499951;
L_0x0049995f:
    // 0049995f  76ee                   -jbe 0x49994f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049994f;
    }
    // 00499961  3c4a                   +cmp al, 0x4a
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
    // 00499963  7306                   -jae 0x49996b
    if (!cpu.flags.cf)
    {
        goto L_0x0049996b;
    }
    // 00499965  3c46                   +cmp al, 0x46
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
    // 00499967  74e6                   -je 0x49994f
    if (cpu.flags.zf)
    {
        goto L_0x0049994f;
    }
    // 00499969  ebe6                   -jmp 0x499951
    goto L_0x00499951;
L_0x0049996b:
    // 0049996b  76e2                   -jbe 0x49994f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049994f;
    }
    // 0049996d  ebe2                   -jmp 0x499951
    goto L_0x00499951;
L_0x0049996f:
    // 0049996f  76de                   -jbe 0x49994f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049994f;
    }
    // 00499971  3c32                   +cmp al, 0x32
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
    // 00499973  74da                   -je 0x49994f
    if (cpu.flags.zf)
    {
        goto L_0x0049994f;
    }
    // 00499975  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499977  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499978  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499979  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049997a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049997b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_499990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00499990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499991  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499992  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499994  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00499997  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049999a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049999f  83f903                 +cmp ecx, 3
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
    // 004999a2  7720                   -ja 0x4999c4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004999c4;
    }
    // 004999a4  ff248d80994900         -jmp dword ptr [ecx*4 + 0x499980]
    cpu.ip = app->getMemory<x86::reg32>(4823424 + cpu.ecx * 4); goto dynamic_jump;
  case 0x004999ab:
    // 004999ab  8b0c85d0944d00         -mov ecx, dword ptr [eax*4 + 0x4d94d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 004999b2  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004999b4  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004999b9  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004999bb  8b0495d0944d00         -mov eax, dword ptr [edx*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.edx * 4);
    // 004999c2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004999c4:
    // 004999c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999c6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004999c7:
    // 004999c7  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 004999cc  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004999ce  8b0c8dd0944d00         -mov ecx, dword ptr [ecx*4 + 0x4d94d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.ecx * 4);
    // 004999d5  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004999d7  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 004999de  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004999e0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004999e2  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004999e4  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004999e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004999e8  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004999e9:
    // 004999e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004999ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004999eb  8b0c85d0944d00         -mov ecx, dword ptr [eax*4 + 0x4d94d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 004999f2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004999f4  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004999f6  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 004999f8  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004999fa  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004999ff  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00499a01  8b0495d0944d00         -mov eax, dword ptr [edx*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.edx * 4);
    // 00499a08  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499a0a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00499a0c  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00499a0e  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00499a10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a14  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00499a15:
    // 00499a15  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 00499a1a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00499a1c  8b0c8dd0944d00         -mov ecx, dword ptr [ecx*4 + 0x4d94d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.ecx * 4);
    // 00499a23  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00499a25  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00499a27  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00499a29  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 00499a30  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00499a32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499a34  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_499a38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499a38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499a39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499a3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499a3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499a3c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499a3e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00499a40  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00499a42  f72f                   -imul dword ptr [edi]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 00499a44  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00499a46  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00499a49  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499a4b  f76f0c                 -imul dword ptr [edi + 0xc]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 00499a4e  01c5                   +add ebp, eax
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
    // 00499a50  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00499a53  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499a55  f76f18                 -imul dword ptr [edi + 0x18]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */))));
    // 00499a58  01e8                   +add eax, ebp
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
    // 00499a5a  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00499a5c  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00499a60  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00499a62  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00499a64  f76f04                 -imul dword ptr [edi + 4]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 00499a67  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00499a69  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00499a6c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499a6e  f76f10                 -imul dword ptr [edi + 0x10]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))));
    // 00499a71  01c5                   +add ebp, eax
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
    // 00499a73  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00499a76  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499a78  f76f1c                 -imul dword ptr [edi + 0x1c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))));
    // 00499a7b  01e8                   +add eax, ebp
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
    // 00499a7d  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00499a7f  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00499a83  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00499a86  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00499a88  f76f08                 -imul dword ptr [edi + 8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 00499a8b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00499a8d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00499a90  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499a92  f76f14                 -imul dword ptr [edi + 0x14]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */))));
    // 00499a95  01c5                   +add ebp, eax
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
    // 00499a97  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00499a9a  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499a9c  f76f20                 -imul dword ptr [edi + 0x20]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */))));
    // 00499a9f  01e8                   +add eax, ebp
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
    // 00499aa1  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00499aa3  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00499aa7  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00499aaa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499aab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499aac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499aad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499aae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_499ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499ab1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499ab2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499ab3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499ab4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499ab6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00499ab8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499aba  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x00499abd:
    // 00499abd  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499ac0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00499ac2  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00499ac4  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499ac7  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00499ac9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499acc  8953fc                 -mov dword ptr [ebx - 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00499acf  39f0                   +cmp eax, esi
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
    // 00499ad1  75ea                   -jne 0x499abd
    if (!cpu.flags.zf)
    {
        goto L_0x00499abd;
    }
    // 00499ad3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499ad5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ad6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ad7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ad8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ad9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499adc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499add  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499ade  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499adf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499ae0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499ae2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00499ae4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00499ae6  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x00499ae9:
    // 00499ae9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499aec  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00499aee  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00499af0  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499af3  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499af5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499af8  8953fc                 -mov dword ptr [ebx - 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00499afb  39f0                   +cmp eax, esi
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
    // 00499afd  75ea                   -jne 0x499ae9
    if (!cpu.flags.zf)
    {
        goto L_0x00499ae9;
    }
    // 00499aff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499b01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_499b08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499b08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499b09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499b0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499b0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499b0c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499b0e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00499b10  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499b12  8d7824                 -lea edi, [eax + 0x24]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x00499b15:
    // 00499b15  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499b17  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00499b19  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499b1c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499b1e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499b21  c1e810                 +shr eax, 0x10
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
    // 00499b24  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499b26  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499b29  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00499b2c  39f9                   +cmp ecx, edi
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
    // 00499b2e  75e5                   -jne 0x499b15
    if (!cpu.flags.zf)
    {
        goto L_0x00499b15;
    }
    // 00499b30  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499b32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499b36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499b38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499b38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499b39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499b3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499b3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499b3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499b3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499b3e  81ecbc000000           -sub esp, 0xbc
    (cpu.esp) -= x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 00499b44  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 00499b4b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499b4d  899424b4000000         -mov dword ptr [esp + 0xb4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.edx;
L_0x00499b54:
    // 00499b54  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00499b58  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00499b5f  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00499b66  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00499b6b  e890ecffff             -call 0x498800
    cpu.esp -= 4;
    sub_498800(app, cpu);
    if (cpu.terminate) return;
    // 00499b70  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00499b77  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00499b7b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00499b7d  e82efcffff             -call 0x4997b0
    cpu.esp -= 4;
    sub_4997b0(app, cpu);
    if (cpu.terminate) return;
    // 00499b82  8d5c246c               -lea ebx, [esp + 0x6c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00499b86  baacb14d00             -mov edx, 0x4db1ac
    cpu.edx = 5091756 /*0x4db1ac*/;
    // 00499b8b  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00499b92  beacb14d00             -mov esi, 0x4db1ac
    cpu.esi = 5091756 /*0x4db1ac*/;
    // 00499b97  e840ffffff             -call 0x499adc
    cpu.esp -= 4;
    sub_499adc(app, cpu);
    if (cpu.terminate) return;
    // 00499b9c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499b9e  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00499ba3  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499ba7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00499ba9  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 00499bae  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00499bb0:
    // 00499bb0  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00499bb4  8d54246c               -lea edx, [esp + 0x6c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00499bb8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499bba  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00499bbf  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00499bc1  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00499bc5  e8e6fbffff             -call 0x4997b0
    cpu.esp -= 4;
    sub_4997b0(app, cpu);
    if (cpu.terminate) return;
    // 00499bca  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00499bd1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499bd3  8b95d0b14d00           -mov edx, dword ptr [ebp + 0x4db1d0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5091792) /* 0x4db1d0 */);
    // 00499bd9  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499bdb  e828ffffff             -call 0x499b08
    cpu.esp -= 4;
    sub_499b08(app, cpu);
    if (cpu.terminate) return;
    // 00499be0  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499be4  8d942490000000         -lea edx, [esp + 0x90]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00499beb  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499bef  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499bf2  e8b9feffff             -call 0x499ab0
    cpu.esp -= 4;
    sub_499ab0(app, cpu);
    if (cpu.terminate) return;
    // 00499bf7  83fd10                 +cmp ebp, 0x10
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
    // 00499bfa  75b4                   -jne 0x499bb0
    if (!cpu.flags.zf)
    {
        goto L_0x00499bb0;
    }
    // 00499bfc  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00499c01  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00499c05  8bb424b8000000         -mov esi, dword ptr [esp + 0xb8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00499c0c  8b9c24b8000000         -mov ebx, dword ptr [esp + 0xb8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00499c13  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499c15  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00499c19  8b8c24b4000000         -mov ecx, dword ptr [esp + 0xb4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00499c20  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00499c24  41                     -inc ecx
    (cpu.ecx)++;
    // 00499c25  e886fbffff             -call 0x4997b0
    cpu.esp -= 4;
    sub_4997b0(app, cpu);
    if (cpu.terminate) return;
    // 00499c2a  898c24b4000000         -mov dword ptr [esp + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 00499c31  83f904                 +cmp ecx, 4
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
    // 00499c34  0f8c1affffff           -jl 0x499b54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00499b54;
    }
    // 00499c3a  81c4bc000000           -add esp, 0xbc
    (cpu.esp) += x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 00499c40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499c46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_499c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499c48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499c49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499c4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499c4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499c4c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00499c4f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00499c51  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00499c53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499c55  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00499c5b  c0e507                 +shl ch, 7
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
    // 00499c5e  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499c60  00ed                   +add ch, ch
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
    // 00499c62  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00499c64  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499c66  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499c6b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499c6d  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 00499c74  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499c76  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00499c78  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00499c7c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499c7e  c0e407                 +shl ah, 7
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
    // 00499c81  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499c83  00e4                   +add ah, ah
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
    // 00499c85  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00499c87  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499c89  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499c8e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499c90  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 00499c97  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499c99  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00499c9b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499c9d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499c9f  7518                   -jne 0x499cb9
    if (!cpu.flags.zf)
    {
        goto L_0x00499cb9;
    }
    // 00499ca1  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00499ca6  beacb14d00             -mov esi, 0x4db1ac
    cpu.esi = 5091756 /*0x4db1ac*/;
    // 00499cab  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00499cad  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499caf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499cb1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00499cb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499cb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499cb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499cb7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499cb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499cb9:
    // 00499cb9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00499cbb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499cbd  e87e4a0100             -call 0x4ae740
    cpu.esp -= 4;
    sub_4ae740(app, cpu);
    if (cpu.terminate) return;
    // 00499cc2  bd00000100             -mov ebp, 0x10000
    cpu.ebp = 65536 /*0x10000*/;
    // 00499cc7  2b6c2414               -sub ebp, dword ptr [esp + 0x14]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00499ccb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499cce  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499cd0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499cd2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499cd5  c1e810                 +shr eax, 0x10
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
    // 00499cd8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499cda  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499cde  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499ce0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499ce2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499ce4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499ce7  c1e810                 +shr eax, 0x10
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
    // 00499cea  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499cec  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499cf0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499cf2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499cf4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499cf6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499cf9  c1e810                 +shr eax, 0x10
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
    // 00499cfc  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499cfe  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499d01  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00499d03  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499d05  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d07  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d0a  c1e810                 +shr eax, 0x10
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
    // 00499d0d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499d0f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499d13  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00499d17  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499d19  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d1b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d1e  c1e810                 +shr eax, 0x10
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
    // 00499d21  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499d23  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499d27  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00499d2b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499d2d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d2f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d32  c1e810                 +shr eax, 0x10
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
    // 00499d35  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499d37  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499d3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499d3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499d3e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d40  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d43  c1e810                 +shr eax, 0x10
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
    // 00499d46  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499d48  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00499d4c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499d4e  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00499d50  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499d52  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499d56  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d58  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d5b  c1e810                 +shr eax, 0x10
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
    // 00499d5e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499d60  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00499d62  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00499d65  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499d69  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499d6b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00499d6f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d71  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d74  c1e810                 +shr eax, 0x10
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
    // 00499d77  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499d79  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499d7b  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00499d7e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499d81  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499d83  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d85  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d88  c1e810                 +shr eax, 0x10
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
    // 00499d8b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499d8d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00499d8f  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00499d92  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499d96  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499d98  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499d9a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499d9d  c1e810                 +shr eax, 0x10
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
    // 00499da0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499da2  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00499da6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499da8  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00499dab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00499dad  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499db1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499db3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499db6  c1e810                 +shr eax, 0x10
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
    // 00499db9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499dbb  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00499dbf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499dc1  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00499dc4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499dc6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00499dc9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499dcb  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499dce  c1e810                 +shr eax, 0x10
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
    // 00499dd1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499dd3  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00499dd6  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00499dd9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499ddb  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499ddf  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00499de3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499de5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499de8  c1e810                 +shr eax, 0x10
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
    // 00499deb  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499ded  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00499def  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00499df2  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499df6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499df8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00499dfa  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00499dfd  c1e810                 +shr eax, 0x10
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
    // 00499e00  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00499e02  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00499e06  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00499e08  895320                 -mov dword ptr [ebx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00499e0b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499e0d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00499e10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499e15(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e15  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499e1b  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00499e1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499e1f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499e20  e8f0ffffff             -call 0x499e15
    cpu.esp -= 4;
    sub_499e15(app, cpu);
    if (cpu.terminate) return;
    // 00499e25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499e27  7418                   -je 0x499e41
    if (cpu.flags.zf)
    {
        goto L_0x00499e41;
    }
    // 00499e29  69106d4ec641           -imul edx, dword ptr [eax], 0x41c64e6d
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))) * x86::sreg64(x86::sreg32(1103515245 /*0x41c64e6d*/)));
    // 00499e2f  81c239300000           -add edx, 0x3039
    (cpu.edx) += x86::reg32(x86::sreg32(12345 /*0x3039*/));
    // 00499e35  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00499e37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499e39  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00499e3c  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
L_0x00499e41:
    // 00499e41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499e43(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e43  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499e44  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499e46  e8caffffff             -call 0x499e15
    cpu.esp -= 4;
    sub_499e15(app, cpu);
    if (cpu.terminate) return;
    // 00499e4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499e4d  7402                   -je 0x499e51
    if (cpu.flags.zf)
    {
        goto L_0x00499e51;
    }
    // 00499e4f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00499e51:
    // 00499e51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499e53(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e53  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499e54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499e55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499e56  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499e57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499e58  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00499e5a  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00499e60  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 00499e66  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00499e68  8b3570e95600           -mov esi, dword ptr [0x56e970]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695856) /* 0x56e970 */);
    // 00499e6e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00499e73  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499e75  740d                   -je 0x499e84
    if (cpu.flags.zf)
    {
        goto L_0x00499e84;
    }
    // 00499e77  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00499e79  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00499e7e  893d70e95600           -mov dword ptr [0x56e970], edi
    app->getMemory<x86::reg32>(x86::reg32(5695856) /* 0x56e970 */) = cpu.edi;
L_0x00499e84:
    // 00499e84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499e85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499e86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499e87  68e4ee4c00             -push 0x4ceee4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5041892 /*0x4ceee4*/;
    cpu.esp -= 4;
    // 00499e8c  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00499e91  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00499e94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499e95  e8e8490100             -call 0x4ae882
    cpu.esp -= 4;
    sub_4ae882(app, cpu);
    if (cpu.terminate) return;
    // 00499e9a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00499e9d  803d48df4d0000         +cmp byte ptr [0x4ddf48], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103432) /* 0x4ddf48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499ea4  0f84f8000000           -je 0x499fa2
    if (cpu.flags.zf)
    {
        goto L_0x00499fa2;
    }
    // 00499eaa  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00499ead  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499eae  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499eb0  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499eb2  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499eb4  49                     -dec ecx
    (cpu.ecx)--;
    // 00499eb5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499eb7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00499eb9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00499ebb  49                     -dec ecx
    (cpu.ecx)--;
    // 00499ebc  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499ebd  8d5117                 -lea edx, [ecx + 0x17]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 00499ec0  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00499ec3  e8e5490100             -call 0x4ae8ad
    cpu.esp -= 4;
    sub_4ae8ad(app, cpu);
    if (cpu.terminate) return;
    // 00499ec8  39c2                   +cmp edx, eax
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
    // 00499eca  733c                   -jae 0x499f08
    if (!cpu.flags.cf)
    {
        goto L_0x00499f08;
    }
    // 00499ecc  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00499ecf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499ed0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499ed2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499ed4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499ed6  49                     -dec ecx
    (cpu.ecx)--;
    // 00499ed7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499ed9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00499edb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00499edd  49                     -dec ecx
    (cpu.ecx)--;
    // 00499ede  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499edf  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 00499ee2  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00499ee4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499ee5  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00499ee8  e80f4a0100             -call 0x4ae8fc
    cpu.esp -= 4;
    sub_4ae8fc(app, cpu);
    if (cpu.terminate) return;
    // 00499eed  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499eee  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499ef0  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499ef2  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00499ef4  49                     -dec ecx
    (cpu.ecx)--;
    // 00499ef5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499ef7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00499ef9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00499efb  49                     -dec ecx
    (cpu.ecx)--;
    // 00499efc  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499efd  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 00499f00  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00499f02  29c4                   +sub esp, eax
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
    // 00499f04  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00499f06  eb02                   -jmp 0x499f0a
    goto L_0x00499f0a;
L_0x00499f08:
    // 00499f08  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00499f0a:
    // 00499f0a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499f0c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00499f0e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499f10  befcee4c00             -mov esi, 0x4ceefc
    cpu.esi = 5041916 /*0x4ceefc*/;
    // 00499f15  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499f16  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499f17  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499f18  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00499f19  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 00499f1b  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00499f1c  8d75fe                 -lea esi, [ebp - 2]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00499f1f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00499f21  894d7e                 -mov dword ptr [ebp + 0x7e], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.ecx;
    // 00499f24  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499f25  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00499f26  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499f27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499f28  2bc9                   +sub ecx, ecx
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
    // 00499f2a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00499f2b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00499f2d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00499f2f  4f                     -dec edi
    (cpu.edi)--;
L_0x00499f30:
    // 00499f30  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00499f32  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00499f34  3c00                   +cmp al, 0
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
    // 00499f36  7410                   -je 0x499f48
    if (cpu.flags.zf)
    {
        goto L_0x00499f48;
    }
    // 00499f38  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00499f3b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499f3e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00499f41  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00499f44  3c00                   +cmp al, 0
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
    // 00499f46  75e8                   -jne 0x499f30
    if (!cpu.flags.zf)
    {
        goto L_0x00499f30;
    }
L_0x00499f48:
    // 00499f48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499f49  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499f4a  e85e490100             -call 0x4ae8ad
    cpu.esp -= 4;
    sub_4ae8ad(app, cpu);
    if (cpu.terminate) return;
    // 00499f4f  83f814                 +cmp eax, 0x14
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
    // 00499f52  7612                   -jbe 0x499f66
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499f66;
    }
    // 00499f54  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 00499f56  e8a1490100             -call 0x4ae8fc
    cpu.esp -= 4;
    sub_4ae8fc(app, cpu);
    if (cpu.terminate) return;
    // 00499f5b  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00499f60  29c4                   +sub esp, eax
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
    // 00499f62  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00499f64  eb02                   -jmp 0x499f68
    goto L_0x00499f68;
L_0x00499f66:
    // 00499f66  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00499f68:
    // 00499f68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499f69  680fef4c00             -push 0x4cef0f
    app->getMemory<x86::reg32>(cpu.esp-4) = 5041935 /*0x4cef0f*/;
    cpu.esp -= 4;
    // 00499f6e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499f6f  e8fda9feff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00499f74  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00499f77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499f78  2eff1528454c00         -call dword ptr cs:[0x4c4528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998440) /* 0x4c4528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499f7f  803d48df4d0000         +cmp byte ptr [0x4ddf48], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103432) /* 0x4ddf48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499f86  7436                   -je 0x499fbe
    if (cpu.flags.zf)
    {
        goto L_0x00499fbe;
    }
    // 00499f88  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499f8a  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00499f8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499f90  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00499f93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499f94  cc                     -int3 
    NFS2_ASSERT(false);
    // 00499f95  eb06                   -jmp 0x499f9d
    goto L_0x00499f9d;
    // 00499f97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499f98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499f99  49                     -dec ecx
    (cpu.ecx)--;
    // 00499f9a  44                     -inc esp
    (cpu.esp)++;
    // 00499f9b  45                     -inc ebp
    (cpu.ebp)++;
    // 00499f9c  4f                     -dec edi
    (cpu.edi)--;
L_0x00499f9d:
    // 00499f9d  83c408                 +add esp, 8
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
    // 00499fa0  eb1c                   -jmp 0x499fbe
    goto L_0x00499fbe;
L_0x00499fa2:
    // 00499fa2  6800200000             -push 0x2000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 00499fa7  6820ef4c00             -push 0x4cef20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5041952 /*0x4cef20*/;
    cpu.esp -= 4;
    // 00499fac  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00499faf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499fb0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00499fb2  2eff15d8434c00         -call dword ptr cs:[0x4c43d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998104) /* 0x4c43d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499fb9  e872490100             -call 0x4ae930
    cpu.esp -= 4;
    sub_4ae930(app, cpu);
    if (cpu.terminate) return;
L_0x00499fbe:
    // 00499fbe  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 00499fc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fc5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499fc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499fca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499fca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499fcb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499fcd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499fcf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00499fd1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00499fd3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499fd5  750f                   -jne 0x499fe6
    if (!cpu.flags.zf)
    {
        goto L_0x00499fe6;
    }
    // 00499fd7  c70570e9560001000000   -mov dword ptr [0x56e970], 1
    app->getMemory<x86::reg32>(x86::reg32(5695856) /* 0x56e970 */) = 1 /*0x1*/;
    // 00499fe1  e86dfeffff             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
L_0x00499fe6:
    // 00499fe6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fe7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_499ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499ff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499ff2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499ff3  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 00499ff9  8b842414040000         -mov eax, dword ptr [esp + 0x414]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0049a000  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a002  7415                   -je 0x49a019
    if (cpu.flags.zf)
    {
        goto L_0x0049a019;
    }
    // 0049a004  8b942418040000         -mov edx, dword ptr [esp + 0x418]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0049a00b  3b10                   +cmp edx, dword ptr [eax]
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
    // 0049a00d  7e0a                   -jle 0x49a019
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a019;
    }
L_0x0049a00f:
    // 0049a00f  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0049a015  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a016  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a017  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a019:
    // 0049a019  8d842420040000         -lea eax, [esp + 0x420]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1056) /* 0x420 */);
    // 0049a020  8d9c2400040000         -lea ebx, [esp + 0x400]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0049a027  8b94241c040000         -mov edx, dword ptr [esp + 0x41c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0049a02e  89842400040000         -mov dword ptr [esp + 0x400], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 0049a035  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a037  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a039  e8b65b0000             -call 0x49fbf4
    cpu.esp -= 4;
    sub_49fbf4(app, cpu);
    if (cpu.terminate) return;
    // 0049a03e  a100b34d00             -mov eax, dword ptr [0x4db300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092096) /* 0x4db300 */);
    // 0049a043  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 0049a04a  83f802                 +cmp eax, 2
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
    // 0049a04d  7319                   -jae 0x49a068
    if (!cpu.flags.cf)
    {
        goto L_0x0049a068;
    }
    // 0049a04f  83f801                 +cmp eax, 1
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
    // 0049a052  75bb                   -jne 0x49a00f
    if (!cpu.flags.zf)
    {
        goto L_0x0049a00f;
    }
    // 0049a054  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a056  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a057  2eff1528454c00         -call dword ptr cs:[0x4c4528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998440) /* 0x4c4528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a05e  81c404040000           +add esp, 0x404
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
    // 0049a064  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a065  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a066  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a067  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a068:
    // 0049a068  761a                   -jbe 0x49a084
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a084;
    }
    // 0049a06a  83f803                 +cmp eax, 3
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
    // 0049a06d  75a0                   -jne 0x49a00f
    if (!cpu.flags.zf)
    {
        goto L_0x0049a00f;
    }
    // 0049a06f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a071  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a072  e8e9fafeff             -call 0x489b60
    cpu.esp -= 4;
    sub_489b60(app, cpu);
    if (cpu.terminate) return;
    // 0049a077  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a07a  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0049a080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a083  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a084:
    // 0049a084  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a086  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a087  e830bcffff             -call 0x495cbc
    cpu.esp -= 4;
    sub_495cbc(app, cpu);
    if (cpu.terminate) return;
    // 0049a08c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a08f  b822c94d00             -mov eax, 0x4dc922
    cpu.eax = 5097762 /*0x4dc922*/;
    // 0049a094  e8af480100             -call 0x4ae948
    cpu.esp -= 4;
    sub_4ae948(app, cpu);
    if (cpu.terminate) return;
    // 0049a099  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0049a09f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a0a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a0a3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a0a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0049a0a6:
    // 0049a0a6  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049a0a8  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0049a0aa  3c41                   +cmp al, 0x41
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
    // 0049a0ac  7206                   -jb 0x49a0b4
    if (cpu.flags.cf)
    {
        goto L_0x0049a0b4;
    }
    // 0049a0ae  3c5a                   +cmp al, 0x5a
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
    // 0049a0b0  7702                   -ja 0x49a0b4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049a0b4;
    }
    // 0049a0b2  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0049a0b4:
    // 0049a0b4  80fc41                 +cmp ah, 0x41
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
    // 0049a0b7  7208                   -jb 0x49a0c1
    if (cpu.flags.cf)
    {
        goto L_0x0049a0c1;
    }
    // 0049a0b9  80fc5a                 +cmp ah, 0x5a
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
    // 0049a0bc  7703                   -ja 0x49a0c1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049a0c1;
    }
    // 0049a0be  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0049a0c1:
    // 0049a0c1  38e0                   +cmp al, ah
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
    // 0049a0c3  7508                   -jne 0x49a0cd
    if (!cpu.flags.zf)
    {
        goto L_0x0049a0cd;
    }
    // 0049a0c5  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049a0c7  7404                   -je 0x49a0cd
    if (cpu.flags.zf)
    {
        goto L_0x0049a0cd;
    }
    // 0049a0c9  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049a0ca  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049a0cb  ebd9                   -jmp 0x49a0a6
    goto L_0x0049a0a6;
L_0x0049a0cd:
    // 0049a0cd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a0cf  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049a0d1  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 0049a0d3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a0d8  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a0da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a0dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49a0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a0e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a0e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a0e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a0e3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a0e6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049a0ea  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049a0ed  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049a0f1  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0049a0f6  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a0f8  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0049a0fa  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049a0fe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049a103  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049a108  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049a10a  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a10e  a388e95600             -mov dword ptr [0x56e988], eax
    app->getMemory<x86::reg32>(x86::reg32(5695880) /* 0x56e988 */) = cpu.eax;
    // 0049a113  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049a115  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a119  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049a11e  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a120  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049a122  a38ce95600             -mov dword ptr [0x56e98c], eax
    app->getMemory<x86::reg32>(x86::reg32(5695884) /* 0x56e98c */) = cpu.eax;
    // 0049a127  a188e95600             -mov eax, dword ptr [0x56e988]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695880) /* 0x56e988 */);
    // 0049a12c  a3cce95600             -mov dword ptr [0x56e9cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */) = cpu.eax;
    // 0049a131  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049a134  8b1588e95600           -mov edx, dword ptr [0x56e988]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695880) /* 0x56e988 */);
    // 0049a13a  891d84e95600           -mov dword ptr [0x56e984], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695876) /* 0x56e984 */) = cpu.ebx;
    // 0049a140  a3d0e95600             -mov dword ptr [0x56e9d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */) = cpu.eax;
    // 0049a145  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049a149  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a14d  e872070000             -call 0x49a8c4
    cpu.esp -= 4;
    sub_49a8c4(app, cpu);
    if (cpu.terminate) return;
    // 0049a152  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a154  8b1d84e95600           -mov ebx, dword ptr [0x56e984]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695876) /* 0x56e984 */);
    // 0049a15a  891580e95600           -mov dword ptr [0x56e980], edx
    app->getMemory<x86::reg32>(x86::reg32(5695872) /* 0x56e980 */) = cpu.edx;
    // 0049a160  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a162  7e23                   -jle 0x49a187
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a187;
    }
L_0x0049a164:
    // 0049a164  a180e95600             -mov eax, dword ptr [0x56e980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695872) /* 0x56e980 */);
    // 0049a169  80b8808a4d0000         +cmp byte ptr [eax + 0x4d8a80], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5081728) /* 0x4d8a80 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a170  7524                   -jne 0x49a196
    if (!cpu.flags.zf)
    {
        goto L_0x0049a196;
    }
L_0x0049a172:
    // 0049a172  8b3580e95600           -mov esi, dword ptr [0x56e980]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695872) /* 0x56e980 */);
    // 0049a178  46                     -inc esi
    (cpu.esi)++;
    // 0049a179  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a17d  893580e95600           -mov dword ptr [0x56e980], esi
    app->getMemory<x86::reg32>(x86::reg32(5695872) /* 0x56e980 */) = cpu.esi;
    // 0049a183  39fe                   +cmp esi, edi
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
    // 0049a185  7cdd                   -jl 0x49a164
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a164;
    }
L_0x0049a187:
    // 0049a187  891d84e95600           -mov dword ptr [0x56e984], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695876) /* 0x56e984 */) = cpu.ebx;
    // 0049a18d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a190  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a191  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a192  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a193  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049a196:
    // 0049a196  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049a199  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a19c  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a19e  0fb67702               -movzx esi, byte ptr [edi + 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */));
    // 0049a1a2  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a1a6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a1a8  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049a1aa  0fb66f01               -movzx ebp, byte ptr [edi + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */));
    // 0049a1ae  a3b8e95600             -mov dword ptr [0x56e9b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5695928) /* 0x56e9b8 */) = cpu.eax;
    // 0049a1b3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a1b5  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049a1b7  0fb63f                 -movzx edi, byte ptr [edi]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 0049a1ba  a3a8e95600             -mov dword ptr [0x56e9a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5695912) /* 0x56e9a8 */) = cpu.eax;
    // 0049a1bf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a1c1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049a1c3  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0049a1c5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a1c8  a3ace95600             -mov dword ptr [0x56e9ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5695916) /* 0x56e9ac */) = cpu.eax;
    // 0049a1cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a1cf  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a1d1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049a1d3  8b0db8e95600           -mov ecx, dword ptr [0x56e9b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695928) /* 0x56e9b8 */);
    // 0049a1d9  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049a1dc  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0049a1df  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049a1e1  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049a1e4  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a1e6  8b15a8e95600           -mov edx, dword ptr [0x56e9a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695912) /* 0x56e9a8 */);
    // 0049a1ec  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049a1ef  890dbce95600           -mov dword ptr [0x56e9bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */) = cpu.ecx;
    // 0049a1f5  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049a1f7  0fafeb                 -imul ebp, ebx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049a1fa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a1fc  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a1fe  8b15ace95600           -mov edx, dword ptr [0x56e9ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695916) /* 0x56e9ac */);
    // 0049a204  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049a207  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049a209  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049a20b  0faffb                 -imul edi, ebx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049a20e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a210  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a212  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049a215  8915b4e95600           -mov dword ptr [0x56e9b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5695924) /* 0x56e9b4 */) = cpu.edx;
    // 0049a21b  8b15bce95600           -mov edx, dword ptr [0x56e9bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */);
    // 0049a221  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a224  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a226  a1b4e95600             -mov eax, dword ptr [0x56e9b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695924) /* 0x56e9b4 */);
    // 0049a22b  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049a22e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a230  a1b8e95600             -mov eax, dword ptr [0x56e9b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695928) /* 0x56e9b8 */);
    // 0049a235  8915b4e95600           -mov dword ptr [0x56e9b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5695924) /* 0x56e9b4 */) = cpu.edx;
    // 0049a23b  8b158ce95600           -mov edx, dword ptr [0x56e98c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695884) /* 0x56e98c */);
    // 0049a241  40                     -inc eax
    (cpu.eax)++;
    // 0049a242  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a245  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a247  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a249  a390e95600             -mov dword ptr [0x56e990], eax
    app->getMemory<x86::reg32>(x86::reg32(5695888) /* 0x56e990 */) = cpu.eax;
    // 0049a24e  a1a8e95600             -mov eax, dword ptr [0x56e9a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695912) /* 0x56e9a8 */);
    // 0049a253  40                     -inc eax
    (cpu.eax)++;
    // 0049a254  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a257  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a259  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a25b  a398e95600             -mov dword ptr [0x56e998], eax
    app->getMemory<x86::reg32>(x86::reg32(5695896) /* 0x56e998 */) = cpu.eax;
    // 0049a260  a1ace95600             -mov eax, dword ptr [0x56e9ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695916) /* 0x56e9ac */);
    // 0049a265  40                     -inc eax
    (cpu.eax)++;
    // 0049a266  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a269  8b35b8e95600           -mov esi, dword ptr [0x56e9b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695928) /* 0x56e9b8 */);
    // 0049a26f  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049a271  0faf35d0e95600         -imul esi, dword ptr [0x56e9d0]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */))));
    // 0049a278  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a27a  a394e95600             -mov dword ptr [0x56e994], eax
    app->getMemory<x86::reg32>(x86::reg32(5695892) /* 0x56e994 */) = cpu.eax;
    // 0049a27f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049a283  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0049a28a  8b15cce95600           -mov edx, dword ptr [0x56e9cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 0049a290  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a292  a1a8e95600             -mov eax, dword ptr [0x56e9a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695912) /* 0x56e9a8 */);
    // 0049a297  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a29a  890dc8e95600           -mov dword ptr [0x56e9c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.ecx;
    // 0049a2a0  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a2a4  891d84e95600           -mov dword ptr [0x56e984], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695876) /* 0x56e984 */) = cpu.ebx;
    // 0049a2aa  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a2ac  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 0049a2b3  8b15ace95600           -mov edx, dword ptr [0x56e9ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695916) /* 0x56e9ac */);
    // 0049a2b9  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049a2bb  8b3dace95600           -mov edi, dword ptr [0x56e9ac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695916) /* 0x56e9ac */);
    // 0049a2c1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a2c3  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049a2c6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a2c8  01fd                   +add ebp, edi
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
    // 0049a2ca  8915a4e95600           -mov dword ptr [0x56e9a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5695908) /* 0x56e9a4 */) = cpu.edx;
    // 0049a2d0  892da0e95600           -mov dword ptr [0x56e9a0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695904) /* 0x56e9a0 */) = cpu.ebp;
    // 0049a2d6  e80d000000             -call 0x49a2e8
    cpu.esp -= 4;
    sub_49a2e8(app, cpu);
    if (cpu.terminate) return;
    // 0049a2db  8b1d84e95600           -mov ebx, dword ptr [0x56e984]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695876) /* 0x56e984 */);
    // 0049a2e1  e98cfeffff             -jmp 0x49a172
    goto L_0x0049a172;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49a2e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a2e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a2e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a2ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a2eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a2ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a2ed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a2ee  8b1d8ce95600           -mov ebx, dword ptr [0x56e98c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695884) /* 0x56e98c */);
    // 0049a2f4  8b0db8e95600           -mov ecx, dword ptr [0x56e9b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695928) /* 0x56e9b8 */);
    // 0049a2fa  a1b4e95600             -mov eax, dword ptr [0x56e9b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695924) /* 0x56e9b4 */);
    // 0049a2ff  8b3590e95600           -mov esi, dword ptr [0x56e990]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695888) /* 0x56e990 */);
    // 0049a305  8b3d88e95600           -mov edi, dword ptr [0x56e988]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695880) /* 0x56e988 */);
    // 0049a30b  a3bce95600             -mov dword ptr [0x56e9bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */) = cpu.eax;
    // 0049a310  a1a0e95600             -mov eax, dword ptr [0x56e9a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695904) /* 0x56e9a0 */);
    // 0049a315  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a317  a39ce95600             -mov dword ptr [0x56e99c], eax
    app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */) = cpu.eax;
    // 0049a31c  a1a4e95600             -mov eax, dword ptr [0x56e9a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695908) /* 0x56e9a4 */);
    // 0049a321  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a323  a3c0e95600             -mov dword ptr [0x56e9c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */) = cpu.eax;
    // 0049a328  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049a32d  39f9                   +cmp ecx, edi
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
    // 0049a32f  0f8cc0000000           -jl 0x49a3f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a3f5;
    }
L_0x0049a335:
    // 0049a335  8b3590e95600           -mov esi, dword ptr [0x56e990]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695888) /* 0x56e990 */);
    // 0049a33b  a1b4e95600             -mov eax, dword ptr [0x56e9b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695924) /* 0x56e9b4 */);
    // 0049a340  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a342  8b3dd0e95600           -mov edi, dword ptr [0x56e9d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */);
    // 0049a348  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a34a  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049a34d  a3bce95600             -mov dword ptr [0x56e9bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */) = cpu.eax;
    // 0049a352  a1a0e95600             -mov eax, dword ptr [0x56e9a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695904) /* 0x56e9a0 */);
    // 0049a357  8b0db8e95600           -mov ecx, dword ptr [0x56e9b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695928) /* 0x56e9b8 */);
    // 0049a35d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049a35f  8b2dd0e95600           -mov ebp, dword ptr [0x56e9d0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */);
    // 0049a365  a39ce95600             -mov dword ptr [0x56e99c], eax
    app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */) = cpu.eax;
    // 0049a36a  a1a4e95600             -mov eax, dword ptr [0x56e9a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695908) /* 0x56e9a4 */);
    // 0049a36f  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a370  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a372  8935d4e95600           -mov dword ptr [0x56e9d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */) = cpu.esi;
    // 0049a378  a3c0e95600             -mov dword ptr [0x56e9c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */) = cpu.eax;
    // 0049a37d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049a382  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a384  7c60                   -jl 0x49a3e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a3e6;
    }
L_0x0049a386:
    // 0049a386  e8f5000000             -call 0x49a480
    cpu.esp -= 4;
    sub_49a480(app, cpu);
    if (cpu.terminate) return;
    // 0049a38b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a38d  0f84dd000000           -je 0x49a470
    if (cpu.flags.zf)
    {
        goto L_0x0049a470;
    }
    // 0049a393  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049a398:
    // 0049a398  a1d0e95600             -mov eax, dword ptr [0x56e9d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */);
    // 0049a39d  8b359ce95600           -mov esi, dword ptr [0x56e99c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */);
    // 0049a3a3  8b3dc0e95600           -mov edi, dword ptr [0x56e9c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */);
    // 0049a3a9  8b2dbce95600           -mov ebp, dword ptr [0x56e9bc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */);
    // 0049a3af  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a3b2  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a3b3  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a3b5  a1d0e95600             -mov eax, dword ptr [0x56e9d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */);
    // 0049a3ba  89359ce95600           -mov dword ptr [0x56e99c], esi
    app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */) = cpu.esi;
    // 0049a3c0  8b35d4e95600           -mov esi, dword ptr [0x56e9d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */);
    // 0049a3c6  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a3c8  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a3ca  893dc0e95600           -mov dword ptr [0x56e9c0], edi
    app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */) = cpu.edi;
    // 0049a3d0  8935d4e95600           -mov dword ptr [0x56e9d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */) = cpu.esi;
    // 0049a3d6  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a3d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a3da  892dbce95600           -mov dword ptr [0x56e9bc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */) = cpu.ebp;
    // 0049a3e0  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a3e2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a3e4  7da0                   -jge 0x49a386
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a386;
    }
L_0x0049a3e6:
    // 0049a3e6  8b35d4e95600           -mov esi, dword ptr [0x56e9d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */);
    // 0049a3ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a3ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a3f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a3f5:
    // 0049a3f5  8935d4e95600           -mov dword ptr [0x56e9d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */) = cpu.esi;
L_0x0049a3fb:
    // 0049a3fb  e880000000             -call 0x49a480
    cpu.esp -= 4;
    sub_49a480(app, cpu);
    if (cpu.terminate) return;
    // 0049a400  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a402  745c                   -je 0x49a460
    if (cpu.flags.zf)
    {
        goto L_0x0049a460;
    }
    // 0049a404  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049a409  8b35d4e95600           -mov esi, dword ptr [0x56e9d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */);
L_0x0049a40f:
    // 0049a40f  a1d0e95600             -mov eax, dword ptr [0x56e9d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */);
    // 0049a414  8b2d9ce95600           -mov ebp, dword ptr [0x56e99c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */);
    // 0049a41a  8b3dc0e95600           -mov edi, dword ptr [0x56e9c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */);
    // 0049a420  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a423  41                     -inc ecx
    (cpu.ecx)++;
    // 0049a424  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a426  a1d0e95600             -mov eax, dword ptr [0x56e9d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695952) /* 0x56e9d0 */);
    // 0049a42b  892d9ce95600           -mov dword ptr [0x56e99c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */) = cpu.ebp;
    // 0049a431  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a433  8b2dbce95600           -mov ebp, dword ptr [0x56e9bc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */);
    // 0049a439  893dc0e95600           -mov dword ptr [0x56e9c0], edi
    app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */) = cpu.edi;
    // 0049a43f  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a441  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a443  8b3d88e95600           -mov edi, dword ptr [0x56e988]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695880) /* 0x56e988 */);
    // 0049a449  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a44b  892dbce95600           -mov dword ptr [0x56e9bc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */) = cpu.ebp;
    // 0049a451  8935d4e95600           -mov dword ptr [0x56e9d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */) = cpu.esi;
    // 0049a457  39f9                   +cmp ecx, edi
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
    // 0049a459  7ca0                   -jl 0x49a3fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a3fb;
    }
    // 0049a45b  e9d5feffff             -jmp 0x49a335
    goto L_0x0049a335;
L_0x0049a460:
    // 0049a460  8b35d4e95600           -mov esi, dword ptr [0x56e9d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695956) /* 0x56e9d4 */);
    // 0049a466  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a468  0f85c7feffff           -jne 0x49a335
    if (!cpu.flags.zf)
    {
        goto L_0x0049a335;
    }
    // 0049a46e  eb9f                   -jmp 0x49a40f
    goto L_0x0049a40f;
L_0x0049a470:
    // 0049a470  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a472  0f856effffff           -jne 0x49a3e6
    if (!cpu.flags.zf)
    {
        goto L_0x0049a3e6;
    }
    // 0049a478  e91bffffff             -jmp 0x49a398
    goto L_0x0049a398;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49a480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a485  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a486  8b358ce95600           -mov esi, dword ptr [0x56e98c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695884) /* 0x56e98c */);
    // 0049a48c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a48e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a490  0f855d020000           -jne 0x49a6f3
    if (!cpu.flags.zf)
    {
        goto L_0x0049a6f3;
    }
L_0x0049a496:
    // 0049a496  8b0dd8e95600           -mov ecx, dword ptr [0x56e9d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695960) /* 0x56e9d8 */);
    // 0049a49c  a1bce95600             -mov eax, dword ptr [0x56e9bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */);
    // 0049a4a1  8b1de4e95600           -mov ebx, dword ptr [0x56e9e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695972) /* 0x56e9e4 */);
    // 0049a4a7  a3c8e95600             -mov dword ptr [0x56e9c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.eax;
    // 0049a4ac  a3ece95600             -mov dword ptr [0x56e9ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */) = cpu.eax;
    // 0049a4b1  a19ce95600             -mov eax, dword ptr [0x56e99c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */);
    // 0049a4b6  8b3de0e95600           -mov edi, dword ptr [0x56e9e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */);
    // 0049a4bc  a3b0e95600             -mov dword ptr [0x56e9b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */) = cpu.eax;
    // 0049a4c1  a3f0e95600             -mov dword ptr [0x56e9f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */) = cpu.eax;
    // 0049a4c6  a1c0e95600             -mov eax, dword ptr [0x56e9c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */);
    // 0049a4cb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a4cd  a3c4e95600             -mov dword ptr [0x56e9c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */) = cpu.eax;
    // 0049a4d2  a3f4e95600             -mov dword ptr [0x56e9f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */) = cpu.eax;
    // 0049a4d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049a4dc  39f9                   +cmp ecx, edi
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
    // 0049a4de  0f8fce000000           -jg 0x49a5b2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a5b2;
    }
    // 0049a4e4  891de8e95600           -mov dword ptr [0x56e9e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */) = cpu.ebx;
L_0x0049a4ea:
    // 0049a4ea  e84d020000             -call 0x49a73c
    cpu.esp -= 4;
    sub_49a73c(app, cpu);
    if (cpu.terminate) return;
    // 0049a4ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a4f1  0f8428020000           -je 0x49a71f
    if (cpu.flags.zf)
    {
        goto L_0x0049a71f;
    }
    // 0049a4f7  8b1de8e95600           -mov ebx, dword ptr [0x56e9e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */);
    // 0049a4fd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a4ff  7537                   -jne 0x49a538
    if (!cpu.flags.zf)
    {
        goto L_0x0049a538;
    }
    // 0049a501  3b0dd8e95600           +cmp ecx, dword ptr [0x56e9d8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5695960) /* 0x56e9d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a507  7e2a                   -jle 0x49a533
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a533;
    }
    // 0049a509  a1f0e95600             -mov eax, dword ptr [0x56e9f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */);
    // 0049a50e  a39ce95600             -mov dword ptr [0x56e99c], eax
    app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */) = cpu.eax;
    // 0049a513  a1f4e95600             -mov eax, dword ptr [0x56e9f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */);
    // 0049a518  890dd8e95600           -mov dword ptr [0x56e9d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5695960) /* 0x56e9d8 */) = cpu.ecx;
    // 0049a51e  a3c0e95600             -mov dword ptr [0x56e9c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */) = cpu.eax;
    // 0049a523  a1ece95600             -mov eax, dword ptr [0x56e9ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */);
    // 0049a528  891de4e95600           -mov dword ptr [0x56e9e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695972) /* 0x56e9e4 */) = cpu.ebx;
    // 0049a52e  a3bce95600             -mov dword ptr [0x56e9bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */) = cpu.eax;
L_0x0049a533:
    // 0049a533  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049a538:
    // 0049a538  a1cce95600             -mov eax, dword ptr [0x56e9cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 0049a53d  8b2db0e95600           -mov ebp, dword ptr [0x56e9b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */);
    // 0049a543  8b3df0e95600           -mov edi, dword ptr [0x56e9f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */);
    // 0049a549  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a54c  41                     -inc ecx
    (cpu.ecx)++;
    // 0049a54d  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a54f  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a551  a1cce95600             -mov eax, dword ptr [0x56e9cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 0049a556  892db0e95600           -mov dword ptr [0x56e9b0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */) = cpu.ebp;
    // 0049a55c  893df0e95600           -mov dword ptr [0x56e9f0], edi
    app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */) = cpu.edi;
    // 0049a562  8b2dc4e95600           -mov ebp, dword ptr [0x56e9c4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */);
    // 0049a568  8b3df4e95600           -mov edi, dword ptr [0x56e9f4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */);
    // 0049a56e  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a570  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a572  892dc4e95600           -mov dword ptr [0x56e9c4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */) = cpu.ebp;
    // 0049a578  893df4e95600           -mov dword ptr [0x56e9f4], edi
    app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */) = cpu.edi;
    // 0049a57e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a580  8b2dc8e95600           -mov ebp, dword ptr [0x56e9c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */);
    // 0049a586  8b3dece95600           -mov edi, dword ptr [0x56e9ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */);
    // 0049a58c  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a58e  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a590  892dc8e95600           -mov dword ptr [0x56e9c8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.ebp;
    // 0049a596  893dece95600           -mov dword ptr [0x56e9ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */) = cpu.edi;
    // 0049a59c  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a59e  8b2de0e95600           -mov ebp, dword ptr [0x56e9e0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */);
    // 0049a5a4  891de8e95600           -mov dword ptr [0x56e9e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */) = cpu.ebx;
    // 0049a5aa  39e9                   +cmp ecx, ebp
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
    // 0049a5ac  0f8e38ffffff           -jle 0x49a4ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a4ea;
    }
L_0x0049a5b2:
    // 0049a5b2  8b0dd8e95600           -mov ecx, dword ptr [0x56e9d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695960) /* 0x56e9d8 */);
    // 0049a5b8  8b1de4e95600           -mov ebx, dword ptr [0x56e9e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695972) /* 0x56e9e4 */);
    // 0049a5be  a1bce95600             -mov eax, dword ptr [0x56e9bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */);
    // 0049a5c3  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a5c5  8b3dcce95600           -mov edi, dword ptr [0x56e9cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 0049a5cb  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a5cd  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049a5d0  a3c8e95600             -mov dword ptr [0x56e9c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.eax;
    // 0049a5d5  a3ece95600             -mov dword ptr [0x56e9ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */) = cpu.eax;
    // 0049a5da  a19ce95600             -mov eax, dword ptr [0x56e99c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */);
    // 0049a5df  8b2ddce95600           -mov ebp, dword ptr [0x56e9dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695964) /* 0x56e9dc */);
    // 0049a5e5  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049a5e7  8b3dcce95600           -mov edi, dword ptr [0x56e9cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 0049a5ed  a3b0e95600             -mov dword ptr [0x56e9b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */) = cpu.eax;
    // 0049a5f2  a3f0e95600             -mov dword ptr [0x56e9f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */) = cpu.eax;
    // 0049a5f7  a1c0e95600             -mov eax, dword ptr [0x56e9c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */);
    // 0049a5fc  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a5fd  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049a5ff  891de8e95600           -mov dword ptr [0x56e9e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */) = cpu.ebx;
    // 0049a605  a3c4e95600             -mov dword ptr [0x56e9c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */) = cpu.eax;
    // 0049a60a  a3f4e95600             -mov dword ptr [0x56e9f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */) = cpu.eax;
    // 0049a60f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049a614  39e9                   +cmp ecx, ebp
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
    // 0049a616  0f8cc8000000           -jl 0x49a6e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a6e4;
    }
L_0x0049a61c:
    // 0049a61c  e81b010000             -call 0x49a73c
    cpu.esp -= 4;
    sub_49a73c(app, cpu);
    if (cpu.terminate) return;
    // 0049a621  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a623  0f8409010000           -je 0x49a732
    if (cpu.flags.zf)
    {
        goto L_0x0049a732;
    }
    // 0049a629  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a62b  7535                   -jne 0x49a662
    if (!cpu.flags.zf)
    {
        goto L_0x0049a662;
    }
    // 0049a62d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049a632  a1f0e95600             -mov eax, dword ptr [0x56e9f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */);
    // 0049a637  8b1de8e95600           -mov ebx, dword ptr [0x56e9e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */);
    // 0049a63d  a39ce95600             -mov dword ptr [0x56e99c], eax
    app->getMemory<x86::reg32>(x86::reg32(5695900) /* 0x56e99c */) = cpu.eax;
    // 0049a642  a1f4e95600             -mov eax, dword ptr [0x56e9f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */);
    // 0049a647  890dd8e95600           -mov dword ptr [0x56e9d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5695960) /* 0x56e9d8 */) = cpu.ecx;
    // 0049a64d  a3c0e95600             -mov dword ptr [0x56e9c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695936) /* 0x56e9c0 */) = cpu.eax;
    // 0049a652  a1ece95600             -mov eax, dword ptr [0x56e9ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */);
    // 0049a657  891de4e95600           -mov dword ptr [0x56e9e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695972) /* 0x56e9e4 */) = cpu.ebx;
    // 0049a65d  a3bce95600             -mov dword ptr [0x56e9bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5695932) /* 0x56e9bc */) = cpu.eax;
L_0x0049a662:
    // 0049a662  a1cce95600             -mov eax, dword ptr [0x56e9cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 0049a667  8b1db0e95600           -mov ebx, dword ptr [0x56e9b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */);
    // 0049a66d  8b3df0e95600           -mov edi, dword ptr [0x56e9f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */);
    // 0049a673  8b2dc4e95600           -mov ebp, dword ptr [0x56e9c4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */);
    // 0049a679  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a67c  49                     -dec ecx
    (cpu.ecx)--;
    // 0049a67d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a67f  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a681  a1cce95600             -mov eax, dword ptr [0x56e9cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695948) /* 0x56e9cc */);
    // 0049a686  891db0e95600           -mov dword ptr [0x56e9b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */) = cpu.ebx;
    // 0049a68c  893df0e95600           -mov dword ptr [0x56e9f0], edi
    app->getMemory<x86::reg32>(x86::reg32(5695984) /* 0x56e9f0 */) = cpu.edi;
    // 0049a692  8b1df4e95600           -mov ebx, dword ptr [0x56e9f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */);
    // 0049a698  8b3dc8e95600           -mov edi, dword ptr [0x56e9c8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */);
    // 0049a69e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a6a0  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a6a2  891df4e95600           -mov dword ptr [0x56e9f4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695988) /* 0x56e9f4 */) = cpu.ebx;
    // 0049a6a8  8b1de8e95600           -mov ebx, dword ptr [0x56e9e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */);
    // 0049a6ae  892dc4e95600           -mov dword ptr [0x56e9c4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */) = cpu.ebp;
    // 0049a6b4  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049a6b6  8b2dece95600           -mov ebp, dword ptr [0x56e9ec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */);
    // 0049a6bc  891de8e95600           -mov dword ptr [0x56e9e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */) = cpu.ebx;
    // 0049a6c2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049a6c4  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a6c6  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a6c8  893dc8e95600           -mov dword ptr [0x56e9c8], edi
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.edi;
    // 0049a6ce  892dece95600           -mov dword ptr [0x56e9ec], ebp
    app->getMemory<x86::reg32>(x86::reg32(5695980) /* 0x56e9ec */) = cpu.ebp;
    // 0049a6d4  8b3ddce95600           -mov edi, dword ptr [0x56e9dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695964) /* 0x56e9dc */);
    // 0049a6da  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a6dc  39f9                   +cmp ecx, edi
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
    // 0049a6de  0f8d38ffffff           -jge 0x49a61c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a61c;
    }
L_0x0049a6e4:
    // 0049a6e4  8b1de8e95600           -mov ebx, dword ptr [0x56e9e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */);
    // 0049a6ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a6ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a6f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a6f3:
    // 0049a6f3  a1a8e95600             -mov eax, dword ptr [0x56e9a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695912) /* 0x56e9a8 */);
    // 0049a6f8  a3d8e95600             -mov dword ptr [0x56e9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5695960) /* 0x56e9d8 */) = cpu.eax;
    // 0049a6fd  a188e95600             -mov eax, dword ptr [0x56e988]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695880) /* 0x56e988 */);
    // 0049a702  48                     -dec eax
    (cpu.eax)--;
    // 0049a703  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049a705  a3e0e95600             -mov dword ptr [0x56e9e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695968) /* 0x56e9e0 */) = cpu.eax;
    // 0049a70a  a198e95600             -mov eax, dword ptr [0x56e998]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695896) /* 0x56e998 */);
    // 0049a70f  890ddce95600           -mov dword ptr [0x56e9dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5695964) /* 0x56e9dc */) = cpu.ecx;
    // 0049a715  a3e4e95600             -mov dword ptr [0x56e9e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5695972) /* 0x56e9e4 */) = cpu.eax;
    // 0049a71a  e977fdffff             -jmp 0x49a496
    goto L_0x0049a496;
L_0x0049a71f:
    // 0049a71f  8b1de8e95600           -mov ebx, dword ptr [0x56e9e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5695976) /* 0x56e9e8 */);
    // 0049a725  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a727  0f8585feffff           -jne 0x49a5b2
    if (!cpu.flags.zf)
    {
        goto L_0x0049a5b2;
    }
    // 0049a72d  e906feffff             -jmp 0x49a538
    goto L_0x0049a538;
L_0x0049a732:
    // 0049a732  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a734  75ae                   -jne 0x49a6e4
    if (!cpu.flags.zf)
    {
        goto L_0x0049a6e4;
    }
    // 0049a736  e927ffffff             -jmp 0x49a662
    goto L_0x0049a662;
}

/* align: skip 0x90 */
void Application::sub_49a73c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a73c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a73d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a73e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a73f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a740  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a741  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a742  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a745  8b1580e95600           -mov edx, dword ptr [0x56e980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695872) /* 0x56e980 */);
    // 0049a74b  8b2d8ce95600           -mov ebp, dword ptr [0x56e98c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5695884) /* 0x56e98c */);
    // 0049a751  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049a755  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a757  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a759  0f8582000000           -jne 0x49a7e1
    if (!cpu.flags.zf)
    {
        goto L_0x0049a7e1;
    }
L_0x0049a75f:
    // 0049a75f  8b0df8e95600           -mov ecx, dword ptr [0x56e9f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5695992) /* 0x56e9f8 */);
    // 0049a765  8b15c8e95600           -mov edx, dword ptr [0x56e9c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */);
    // 0049a76b  8b3504ea5600           -mov esi, dword ptr [0x56ea04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5696004) /* 0x56ea04 */);
    // 0049a771  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a773  a1b0e95600             -mov eax, dword ptr [0x56e9b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */);
    // 0049a778  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049a77b  8b1d00ea5600           -mov ebx, dword ptr [0x56ea00]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696000) /* 0x56ea00 */);
    // 0049a781  8b3dc4e95600           -mov edi, dword ptr [0x56e9c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */);
    // 0049a787  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049a78b  39d9                   +cmp ecx, ebx
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
    // 0049a78d  7f34                   -jg 0x49a7c3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a7c3;
    }
L_0x0049a78f:
    // 0049a78f  3b10                   +cmp edx, dword ptr [eax]
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
    // 0049a791  0f8376000000           -jae 0x49a80d
    if (!cpu.flags.cf)
    {
        goto L_0x0049a80d;
    }
    // 0049a797  3b0df8e95600           +cmp ecx, dword ptr [0x56e9f8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5695992) /* 0x56e9f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a79d  7e1d                   -jle 0x49a7bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a7bc;
    }
    // 0049a79f  890df8e95600           -mov dword ptr [0x56e9f8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5695992) /* 0x56e9f8 */) = cpu.ecx;
    // 0049a7a5  a3b0e95600             -mov dword ptr [0x56e9b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */) = cpu.eax;
    // 0049a7aa  893dc4e95600           -mov dword ptr [0x56e9c4], edi
    app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */) = cpu.edi;
    // 0049a7b0  8915c8e95600           -mov dword ptr [0x56e9c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.edx;
    // 0049a7b6  893504ea5600           -mov dword ptr [0x56ea04], esi
    app->getMemory<x86::reg32>(x86::reg32(5696004) /* 0x56ea04 */) = cpu.esi;
L_0x0049a7bc:
    // 0049a7bc  c7042401000000         -mov dword ptr [esp], 1
    app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
L_0x0049a7c3:
    // 0049a7c3  3b4c240c               +cmp ecx, dword ptr [esp + 0xc]
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
    // 0049a7c7  7f5b                   -jg 0x49a824
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a824;
    }
    // 0049a7c9  3b10                   +cmp edx, dword ptr [eax]
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
    // 0049a7cb  7357                   -jae 0x49a824
    if (!cpu.flags.cf)
    {
        goto L_0x0049a824;
    }
    // 0049a7cd  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049a7d1  41                     -inc ecx
    (cpu.ecx)++;
    // 0049a7d2  47                     -inc edi
    (cpu.edi)++;
    // 0049a7d3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049a7d5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a7d8  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a7da  885fff                 -mov byte ptr [edi - 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0049a7dd  01ee                   +add esi, ebp
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
    // 0049a7df  ebe2                   -jmp 0x49a7c3
    goto L_0x0049a7c3;
L_0x0049a7e1:
    // 0049a7e1  a1ace95600             -mov eax, dword ptr [0x56e9ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695916) /* 0x56e9ac */);
    // 0049a7e6  a3f8e95600             -mov dword ptr [0x56e9f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5695992) /* 0x56e9f8 */) = cpu.eax;
    // 0049a7eb  a188e95600             -mov eax, dword ptr [0x56e988]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695880) /* 0x56e988 */);
    // 0049a7f0  48                     -dec eax
    (cpu.eax)--;
    // 0049a7f1  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049a7f3  a300ea5600             -mov dword ptr [0x56ea00], eax
    app->getMemory<x86::reg32>(x86::reg32(5696000) /* 0x56ea00 */) = cpu.eax;
    // 0049a7f8  a194e95600             -mov eax, dword ptr [0x56e994]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695892) /* 0x56e994 */);
    // 0049a7fd  890dfce95600           -mov dword ptr [0x56e9fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5695996) /* 0x56e9fc */) = cpu.ecx;
    // 0049a803  a304ea5600             -mov dword ptr [0x56ea04], eax
    app->getMemory<x86::reg32>(x86::reg32(5696004) /* 0x56ea04 */) = cpu.eax;
    // 0049a808  e952ffffff             -jmp 0x49a75f
    goto L_0x0049a75f;
L_0x0049a80d:
    // 0049a80d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a811  41                     -inc ecx
    (cpu.ecx)++;
    // 0049a812  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a815  47                     -inc edi
    (cpu.edi)++;
    // 0049a816  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a818  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a81a  39d9                   +cmp ecx, ebx
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
    // 0049a81c  0f8e6dffffff           -jle 0x49a78f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a78f;
    }
    // 0049a822  eb9f                   -jmp 0x49a7c3
    goto L_0x0049a7c3;
L_0x0049a824:
    // 0049a824  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049a827  a1fce95600             -mov eax, dword ptr [0x56e9fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695996) /* 0x56e9fc */);
    // 0049a82c  8b35f8e95600           -mov esi, dword ptr [0x56e9f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5695992) /* 0x56e9f8 */);
    // 0049a832  8b0d04ea5600           -mov ecx, dword ptr [0x56ea04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696004) /* 0x56ea04 */);
    // 0049a838  8b15b0e95600           -mov edx, dword ptr [0x56e9b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */);
    // 0049a83e  8b3dc4e95600           -mov edi, dword ptr [0x56e9c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */);
    // 0049a844  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049a848  4e                     -dec esi
    (cpu.esi)--;
    // 0049a849  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a84c  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a84e  a1c8e95600             -mov eax, dword ptr [0x56e9c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */);
    // 0049a853  4f                     -dec edi
    (cpu.edi)--;
    // 0049a854  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a856  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a858  7506                   -jne 0x49a860
    if (!cpu.flags.zf)
    {
        goto L_0x0049a860;
    }
L_0x0049a85a:
    // 0049a85a  3b742408               +cmp esi, dword ptr [esp + 8]
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
    // 0049a85e  7d1e                   -jge 0x49a87e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a87e;
    }
L_0x0049a860:
    // 0049a860  3b742408               +cmp esi, dword ptr [esp + 8]
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
    // 0049a864  7c4e                   -jl 0x49a8b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a8b4;
    }
    // 0049a866  3b02                   +cmp eax, dword ptr [edx]
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
    // 0049a868  734a                   -jae 0x49a8b4
    if (!cpu.flags.cf)
    {
        goto L_0x0049a8b4;
    }
    // 0049a86a  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049a86e  4e                     -dec esi
    (cpu.esi)--;
    // 0049a86f  4f                     -dec edi
    (cpu.edi)--;
    // 0049a870  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a872  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049a874  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a877  29c8                   +sub eax, ecx
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
    // 0049a879  885f01                 -mov byte ptr [edi + 1], bl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049a87c  ebe2                   -jmp 0x49a860
    goto L_0x0049a860;
L_0x0049a87e:
    // 0049a87e  3b02                   +cmp eax, dword ptr [edx]
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
    // 0049a880  720b                   -jb 0x49a88d
    if (cpu.flags.cf)
    {
        goto L_0x0049a88d;
    }
    // 0049a882  4e                     -dec esi
    (cpu.esi)--;
    // 0049a883  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a886  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a888  4f                     -dec edi
    (cpu.edi)--;
    // 0049a889  29c8                   +sub eax, ecx
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
    // 0049a88b  ebcd                   -jmp 0x49a85a
    goto L_0x0049a85a;
L_0x0049a88d:
    // 0049a88d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049a892  8935f8e95600           -mov dword ptr [0x56e9f8], esi
    app->getMemory<x86::reg32>(x86::reg32(5695992) /* 0x56e9f8 */) = cpu.esi;
    // 0049a898  8915b0e95600           -mov dword ptr [0x56e9b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5695920) /* 0x56e9b0 */) = cpu.edx;
    // 0049a89e  893dc4e95600           -mov dword ptr [0x56e9c4], edi
    app->getMemory<x86::reg32>(x86::reg32(5695940) /* 0x56e9c4 */) = cpu.edi;
    // 0049a8a4  a3c8e95600             -mov dword ptr [0x56e9c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5695944) /* 0x56e9c8 */) = cpu.eax;
    // 0049a8a9  890d04ea5600           -mov dword ptr [0x56ea04], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696004) /* 0x56ea04 */) = cpu.ecx;
    // 0049a8af  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049a8b2  ebac                   -jmp 0x49a860
    goto L_0x0049a860;
L_0x0049a8b4:
    // 0049a8b4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049a8b7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049a8ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49a8c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a8c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a8c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a8c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a8c9  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a8cc  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049a8cf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a8d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a8d3  7e0f                   -jle 0x49a8e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a8e4;
    }
L_0x0049a8d5:
    // 0049a8d5  48                     -dec eax
    (cpu.eax)--;
    // 0049a8d6  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0049a8dc  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a8df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a8e1  7ff2                   -jg 0x49a8d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a8d5;
    }
    // 0049a8e3  90                     -nop 
    ;
L_0x0049a8e4:
    // 0049a8e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49a8e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a8e8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a8e9  8b157c8a4d00           -mov edx, dword ptr [0x4d8a7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081724) /* 0x4d8a7c */);
    // 0049a8ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a8f1  7502                   -jne 0x49a8f5
    if (!cpu.flags.zf)
    {
        goto L_0x0049a8f5;
    }
    // 0049a8f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a8f5:
    // 0049a8f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a8f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a8f8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a8fa  e86d84feff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0049a8ff  890d7c8a4d00           -mov dword ptr [0x4d8a7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5081724) /* 0x4d8a7c */) = cpu.ecx;
    // 0049a905  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a906  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a907  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a908(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a908  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a909  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a90a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a90b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a90c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a90d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a90e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049a910  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 0049a915  b834ef4c00             -mov eax, 0x4cef34
    cpu.eax = 5041972 /*0x4cef34*/;
    // 0049a91a  8b1d048a4d00           -mov ebx, dword ptr [0x4d8a04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 0049a920  e8fb7ffeff             -call 0x482920
    cpu.esp -= 4;
    sub_482920(app, cpu);
    if (cpu.terminate) return;
    // 0049a925  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a927  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a929  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a92b  7509                   -jne 0x49a936
    if (!cpu.flags.zf)
    {
        goto L_0x0049a936;
    }
    // 0049a92d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a92f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a930  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a931  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a932  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a933  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a934  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a935  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a936:
    // 0049a936  ba00000200             -mov edx, 0x20000
    cpu.edx = 131072 /*0x20000*/;
    // 0049a93b  b840ef4c00             -mov eax, 0x4cef40
    cpu.eax = 5041984 /*0x4cef40*/;
    // 0049a940  8b1d048a4d00           -mov ebx, dword ptr [0x4d8a04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 0049a946  e8d57ffeff             -call 0x482920
    cpu.esp -= 4;
    sub_482920(app, cpu);
    if (cpu.terminate) return;
    // 0049a94b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a94d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a94f  750b                   -jne 0x49a95c
    if (!cpu.flags.zf)
    {
        goto L_0x0049a95c;
    }
    // 0049a951  31cf                   -xor edi, ecx
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a953  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a956  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a957  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a958  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a959  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a95a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a95b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a95c:
    // 0049a95c  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0049a961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a962  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049a964  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a966  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049a96b  e870f7ffff             -call 0x49a0e0
    cpu.esp -= 4;
    sub_49a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0049a970  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a972  e8f583feff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0049a977  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a979  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a97a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a97b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a97c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a97d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a97e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a97f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a981  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a982  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049a988  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049a98a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a98c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049a991  e8eaec0000             -call 0x4a9680
    cpu.esp -= 4;
    sub_4a9680(app, cpu);
    if (cpu.terminate) return;
    // 0049a996  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a998  e86bffffff             -call 0x49a908
    cpu.esp -= 4;
    sub_49a908(app, cpu);
    if (cpu.terminate) return;
    // 0049a99d  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049a9a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49a9a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a9a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a9a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a9aa  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049a9b0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049a9b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a9b4  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049a9b9  e8b6ed0000             -call 0x4a9774
    cpu.esp -= 4;
    sub_4a9774(app, cpu);
    if (cpu.terminate) return;
    // 0049a9be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a9c0  e843ffffff             -call 0x49a908
    cpu.esp -= 4;
    sub_49a908(app, cpu);
    if (cpu.terminate) return;
    // 0049a9c5  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049a9cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49a9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a9d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a9d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a9d3  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049a9d9  e80affffff             -call 0x49a8e8
    cpu.esp -= 4;
    sub_49a8e8(app, cpu);
    if (cpu.terminate) return;
    // 0049a9de  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049a9e0  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049a9e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a9e7  e89c150000             -call 0x49bf88
    cpu.esp -= 4;
    sub_49bf88(app, cpu);
    if (cpu.terminate) return;
    // 0049a9ec  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a9ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a9f0  e813ffffff             -call 0x49a908
    cpu.esp -= 4;
    sub_49a908(app, cpu);
    if (cpu.terminate) return;
    // 0049a9f5  a37c8a4d00             -mov dword ptr [0x4d8a7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5081724) /* 0x4d8a7c */) = cpu.eax;
    // 0049a9fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a9fc  7405                   -je 0x49aa03
    if (cpu.flags.zf)
    {
        goto L_0x0049aa03;
    }
    // 0049a9fe  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0049aa03:
    // 0049aa03  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049aa05  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049aa0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49aa10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aa10  e9433f0100             -jmp 0x4ae958
    return sub_4ae958(app, cpu);
}

/* align: skip  */
/* data blob: 03104000574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939352e20416c6c207269676874732072657365727665642e */
void Application::sub_49aa84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aa84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049aa85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aa86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x0049aa87:
    // 0049aa87  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049aa89  fec2                   -inc dl
    (cpu.dl)++;
    // 0049aa8b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049aa91  f68228cd4d0002         +test byte ptr [edx + 0x4dcd28], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 2 /*0x2*/));
    // 0049aa98  7403                   -je 0x49aa9d
    if (cpu.flags.zf)
    {
        goto L_0x0049aa9d;
    }
    // 0049aa9a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049aa9b  ebea                   -jmp 0x49aa87
    goto L_0x0049aa87;
L_0x0049aa9d:
    // 0049aa9d  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049aa9f  80f92b                 +cmp cl, 0x2b
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049aaa2  7405                   -je 0x49aaa9
    if (cpu.flags.zf)
    {
        goto L_0x0049aaa9;
    }
    // 0049aaa4  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049aaa7  7501                   -jne 0x49aaaa
    if (!cpu.flags.zf)
    {
        goto L_0x0049aaaa;
    }
L_0x0049aaa9:
    // 0049aaa9  40                     -inc eax
    (cpu.eax)++;
L_0x0049aaaa:
    // 0049aaaa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049aaac:
    // 0049aaac  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049aaae  fec2                   -inc dl
    (cpu.dl)++;
    // 0049aab0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049aab6  f68228cd4d0020         +test byte ptr [edx + 0x4dcd28], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5098792) /* 0x4dcd28 */) & 32 /*0x20*/));
    // 0049aabd  740f                   -je 0x49aace
    if (cpu.flags.zf)
    {
        goto L_0x0049aace;
    }
    // 0049aabf  6bdb0a                 -imul ebx, ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0049aac2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049aac4  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049aac6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049aac8  40                     -inc eax
    (cpu.eax)++;
    // 0049aac9  83eb30                 +sub ebx, 0x30
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049aacc  ebde                   -jmp 0x49aaac
    goto L_0x0049aaac;
L_0x0049aace:
    // 0049aace  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049aad1  7502                   -jne 0x49aad5
    if (!cpu.flags.zf)
    {
        goto L_0x0049aad5;
    }
    // 0049aad3  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x0049aad5:
    // 0049aad5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049aad7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aad8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aad9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49aae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049aae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aae2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049aae3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049aae4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049aae6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049aae8  891518ea5600           -mov dword ptr [0x56ea18], edx
    app->getMemory<x86::reg32>(x86::reg32(5696024) /* 0x56ea18 */) = cpu.edx;
    // 0049aaee  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0049aaf5  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049aaf8  e8df03ffff             -call 0x48aedc
    cpu.esp -= 4;
    sub_48aedc(app, cpu);
    if (cpu.terminate) return;
    // 0049aafd  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049ab00  e897fffeff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0049ab05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ab07  7508                   -jne 0x49ab11
    if (!cpu.flags.zf)
    {
        goto L_0x0049ab11;
    }
    // 0049ab09  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0049ab0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ab11:
    // 0049ab11  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0049ab14  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0049ab17  8b5e40                 -mov ebx, dword ptr [esi + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0049ab1a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ab1b  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049ab1e  8b563c                 -mov edx, dword ptr [esi + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 0049ab21  e8d605ffff             -call 0x48b0fc
    cpu.esp -= 4;
    sub_48b0fc(app, cpu);
    if (cpu.terminate) return;
    // 0049ab26  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049ab29  e81201ffff             -call 0x48ac40
    cpu.esp -= 4;
    sub_48ac40(app, cpu);
    if (cpu.terminate) return;
    // 0049ab2e  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049ab31  e82a01ffff             -call 0x48ac60
    cpu.esp -= 4;
    sub_48ac60(app, cpu);
    if (cpu.terminate) return;
    // 0049ab36  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049ab39  e892f9feff             -call 0x48a4d0
    cpu.esp -= 4;
    sub_48a4d0(app, cpu);
    if (cpu.terminate) return;
    // 0049ab3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ab40  750f                   -jne 0x49ab51
    if (!cpu.flags.zf)
    {
        goto L_0x0049ab51;
    }
    // 0049ab42  c7463001000000         -mov dword ptr [esi + 0x30], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 0049ab49  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0049ab4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ab51:
    // 0049ab51  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049ab54  e82701ffff             -call 0x48ac80
    cpu.esp -= 4;
    sub_48ac80(app, cpu);
    if (cpu.terminate) return;
    // 0049ab59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ab5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ab60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ab60  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0049ab67  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ab6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49ab70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ab70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ab71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ab72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ab73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ab75  8b1d18ea5600           -mov ebx, dword ptr [0x56ea18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696024) /* 0x56ea18 */);
    // 0049ab7b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ab7d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049ab7f  7507                   -jne 0x49ab88
    if (!cpu.flags.zf)
    {
        goto L_0x0049ab88;
    }
L_0x0049ab81:
    // 0049ab81  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0049ab84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ab87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ab88:
    // 0049ab88  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049ab8b  e8b806ffff             -call 0x48b248
    cpu.esp -= 4;
    sub_48b248(app, cpu);
    if (cpu.terminate) return;
    // 0049ab90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ab92  74ed                   -je 0x49ab81
    if (cpu.flags.zf)
    {
        goto L_0x0049ab81;
    }
    // 0049ab94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ab96  ff1518ea5600           -call dword ptr [0x56ea18]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5696024) /* 0x56ea18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ab9c  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0049ab9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aba0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aba1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aba2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49aba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aba4  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049aba7  e9f006ffff             -jmp 0x48b29c
    return sub_48b29c(app, cpu);
}

/* align: skip  */
void Application::sub_49abac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049abac  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049abaf  e99406ffff             -jmp 0x48b248
    return sub_48b248(app, cpu);
}

/* align: skip  */
void Application::sub_49abb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049abb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049abb5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049abb7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049abb9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049abbb  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0049abbe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049abc0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049abc2  e8f107ffff             -call 0x48b3b8
    cpu.esp -= 4;
    sub_48b3b8(app, cpu);
    if (cpu.terminate) return;
    // 0049abc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049abc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049abcb  7c04                   -jl 0x49abd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049abd1;
    }
    // 0049abcd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049abcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049abd1:
    // 0049abd1  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049abd3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049abd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49abd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049abd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049abd9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049abdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049abdd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049abdf  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0049abe2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049abe4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049abe6  e85d03ffff             -call 0x48af48
    cpu.esp -= 4;
    sub_48af48(app, cpu);
    if (cpu.terminate) return;
    // 0049abeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049abec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49abf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049abf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049abf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049abf2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049abf4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049abf6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049abf8  745b                   -je 0x49ac55
    if (cpu.flags.zf)
    {
        goto L_0x0049ac55;
    }
    // 0049abfa  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049abfe  7516                   -jne 0x49ac16
    if (!cpu.flags.zf)
    {
        goto L_0x0049ac16;
    }
    // 0049ac00  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0049ac06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ac08  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049ac0b  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049ac0e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049ac10  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0049ac13  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x0049ac16:
    // 0049ac16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ac17  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 0049ac1b  7515                   -jne 0x49ac32
    if (!cpu.flags.zf)
    {
        goto L_0x0049ac32;
    }
    // 0049ac1d  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0049ac23  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0049ac28  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ac2a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049ac2d  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049ac2f  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0049ac32:
    // 0049ac32  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 0049ac36  7515                   -jne 0x49ac4d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ac4d;
    }
    // 0049ac38  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0049ac3e  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0049ac43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ac45  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049ac48  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049ac4a  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0049ac4d:
    // 0049ac4d  c7460803000000         -mov dword ptr [esi + 8], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 0049ac54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049ac55:
    // 0049ac55  badc294d00             -mov edx, 0x4d29dc
    cpu.edx = 5056988 /*0x4d29dc*/;
    // 0049ac5a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ac5b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ac5d  bb04b34d00             -mov ebx, 0x4db304
    cpu.ebx = 5092100 /*0x4db304*/;
    // 0049ac62  e891d9feff             -call 0x4885f8
    cpu.esp -= 4;
    sub_4885f8(app, cpu);
    if (cpu.terminate) return;
    // 0049ac67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49ac70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ac70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ac71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ac72  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ac74  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049ac76  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 0049ac7d  7405                   -je 0x49ac84
    if (cpu.flags.zf)
    {
        goto L_0x0049ac84;
    }
    // 0049ac7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ac81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ac84:
    // 0049ac84  e8dfd6feff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0049ac89  a340a25900             -mov dword ptr [0x59a240], eax
    app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */) = cpu.eax;
    // 0049ac8e  e8c5000000             -call 0x49ad58
    cpu.esp -= 4;
    sub_49ad58(app, cpu);
    if (cpu.terminate) return;
    // 0049ac93  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ac95  e802010000             -call 0x49ad9c
    cpu.esp -= 4;
    sub_49ad9c(app, cpu);
    if (cpu.terminate) return;
    // 0049ac9a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049ac9c  e803c3feff             -call 0x486fa4
    cpu.esp -= 4;
    sub_486fa4(app, cpu);
    if (cpu.terminate) return;
    // 0049aca1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049aca3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049aca5  7c0d                   -jl 0x49acb4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049acb4;
    }
    // 0049aca7  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0049aca9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049acab  881538b84d00           -mov byte ptr [0x4db838], dl
    app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */) = cpu.dl;
    // 0049acb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049acb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049acb3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049acb4:
    // 0049acb4  e85bc3feff             -call 0x487014
    cpu.esp -= 4;
    sub_487014(app, cpu);
    if (cpu.terminate) return;
    // 0049acb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049acbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049acbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049acbd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49acc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049acc0  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 0049acc7  7506                   -jne 0x49accf
    if (!cpu.flags.zf)
    {
        goto L_0x0049accf;
    }
    // 0049acc9  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049acce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049accf:
    // 0049accf  e8bcddffff             -call 0x498a90
    cpu.esp -= 4;
    sub_498a90(app, cpu);
    if (cpu.terminate) return;
    // 0049acd4  833d58b84d0000         +cmp dword ptr [0x4db858], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093464) /* 0x4db858 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049acdb  7406                   -je 0x49ace3
    if (cpu.flags.zf)
    {
        goto L_0x0049ace3;
    }
    // 0049acdd  ff1558b84d00           -call dword ptr [0x4db858]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093464) /* 0x4db858 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049ace3:
    // 0049ace3  833d5cb84d0000         +cmp dword ptr [0x4db85c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093468) /* 0x4db85c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049acea  7406                   -je 0x49acf2
    if (cpu.flags.zf)
    {
        goto L_0x0049acf2;
    }
    // 0049acec  ff155cb84d00           -call dword ptr [0x4db85c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093468) /* 0x4db85c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049acf2:
    // 0049acf2  833d60b84d0000         +cmp dword ptr [0x4db860], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093472) /* 0x4db860 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049acf9  7406                   -je 0x49ad01
    if (cpu.flags.zf)
    {
        goto L_0x0049ad01;
    }
    // 0049acfb  ff1560b84d00           -call dword ptr [0x4db860]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093472) /* 0x4db860 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049ad01:
    // 0049ad01  833d50b84d0000         +cmp dword ptr [0x4db850], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093456) /* 0x4db850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ad08  740b                   -je 0x49ad15
    if (cpu.flags.zf)
    {
        goto L_0x0049ad15;
    }
    // 0049ad0a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049ad0f  ff1550b84d00           -call dword ptr [0x4db850]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093456) /* 0x4db850 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049ad15:
    // 0049ad15  833d64b84d0000         +cmp dword ptr [0x4db864], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093476) /* 0x4db864 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ad1c  7406                   -je 0x49ad24
    if (cpu.flags.zf)
    {
        goto L_0x0049ad24;
    }
    // 0049ad1e  ff1564b84d00           -call dword ptr [0x4db864]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093476) /* 0x4db864 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049ad24:
    // 0049ad24  833d54b84d0000         +cmp dword ptr [0x4db854], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093460) /* 0x4db854 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ad2b  7406                   -je 0x49ad33
    if (cpu.flags.zf)
    {
        goto L_0x0049ad33;
    }
    // 0049ad2d  ff1554b84d00           -call dword ptr [0x4db854]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093460) /* 0x4db854 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049ad33:
    // 0049ad33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ad34  e8dbc2feff             -call 0x487014
    cpu.esp -= 4;
    sub_487014(app, cpu);
    if (cpu.terminate) return;
    // 0049ad39  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ad3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ad3d  7c0a                   -jl 0x49ad49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ad49;
    }
    // 0049ad3f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ad40  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0049ad42  881d38b84d00           -mov byte ptr [0x4db838], bl
    app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */) = cpu.bl;
    // 0049ad48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049ad49:
    // 0049ad49  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 0049ad4e  e891d6feff             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 0049ad53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ad55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49ad58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ad58  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ad59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049ad5b:
    // 0049ad5b  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049ad5e  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0049ad60  88909c9b5900           -mov byte ptr [eax + 0x599b9c], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5872540) /* 0x599b9c */) = cpu.dl;
    // 0049ad66  3d00060000             +cmp eax, 0x600
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1536 /*0x600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ad6b  75ee                   -jne 0x49ad5b
    if (!cpu.flags.zf)
    {
        goto L_0x0049ad5b;
    }
    // 0049ad6d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049ad6f:
    // 0049ad6f  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ad72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ad74  8990e8a15900           -mov dword ptr [eax + 0x59a1e8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5874152) /* 0x59a1e8 */) = cpu.edx;
    // 0049ad7a  8990eca15900           -mov dword ptr [eax + 0x59a1ec], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5874156) /* 0x59a1ec */) = cpu.edx;
    // 0049ad80  83f850                 +cmp eax, 0x50
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ad83  75ea                   -jne 0x49ad6f
    if (!cpu.flags.zf)
    {
        goto L_0x0049ad6f;
    }
    // 0049ad85  891548a25900           -mov dword ptr [0x59a248], edx
    app->getMemory<x86::reg32>(x86::reg32(5874248) /* 0x59a248 */) = cpu.edx;
    // 0049ad8b  891544a25900           -mov dword ptr [0x59a244], edx
    app->getMemory<x86::reg32>(x86::reg32(5874244) /* 0x59a244 */) = cpu.edx;
    // 0049ad91  c6054da259007f         -mov byte ptr [0x59a24d], 0x7f
    app->getMemory<x86::reg8>(x86::reg32(5874253) /* 0x59a24d */) = 127 /*0x7f*/;
    // 0049ad98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ad99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49ad9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ad9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ad9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ad9e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ad9f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ada1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ada3  e804bffeff             -call 0x486cac
    cpu.esp -= 4;
    sub_486cac(app, cpu);
    if (cpu.terminate) return;
    // 0049ada8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049adaa  83fbff                 +cmp ebx, -1
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
    // 0049adad  754c                   -jne 0x49adfb
    if (!cpu.flags.zf)
    {
        goto L_0x0049adfb;
    }
L_0x0049adaf:
    // 0049adaf  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
    // 0049adb1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049adb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049adb5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049adb7  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049adbd  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0049adc3  81e60000ff00           -and esi, 0xff0000
    cpu.esi &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0049adc9  83fbff                 +cmp ebx, -1
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
    // 0049adcc  7502                   -jne 0x49add0
    if (!cpu.flags.zf)
    {
        goto L_0x0049add0;
    }
    // 0049adce  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049add0:
    // 0049add0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049add2  742b                   -je 0x49adff
    if (cpu.flags.zf)
    {
        goto L_0x0049adff;
    }
    // 0049add4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049add6  7427                   -je 0x49adff
    if (cpu.flags.zf)
    {
        goto L_0x0049adff;
    }
    // 0049add8  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0049addb  7428                   -je 0x49ae05
    if (cpu.flags.zf)
    {
        goto L_0x0049ae05;
    }
    // 0049addd  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x0049ade2:
    // 0049ade2  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 0049ade5  743d                   -je 0x49ae24
    if (cpu.flags.zf)
    {
        goto L_0x0049ae24;
    }
    // 0049ade7  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0049adea:
    // 0049adea  f7c600000200           +test esi, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 131072 /*0x20000*/));
    // 0049adf0  7405                   -je 0x49adf7
    if (cpu.flags.zf)
    {
        goto L_0x0049adf7;
    }
    // 0049adf2  0d00000200             +or eax, 0x20000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(131072 /*0x20000*/))));
L_0x0049adf7:
    // 0049adf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adf9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049adfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049adfb:
    // 0049adfb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049adfd  ebb0                   -jmp 0x49adaf
    goto L_0x0049adaf;
L_0x0049adff:
    // 0049adff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ae01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ae05:
    // 0049ae05  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0049ae08  7407                   -je 0x49ae11
    if (cpu.flags.zf)
    {
        goto L_0x0049ae11;
    }
    // 0049ae0a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049ae0f  ebd1                   -jmp 0x49ade2
    goto L_0x0049ade2;
L_0x0049ae11:
    // 0049ae11  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0049ae14  7407                   -je 0x49ae1d
    if (cpu.flags.zf)
    {
        goto L_0x0049ae1d;
    }
    // 0049ae16  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049ae1b  ebc5                   -jmp 0x49ade2
    goto L_0x0049ade2;
L_0x0049ae1d:
    // 0049ae1d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ae22  ebbe                   -jmp 0x49ade2
    goto L_0x0049ade2;
L_0x0049ae24:
    // 0049ae24  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0049ae27  7405                   -je 0x49ae2e
    if (cpu.flags.zf)
    {
        goto L_0x0049ae2e;
    }
    // 0049ae29  80cc10                 +or ah, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0049ae2c  ebbc                   -jmp 0x49adea
    goto L_0x0049adea;
L_0x0049ae2e:
    // 0049ae2e  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 0049ae31  7405                   -je 0x49ae38
    if (cpu.flags.zf)
    {
        goto L_0x0049ae38;
    }
    // 0049ae33  80cc04                 +or ah, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0049ae36  ebb2                   -jmp 0x49adea
    goto L_0x0049adea;
L_0x0049ae38:
    // 0049ae38  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0049ae3b  7405                   -je 0x49ae42
    if (cpu.flags.zf)
    {
        goto L_0x0049ae42;
    }
    // 0049ae3d  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049ae40  eba8                   -jmp 0x49adea
    goto L_0x0049adea;
L_0x0049ae42:
    // 0049ae42  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 0049ae45  7405                   -je 0x49ae4c
    if (cpu.flags.zf)
    {
        goto L_0x0049ae4c;
    }
    // 0049ae47  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0049ae4a  eb9e                   -jmp 0x49adea
    goto L_0x0049adea;
L_0x0049ae4c:
    // 0049ae4c  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0049ae4f  eb99                   -jmp 0x49adea
    goto L_0x0049adea;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49ae60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ae60  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 0049ae67  7506                   -jne 0x49ae6f
    if (!cpu.flags.zf)
    {
        goto L_0x0049ae6f;
    }
    // 0049ae69  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049ae6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ae6f:
    // 0049ae6f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ae70  a1b8ab4d00             -mov eax, dword ptr [0x4dabb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 0049ae75  e8163d0100             -call 0x4aeb90
    cpu.esp -= 4;
    sub_4aeb90(app, cpu);
    if (cpu.terminate) return;
    // 0049ae7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ae7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ae7e  7c04                   -jl 0x49ae84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ae84;
    }
    // 0049ae80  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ae82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ae84:
    // 0049ae84  0fbe152aac4d00         -movsx edx, byte ptr [0x4dac2a]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5090346) /* 0x4dac2a */)));
    // 0049ae8b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ae8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ae8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ae8f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ae8f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ae90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ae91  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ae92  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049ae95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ae96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ae97  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049ae99  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049ae9b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ae9e  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049aea4  f6410c02               +test byte ptr [ecx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 0049aea8  751e                   -jne 0x49aec8
    if (!cpu.flags.zf)
    {
        goto L_0x0049aec8;
    }
    // 0049aeaa  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049aeaf  e86c730000             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 0049aeb4  80490c20               -or byte ptr [ecx + 0xc], 0x20
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049aeb8  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049aebb  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049aec1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049aec3  e9c6010000             -jmp 0x49b08e
    goto L_0x0049b08e;
L_0x0049aec8:
    // 0049aec8  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049aecb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049aecd  7510                   -jne 0x49aedf
    if (!cpu.flags.zf)
    {
        goto L_0x0049aedf;
    }
    // 0049aecf  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049aed2  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049aed8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049aeda  e9af010000             -jmp 0x49b08e
    goto L_0x0049b08e;
L_0x0049aedf:
    // 0049aedf  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049aee2  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0049aee6  7507                   -jne 0x49aeef
    if (!cpu.flags.zf)
    {
        goto L_0x0049aeef;
    }
    // 0049aee8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049aeea  e8dc0e0100             -call 0x4abdcb
    cpu.esp -= 4;
    sub_4abdcb(app, cpu);
    if (cpu.terminate) return;
L_0x0049aeef:
    // 0049aeef  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0049aef2  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0049aef5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aef7  83e030                 -and eax, 0x30
    cpu.eax &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049aefa  80e2cf                 -and dl, 0xcf
    cpu.dl &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 0049aefd  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049af01  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049af05  88550c                 -mov byte ptr [ebp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 0049af08  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0049af0b  0f84e1000000           -je 0x49aff2
    if (cpu.flags.zf)
    {
        goto L_0x0049aff2;
    }
    // 0049af11  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0049af15:
    // 0049af15  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049af19  7544                   -jne 0x49af5f
    if (!cpu.flags.zf)
    {
        goto L_0x0049af5f;
    }
    // 0049af1b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049af1f  3b4514                 +cmp eax, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049af22  723b                   -jb 0x49af5f
    if (cpu.flags.cf)
    {
        goto L_0x0049af5f;
    }
    // 0049af24  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049af26  30c3                   -xor bl, al
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.al));
    // 0049af28  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049af2b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049af2d  7502                   -jne 0x49af31
    if (!cpu.flags.zf)
    {
        goto L_0x0049af31;
    }
    // 0049af2f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0049af31:
    // 0049af31  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049af35  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049af38  e89e3c0100             -call 0x4aebdb
    cpu.esp -= 4;
    sub_4aebdb(app, cpu);
    if (cpu.terminate) return;
    // 0049af3d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049af3f  83f8ff                 +cmp eax, -1
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
    // 0049af42  7415                   -je 0x49af59
    if (cpu.flags.zf)
    {
        goto L_0x0049af59;
    }
    // 0049af44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049af46  0f8573000000           -jne 0x49afbf
    if (!cpu.flags.zf)
    {
        goto L_0x0049afbf;
    }
    // 0049af4c  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049af52  c740040c000000         -mov dword ptr [eax + 4], 0xc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
L_0x0049af59:
    // 0049af59  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049af5d  eb60                   -jmp 0x49afbf
    goto L_0x0049afbf;
L_0x0049af5f:
    // 0049af5f  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049af62  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049af65  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049af69  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049af6b  39fa                   +cmp edx, edi
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
    // 0049af6d  7602                   -jbe 0x49af71
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049af71;
    }
    // 0049af6f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0049af71:
    // 0049af71  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049af75  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049af77  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049af7a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049af7b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049af7d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049af7f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049af80  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049af82  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049af85  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049af87  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049af89  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049af8c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049af8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049af8f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049af90  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049af93  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049af96  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049af98  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049af9b  895d04                 -mov dword ptr [ebp + 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049af9e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049afa0  8a7d0d                 -mov bh, byte ptr [ebp + 0xd]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 0049afa3  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0049afa6  80cf10                 -or bh, 0x10
    cpu.bh |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0049afa9  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049afac  887d0d                 -mov byte ptr [ebp + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 0049afaf  39c8                   +cmp eax, ecx
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
    // 0049afb1  7405                   -je 0x49afb8
    if (cpu.flags.zf)
    {
        goto L_0x0049afb8;
    }
    // 0049afb3  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0049afb6  7407                   -je 0x49afbf
    if (cpu.flags.zf)
    {
        goto L_0x0049afbf;
    }
L_0x0049afb8:
    // 0049afb8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049afba  e890be0000             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
L_0x0049afbf:
    // 0049afbf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049afc3  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049afc7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049afcb  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049afcd  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049afcf  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049afd3  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049afd7  29d0                   +sub eax, edx
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
    // 0049afd9  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049afdd  0f847f000000           -je 0x49b062
    if (cpu.flags.zf)
    {
        goto L_0x0049b062;
    }
    // 0049afe3  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 0049afe7  0f8428ffffff           -je 0x49af15
    if (cpu.flags.zf)
    {
        goto L_0x0049af15;
    }
    // 0049afed  e970000000             -jmp 0x49b062
    goto L_0x0049b062;
L_0x0049aff2:
    // 0049aff2  8a5d0d                 -mov bl, byte ptr [ebp + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 0049aff5  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0049aff8  7414                   -je 0x49b00e
    if (cpu.flags.zf)
    {
        goto L_0x0049b00e;
    }
    // 0049affa  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 0049affc  80e7fa                 -and bh, 0xfa
    cpu.bh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 0049afff  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0049b001  887d0d                 -mov byte ptr [ebp + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 0049b004  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049b006  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049b00b  88450d                 -mov byte ptr [ebp + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x0049b00e:
    // 0049b00e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0049b011  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b015  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049b018  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0049b01f:
    // 0049b01f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b021  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049b023  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049b025  e87b3c0100             -call 0x4aeca5
    cpu.esp -= 4;
    sub_4aeca5(app, cpu);
    if (cpu.terminate) return;
    // 0049b02a  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0049b02d  43                     -inc ebx
    (cpu.ebx)++;
    // 0049b02e  f6c230                 +test dl, 0x30
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 48 /*0x30*/));
    // 0049b031  750d                   -jne 0x49b040
    if (!cpu.flags.zf)
    {
        goto L_0x0049b040;
    }
    // 0049b033  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b037  40                     -inc eax
    (cpu.eax)++;
    // 0049b038  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049b03c  39c7                   +cmp edi, eax
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
    // 0049b03e  75df                   -jne 0x49b01f
    if (!cpu.flags.zf)
    {
        goto L_0x0049b01f;
    }
L_0x0049b040:
    // 0049b040  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0049b043  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0049b046  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b048  7418                   -je 0x49b062
    if (cpu.flags.zf)
    {
        goto L_0x0049b062;
    }
    // 0049b04a  8a750d                 -mov dh, byte ptr [ebp + 0xd]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 0049b04d  80e6fa                 -and dh, 0xfa
    cpu.dh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 0049b050  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 0049b052  88750d                 -mov byte ptr [ebp + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.dh;
    // 0049b055  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0049b058  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049b05a  885d0d                 -mov byte ptr [ebp + 0xd], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 0049b05d  e8edbd0000             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
L_0x0049b062:
    // 0049b062  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 0049b066  7406                   -je 0x49b06e
    if (cpu.flags.zf)
    {
        goto L_0x0049b06e;
    }
    // 0049b068  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b06a  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x0049b06e:
    // 0049b06e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b072  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b075  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0049b078  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b07a  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b07c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049b07f  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049b082  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b088  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b08c  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x0049b08e:
    // 0049b08e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049b091  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b092  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b093  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b094  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49b096(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b096  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0049b098  f60564df4d0001         +test byte ptr [0x4ddf64], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5103460) /* 0x4ddf64 */) & 1 /*0x1*/));
    // 0049b09f  7504                   -jne 0x49b0a5
    if (!cpu.flags.zf)
    {
        goto L_0x0049b0a5;
    }
    // 0049b0a1  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0049b0a3  eb05                   -jmp 0x49b0aa
    goto L_0x0049b0aa;
L_0x0049b0a5:
    // 0049b0a5  e8da3c0100             -call 0x4aed84
    cpu.esp -= 4;
    sub_4aed84(app, cpu);
    if (cpu.terminate) return;
L_0x0049b0aa:
    // 0049b0aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b0ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b0ab  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049b0ad  f60564df4d0001         +test byte ptr [0x4ddf64], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5103460) /* 0x4ddf64 */) & 1 /*0x1*/));
    // 0049b0b4  7504                   -jne 0x49b0ba
    if (!cpu.flags.zf)
    {
        goto L_0x0049b0ba;
    }
    // 0049b0b6  d9f3                   +fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0049b0b8  eb05                   -jmp 0x49b0bf
    goto L_0x0049b0bf;
L_0x0049b0ba:
    // 0049b0ba  e8c53c0100             -call 0x4aed84
    cpu.esp -= 4;
    sub_4aed84(app, cpu);
    if (cpu.terminate) return;
L_0x0049b0bf:
    // 0049b0bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b0c0  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049b0c4  e8cdffffff             -call 0x49b096
    cpu.esp -= 4;
    sub_49b096(app, cpu);
    if (cpu.terminate) return;
    // 0049b0c9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_49b0cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b0cc  dd44240c               -fld qword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0049b0d0  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049b0d4  e8d2ffffff             -call 0x49b0ab
    cpu.esp -= 4;
    sub_49b0ab(app, cpu);
    if (cpu.terminate) return;
    // 0049b0d9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_49b0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b0e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b0e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b0e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b0e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b0e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b0e6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049b0e8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b0ea  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b0ec  39d0                   +cmp eax, edx
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
    // 0049b0ee  7540                   -jne 0x49b130
    if (!cpu.flags.zf)
    {
        goto L_0x0049b130;
    }
    // 0049b0f0  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b0f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b0f4  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b0f8  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049b0fc  39d0                   +cmp eax, edx
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
    // 0049b0fe  7530                   -jne 0x49b130
    if (!cpu.flags.zf)
    {
        goto L_0x0049b130;
    }
    // 0049b100  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b102  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b104  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049b108  668b5706               -mov dx, word ptr [edi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0049b10c  39d0                   +cmp eax, edx
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
    // 0049b10e  7520                   -jne 0x49b130
    if (!cpu.flags.zf)
    {
        goto L_0x0049b130;
    }
    // 0049b110  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049b112  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b115  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b117  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049b11a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049b11c  38fb                   +cmp bl, bh
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
    // 0049b11e  7510                   -jne 0x49b130
    if (!cpu.flags.zf)
    {
        goto L_0x0049b130;
    }
L_0x0049b120:
    // 0049b120  42                     -inc edx
    (cpu.edx)++;
    // 0049b121  40                     -inc eax
    (cpu.eax)++;
    // 0049b122  41                     -inc ecx
    (cpu.ecx)++;
    // 0049b123  83f808                 +cmp eax, 8
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
    // 0049b126  7d0f                   -jge 0x49b137
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b137;
    }
    // 0049b128  8a5908                 -mov bl, byte ptr [ecx + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049b12b  3a5a08                 +cmp bl, byte ptr [edx + 8]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049b12e  74f0                   -je 0x49b120
    if (cpu.flags.zf)
    {
        goto L_0x0049b120;
    }
L_0x0049b130:
    // 0049b130  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b132  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b133  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b134  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b135  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b136  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b137:
    // 0049b137  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b13c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b13d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b13e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b13f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b140  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b144(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b144  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b145  833d48b34d0000         +cmp dword ptr [0x4db348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092168) /* 0x4db348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b14c  742b                   -je 0x49b179
    if (cpu.flags.zf)
    {
        goto L_0x0049b179;
    }
L_0x0049b14e:
    // 0049b14e  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b153  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b155  e8dae0feff             -call 0x489234
    cpu.esp -= 4;
    sub_489234(app, cpu);
    if (cpu.terminate) return;
    // 0049b15a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b15c  7407                   -je 0x49b165
    if (cpu.flags.zf)
    {
        goto L_0x0049b165;
    }
    // 0049b15e  e8e9010000             -call 0x49b34c
    cpu.esp -= 4;
    sub_49b34c(app, cpu);
    if (cpu.terminate) return;
    // 0049b163  ebe9                   -jmp 0x49b14e
    goto L_0x0049b14e;
L_0x0049b165:
    // 0049b165  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b166  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b16b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b16d  e8baddfeff             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 0049b172  890d48b34d00           -mov dword ptr [0x4db348], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092168) /* 0x4db348 */) = cpu.ecx;
    // 0049b178  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049b179:
    // 0049b179  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b17a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b17c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b17c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b17d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b17e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b17f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b182  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049b186  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049b189  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049b18d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049b18f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b194  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b196  8b0d44b34d00           -mov ecx, dword ptr [0x4db344]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5092164) /* 0x4db344 */);
    // 0049b19c  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049b1a0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b1a2  7e43                   -jle 0x49b1e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b1e7;
    }
    // 0049b1a4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049b1a6:
    // 0049b1a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b1a8  743d                   -je 0x49b1e7
    if (cpu.flags.zf)
    {
        goto L_0x0049b1e7;
    }
    // 0049b1aa  8b9620ea5600           -mov edx, dword ptr [esi + 0x56ea20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5696032) /* 0x56ea20 */);
    // 0049b1b0  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b1b3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b1b5  7537                   -jne 0x49b1ee
    if (!cpu.flags.zf)
    {
        goto L_0x0049b1ee;
    }
    // 0049b1b7  83ff20                 +cmp edi, 0x20
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
    // 0049b1ba  7715                   -ja 0x49b1d1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049b1d1;
    }
    // 0049b1bc  8b8640ea5600           -mov eax, dword ptr [esi + 0x56ea40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5696064) /* 0x56ea40 */);
    // 0049b1c2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b1c5  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 0049b1ca  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0049b1cd  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049b1d1:
    // 0049b1d1  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b1d5  8b2d44b34d00           -mov ebp, dword ptr [0x4db344]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5092164) /* 0x4db344 */);
    // 0049b1db  43                     -inc ebx
    (cpu.ebx)++;
    // 0049b1dc  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b1df  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049b1e3  39eb                   +cmp ebx, ebp
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
    // 0049b1e5  7cbf                   -jl 0x49b1a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b1a6;
    }
L_0x0049b1e7:
    // 0049b1e7  83c410                 +add esp, 0x10
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
    // 0049b1ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b1eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b1ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b1ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b1ee:
    // 0049b1ee  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b1f2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b1f6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049b1f8  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049b1fa  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b1fd  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b200  ebcf                   -jmp 0x49b1d1
    goto L_0x0049b1d1;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b204(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b204  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b205  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b206  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b207  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b20a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b20c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049b210  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049b213  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049b217  8b1548b34d00           -mov edx, dword ptr [0x4db348]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092168) /* 0x4db348 */);
    // 0049b21d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b21f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b221  0f84a4000000           -je 0x49b2cb
    if (cpu.flags.zf)
    {
        goto L_0x0049b2cb;
    }
L_0x0049b227:
    // 0049b227  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b22c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049b22e  e8dddefeff             -call 0x489110
    cpu.esp -= 4;
    sub_489110(app, cpu);
    if (cpu.terminate) return;
    // 0049b233  83f8ff                 +cmp eax, -1
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
    // 0049b236  7407                   -je 0x49b23f
    if (cpu.flags.zf)
    {
        goto L_0x0049b23f;
    }
    // 0049b238  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b23a  e80d010000             -call 0x49b34c
    cpu.esp -= 4;
    sub_49b34c(app, cpu);
    if (cpu.terminate) return;
L_0x0049b23f:
    // 0049b23f  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 0049b244  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b246  e841d2feff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0049b24b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b24d  a144b34d00             -mov eax, dword ptr [0x4db344]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092164) /* 0x4db344 */);
    // 0049b252  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0049b256  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b258  7e62                   -jle 0x49b2bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b2bc;
    }
    // 0049b25a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049b25c:
    // 0049b25c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b25e  755c                   -jne 0x49b2bc
    if (!cpu.flags.zf)
    {
        goto L_0x0049b2bc;
    }
    // 0049b260  8b8740ea5600           -mov eax, dword ptr [edi + 0x56ea40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5696064) /* 0x56ea40 */);
    // 0049b266  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049b269  8b8720ea5600           -mov eax, dword ptr [edi + 0x56ea20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5696032) /* 0x56ea20 */);
    // 0049b26f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049b272  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b276  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049b279  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b27c  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0049b280  0f848d000000           -je 0x49b313
    if (cpu.flags.zf)
    {
        goto L_0x0049b313;
    }
L_0x0049b286:
    // 0049b286  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049b28a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049b28e  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049b292  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b293  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b297  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b29a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b29b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b29d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b2a1  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b2a4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0049b2a6:
    // 0049b2a6  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b2aa  8b1d44b34d00           -mov ebx, dword ptr [0x4db344]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092164) /* 0x4db344 */);
    // 0049b2b0  42                     -inc edx
    (cpu.edx)++;
    // 0049b2b1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b2b4  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049b2b8  39da                   +cmp edx, ebx
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
    // 0049b2ba  7ca0                   -jl 0x49b25c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b25c;
    }
L_0x0049b2bc:
    // 0049b2bc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b2be  7572                   -jne 0x49b332
    if (!cpu.flags.zf)
    {
        goto L_0x0049b332;
    }
    // 0049b2c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b2c2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b2c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b2c8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049b2cb:
    // 0049b2cb  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b2d0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b2d2  e815dcfeff             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 0049b2d7  b844b14900             -mov eax, 0x49b144
    cpu.eax = 4829508 /*0x49b144*/;
    // 0049b2dc  e8ffa9ffff             -call 0x495ce0
    cpu.esp -= 4;
    sub_495ce0(app, cpu);
    if (cpu.terminate) return;
    // 0049b2e1  833d3cb34d0000         +cmp dword ptr [0x4db33c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092156) /* 0x4db33c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b2e8  751a                   -jne 0x49b304
    if (!cpu.flags.zf)
    {
        goto L_0x0049b304;
    }
    // 0049b2ea  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0049b2f0  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0049b2f3  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0049b2f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b2fa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049b2fd  f7ff                   +idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049b2ff  a33cb34d00             -mov dword ptr [0x4db33c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092156) /* 0x4db33c */) = cpu.eax;
L_0x0049b304:
    // 0049b304  c70548b34d0001000000   -mov dword ptr [0x4db348], 1
    app->getMemory<x86::reg32>(x86::reg32(5092168) /* 0x4db348 */) = 1 /*0x1*/;
    // 0049b30e  e914ffffff             -jmp 0x49b227
    goto L_0x0049b227;
L_0x0049b313:
    // 0049b313  8b8740ea5600           -mov eax, dword ptr [edi + 0x56ea40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5696064) /* 0x56ea40 */);
    // 0049b319  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b31d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b320  e8bbfdffff             -call 0x49b0e0
    cpu.esp -= 4;
    sub_49b0e0(app, cpu);
    if (cpu.terminate) return;
    // 0049b325  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b327  0f8559ffffff           -jne 0x49b286
    if (!cpu.flags.zf)
    {
        goto L_0x0049b286;
    }
    // 0049b32d  e974ffffff             -jmp 0x49b2a6
    goto L_0x0049b2a6;
L_0x0049b332:
    // 0049b332  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b337  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049b339  e802dcfeff             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 0049b33e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b340  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b343  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b344  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b345  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b346  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b34c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b34c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b34d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b34e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b34f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b351  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b353  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b358  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b35a  e8b1ddfeff             -call 0x489110
    cpu.esp -= 4;
    sub_489110(app, cpu);
    if (cpu.terminate) return;
    // 0049b35f  83f8ff                 +cmp eax, -1
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
    // 0049b362  7506                   -jne 0x49b36a
    if (!cpu.flags.zf)
    {
        goto L_0x0049b36a;
    }
    // 0049b364  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b366  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b367  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b368  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b369  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b36a:
    // 0049b36a  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b36d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b36f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049b371  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b374  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049b376  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b37b  e858ddfeff             -call 0x4890d8
    cpu.esp -= 4;
    sub_4890d8(app, cpu);
    if (cpu.terminate) return;
    // 0049b380  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b382  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b384  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b385  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b388  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b389  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b38c  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b38f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b390  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b394(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b394  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b395  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b398  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b39b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b39c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b3a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b3a1  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b3a4  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b3a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b3ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b3ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b3ad  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b3b0  ff561c                 -call dword ptr [esi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b3b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b3b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b3b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b3b9  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b3bc  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b3bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b3c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b3c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b3c5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b3c8  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b3cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b3d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b3d1  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b3d4  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b3d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b3dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b3dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b3dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b3de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b3e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b3e2  b860ea5600             -mov eax, 0x56ea60
    cpu.eax = 5696096 /*0x56ea60*/;
    // 0049b3e7  e824ddfeff             -call 0x489110
    cpu.esp -= 4;
    sub_489110(app, cpu);
    if (cpu.terminate) return;
    // 0049b3ec  83f8ff                 +cmp eax, -1
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
    // 0049b3ef  7508                   -jne 0x49b3f9
    if (!cpu.flags.zf)
    {
        goto L_0x0049b3f9;
    }
    // 0049b3f1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b3f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b3f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b3f9:
    // 0049b3f9  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b3fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b3fe  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b401  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b402  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b403  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b404  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b405  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b408  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b40b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b40c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b411  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b414  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b417  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b418  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b41c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b41c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b41d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b41e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049b420  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b422  740a                   -je 0x49b42e
    if (cpu.flags.zf)
    {
        goto L_0x0049b42e;
    }
    // 0049b424  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0049b42b  894848                 -mov dword ptr [eax + 0x48], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.ecx;
L_0x0049b42e:
    // 0049b42e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049b430  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b433  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049b435  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b437  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b439  ff5738                 -call dword ptr [edi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b43c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b43d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b43e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b441  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b444  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049b447  ff513c                 -call dword ptr [ecx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b44a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b44b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b44c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b44c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b44d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b450  837e3800               +cmp dword ptr [esi + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b454  7504                   -jne 0x49b45a
    if (!cpu.flags.zf)
    {
        goto L_0x0049b45a;
    }
    // 0049b456  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b458  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b459  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b45a:
    // 0049b45a  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049b45d  ff5638                 -call dword ptr [esi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b460  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b461  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b464(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b464  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b465  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049b468  837a2400               +cmp dword ptr [edx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b46c  7504                   -jne 0x49b472
    if (!cpu.flags.zf)
    {
        goto L_0x0049b472;
    }
    // 0049b46e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b470  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b471  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b472:
    // 0049b472  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049b475  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b478  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b479  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b482  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b483  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b485  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049b487  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049b48c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b48f  e86ce6feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049b494  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0049b499  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b49c  8d4606                 -lea eax, [esi + 6]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049b49f  e85ce6feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049b4a4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049b4a9  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 0049b4ac  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049b4af  e84ce6feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049b4b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b4b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b4b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b4b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b4ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b4bb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b4bd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049b4bf  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049b4c4  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b4c7  e834e6feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049b4cc  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0049b4d1  8d5106                 -lea edx, [ecx + 6]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0049b4d4  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049b4d7  e824e6feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049b4dc  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049b4e1  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049b4e4  8d460a                 -lea eax, [esi + 0xa]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0049b4e7  e814e6feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049b4ec  66c7010600             -mov word ptr [ecx], 6
    app->getMemory<x86::reg16>(cpu.ecx) = 6 /*0x6*/;
    // 0049b4f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b4f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b4f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b4f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b4f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b4fa  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b4fd  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049b500  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049b502  8d4202                 -lea eax, [edx + 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049b505  66c7020600             -mov word ptr [edx], 6
    app->getMemory<x86::reg16>(cpu.edx) = 6 /*0x6*/;
    // 0049b50a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b50c  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049b511  e880cffeff             -call 0x488496
    cpu.esp -= 4;
    sub_488496(app, cpu);
    if (cpu.terminate) return;
    // 0049b516  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0049b51b  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0049b520  8d4106                 -lea eax, [ecx + 6]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0049b523  e86ecffeff             -call 0x488496
    cpu.esp -= 4;
    sub_488496(app, cpu);
    if (cpu.terminate) return;
    // 0049b528  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049b52d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049b52f  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049b532  e8c9e5feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049b537  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b53a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b53b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b53c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b541  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b542  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b543  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b544  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b545  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049b548  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049b54a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049b54c  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 0049b551  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0049b556  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049b55a  e859cefeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049b55f  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b563  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b564  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b568  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b569  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049b56b  681c010000             -push 0x11c
    app->getMemory<x86::reg32>(cpu.esp-4) = 284 /*0x11c*/;
    cpu.esp -= 4;
    // 0049b570  8d5e24                 -lea ebx, [esi + 0x24]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049b573  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b574  8b4f34                 -mov ecx, dword ptr [edi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b577  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b578  e8617d0200             -call 0x4c32de
    cpu.esp -= 4;
    sub_4c32de(app, cpu);
    if (cpu.terminate) return;
    // 0049b57d  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049b580  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0049b585  e846cefeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049b58a  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049b58d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049b58f  7e47                   -jle 0x49b5d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b5d8;
    }
    // 0049b591  807f0200               +cmp byte ptr [edi + 2], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049b595  754c                   -jne 0x49b5e3
    if (!cpu.flags.zf)
    {
        goto L_0x0049b5e3;
    }
L_0x0049b597:
    // 0049b597  a1c0155600             -mov eax, dword ptr [0x5615c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 0049b59c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049b5a1  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049b5a4  8d4624                 -lea eax, [esi + 0x24]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049b5a7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b5a9  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049b5ab  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049b5ad  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049b5b4  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049b5b6  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049b5b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b5bb  740d                   -je 0x49b5ca
    if (cpu.flags.zf)
    {
        goto L_0x0049b5ca;
    }
    // 0049b5bd  837e0804               +cmp dword ptr [esi + 8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b5c1  7c07                   -jl 0x49b5ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b5ca;
    }
    // 0049b5c3  837c24100e             +cmp dword ptr [esp + 0x10], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b5c8  742a                   -je 0x49b5f4
    if (cpu.flags.zf)
    {
        goto L_0x0049b5f4;
    }
L_0x0049b5ca:
    // 0049b5ca  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0049b5d1  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0049b5d8:
    // 0049b5d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b5da  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049b5dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b5e3:
    // 0049b5e3  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049b5e5  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049b5e7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b5e9  e88a380100             -call 0x4aee78
    cpu.esp -= 4;
    sub_4aee78(app, cpu);
    if (cpu.terminate) return;
    // 0049b5ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b5f0  74a5                   -je 0x49b597
    if (cpu.flags.zf)
    {
        goto L_0x0049b597;
    }
    // 0049b5f2  ebe4                   -jmp 0x49b5d8
    goto L_0x0049b5d8;
L_0x0049b5f4:
    // 0049b5f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049b5f6  8d560c                 -lea edx, [esi + 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049b5f9  e882feffff             -call 0x49b480
    cpu.esp -= 4;
    sub_49b480(app, cpu);
    if (cpu.terminate) return;
    // 0049b5fe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b603  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049b606  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b608  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b609  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b60a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b60b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b60c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b60c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b60d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b60e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b611  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049b613  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049b616  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049b618  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049b61b  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 0049b620  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b622  e850c1ffff             -call 0x497777
    cpu.esp -= 4;
    sub_497777(app, cpu);
    if (cpu.terminate) return;
    // 0049b627  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b629  7406                   -je 0x49b631
    if (cpu.flags.zf)
    {
        goto L_0x0049b631;
    }
    // 0049b62b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b62e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b62f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b630  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b631:
    // 0049b631  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b632  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b633  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049b635  bb767273ea             -mov ebx, 0xea737276
    cpu.ebx = 3933434486 /*0xea737276*/;
    // 0049b63a  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b63c  49                     -dec ecx
    (cpu.ecx)--;
    // 0049b63d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049b63f  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049b641  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049b643  49                     -dec ecx
    (cpu.ecx)--;
    // 0049b644  41                     -inc ecx
    (cpu.ecx)++;
    // 0049b645  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b649  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b64a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049b64c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049b64e  e8bd030000             -call 0x49ba10
    cpu.esp -= 4;
    sub_49ba10(app, cpu);
    if (cpu.terminate) return;
    // 0049b653  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b654  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b655  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b658  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b65a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b65c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b65c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b65d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b65e  8b0dc0155600           -mov ecx, dword ptr [0x5615c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 0049b664  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049b667  3b4804                 +cmp ecx, dword ptr [eax + 4]
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
    // 0049b66a  7c07                   -jl 0x49b673
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b673;
    }
    // 0049b66c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b66e  3b4820                 +cmp ecx, dword ptr [eax + 0x20]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b671  7408                   -je 0x49b67b
    if (cpu.flags.zf)
    {
        goto L_0x0049b67b;
    }
L_0x0049b673:
    // 0049b673  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b678  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b679  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b67a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b67b:
    // 0049b67b  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049b67e  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b681  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049b684  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b686  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b688  e8ff020000             -call 0x49b98c
    cpu.esp -= 4;
    sub_49b98c(app, cpu);
    if (cpu.terminate) return;
    // 0049b68d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b68f  75e2                   -jne 0x49b673
    if (!cpu.flags.zf)
    {
        goto L_0x0049b673;
    }
    // 0049b691  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b692  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b693  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b694(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b694  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b695  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b696  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b697  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b698  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049b69b  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b69d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b69f  39d9                   +cmp ecx, ebx
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
    // 0049b6a1  750e                   -jne 0x49b6b1
    if (!cpu.flags.zf)
    {
        goto L_0x0049b6b1;
    }
    // 0049b6a3  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049b6a6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049b6a8  7511                   -jne 0x49b6bb
    if (!cpu.flags.zf)
    {
        goto L_0x0049b6bb;
    }
L_0x0049b6aa:
    // 0049b6aa  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x0049b6b1:
    // 0049b6b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b6b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b6bb:
    // 0049b6bb  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b6be  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049b6c1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b6c3  e8c4020000             -call 0x49b98c
    cpu.esp -= 4;
    sub_49b98c(app, cpu);
    if (cpu.terminate) return;
    // 0049b6c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b6ca  75de                   -jne 0x49b6aa
    if (!cpu.flags.zf)
    {
        goto L_0x0049b6aa;
    }
    // 0049b6cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b6d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b6d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b6d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b6d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b6d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b6da  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0049b6e0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049b6e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b6e3  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 0049b6e8  e8eb7b0200             -call 0x4c32d8
    cpu.esp -= 4;
    sub_4c32d8(app, cpu);
    if (cpu.terminate) return;
    // 0049b6ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b6ef  751f                   -jne 0x49b710
    if (!cpu.flags.zf)
    {
        goto L_0x0049b710;
    }
    // 0049b6f1  8b942488010000         -mov edx, dword ptr [esp + 0x188]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 0049b6f8  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0049b6fb  740c                   -je 0x49b709
    if (cpu.flags.zf)
    {
        goto L_0x0049b709;
    }
    // 0049b6fd  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
L_0x0049b700:
    // 0049b700  81c490010000           +add esp, 0x190
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(400 /*0x190*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049b706  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b707  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b708  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b709:
    // 0049b709  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0049b70e  ebf0                   -jmp 0x49b700
    goto L_0x0049b700;
L_0x0049b710:
    // 0049b710  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b712  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0049b718  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b719  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b71a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b71c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b71c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b71d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b71e  e8af7b0200             -call 0x4c32d2
    cpu.esp -= 4;
    sub_4c32d2(app, cpu);
    if (cpu.terminate) return;
    // 0049b723  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b725  7508                   -jne 0x49b72f
    if (!cpu.flags.zf)
    {
        goto L_0x0049b72f;
    }
    // 0049b727  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b72c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b72d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b72e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b72f:
    // 0049b72f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b731  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b732  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b733  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b734(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b734  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b735  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b736  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b737  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b738  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b739  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049b73c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049b740  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0049b745  ba84400100             -mov edx, 0x14084
    cpu.edx = 82052 /*0x14084*/;
    // 0049b74a  b860ef4c00             -mov eax, 0x4cef60
    cpu.eax = 5042016 /*0x4cef60*/;
    // 0049b74f  e8b471feff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0049b754  ba84400100             -mov edx, 0x14084
    cpu.edx = 82052 /*0x14084*/;
    // 0049b759  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b75b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049b75d  e82acdfeff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0049b762  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b764  8d714c                 -lea esi, [ecx + 0x4c]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0049b767  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b769  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b76b  e87cd7feff             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 0049b770  8d4168                 -lea eax, [ecx + 0x68]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0049b773  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049b775  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b777  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b779  e86ed7feff             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 0049b77e  8d8184000000           -lea eax, [ecx + 0x84]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0049b784  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049b786  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b788  8db000400100           -lea esi, [eax + 0x14000]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(81920) /* 0x14000 */);
L_0x0049b78e:
    // 0049b78e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049b790  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b792  81c140010000           -add ecx, 0x140
    (cpu.ecx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0049b798  e8a3d7feff             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 0049b79d  39f1                   +cmp ecx, esi
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
    // 0049b79f  75ed                   -jne 0x49b78e
    if (!cpu.flags.zf)
    {
        goto L_0x0049b78e;
    }
    // 0049b7a1  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 0049b7a6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049b7a8  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0049b7aa  e81d7b0200             -call 0x4c32cc
    cpu.esp -= 4;
    sub_4c32cc(app, cpu);
    if (cpu.terminate) return;
    // 0049b7af  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0049b7b2  83f8ff                 +cmp eax, -1
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
    // 0049b7b5  7526                   -jne 0x49b7dd
    if (!cpu.flags.zf)
    {
        goto L_0x0049b7dd;
    }
L_0x0049b7b7:
    // 0049b7b7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049b7b9  7517                   -jne 0x49b7d2
    if (!cpu.flags.zf)
    {
        goto L_0x0049b7d2;
    }
    // 0049b7bb  8b5734                 -mov edx, dword ptr [edi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b7be  83faff                 +cmp edx, -1
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
    // 0049b7c1  7406                   -je 0x49b7c9
    if (cpu.flags.zf)
    {
        goto L_0x0049b7c9;
    }
    // 0049b7c3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b7c4  e8fd7a0200             -call 0x4c32c6
    cpu.esp -= 4;
    sub_4c32c6(app, cpu);
    if (cpu.terminate) return;
L_0x0049b7c9:
    // 0049b7c9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b7cb  e89c75feff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0049b7d0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049b7d2:
    // 0049b7d2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b7d4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049b7d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b7dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b7dd:
    // 0049b7dd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049b7df  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b7e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b7e4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049b7e9  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0049b7eb  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049b7ef  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0049b7f4  8b5f34                 -mov ebx, dword ptr [edi + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b7f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b7f8  e8c37a0200             -call 0x4c32c0
    cpu.esp -= 4;
    sub_4c32c0(app, cpu);
    if (cpu.terminate) return;
    // 0049b7fd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049b7ff  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b803  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b804  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b806  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 0049b80b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0049b80f  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0049b814  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b817  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b818  e8a37a0200             -call 0x4c32c0
    cpu.esp -= 4;
    sub_4c32c0(app, cpu);
    if (cpu.terminate) return;
    // 0049b81d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049b81f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b823  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b824  6801400000             -push 0x4001
    app->getMemory<x86::reg32>(cpu.esp-4) = 16385 /*0x4001*/;
    cpu.esp -= 4;
    // 0049b829  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0049b82d  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0049b832  8b4f34                 -mov ecx, dword ptr [edi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b835  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b836  e8857a0200             -call 0x4c32c0
    cpu.esp -= 4;
    sub_4c32c0(app, cpu);
    if (cpu.terminate) return;
    // 0049b83b  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049b83d  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b841  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b842  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 0049b847  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0049b84b  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0049b850  8b7734                 -mov esi, dword ptr [edi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b854  e8677a0200             -call 0x4c32c0
    cpu.esp -= 4;
    sub_4c32c0(app, cpu);
    if (cpu.terminate) return;
    // 0049b859  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0049b861  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b865  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b866  687e660480             -push 0x8004667e
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147772030 /*0x8004667e*/;
    cpu.esp -= 4;
    // 0049b86b  8b5734                 -mov edx, dword ptr [edi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b86e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b86f  e8467a0200             -call 0x4c32ba
    cpu.esp -= 4;
    sub_4c32ba(app, cpu);
    if (cpu.terminate) return;
    // 0049b874  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 0049b879  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049b87b  e80cccfeff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0049b880  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b882  668b442418             -mov ax, word ptr [esp + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b887  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0049b88c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b88d  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0049b892  e81d7a0200             -call 0x4c32b4
    cpu.esp -= 4;
    sub_4c32b4(app, cpu);
    if (cpu.terminate) return;
    // 0049b897  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0049b899  6689442410             -mov word ptr [esp + 0x10], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 0049b89e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b8a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b8a3  8b4f34                 -mov ecx, dword ptr [edi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b8a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b8a7  e8027a0200             -call 0x4c32ae
    cpu.esp -= 4;
    sub_4c32ae(app, cpu);
    if (cpu.terminate) return;
    // 0049b8ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b8ae  0f8503ffffff           -jne 0x49b7b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049b7b7;
    }
    // 0049b8b4  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049b8b8  bb0e000000             -mov ebx, 0xe
    cpu.ebx = 14 /*0xe*/;
    // 0049b8bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b8be  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b8c2  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049b8c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b8c7  8b7734                 -mov esi, dword ptr [edi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049b8ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b8cb  e8d8790200             -call 0x4c32a8
    cpu.esp -= 4;
    sub_4c32a8(app, cpu);
    if (cpu.terminate) return;
    // 0049b8d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b8d2  0f85dffeffff           -jne 0x49b7b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049b7b7;
    }
    // 0049b8d8  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b8dc  0f85d5feffff           -jne 0x49b7b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049b7b7;
    }
    // 0049b8e2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049b8e4  8d5738                 -lea edx, [edi + 0x38]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 0049b8e7  e894fbffff             -call 0x49b480
    cpu.esp -= 4;
    sub_49b480(app, cpu);
    if (cpu.terminate) return;
    // 0049b8ec  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b8f0  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049b8f3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b8f5  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049b8f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b903  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049b905  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049b908  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b909  e8b8790200             -call 0x4c32c6
    cpu.esp -= 4;
    sub_4c32c6(app, cpu);
    if (cpu.terminate) return;
    // 0049b90e  8d434c                 -lea eax, [ebx + 0x4c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 0049b911  e816d6feff             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 0049b916  8d4368                 -lea eax, [ebx + 0x68]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(104) /* 0x68 */);
    // 0049b919  e80ed6feff             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 0049b91e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b920  e84774feff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0049b925  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b92a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b92b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b92c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b92d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b931  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049b936  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b938  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049b93a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0049b93c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049b943  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049b945  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b946  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49b948(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b948  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b949  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b94a  8d4838                 -lea ecx, [eax + 0x38]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0049b94d  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049b94f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049b951  e8ca380100             -call 0x4af220
    cpu.esp -= 4;
    sub_4af220(app, cpu);
    if (cpu.terminate) return;
    // 0049b956  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b957  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b958  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b95c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b95c  e9b3390100             -jmp 0x4af314
    return sub_4af314(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b964(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b964  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b965  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b966  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b968  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 0049b96d  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049b970  e8d78ffeff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 0049b975  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0049b978  e843340100             -call 0x4aedc0
    cpu.esp -= 4;
    sub_4aedc0(app, cpu);
    if (cpu.terminate) return;
    // 0049b97d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b97e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b97f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b980  c6400200               -mov byte ptr [eax + 2], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0049b984  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b989  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49b98c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b98c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b98d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b98e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b98f  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049b994  8d7b04                 -lea edi, [ebx + 4]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049b997  8d7204                 -lea esi, [edx + 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b99a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049b99c  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 0049b99e  7405                   -je 0x49b9a5
    if (cpu.flags.zf)
    {
        goto L_0x0049b9a5;
    }
    // 0049b9a0  19c0                   +sbb eax, eax
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
    // 0049b9a2  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0049b9a5:
    // 0049b9a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b9a7  7509                   -jne 0x49b9b2
    if (!cpu.flags.zf)
    {
        goto L_0x0049b9b2;
    }
    // 0049b9a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b9ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b9b2:
    // 0049b9b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b9b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b9b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b9b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b9b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b9ba  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049b9bc  8d7038                 -lea esi, [eax + 0x38]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0049b9bf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b9c4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049b9c5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049b9c6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049b9c7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049b9c8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049b9c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b9cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b9cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b9cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b9ce  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b9d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049b9d3  83c068                 -add eax, 0x68
    (cpu.eax) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0049b9d6  e831d7feff             -call 0x48910c
    cpu.esp -= 4;
    sub_48910c(app, cpu);
    if (cpu.terminate) return;
    // 0049b9db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b9dd  760b                   -jbe 0x49b9ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049b9ea;
    }
L_0x0049b9df:
    // 0049b9df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049b9e4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b9e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b9ea:
    // 0049b9ea  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049b9ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b9ed  687f660440             -push 0x4004667f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1074030207 /*0x4004667f*/;
    cpu.esp -= 4;
    // 0049b9f2  8b4a34                 -mov ecx, dword ptr [edx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 0049b9f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b9f6  e8bf780200             -call 0x4c32ba
    cpu.esp -= 4;
    sub_4c32ba(app, cpu);
    if (cpu.terminate) return;
    // 0049b9fb  83f8ff                 +cmp eax, -1
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
    // 0049b9fe  7406                   -je 0x49ba06
    if (cpu.flags.zf)
    {
        goto L_0x0049ba06;
    }
    // 0049ba00  833c2400               +cmp dword ptr [esp], 0
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
    // 0049ba04  77d9                   -ja 0x49b9df
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049b9df;
    }
L_0x0049ba06:
    // 0049ba06  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba08  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ba0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ba0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49ba10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ba10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ba11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ba12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ba13  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0049ba19  8bac243c010000         -mov ebp, dword ptr [esp + 0x13c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 0049ba20  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049ba22  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049ba24  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049ba26  81fd18010000           +cmp ebp, 0x118
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(280 /*0x118*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ba2c  7e05                   -jle 0x49ba33
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ba33;
    }
    // 0049ba2e  bd18010000             -mov ebp, 0x118
    cpu.ebp = 280 /*0x118*/;
L_0x0049ba33:
    // 0049ba33  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0049ba38  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049ba3a  e8e16a0000             -call 0x4a2520
    cpu.esp -= 4;
    sub_4a2520(app, cpu);
    if (cpu.terminate) return;
    // 0049ba3f  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ba43  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049ba45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ba47  e8b4e0feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049ba4c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ba4e  7457                   -je 0x49baa7
    if (cpu.flags.zf)
    {
        goto L_0x0049baa7;
    }
    // 0049ba50  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0049ba57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ba59  e85afaffff             -call 0x49b4b8
    cpu.esp -= 4;
    sub_49b4b8(app, cpu);
    if (cpu.terminate) return;
L_0x0049ba5e:
    // 0049ba5e  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0049ba63  e850c9feff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049ba68  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0049ba6a  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0049ba71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ba72  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049ba74  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ba77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ba78  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ba7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ba7d  8b5734                 -mov edx, dword ptr [edi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0049ba80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ba81  e81c780200             -call 0x4c32a2
    cpu.esp -= 4;
    sub_4c32a2(app, cpu);
    if (cpu.terminate) return;
    // 0049ba86  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ba88  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0049ba8d  e83ec9feff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049ba92  39ea                   +cmp edx, ebp
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
    // 0049ba94  7522                   -jne 0x49bab8
    if (!cpu.flags.zf)
    {
        goto L_0x0049bab8;
    }
    // 0049ba96  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ba9b  81c42c010000           +add esp, 0x12c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(300 /*0x12c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049baa1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049baa2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049baa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049baa4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049baa7:
    // 0049baa7  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0049baae  0fbf07                 -movsx eax, word ptr [edi]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edi)));
    // 0049bab1  e842faffff             -call 0x49b4f8
    cpu.esp -= 4;
    sub_49b4f8(app, cpu);
    if (cpu.terminate) return;
    // 0049bab6  eba6                   -jmp 0x49ba5e
    goto L_0x0049ba5e;
L_0x0049bab8:
    // 0049bab8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049baba  81c42c010000           -add esp, 0x12c
    (cpu.esp) += x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0049bac0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bac1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bac2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bac3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49bac8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bac8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bac9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049baca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bacb  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049bace  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049bad0  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049bad4  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049bad8  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049badc  8d584c                 -lea ebx, [eax + 0x4c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0049badf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049bae1  e8d6d4feff             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 0049bae6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bae8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049baea  742a                   -je 0x49bb16
    if (cpu.flags.zf)
    {
        goto L_0x0049bb16;
    }
    // 0049baec  8d7568                 -lea esi, [ebp + 0x68]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(104) /* 0x68 */);
L_0x0049baef:
    // 0049baef  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049baf1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049baf3  e848faffff             -call 0x49b540
    cpu.esp -= 4;
    sub_49b540(app, cpu);
    if (cpu.terminate) return;
    // 0049baf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bafa  0f84b8000000           -je 0x49bbb8
    if (cpu.flags.zf)
    {
        goto L_0x0049bbb8;
    }
    // 0049bb00  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049bb02  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049bb04  e86bd4feff             -call 0x488f74
    cpu.esp -= 4;
    sub_488f74(app, cpu);
    if (cpu.terminate) return;
    // 0049bb09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049bb0b  e8acd4feff             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 0049bb10  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bb12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bb14  75d9                   -jne 0x49baef
    if (!cpu.flags.zf)
    {
        goto L_0x0049baef;
    }
L_0x0049bb16:
    // 0049bb16  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bb1a  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049bb1e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049bb20  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049bb24  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049bb27  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb28  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb29  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb2a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb2b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb2c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049bb2e  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0049bb32  8d7d68                 -lea edi, [ebp + 0x68]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(104) /* 0x68 */);
    // 0049bb35  ba5cb64900             -mov edx, 0x49b65c
    cpu.edx = 4830812 /*0x49b65c*/;
    // 0049bb3a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049bb3c  e88fd7feff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
    // 0049bb41  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bb43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bb45  0f84a8000000           -je 0x49bbf3
    if (cpu.flags.zf)
    {
        goto L_0x0049bbf3;
    }
    // 0049bb4b  8d754c                 -lea esi, [ebp + 0x4c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(76) /* 0x4c */);
L_0x0049bb4e:
    // 0049bb4e  a1c0155600             -mov eax, dword ptr [0x5615c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 0049bb53  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bb56  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bb59  0f8c73000000           -jl 0x49bbd2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bbd2;
    }
    // 0049bb5f  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049bb62  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bb65  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049bb69  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049bb6d  39d8                   +cmp eax, ebx
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
    // 0049bb6f  7e55                   -jle 0x49bbc6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bbc6;
    }
    // 0049bb71  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
L_0x0049bb75:
    // 0049bb75  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049bb79  8d710c                 -lea esi, [ecx + 0xc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049bb7c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb7d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb7e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb7f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb80  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bb81  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bb85  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049bb88  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049bb8a  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 0049bb8f  7410                   -je 0x49bba1
    if (cpu.flags.zf)
    {
        goto L_0x0049bba1;
    }
    // 0049bb91  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049bb95  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049bb99  8d4128                 -lea eax, [ecx + 0x28]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0049bb9c  e85fdffeff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
L_0x0049bba1:
    // 0049bba1  8d454c                 -lea eax, [ebp + 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 0049bba4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049bba6  e895d3feff             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 0049bbab  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049bbaf  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049bbb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bbb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bbb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bbb5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049bbb8:
    // 0049bbb8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049bbba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049bbbc  e87fd3feff             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 0049bbc1  e950ffffff             -jmp 0x49bb16
    goto L_0x0049bb16;
L_0x0049bbc6:
    // 0049bbc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bbc8  7dab                   -jge 0x49bb75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bb75;
    }
    // 0049bbca  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0049bbcc  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0049bbd0  eba3                   -jmp 0x49bb75
    goto L_0x0049bb75;
L_0x0049bbd2:
    // 0049bbd2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049bbd4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049bbd6  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049bbd8  e863d3feff             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 0049bbdd  ba5cb64900             -mov edx, 0x49b65c
    cpu.edx = 4830812 /*0x49b65c*/;
    // 0049bbe2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049bbe4  e8e7d6feff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
    // 0049bbe9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bbeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bbed  0f855bffffff           -jne 0x49bb4e
    if (!cpu.flags.zf)
    {
        goto L_0x0049bb4e;
    }
L_0x0049bbf3:
    // 0049bbf3  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bbf7  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0049bbfd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bbff  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049bc02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc05  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49bc08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bc08  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049bc0b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049bc0e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049bc10  742b                   -je 0x49bc3d
    if (cpu.flags.zf)
    {
        goto L_0x0049bc3d;
    }
    // 0049bc12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bc13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bc14  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bc18  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049bc1a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bc1b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bc1c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bc1d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bc1e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049bc1f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049bc23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049bc25:
    // 0049bc25  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049bc27  ba94b64900             -mov edx, 0x49b694
    cpu.edx = 4830868 /*0x49b694*/;
    // 0049bc2c  83c068                 -add eax, 0x68
    (cpu.eax) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0049bc2f  e888d8feff             -call 0x4894bc
    cpu.esp -= 4;
    sub_4894bc(app, cpu);
    if (cpu.terminate) return;
    // 0049bc34  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049bc39  83c41c                 +add esp, 0x1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049bc3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bc3d:
    // 0049bc3d  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049bc41  ebe2                   -jmp 0x49bc25
    goto L_0x0049bc25;
}

/* align: skip 0x90 */
void Application::sub_49bc44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bc44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049bc45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bc46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bc47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bc48  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0049bc4e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049bc50  833da8b34d0000         +cmp dword ptr [0x4db3a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092264) /* 0x4db3a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bc57  7410                   -je 0x49bc69
    if (cpu.flags.zf)
    {
        goto L_0x0049bc69;
    }
L_0x0049bc59:
    // 0049bc59  a1a8b34d00             -mov eax, dword ptr [0x4db3a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092264) /* 0x4db3a8 */);
    // 0049bc5e  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0049bc64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bc68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bc69:
    // 0049bc69  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049bc6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc6c  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 0049bc71  e862760200             -call 0x4c32d8
    cpu.esp -= 4;
    sub_4c32d8(app, cpu);
    if (cpu.terminate) return;
    // 0049bc76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bc78  75df                   -jne 0x49bc59
    if (!cpu.flags.zf)
    {
        goto L_0x0049bc59;
    }
    // 0049bc7a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bc7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bc7c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bc7e  e8b1faffff             -call 0x49b734
    cpu.esp -= 4;
    sub_49b734(app, cpu);
    if (cpu.terminate) return;
    // 0049bc83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bc85  7440                   -je 0x49bcc7
    if (cpu.flags.zf)
    {
        goto L_0x0049bcc7;
    }
    // 0049bc87  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049bc8c  be4cb34d00             -mov esi, 0x4db34c
    cpu.esi = 5092172 /*0x4db34c*/;
    // 0049bc91  890da8b34d00           -mov dword ptr [0x4db3a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092264) /* 0x4db3a8 */) = cpu.ecx;
    // 0049bc97  e864fcffff             -call 0x49b900
    cpu.esp -= 4;
    sub_49b900(app, cpu);
    if (cpu.terminate) return;
    // 0049bc9c  a144b34d00             -mov eax, dword ptr [0x4db344]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092164) /* 0x4db344 */);
    // 0049bca1  bf74df4d00             -mov edi, 0x4ddf74
    cpu.edi = 5103476 /*0x4ddf74*/;
    // 0049bca6  8d2c08                 -lea ebp, [eax + ecx]
    cpu.ebp = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 0049bca9  89348540ea5600         -mov dword ptr [eax*4 + 0x56ea40], esi
    app->getMemory<x86::reg32>(x86::reg32(5696064) /* 0x56ea40 */ + cpu.eax * 4) = cpu.esi;
    // 0049bcb0  893c8520ea5600         -mov dword ptr [eax*4 + 0x56ea20], edi
    app->getMemory<x86::reg32>(x86::reg32(5696032) /* 0x56ea20 */ + cpu.eax * 4) = cpu.edi;
    // 0049bcb7  892d44b34d00           -mov dword ptr [0x4db344], ebp
    app->getMemory<x86::reg32>(x86::reg32(5092164) /* 0x4db344 */) = cpu.ebp;
    // 0049bcbd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049bcbf  7406                   -je 0x49bcc7
    if (cpu.flags.zf)
    {
        goto L_0x0049bcc7;
    }
    // 0049bcc1  891d4cb34d00           -mov dword ptr [0x4db34c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092172) /* 0x4db34c */) = cpu.ebx;
L_0x0049bcc7:
    // 0049bcc7  e806760200             -call 0x4c32d2
    cpu.esp -= 4;
    sub_4c32d2(app, cpu);
    if (cpu.terminate) return;
    // 0049bccc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bccd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcce  a1a8b34d00             -mov eax, dword ptr [0x4db3a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092264) /* 0x4db3a8 */);
    // 0049bcd3  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0049bcd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcdb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcdc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49bce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bce0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bce1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bce2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bce3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bce4  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0049bcea  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049bcec  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0049bcf0  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049bcf2  ff05f4894d00           -inc dword ptr [0x4d89f4]
    (app->getMemory<x86::reg32>(x86::reg32(5081588) /* 0x4d89f4 */))++;
    // 0049bcf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bcfa  7505                   -jne 0x49bd01
    if (!cpu.flags.zf)
    {
        goto L_0x0049bd01;
    }
    // 0049bcfc  bdd0165600             -mov ebp, 0x5616d0
    cpu.ebp = 5641936 /*0x5616d0*/;
L_0x0049bd01:
    // 0049bd01  833d78894d0007         +cmp dword ptr [0x4d8978], 7
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
    // 0049bd08  0f8525010000           -jne 0x49be33
    if (!cpu.flags.zf)
    {
        goto L_0x0049be33;
    }
    // 0049bd0e  837d1c08               +cmp dword ptr [ebp + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bd12  0f8f1b010000           -jg 0x49be33
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049be33;
    }
    // 0049bd18  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049bd1c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049bd1e  48                     -dec eax
    (cpu.eax)--;
    // 0049bd1f  8bbd3c040000           -mov edi, dword ptr [ebp + 0x43c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1084) /* 0x43c */);
    // 0049bd25  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0049bd29  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049bd2b  0f840d010000           -je 0x49be3e
    if (cpu.flags.zf)
    {
        goto L_0x0049be3e;
    }
    // 0049bd31  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049bd36:
    // 0049bd36  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0049bd3a  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049bd3e  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0049bd41  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bd44  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bd46  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0049bd49  05a0ea5600             -add eax, 0x56eaa0
    (cpu.eax) += x86::reg32(x86::sreg32(5696160 /*0x56eaa0*/));
    // 0049bd4e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049bd50  7e2a                   -jle 0x49bd7c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bd7c;
    }
    // 0049bd52  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0049bd54:
    // 0049bd54  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd56  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049bd59  0fb67802               -movzx edi, byte ptr [eax + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */));
    // 0049bd5d  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049bd60  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd62  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049bd64  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049bd66  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bd69  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0049bd6c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bd6f  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0049bd71  41                     -inc ecx
    (cpu.ecx)++;
    // 0049bd72  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0049bd75  39f1                   +cmp ecx, esi
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
    // 0049bd77  7cdb                   -jl 0x49bd54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bd54;
    }
    // 0049bd79  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049bd7c:
    // 0049bd7c  8b852e040000           -mov eax, dword ptr [ebp + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1070) /* 0x42e */);
    // 0049bd82  8b54247c               -mov edx, dword ptr [esp + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049bd86  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049bd89  39d0                   +cmp eax, edx
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
    // 0049bd8b  7e0b                   -jle 0x49bd98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bd98;
    }
    // 0049bd8d  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049bd91  66898530040000         -mov word ptr [ebp + 0x430], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1072) /* 0x430 */) = cpu.ax;
L_0x0049bd98:
    // 0049bd98  8b8530040000           -mov eax, dword ptr [ebp + 0x430]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1072) /* 0x430 */);
    // 0049bd9e  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049bda2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049bda5  39c8                   +cmp eax, ecx
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
    // 0049bda7  7d0b                   -jge 0x49bdb4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bdb4;
    }
    // 0049bda9  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049bdad  66898532040000         -mov word ptr [ebp + 0x432], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1074) /* 0x432 */) = cpu.ax;
L_0x0049bdb4:
    // 0049bdb4  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bdb9  740c                   -je 0x49bdc7
    if (cpu.flags.zf)
    {
        goto L_0x0049bdc7;
    }
    // 0049bdbb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049bdbd  e8de3d0000             -call 0x49fba0
    cpu.esp -= 4;
    sub_49fba0(app, cpu);
    if (cpu.terminate) return;
    // 0049bdc2  e8654bfeff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
L_0x0049bdc7:
    // 0049bdc7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049bdc9  e8620cffff             -call 0x48ca30
    cpu.esp -= 4;
    sub_48ca30(app, cpu);
    if (cpu.terminate) return;
    // 0049bdce  80bd5d04000000         +cmp byte ptr [ebp + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bdd5  7555                   -jne 0x49be2c
    if (!cpu.flags.zf)
    {
        goto L_0x0049be2c;
    }
    // 0049bdd7  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049bddb  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0049bdde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bde1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bde3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bde5  05a0ea5600             -add eax, 0x56eaa0
    (cpu.eax) += x86::reg32(x86::sreg32(5696160 /*0x56eaa0*/));
    // 0049bdea  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049bdec  7e3e                   -jle 0x49be2c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049be2c;
    }
L_0x0049bdee:
    // 0049bdee  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049bdf0  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0049bdf3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049bdf5  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0049bdf8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049bdfe  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 0049be02  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0049be06  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049be09  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049be0b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0049be0e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049be14  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049be17  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 0049be1b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049be1e  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0049be22  41                     -inc ecx
    (cpu.ecx)++;
    // 0049be23  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 0049be26  39f1                   +cmp ecx, esi
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
    // 0049be28  7cc4                   -jl 0x49bdee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bdee;
    }
    // 0049be2a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049be2c:
    // 0049be2c  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049be31  7512                   -jne 0x49be45
    if (!cpu.flags.zf)
    {
        goto L_0x0049be45;
    }
L_0x0049be33:
    // 0049be33  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0049be39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049be3e:
    // 0049be3e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049be40  e9f1feffff             -jmp 0x49bd36
    goto L_0x0049bd36;
L_0x0049be45:
    // 0049be45  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049be47  e8783d0000             -call 0x49fbc4
    cpu.esp -= 4;
    sub_49fbc4(app, cpu);
    if (cpu.terminate) return;
    // 0049be4c  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0049be52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49be58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049be59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be5a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049be5c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049be5e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049be60  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 0049be67  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049be69  81c2a0ea5600           -add edx, 0x56eaa0
    (cpu.edx) += x86::reg32(x86::sreg32(5696160 /*0x56eaa0*/));
    // 0049be6f  e885680000             -call 0x4a26f9
    cpu.esp -= 4;
    sub_4a26f9(app, cpu);
    if (cpu.terminate) return;
    // 0049be74  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049be79  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049be7b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049be7d  e85efeffff             -call 0x49bce0
    cpu.esp -= 4;
    sub_49bce0(app, cpu);
    if (cpu.terminate) return;
    // 0049be82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49be88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049be89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049be8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049be8c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049be8f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049be93  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049be96  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049be99  05a0ea5600             -add eax, 0x56eaa0
    (cpu.eax) += x86::reg32(x86::sreg32(5696160 /*0x56eaa0*/));
L_0x0049be9e:
    // 0049be9e  4a                     -dec edx
    (cpu.edx)--;
    // 0049be9f  83faff                 +cmp edx, -1
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
    // 0049bea2  745d                   -je 0x49bf01
    if (cpu.flags.zf)
    {
        goto L_0x0049bf01;
    }
    // 0049bea4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bea6  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049bea8  8d2c8d00000000         -lea ebp, [ecx*4]
    cpu.ebp = x86::reg32(cpu.ecx * 4);
    // 0049beaf  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0049beb2  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049beb4  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0049beb8  0fb67301               -movzx esi, byte ptr [ebx + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */));
    // 0049bebc  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049bec0  0fb67b02               -movzx edi, byte ptr [ebx + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */));
    // 0049bec4  884802                 -mov byte ptr [eax + 2], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 0049bec7  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 0049bece  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0049bed1  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049bed3  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049bed7  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049bedb  884801                 -mov byte ptr [eax + 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0049bede  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 0049bee5  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bee6  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 0049bee9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049beec  09f9                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0049beee  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049beef  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049bef3  c640ffff               -mov byte ptr [eax - 1], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 0049bef7  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049befb  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049befc  8848fc                 -mov byte ptr [eax - 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.cl;
    // 0049beff  eb9d                   -jmp 0x49be9e
    goto L_0x0049be9e;
L_0x0049bf01:
    // 0049bf01  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049bf04  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bf08  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049bf0d  e8cefdffff             -call 0x49bce0
    cpu.esp -= 4;
    sub_49bce0(app, cpu);
    if (cpu.terminate) return;
    // 0049bf12  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049bf15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49bf1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bf1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bf1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bf1e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049bf20  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049bf22  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049bf24  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 0049bf2b  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0049bf32  81c2a0ea5600           -add edx, 0x56eaa0
    (cpu.edx) += x86::reg32(x86::sreg32(5696160 /*0x56eaa0*/));
    // 0049bf38  e8c3dbfeff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0049bf3d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049bf42  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049bf44  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049bf46  e895fdffff             -call 0x49bce0
    cpu.esp -= 4;
    sub_49bce0(app, cpu);
    if (cpu.terminate) return;
    // 0049bf4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49bf50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bf50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bf51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bf52  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049bf54  b9a0ea5600             -mov ecx, 0x56eaa0
    cpu.ecx = 5696160 /*0x56eaa0*/;
    // 0049bf59  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bf5c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bf5e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bf60  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049bf62  7e20                   -jle 0x49bf84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bf84;
    }
    // 0049bf64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049bf66:
    // 0049bf66  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bf67  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049bf6a  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049bf6d  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bf6e  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049bf71  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bf74  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049bf77  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bf78  8a48fc                 -mov cl, byte ptr [eax - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0049bf7b  42                     -inc edx
    (cpu.edx)++;
    // 0049bf7c  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049bf7f  39f2                   +cmp edx, esi
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
    // 0049bf81  7ce3                   -jl 0x49bf66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bf66;
    }
    // 0049bf83  90                     -nop 
    ;
L_0x0049bf84:
    // 0049bf84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49bf88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bf88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bf89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bf8a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049bf8c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049bf8e  b9a0ea5600             -mov ecx, 0x56eaa0
    cpu.ecx = 5696160 /*0x56eaa0*/;
    // 0049bf93  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bf96  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bf98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bf9a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049bf9c  7e12                   -jle 0x49bfb0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049bfb0;
    }
L_0x0049bf9e:
    // 0049bf9e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bfa1  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049bfa3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bfa6  40                     -inc eax
    (cpu.eax)++;
    // 0049bfa7  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0049bfaa  39f0                   +cmp eax, esi
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
    // 0049bfac  7cf0                   -jl 0x49bf9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bf9e;
    }
    // 0049bfae  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0049bfb0:
    // 0049bfb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bfb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bfb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49bfb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bfb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bfb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bfb6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bfb9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049bfbb  b9a0ea5600             -mov ecx, 0x56eaa0
    cpu.ecx = 5696160 /*0x56eaa0*/;
    // 0049bfc0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bfc3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bfc5  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bfc7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049bfc9  7e41                   -jle 0x49c00c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c00c;
    }
    // 0049bfcb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049bfcd:
    // 0049bfcd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bfcf  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049bfd2  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049bfd5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049bfd8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049bfdb  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049bfdd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bfdf  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049bfe2  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049bfe5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049bfe8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049bfeb  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0049bfee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bff0  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bff1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049bff3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bff6  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049bff9  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bffa  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049bffd  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bffe  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049c001  42                     -inc edx
    (cpu.edx)++;
    // 0049c002  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049c005  39f2                   +cmp edx, esi
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
    // 0049c007  7cc4                   -jl 0x49bfcd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bfcd;
    }
    // 0049c009  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049c00c:
    // 0049c00c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c00f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c010  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c011  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c021  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c023  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049c025  39d0                   +cmp eax, edx
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
    // 0049c027  7e0b                   -jle 0x49c034
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c034;
    }
    // 0049c029  39c8                   +cmp eax, ecx
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
    // 0049c02b  7c0e                   -jl 0x49c03b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c03b;
    }
    // 0049c02d  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049c032  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c033  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c034:
    // 0049c034  b800ffffff             -mov eax, 0xffffff00
    cpu.eax = 4294967040 /*0xffffff00*/;
    // 0049c039  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c03a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c03b:
    // 0049c03b  c1e00e                 -shl eax, 0xe
    cpu.eax <<= 14 /*0xe*/ % 32;
    // 0049c03e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c040  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c043  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c045  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049c048  e803000000             -call 0x49c050
    cpu.esp -= 4;
    sub_49c050(app, cpu);
    if (cpu.terminate) return;
    // 0049c04d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c04e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
