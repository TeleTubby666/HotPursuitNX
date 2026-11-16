#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_48d78c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d78c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d78d  81ecb0000000           -sub esp, 0xb0
    (cpu.esp) -= x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 0048d793  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d795  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d79c  0f84e8000000           -je 0x48d88a
    if (cpu.flags.zf)
    {
        goto L_0x0048d88a;
    }
    // 0048d7a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d7a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d7a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d7a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d7a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d7a7  a1f4ba4d00             -mov eax, dword ptr [0x4dbaf4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094132) /* 0x4dbaf4 */);
    // 0048d7ac  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048d7b0  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d7b4  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048d7b7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d7b8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d7b9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d7ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d7bb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d7bc  40                     -inc eax
    (cpu.eax)++;
    // 0048d7bd  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d7c0  a3f4ba4d00             -mov dword ptr [0x4dbaf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5094132) /* 0x4dbaf4 */) = cpu.eax;
    // 0048d7c5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d7c7  0f84ca000000           -je 0x48d897
    if (cpu.flags.zf)
    {
        goto L_0x0048d897;
    }
    // 0048d7cd  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048d7d0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d7d2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d7d4  0f8588000000           -jne 0x48d862
    if (!cpu.flags.zf)
    {
        goto L_0x0048d862;
    }
    // 0048d7da  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048d7dd  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d7e0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048d7e3  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d7e6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d7e9  899c24c0000000         -mov dword ptr [esp + 0xc0], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.ebx;
    // 0048d7f0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d7f2  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x0048d7f6:
    // 0048d7f6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d7f9  8b7850                 -mov edi, dword ptr [eax + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048d7fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048d7fe  7462                   -je 0x48d862
    if (cpu.flags.zf)
    {
        goto L_0x0048d862;
    }
    // 0048d800  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048d806  8b8c24c0000000         -mov ecx, dword ptr [esp + 0xc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048d80d  4a                     -dec edx
    (cpu.edx)--;
    // 0048d80e  39ca                   +cmp edx, ecx
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
    // 0048d810  7650                   -jbe 0x48d862
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048d862;
    }
    // 0048d812  8a8c24c0000000         -mov cl, byte ptr [esp + 0xc0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048d819  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048d81e  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048d820  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048d822  85fa                   +test edx, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edi));
    // 0048d824  7514                   -jne 0x48d83a
    if (!cpu.flags.zf)
    {
        goto L_0x0048d83a;
    }
L_0x0048d826:
    // 0048d826  8b8424c0000000         -mov eax, dword ptr [esp + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0048d82d  40                     -inc eax
    (cpu.eax)++;
    // 0048d82e  83c664                 +add esi, 0x64
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d831  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 0048d838  ebbc                   -jmp 0x48d7f6
    goto L_0x0048d7f6;
L_0x0048d83a:
    // 0048d83a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048d83c  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0048d83e  21cf                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d840  bb657962ea             -mov ebx, 0xea627965
    cpu.ebx = 3932322149 /*0xea627965*/;
    // 0048d845  897850                 -mov dword ptr [eax + 0x50], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 0048d848  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d84c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d84f  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048d852  81c288000000           -add edx, 0x88
    (cpu.edx) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048d858  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048d85b  01f2                   +add edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d85d  ff5750                 -call dword ptr [edi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d860  ebc4                   -jmp 0x48d826
    goto L_0x0048d826;
L_0x0048d862:
    // 0048d862  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d865  e89270ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0048d86a  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x0048d871:
    // 0048d871  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0048d87b  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 0048d885  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d886  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d887  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d888  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d889  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048d88a:
    // 0048d88a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d88f  81c4b0000000           +add esp, 0xb0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(176 /*0xb0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d895  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d896  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d897:
    // 0048d897  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 0048d899  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d89d  bb657962ea             -mov ebx, 0xea627965
    cpu.ebx = 3932322149 /*0xea627965*/;
    // 0048d8a2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048d8a5  8d551c                 -lea edx, [ebp + 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048d8a8  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048d8ab  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d8ae  ebc1                   -jmp 0x48d871
    goto L_0x0048d871;
}

/* align: skip  */
void Application::sub_48d8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d8b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d8b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d8b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d8b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d8b4  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0048d8ba  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d8bc  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 0048d8c3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d8c5  898c2404010000         -mov dword ptr [esp + 0x104], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.ecx;
    // 0048d8cc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d8ce  0f85a2000000           -jne 0x48d976
    if (!cpu.flags.zf)
    {
        goto L_0x0048d976;
    }
    // 0048d8d4  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d8db  0f8495000000           -je 0x48d976
    if (cpu.flags.zf)
    {
        goto L_0x0048d976;
    }
    // 0048d8e1  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x0048d8e4:
    // 0048d8e4  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d8e8  0f84d8000000           -je 0x48d9c6
    if (cpu.flags.zf)
    {
        goto L_0x0048d9c6;
    }
    // 0048d8ee  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048d8f1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048d8f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d8f5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d8f7  e8f4d9ffff             -call 0x48b2f0
    cpu.esp -= 4;
    sub_48b2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048d8fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d8fe  0f84c2000000           -je 0x48d9c6
    if (cpu.flags.zf)
    {
        goto L_0x0048d9c6;
    }
    // 0048d904  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048d909  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048d90c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d90e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d910  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d917  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d919  0f8451020000           -je 0x48db70
    if (cpu.flags.zf)
    {
        goto L_0x0048db70;
    }
    // 0048d91f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0048d924  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d926  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d928  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 0048d92f  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
L_0x0048d936:
    // 0048d936  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048d939  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048d93f  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0048d946  4a                     -dec edx
    (cpu.edx)--;
    // 0048d947  39fa                   +cmp edx, edi
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
    // 0048d949  0f8621020000           -jbe 0x48db70
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048db70;
    }
    // 0048d94f  8a8c2408010000         -mov cl, byte ptr [esp + 0x108]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0048d956  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048d95b  d3e2                   +shl edx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0048d95d  855050                 -test dword ptr [eax + 0x50], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) & cpu.edx));
    // 0048d960  753d                   -jne 0x48d99f
    if (!cpu.flags.zf)
    {
        goto L_0x0048d99f;
    }
L_0x0048d962:
    // 0048d962  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0048d969  47                     -inc edi
    (cpu.edi)++;
    // 0048d96a  83c664                 +add esi, 0x64
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d96d  89bc2408010000         -mov dword ptr [esp + 0x108], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.edi;
    // 0048d974  ebc0                   -jmp 0x48d936
    goto L_0x0048d936;
L_0x0048d976:
    // 0048d976  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d978  7418                   -je 0x48d992
    if (cpu.flags.zf)
    {
        goto L_0x0048d992;
    }
    // 0048d97a  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d981  750f                   -jne 0x48d992
    if (!cpu.flags.zf)
    {
        goto L_0x0048d992;
    }
    // 0048d983  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d985  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048d988  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d989  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d98a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d98b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d98c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d98d  e952ffffff             -jmp 0x48d8e4
    goto L_0x0048d8e4;
L_0x0048d992:
    // 0048d992  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d994  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0048d99a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d99b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d99c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d99d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d99e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d99f:
    // 0048d99f  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048d9a4  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048d9a7  8d1430                 -lea edx, [eax + esi]
    cpu.edx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0048d9aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d9ac  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d9ae  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d9b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d9b7  0f84b3010000           -je 0x48db70
    if (cpu.flags.zf)
    {
        goto L_0x0048db70;
    }
    // 0048d9bd  ff842404010000         +inc dword ptr [esp + 0x104]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048d9c4  eb9c                   -jmp 0x48d962
    goto L_0x0048d962;
L_0x0048d9c6:
    // 0048d9c6  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048d9cb  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048d9d2  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 0048d9d7  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048d9dc  bed0c14800             -mov esi, 0x48c1d0
    cpu.esi = 4768208 /*0x48c1d0*/;
    // 0048d9e1  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d9e3  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048d9ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d9eb  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d9ed  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 0048d9f2  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d9f6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d9f8  e85beaffff             -call 0x48c458
    cpu.esp -= 4;
    sub_48c458(app, cpu);
    if (cpu.terminate) return;
    // 0048d9fd  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048da05  0f8465010000           -je 0x48db70
    if (cpu.flags.zf)
    {
        goto L_0x0048db70;
    }
    // 0048da0b  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048da12  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048da17  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048da1c  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0048da23  899424b0000000         -mov dword ptr [esp + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 0048da2a  8b8424fc000000         -mov eax, dword ptr [esp + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0048da31  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048da36  898424c4000000         -mov dword ptr [esp + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 0048da3d  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048da41  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048da45  e80ae6ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048da4a  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048da4f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048da51  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048da53  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 0048da58  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048da59  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048da60  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048da63  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0048da65  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048da67  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048da68  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048da69  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048da6a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048da6b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048da6c  e8e7e9ffff             -call 0x48c458
    cpu.esp -= 4;
    sub_48c458(app, cpu);
    if (cpu.terminate) return;
    // 0048da71  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048da79  0f8403010000           -je 0x48db82
    if (cpu.flags.zf)
    {
        goto L_0x0048db82;
    }
    // 0048da7f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048da84:
    // 0048da84  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048da8b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048da8d  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 0048da94  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
    // 0048da9b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048da9d  0f84cd000000           -je 0x48db70
    if (cpu.flags.zf)
    {
        goto L_0x0048db70;
    }
L_0x0048daa3:
    // 0048daa3  83bc240c0100001f       +cmp dword ptr [esp + 0x10c], 0x1f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048daab  0f8dbf000000           -jge 0x48db70
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048db70;
    }
    // 0048dab1  83bc24c400000000       +cmp dword ptr [esp + 0xc4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dab9  0f84b1000000           -je 0x48db70
    if (cpu.flags.zf)
    {
        goto L_0x0048db70;
    }
    // 0048dabf  83bc240401000000       +cmp dword ptr [esp + 0x104], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dac7  0f84a3000000           -je 0x48db70
    if (cpu.flags.zf)
    {
        goto L_0x0048db70;
    }
    // 0048dacd  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0048dad4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048dad9  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048dae0  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048dae2  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 0048dae4  746c                   -je 0x48db52
    if (cpu.flags.zf)
    {
        goto L_0x0048db52;
    }
    // 0048dae6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048daeb  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0048daf2  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048daf6  e859e5ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048dafb  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048db00  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048db02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048db03  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048db07  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 0048db0c  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0048db0e  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048db15  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048db17  e83ce9ffff             -call 0x48c458
    cpu.esp -= 4;
    sub_48c458(app, cpu);
    if (cpu.terminate) return;
    // 0048db1c  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048db24  7463                   -je 0x48db89
    if (cpu.flags.zf)
    {
        goto L_0x0048db89;
    }
    // 0048db26  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048db2b:
    // 0048db2b  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0048db32  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 0048db39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048db3e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048db40  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0048db47  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0048db49  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0048db4b  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
L_0x0048db52:
    // 0048db52  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0048db59  42                     -inc edx
    (cpu.edx)++;
    // 0048db5a  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048db61  8994240c010000         -mov dword ptr [esp + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 0048db68  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048db6a  0f8533ffffff           -jne 0x48daa3
    if (!cpu.flags.zf)
    {
        goto L_0x0048daa3;
    }
L_0x0048db70:
    // 0048db70  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048db77  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0048db7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048db7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048db7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048db80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048db81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048db82:
    // 0048db82  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048db84  e9fbfeffff             -jmp 0x48da84
    goto L_0x0048da84;
L_0x0048db89:
    // 0048db89  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048db8b  eb9e                   -jmp 0x48db2b
    goto L_0x0048db2b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48db90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048db90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048db91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048db92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048db93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048db94  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048db97  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048db99  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048db9c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048db9e  750a                   -jne 0x48dbaa
    if (!cpu.flags.zf)
    {
        goto L_0x0048dbaa;
    }
L_0x0048dba0:
    // 0048dba0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dba2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dba5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dba6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dba7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dba8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dba9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dbaa:
    // 0048dbaa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048dbac  e887e9ffff             -call 0x48c538
    cpu.esp -= 4;
    sub_48c538(app, cpu);
    if (cpu.terminate) return;
    // 0048dbb1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048dbb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048dbb5  74e9                   -je 0x48dba0
    if (cpu.flags.zf)
    {
        goto L_0x0048dba0;
    }
    // 0048dbb7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dbb8  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048dbbb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048dbbd  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048dbc2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dbc4  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0048dbc9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dbcb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dbce  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dbd0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048dbd2  bb74756fea             -mov ebx, 0xea6f7574
    cpu.ebx = 3933173108 /*0xea6f7574*/;
    // 0048dbd7  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048dbda  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048dbde  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048dbe0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dbe2  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048dbe5  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048dbe8  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048dbec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048dbf1  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048dbf4  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048dbf6  8b5a50                 -mov ebx, dword ptr [edx + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 0048dbf9  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0048dbfb  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dbfd  895a50                 -mov dword ptr [edx + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 0048dc00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dc03  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dc06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48dc0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc0c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dc0d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048dc0f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048dc11  745a                   -je 0x48dc6d
    if (cpu.flags.zf)
    {
        goto L_0x0048dc6d;
    }
    // 0048dc13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dc14  837a2400               +cmp dword ptr [edx + 0x24], 0
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
    // 0048dc18  7515                   -jne 0x48dc2f
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc2f;
    }
    // 0048dc1a  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048dc20  bf1e000000             -mov edi, 0x1e
    cpu.edi = 30 /*0x1e*/;
    // 0048dc25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc27  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dc2a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dc2c  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x0048dc2f:
    // 0048dc2f  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 0048dc33  7515                   -jne 0x48dc4a
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc4a;
    }
    // 0048dc35  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048dc3b  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 0048dc40  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc42  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dc45  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dc47  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0048dc4a:
    // 0048dc4a  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 0048dc4e  7515                   -jne 0x48dc65
    if (!cpu.flags.zf)
    {
        goto L_0x0048dc65;
    }
    // 0048dc50  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048dc56  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 0048dc5b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc5d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dc60  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dc62  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0048dc65:
    // 0048dc65  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048dc6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048dc6d:
    // 0048dc6d  bac84b4d00             -mov edx, 0x4d4bc8
    cpu.edx = 5065672 /*0x4d4bc8*/;
    // 0048dc72  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dc73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048dc75  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048dc77  bb3cbb4d00             -mov ebx, 0x4dbb3c
    cpu.ebx = 5094204 /*0x4dbb3c*/;
    // 0048dc7c  e807c5ffff             -call 0x48a188
    cpu.esp -= 4;
    sub_48a188(app, cpu);
    if (cpu.terminate) return;
    // 0048dc81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48dc84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dc85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dc86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dc87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dc88  8b7048                 -mov esi, dword ptr [eax + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048dc8b  89158c435600           -mov dword ptr [0x56438c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */) = cpu.edx;
    // 0048dc91  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048dc94  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048dc96  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048dc98  7459                   -je 0x48dcf3
    if (cpu.flags.zf)
    {
        goto L_0x0048dcf3;
    }
    // 0048dc9a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048dc9d  837a4400               +cmp dword ptr [edx + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dca1  740b                   -je 0x48dcae
    if (cpu.flags.zf)
    {
        goto L_0x0048dcae;
    }
    // 0048dca3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048dca5  8d5030                 -lea edx, [eax + 0x30]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 0048dca8  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048dcab  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048dcae:
    // 0048dcae  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dcaf  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 0048dcb4  8d5730                 -lea edx, [edi + 0x30]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0048dcb7  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048dcba  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048dcbd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dcbf  ff5558                 -call dword ptr [ebp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048dcc2  a17c435600             -mov eax, dword ptr [0x56437c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653372) /* 0x56437c */);
    // 0048dcc7  e87cc2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048dccc  8b9ea8000000           -mov ebx, dword ptr [esi + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0048dcd2  43                     -inc ebx
    (cpu.ebx)++;
    // 0048dcd3  a17c435600             -mov eax, dword ptr [0x56437c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653372) /* 0x56437c */);
    // 0048dcd8  899ea8000000           -mov dword ptr [esi + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 0048dcde  e87dc2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048dce3  c74744ffffffff         -mov dword ptr [edi + 0x44], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 4294967295 /*0xffffffff*/;
    // 0048dcea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dceb  8b4744                 -mov eax, dword ptr [edi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 0048dcee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcf2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dcf3:
    // 0048dcf3  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0048dcf6  8b4744                 -mov eax, dword ptr [edi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 0048dcf9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcfa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcfb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcfd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48dd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dd00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dd02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048dd03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dd04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dd05  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048dd07  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048dd0a  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048dd0d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048dd0f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048dd11  7409                   -je 0x48dd1c
    if (cpu.flags.zf)
    {
        goto L_0x0048dd1c;
    }
    // 0048dd13  83baa800000000         +cmp dword ptr [edx + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dd1a  7512                   -jne 0x48dd2e
    if (!cpu.flags.zf)
    {
        goto L_0x0048dd2e;
    }
L_0x0048dd1c:
    // 0048dd1c  c7474400000000         -mov dword ptr [edi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0048dd23  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048dd28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dd2e:
    // 0048dd2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dd2f  a17c435600             -mov eax, dword ptr [0x56437c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653372) /* 0x56437c */);
    // 0048dd34  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 0048dd39  e80ac2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048dd3e  8d7130                 -lea esi, [ecx + 0x30]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0048dd41  8baaa8000000           -mov ebp, dword ptr [edx + 0xa8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 0048dd47  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048dd4c  4d                     -dec ebp
    (cpu.ebp)--;
    // 0048dd4d  a17c435600             -mov eax, dword ptr [0x56437c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653372) /* 0x56437c */);
    // 0048dd52  89aaa8000000           -mov dword ptr [edx + 0xa8], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.ebp;
    // 0048dd58  e803c2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048dd5d  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048dd60  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048dd63  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048dd65  ff5558                 -call dword ptr [ebp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048dd68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd69  c7474400000000         -mov dword ptr [edi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0048dd70  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048dd75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd77  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48dd7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dd7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dd7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dd7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048dd7f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048dd81  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 0048dd87  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048dd89  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048dd8b  751b                   -jne 0x48dda8
    if (!cpu.flags.zf)
    {
        goto L_0x0048dda8;
    }
L_0x0048dd8d:
    // 0048dd8d  83794400               +cmp dword ptr [ecx + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dd91  7428                   -je 0x48ddbb
    if (cpu.flags.zf)
    {
        goto L_0x0048ddbb;
    }
    // 0048dd93  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0048dd96  83b89c00000000         +cmp dword ptr [eax + 0x9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dd9d  741c                   -je 0x48ddbb
    if (cpu.flags.zf)
    {
        goto L_0x0048ddbb;
    }
    // 0048dd9f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048dda4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dda5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dda6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dda7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dda8:
    // 0048dda8  e833000000             -call 0x48dde0
    cpu.esp -= 4;
    sub_48dde0(app, cpu);
    if (cpu.terminate) return;
    // 0048ddad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ddaf  74dc                   -je 0x48dd8d
    if (cpu.flags.zf)
    {
        goto L_0x0048dd8d;
    }
    // 0048ddb1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ddb3  ff158c435600           -call dword ptr [0x56438c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ddb9  ebd2                   -jmp 0x48dd8d
    goto L_0x0048dd8d;
L_0x0048ddbb:
    // 0048ddbb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ddbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ddc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ddc4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ddc5  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048ddc8  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048ddcb  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048ddce  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ddd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ddd3  7408                   -je 0x48dddd
    if (cpu.flags.zf)
    {
        goto L_0x0048dddd;
    }
    // 0048ddd5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ddd7  66a158bb4d00           -mov ax, word ptr [0x4dbb58]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5094232) /* 0x4dbb58 */);
L_0x0048dddd:
    // 0048dddd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48dde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dde0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048dde1  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048dde4  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048dde7  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048ddea  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048dded  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ddf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ddf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ddf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ddf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ddf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ddf4  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048ddf7  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 0048ddfb  895c2468               -mov dword ptr [esp + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 0048ddff  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0048de04  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048de06  be20c24800             -mov esi, 0x48c220
    cpu.esi = 4768288 /*0x48c220*/;
    // 0048de0b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048de0d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048de0f  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048de12  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0048de14  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048de18  83c730                 -add edi, 0x30
    (cpu.edi) += x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x0048de1b:
    // 0048de1b  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 0048de20  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0048de25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048de27  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0048de2b  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0048de2f  8b4c2468               -mov ecx, dword ptr [esp + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0048de33  e848cbffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048de38  8d5c2464               -lea ebx, [esp + 0x64]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048de3c  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 0048de3f  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0048de43  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048de44  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048de47  8b4c2470               -mov ecx, dword ptr [esp + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0048de4b  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048de4e  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048de51  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048de55  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048de57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048de59  746c                   -je 0x48dec7
    if (cpu.flags.zf)
    {
        goto L_0x0048dec7;
    }
    // 0048de5b  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 0048de5e  83781800               +cmp dword ptr [eax + 0x18], 0
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
    // 0048de62  7505                   -jne 0x48de69
    if (!cpu.flags.zf)
    {
        goto L_0x0048de69;
    }
    // 0048de64  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048de66  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0048de69:
    // 0048de69  8b4c246c               -mov ecx, dword ptr [esp + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048de6d  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048de71  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 0048de74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048de75  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0048de79  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048de7c  e83be8ffff             -call 0x48c6bc
    cpu.esp -= 4;
    sub_48c6bc(app, cpu);
    if (cpu.terminate) return;
    // 0048de81  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 0048de84  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048de86  3b5018                 +cmp edx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048de89  7507                   -jne 0x48de92
    if (!cpu.flags.zf)
    {
        goto L_0x0048de92;
    }
    // 0048de8b  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x0048de92:
    // 0048de92  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048de96  81fb746164ea           +cmp ebx, 0xea646174
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932447092 /*0xea646174*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048de9c  7418                   -je 0x48deb6
    if (cpu.flags.zf)
    {
        goto L_0x0048deb6;
    }
    // 0048de9e  81fb216f6eea           +cmp ebx, 0xea6e6f21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933105953 /*0xea6e6f21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dea4  0f8571ffffff           -jne 0x48de1b
    if (!cpu.flags.zf)
    {
        goto L_0x0048de1b;
    }
    // 0048deaa  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048deb1  e965ffffff             -jmp 0x48de1b
    goto L_0x0048de1b;
L_0x0048deb6:
    // 0048deb6  c7454401000000         -mov dword ptr [ebp + 0x44], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(68) /* 0x44 */) = 1 /*0x1*/;
    // 0048debd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048debf  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048dec2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dec3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dec4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dec5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dec6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dec7:
    // 0048dec7  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 0048deca  83b8a800000000         +cmp dword ptr [eax + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ded1  7512                   -jne 0x48dee5
    if (!cpu.flags.zf)
    {
        goto L_0x0048dee5;
    }
    // 0048ded3  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 0048ded8  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048dedb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dedd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048dedf  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048dee2  ff5658                 -call dword ptr [esi + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048dee5:
    // 0048dee5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048dee7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048dee9  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048deec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048deed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048deee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048deef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048def0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48def4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048def4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048def5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048def6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048def7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048def8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048defb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048defd  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048df00  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048df02  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 0048df07  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048df0b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048df0f  83784400               +cmp dword ptr [eax + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048df13  7d35                   -jge 0x48df4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048df4a;
    }
    // 0048df15  ff4844                 -dec dword ptr [eax + 0x44]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */))--;
    // 0048df18  837844fc               +cmp dword ptr [eax + 0x44], -4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048df1c  7d2c                   -jge 0x48df4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048df4a;
    }
    // 0048df1e  b86e706fea             -mov eax, 0xea6f706e
    cpu.eax = 3933171822 /*0xea6f706e*/;
    // 0048df23  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048df25  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048df29  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0048df2c  bb6e706fea             -mov ebx, 0xea6f706e
    cpu.ebx = 3933171822 /*0xea6f706e*/;
    // 0048df31  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0048df34  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048df37  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048df39  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048df3c  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048df3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048df41  7407                   -je 0x48df4a
    if (cpu.flags.zf)
    {
        goto L_0x0048df4a;
    }
    // 0048df43  c74644ffffffff         -mov dword ptr [esi + 0x44], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 4294967295 /*0xffffffff*/;
L_0x0048df4a:
    // 0048df4a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048df4e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048df52  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048df55  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048df58  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048df5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048df5d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048df60  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048df63  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048df66  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048df69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048df6b  7402                   -je 0x48df6f
    if (cpu.flags.zf)
    {
        goto L_0x0048df6f;
    }
    // 0048df6d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0048df6f:
    // 0048df6f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048df72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48df80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df80  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 0048df81  61                     -popal 
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
    // 0048df82  67eaffffffff5152       -ljmp 0x5251:0xffffffff
    NFS2_ASSERT(false);
    // 0048df8a  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048df91  3b05e4435600           +cmp eax, dword ptr [0x5643e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653476) /* 0x5643e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048df97  7208                   -jb 0x48dfa1
    if (cpu.flags.cf)
    {
        goto L_0x0048dfa1;
    }
    // 0048df99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048df9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfa0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dfa1:
    // 0048dfa1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dfa3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfa5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48dfa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dfa8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dfa9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dfab  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048dfad  833df043560000         +cmp dword ptr [0x5643f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dfb4  7404                   -je 0x48dfba
    if (cpu.flags.zf)
    {
        goto L_0x0048dfba;
    }
    // 0048dfb6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dfb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dfb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dfba:
    // 0048dfba  baf4435600             -mov edx, 0x5643f4
    cpu.edx = 5653492 /*0x5643f4*/;
    // 0048dfbf  e8bcc9ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048dfc4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048dfc9  890df0435600           -mov dword ptr [0x5643f0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */) = cpu.ecx;
    // 0048dfcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
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
    // 0048dfd4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dfd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dfd6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dfd7  81ec04200000           -sub esp, 0x2004
    (cpu.esp) -= x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 0048dfdd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048dfdf  89942400200000         -mov dword ptr [esp + 0x2000], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8192) /* 0x2000 */) = cpu.edx;
    // 0048dfe6  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048dfe8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048dfea  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048dfef  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048dff1  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048dff6  e885c9ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048dffb  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048dfff  8b842400200000         -mov eax, dword ptr [esp + 0x2000]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8192) /* 0x2000 */);
    // 0048e006  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048e008  e873c9ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048e00d  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048e010  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e017  a3e8435600             -mov dword ptr [0x5643e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653480) /* 0x5643e8 */) = cpu.eax;
    // 0048e01c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048e01e:
    // 0048e01e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e020  b890435600             -mov eax, 0x564390
    cpu.eax = 5653392 /*0x564390*/;
    // 0048e025  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048e027  e8c4c2ffff             -call 0x48a2f0
    cpu.esp -= 4;
    sub_48a2f0(app, cpu);
    if (cpu.terminate) return;
    // 0048e02c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e02e  751a                   -jne 0x48e04a
    if (!cpu.flags.zf)
    {
        goto L_0x0048e04a;
    }
    // 0048e030  3b0d94435600           +cmp ecx, dword ptr [0x564394]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653396) /* 0x564394 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e036  7412                   -je 0x48e04a
    if (cpu.flags.zf)
    {
        goto L_0x0048e04a;
    }
    // 0048e038  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048e03a  74e2                   -je 0x48e01e
    if (cpu.flags.zf)
    {
        goto L_0x0048e01e;
    }
    // 0048e03c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e041  e8fe5effff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048e046  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e048  7cd4                   -jl 0x48e01e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e01e;
    }
L_0x0048e04a:
    // 0048e04a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048e04c  0f847c000000           -je 0x48e0ce
    if (cpu.flags.zf)
    {
        goto L_0x0048e0ce;
    }
    // 0048e052  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e057  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048e059:
    // 0048e059  8b1df0435600           -mov ebx, dword ptr [0x5643f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
    // 0048e05f  39da                   +cmp edx, ebx
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
    // 0048e061  7513                   -jne 0x48e076
    if (!cpu.flags.zf)
    {
        goto L_0x0048e076;
    }
    // 0048e063  3b1d94435600           +cmp ebx, dword ptr [0x564394]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653396) /* 0x564394 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e069  740b                   -je 0x48e076
    if (cpu.flags.zf)
    {
        goto L_0x0048e076;
    }
    // 0048e06b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e06d  e8d25effff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048e072  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e074  7de3                   -jge 0x48e059
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e059;
    }
L_0x0048e076:
    // 0048e076  833df043560000         +cmp dword ptr [0x5643f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e07d  7420                   -je 0x48e09f
    if (cpu.flags.zf)
    {
        goto L_0x0048e09f;
    }
    // 0048e07f  813df4435600687568ea   +cmp dword ptr [0x5643f4], 0xea687568
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932714344 /*0xea687568*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e089  7520                   -jne 0x48e0ab
    if (!cpu.flags.zf)
    {
        goto L_0x0048e0ab;
    }
    // 0048e08b  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0048e095  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
L_0x0048e09f:
    // 0048e09f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e0a1  81c404200000           -add esp, 0x2004
    (cpu.esp) += x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 0048e0a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e0ab:
    // 0048e0ab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e0ad  8915f0435600           -mov dword ptr [0x5643f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */) = cpu.edx;
    // 0048e0b3  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e0ba  a3e8435600             -mov dword ptr [0x5643e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653480) /* 0x5643e8 */) = cpu.eax;
    // 0048e0bf  a1f4435600             -mov eax, dword ptr [0x5643f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 0048e0c4  81c404200000           -add esp, 0x2004
    (cpu.esp) += x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 0048e0ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e0ce:
    // 0048e0ce  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e0d3  81c404200000           -add esp, 0x2004
    (cpu.esp) += x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 0048e0d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e0e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e0e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e0e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e0e4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e0e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e0e8  740e                   -je 0x48e0f8
    if (cpu.flags.zf)
    {
        goto L_0x0048e0f8;
    }
L_0x0048e0ea:
    // 0048e0ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e0ec  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048e0ee  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048e0f0  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e0f2  42                     -inc edx
    (cpu.edx)++;
    // 0048e0f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e0f5  75f3                   -jne 0x48e0ea
    if (!cpu.flags.zf)
    {
        goto L_0x0048e0ea;
    }
    // 0048e0f7  90                     -nop 
    ;
L_0x0048e0f8:
    // 0048e0f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e0fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e100  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e101  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e102  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e103  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048e106  833df043560000         +cmp dword ptr [0x5643f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e10d  0f847e000000           -je 0x48e191
    if (cpu.flags.zf)
    {
        goto L_0x0048e191;
    }
    // 0048e113  833d9443560000         +cmp dword ptr [0x564394], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653396) /* 0x564394 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e11a  7475                   -je 0x48e191
    if (cpu.flags.zf)
    {
        goto L_0x0048e191;
    }
    // 0048e11c  813df4435600706e61ea   +cmp dword ptr [0x5643f4], 0xea616e70
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932253808 /*0xea616e70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e126  7569                   -jne 0x48e191
    if (!cpu.flags.zf)
    {
        goto L_0x0048e191;
    }
    // 0048e128  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e129  8b2dd8435600           -mov ebp, dword ptr [0x5643d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0048e12f  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048e132  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048e134  7452                   -je 0x48e188
    if (cpu.flags.zf)
    {
        goto L_0x0048e188;
    }
    // 0048e136  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e137  be736572ea             -mov esi, 0xea726573
    cpu.esi = 3933365619 /*0xea726573*/;
    // 0048e13c  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e140  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0048e144  bef8435600             -mov esi, 0x5643f8
    cpu.esi = 5653496 /*0x5643f8*/;
    // 0048e149  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e14a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e14b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e14c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e14d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e14e  8b1d78445600           -mov ebx, dword ptr [0x564478]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653624) /* 0x564478 */);
    // 0048e154  baf4435600             -mov edx, 0x5643f4
    cpu.edx = 5653492 /*0x5643f4*/;
    // 0048e159  83c228                 -add edx, 0x28
    (cpu.edx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0048e15c  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0048e161  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e163  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e165  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048e169  a178445600             -mov eax, dword ptr [0x564478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653624) /* 0x564478 */);
    // 0048e16e  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048e172  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0048e177  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0048e17c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e180  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e182  e84dfeffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e187  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048e188:
    // 0048e188  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048e18a  893df0435600           -mov dword ptr [0x5643f0], edi
    app->getMemory<x86::reg32>(x86::reg32(5653488) /* 0x5643f0 */) = cpu.edi;
    // 0048e190  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048e191:
    // 0048e191  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0048e196  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 0048e19a  7520                   -jne 0x48e1bc
    if (!cpu.flags.zf)
    {
        goto L_0x0048e1bc;
    }
    // 0048e19c  833d9443560000         +cmp dword ptr [0x564394], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653396) /* 0x564394 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e1a3  7420                   -je 0x48e1c5
    if (cpu.flags.zf)
    {
        goto L_0x0048e1c5;
    }
    // 0048e1a5  8b1de8435600           -mov ebx, dword ptr [0x5643e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653480) /* 0x5643e8 */);
    // 0048e1ab  81c310270000           -add ebx, 0x2710
    (cpu.ebx) += x86::reg32(x86::sreg32(10000 /*0x2710*/));
    // 0048e1b1  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e1b8  39d8                   +cmp eax, ebx
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
    // 0048e1ba  7709                   -ja 0x48e1c5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048e1c5;
    }
L_0x0048e1bc:
    // 0048e1bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e1be  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048e1c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e1c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e1c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e1c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e1c5:
    // 0048e1c5  b890435600             -mov eax, 0x564390
    cpu.eax = 5653392 /*0x564390*/;
    // 0048e1ca  e839c1ffff             -call 0x48a308
    cpu.esp -= 4;
    sub_48a308(app, cpu);
    if (cpu.terminate) return;
    // 0048e1cf  b800e14800             -mov eax, 0x48e100
    cpu.eax = 4776192 /*0x48e100*/;
    // 0048e1d4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e1d6  e8895cffff             -call 0x483e64
    cpu.esp -= 4;
    sub_483e64(app, cpu);
    if (cpu.terminate) return;
    // 0048e1db  8915e0435600           -mov dword ptr [0x5643e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653472) /* 0x5643e0 */) = cpu.edx;
    // 0048e1e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e1e3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048e1e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e1e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e1e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e1e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e1ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e1ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e1ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e1ee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e1ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e1f0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e1f2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048e1f4  833d9443560000         +cmp dword ptr [0x564394], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653396) /* 0x564394 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e1fb  7426                   -je 0x48e223
    if (cpu.flags.zf)
    {
        goto L_0x0048e223;
    }
    // 0048e1fd  3b05d8435600           +cmp eax, dword ptr [0x5643d8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e203  7473                   -je 0x48e278
    if (cpu.flags.zf)
    {
        goto L_0x0048e278;
    }
    // 0048e205  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e206  b890435600             -mov eax, 0x564390
    cpu.eax = 5653392 /*0x564390*/;
    // 0048e20b  e8f8c0ffff             -call 0x48a308
    cpu.esp -= 4;
    sub_48a308(app, cpu);
    if (cpu.terminate) return;
    // 0048e210  b800e14800             -mov eax, 0x48e100
    cpu.eax = 4776192 /*0x48e100*/;
    // 0048e215  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048e217  e8485cffff             -call 0x483e64
    cpu.esp -= 4;
    sub_483e64(app, cpu);
    if (cpu.terminate) return;
    // 0048e21c  893de0435600           -mov dword ptr [0x5643e0], edi
    app->getMemory<x86::reg32>(x86::reg32(5653472) /* 0x5643e0 */) = cpu.edi;
    // 0048e222  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048e223:
    // 0048e223  ba50000000             -mov edx, 0x50
    cpu.edx = 80 /*0x50*/;
    // 0048e228  b890435600             -mov eax, 0x564390
    cpu.eax = 5653392 /*0x564390*/;
    // 0048e22d  bd88df4800             -mov ebp, 0x48df88
    cpu.ebp = 4775816 /*0x48df88*/;
    // 0048e232  e8e5bdffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048e237  892da4435600           -mov dword ptr [0x5643a4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653412) /* 0x5643a4 */) = cpu.ebp;
    // 0048e23d  c705b0435600a8df4800   -mov dword ptr [0x5643b0], 0x48dfa8
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = 4775848 /*0x48dfa8*/;
    // 0048e247  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e24e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e250  a3e4435600             -mov dword ptr [0x5643e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653476) /* 0x5643e4 */) = cpu.eax;
    // 0048e255  b9c0435600             -mov ecx, 0x5643c0
    cpu.ecx = 5653440 /*0x5643c0*/;
    // 0048e25a  8b1d60bb4d00           -mov ebx, dword ptr [0x4dbb60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094240) /* 0x4dbb60 */);
    // 0048e260  8b155cbb4d00           -mov edx, dword ptr [0x4dbb5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094236) /* 0x4dbb5c */);
    // 0048e266  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e268  e88fd0ffff             -call 0x48b2fc
    cpu.esp -= 4;
    sub_48b2fc(app, cpu);
    if (cpu.terminate) return;
    // 0048e26d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e26f  7511                   -jne 0x48e282
    if (!cpu.flags.zf)
    {
        goto L_0x0048e282;
    }
L_0x0048e271:
    // 0048e271  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e273  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e274  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e275  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e276  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e277  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e278:
    // 0048e278  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e27d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e27e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e27f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e280  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e281  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e282:
    // 0048e282  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048e287  bafa000000             -mov edx, 0xfa
    cpu.edx = 250 /*0xfa*/;
    // 0048e28c  b890435600             -mov eax, 0x564390
    cpu.eax = 5653392 /*0x564390*/;
    // 0048e291  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048e293  e834d0ffff             -call 0x48b2cc
    cpu.esp -= 4;
    sub_48b2cc(app, cpu);
    if (cpu.terminate) return;
    // 0048e298  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e29a  74d5                   -je 0x48e271
    if (cpu.flags.zf)
    {
        goto L_0x0048e271;
    }
    // 0048e29c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048e2a1  b800e14800             -mov eax, 0x48e100
    cpu.eax = 4776192 /*0x48e100*/;
    // 0048e2a6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048e2a8  e8235bffff             -call 0x483dd0
    cpu.esp -= 4;
    sub_483dd0(app, cpu);
    if (cpu.terminate) return;
    // 0048e2ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048e2b2  8915e0435600           -mov dword ptr [0x5643e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653472) /* 0x5643e0 */) = cpu.edx;
    // 0048e2b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e2ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48e2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e2c0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e2c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e2c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e2c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e2c9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e2ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e2cc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048e2ce  e89dbfffff             -call 0x48a270
    cpu.esp -= 4;
    sub_48a270(app, cpu);
    if (cpu.terminate) return;
    // 0048e2d3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048e2d6  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e2d9  a3a8bb4d00             -mov dword ptr [0x4dbba8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094312) /* 0x4dbba8 */) = cpu.eax;
    // 0048e2de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e2e0  7505                   -jne 0x48e2e7
    if (!cpu.flags.zf)
    {
        goto L_0x0048e2e7;
    }
L_0x0048e2e2:
    // 0048e2e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e2e4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e2e7:
    // 0048e2e7  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048e2ea  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048e2ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e2ee  ff531c                 -call dword ptr [ebx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e2f1  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048e2f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e2f6  74ea                   -je 0x48e2e2
    if (cpu.flags.zf)
    {
        goto L_0x0048e2e2;
    }
    // 0048e2f8  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048e2fb  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0048e2fe  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048e303  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e306  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048e30c  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 0048e316  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048e318  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048e31f  e85cc6ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048e324  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 0048e329  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e32d  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0048e330  e8a781ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048e335  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 0048e33a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e33e  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0048e341  e89681ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048e346  a1a8bb4d00             -mov eax, dword ptr [0x4dbba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094312) /* 0x4dbba8 */);
    // 0048e34b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e34c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e34d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_48e350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e351  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e352  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e354  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048e357  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e35c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048e35e  7431                   -je 0x48e391
    if (cpu.flags.zf)
    {
        goto L_0x0048e391;
    }
    // 0048e360  83baa000000000         +cmp dword ptr [edx + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e367  7407                   -je 0x48e370
    if (cpu.flags.zf)
    {
        goto L_0x0048e370;
    }
    // 0048e369  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e36b  e81ccfffff             -call 0x48b28c
    cpu.esp -= 4;
    sub_48b28c(app, cpu);
    if (cpu.terminate) return;
L_0x0048e370:
    // 0048e370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e371  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048e374  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e376  ff5320                 -call dword ptr [ebx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e379  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 0048e383  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048e386  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048e38d  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e390  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048e391:
    // 0048e391  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e392  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e393  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e394(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e394  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e395  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e396  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048e399  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e39b  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048e39f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048e3a1  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048e3a8  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e3aa  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e3ad  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e3af  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e3b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e3b4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048e3b7  8b0dccab4d00           -mov ecx, dword ptr [0x4dabcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048e3bd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e3bf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e3c1  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0048e3c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e3c5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e3c7  e820feffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e3cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e3ce  745f                   -je 0x48e42f
    if (cpu.flags.zf)
    {
        goto L_0x0048e42f;
    }
    // 0048e3d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e3d1  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e3d5  be80df4800             -mov esi, 0x48df80
    cpu.esi = 4775808 /*0x48df80*/;
    // 0048e3da  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e3db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e3dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048e3dd:
    // 0048e3dd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e3e2  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0048e3e7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e3e9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e3eb  e8e4fbffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e3f0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048e3f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e3f4  7435                   -je 0x48e42b
    if (cpu.flags.zf)
    {
        goto L_0x0048e42b;
    }
    // 0048e3f6  813df4435600636564ea   +cmp dword ptr [0x5643f4], 0xea646563
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e400  7529                   -jne 0x48e42b
    if (!cpu.flags.zf)
    {
        goto L_0x0048e42b;
    }
    // 0048e402  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048e404:
    // 0048e404  8b8260445600           -mov eax, dword ptr [edx + 0x564460]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5653600) /* 0x564460 */);
    // 0048e40a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048e40d  e8cefcffff             -call 0x48e0e0
    cpu.esp -= 4;
    sub_48e0e0(app, cpu);
    if (cpu.terminate) return;
    // 0048e412  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e415  75ed                   -jne 0x48e404
    if (!cpu.flags.zf)
    {
        goto L_0x0048e404;
    }
    // 0048e417  b9f8435600             -mov ecx, 0x5643f8
    cpu.ecx = 5653496 /*0x5643f8*/;
    // 0048e41c  ba1c445600             -mov edx, 0x56441c
    cpu.edx = 5653532 /*0x56441c*/;
    // 0048e421  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048e423  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e425  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e429  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048e42b:
    // 0048e42b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048e42d  75ae                   -jne 0x48e3dd
    if (!cpu.flags.zf)
    {
        goto L_0x0048e3dd;
    }
L_0x0048e42f:
    // 0048e42f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e431  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048e434  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e435  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48e438(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e438  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e439  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e43a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e43b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e43c  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048e442  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e444  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048e446  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e44d  7405                   -je 0x48e454
    if (cpu.flags.zf)
    {
        goto L_0x0048e454;
    }
    // 0048e44f  e8f0030000             -call 0x48e844
    cpu.esp -= 4;
    sub_48e844(app, cpu);
    if (cpu.terminate) return;
L_0x0048e454:
    // 0048e454  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e459  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e45b  e88cfdffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e460  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e462  0f8497000000           -je 0x48e4ff
    if (cpu.flags.zf)
    {
        goto L_0x0048e4ff;
    }
    // 0048e468  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0048e46d  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e471  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048e475  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e477  b9646461ea             -mov ecx, 0xea616464
    cpu.ecx = 3932251236 /*0xea616464*/;
    // 0048e47c  e85b80ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048e481  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048e484  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 0048e489  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048e48c  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 0048e491  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e493  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e495  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e497  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e49c  e833fbffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e4a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e4a3  745a                   -je 0x48e4ff
    if (cpu.flags.zf)
    {
        goto L_0x0048e4ff;
    }
    // 0048e4a5  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048e4aa  b80c445600             -mov eax, 0x56440c
    cpu.eax = 5653516 /*0x56440c*/;
    // 0048e4af  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e4b1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048e4b3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048e4b5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048e4bc  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048e4be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e4c0  7e3d                   -jle 0x48e4ff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e4ff;
    }
    // 0048e4c2  bef8435600             -mov esi, 0x5643f8
    cpu.esi = 5653496 /*0x5643f8*/;
    // 0048e4c7  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048e4ca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e4cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e4cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e4cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e4ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e4cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e4d1  7e28                   -jle 0x48e4fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e4fb;
    }
    // 0048e4d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048e4d8:
    // 0048e4d8  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048e4df  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048e4e5  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048e4eb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e4f0  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048e4f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e4fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e4fb:
    // 0048e4fb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048e4fd  ebd9                   -jmp 0x48e4d8
    goto L_0x0048e4d8;
L_0x0048e4ff:
    // 0048e4ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e501  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0048e507  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e508  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e509  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e50a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e50b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e50c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e50c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e50d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e50e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e50f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e510  81ecb0000000           -sub esp, 0xb0
    (cpu.esp) -= x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 0048e516  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e518  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048e51a  899c24ac000000         -mov dword ptr [esp + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 0048e521  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e526  e8c1fcffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e52b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e52d  7461                   -je 0x48e590
    if (cpu.flags.zf)
    {
        goto L_0x0048e590;
    }
    // 0048e52f  c70424716572ea         -mov dword ptr [esp], 0xea726571
    app->getMemory<x86::reg32>(cpu.esp) = 3933365617 /*0xea726571*/;
    // 0048e536  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048e538  7451                   -je 0x48e58b
    if (cpu.flags.zf)
    {
        goto L_0x0048e58b;
    }
L_0x0048e53a:
    // 0048e53a  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e53e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e543  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e544  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e545  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e546  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e547  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e548  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 0048e54d  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e551  8db58c000000           -lea esi, [ebp + 0x8c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0048e557  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e559  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e55b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e55c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e55d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e55e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e55f  e870faffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e564  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e566  7428                   -je 0x48e590
    if (cpu.flags.zf)
    {
        goto L_0x0048e590;
    }
    // 0048e568  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0048e56d  8bbc24ac000000         -mov edi, dword ptr [esp + 0xac]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048e574  be1c445600             -mov esi, 0x56441c
    cpu.esi = 5653532 /*0x56441c*/;
    // 0048e579  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e57e  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e580  81c4b0000000           +add esp, 0xb0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(176 /*0xb0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e586  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e587  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e588  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e589  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e58a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e58b:
    // 0048e58b  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048e58e  ebaa                   -jmp 0x48e53a
    goto L_0x0048e53a;
L_0x0048e590:
    // 0048e590  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e592  81c4b0000000           -add esp, 0xb0
    (cpu.esp) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 0048e598  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e599  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e59a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e59b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e59c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e5a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e5a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e5a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e5a3  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0048e5a9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e5ab  899424ac000000         -mov dword ptr [esp + 0xac], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.edx;
    // 0048e5b2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048e5b4  898c24b0000000         -mov dword ptr [esp + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 0048e5bb  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e5c2  7405                   -je 0x48e5c9
    if (cpu.flags.zf)
    {
        goto L_0x0048e5c9;
    }
    // 0048e5c4  e87b020000             -call 0x48e844
    cpu.esp -= 4;
    sub_48e844(app, cpu);
    if (cpu.terminate) return;
L_0x0048e5c9:
    // 0048e5c9  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e5ce  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e5d0  e817fcffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e5d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e5d7  0f84e6000000           -je 0x48e6c3
    if (cpu.flags.zf)
    {
        goto L_0x0048e6c3;
    }
    // 0048e5dd  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 0048e5e2  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048e5e6  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048e5eb  e82cbaffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048e5f0  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048e5f4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048e5f6  e8e17effff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048e5fb  833d68bb4d0000         +cmp dword ptr [0x4dbb68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094248) /* 0x4dbb68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e602  0f849e000000           -je 0x48e6a6
    if (cpu.flags.zf)
    {
        goto L_0x0048e6a6;
    }
    // 0048e608  833d64bb4d0000         +cmp dword ptr [0x4dbb64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094244) /* 0x4dbb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e60f  0f8487000000           -je 0x48e69c
    if (cpu.flags.zf)
    {
        goto L_0x0048e69c;
    }
    // 0048e615  b8617472ea             -mov eax, 0xea727461
    cpu.eax = 3933369441 /*0xea727461*/;
L_0x0048e61a:
    // 0048e61a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048e61d  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0048e622  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048e626  8bb424ac000000         -mov esi, dword ptr [esp + 0xac]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048e62d  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 0048e632  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e634  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e636  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e63a  8db58c000000           -lea esi, [ebp + 0x8c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0048e640  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e642  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e647  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e648  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e649  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e64a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e64b  e884f9ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e650  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e652  746f                   -je 0x48e6c3
    if (cpu.flags.zf)
    {
        goto L_0x0048e6c3;
    }
    // 0048e654  813df4435600636564ea   +cmp dword ptr [0x5643f4], 0xea646563
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e65e  7563                   -jne 0x48e6c3
    if (!cpu.flags.zf)
    {
        goto L_0x0048e6c3;
    }
    // 0048e660  bef8435600             -mov esi, 0x5643f8
    cpu.esi = 5653496 /*0x5643f8*/;
    // 0048e665  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048e668  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e669  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e66a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e66b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e66c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e66d  c785a000000001000000   -mov dword ptr [ebp + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 0048e677  8b85a0000000           -mov eax, dword ptr [ebp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
    // 0048e67d  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048e683  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048e68a  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048e68d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e692  81c4b4000000           +add esp, 0xb4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(180 /*0xb4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e698  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e699  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e69a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e69b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e69c:
    // 0048e69c  b861776eea             -mov eax, 0xea6e7761
    cpu.eax = 3933108065 /*0xea6e7761*/;
    // 0048e6a1  e974ffffff             -jmp 0x48e61a
    goto L_0x0048e61a;
L_0x0048e6a6:
    // 0048e6a6  833d64bb4d0000         +cmp dword ptr [0x4dbb64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094244) /* 0x4dbb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e6ad  740a                   -je 0x48e6b9
    if (cpu.flags.zf)
    {
        goto L_0x0048e6b9;
    }
    // 0048e6af  b8647472ea             -mov eax, 0xea727464
    cpu.eax = 3933369444 /*0xea727464*/;
    // 0048e6b4  e961ffffff             -jmp 0x48e61a
    goto L_0x0048e61a;
L_0x0048e6b9:
    // 0048e6b9  b877656eea             -mov eax, 0xea6e6577
    cpu.eax = 3933103479 /*0xea6e6577*/;
    // 0048e6be  e957ffffff             -jmp 0x48e61a
    goto L_0x0048e61a;
L_0x0048e6c3:
    // 0048e6c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e6c5  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0048e6cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48e6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e6d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e6d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e6d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e6d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e6d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e6d5  81ecac000000           -sub esp, 0xac
    (cpu.esp) -= x86::reg32(x86::sreg32(172 /*0xac*/));
    // 0048e6db  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e6dd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048e6df  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e6e4  e803fbffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e6e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e6eb  750e                   -jne 0x48e6fb
    if (!cpu.flags.zf)
    {
        goto L_0x0048e6fb;
    }
L_0x0048e6ed:
    // 0048e6ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e6ef  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 0048e6f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e6fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e6fb:
    // 0048e6fb  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 0048e700  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048e702  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 0048e707  e810b9ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048e70c  ba647075ea             -mov edx, 0xea757064
    cpu.edx = 3933565028 /*0xea757064*/;
    // 0048e711  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048e715  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048e718  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 0048e71d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e71f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e721  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e725  8db58c000000           -lea esi, [ebp + 0x8c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 0048e72b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e72d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e732  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e733  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e734  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e735  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e736  e899f8ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e73b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e73d  74ae                   -je 0x48e6ed
    if (cpu.flags.zf)
    {
        goto L_0x0048e6ed;
    }
    // 0048e73f  813df4435600636564ea   +cmp dword ptr [0x5643f4], 0xea646563
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e749  75a2                   -jne 0x48e6ed
    if (!cpu.flags.zf)
    {
        goto L_0x0048e6ed;
    }
    // 0048e74b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e750  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 0048e756  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e757  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e758  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e759  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e75a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e75b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e75c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e75c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e75d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e75e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e75f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e760  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e761  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048e764  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e766  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048e76a  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 0048e76e  750b                   -jne 0x48e77b
    if (!cpu.flags.zf)
    {
        goto L_0x0048e77b;
    }
L_0x0048e770:
    // 0048e770  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e772  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048e775  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e776  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e777  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e778  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e779  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e77a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e77b:
    // 0048e77b  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e780  e867faffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e785  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e787  74e7                   -je 0x48e770
    if (cpu.flags.zf)
    {
        goto L_0x0048e770;
    }
    // 0048e789  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e78d  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048e790  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e794  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e795  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e796  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e797  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e798  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e799  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048e79b  7549                   -jne 0x48e7e6
    if (!cpu.flags.zf)
    {
        goto L_0x0048e7e6;
    }
    // 0048e79d  c70424746873ea         -mov dword ptr [esp], 0xea736874
    app->getMemory<x86::reg32>(cpu.esp) = 3933431924 /*0xea736874*/;
L_0x0048e7a4:
    // 0048e7a4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e7a9  bb18000000             -mov ebx, 0x18
    cpu.ebx = 24 /*0x18*/;
    // 0048e7ae  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e7b0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e7b2  e81df8ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e7b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e7b9  74b5                   -je 0x48e770
    if (cpu.flags.zf)
    {
        goto L_0x0048e770;
    }
    // 0048e7bb  837c241800             +cmp dword ptr [esp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e7c0  7416                   -je 0x48e7d8
    if (cpu.flags.zf)
    {
        goto L_0x0048e7d8;
    }
    // 0048e7c2  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0048e7cc  8b85a0000000           -mov eax, dword ptr [ebp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
    // 0048e7d2  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
L_0x0048e7d8:
    // 0048e7d8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e7dd  83c41c                 +add esp, 0x1c
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
    // 0048e7e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e7e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e7e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e7e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e7e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e7e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e7e6:
    // 0048e7e6  c70424656964ea         -mov dword ptr [esp], 0xea646965
    app->getMemory<x86::reg32>(cpu.esp) = 3932449125 /*0xea646965*/;
    // 0048e7ed  ebb5                   -jmp 0x48e7a4
    goto L_0x0048e7a4;
}

/* align: skip 0x90 */
void Application::sub_48e7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e7f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e7f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e7f2  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048e7f5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e7f7  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e7fc  e8ebf9ffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e801  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e803  7506                   -jne 0x48e80b
    if (!cpu.flags.zf)
    {
        goto L_0x0048e80b;
    }
    // 0048e805  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048e808  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e809  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e80a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e80b:
    // 0048e80b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e80c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e80d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e80e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e80f  ba776c61ea             -mov edx, 0xea616c77
    cpu.edx = 3932253303 /*0xea616c77*/;
    // 0048e814  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048e818  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e81d  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048e821  bb18000000             -mov ebx, 0x18
    cpu.ebx = 24 /*0x18*/;
    // 0048e826  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048e829  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e82b  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e82f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e830  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e831  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e832  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e833  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e834  e89bf7ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e839  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e83a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e83b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e83c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e83d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048e840  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e841  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48e844(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e844  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e845  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e846  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e847  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e848  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e849  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e84a  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048e84d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048e84f  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e854  e893f9ffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e859  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e85b  750c                   -jne 0x48e869
    if (!cpu.flags.zf)
    {
        goto L_0x0048e869;
    }
L_0x0048e85d:
    // 0048e85d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e85f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048e862  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e863  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e864  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e865  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e866  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e867  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e868  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e869:
    // 0048e869  ba657962ea             -mov edx, 0xea627965
    cpu.edx = 3932322149 /*0xea627965*/;
    // 0048e86e  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e872  bb18000000             -mov ebx, 0x18
    cpu.ebx = 24 /*0x18*/;
    // 0048e877  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048e87a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048e87c  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048e87f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e881  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e883  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e884  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e885  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e886  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e887  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e888  e847f7ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e88d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e88f  74cc                   -je 0x48e85d
    if (cpu.flags.zf)
    {
        goto L_0x0048e85d;
    }
    // 0048e891  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0048e89b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e8a0  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 0048e8aa  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048e8ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e8b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e8b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e8b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e8b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e8b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e8b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e8b8  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0048e8be  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 0048e8c5  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 0048e8cc  899c24f8000000         -mov dword ptr [esp + 0xf8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */) = cpu.ebx;
    // 0048e8d3  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048e8d8  e80ff9ffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048e8dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e8df  744f                   -je 0x48e930
    if (cpu.flags.zf)
    {
        goto L_0x0048e930;
    }
    // 0048e8e1  ba716572ea             -mov edx, 0xea726571
    cpu.edx = 3933365617 /*0xea726571*/;
    // 0048e8e6  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048e8ed  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048e8f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048e8f2  7449                   -je 0x48e93d
    if (cpu.flags.zf)
    {
        goto L_0x0048e93d;
    }
    // 0048e8f4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0048e8f6:
    // 0048e8f6  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e8fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e8fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e8fc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e8fd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e8fe  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e8ff  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e904  8bb42404010000         -mov esi, dword ptr [esp + 0x104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048e90b  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 0048e910  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e914  8db68c000000           -lea esi, [esi + 0x8c]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048e91a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e91c  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048e923  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e924  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e925  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e926  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e927  e8a8f6ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e92c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e92e  7519                   -jne 0x48e949
    if (!cpu.flags.zf)
    {
        goto L_0x0048e949;
    }
L_0x0048e930:
    // 0048e930  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048e932:
    // 0048e932  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0048e938  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e939  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e93a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e93b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e93c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e93d:
    // 0048e93d  8bb42404010000         -mov esi, dword ptr [esp + 0x104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048e944  83c61c                 +add esi, 0x1c
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e947  ebad                   -jmp 0x48e8f6
    goto L_0x0048e8f6;
L_0x0048e949:
    // 0048e949  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048e950  b860445600             -mov eax, 0x564460
    cpu.eax = 5653600 /*0x564460*/;
    // 0048e955  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e957  be746567ea             -mov esi, 0xea676574
    cpu.esi = 3932644724 /*0xea676574*/;
    // 0048e95c  899c24ec000000         -mov dword ptr [esp + 0xec], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */) = cpu.ebx;
    // 0048e963  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 0048e968  8bbc2400010000         -mov edi, dword ptr [esp + 0x100]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048e96f  e80cc0ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048e974  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0048e977  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048e979  0f8464010000           -je 0x48eae3
    if (cpu.flags.zf)
    {
        goto L_0x0048eae3;
    }
    // 0048e97f  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0048e981:
    // 0048e981  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048e985  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048e98a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048e98f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e993  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048e998  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e999  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e99a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e99b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e99c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e99d  e8b2d6ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048e9a2  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 0048e9a7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048e9a9  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048e9b0  e81ff6ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048e9b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e9b7  7410                   -je 0x48e9c9
    if (cpu.flags.zf)
    {
        goto L_0x0048e9c9;
    }
    // 0048e9b9  813df4435600796c70ea   +cmp dword ptr [0x5643f4], 0xea706c79
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e9c3  0f8429010000           -je 0x48eaf2
    if (cpu.flags.zf)
    {
        goto L_0x0048eaf2;
    }
L_0x0048e9c9:
    // 0048e9c9  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048e9d0  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048e9d3  898424f4000000         -mov dword ptr [esp + 0xf4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(244) /* 0xf4 */) = cpu.eax;
    // 0048e9da  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048e9dc  898424f0000000         -mov dword ptr [esp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
L_0x0048e9e3:
    // 0048e9e3  8b8424f0000000         -mov eax, dword ptr [esp + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 0048e9ea  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0048e9ef  898424fc000000         -mov dword ptr [esp + 0xfc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.eax;
L_0x0048e9f6:
    // 0048e9f6  8b8424fc000000         -mov eax, dword ptr [esp + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0048e9fd  85ac04ac000000         -test dword ptr [esp + eax + 0xac], ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */ + cpu.eax * 1) & cpu.ebp));
    // 0048ea04  0f8499000000           -je 0x48eaa3
    if (cpu.flags.zf)
    {
        goto L_0x0048eaa3;
    }
    // 0048ea0a  b9746567ea             -mov ecx, 0xea676574
    cpu.ecx = 3932644724 /*0xea676574*/;
    // 0048ea0f  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048ea16  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048ea19  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048ea1b  0f8416010000           -je 0x48eb37
    if (cpu.flags.zf)
    {
        goto L_0x0048eb37;
    }
    // 0048ea21  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0048ea23:
    // 0048ea23  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ea27  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048ea2c  8b9424ec000000         -mov edx, dword ptr [esp + 0xec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */);
    // 0048ea33  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ea37  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048ea3c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ea3d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ea3e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ea3f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ea40  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048ea41  e80ed6ffff             -call 0x48c054
    cpu.esp -= 4;
    sub_48c054(app, cpu);
    if (cpu.terminate) return;
    // 0048ea46  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 0048ea4b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048ea4d  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048ea54  e87bf5ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048ea59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ea5b  7446                   -je 0x48eaa3
    if (cpu.flags.zf)
    {
        goto L_0x0048eaa3;
    }
    // 0048ea5d  813df4435600796c70ea   +cmp dword ptr [0x5643f4], 0xea706c79
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ea67  753a                   -jne 0x48eaa3
    if (!cpu.flags.zf)
    {
        goto L_0x0048eaa3;
    }
    // 0048ea69  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ea6e  8d8424ec000000         -lea eax, [esp + 0xec]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(236) /* 0xec */);
    // 0048ea75  ba10445600             -mov edx, 0x564410
    cpu.edx = 5653520 /*0x564410*/;
    // 0048ea7a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ea7c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ea7e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ea80  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ea87  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ea89  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ea8b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ea8d  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048ea94  ff9424f8000000         -call dword ptr [esp + 0xf8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ea9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ea9d  0f848ffeffff           -je 0x48e932
    if (cpu.flags.zf)
    {
        goto L_0x0048e932;
    }
L_0x0048eaa3:
    // 0048eaa3  8bbc24ec000000         -mov edi, dword ptr [esp + 0xec]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */);
    // 0048eaaa  47                     -inc edi
    (cpu.edi)++;
    // 0048eaab  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048eaad  89bc24ec000000         -mov dword ptr [esp + 0xec], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */) = cpu.edi;
    // 0048eab4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048eab6  0f853affffff           -jne 0x48e9f6
    if (!cpu.flags.zf)
    {
        goto L_0x0048e9f6;
    }
    // 0048eabc  8bac24f0000000         -mov ebp, dword ptr [esp + 0xf0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 0048eac3  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048eac6  89ac24f0000000         -mov dword ptr [esp + 0xf0], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */) = cpu.ebp;
    // 0048eacd  83fd40                 +cmp ebp, 0x40
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ead0  0f8c0dffffff           -jl 0x48e9e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e9e3;
    }
    // 0048ead6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ead8  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0048eade  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eadf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eae0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eae1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eae2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eae3:
    // 0048eae3  8bb42404010000         -mov esi, dword ptr [esp + 0x104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048eaea  83c61c                 +add esi, 0x1c
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048eaed  e98ffeffff             -jmp 0x48e981
    goto L_0x0048e981;
L_0x0048eaf2:
    // 0048eaf2  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048eaf7  8d8424ec000000         -lea eax, [esp + 0xec]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(236) /* 0xec */);
    // 0048eafe  ba10445600             -mov edx, 0x564410
    cpu.edx = 5653520 /*0x564410*/;
    // 0048eb03  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048eb05  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048eb07  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048eb09  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048eb10  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048eb12  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048eb14  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb16  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048eb1d  ff9424f8000000         -call dword ptr [esp + 0xf8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048eb24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048eb26  0f859dfeffff           -jne 0x48e9c9
    if (!cpu.flags.zf)
    {
        goto L_0x0048e9c9;
    }
    // 0048eb2c  81c408010000           +add esp, 0x108
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(264 /*0x108*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048eb32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eb37:
    // 0048eb37  8bb424f4000000         -mov esi, dword ptr [esp + 0xf4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(244) /* 0xf4 */);
    // 0048eb3e  e9e0feffff             -jmp 0x48ea23
    goto L_0x0048ea23;
}

/* align: skip 0x90 */
void Application::sub_48eb44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eb44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eb45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048eb46  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048eb49  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048eb4b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048eb4d  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048eb52  e895f6ffff             -call 0x48e1ec
    cpu.esp -= 4;
    sub_48e1ec(app, cpu);
    if (cpu.terminate) return;
    // 0048eb57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048eb59  7506                   -jne 0x48eb61
    if (!cpu.flags.zf)
    {
        goto L_0x0048eb61;
    }
    // 0048eb5b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048eb5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eb61:
    // 0048eb61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048eb62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048eb63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eb64  c744240c766d72ea       -mov dword ptr [esp + 0xc], 0xea726d76
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 3933367670 /*0xea726d76*/;
    // 0048eb6c  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048eb70  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048eb73  bb2c000000             -mov ebx, 0x2c
    cpu.ebx = 44 /*0x2c*/;
    // 0048eb78  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb79  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb7a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb7b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb7c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb7d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048eb7f  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048eb83  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048eb85  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048eb89  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048eb8e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb8f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb90  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb91  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb92  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048eb93  e83cf4ffff             -call 0x48dfd4
    cpu.esp -= 4;
    sub_48dfd4(app, cpu);
    if (cpu.terminate) return;
    // 0048eb98  3d6b6361ea             +cmp eax, 0xea61636b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932250987 /*0xea61636b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eb9d  750e                   -jne 0x48ebad
    if (!cpu.flags.zf)
    {
        goto L_0x0048ebad;
    }
    // 0048eb9f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048eba4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eba5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eba6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eba7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048ebaa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ebad:
    // 0048ebad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ebaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebb2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048ebb5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ebb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ebb8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ebba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ebbc  7407                   -je 0x48ebc5
    if (cpu.flags.zf)
    {
        goto L_0x0048ebc5;
    }
    // 0048ebbe  c7420801000000         -mov dword ptr [edx + 8], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0048ebc5:
    // 0048ebc5  ba504b4d00             -mov edx, 0x4d4b50
    cpu.edx = 5065552 /*0x4d4b50*/;
    // 0048ebca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ebcb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048ebcd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ebcf  e8b4b5ffff             -call 0x48a188
    cpu.esp -= 4;
    sub_48a188(app, cpu);
    if (cpu.terminate) return;
    // 0048ebd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48ebe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ebe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ebe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ebe2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ebe3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ebe5  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0048ebe8  baeafb0000             -mov edx, 0xfbea
    cpu.edx = 64490 /*0xfbea*/;
    // 0048ebed  39f0                   +cmp eax, esi
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
    // 0048ebef  7323                   -jae 0x48ec14
    if (!cpu.flags.cf)
    {
        goto L_0x0048ec14;
    }
L_0x0048ebf1:
    // 0048ebf1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ebf3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ebf5  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0048ebf7  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0048ebf9  31d9                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ebfb  668b0c4dacbb4d00       -mov cx, word ptr [ecx*2 + 0x4dbbac]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5094316) /* 0x4dbbac */ + cpu.ecx * 2);
    // 0048ec03  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048ec09  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0048ec0c  40                     -inc eax
    (cpu.eax)++;
    // 0048ec0d  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ec0f  39f0                   +cmp eax, esi
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
    // 0048ec11  72de                   -jb 0x48ebf1
    if (cpu.flags.cf)
    {
        goto L_0x0048ebf1;
    }
    // 0048ec13  90                     -nop 
    ;
L_0x0048ec14:
    // 0048ec14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ec16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48ec20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ec20  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048ec26  833db0bd4d0002         +cmp dword ptr [0x4dbdb0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094832) /* 0x4dbdb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ec2d  7c21                   -jl 0x48ec50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ec50;
    }
    // 0048ec2f  833dacbd4d0000         +cmp dword ptr [0x4dbdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ec36  750a                   -jne 0x48ec42
    if (!cpu.flags.zf)
    {
        goto L_0x0048ec42;
    }
    // 0048ec38  e8bbb2ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048ec3d  a3acbd4d00             -mov dword ptr [0x4dbdac], eax
    app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */) = cpu.eax;
L_0x0048ec42:
    // 0048ec42  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048ec47  e8fcb2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048ec4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ec4e  7507                   -jne 0x48ec57
    if (!cpu.flags.zf)
    {
        goto L_0x0048ec57;
    }
L_0x0048ec50:
    // 0048ec50  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048ec56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ec57:
    // 0048ec57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ec58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ec59  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0048ec60  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0048ec67  8b942410010000         -mov edx, dword ptr [esp + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 0048ec6e  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 0048ec75  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ec79  e806540100             -call 0x4a4084
    cpu.esp -= 4;
    sub_4a4084(app, cpu);
    if (cpu.terminate) return;
    // 0048ec7e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ec80  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ec84  899c2408010000         -mov dword ptr [esp + 0x108], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.ebx;
    // 0048ec8b  e8e0000000             -call 0x48ed70
    cpu.esp -= 4;
    sub_48ed70(app, cpu);
    if (cpu.terminate) return;
    // 0048ec90  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048ec95  e8c6b2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048ec9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ec9c  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048eca2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48eca4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eca4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eca5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048eca6  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048ecac  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 0048ecb3  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0048ecba  833db0bd4d0002         +cmp dword ptr [0x4dbdb0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094832) /* 0x4dbdb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ecc1  0f8c8b000000           -jl 0x48ed52
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ed52;
    }
    // 0048ecc7  833dacbd4d0000         +cmp dword ptr [0x4dbdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ecce  750a                   -jne 0x48ecda
    if (!cpu.flags.zf)
    {
        goto L_0x0048ecda;
    }
    // 0048ecd0  e823b2ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048ecd5  a3acbd4d00             -mov dword ptr [0x4dbdac], eax
    app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */) = cpu.eax;
L_0x0048ecda:
    // 0048ecda  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048ecdf  e864b2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048ece4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ece6  746a                   -je 0x48ed52
    if (cpu.flags.zf)
    {
        goto L_0x0048ed52;
    }
    // 0048ece8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048ecea  7c23                   -jl 0x48ed0f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ed0f;
    }
    // 0048ecec  83fb50                 +cmp ebx, 0x50
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ecef  7d1e                   -jge 0x48ed0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed0f;
    }
    // 0048ecf1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ecf3  7c1a                   -jl 0x48ed0f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ed0f;
    }
    // 0048ecf5  83fa19                 +cmp edx, 0x19
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ecf8  7d15                   -jge 0x48ed0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed0f;
    }
    // 0048ecfa  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048ed01  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ed03  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0048ed06  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ed08  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ed0a  a3bcbd4d00             -mov dword ptr [0x4dbdbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */) = cpu.eax;
L_0x0048ed0f:
    // 0048ed0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ed10  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0048ed17  8d9c2404010000         -lea ebx, [esp + 0x104]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048ed1e  8b94241c010000         -mov edx, dword ptr [esp + 0x11c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0048ed25  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 0048ed2c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ed30  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048ed32  e84d530100             -call 0x4a4084
    cpu.esp -= 4;
    sub_4a4084(app, cpu);
    if (cpu.terminate) return;
    // 0048ed37  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ed3b  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 0048ed42  e829000000             -call 0x48ed70
    cpu.esp -= 4;
    sub_48ed70(app, cpu);
    if (cpu.terminate) return;
    // 0048ed47  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048ed4c  e80fb2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048ed51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048ed52:
    // 0048ed52  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048ed58  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ed70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048ed70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ed71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ed72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ed73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ed74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ed75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ed76  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ed79  8b1dbcbd4d00           -mov ebx, dword ptr [0x4dbdbc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */);
    // 0048ed7f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ed81  833db0bd4d0002         +cmp dword ptr [0x4dbdb0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094832) /* 0x4dbdb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ed88  7d10                   -jge 0x48ed9a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed9a;
    }
L_0x0048ed8a:
    // 0048ed8a  8b1dbcbd4d00           -mov ebx, dword ptr [0x4dbdbc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */);
    // 0048ed90  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ed93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ed99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ed9a:
    // 0048ed9a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048ed9c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ed9e  49                     -dec ecx
    (cpu.ecx)--;
    // 0048ed9f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048eda1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048eda3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048eda5  49                     -dec ecx
    (cpu.ecx)--;
    // 0048eda6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048eda8  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048edab  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048edad  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0048edaf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048edb1  7ed7                   -jle 0x48ed8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ed8a;
    }
L_0x0048edb3:
    // 0048edb3  8b1dbcbd4d00           -mov ebx, dword ptr [0x4dbdbc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */);
    // 0048edb9  80f90e                 +cmp cl, 0xe
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(14 /*0xe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048edbc  7441                   -je 0x48edff
    if (cpu.flags.zf)
    {
        goto L_0x0048edff;
    }
    // 0048edbe  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0048edc0  80f920                 +cmp cl, 0x20
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
    // 0048edc3  7245                   -jb 0x48ee0a
    if (cpu.flags.cf)
    {
        goto L_0x0048ee0a;
    }
    // 0048edc5  e8fa000000             -call 0x48eec4
    cpu.esp -= 4;
    sub_48eec4(app, cpu);
    if (cpu.terminate) return;
    // 0048edca  8b1dbcbd4d00           -mov ebx, dword ptr [0x4dbdbc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */);
    // 0048edd0  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0048edd2  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0048edd4  a0c1bd4d00             -mov al, byte ptr [0x4dbdc1]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5094849) /* 0x4dbdc1 */);
    // 0048edd9  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0048eddb  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048edde  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0048ede1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ede3  8b15b8bd4d00           -mov edx, dword ptr [0x4dbdb8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094840) /* 0x4dbdb8 */);
    // 0048ede9  6689441afe             -mov word ptr [edx + ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */ + cpu.ebx * 1) = cpu.ax;
L_0x0048edee:
    // 0048edee  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0048edf1  46                     -inc esi
    (cpu.esi)++;
    // 0048edf2  47                     -inc edi
    (cpu.edi)++;
    // 0048edf3  891dbcbd4d00           -mov dword ptr [0x4dbdbc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */) = cpu.ebx;
    // 0048edf9  39ef                   +cmp edi, ebp
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
    // 0048edfb  7d8d                   -jge 0x48ed8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed8a;
    }
    // 0048edfd  ebb4                   -jmp 0x48edb3
    goto L_0x0048edb3;
L_0x0048edff:
    // 0048edff  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048ee01  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 0048ee03  a2c1bd4d00             -mov byte ptr [0x4dbdc1], al
    app->getMemory<x86::reg8>(x86::reg32(5094849) /* 0x4dbdc1 */) = cpu.al;
    // 0048ee08  ebe4                   -jmp 0x48edee
    goto L_0x0048edee;
L_0x0048ee0a:
    // 0048ee0a  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0048ee0c  80ea08                 -sub dl, 8
    (cpu.dl) -= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0048ee0f  80fa04                 +cmp dl, 4
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048ee12  77da                   -ja 0x48edee
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048edee;
    }
    // 0048ee14  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048ee16  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0048ee18  ff24855ced4800         -jmp dword ptr [eax*4 + 0x48ed5c]
    cpu.ip = app->getMemory<x86::reg32>(4779356 + cpu.eax * 4); goto dynamic_jump;
  case 0x0048ee1f:
    // 0048ee1f  83fb02                 +cmp ebx, 2
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
    // 0048ee22  7cca                   -jl 0x48edee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048edee;
    }
    // 0048ee24  83eb02                 +sub ebx, 2
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
    // 0048ee27  ebc5                   -jmp 0x48edee
    goto L_0x0048edee;
  case 0x0048ee29:
    // 0048ee29  803dc2bd4d0001         +cmp byte ptr [0x4dbdc2], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5094850) /* 0x4dbdc2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048ee30  76bc                   -jbe 0x48edee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048edee;
    }
    // 0048ee32  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 0048ee37  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ee39  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ee3b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ee3e  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ee40  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048ee43  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ee45  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048ee47  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ee49  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ee4c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ee4e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048ee50  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ee52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ee54  8a1dc2bd4d00           -mov bl, byte ptr [0x4dbdc2]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5094850) /* 0x4dbdc2 */);
    // 0048ee5a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ee5d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ee5f  40                     -inc eax
    (cpu.eax)++;
    // 0048ee60  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ee63  01c0                   +add eax, eax
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
    // 0048ee65  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0048ee68  eb84                   -jmp 0x48edee
    goto L_0x0048edee;
  case 0x0048ee6a:
    // 0048ee6a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ee6c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ee6e  bba0000000             -mov ebx, 0xa0
    cpu.ebx = 160 /*0xa0*/;
    // 0048ee73  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ee76  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ee78  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048ee7b  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 0048ee81  891dbcbd4d00           -mov dword ptr [0x4dbdbc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */) = cpu.ebx;
    // 0048ee87  e838000000             -call 0x48eec4
    cpu.esp -= 4;
    sub_48eec4(app, cpu);
    if (cpu.terminate) return;
    // 0048ee8c  8b1dbcbd4d00           -mov ebx, dword ptr [0x4dbdbc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */);
    // 0048ee92  e957ffffff             -jmp 0x48edee
    goto L_0x0048edee;
  case 0x0048ee97:
    // 0048ee97  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ee99  8a1dc0bd4d00           -mov bl, byte ptr [0x4dbdc0]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5094848) /* 0x4dbdc0 */);
    // 0048ee9f  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 0048eea5  e944ffffff             -jmp 0x48edee
    goto L_0x0048edee;
  case 0x0048eeaa:
    // 0048eeaa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048eeac  e897000000             -call 0x48ef48
    cpu.esp -= 4;
    sub_48ef48(app, cpu);
    if (cpu.terminate) return;
    // 0048eeb1  8a1dc0bd4d00           -mov bl, byte ptr [0x4dbdc0]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5094848) /* 0x4dbdc0 */);
    // 0048eeb7  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 0048eebd  e92cffffff             -jmp 0x48edee
    goto L_0x0048edee;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48eec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048eec4  813dbcbd4d00a00f0000   +cmp dword ptr [0x4dbdbc], 0xfa0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eece  7d01                   -jge 0x48eed1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eed1;
    }
    // 0048eed0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eed1:
    // 0048eed1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048eed2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048eed3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048eed4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eed5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048eed6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048eed8  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 0048eedd  8a15c0bd4d00           -mov dl, byte ptr [0x4dbdc0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5094848) /* 0x4dbdc0 */);
    // 0048eee3  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048eee5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048eeec  49                     -dec ecx
    (cpu.ecx)--;
    // 0048eeed  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048eeef  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0048eef6  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048eef9  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eefb  8b0db8bd4d00           -mov ecx, dword ptr [0x4dbdb8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094840) /* 0x4dbdb8 */);
    // 0048ef01  42                     -inc edx
    (cpu.edx)++;
    // 0048ef02  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ef04  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048ef0b  8b35b8bd4d00           -mov esi, dword ptr [0x4dbdb8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094840) /* 0x4dbdb8 */);
    // 0048ef11  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ef13  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 0048ef16  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048ef19  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048ef1b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048ef1d  e85ebaffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048ef22  a1b8bd4d00             -mov eax, dword ptr [0x4dbdb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094840) /* 0x4dbdb8 */);
    // 0048ef27  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 0048ef2c  05000f0000             -add eax, 0xf00
    (cpu.eax) += x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048ef31  bf000f0000             -mov edi, 0xf00
    cpu.edi = 3840 /*0xf00*/;
    // 0048ef36  e8e1b0ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048ef3b  893dbcbd4d00           -mov dword ptr [0x4dbdbc], edi
    app->getMemory<x86::reg32>(x86::reg32(5094844) /* 0x4dbdbc */) = cpu.edi;
    // 0048ef41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ef46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ef48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ef48  833db0bd4d0002         +cmp dword ptr [0x4dbdb0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094832) /* 0x4dbdb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ef4f  7c46                   -jl 0x48ef97
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ef97;
    }
    // 0048ef51  833dacbd4d0000         +cmp dword ptr [0x4dbdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ef58  750a                   -jne 0x48ef64
    if (!cpu.flags.zf)
    {
        goto L_0x0048ef64;
    }
    // 0048ef5a  e899afffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048ef5f  a3acbd4d00             -mov dword ptr [0x4dbdac], eax
    app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */) = cpu.eax;
L_0x0048ef64:
    // 0048ef64  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048ef69  e8daafffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048ef6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ef70  7425                   -je 0x48ef97
    if (cpu.flags.zf)
    {
        goto L_0x0048ef97;
    }
    // 0048ef72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ef73  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048ef75:
    // 0048ef75  8b15b8bd4d00           -mov edx, dword ptr [0x4dbdb8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094840) /* 0x4dbdb8 */);
    // 0048ef7b  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 0048ef82  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ef85  3da00f0000             +cmp eax, 0xfa0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ef8a  7ce9                   -jl 0x48ef75
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ef75;
    }
    // 0048ef8c  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048ef91  e8caafffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048ef96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048ef97:
    // 0048ef97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ef98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ef98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ef99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ef9b  833dacbd4d0000         +cmp dword ptr [0x4dbdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048efa2  750a                   -jne 0x48efae
    if (!cpu.flags.zf)
    {
        goto L_0x0048efae;
    }
    // 0048efa4  e84fafffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048efa9  a3acbd4d00             -mov dword ptr [0x4dbdac], eax
    app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */) = cpu.eax;
L_0x0048efae:
    // 0048efae  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048efb3  e890afffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048efb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048efba  7419                   -je 0x48efd5
    if (cpu.flags.zf)
    {
        goto L_0x0048efd5;
    }
    // 0048efbc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048efbe  7c0b                   -jl 0x48efcb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048efcb;
    }
    // 0048efc0  83fa18                 +cmp edx, 0x18
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048efc3  7f06                   -jg 0x48efcb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048efcb;
    }
    // 0048efc5  8815c0bd4d00           -mov byte ptr [0x4dbdc0], dl
    app->getMemory<x86::reg8>(x86::reg32(5094848) /* 0x4dbdc0 */) = cpu.dl;
L_0x0048efcb:
    // 0048efcb  a1acbd4d00             -mov eax, dword ptr [0x4dbdac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094828) /* 0x4dbdac */);
    // 0048efd0  e88bafffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x0048efd5:
    // 0048efd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048efd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48efd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048efd8  a2c1bd4d00             -mov byte ptr [0x4dbdc1], al
    app->getMemory<x86::reg8>(x86::reg32(5094849) /* 0x4dbdc1 */) = cpu.al;
    // 0048efdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48efe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048efe0  83f801                 +cmp eax, 1
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
    // 0048efe3  7d01                   -jge 0x48efe6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048efe6;
    }
    // 0048efe5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048efe6:
    // 0048efe6  a2c2bd4d00             -mov byte ptr [0x4dbdc2], al
    app->getMemory<x86::reg8>(x86::reg32(5094850) /* 0x4dbdc2 */) = cpu.al;
    // 0048efeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48efec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048efec  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 0048efef  0500000b00             -add eax, 0xb0000
    (cpu.eax) += x86::reg32(x86::sreg32(720896 /*0xb0000*/));
    // 0048eff4  a3b8bd4d00             -mov dword ptr [0x4dbdb8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094840) /* 0x4dbdb8 */) = cpu.eax;
    // 0048eff9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48effc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048effc  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0048efff  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0048f002  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48f010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f010  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f011  ba60014d00             -mov edx, 0x4d0160
    cpu.edx = 5046624 /*0x4d0160*/;
    // 0048f016  e805000000             -call 0x48f020
    cpu.esp -= 4;
    sub_48f020(app, cpu);
    if (cpu.terminate) return;
    // 0048f01b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f01c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f022  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f024  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f026  e865040000             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f02b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f02d  7508                   -jne 0x48f037
    if (!cpu.flags.zf)
    {
        goto L_0x0048f037;
    }
L_0x0048f02f:
    // 0048f02f  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0048f034  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f035  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f036  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f037:
    // 0048f037  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f03d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f03f  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f041  e826020000             -call 0x48f26c
    cpu.esp -= 4;
    sub_48f26c(app, cpu);
    if (cpu.terminate) return;
    // 0048f046  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f048  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f04a  7405                   -je 0x48f051
    if (cpu.flags.zf)
    {
        goto L_0x0048f051;
    }
    // 0048f04c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f04e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f04f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f050  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f051:
    // 0048f051  ba70014d00             -mov edx, 0x4d0170
    cpu.edx = 5046640 /*0x4d0170*/;
    // 0048f056  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f058  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f05a  e831040000             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f05f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f061  74cc                   -je 0x48f02f
    if (cpu.flags.zf)
    {
        goto L_0x0048f02f;
    }
    // 0048f063  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f069  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f06b  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f06d  e8fa010000             -call 0x48f26c
    cpu.esp -= 4;
    sub_48f26c(app, cpu);
    if (cpu.terminate) return;
    // 0048f072  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f074  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f076  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f077  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f078  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f07c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f07c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f07d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f07e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f07f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f081  ba7c014d00             -mov edx, 0x4d017c
    cpu.edx = 5046652 /*0x4d017c*/;
    // 0048f086  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f088  e803040000             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f08d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f08f  7509                   -jne 0x48f09a
    if (!cpu.flags.zf)
    {
        goto L_0x0048f09a;
    }
    // 0048f091  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0048f096  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f097  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f098  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f099  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f09a:
    // 0048f09a  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f0a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f0a2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f0a4  e8c3010000             -call 0x48f26c
    cpu.esp -= 4;
    sub_48f26c(app, cpu);
    if (cpu.terminate) return;
    // 0048f0a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f0b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f0b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f0b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f0b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f0b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f0b5  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0048f0b8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f0ba  be84014d00             -mov esi, 0x4d0184
    cpu.esi = 5046660 /*0x4d0184*/;
    // 0048f0bf  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048f0c1  e8b6ffffff             -call 0x48f07c
    cpu.esp -= 4;
    sub_48f07c(app, cpu);
    if (cpu.terminate) return;
    // 0048f0c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048f0c7:
    // 0048f0c7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f0c9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048f0cb  3c00                   +cmp al, 0
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
    // 0048f0cd  7410                   -je 0x48f0df
    if (cpu.flags.zf)
    {
        goto L_0x0048f0df;
    }
    // 0048f0cf  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048f0d2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f0d5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048f0d8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f0db  3c00                   +cmp al, 0
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
    // 0048f0dd  75e8                   -jne 0x48f0c7
    if (!cpu.flags.zf)
    {
        goto L_0x0048f0c7;
    }
L_0x0048f0df:
    // 0048f0df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f0e0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048f0e2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048f0e4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f0e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f0ea  2bc9                   +sub ecx, ecx
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
    // 0048f0ec  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048f0ed  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048f0ef  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f0f1  4f                     -dec edi
    (cpu.edi)--;
L_0x0048f0f2:
    // 0048f0f2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f0f4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048f0f6  3c00                   +cmp al, 0
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
    // 0048f0f8  7410                   -je 0x48f10a
    if (cpu.flags.zf)
    {
        goto L_0x0048f10a;
    }
    // 0048f0fa  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048f0fd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f100  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048f103  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f106  3c00                   +cmp al, 0
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
    // 0048f108  75e8                   -jne 0x48f0f2
    if (!cpu.flags.zf)
    {
        goto L_0x0048f0f2;
    }
L_0x0048f10a:
    // 0048f10a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f10b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048f10d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f10f  e87c030000             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f114  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0048f117  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f118  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f119  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f11a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f11b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f11c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f120  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f121  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f122  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f123  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0048f126  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f128  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048f12a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048f12c  e84bffffff             -call 0x48f07c
    cpu.esp -= 4;
    sub_48f07c(app, cpu);
    if (cpu.terminate) return;
    // 0048f131  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048f132:
    // 0048f132  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f134  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048f136  3c00                   +cmp al, 0
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
    // 0048f138  7410                   -je 0x48f14a
    if (cpu.flags.zf)
    {
        goto L_0x0048f14a;
    }
    // 0048f13a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048f13d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f140  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048f143  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f146  3c00                   +cmp al, 0
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
    // 0048f148  75e8                   -jne 0x48f132
    if (!cpu.flags.zf)
    {
        goto L_0x0048f132;
    }
L_0x0048f14a:
    // 0048f14a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f14b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f14d  7464                   -je 0x48f1b3
    if (cpu.flags.zf)
    {
        goto L_0x0048f1b3;
    }
    // 0048f14f  be88014d00             -mov esi, 0x4d0188
    cpu.esi = 5046664 /*0x4d0188*/;
L_0x0048f154:
    // 0048f154  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048f156  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f157  2bc9                   +sub ecx, ecx
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
    // 0048f159  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048f15a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048f15c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f15e  4f                     -dec edi
    (cpu.edi)--;
L_0x0048f15f:
    // 0048f15f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f161  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048f163  3c00                   +cmp al, 0
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
    // 0048f165  7410                   -je 0x48f177
    if (cpu.flags.zf)
    {
        goto L_0x0048f177;
    }
    // 0048f167  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048f16a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f16d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048f170  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f173  3c00                   +cmp al, 0
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
    // 0048f175  75e8                   -jne 0x48f15f
    if (!cpu.flags.zf)
    {
        goto L_0x0048f15f;
    }
L_0x0048f177:
    // 0048f177  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f178  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048f17a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048f17c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f181  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f182  2bc9                   +sub ecx, ecx
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
    // 0048f184  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048f185  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048f187  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f189  4f                     -dec edi
    (cpu.edi)--;
L_0x0048f18a:
    // 0048f18a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048f18c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048f18e  3c00                   +cmp al, 0
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
    // 0048f190  7410                   -je 0x48f1a2
    if (cpu.flags.zf)
    {
        goto L_0x0048f1a2;
    }
    // 0048f192  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048f195  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f198  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048f19b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048f19e  3c00                   +cmp al, 0
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
    // 0048f1a0  75e8                   -jne 0x48f18a
    if (!cpu.flags.zf)
    {
        goto L_0x0048f18a;
    }
L_0x0048f1a2:
    // 0048f1a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1a3  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048f1a5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f1a7  e8e4020000             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f1ac  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f1af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f1b3:
    // 0048f1b3  be8c014d00             -mov esi, 0x4d018c
    cpu.esi = 5046668 /*0x4d018c*/;
    // 0048f1b8  eb9a                   -jmp 0x48f154
    goto L_0x0048f154;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48f1bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f1bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f1bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f1be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f1bf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f1c1  e8b6feffff             -call 0x48f07c
    cpu.esp -= 4;
    sub_48f07c(app, cpu);
    if (cpu.terminate) return;
    // 0048f1c6  ba84014d00             -mov edx, 0x4d0184
    cpu.edx = 5046660 /*0x4d0184*/;
    // 0048f1cb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f1cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f1cf  e8bc020000             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f1d4  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f1da  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f1dc  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f1de  e889000000             -call 0x48f26c
    cpu.esp -= 4;
    sub_48f26c(app, cpu);
    if (cpu.terminate) return;
    // 0048f1e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f1e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48f1e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f1e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f1e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f1ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f1eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f1ed  e88afeffff             -call 0x48f07c
    cpu.esp -= 4;
    sub_48f07c(app, cpu);
    if (cpu.terminate) return;
    // 0048f1f2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048f1f7  ba90014d00             -mov edx, 0x4d0190
    cpu.edx = 5046672 /*0x4d0190*/;
    // 0048f1fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f1fe  e88d020000             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f203  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f204  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f205  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f206  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48f208(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f208  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f209  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f20a  bb98014d00             -mov ebx, 0x4d0198
    cpu.ebx = 5046680 /*0x4d0198*/;
    // 0048f20f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048f214  e8a70e0000             -call 0x4900c0
    cpu.esp -= 4;
    sub_4900c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f219  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f21a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f21b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f21c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f21c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f21d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f21e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f220  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f225  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f227  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f22a  c1e202                 +shl edx, 2
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
    // 0048f22d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f22f  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048f232  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f234  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f236  e831000000             -call 0x48f26c
    cpu.esp -= 4;
    sub_48f26c(app, cpu);
    if (cpu.terminate) return;
    // 0048f23b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f23d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f23f  741e                   -je 0x48f25f
    if (cpu.flags.zf)
    {
        goto L_0x0048f25f;
    }
    // 0048f241  83f802                 +cmp eax, 2
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
    // 0048f244  7419                   -je 0x48f25f
    if (cpu.flags.zf)
    {
        goto L_0x0048f25f;
    }
    // 0048f246  83f8ff                 +cmp eax, -1
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
    // 0048f249  7414                   -je 0x48f25f
    if (cpu.flags.zf)
    {
        goto L_0x0048f25f;
    }
    // 0048f24b  83f801                 +cmp eax, 1
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
    // 0048f24e  740a                   -je 0x48f25a
    if (cpu.flags.zf)
    {
        goto L_0x0048f25a;
    }
    // 0048f250  83f805                 +cmp eax, 5
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
    // 0048f253  7405                   -je 0x48f25a
    if (cpu.flags.zf)
    {
        goto L_0x0048f25a;
    }
    // 0048f255  83f80a                 +cmp eax, 0xa
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
    // 0048f258  7c0a                   -jl 0x48f264
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f264;
    }
L_0x0048f25a:
    // 0048f25a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f25c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f25d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f25e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f25f:
    // 0048f25f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f261  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f262  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f263  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f264:
    // 0048f264  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048f269  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f26a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f26b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f26c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f26c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f26d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f26e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f26f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f270  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f271  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048f274  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0048f278  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048f27a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f27c  8b1dc8bd4d00           -mov ebx, dword ptr [0x4dbdc8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094856) /* 0x4dbdc8 */);
    // 0048f282  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0048f286  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048f288  7518                   -jne 0x48f2a2
    if (!cpu.flags.zf)
    {
        goto L_0x0048f2a2;
    }
    // 0048f28a  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f290  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f292  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f295  c1e202                 +shl edx, 2
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
    // 0048f298  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f29a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048f29d  a3c8bd4d00             -mov dword ptr [0x4dbdc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094856) /* 0x4dbdc8 */) = cpu.eax;
L_0x0048f2a2:
    // 0048f2a2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048f2a4  8935c4be4d00           -mov dword ptr [0x4dbec4], esi
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.esi;
    // 0048f2aa  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 0048f2af  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f2b1  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048f2b5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f2b7  48                     -dec eax
    (cpu.eax)--;
    // 0048f2b8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f2ba  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
L_0x0048f2be:
    // 0048f2be  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f2c2  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 0048f2c7  39f8                   +cmp eax, edi
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
    // 0048f2c9  7c0e                   -jl 0x48f2d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f2d9;
    }
    // 0048f2cb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048f2d0  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048f2d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f2d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f2d9:
    // 0048f2d9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048f2db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f2dd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048f2e2  e8c94bffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 0048f2e7  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f2eb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048f2ed  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f2ef  e8cc120000             -call 0x4905c0
    cpu.esp -= 4;
    sub_4905c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f2f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f2f6  0f846b010000           -je 0x48f467
    if (cpu.flags.zf)
    {
        goto L_0x0048f467;
    }
    // 0048f2fc  ff442434               -inc dword ptr [esp + 0x34]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))++;
    // 0048f300  8a242c                 -mov ah, byte ptr [esp + ebp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1);
    // 0048f303  45                     -inc ebp
    (cpu.ebp)++;
    // 0048f304  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f307  0f8384000000           -jae 0x48f391
    if (!cpu.flags.cf)
    {
        goto L_0x0048f391;
    }
    // 0048f30d  c6442cff5f             -mov byte ptr [esp + ebp - 1], 0x5f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ebp * 1) = 95 /*0x5f*/;
L_0x0048f312:
    // 0048f312  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048f314:
    // 0048f314  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f318  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0048f31c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048f31e  0f8489000000           -je 0x48f3ad
    if (cpu.flags.zf)
    {
        goto L_0x0048f3ad;
    }
L_0x0048f324:
    // 0048f324  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0048f326  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048f328  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048f32a  883c2c                 -mov byte ptr [esp + ebp], bh
    app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1) = cpu.bh;
L_0x0048f32d:
    // 0048f32d  8b0dc8be4d00           -mov ecx, dword ptr [0x4dbec8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5095112) /* 0x4dbec8 */);
    // 0048f333  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f334  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f336  0f8cc1000000           -jl 0x48f3fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f3fd;
    }
    // 0048f33c  6bd90c                 -imul ebx, ecx, 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0048f33f  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0048f341:
    // 0048f341  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048f343  8b93d0bd4d00           -mov edx, dword ptr [ebx + 0x4dbdd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5094864) /* 0x4dbdd0 */);
    // 0048f349  e8b3de0000             -call 0x49d201
    cpu.esp -= 4;
    sub_49d201(app, cpu);
    if (cpu.terminate) return;
    // 0048f34e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f350  0f849b000000           -je 0x48f3f1
    if (cpu.flags.zf)
    {
        goto L_0x0048f3f1;
    }
    // 0048f356  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048f358  0f8e64000000           -jle 0x48f3c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f3c2;
    }
    // 0048f35e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048f363:
    // 0048f363  8b1dccbe4d00           -mov ebx, dword ptr [0x4dbecc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5095116) /* 0x4dbecc */);
    // 0048f369  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f36b  a1c8bd4d00             -mov eax, dword ptr [0x4dbdc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094856) /* 0x4dbdc8 */);
    // 0048f370  891dccbe4d00           -mov dword ptr [0x4dbecc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5095116) /* 0x4dbecc */) = cpu.ebx;
    // 0048f376  e8c94bffff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048f37b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f37d  0f8d43000000           -jge 0x48f3c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f3c6;
    }
L_0x0048f383:
    // 0048f383  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048f388  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048f38b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f38c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f38d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f38e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f38f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f390  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f391:
    // 0048f391  80fc30                 +cmp ah, 0x30
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f394  0f8278ffffff           -jb 0x48f312
    if (cpu.flags.cf)
    {
        goto L_0x0048f312;
    }
    // 0048f39a  80fc39                 +cmp ah, 0x39
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048f39d  0f876fffffff           -ja 0x48f312
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048f312;
    }
    // 0048f3a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048f3a8  e967ffffff             -jmp 0x48f314
    goto L_0x0048f314;
L_0x0048f3ad:
    // 0048f3ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f3af  0f846fffffff           -je 0x48f324
    if (cpu.flags.zf)
    {
        goto L_0x0048f324;
    }
    // 0048f3b5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f3b9  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0048f3bd  e962ffffff             -jmp 0x48f324
    goto L_0x0048f324;
L_0x0048f3c2:
    // 0048f3c2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f3c4  eb9d                   -jmp 0x48f363
    goto L_0x0048f363;
L_0x0048f3c6:
    // 0048f3c6  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048f3cd  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f3cf  8b1485d0bd4d00         -mov edx, dword ptr [eax*4 + 0x4dbdd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094864) /* 0x4dbdd0 */ + cpu.eax * 4);
    // 0048f3d6  8b0485d8bd4d00         -mov eax, dword ptr [eax*4 + 0x4dbdd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094872) /* 0x4dbdd8 */ + cpu.eax * 4);
    // 0048f3dd  8915c4be4d00           -mov dword ptr [0x4dbec4], edx
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.edx;
    // 0048f3e3  e82c070100             -call 0x49fb14
    cpu.esp -= 4;
    sub_49fb14(app, cpu);
    if (cpu.terminate) return;
    // 0048f3e8  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048f3eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f3f1:
    // 0048f3f1  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f3f2  83eb0c                 -sub ebx, 0xc
    (cpu.ebx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048f3f5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f3f7  0f8d44ffffff           -jge 0x48f341
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f341;
    }
L_0x0048f3fd:
    // 0048f3fd  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f400  47                     -inc edi
    (cpu.edi)++;
    // 0048f401  83fe08                 +cmp esi, 8
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
    // 0048f404  0f8c23ffffff           -jl 0x48f32d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f32d;
    }
    // 0048f40a  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f40e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048f410  7455                   -je 0x48f467
    if (cpu.flags.zf)
    {
        goto L_0x0048f467;
    }
    // 0048f412  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 0048f417  754e                   -jne 0x48f467
    if (!cpu.flags.zf)
    {
        goto L_0x0048f467;
    }
    // 0048f419  833dccbe4d0000         +cmp dword ptr [0x4dbecc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095116) /* 0x4dbecc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f420  7445                   -je 0x48f467
    if (cpu.flags.zf)
    {
        goto L_0x0048f467;
    }
    // 0048f422  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f424  e8eb060100             -call 0x49fb14
    cpu.esp -= 4;
    sub_49fb14(app, cpu);
    if (cpu.terminate) return;
    // 0048f429  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f42b  83f80a                 +cmp eax, 0xa
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
    // 0048f42e  7c4e                   -jl 0x48f47e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f47e;
    }
    // 0048f430  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048f435:
    // 0048f435  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048f43c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f43e  8b0485d0bd4d00         -mov eax, dword ptr [eax*4 + 0x4dbdd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094864) /* 0x4dbdd0 */ + cpu.eax * 4);
    // 0048f445  a3c4be4d00             -mov dword ptr [0x4dbec4], eax
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.eax;
L_0x0048f44a:
    // 0048f44a  a1c8bd4d00             -mov eax, dword ptr [0x4dbdc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094856) /* 0x4dbdc8 */);
    // 0048f44f  e8f04affff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048f454  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f456  0f8c27ffffff           -jl 0x48f383
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f383;
    }
    // 0048f45c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f45e  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048f461  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f462  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f463  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f464  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f465  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f466  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f467:
    // 0048f467  83fd29                 +cmp ebp, 0x29
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f46a  0f8c4efeffff           -jl 0x48f2be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f2be;
    }
    // 0048f470  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048f475  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048f478  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f479  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f47a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f47b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f47c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f47d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f47e:
    // 0048f47e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f480  7c04                   -jl 0x48f486
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f486;
    }
    // 0048f482  7db1                   -jge 0x48f435
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f435;
    }
    // 0048f484  ebc4                   -jmp 0x48f44a
    goto L_0x0048f44a;
L_0x0048f486:
    // 0048f486  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048f48b  ebbd                   -jmp 0x48f44a
    goto L_0x0048f44a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f490  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f492  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f493  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f494  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f497  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048f499  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048f49c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048f49e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f4a0  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f4a1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f4a3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f4a5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048f4a7  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f4a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f4aa  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048f4ac  8915c0be4d00           -mov dword ptr [0x4dbec0], edx
    app->getMemory<x86::reg32>(x86::reg32(5095104) /* 0x4dbec0 */) = cpu.edx;
    // 0048f4b2  83f931                 +cmp ecx, 0x31
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f4b5  0f8fb5000000           -jg 0x48f570
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048f570;
    }
    // 0048f4bb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048f4bd  7407                   -je 0x48f4c6
    if (cpu.flags.zf)
    {
        goto L_0x0048f4c6;
    }
    // 0048f4bf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f4c1  e85a080000             -call 0x48fd20
    cpu.esp -= 4;
    sub_48fd20(app, cpu);
    if (cpu.terminate) return;
L_0x0048f4c6:
    // 0048f4c6  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f4cb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f4cd  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0048f4d2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f4d5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f4d7  e8684affff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048f4dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f4de  0f8c8c000000           -jl 0x48f570
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f570;
    }
    // 0048f4e4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f4e6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f4e9  e812080000             -call 0x48fd00
    cpu.esp -= 4;
    sub_48fd00(app, cpu);
    if (cpu.terminate) return;
    // 0048f4ee  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048f4f0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f4f2  e8c90b0000             -call 0x4900c0
    cpu.esp -= 4;
    sub_4900c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f4f7  bba0014d00             -mov ebx, 0x4d01a0
    cpu.ebx = 5046688 /*0x4d01a0*/;
    // 0048f4fc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048f501  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f503  e8b80b0000             -call 0x4900c0
    cpu.esp -= 4;
    sub_4900c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f508  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 0048f50d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048f50f  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f514  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f516  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0048f51b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f51e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f520  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048f522  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048f524:
    // 0048f524  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 0048f529  39f8                   +cmp eax, edi
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
    // 0048f52b  7d4d                   -jge 0x48f57a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f57a;
    }
    // 0048f52d  833dc0be4d0000         +cmp dword ptr [0x4dbec0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095104) /* 0x4dbec0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f534  7544                   -jne 0x48f57a
    if (!cpu.flags.zf)
    {
        goto L_0x0048f57a;
    }
    // 0048f536  bba0445600             -mov ebx, 0x5644a0
    cpu.ebx = 5653664 /*0x5644a0*/;
    // 0048f53b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f53d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048f542  e86949ffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 0048f547  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048f549  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f54b  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048f54d  e86e100000             -call 0x4905c0
    cpu.esp -= 4;
    sub_4905c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f552  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f554  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0048f556  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f559  88a6a0445600           -mov byte ptr [esi + 0x5644a0], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5653664) /* 0x5644a0 */) = cpu.ah;
    // 0048f55f  b8a0445600             -mov eax, 0x5644a0
    cpu.eax = 5653664 /*0x5644a0*/;
    // 0048f564  e898dc0000             -call 0x49d201
    cpu.esp -= 4;
    sub_49d201(app, cpu);
    if (cpu.terminate) return;
    // 0048f569  a3c0be4d00             -mov dword ptr [0x4dbec0], eax
    app->getMemory<x86::reg32>(x86::reg32(5095104) /* 0x4dbec0 */) = cpu.eax;
    // 0048f56e  ebb4                   -jmp 0x48f524
    goto L_0x0048f524;
L_0x0048f570:
    // 0048f570  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f572  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f575  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f576  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f577  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f578  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f579  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f57a:
    // 0048f57a  833dc0be4d0000         +cmp dword ptr [0x4dbec0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095104) /* 0x4dbec0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f581  74ed                   -je 0x48f570
    if (cpu.flags.zf)
    {
        goto L_0x0048f570;
    }
    // 0048f583  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048f588  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f58b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f58c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f58d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f58e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f58f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f592  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f593  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f594  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f595  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048f597  833dc8bd4d0000         +cmp dword ptr [0x4dbdc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094856) /* 0x4dbdc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f59e  7518                   -jne 0x48f5b8
    if (!cpu.flags.zf)
    {
        goto L_0x0048f5b8;
    }
    // 0048f5a0  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f5a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f5a8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f5ab  c1e202                 +shl edx, 2
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
    // 0048f5ae  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048f5b0  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048f5b3  a3c8bd4d00             -mov dword ptr [0x4dbdc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5094856) /* 0x4dbdc8 */) = cpu.eax;
L_0x0048f5b8:
    // 0048f5b8  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f5be  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048f5c5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f5c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f5c9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f5cc  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f5ce  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048f5d0  e86f49ffff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048f5d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f5d7  7d08                   -jge 0x48f5e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f5e1;
    }
L_0x0048f5d9:
    // 0048f5d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f5db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f5e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f5e1:
    // 0048f5e1  bba4014d00             -mov ebx, 0x4d01a4
    cpu.ebx = 5046692 /*0x4d01a4*/;
    // 0048f5e6  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048f5eb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f5ed  e8ce0a0000             -call 0x4900c0
    cpu.esp -= 4;
    sub_4900c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f5f2  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f5f8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048f5ff  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f601  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f603  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048f606  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f608  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048f60a  e83549ffff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048f60f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f611  7cc6                   -jl 0x48f5d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f5d9;
    }
    // 0048f613  8b1dccbd4d00           -mov ebx, dword ptr [0x4dbdcc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094860) /* 0x4dbdcc */);
    // 0048f619  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048f61b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f61d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f61e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f620  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048f622  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048f624  49                     -dec ecx
    (cpu.ecx)--;
    // 0048f625  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048f627  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f629  e8920a0000             -call 0x4900c0
    cpu.esp -= 4;
    sub_4900c0(app, cpu);
    if (cpu.terminate) return;
    // 0048f62e  a1c8bd4d00             -mov eax, dword ptr [0x4dbdc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094856) /* 0x4dbdc8 */);
    // 0048f633  e80c49ffff             -call 0x483f44
    cpu.esp -= 4;
    sub_483f44(app, cpu);
    if (cpu.terminate) return;
    // 0048f638  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f63a  7c9d                   -jl 0x48f5d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f5d9;
    }
    // 0048f63c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f63e  baa8014d00             -mov edx, 0x4d01a8
    cpu.edx = 5046696 /*0x4d01a8*/;
    // 0048f643  e8b8060000             -call 0x48fd00
    cpu.esp -= 4;
    sub_48fd00(app, cpu);
    if (cpu.terminate) return;
    // 0048f648  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f64a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f64c  e83ffeffff             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f651  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f653  7484                   -je 0x48f5d9
    if (cpu.flags.zf)
    {
        goto L_0x0048f5d9;
    }
    // 0048f655  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f65b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f65d  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f65f  e808fcffff             -call 0x48f26c
    cpu.esp -= 4;
    sub_48f26c(app, cpu);
    if (cpu.terminate) return;
    // 0048f664  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f666  0f856dffffff           -jne 0x48f5d9
    if (!cpu.flags.zf)
    {
        goto L_0x0048f5d9;
    }
    // 0048f66c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048f671  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f672  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f673  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f674  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f675  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f676  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48f678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f679  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f67a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f67b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f67d  baac014d00             -mov edx, 0x4d01ac
    cpu.edx = 5046700 /*0x4d01ac*/;
    // 0048f682  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f684  e807feffff             -call 0x48f490
    cpu.esp -= 4;
    sub_48f490(app, cpu);
    if (cpu.terminate) return;
    // 0048f689  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0048f68f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f691  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f693  e8d4fbffff             -call 0x48f26c
    cpu.esp -= 4;
    sub_48f26c(app, cpu);
    if (cpu.terminate) return;
    // 0048f698  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f699  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f69a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f69b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_48f6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f6a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f6a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f6a3  833dd0be4d0000         +cmp dword ptr [0x4dbed0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f6aa  7416                   -je 0x48f6c2
    if (cpu.flags.zf)
    {
        goto L_0x0048f6c2;
    }
L_0x0048f6ac:
    // 0048f6ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f6ae  42                     -inc edx
    (cpu.edx)++;
    // 0048f6af  e88c060000             -call 0x48fd40
    cpu.esp -= 4;
    sub_48fd40(app, cpu);
    if (cpu.terminate) return;
    // 0048f6b4  83fa10                 +cmp edx, 0x10
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
    // 0048f6b7  7d09                   -jge 0x48f6c2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f6c2;
    }
    // 0048f6b9  833dd0be4d0000         +cmp dword ptr [0x4dbed0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f6c0  75ea                   -jne 0x48f6ac
    if (!cpu.flags.zf)
    {
        goto L_0x0048f6ac;
    }
L_0x0048f6c2:
    // 0048f6c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f6c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f6c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f6c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f6c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f6c7  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f6cc  e877a8ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048f6d1  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048f6d8  8b88e0445600           -mov ecx, dword ptr [eax + 0x5644e0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5653728) /* 0x5644e0 */);
    // 0048f6de  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f6e0  750c                   -jne 0x48f6ee
    if (!cpu.flags.zf)
    {
        goto L_0x0048f6ee;
    }
    // 0048f6e2  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f6e7  e874a8ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048f6ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f6ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f6ee:
    // 0048f6ee  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0048f6f0  8b15d4be4d00           -mov edx, dword ptr [0x4dbed4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5095124) /* 0x4dbed4 */);
    // 0048f6f6  b820455600             -mov eax, 0x564520
    cpu.eax = 5653792 /*0x564520*/;
    // 0048f6fb  e820a7ffff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 0048f700  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f705  e856a8ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048f70a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f70b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f70c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f70c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f70d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f70e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f70f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f710  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f711  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f712  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f714  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f719  e82aa8ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048f71e  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f722  7518                   -jne 0x48f73c
    if (!cpu.flags.zf)
    {
        goto L_0x0048f73c;
    }
    // 0048f724  8d7318                 -lea esi, [ebx + 0x18]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048f727  8d6b14                 -lea ebp, [ebx + 0x14]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048f72a  8d7b2c                 -lea edi, [ebx + 0x2c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */);
L_0x0048f72d:
    // 0048f72d  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048f730  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f736  0f8cbb000000           -jl 0x48f7f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f7f7;
    }
L_0x0048f73c:
    // 0048f73c  8dbb3c020000           -lea edi, [ebx + 0x23c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 0048f742  8dab38020000           -lea ebp, [ebx + 0x238]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048f748  8db350020000           -lea esi, [ebx + 0x250]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(592) /* 0x250 */);
L_0x0048f74e:
    // 0048f74e  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f755  0f854c010000           -jne 0x48f8a7
    if (!cpu.flags.zf)
    {
        goto L_0x0048f8a7;
    }
    // 0048f75b  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0048f761  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048f763  0f8e3e010000           -jle 0x48f8a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f8a7;
    }
    // 0048f769  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048f76f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f771  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f777  0f8e03010000           -jle 0x48f880
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f880;
    }
    // 0048f77d  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0048f782  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048f784:
    // 0048f784  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f785  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f786  c7833c02000000000000   -mov dword ptr [ebx + 0x23c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(572) /* 0x23c */) = 0 /*0x0*/;
    // 0048f790  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f791  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048f793  c7834002000000000000   -mov dword ptr [ebx + 0x240], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(576) /* 0x240 */) = 0 /*0x0*/;
    // 0048f79d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f79e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048f7a1  c7834402000000000000   -mov dword ptr [ebx + 0x244], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(580) /* 0x244 */) = 0 /*0x0*/;
    // 0048f7ab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f7ac  c7834802000000000000   -mov dword ptr [ebx + 0x248], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(584) /* 0x248 */) = 0 /*0x0*/;
    // 0048f7b6  2eff15e4654c00         -call dword ptr cs:[0x4c65e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006820) /* 0x4c65e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f7bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f7bf  0f84c6000000           -je 0x48f88b
    if (cpu.flags.zf)
    {
        goto L_0x0048f88b;
    }
    // 0048f7c5  8b8338020000           -mov eax, dword ptr [ebx + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048f7cb  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0048f7d1  8b8b38020000           -mov ecx, dword ptr [ebx + 0x238]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048f7d7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f7d9  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048f7df  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f7e1  899334020000           -mov dword ptr [ebx + 0x234], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edx;
    // 0048f7e7  25ff010000             +and eax, 0x1ff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/))));
    // 0048f7ec  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 0048f7f2  e957ffffff             -jmp 0x48f74e
    goto L_0x0048f74e;
L_0x0048f7f7:
    // 0048f7f7  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048f7fa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f7fc  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048f801  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048f804  39d0                   +cmp eax, edx
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
    // 0048f806  7d4e                   -jge 0x48f856
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f856;
    }
L_0x0048f808:
    // 0048f808  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f80a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f80b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f80c  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048f813  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f814  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048f816  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048f81d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f81e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048f821  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0048f828  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f829  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0048f830  2eff1560654c00         -call dword ptr cs:[0x4c6560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006688) /* 0x4c6560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f837  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f839  7422                   -je 0x48f85d
    if (cpu.flags.zf)
    {
        goto L_0x0048f85d;
    }
    // 0048f83b  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048f83e  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048f841  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f843  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048f846  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048f849  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f84b  0f84dcfeffff           -je 0x48f72d
    if (cpu.flags.zf)
    {
        goto L_0x0048f72d;
    }
    // 0048f851  e9e6feffff             -jmp 0x48f73c
    goto L_0x0048f73c;
L_0x0048f856:
    // 0048f856  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0048f85b  ebab                   -jmp 0x48f808
    goto L_0x0048f808;
L_0x0048f85d:
    // 0048f85d  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f864  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f866  750c                   -jne 0x48f874
    if (!cpu.flags.zf)
    {
        goto L_0x0048f874;
    }
L_0x0048f868:
    // 0048f868  c7430801000000         -mov dword ptr [ebx + 8], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0048f86f  e9c8feffff             -jmp 0x48f73c
    goto L_0x0048f73c;
L_0x0048f874:
    // 0048f874  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f879  74ed                   -je 0x48f868
    if (cpu.flags.zf)
    {
        goto L_0x0048f868;
    }
    // 0048f87b  e9bcfeffff             -jmp 0x48f73c
    goto L_0x0048f73c;
L_0x0048f880:
    // 0048f880  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0048f886  e9f9feffff             -jmp 0x48f784
    goto L_0x0048f784;
L_0x0048f88b:
    // 0048f88b  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f892  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f894  7407                   -je 0x48f89d
    if (cpu.flags.zf)
    {
        goto L_0x0048f89d;
    }
    // 0048f896  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f89b  750a                   -jne 0x48f8a7
    if (!cpu.flags.zf)
    {
        goto L_0x0048f8a7;
    }
L_0x0048f89d:
    // 0048f89d  c7832c02000001000000   -mov dword ptr [ebx + 0x22c], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 1 /*0x1*/;
L_0x0048f8a7:
    // 0048f8a7  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f8ac  e8afa6ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048f8b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48f8b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f8b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f8b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f8ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f8bb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f8be  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f8c0  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f8c5  e87ea6ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048f8ca  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f8ce  751e                   -jne 0x48f8ee
    if (!cpu.flags.zf)
    {
        goto L_0x0048f8ee;
    }
L_0x0048f8d0:
    // 0048f8d0  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f8d7  0f856e000000           -jne 0x48f94b
    if (!cpu.flags.zf)
    {
        goto L_0x0048f94b;
    }
L_0x0048f8dd:
    // 0048f8dd  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f8e2  e879a6ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048f8e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f8ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f8ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f8ee:
    // 0048f8ee  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0048f8f1  e836a5ffff             -call 0x489e2c
    cpu.esp -= 4;
    sub_489e2c(app, cpu);
    if (cpu.terminate) return;
    // 0048f8f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f8f8  74d6                   -je 0x48f8d0
    if (cpu.flags.zf)
    {
        goto L_0x0048f8d0;
    }
    // 0048f8fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048f8fc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f900  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f901  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048f904  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f905  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048f908  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f909  2eff1510654c00         -call dword ptr cs:[0x4c6510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006608) /* 0x4c6510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f910  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f912  7418                   -je 0x48f92c
    if (cpu.flags.zf)
    {
        goto L_0x0048f92c;
    }
    // 0048f914  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f915  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f919  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048f91b  750a                   -jne 0x48f927
    if (!cpu.flags.zf)
    {
        goto L_0x0048f927;
    }
L_0x0048f91d:
    // 0048f91d  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048f924  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f925  eba9                   -jmp 0x48f8d0
    goto L_0x0048f8d0;
L_0x0048f927:
    // 0048f927  017310                 +add dword ptr [ebx + 0x10], esi
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f92a  ebf1                   -jmp 0x48f91d
    goto L_0x0048f91d;
L_0x0048f92c:
    // 0048f92c  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f933  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f938  750a                   -jne 0x48f944
    if (!cpu.flags.zf)
    {
        goto L_0x0048f944;
    }
    // 0048f93a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048f93f  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048f942  eb8c                   -jmp 0x48f8d0
    goto L_0x0048f8d0;
L_0x0048f944:
    // 0048f944  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f946  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048f949  eb85                   -jmp 0x48f8d0
    goto L_0x0048f8d0;
L_0x0048f94b:
    // 0048f94b  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 0048f951  e8d6a4ffff             -call 0x489e2c
    cpu.esp -= 4;
    sub_489e2c(app, cpu);
    if (cpu.terminate) return;
    // 0048f956  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f958  7483                   -je 0x48f8dd
    if (cpu.flags.zf)
    {
        goto L_0x0048f8dd;
    }
    // 0048f95a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048f95c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f960  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f961  8d833c020000           -lea eax, [ebx + 0x23c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 0048f967  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f968  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048f96b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f96c  2eff1510654c00         -call dword ptr cs:[0x4c6510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006608) /* 0x4c6510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f973  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f975  743c                   -je 0x48f9b3
    if (cpu.flags.zf)
    {
        goto L_0x0048f9b3;
    }
    // 0048f977  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f97a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048f97c  741a                   -je 0x48f998
    if (cpu.flags.zf)
    {
        goto L_0x0048f998;
    }
    // 0048f97e  299334020000           -sub dword ptr [ebx + 0x234], edx
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f984  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048f98a  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0048f98d  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048f992  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
L_0x0048f998:
    // 0048f998  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 0048f9a2  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f9a7  e8b4a5ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048f9ac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f9af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f9b3:
    // 0048f9b3  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f9ba  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f9bf  751c                   -jne 0x48f9dd
    if (!cpu.flags.zf)
    {
        goto L_0x0048f9dd;
    }
    // 0048f9c1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048f9c6:
    // 0048f9c6  89832c020000           -mov dword ptr [ebx + 0x22c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = cpu.eax;
    // 0048f9cc  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048f9d1  e88aa5ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048f9d6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f9d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f9dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f9dd:
    // 0048f9dd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048f9df  ebe5                   -jmp 0x48f9c6
    goto L_0x0048f9c6;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f9e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f9e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f9e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f9e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f9e7  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048f9ed  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048f9f2  a1d4be4d00             -mov eax, dword ptr [0x4dbed4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095124) /* 0x4dbed4 */);
    // 0048f9f7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048f9fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048f9fc:
    // 0048f9fc  8b90e0445600           -mov edx, dword ptr [eax + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5653728) /* 0x5644e0 */);
    // 0048fa02  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fa04  7422                   -je 0x48fa28
    if (cpu.flags.zf)
    {
        goto L_0x0048fa28;
    }
    // 0048fa06  837a0800               +cmp dword ptr [edx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fa0a  7408                   -je 0x48fa14
    if (cpu.flags.zf)
    {
        goto L_0x0048fa14;
    }
    // 0048fa0c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048fa0d  8b5a28                 -mov ebx, dword ptr [edx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0048fa10  895c8cfc               -mov dword ptr [esp + ecx*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.ebx;
L_0x0048fa14:
    // 0048fa14  83ba2c02000000         +cmp dword ptr [edx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fa1b  740b                   -je 0x48fa28
    if (cpu.flags.zf)
    {
        goto L_0x0048fa28;
    }
    // 0048fa1d  41                     -inc ecx
    (cpu.ecx)++;
    // 0048fa1e  8b924c020000           -mov edx, dword ptr [edx + 0x24c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(588) /* 0x24c */);
    // 0048fa24  89548cfc               -mov dword ptr [esp + ecx*4 - 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.edx;
L_0x0048fa28:
    // 0048fa28  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fa2b  83f840                 +cmp eax, 0x40
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
    // 0048fa2e  75cc                   -jne 0x48f9fc
    if (!cpu.flags.zf)
    {
        goto L_0x0048f9fc;
    }
    // 0048fa30  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048fa32  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fa34  e89fa4ffff             -call 0x489ed8
    cpu.esp -= 4;
    sub_489ed8(app, cpu);
    if (cpu.terminate) return;
    // 0048fa39  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048fa3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fa42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48fa44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fa44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fa45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fa46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fa47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fa48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fa49  e8bea3ffff             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 0048fa4e  a3d4be4d00             -mov dword ptr [0x4dbed4], eax
    app->getMemory<x86::reg32>(x86::reg32(5095124) /* 0x4dbed4 */) = cpu.eax;
    // 0048fa53  833dd0be4d0000         +cmp dword ptr [0x4dbed0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fa5a  0f8479000000           -je 0x48fad9
    if (cpu.flags.zf)
    {
        goto L_0x0048fad9;
    }
    // 0048fa60  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048fa62:
    // 0048fa62  e87dffffff             -call 0x48f9e4
    cpu.esp -= 4;
    sub_48f9e4(app, cpu);
    if (cpu.terminate) return;
    // 0048fa67  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0048fa69:
    // 0048fa69  8b9ee0445600           -mov ebx, dword ptr [esi + 0x5644e0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5653728) /* 0x5644e0 */);
    // 0048fa6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048fa71  7456                   -je 0x48fac9
    if (cpu.flags.zf)
    {
        goto L_0x0048fac9;
    }
    // 0048fa73  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fa75  e83efeffff             -call 0x48f8b8
    cpu.esp -= 4;
    sub_48f8b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fa7a  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fa7c  743c                   -je 0x48faba
    if (cpu.flags.zf)
    {
        goto L_0x0048faba;
    }
    // 0048fa7e  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fa83  e8c0a4ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048fa88  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048fa8a  83f803                 +cmp eax, 3
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
    // 0048fa8d  7362                   -jae 0x48faf1
    if (!cpu.flags.cf)
    {
        goto L_0x0048faf1;
    }
    // 0048fa8f  83f802                 +cmp eax, 2
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
    // 0048fa92  751a                   -jne 0x48faae
    if (!cpu.flags.zf)
    {
        goto L_0x0048faae;
    }
    // 0048fa94  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0048fa96  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048fa99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fa9a  2eff1558654c00         -call dword ptr cs:[0x4c6558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006680) /* 0x4c6558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048faa1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048faa3  e810feffff             -call 0x48f8b8
    cpu.esp -= 4;
    sub_48f8b8(app, cpu);
    if (cpu.terminate) return;
    // 0048faa8  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048faab  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0048faae:
    // 0048faae  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0048fab0  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fab5  e8a6a4ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x0048faba:
    // 0048faba  3bbee0445600           +cmp edi, dword ptr [esi + 0x5644e0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5653728) /* 0x5644e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fac0  7407                   -je 0x48fac9
    if (cpu.flags.zf)
    {
        goto L_0x0048fac9;
    }
    // 0048fac2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fac4  e843fcffff             -call 0x48f70c
    cpu.esp -= 4;
    sub_48f70c(app, cpu);
    if (cpu.terminate) return;
L_0x0048fac9:
    // 0048fac9  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048facc  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048facf  7598                   -jne 0x48fa69
    if (!cpu.flags.zf)
    {
        goto L_0x0048fa69;
    }
    // 0048fad1  3b3dd0be4d00           +cmp edi, dword ptr [0x4dbed0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fad7  7589                   -jne 0x48fa62
    if (!cpu.flags.zf)
    {
        goto L_0x0048fa62;
    }
L_0x0048fad9:
    // 0048fad9  a1d4be4d00             -mov eax, dword ptr [0x4dbed4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095124) /* 0x4dbed4 */);
    // 0048fade  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0048fae0  e803a4ffff             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 0048fae5  891dd4be4d00           -mov dword ptr [0x4dbed4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5095124) /* 0x4dbed4 */) = cpu.ebx;
    // 0048faeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048faec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048faed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048faee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048faef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048faf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048faf1:
    // 0048faf1  7642                   -jbe 0x48fb35
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048fb35;
    }
    // 0048faf3  83f804                 +cmp eax, 4
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
    // 0048faf6  75b6                   -jne 0x48faae
    if (!cpu.flags.zf)
    {
        goto L_0x0048faae;
    }
    // 0048faf8  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0048fafa  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048fafd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fafe  2eff1558654c00         -call dword ptr cs:[0x4c6558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006680) /* 0x4c6558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fb05  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fb07  e8acfdffff             -call 0x48f8b8
    cpu.esp -= 4;
    sub_48f8b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fb0c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048fb0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fb10  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fb17  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0048fb1a  e8c9a3ffff             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 0048fb1f  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 0048fb25  e8bea3ffff             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 0048fb2a  89bee0445600           -mov dword ptr [esi + 0x5644e0], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5653728) /* 0x5644e0 */) = cpu.edi;
    // 0048fb30  e979ffffff             -jmp 0x48faae
    goto L_0x0048faae;
L_0x0048fb35:
    // 0048fb35  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0048fb37  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048fb3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fb3b  2eff1558654c00         -call dword ptr cs:[0x4c6558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006680) /* 0x4c6558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fb42  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fb44  e86ffdffff             -call 0x48f8b8
    cpu.esp -= 4;
    sub_48f8b8(app, cpu);
    if (cpu.terminate) return;
    // 0048fb49  89bb30020000           -mov dword ptr [ebx + 0x230], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.edi;
    // 0048fb4f  89bb34020000           -mov dword ptr [ebx + 0x234], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edi;
    // 0048fb55  e954ffffff             -jmp 0x48faae
    goto L_0x0048faae;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48fb5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fb5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fb5e  7c10                   -jl 0x48fb70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fb70;
    }
    // 0048fb60  83f810                 +cmp eax, 0x10
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
    // 0048fb63  7d0b                   -jge 0x48fb70
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fb70;
    }
    // 0048fb65  833c85e044560000       +cmp dword ptr [eax*4 + 0x5644e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fb6d  7504                   -jne 0x48fb73
    if (!cpu.flags.zf)
    {
        goto L_0x0048fb73;
    }
    // 0048fb6f  90                     -nop 
    ;
L_0x0048fb70:
    // 0048fb70  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fb72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fb73:
    // 0048fb73  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048fb78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48fb7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fb7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fb7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fb7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fb7f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048fb81  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fb88  750a                   -jne 0x48fb94
    if (!cpu.flags.zf)
    {
        goto L_0x0048fb94;
    }
    // 0048fb8a  e869a3ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048fb8f  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x0048fb94:
    // 0048fb94  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fb99  e8aaa3ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048fb9e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048fba0  e8b7ffffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0048fba5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fba7  750e                   -jne 0x48fbb7
    if (!cpu.flags.zf)
    {
        goto L_0x0048fbb7;
    }
L_0x0048fba9:
    // 0048fba9  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fbae  e8ada3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fbb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fbb7:
    // 0048fbb7  8b0495e0445600         -mov eax, dword ptr [edx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.edx * 4);
    // 0048fbbe  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0048fbc0  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fbc3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fbc4  2eff1580644c00         -call dword ptr cs:[0x4c6480]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006464) /* 0x4c6480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fbcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fbcd  75da                   -jne 0x48fba9
    if (!cpu.flags.zf)
    {
        goto L_0x0048fba9;
    }
    // 0048fbcf  e804a4ffff             -call 0x489fd8
    cpu.esp -= 4;
    sub_489fd8(app, cpu);
    if (cpu.terminate) return;
    // 0048fbd4  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fbd9  e882a3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fbde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbe0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fbe1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48fbe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fbe4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fbe5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fbe6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fbe7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048fbe9  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fbf0  750a                   -jne 0x48fbfc
    if (!cpu.flags.zf)
    {
        goto L_0x0048fbfc;
    }
    // 0048fbf2  e801a3ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048fbf7  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x0048fbfc:
    // 0048fbfc  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fc01  e842a3ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048fc06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048fc08  e84fffffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0048fc0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fc0f  750e                   -jne 0x48fc1f
    if (!cpu.flags.zf)
    {
        goto L_0x0048fc1f;
    }
L_0x0048fc11:
    // 0048fc11  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fc16  e845a3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fc1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fc1f:
    // 0048fc1f  8b0495e0445600         -mov eax, dword ptr [edx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.edx * 4);
    // 0048fc26  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0048fc28  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fc2b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fc2c  2eff1580644c00         -call dword ptr cs:[0x4c6480]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006464) /* 0x4c6480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fc33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fc35  75da                   -jne 0x48fc11
    if (!cpu.flags.zf)
    {
        goto L_0x0048fc11;
    }
    // 0048fc37  e89ca3ffff             -call 0x489fd8
    cpu.esp -= 4;
    sub_489fd8(app, cpu);
    if (cpu.terminate) return;
    // 0048fc3c  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fc41  e81aa3ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fc46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48fc4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fc4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fc4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fc4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fc4f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fc50  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fc53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048fc55  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048fc5a  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fc61  750a                   -jne 0x48fc6d
    if (!cpu.flags.zf)
    {
        goto L_0x0048fc6d;
    }
    // 0048fc63  e890a2ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048fc68  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x0048fc6d:
    // 0048fc6d  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fc72  e8d1a2ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048fc77  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048fc79  e8defeffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0048fc7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fc80  7514                   -jne 0x48fc96
    if (!cpu.flags.zf)
    {
        goto L_0x0048fc96;
    }
    // 0048fc82  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fc87  e8d4a2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fc8c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fc8e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fc91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fc95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fc96:
    // 0048fc96  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048fc98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fc99  8b0495e0445600         -mov eax, dword ptr [edx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.edx * 4);
    // 0048fca0  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fca3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fca4  2eff15a8644c00         -call dword ptr cs:[0x4c64a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006504) /* 0x4c64a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fcab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fcad  751f                   -jne 0x48fcce
    if (!cpu.flags.zf)
    {
        goto L_0x0048fcce;
    }
    // 0048fcaf  f6042480               +test byte ptr [esp], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 128 /*0x80*/));
    // 0048fcb3  7432                   -je 0x48fce7
    if (cpu.flags.zf)
    {
        goto L_0x0048fce7;
    }
    // 0048fcb5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048fcba  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fcbf  e89ca2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fcc4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fcc6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fcc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fcca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fccb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fccc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fccd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fcce:
    // 0048fcce  e805a3ffff             -call 0x489fd8
    cpu.esp -= 4;
    sub_489fd8(app, cpu);
    if (cpu.terminate) return;
    // 0048fcd3  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fcd8  e883a2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fcdd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fcdf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fce2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fce3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fce4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fce5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fce6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fce7:
    // 0048fce7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048fce9  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fcee  e86da2ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fcf3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fcf5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fcf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fcf9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fcfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fcfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fcfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48fd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fd00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fd01  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048fd03  e854feffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0048fd08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fd0a  7502                   -jne 0x48fd0e
    if (!cpu.flags.zf)
    {
        goto L_0x0048fd0e;
    }
    // 0048fd0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fd0d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fd0e:
    // 0048fd0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fd0f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0048fd14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fd16  e8a9f9ffff             -call 0x48f6c4
    cpu.esp -= 4;
    sub_48f6c4(app, cpu);
    if (cpu.terminate) return;
    // 0048fd1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fd1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fd1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48fd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fd20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fd21  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048fd23  e834feffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0048fd28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fd2a  7502                   -jne 0x48fd2e
    if (!cpu.flags.zf)
    {
        goto L_0x0048fd2e;
    }
    // 0048fd2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fd2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fd2e:
    // 0048fd2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fd2f  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048fd34  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fd36  e889f9ffff             -call 0x48f6c4
    cpu.esp -= 4;
    sub_48f6c4(app, cpu);
    if (cpu.terminate) return;
    // 0048fd3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fd3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fd3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48fd40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fd40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fd41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fd42  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048fd44  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd4b  0f8480000000           -je 0x48fdd1
    if (cpu.flags.zf)
    {
        goto L_0x0048fdd1;
    }
L_0x0048fd51:
    // 0048fd51  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fd56  e8eda1ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0048fd5b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fd5d  e8fafdffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0048fd62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fd64  0f8476000000           -je 0x48fde0
    if (cpu.flags.zf)
    {
        goto L_0x0048fde0;
    }
    // 0048fd6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fd6b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fd6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fd6d  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0048fd74  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048fd79  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fd7b  8bb3e0445600           -mov esi, dword ptr [ebx + 0x5644e0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5653728) /* 0x5644e0 */);
    // 0048fd81  e83ef9ffff             -call 0x48f6c4
    cpu.esp -= 4;
    sub_48f6c4(app, cpu);
    if (cpu.terminate) return;
    // 0048fd86  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fd8b  e8d0a1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fd90  8bbbe0445600           -mov edi, dword ptr [ebx + 0x5644e0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5653728) /* 0x5644e0 */);
    // 0048fd96  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048fd98  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048fd9a  7418                   -je 0x48fdb4
    if (cpu.flags.zf)
    {
        goto L_0x0048fdb4;
    }
    // 0048fd9c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0048fda1:
    // 0048fda1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048fda3  e8f49dffff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 0048fda8  83bae044560000         +cmp dword ptr [edx + 0x5644e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5653728) /* 0x5644e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fdaf  75f0                   -jne 0x48fda1
    if (!cpu.flags.zf)
    {
        goto L_0x0048fda1;
    }
    // 0048fdb1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048fdb4:
    // 0048fdb4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048fdb6  e8414bffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0048fdbb  ff0dd0be4d00           -dec dword ptr [0x4dbed0]
    (app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */))--;
    // 0048fdc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fdc2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fdc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fdc4  8b15d0be4d00           -mov edx, dword ptr [0x4dbed0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */);
    // 0048fdca  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fdcc  7429                   -je 0x48fdf7
    if (cpu.flags.zf)
    {
        goto L_0x0048fdf7;
    }
    // 0048fdce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fdcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fdd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fdd1:
    // 0048fdd1  e822a1ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048fdd6  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
    // 0048fddb  e971ffffff             -jmp 0x48fd51
    goto L_0x0048fd51;
L_0x0048fde0:
    // 0048fde0  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fde5  e876a1ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0048fdea  8b15d0be4d00           -mov edx, dword ptr [0x4dbed0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */);
    // 0048fdf0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fdf2  7403                   -je 0x48fdf7
    if (cpu.flags.zf)
    {
        goto L_0x0048fdf7;
    }
    // 0048fdf4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fdf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fdf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fdf7:
    // 0048fdf7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fdf9  e8c6f8ffff             -call 0x48f6c4
    cpu.esp -= 4;
    sub_48f6c4(app, cpu);
    if (cpu.terminate) return;
    // 0048fdfe  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048fe03  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fe05  e86aa1ffff             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 0048fe0a  890dd8be4d00           -mov dword ptr [0x4dbed8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.ecx;
    // 0048fe10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fe12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48fe14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fe14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048fe15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fe16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048fe17  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fe18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048fe19  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048fe1c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048fe1e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048fe20  83f8ff                 +cmp eax, -1
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
    // 0048fe23  752e                   -jne 0x48fe53
    if (!cpu.flags.zf)
    {
        goto L_0x0048fe53;
    }
    // 0048fe25  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
    // 0048fe2a  8b151c455600           -mov edx, dword ptr [0x56451c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653788) /* 0x56451c */);
    // 0048fe30  b83c000000             -mov eax, 0x3c
    cpu.eax = 60 /*0x3c*/;
    // 0048fe35  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fe37  7412                   -je 0x48fe4b
    if (cpu.flags.zf)
    {
        goto L_0x0048fe4b;
    }
L_0x0048fe39:
    // 0048fe39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fe3b  7c0e                   -jl 0x48fe4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fe4b;
    }
    // 0048fe3d  8b88dc445600           -mov ecx, dword ptr [eax + 0x5644dc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5653724) /* 0x5644dc */);
    // 0048fe43  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fe46  4e                     -dec esi
    (cpu.esi)--;
    // 0048fe47  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048fe49  75ee                   -jne 0x48fe39
    if (!cpu.flags.zf)
    {
        goto L_0x0048fe39;
    }
L_0x0048fe4b:
    // 0048fe4b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048fe4d  0f8ccf000000           -jl 0x48ff22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ff22;
    }
L_0x0048fe53:
    // 0048fe53  ff05d0be4d00           -inc dword ptr [0x4dbed0]
    (app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */))++;
    // 0048fe59  833dd0be4d0001         +cmp dword ptr [0x4dbed0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fe60  0f84ca000000           -je 0x48ff30
    if (cpu.flags.zf)
    {
        goto L_0x0048ff30;
    }
L_0x0048fe66:
    // 0048fe66  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048fe6b  ba50040000             -mov edx, 0x450
    cpu.edx = 1104 /*0x450*/;
    // 0048fe70  b8b4014d00             -mov eax, 0x4d01b4
    cpu.eax = 5046708 /*0x4d01b4*/;
    // 0048fe75  e81e46ffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 0048fe7a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048fe7c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048fe7e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048fe80  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048fe82  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048fe89  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048fe8b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048fe8d  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048fe90  2eff1558644c00         -call dword ptr cs:[0x4c6458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006424) /* 0x4c6458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fe97  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048fe99  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048fea0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048fea2  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0048fea9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048feab  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 0048feb5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048feb7  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0048feba  2eff1558644c00         -call dword ptr cs:[0x4c6458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006424) /* 0x4c6458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fec1  c7833002000000000000   -mov dword ptr [ebx + 0x230], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = 0 /*0x0*/;
    // 0048fecb  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0048fed0  89834c020000           -mov dword ptr [ebx + 0x24c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */) = cpu.eax;
    // 0048fed6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048fed8  c7833402000000000000   -mov dword ptr [ebx + 0x234], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = 0 /*0x0*/;
    // 0048fee2  e835a1ffff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048fee7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048fee9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048feea  ba19000000             -mov edx, 0x19
    cpu.edx = 25 /*0x19*/;
    // 0048feef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048fef0  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048fef4  2eff156c654c00         -call dword ptr cs:[0x4c656c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006700) /* 0x4c656c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fefb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fefd  7505                   -jne 0x48ff04
    if (!cpu.flags.zf)
    {
        goto L_0x0048ff04;
    }
    // 0048feff  e8d4a0ffff             -call 0x489fd8
    cpu.esp -= 4;
    sub_489fd8(app, cpu);
    if (cpu.terminate) return;
L_0x0048ff04:
    // 0048ff04  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ff09  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ff0b  892cb5e0445600         -mov dword ptr [esi*4 + 0x5644e0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.esi * 4) = cpu.ebp;
    // 0048ff12  e8adf7ffff             -call 0x48f6c4
    cpu.esp -= 4;
    sub_48f6c4(app, cpu);
    if (cpu.terminate) return;
    // 0048ff17  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ff19  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048ff1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff20  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ff22:
    // 0048ff22  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048ff27  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048ff2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ff30:
    // 0048ff30  b8a0f64800             -mov eax, 0x48f6a0
    cpu.eax = 4781728 /*0x48f6a0*/;
    // 0048ff35  e866ae0000             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 0048ff3a  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ff41  750a                   -jne 0x48ff4d
    if (!cpu.flags.zf)
    {
        goto L_0x0048ff4d;
    }
    // 0048ff43  e8b09fffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0048ff48  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x0048ff4d:
    // 0048ff4d  6820455600             -push 0x564520
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653792 /*0x564520*/;
    cpu.esp -= 4;
    // 0048ff52  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048ff57  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ff5c  b844fa4800             -mov eax, 0x48fa44
    cpu.eax = 4782660 /*0x48fa44*/;
    // 0048ff61  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ff63  e8789bffff             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 0048ff68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ff6a  0f85f6feffff           -jne 0x48fe66
    if (!cpu.flags.zf)
    {
        goto L_0x0048fe66;
    }
    // 0048ff70  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0048ff75  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ff77  e8f89fffff             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 0048ff7c  890dd8be4d00           -mov dword ptr [0x4dbed8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.ecx;
    // 0048ff82  a1d0be4d00             -mov eax, dword ptr [0x4dbed0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */);
    // 0048ff87  ff0dd0be4d00           -dec dword ptr [0x4dbed0]
    (app->getMemory<x86::reg32>(x86::reg32(5095120) /* 0x4dbed0 */))--;
    // 0048ff8d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048ff92  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048ff95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ff9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ff9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ff9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ff9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ff9e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ff9f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048ffa2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ffa4  8b1485e0445600         -mov edx, dword ptr [eax*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.eax * 4);
    // 0048ffab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ffad  7407                   -je 0x48ffb6
    if (cpu.flags.zf)
    {
        goto L_0x0048ffb6;
    }
    // 0048ffaf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048ffb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ffb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ffb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ffb5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ffb6:
    // 0048ffb6  40                     -inc eax
    (cpu.eax)++;
    // 0048ffb7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ffb8  68c0014d00             -push 0x4d01c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5046720 /*0x4d01c0*/;
    cpu.esp -= 4;
    // 0048ffbd  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ffc1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ffc2  e83a65ffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0048ffc7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048ffca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ffcb  6880000040             -push 0x40000080
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741952 /*0x40000080*/;
    cpu.esp -= 4;
    // 0048ffd0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0048ffd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ffd3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ffd4  68000000c0             -push 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 3221225472 /*0xc0000000*/;
    cpu.esp -= 4;
    // 0048ffd9  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ffdd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ffde  2eff155c644c00         -call dword ptr cs:[0x4c645c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006428) /* 0x4c645c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ffe5  83f8ff                 +cmp eax, -1
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
    // 0048ffe8  7410                   -je 0x48fffa
    if (cpu.flags.zf)
    {
        goto L_0x0048fffa;
    }
    // 0048ffea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ffec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ffee  e821feffff             -call 0x48fe14
    cpu.esp -= 4;
    sub_48fe14(app, cpu);
    if (cpu.terminate) return;
    // 0048fff3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048fff6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fff7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fff8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fff9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048fffa:
    // 0048fffa  e8d99fffff             -call 0x489fd8
    cpu.esp -= 4;
    sub_489fd8(app, cpu);
    if (cpu.terminate) return;
    // 0048ffff  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490002  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490003  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490004  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490005  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490008  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490009  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049000b  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490012  750a                   -jne 0x49001e
    if (!cpu.flags.zf)
    {
        goto L_0x0049001e;
    }
    // 00490014  e8df9effff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00490019  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x0049001e:
    // 0049001e  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490023  e8209fffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00490028  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049002a  e82dfbffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0049002f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490031  740b                   -je 0x49003e
    if (cpu.flags.zf)
    {
        goto L_0x0049003e;
    }
    // 00490033  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490035  e822030000             -call 0x49035c
    cpu.esp -= 4;
    sub_49035c(app, cpu);
    if (cpu.terminate) return;
    // 0049003a  39d0                   +cmp eax, edx
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
    // 0049003c  7d10                   -jge 0x49004e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049004e;
    }
L_0x0049003e:
    // 0049003e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490040  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490045  e8169fffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049004a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049004c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049004d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049004e:
    // 0049004e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490050  e86b000000             -call 0x4900c0
    cpu.esp -= 4;
    sub_4900c0(app, cpu);
    if (cpu.terminate) return;
    // 00490055  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490057  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0049005c  e8ff9effff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00490061  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490063  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490064  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490068(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490068  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490069  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049006a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049006c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049006e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00490070  e8e7faffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 00490075  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490077  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490079  742d                   -je 0x4900a8
    if (cpu.flags.zf)
    {
        goto L_0x004900a8;
    }
    // 0049007b  031df0375600           -add ebx, dword ptr [0x5637f0]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */)));
L_0x00490081:
    // 00490081  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00490083  e8d4020000             -call 0x49035c
    cpu.esp -= 4;
    sub_49035c(app, cpu);
    if (cpu.terminate) return;
    // 00490088  39d0                   +cmp eax, edx
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
    // 0049008a  7d11                   -jge 0x49009d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049009d;
    }
    // 0049008c  3b1df0375600           +cmp ebx, dword ptr [0x5637f0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490092  7e09                   -jle 0x49009d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049009d;
    }
    // 00490094  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490096  e8153effff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049009b  ebe4                   -jmp 0x490081
    goto L_0x00490081;
L_0x0049009d:
    // 0049009d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049009f  e8b8020000             -call 0x49035c
    cpu.esp -= 4;
    sub_49035c(app, cpu);
    if (cpu.terminate) return;
    // 004900a4  39d0                   +cmp eax, edx
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
    // 004900a6  7d05                   -jge 0x4900ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004900ad;
    }
L_0x004900a8:
    // 004900a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004900aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004900ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004900ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004900ad:
    // 004900ad  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004900af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004900b1  e80a000000             -call 0x4900c0
    cpu.esp -= 4;
    sub_4900c0(app, cpu);
    if (cpu.terminate) return;
    // 004900b6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004900b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004900ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004900bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004900bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4900c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004900c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004900c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004900c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004900c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004900c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004900c6  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004900c8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004900ca  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004900cc  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004900d3  750a                   -jne 0x4900df
    if (!cpu.flags.zf)
    {
        goto L_0x004900df;
    }
    // 004900d5  e81e9effff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 004900da  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x004900df:
    // 004900df  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004900e4  e85f9effff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004900e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004900eb  e86cfaffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 004900f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004900f2  0f84b1000000           -je 0x4901a9
    if (cpu.flags.zf)
    {
        goto L_0x004901a9;
    }
    // 004900f8  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 004900ff  8bb034020000           -mov esi, dword ptr [eax + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00490105  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490107  81fe00020000           +cmp esi, 0x200
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049010d  7e0b                   -jle 0x49011a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049011a;
    }
    // 0049010f  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 00490114  2b9034020000           -sub edx, dword ptr [eax + 0x234]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */)));
L_0x0049011a:
    // 0049011a  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 00490121  8b9830020000           -mov ebx, dword ptr [eax + 0x230]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 00490127  8b8034020000           -mov eax, dword ptr [eax + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 0049012d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049012f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490131  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00490136  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00490139  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049013b  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490141  7e0b                   -jle 0x49014e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049014e;
    }
    // 00490143  be00020000             -mov esi, 0x200
    cpu.esi = 512 /*0x200*/;
    // 00490148  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049014a  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049014c  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049014e:
    // 0049014e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490150  7418                   -je 0x49016a
    if (cpu.flags.zf)
    {
        goto L_0x0049016a;
    }
    // 00490152  8b148de0445600         -mov edx, dword ptr [ecx*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 00490159  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 0049015f  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00490161  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490163  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490165  e816a8ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
L_0x0049016a:
    // 0049016a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049016c  7417                   -je 0x490185
    if (cpu.flags.zf)
    {
        goto L_0x00490185;
    }
    // 0049016e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00490170  8b148de0445600         -mov edx, dword ptr [ecx*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 00490177  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0049017a  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 00490180  e8fba7ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
L_0x00490185:
    // 00490185  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 0049018c  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0049018f  8ba834020000           -mov ebp, dword ptr [eax + 0x234]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00490195  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490197  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049019c  89a834020000           -mov dword ptr [eax + 0x234], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */) = cpu.ebp;
    // 004901a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004901a4  e81bf5ffff             -call 0x48f6c4
    cpu.esp -= 4;
    sub_48f6c4(app, cpu);
    if (cpu.terminate) return;
L_0x004901a9:
    // 004901a9  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004901ae  e8ad9dffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004901b3  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004901b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4901bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004901bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004901bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004901be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004901bf  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004901c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004901c4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004901c6  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004901c8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004901ca  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004901d1  750a                   -jne 0x4901dd
    if (!cpu.flags.zf)
    {
        goto L_0x004901dd;
    }
    // 004901d3  e8209dffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 004901d8  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x004901dd:
    // 004901dd  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004901e2  e8619dffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004901e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004901e9  e86ef9ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 004901ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004901f0  7513                   -jne 0x490205
    if (!cpu.flags.zf)
    {
        goto L_0x00490205;
    }
L_0x004901f2:
    // 004901f2  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004901f7  e8649dffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004901fc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004901ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490200  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490201  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490202  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00490205:
    // 00490205  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00490207  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490208  8b04b5e0445600         -mov eax, dword ptr [esi*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.esi * 4);
    // 0049020f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00490212  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490213  2eff15b0644c00         -call dword ptr cs:[0x4c64b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006512) /* 0x4c64b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049021a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049021c  745c                   -je 0x49027a
    if (cpu.flags.zf)
    {
        goto L_0x0049027a;
    }
    // 0049021e  804c240801             -or byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00490223  6681642408fdb0         -and word ptr [esp + 8], 0xb0fd
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) &= x86::reg16(x86::sreg16(45309 /*0xb0fd*/));
    // 0049022a  83ff10                 +cmp edi, 0x10
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
    // 0049022d  7f07                   -jg 0x490236
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00490236;
    }
    // 0049022f  8b3cbddcbe4d00         -mov edi, dword ptr [edi*4 + 0x4dbedc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5095132) /* 0x4dbedc */ + cpu.edi * 4);
L_0x00490236:
    // 00490236  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049023a  0405                   -add al, 5
    (cpu.al) += x86::reg8(x86::sreg8(5 /*0x5*/));
    // 0049023c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00490240  88442412               -mov byte ptr [esp + 0x12], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 00490244  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490246  764a                   -jbe 0x490292
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490292;
    }
    // 00490248  83fb01                 +cmp ebx, 1
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
    // 0049024b  7545                   -jne 0x490292
    if (!cpu.flags.zf)
    {
        goto L_0x00490292;
    }
    // 0049024d  c644241402             -mov byte ptr [esp + 0x14], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
L_0x00490252:
    // 00490252  83fd01                 +cmp ebp, 1
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
    // 00490255  7343                   -jae 0x49029a
    if (!cpu.flags.cf)
    {
        goto L_0x0049029a;
    }
L_0x00490257:
    // 00490257  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00490259  884c2413               -mov byte ptr [esp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = cpu.cl;
L_0x0049025d:
    // 0049025d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049025f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490260  8b04b5e0445600         -mov eax, dword ptr [esi*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.esi * 4);
    // 00490267  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049026a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049026b  2eff1568654c00         -call dword ptr cs:[0x4c6568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006696) /* 0x4c6568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490272  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490274  0f8578ffffff           -jne 0x4901f2
    if (!cpu.flags.zf)
    {
        goto L_0x004901f2;
    }
L_0x0049027a:
    // 0049027a  e8599dffff             -call 0x489fd8
    cpu.esp -= 4;
    sub_489fd8(app, cpu);
    if (cpu.terminate) return;
    // 0049027f  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490284  e8d79cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00490289  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049028c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049028d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049028e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049028f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00490292:
    // 00490292  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 00490294  88742414               -mov byte ptr [esp + 0x14], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dh;
    // 00490298  ebb8                   -jmp 0x490252
    goto L_0x00490252;
L_0x0049029a:
    // 0049029a  7707                   -ja 0x4902a3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004902a3;
    }
    // 0049029c  c644241301             -mov byte ptr [esp + 0x13], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 1 /*0x1*/;
    // 004902a1  ebba                   -jmp 0x49025d
    goto L_0x0049025d;
L_0x004902a3:
    // 004902a3  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004902a6  75af                   -jne 0x490257
    if (!cpu.flags.zf)
    {
        goto L_0x00490257;
    }
    // 004902a8  c644241302             -mov byte ptr [esp + 0x13], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 2 /*0x2*/;
    // 004902ad  ebae                   -jmp 0x49025d
    goto L_0x0049025d;
}

/* align: skip 0x90 */
void Application::sub_4902b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004902b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004902b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004902b3  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004902ba  750a                   -jne 0x4902c6
    if (!cpu.flags.zf)
    {
        goto L_0x004902c6;
    }
    // 004902bc  e8379cffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 004902c1  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x004902c6:
    // 004902c6  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004902cb  e8789cffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004902d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004902d2  e885f8ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 004902d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004902d9  741b                   -je 0x4902f6
    if (cpu.flags.zf)
    {
        goto L_0x004902f6;
    }
    // 004902db  8b1495e0445600         -mov edx, dword ptr [edx*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.edx * 4);
    // 004902e2  8b9234020000           -mov edx, dword ptr [edx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004902e8  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004902ed  e86e9cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004902f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004902f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004902f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004902f6:
    // 004902f6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004902f8  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004902fd  e85e9cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00490302  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490304  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490305  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490308(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490308  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490309  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049030b  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490312  750a                   -jne 0x49031e
    if (!cpu.flags.zf)
    {
        goto L_0x0049031e;
    }
    // 00490314  e8df9bffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00490319  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x0049031e:
    // 0049031e  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490323  e8209cffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00490328  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049032a  e82df8ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 0049032f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490331  7418                   -je 0x49034b
    if (cpu.flags.zf)
    {
        goto L_0x0049034b;
    }
    // 00490333  8b1495e0445600         -mov edx, dword ptr [edx*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.edx * 4);
    // 0049033a  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049033d  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490342  e8199cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00490347  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490349  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049034a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049034b:
    // 0049034b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049034d  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490352  e8099cffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00490357  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490359  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049035a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49035c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049035c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049035d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049035f  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490366  750a                   -jne 0x490372
    if (!cpu.flags.zf)
    {
        goto L_0x00490372;
    }
    // 00490368  e88b9bffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 0049036d  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x00490372:
    // 00490372  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490377  e8cc9bffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049037c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049037e  e8d9f7ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 00490383  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490385  7426                   -je 0x4903ad
    if (cpu.flags.zf)
    {
        goto L_0x004903ad;
    }
    // 00490387  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490388  8b1495e0445600         -mov edx, dword ptr [edx*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.edx * 4);
    // 0049038f  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 00490394  8b9a34020000           -mov ebx, dword ptr [edx + 0x234]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 0049039a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049039c  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049039e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039f  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004903a4  e8b79bffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004903a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004903ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004903ad:
    // 004903ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004903af  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004903b4  e8a79bffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004903b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004903bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4903c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004903c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004903c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004903c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004903c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004903c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004903c6  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004903c8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004903ca  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004903cc  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004903d3  750a                   -jne 0x4903df
    if (!cpu.flags.zf)
    {
        goto L_0x004903df;
    }
    // 004903d5  e81e9bffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 004903da  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x004903df:
    // 004903df  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004903e4  e85f9bffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004903e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004903eb  e86cf7ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 004903f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004903f2  0f846e000000           -je 0x490466
    if (cpu.flags.zf)
    {
        goto L_0x00490466;
    }
    // 004903f8  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 004903ff  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00490402  39f2                   +cmp edx, esi
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
    // 00490404  7e02                   -jle 0x490408
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490408;
    }
    // 00490406  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00490408:
    // 00490408  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 0049040f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00490412  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490414  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00490416  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049041c  7e14                   -jle 0x490432
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490432;
    }
    // 0049041e  bf00020000             -mov edi, 0x200
    cpu.edi = 512 /*0x200*/;
    // 00490423  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00490426  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490428  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049042a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049042c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049042e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490430  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00490432:
    // 00490432  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490434  7418                   -je 0x49044e
    if (cpu.flags.zf)
    {
        goto L_0x0049044e;
    }
    // 00490436  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 0049043d  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00490440  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00490443  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00490445  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490447  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00490449  e832a5ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
L_0x0049044e:
    // 0049044e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00490450  7414                   -je 0x490466
    if (cpu.flags.zf)
    {
        goto L_0x00490466;
    }
    // 00490452  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00490454  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 0049045b  8d142e                 -lea edx, [esi + ebp]
    cpu.edx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0049045e  83c02c                 -add eax, 0x2c
    (cpu.eax) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00490461  e81aa5ffff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
L_0x00490466:
    // 00490466  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0049046b  e8f09affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00490470  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00490473  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490474  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490475  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490477  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490478(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490478  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490479  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049047b  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490482  750a                   -jne 0x49048e
    if (!cpu.flags.zf)
    {
        goto L_0x0049048e;
    }
    // 00490484  e86f9affff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00490489  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x0049048e:
    // 0049048e  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490493  e8b09affff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00490498  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049049a  e821ffffff             -call 0x4903c0
    cpu.esp -= 4;
    sub_4903c0(app, cpu);
    if (cpu.terminate) return;
    // 0049049f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004904a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004904a3  750e                   -jne 0x4904b3
    if (!cpu.flags.zf)
    {
        goto L_0x004904b3;
    }
    // 004904a5  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004904aa  e8b19affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004904af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004904b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004904b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004904b3:
    // 004904b3  8b148de0445600         -mov edx, dword ptr [ecx*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 004904ba  294210                 -sub dword ptr [edx + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004904bd  8b148de0445600         -mov edx, dword ptr [ecx*4 + 0x5644e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 004904c4  03420c                 -add eax, dword ptr [edx + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 004904c7  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004904cc  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004904cf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004904d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004904d6  e8e9f1ffff             -call 0x48f6c4
    cpu.esp -= 4;
    sub_48f6c4(app, cpu);
    if (cpu.terminate) return;
    // 004904db  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004904e0  e87b9affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004904e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004904e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004904e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4904ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004904ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004904ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004904ee  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004904f0  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004904f2  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004904f9  750a                   -jne 0x490505
    if (!cpu.flags.zf)
    {
        goto L_0x00490505;
    }
    // 004904fb  e8f899ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00490500  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x00490505:
    // 00490505  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0049050a  e8399affff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0049050f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490511  e846f6ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 00490516  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490518  7435                   -je 0x49054f
    if (cpu.flags.zf)
    {
        goto L_0x0049054f;
    }
    // 0049051a  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
L_0x00490521:
    // 00490521  8b83e0445600           -mov eax, dword ptr [ebx + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5653728) /* 0x5644e0 */);
    // 00490527  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049052a  7e09                   -jle 0x490535
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490535;
    }
    // 0049052c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049052e  e87d39ffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00490533  ebec                   -jmp 0x490521
    goto L_0x00490521;
L_0x00490535:
    // 00490535  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00490537  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490539  e83affffff             -call 0x490478
    cpu.esp -= 4;
    sub_490478(app, cpu);
    if (cpu.terminate) return;
    // 0049053e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490540  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490545  e8169affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049054a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049054c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049054d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049054e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049054f:
    // 0049054f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490551  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 00490556  e8059affff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0049055b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049055d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049055e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049055f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490560  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490561  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490563  833dd8be4d0000         +cmp dword ptr [0x4dbed8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049056a  750a                   -jne 0x490576
    if (!cpu.flags.zf)
    {
        goto L_0x00490576;
    }
    // 0049056c  e88799ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00490571  a3d8be4d00             -mov dword ptr [0x4dbed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */) = cpu.eax;
L_0x00490576:
    // 00490576  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0049057b  e8c899ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00490580  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490582  e8d5f5ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 00490587  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490589  740c                   -je 0x490597
    if (cpu.flags.zf)
    {
        goto L_0x00490597;
    }
    // 0049058b  8b048de0445600         -mov eax, dword ptr [ecx*4 + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */ + cpu.ecx * 4);
    // 00490592  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490595  7e10                   -jle 0x4905a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004905a7;
    }
L_0x00490597:
    // 00490597  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490599  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 0049059e  e8bd99ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004905a3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004905a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004905a7:
    // 004905a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004905a9  e8cafeffff             -call 0x490478
    cpu.esp -= 4;
    sub_490478(app, cpu);
    if (cpu.terminate) return;
    // 004905ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004905b0  a1d8be4d00             -mov eax, dword ptr [0x4dbed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5095128) /* 0x4dbed8 */);
    // 004905b5  e8a699ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004905ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004905bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4905c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004905c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004905c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004905c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004905c4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004905c6  e891f5ffff             -call 0x48fb5c
    cpu.esp -= 4;
    sub_48fb5c(app, cpu);
    if (cpu.terminate) return;
    // 004905cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004905cd  7434                   -je 0x490603
    if (cpu.flags.zf)
    {
        goto L_0x00490603;
    }
    // 004905cf  8b1df0375600           -mov ebx, dword ptr [0x5637f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 004905d5  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004905d7  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
L_0x004905de:
    // 004905de  8b81e0445600           -mov eax, dword ptr [ecx + 0x5644e0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5653728) /* 0x5644e0 */);
    // 004905e4  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004905e7  7e11                   -jle 0x4905fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004905fa;
    }
    // 004905e9  3b1df0375600           +cmp ebx, dword ptr [0x5637f0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004905ef  7e09                   -jle 0x4905fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004905fa;
    }
    // 004905f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004905f3  e8b838ffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 004905f8  ebe4                   -jmp 0x4905de
    goto L_0x004905de;
L_0x004905fa:
    // 004905fa  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004905fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004905fe  e875feffff             -call 0x490478
    cpu.esp -= 4;
    sub_490478(app, cpu);
    if (cpu.terminate) return;
L_0x00490603:
    // 00490603  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490604  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490605  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490610  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490612  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490614  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490616  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490618  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049061a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049061c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049061e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490622  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490625  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490627  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490628  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049062c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049062d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049062e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00490632  e8114c0300             -call 0x4c5248
    cpu.esp -= 4;
    sub_4c5248(app, cpu);
    if (cpu.terminate) return;
    // 00490637  8b1d6c3d5600           -mov ebx, dword ptr [0x563d6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5651820) /* 0x563d6c */);
    // 0049063d  43                     -inc ebx
    (cpu.ebx)++;
    // 0049063e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00490641  891d6c3d5600           -mov dword ptr [0x563d6c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651820) /* 0x563d6c */) = cpu.ebx;
    // 00490647  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049064a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049064b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049064c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00490620;
    // 00490610  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490612  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490614  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490616  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00490618  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049061a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049061c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049061e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x00490620:
    // 00490620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490622  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490625  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490627  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490628  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049062c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049062d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049062e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00490632  e8114c0300             -call 0x4c5248
    cpu.esp -= 4;
    sub_4c5248(app, cpu);
    if (cpu.terminate) return;
    // 00490637  8b1d6c3d5600           -mov ebx, dword ptr [0x563d6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5651820) /* 0x563d6c */);
    // 0049063d  43                     -inc ebx
    (cpu.ebx)++;
    // 0049063e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00490641  891d6c3d5600           -mov dword ptr [0x563d6c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651820) /* 0x563d6c */) = cpu.ebx;
    // 00490647  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049064a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049064b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049064c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490651  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490652  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490653  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490654  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00490657  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490659  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049065c  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0049065f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490660  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490664  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490666  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490667  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049066a  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 00490670  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490672  48                     -dec eax
    (cpu.eax)--;
    // 00490673  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00490676  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490677  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049067a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049067c  e883180000             -call 0x491f04
    cpu.esp -= 4;
    sub_491f04(app, cpu);
    if (cpu.terminate) return;
    // 00490681  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490683  7408                   -je 0x49068d
    if (cpu.flags.zf)
    {
        goto L_0x0049068d;
    }
L_0x00490685:
    // 00490685  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00490688  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490689  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049068a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049068b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049068c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049068d:
    // 0049068d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00490690  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00490693  80e4b7                 -and ah, 0xb7
    cpu.ah &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 00490696  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490697  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049069b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049069c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049069e  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004906a1  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 004906a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004906a9  48                     -dec eax
    (cpu.eax)--;
    // 004906aa  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004906ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004906ae  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004906b1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004906b3  e84c180000             -call 0x491f04
    cpu.esp -= 4;
    sub_491f04(app, cpu);
    if (cpu.terminate) return;
    // 004906b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004906ba  7531                   -jne 0x4906ed
    if (!cpu.flags.zf)
    {
        goto L_0x004906ed;
    }
    // 004906bc  f644240140             +test byte ptr [esp + 1], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 64 /*0x40*/));
    // 004906c1  746c                   -je 0x49072f
    if (cpu.flags.zf)
    {
        goto L_0x0049072f;
    }
    // 004906c3  804c240508             -or byte ptr [esp + 5], 8
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004906c8:
    // 004906c8  8b6e24                 -mov ebp, dword ptr [esi + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004906cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004906cc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004906d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004906d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004906d3  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004906d6  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 004906dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004906de  48                     -dec eax
    (cpu.eax)--;
    // 004906df  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004906e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004906e3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004906e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004906e8  e817180000             -call 0x491f04
    cpu.esp -= 4;
    sub_491f04(app, cpu);
    if (cpu.terminate) return;
L_0x004906ed:
    // 004906ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004906ef  7594                   -jne 0x490685
    if (!cpu.flags.zf)
    {
        goto L_0x00490685;
    }
    // 004906f1  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004906f8  768b                   -jbe 0x490685
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490685;
    }
    // 004906fa  8a7c2405               -mov bh, byte ptr [esp + 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 004906fe  80e7b7                 -and bh, 0xb7
    cpu.bh &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 00490701  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00490704  887c2405               -mov byte ptr [esp + 5], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.bh;
    // 00490708  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490709  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049070d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049070e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00490711  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490712  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00490715  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00490718  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490719  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049071b  c6866304000001         -mov byte ptr [esi + 0x463], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 00490722  e8dd170000             -call 0x491f04
    cpu.esp -= 4;
    sub_491f04(app, cpu);
    if (cpu.terminate) return;
    // 00490727  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049072a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049072b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049072c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049072d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049072e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049072f:
    // 0049072f  804c240540             +or byte ptr [esp + 5], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00490734  eb92                   -jmp 0x4906c8
    goto L_0x004906c8;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490738(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490738  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490739  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049073a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049073b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049073d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049073f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490741  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00490743  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490744  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 0049074a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049074c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049074e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049074f  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490752  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490754  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049075a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049075c  7408                   -je 0x490766
    if (cpu.flags.zf)
    {
        goto L_0x00490766;
    }
    // 0049075e  81fac2010000           +cmp edx, 0x1c2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(450 /*0x1c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490764  7406                   -je 0x49076c
    if (cpu.flags.zf)
    {
        goto L_0x0049076c;
    }
L_0x00490766:
    // 00490766  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490768  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490769  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049076a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049076b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049076c:
    // 0049076c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049076d  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049076f  ff506c                 -call dword ptr [eax + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490772  8b9644040000           -mov edx, dword ptr [esi + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00490778  39d7                   +cmp edi, edx
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
    // 0049077a  7418                   -je 0x490794
    if (cpu.flags.zf)
    {
        goto L_0x00490794;
    }
    // 0049077c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049077e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049077f  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00490781  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490784  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490786  740c                   -je 0x490794
    if (cpu.flags.zf)
    {
        goto L_0x00490794;
    }
    // 00490788  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0049078e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049078f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490791  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00490794:
    // 00490794  8b8e48040000           -mov ecx, dword ptr [esi + 0x448]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0049079a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049079c  741a                   -je 0x4907b8
    if (cpu.flags.zf)
    {
        goto L_0x004907b8;
    }
    // 0049079e  39cf                   +cmp edi, ecx
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
    // 004907a0  7416                   -je 0x4907b8
    if (cpu.flags.zf)
    {
        goto L_0x004907b8;
    }
    // 004907a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004907a3  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004907a5  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004907a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004907aa  740c                   -je 0x4907b8
    if (cpu.flags.zf)
    {
        goto L_0x004907b8;
    }
    // 004907ac  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 004907b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004907b3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004907b5  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004907b8:
    // 004907b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004907b9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004907bb  ff5060                 -call dword ptr [eax + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004907be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004907c0  0f85b2000000           -jne 0x490878
    if (!cpu.flags.zf)
    {
        goto L_0x00490878;
    }
    // 004907c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004907c8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004907ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004907cb  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 004907d1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004907d3  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004907d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004907d6  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004907d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004907db  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004907e1  7434                   -je 0x490817
    if (cpu.flags.zf)
    {
        goto L_0x00490817;
    }
    // 004907e3  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004907e8  e87397ffff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004907ed  e81eba0100             -call 0x4ac210
    cpu.esp -= 4;
    sub_4ac210(app, cpu);
    if (cpu.terminate) return;
    // 004907f2  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004907f7  e84c97ffff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004907fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004907fe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00490800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490801  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 00490807  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490809  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049080b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049080c  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049080f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490811  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
L_0x00490817:
    // 00490817  0f8549ffffff           -jne 0x490766
    if (!cpu.flags.zf)
    {
        goto L_0x00490766;
    }
    // 0049081d  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 00490821  7519                   -jne 0x49083c
    if (!cpu.flags.zf)
    {
        goto L_0x0049083c;
    }
L_0x00490823:
    // 00490823  833dd0b14d0000         +cmp dword ptr [0x4db1d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091792) /* 0x4db1d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049082a  0f8436ffffff           -je 0x490766
    if (cpu.flags.zf)
    {
        goto L_0x00490766;
    }
    // 00490830  ff15d0b14d00           -call dword ptr [0x4db1d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5091792) /* 0x4db1d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490836  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490838  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490839  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049083a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049083b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049083c:
    // 0049083c  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0049083f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490840  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00490845  66c78632040000ffff     -mov word ptr [esi + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 0049084e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490850  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00490853  66c786300400000001     -mov word ptr [esi + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 0049085c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049085e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490860  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490861  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490864  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00490867  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0049086d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049086e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490870  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490871  ff527c                 -call dword ptr [edx + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490874  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00490876  ebab                   -jmp 0x490823
    goto L_0x00490823;
L_0x00490878:
    // 00490878  bac2010000             -mov edx, 0x1c2
    cpu.edx = 450 /*0x1c2*/;
    // 0049087d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049087f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490880  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490882  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490884(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490884  3b05443d5600           +cmp eax, dword ptr [0x563d44]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651780) /* 0x563d44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049088a  7401                   -je 0x49088d
    if (cpu.flags.zf)
    {
        goto L_0x0049088d;
    }
    // 0049088c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049088d:
    // 0049088d  a1643d5600             -mov eax, dword ptr [0x563d64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651812) /* 0x563d64 */);
    // 00490892  0102                   -add dword ptr [edx], eax
    (app->getMemory<x86::reg32>(cpu.edx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490894  a1683d5600             -mov eax, dword ptr [0x563d68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651816) /* 0x563d68 */);
    // 00490899  0103                   -add dword ptr [ebx], eax
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049089b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49089c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049089c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049089d  3b05443d5600           +cmp eax, dword ptr [0x563d44]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651780) /* 0x563d44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004908a3  7402                   -je 0x4908a7
    if (cpu.flags.zf)
    {
        goto L_0x004908a7;
    }
    // 004908a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004908a7:
    // 004908a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004908a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004908a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004908aa  a1643d5600             -mov eax, dword ptr [0x563d64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651812) /* 0x563d64 */);
    // 004908af  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004908b1  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004908b4  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004908b7  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004908ba  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004908bc  a1683d5600             -mov eax, dword ptr [0x563d68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651816) /* 0x563d68 */);
    // 004908c1  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004908c3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004908c5  a1643d5600             -mov eax, dword ptr [0x563d64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651812) /* 0x563d64 */);
    // 004908ca  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004908cd  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004908cf  a1683d5600             -mov eax, dword ptr [0x563d68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651816) /* 0x563d68 */);
    // 004908d4  897a08                 -mov dword ptr [edx + 8], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004908d7  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004908d9  896a0c                 -mov dword ptr [edx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004908dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4908e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004908e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004908e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004908e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004908e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004908ea  7410                   -je 0x4908fc
    if (cpu.flags.zf)
    {
        goto L_0x004908fc;
    }
L_0x004908ec:
    // 004908ec  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004908ee  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004908f0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004908f2  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004908f4  42                     -inc edx
    (cpu.edx)++;
    // 004908f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004908f7  75f3                   -jne 0x4908ec
    if (!cpu.flags.zf)
    {
        goto L_0x004908ec;
    }
    // 004908f9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004908fc:
    // 004908fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004908fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490900  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490904  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490905  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490906  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490907  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049090a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049090c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049090e  f6430510               +test byte ptr [ebx + 5], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) & 16 /*0x10*/));
    // 00490912  0f844a010000           -je 0x490a62
    if (cpu.flags.zf)
    {
        goto L_0x00490a62;
    }
    // 00490918  837b5410               +cmp dword ptr [ebx + 0x54], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049091c  0f8440010000           -je 0x490a62
    if (cpu.flags.zf)
    {
        goto L_0x00490a62;
    }
    // 00490922  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490924  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 00490927  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0049092b:
    // 0049092b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049092d  0f8cdd000000           -jl 0x490a10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490a10;
    }
    // 00490933  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049093a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049093c  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049093f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00490942  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00490945  890c28                 -mov dword ptr [eax + ebp], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1) = cpu.ecx;
    // 00490948  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049094b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049094d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00490950  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00490953  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00490956  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00490959  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049095c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049095e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00490961  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00490964  8a4b54                 -mov cl, byte ptr [ebx + 0x54]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 00490967  884d12                 -mov byte ptr [ebp + 0x12], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.cl;
    // 0049096a  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049096d  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490971  884c2813               -mov byte ptr [eax + ebp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */ + cpu.ebp * 1) = cpu.cl;
    // 00490975  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00490978  66c74401100100         -mov word ptr [ecx + eax + 0x10], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1) = 1 /*0x1*/;
    // 0049097f  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00490982  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490984  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00490987  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0049098a  8b0d20bf4d00           -mov ecx, dword ptr [0x4dbf20]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5095200) /* 0x4dbf20 */);
    // 00490990  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00490993  f6430604               +test byte ptr [ebx + 6], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) & 4 /*0x4*/));
    // 00490997  740b                   -je 0x4909a4
    if (cpu.flags.zf)
    {
        goto L_0x004909a4;
    }
    // 00490999  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049099c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049099e  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004909a1  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004909a4:
    // 004909a4  f6430420               +test byte ptr [ebx + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 004909a8  741b                   -je 0x4909c5
    if (cpu.flags.zf)
    {
        goto L_0x004909c5;
    }
    // 004909aa  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004909b1  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004909b4  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004909b7  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004909ba  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004909bc  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 004909be  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004909c1  66014810               -add word ptr [eax + 0x10], cx
    (app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.cx));
L_0x004909c5:
    // 004909c5  f6430480               +test byte ptr [ebx + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 004909c9  7411                   -je 0x4909dc
    if (cpu.flags.zf)
    {
        goto L_0x004909dc;
    }
    // 004909cb  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004909d2  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004909d5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004909d7  804c810c01             -or byte ptr [ecx + eax*4 + 0xc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004909dc:
    // 004909dc  f6430440               +test byte ptr [ebx + 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 64 /*0x40*/));
    // 004909e0  7411                   -je 0x4909f3
    if (cpu.flags.zf)
    {
        goto L_0x004909f3;
    }
    // 004909e2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004909e9  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004909ec  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004909ee  804c810c02             -or byte ptr [ecx + eax*4 + 0xc], 2
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004909f3:
    // 004909f3  f6430401               +test byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 004909f7  7417                   -je 0x490a10
    if (cpu.flags.zf)
    {
        goto L_0x00490a10;
    }
    // 004909f9  f6436a20               +test byte ptr [ebx + 0x6a], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(106) /* 0x6a */) & 32 /*0x20*/));
    // 004909fd  7411                   -je 0x490a10
    if (cpu.flags.zf)
    {
        goto L_0x00490a10;
    }
    // 004909ff  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00490a06  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00490a09  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490a0b  804c810c04             -or byte ptr [ecx + eax*4 + 0xc], 4
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00490a10:
    // 00490a10  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00490a12  7447                   -je 0x490a5b
    if (cpu.flags.zf)
    {
        goto L_0x00490a5b;
    }
    // 00490a14  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490a16  7c1e                   -jl 0x490a36
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490a36;
    }
    // 00490a18  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00490a1f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490a21  8a9660040000           -mov dl, byte ptr [esi + 0x460]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
    // 00490a27  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00490a2a  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00490a2c  755b                   -jne 0x490a89
    if (!cpu.flags.zf)
    {
        goto L_0x00490a89;
    }
    // 00490a2e  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00490a31  8064020cef             -and byte ptr [edx + eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x00490a36:
    // 00490a36  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490a3d  740c                   -je 0x490a4b
    if (cpu.flags.zf)
    {
        goto L_0x00490a4b;
    }
    // 00490a3f  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00490a42  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00490a45  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00490a48  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00490a4b:
    // 00490a4b  8b4354                 -mov eax, dword ptr [ebx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 00490a4e  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00490a51  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490a55  88865c040000           -mov byte ptr [esi + 0x45c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */) = cpu.al;
L_0x00490a5b:
    // 00490a5b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00490a5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490a62:
    // 00490a62  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 00490a65  e87afeffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 00490a6a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490a6c  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 00490a6f  e870feffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 00490a74  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490a76  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 00490a79  e866feffff             -call 0x4908e4
    cpu.esp -= 4;
    sub_4908e4(app, cpu);
    if (cpu.terminate) return;
    // 00490a7e  01c1                   +add ecx, eax
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
    // 00490a80  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00490a84  e9a2feffff             -jmp 0x49092b
    goto L_0x0049092b;
L_0x00490a89:
    // 00490a89  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00490a8c  804c020c10             +or byte ptr [edx + eax + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00490a91  eba3                   -jmp 0x490a36
    goto L_0x00490a36;
}

/* align: skip 0x90 */
void Application::sub_490a94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490a94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490a95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490a96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490a97  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490a9a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490a9c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00490a9e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00490aa0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490aa1  8b15543d5600           -mov edx, dword ptr [0x563d54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 00490aa7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490aa8  2eff15e8634c00         -call dword ptr cs:[0x4c63e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006312) /* 0x4c63e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490aaf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490ab3  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490ab6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490ab8  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00490aba  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490abe  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490ac2  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00490ac4  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00490ac6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490ac9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490aca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490acb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490acc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490ad0  a1543d5600             -mov eax, dword ptr [0x563d54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 00490ad5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490ad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490ad8  a16c3d5600             -mov eax, dword ptr [0x563d6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5651820) /* 0x563d6c */);
    // 00490add  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490ae0  a100395600             -mov eax, dword ptr [0x563900]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650688) /* 0x563900 */);
    // 00490ae5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490ae8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490ae8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490ae9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490aea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490aec  7414                   -je 0x490b02
    if (cpu.flags.zf)
    {
        goto L_0x00490b02;
    }
    // 00490aee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490af0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490af1  8b15543d5600           -mov edx, dword ptr [0x563d54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 00490af7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490af8  2eff1538644c00         -call dword ptr cs:[0x4c6438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006392) /* 0x4c6438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490aff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490b02:
    // 00490b02  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00490b07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490b08  8b15543d5600           -mov edx, dword ptr [0x563d54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 00490b0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490b0f  2eff1538644c00         -call dword ptr cs:[0x4c6438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006392) /* 0x4c6438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490b16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490b1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490b1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490b1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490b1f  6810254900             -push 0x492510
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793616 /*0x492510*/;
    cpu.esp -= 4;
    // 00490b24  e819470300             -call 0x4c5242
    cpu.esp -= 4;
    sub_4c5242(app, cpu);
    if (cpu.terminate) return;
    // 00490b29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490b2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490b2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490b2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490b2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490b30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490b31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490b32  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 00490b38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490b3a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00490b3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490b3e  7505                   -jne 0x490b45
    if (!cpu.flags.zf)
    {
        goto L_0x00490b45;
    }
    // 00490b40  bb00395600             -mov ebx, 0x563900
    cpu.ebx = 5650688 /*0x563900*/;
L_0x00490b45:
    // 00490b45  833da0b64d0000         +cmp dword ptr [0x4db6a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490b4c  750a                   -jne 0x490b58
    if (!cpu.flags.zf)
    {
        goto L_0x00490b58;
    }
    // 00490b4e  e8a593ffff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00490b53  a3a0b64d00             -mov dword ptr [0x4db6a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */) = cpu.eax;
L_0x00490b58:
    // 00490b58  ba40455600             -mov edx, 0x564540
    cpu.edx = 5653824 /*0x564540*/;
    // 00490b5d  a140455600             -mov eax, dword ptr [0x564540]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653824) /* 0x564540 */);
    // 00490b62  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00490b65  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00490b68  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490b6a  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00490b6d  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00490b6f  8a1588ab4d00           -mov dl, byte ptr [0x4dab88]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5090184) /* 0x4dab88 */);
    // 00490b75  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00490b77  f6c280                 +test dl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 128 /*0x80*/));
    // 00490b7a  7521                   -jne 0x490b9d
    if (!cpu.flags.zf)
    {
        goto L_0x00490b9d;
    }
    // 00490b7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490b7e  740e                   -je 0x490b8e
    if (cpu.flags.zf)
    {
        goto L_0x00490b8e;
    }
    // 00490b80  ba40455600             -mov edx, 0x564540
    cpu.edx = 5653824 /*0x564540*/;
    // 00490b85  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490b87  e894faffff             -call 0x490620
    cpu.esp -= 4;
    sub_490620(app, cpu);
    if (cpu.terminate) return;
    // 00490b8c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00490b8e:
    // 00490b8e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490b90  750b                   -jne 0x490b9d
    if (!cpu.flags.zf)
    {
        goto L_0x00490b9d;
    }
    // 00490b92  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490b94  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490b96  e885faffff             -call 0x490620
    cpu.esp -= 4;
    sub_490620(app, cpu);
    if (cpu.terminate) return;
    // 00490b9b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00490b9d:
    // 00490b9d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490b9f  0f8420010000           -je 0x490cc5
    if (cpu.flags.zf)
    {
        goto L_0x00490cc5;
    }
L_0x00490ba5:
    // 00490ba5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490ba6  68f8274e00             -push 0x4e27f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122040 /*0x4e27f8*/;
    cpu.esp -= 4;
    // 00490bab  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490bad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490bae  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490bb0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490bb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490bb3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490bb5  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00490bbb  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490bbe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00490bc0  0f853e010000           -jne 0x490d04
    if (!cpu.flags.zf)
    {
        goto L_0x00490d04;
    }
    // 00490bc6  b86c010000             -mov eax, 0x16c
    cpu.eax = 364 /*0x16c*/;
    // 00490bcb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00490bcd  8984246c010000         -mov dword ptr [esp + 0x16c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.eax;
    // 00490bd4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00490bd7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490bd8  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00490bdf  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00490be1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490be2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00490be4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490be5  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490be8  8ab42473010000         -mov dh, byte ptr [esp + 0x173]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */);
    // 00490bef  893d20bf4d00           -mov dword ptr [0x4dbf20], edi
    app->getMemory<x86::reg32>(x86::reg32(5095200) /* 0x4dbf20 */) = cpu.edi;
    // 00490bf5  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00490bf8  740a                   -je 0x490c04
    if (cpu.flags.zf)
    {
        goto L_0x00490c04;
    }
    // 00490bfa  c70520bf4d0008000000   -mov dword ptr [0x4dbf20], 8
    app->getMemory<x86::reg32>(x86::reg32(5095200) /* 0x4dbf20 */) = 8 /*0x8*/;
L_0x00490c04:
    // 00490c04  f684247201000008       +test byte ptr [esp + 0x172], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(370) /* 0x172 */) & 8 /*0x8*/));
    // 00490c0c  7407                   -je 0x490c15
    if (cpu.flags.zf)
    {
        goto L_0x00490c15;
    }
    // 00490c0e  800d21bf4d0008         -or byte ptr [0x4dbf21], 8
    app->getMemory<x86::reg8>(x86::reg32(5095201) /* 0x4dbf21 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00490c15:
    // 00490c15  f684247001000001       +test byte ptr [esp + 0x170], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 1 /*0x1*/));
    // 00490c1d  7407                   -je 0x490c26
    if (cpu.flags.zf)
    {
        goto L_0x00490c26;
    }
    // 00490c1f  800d20bf4d0020         -or byte ptr [0x4dbf20], 0x20
    app->getMemory<x86::reg8>(x86::reg32(5095200) /* 0x4dbf20 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00490c26:
    // 00490c26  8a942470010000         -mov dl, byte ptr [esp + 0x170]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00490c2d  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00490c30  0f85c0000000           -jne 0x490cf6
    if (!cpu.flags.zf)
    {
        goto L_0x00490cf6;
    }
L_0x00490c36:
    // 00490c36  f684247001000040       +test byte ptr [esp + 0x170], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 64 /*0x40*/));
    // 00490c3e  7407                   -je 0x490c47
    if (cpu.flags.zf)
    {
        goto L_0x00490c47;
    }
    // 00490c40  800d20bf4d0040         -or byte ptr [0x4dbf20], 0x40
    app->getMemory<x86::reg8>(x86::reg32(5095200) /* 0x4dbf20 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00490c47:
    // 00490c47  f684247301000004       +test byte ptr [esp + 0x173], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 4 /*0x4*/));
    // 00490c4f  7407                   -je 0x490c58
    if (cpu.flags.zf)
    {
        goto L_0x00490c58;
    }
    // 00490c51  800d20bf4d0080         -or byte ptr [0x4dbf20], 0x80
    app->getMemory<x86::reg8>(x86::reg32(5095200) /* 0x4dbf20 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00490c58:
    // 00490c58  f684247101000002       +test byte ptr [esp + 0x171], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(369) /* 0x171 */) & 2 /*0x2*/));
    // 00490c60  7407                   -je 0x490c69
    if (cpu.flags.zf)
    {
        goto L_0x00490c69;
    }
    // 00490c62  800d21bf4d0001         -or byte ptr [0x4dbf21], 1
    app->getMemory<x86::reg8>(x86::reg32(5095201) /* 0x4dbf21 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00490c69:
    // 00490c69  f684247301000080       +test byte ptr [esp + 0x173], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 128 /*0x80*/));
    // 00490c71  7407                   -je 0x490c7a
    if (cpu.flags.zf)
    {
        goto L_0x00490c7a;
    }
    // 00490c73  800d21bf4d0004         -or byte ptr [0x4dbf21], 4
    app->getMemory<x86::reg8>(x86::reg32(5095201) /* 0x4dbf21 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00490c7a:
    // 00490c7a  f684247301000001       +test byte ptr [esp + 0x173], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 1 /*0x1*/));
    // 00490c82  7411                   -je 0x490c95
    if (cpu.flags.zf)
    {
        goto L_0x00490c95;
    }
    // 00490c84  f684247901000002       +test byte ptr [esp + 0x179], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(377) /* 0x179 */) & 2 /*0x2*/));
    // 00490c8c  7407                   -je 0x490c95
    if (cpu.flags.zf)
    {
        goto L_0x00490c95;
    }
    // 00490c8e  800d21bf4d0002         -or byte ptr [0x4dbf21], 2
    app->getMemory<x86::reg8>(x86::reg32(5095201) /* 0x4dbf21 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00490c95:
    // 00490c95  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 00490c9d  7407                   -je 0x490ca6
    if (cpu.flags.zf)
    {
        goto L_0x00490ca6;
    }
    // 00490c9f  800d20bf4d0010         -or byte ptr [0x4dbf20], 0x10
    app->getMemory<x86::reg8>(x86::reg32(5095200) /* 0x4dbf20 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00490ca6:
    // 00490ca6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00490ca8  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
L_0x00490cae:
    // 00490cae  833b00                 +cmp dword ptr [ebx], 0
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
    // 00490cb1  7463                   -je 0x490d16
    if (cpu.flags.zf)
    {
        goto L_0x00490d16;
    }
    // 00490cb3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00490cb8:
    // 00490cb8  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 00490cbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cbf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cc3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490cc5:
    // 00490cc5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00490cca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490ccc  e84ff9ffff             -call 0x490620
    cpu.esp -= 4;
    sub_490620(app, cpu);
    if (cpu.terminate) return;
    // 00490cd1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490cd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490cd5  0f85cafeffff           -jne 0x490ba5
    if (!cpu.flags.zf)
    {
        goto L_0x00490ba5;
    }
    // 00490cdb  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00490cdd  b8cc014d00             -mov eax, 0x4d01cc
    cpu.eax = 5046732 /*0x4d01cc*/;
    // 00490ce2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490ce4  7509                   -jne 0x490cef
    if (!cpu.flags.zf)
    {
        goto L_0x00490cef;
    }
L_0x00490ce6:
    // 00490ce6  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 00490ceb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490ced  ebc9                   -jmp 0x490cb8
    goto L_0x00490cb8;
L_0x00490cef:
    // 00490cef  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 00490cf4  ebf0                   -jmp 0x490ce6
    goto L_0x00490ce6;
L_0x00490cf6:
    // 00490cf6  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00490cf9  0f8437ffffff           -je 0x490c36
    if (cpu.flags.zf)
    {
        goto L_0x00490c36;
    }
    // 00490cff  e976ffffff             -jmp 0x490c7a
    goto L_0x00490c7a;
L_0x00490d04:
    // 00490d04  b8e8014d00             -mov eax, 0x4d01e8
    cpu.eax = 5046760 /*0x4d01e8*/;
    // 00490d09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d0b  7518                   -jne 0x490d25
    if (!cpu.flags.zf)
    {
        goto L_0x00490d25;
    }
L_0x00490d0d:
    // 00490d0d  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 00490d12  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00490d14  7498                   -je 0x490cae
    if (cpu.flags.zf)
    {
        goto L_0x00490cae;
    }
L_0x00490d16:
    // 00490d16  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490d18  81c4d8020000           +add esp, 0x2d8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(728 /*0x2d8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490d1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490d25:
    // 00490d25  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 00490d2a  ebe1                   -jmp 0x490d0d
    goto L_0x00490d0d;
}

/* align: skip  */
void Application::sub_490d2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490d2c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490d2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490d2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490d2f  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 00490d35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490d37  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00490d39  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00490d3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d3d  7505                   -jne 0x490d44
    if (!cpu.flags.zf)
    {
        goto L_0x00490d44;
    }
    // 00490d3f  be00395600             -mov esi, 0x563900
    cpu.esi = 5650688 /*0x563900*/;
L_0x00490d44:
    // 00490d44  833e00                 +cmp dword ptr [esi], 0
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
    // 00490d47  750e                   -jne 0x490d57
    if (!cpu.flags.zf)
    {
        goto L_0x00490d57;
    }
L_0x00490d49:
    // 00490d49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490d4b  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 00490d51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d54  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00490d57:
    // 00490d57  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 00490d5c  898c246c010000         -mov dword ptr [esp + 0x16c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.ecx;
    // 00490d63  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00490d66  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00490d68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490d69  8d8c2470010000         -lea ecx, [esp + 0x170]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00490d70  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490d72  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490d73  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490d75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490d76  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490d79  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00490d7d  75ca                   -jne 0x490d49
    if (!cpu.flags.zf)
    {
        goto L_0x00490d49;
    }
    // 00490d7f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00490d81  740a                   -je 0x490d8d
    if (cpu.flags.zf)
    {
        goto L_0x00490d8d;
    }
    // 00490d83  8b8424a8010000         -mov eax, dword ptr [esp + 0x1a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(424) /* 0x1a8 */);
    // 00490d8a  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00490d8d:
    // 00490d8d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490d8f  7409                   -je 0x490d9a
    if (cpu.flags.zf)
    {
        goto L_0x00490d9a;
    }
    // 00490d91  8b8424ac010000         -mov eax, dword ptr [esp + 0x1ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */);
    // 00490d98  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00490d9a:
    // 00490d9a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00490d9c  7411                   -je 0x490daf
    if (cpu.flags.zf)
    {
        goto L_0x00490daf;
    }
    // 00490d9e  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 00490da6  745c                   -je 0x490e04
    if (cpu.flags.zf)
    {
        goto L_0x00490e04;
    }
    // 00490da8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00490dad:
    // 00490dad  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00490daf:
    // 00490daf  83bc24e802000000       +cmp dword ptr [esp + 0x2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490db7  742d                   -je 0x490de6
    if (cpu.flags.zf)
    {
        goto L_0x00490de6;
    }
    // 00490db9  6848254900             -push 0x492548
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793672 /*0x492548*/;
    cpu.esp -= 4;
    // 00490dbe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490dc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490dc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490dc2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490dc4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00490dc6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490dc8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490dc9  890d58455600           -mov dword ptr [0x564558], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */) = cpu.ecx;
    // 00490dcf  890d50455600           -mov dword ptr [0x564550], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653840) /* 0x564550 */) = cpu.ecx;
    // 00490dd5  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490dd8  8b9424e8020000         -mov edx, dword ptr [esp + 0x2e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
    // 00490ddf  a150455600             -mov eax, dword ptr [0x564550]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653840) /* 0x564550 */);
    // 00490de4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00490de6:
    // 00490de6  833d5845560000         +cmp dword ptr [0x564558], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ded  0f8e56ffffff           -jle 0x490d49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490d49;
    }
    // 00490df3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00490df8  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 00490dfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490dff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e01  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00490e04:
    // 00490e04  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490e06  eba5                   -jmp 0x490dad
    goto L_0x00490dad;
}

/* align: skip  */
void Application::sub_490e08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490e08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490e09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490e0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490e0b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490e0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490e0d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490e0e  8b3d1cef4d00           -mov edi, dword ptr [0x4def1c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */);
    // 00490e14  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490e16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490e18  7505                   -jne 0x490e1f
    if (!cpu.flags.zf)
    {
        goto L_0x00490e1f;
    }
    // 00490e1a  be00395600             -mov esi, 0x563900
    cpu.esi = 5650688 /*0x563900*/;
L_0x00490e1f:
    // 00490e1f  833e00                 +cmp dword ptr [esi], 0
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
    // 00490e22  7521                   -jne 0x490e45
    if (!cpu.flags.zf)
    {
        goto L_0x00490e45;
    }
    // 00490e24  b80c024d00             -mov eax, 0x4d020c
    cpu.eax = 5046796 /*0x4d020c*/;
    // 00490e29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490e2b  7511                   -jne 0x490e3e
    if (!cpu.flags.zf)
    {
        goto L_0x00490e3e;
    }
L_0x00490e2d:
    // 00490e2d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490e2f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490e31  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490e37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490e3e:
    // 00490e3e  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 00490e43  ebe8                   -jmp 0x490e2d
    goto L_0x00490e2d;
L_0x00490e45:
    // 00490e45  83be5404000000         +cmp dword ptr [esi + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490e4c  751f                   -jne 0x490e6d
    if (!cpu.flags.zf)
    {
        goto L_0x00490e6d;
    }
    // 00490e4e  b82c024d00             -mov eax, 0x4d022c
    cpu.eax = 5046828 /*0x4d022c*/;
    // 00490e53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490e55  74d6                   -je 0x490e2d
    if (cpu.flags.zf)
    {
        goto L_0x00490e2d;
    }
    // 00490e57  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 00490e5c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490e5e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490e60  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490e66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490e6d:
    // 00490e6d  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490e74  744f                   -je 0x490ec5
    if (cpu.flags.zf)
    {
        goto L_0x00490ec5;
    }
    // 00490e76  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00490e7b  8b1d24bf4d00           -mov ebx, dword ptr [0x4dbf24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5095204) /* 0x4dbf24 */);
    // 00490e81  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490e87  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490e89  7405                   -je 0x490e90
    if (cpu.flags.zf)
    {
        goto L_0x00490e90;
    }
    // 00490e8b  b851000000             -mov eax, 0x51
    cpu.eax = 81 /*0x51*/;
L_0x00490e90:
    // 00490e90  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490e91  8bae54040000           -mov ebp, dword ptr [esi + 0x454]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 00490e97  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00490e99  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490e9a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00490e9c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490e9d  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490ea0  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00490ea5  742b                   -je 0x490ed2
    if (cpu.flags.zf)
    {
        goto L_0x00490ed2;
    }
    // 00490ea7  b8a0024d00             -mov eax, 0x4d02a0
    cpu.eax = 5046944 /*0x4d02a0*/;
    // 00490eac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490eae  0f85ba000000           -jne 0x490f6e
    if (!cpu.flags.zf)
    {
        goto L_0x00490f6e;
    }
    // 00490eb4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490eb6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490eb8  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490ebe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ebf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ec0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ec1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ec2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ec3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ec4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490ec5:
    // 00490ec5  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00490eca  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490ed0  ebbe                   -jmp 0x490e90
    goto L_0x00490e90;
L_0x00490ed2:
    // 00490ed2  6848254900             -push 0x492548
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793672 /*0x492548*/;
    cpu.esp -= 4;
    // 00490ed7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490ed8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490eda  a358455600             -mov dword ptr [0x564558], eax
    app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */) = cpu.eax;
    // 00490edf  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490ee1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00490ee3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490ee5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490ee6  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490ee9  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00490eee  7423                   -je 0x490f13
    if (cpu.flags.zf)
    {
        goto L_0x00490f13;
    }
    // 00490ef0  b848024d00             -mov eax, 0x4d0248
    cpu.eax = 5046856 /*0x4d0248*/;
    // 00490ef5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490ef7  0f8430ffffff           -je 0x490e2d
    if (cpu.flags.zf)
    {
        goto L_0x00490e2d;
    }
    // 00490efd  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 00490f02  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490f04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490f06  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490f13:
    // 00490f13  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00490f16  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490f18  740e                   -je 0x490f28
    if (cpu.flags.zf)
    {
        goto L_0x00490f28;
    }
    // 00490f1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490f1c  e8db39ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00490f21  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x00490f28:
    // 00490f28  a158455600             -mov eax, dword ptr [0x564558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */);
    // 00490f2d  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00490f30  83f810                 +cmp eax, 0x10
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
    // 00490f33  7d07                   -jge 0x490f3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00490f3c;
    }
    // 00490f35  c7460810000000         -mov dword ptr [esi + 8], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 16 /*0x10*/;
L_0x00490f3c:
    // 00490f3c  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00490f3f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00490f46  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00490f4b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490f4d  b86c024d00             -mov eax, 0x4d026c
    cpu.eax = 5046892 /*0x4d026c*/;
    // 00490f52  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00490f55  e83e35ffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00490f5a  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00490f5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490f5f  7523                   -jne 0x490f84
    if (!cpu.flags.zf)
    {
        goto L_0x00490f84;
    }
    // 00490f61  b878024d00             -mov eax, 0x4d0278
    cpu.eax = 5046904 /*0x4d0278*/;
    // 00490f66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490f68  0f84bffeffff           -je 0x490e2d
    if (cpu.flags.zf)
    {
        goto L_0x00490e2d;
    }
L_0x00490f6e:
    // 00490f6e  b8e4014d00             -mov eax, 0x4d01e4
    cpu.eax = 5046756 /*0x4d01e4*/;
    // 00490f73  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490f75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490f77  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490f7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490f83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490f84:
    // 00490f84  6848254900             -push 0x492548
    app->getMemory<x86::reg32>(cpu.esp-4) = 4793672 /*0x492548*/;
    cpu.esp -= 4;
    // 00490f89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490f8a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00490f8c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490f8d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490f8f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00490f91  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490f93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490f94  892d54455600           -mov dword ptr [0x564554], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653844) /* 0x564554 */) = cpu.ebp;
    // 00490f9a  892d58455600           -mov dword ptr [0x564558], ebp
    app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */) = cpu.ebp;
    // 00490fa0  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490fa3  c7462800030000         -mov dword ptr [esi + 0x28], 0x300
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 768 /*0x300*/;
    // 00490faa  c7462c00010000         -mov dword ptr [esi + 0x2c], 0x100
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 256 /*0x100*/;
    // 00490fb1  a158455600             -mov eax, dword ptr [0x564558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653848) /* 0x564558 */);
    // 00490fb6  8a965d040000           -mov dl, byte ptr [esi + 0x45d]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 00490fbc  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00490fbf  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00490fc1  7539                   -jne 0x490ffc
    if (!cpu.flags.zf)
    {
        goto L_0x00490ffc;
    }
    // 00490fc3  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 00490fc7  7533                   -jne 0x490ffc
    if (!cpu.flags.zf)
    {
        goto L_0x00490ffc;
    }
    // 00490fc9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490fca  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00490fcd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490fce  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490fd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490fd1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490fd3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490fd4  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490fd7  8b8e54040000           -mov ecx, dword ptr [esi + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 00490fdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490fde  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00490fe1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490fe2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490fe4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490fe5  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490fe8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00490fed  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00490fef  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00490ff5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ffa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ffb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490ffc:
    // 00490ffc  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00491003  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491008  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049100a  893d1cef4d00           -mov dword ptr [0x4def1c], edi
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.edi;
    // 00491010  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491011  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491012  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491013  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491014  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491015  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491016  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491018(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491018  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491019  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049101a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049101b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049101c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049101d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049101e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491020  83b84404000000         +cmp dword ptr [eax + 0x444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491027  740c                   -je 0x491035
    if (cpu.flags.zf)
    {
        goto L_0x00491035;
    }
    // 00491029  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049102b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049102d  7406                   -je 0x491035
    if (cpu.flags.zf)
    {
        goto L_0x00491035;
    }
    // 0049102f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491030  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00491032  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00491035:
    // 00491035  8bb350040000           -mov esi, dword ptr [ebx + 0x450]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */);
    // 0049103b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049103d  7407                   -je 0x491046
    if (cpu.flags.zf)
    {
        goto L_0x00491046;
    }
    // 0049103f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491041  e882b90100             -call 0x4ac9c8
    cpu.esp -= 4;
    sub_4ac9c8(app, cpu);
    if (cpu.terminate) return;
L_0x00491046:
    // 00491046  8bbb4c040000           -mov edi, dword ptr [ebx + 0x44c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */);
    // 0049104c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049104e  7407                   -je 0x491057
    if (cpu.flags.zf)
    {
        goto L_0x00491057;
    }
    // 00491050  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491052  e871b90100             -call 0x4ac9c8
    cpu.esp -= 4;
    sub_4ac9c8(app, cpu);
    if (cpu.terminate) return;
L_0x00491057:
    // 00491057  c7835004000000000000   -mov dword ptr [ebx + 0x450], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */) = 0 /*0x0*/;
    // 00491061  8bab48040000           -mov ebp, dword ptr [ebx + 0x448]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */);
    // 00491067  c7834c04000000000000   -mov dword ptr [ebx + 0x44c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */) = 0 /*0x0*/;
    // 00491071  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00491073  7409                   -je 0x49107e
    if (cpu.flags.zf)
    {
        goto L_0x0049107e;
    }
    // 00491075  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00491077  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491079  e87a100000             -call 0x4920f8
    cpu.esp -= 4;
    sub_4920f8(app, cpu);
    if (cpu.terminate) return;
L_0x0049107e:
    // 0049107e  8b8344040000           -mov eax, dword ptr [ebx + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */);
    // 00491084  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491086  7520                   -jne 0x4910a8
    if (!cpu.flags.zf)
    {
        goto L_0x004910a8;
    }
L_0x00491088:
    // 00491088  c7834804000000000000   -mov dword ptr [ebx + 0x448], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */) = 0 /*0x0*/;
    // 00491092  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491097  c7834404000000000000   -mov dword ptr [ebx + 0x444], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */) = 0 /*0x0*/;
    // 004910a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004910a8:
    // 004910a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004910aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004910ac  e847100000             -call 0x4920f8
    cpu.esp -= 4;
    sub_4920f8(app, cpu);
    if (cpu.terminate) return;
    // 004910b1  ebd5                   -jmp 0x491088
    goto L_0x00491088;
}

}
